// TNuSec04.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec04 --- File 4 : Angular distributions                               //
/* Begin_Latex
f(E_{n}, #mu) = #frac{#sigma_{c}(E_{n})}{d#mu} / #sigma_{c}(E_{n})
with #int_{-1}^{1} f(E_{n}, #mu) d#mu = 1,
End_Latex
where En is the indident energy (in eV), #mu is cos(theta) and
c is the channel index given by the MT value.
*/
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) :
// [MAT, 4, MT/  ZA, AWR,  0, LTT, 0, 0]HEAD                                 //
// HeadAt(1) :
// [MAT, 4, MT/ 0.0, AWR, LI, LCT, 0, 0]CONT                                 //
//
// ------------------ body --------------------------------------------------//
// At(0) :
// [MAT, 4, MT/ TNuTab2                                                      //
// At(1) :
// [MAT, 4, MT/ (optional) TNuTab2 (for high-E data)                         //
//                                                                           //
//
// ------------------ notes -------------------------------------------------//
//
// At(0) is Tab2 of ListLegendre if LTT =1 or 3,
//      and Tab2 of Tab1 if LTT = 2.
// At(1) is, if any, Tab2 of Tab1.
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec04.h"
#include "TNuMat.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2Tab1.h"
#include "TNuTab2List1.h"
#include "TNuListLegendre.h"

#include <iostream>
using namespace std;

ClassImp(TNuSec04)

//______________________________________________________________________________
void TNuSec04::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 4
   //
/*
[MAT, 4, MT/  ZA, AWR,  0, LTT, 0, 0]HEAD
[MAT, 4, MT/ 0.0, AWR, LI, LCT, 0, 0]CONT
*/
   SetHead(new TNuCont(src, "ZA, AWR,  0, LTT, 0, 0/HEAD"));

   Int_t vLTT = GetLTT();

   if (vLTT < 3) {
      // Standard format for Sec4000 reads
      // TNuCont, TNuCont, TNuTab2, ...
      // but in some cases (some Sec4002 of JEFF),
      // the 2nd TNuCont is replaced by LIST.
      // Below is to handle that cases :
      TString type = src.GuessRecType();
      if (type == "CONT") {
         // for the standard cases
         AddToHead(new TNuCont(src, " 0.0, AWR, LI, LCT, 0, 0"));
      }
      else if (type == "LIST") {
         // for the exceptional cases
         AddToHead(new TNuList(src, "0.0, AWR, LI, LCT, N1, N2"));
      }
      else {
         // error
         Error("ImportEndfData", "Unknown type %s in %ld-th line",
            type.Data(), src.GetLineNum());
      }
   } else if (vLTT == 3) {
      AddToHead(new TNuListLegendre(src, "0.0, AWR, LI, LCT, 0, NM"));
   } else {
      Error("ImportEndfData", "Unknown case, LTT = %d in %ld-th line",
         vLTT, src.GetLineNum());
   }
   Int_t vLI  = GetLI();

   //TNuTab2* tab2;
   TNuTab2List1* tab2list;
   TNuTab2Tab1* tab2tab1;
   if (vLTT==1 && vLI==0) {
      // Legendre Polynomial Coefficients (LTT=1, LI=0)
      tab2list = new TNuTab2List1(src, "0.0, 0.0, 0, 0, NR, NE");
 
      for (Int_t n=0; n < tab2list->GetN2(); n++)
         tab2list->Add(new TNuListLegendre(src, "T, E, LT, 0, NL, 0/ a(E_i)"));

      Add(tab2list);
   }
   else if (vLTT==2 && vLI==0) {
      // Tabulated Probability Distributions (LTT=2, LI=0)
      tab2tab1 = new TNuTab2Tab1(src, "0.0, 0.0, 0, 0, NR, NE");
      for (Int_t n=0; n < tab2tab1->GetN2(); n++)
         tab2tab1->Add(new TNuTab1(src, "T, E, LT, 0, NR, NP/ f(#mu, E_i)"));
      Add(tab2tab1);
   }
   else if (vLTT==0 && vLI==1) {
      // Purely Isotropic Angular Distributions (LTT=0, LI=1)
   }
   else if (vLTT ==3 && vLI == 0) {
      // Angular Distribution Over Two Energy Ranges (LTT=3, LI=0)
      tab2list = new TNuTab2List1(src, "0.0, 0.0, 0, 0, NR, NE1");
      for (Int_t n=0; n < tab2list->GetN2(); n++)
         tab2list->Add(new TNuListLegendre(src, "T, E, LT, 0, NL, 0/ a(E_i)"));
      Add(tab2list);
      tab2tab1 = new TNuTab2Tab1(src, "0.0, 0.0, 0, 0, NR, NE2");
      for (Int_t n=0; n < tab2tab1->GetN2(); n++)
         tab2tab1->Add(new TNuTab1(src, "T, E, LT, 0, NR, NP/ f(#mu, E_i)"));
      Add(tab2tab1);
   }
   else {
      Error("ImportEndfData", "Unsupported value of LTT=%d and LI=%d", vLTT, vLI);
   }
}

//______________________________________________________________________________
void TNuSec04::What() const
{
   TNuSection::What();
   Int_t vLTT=GetLTT();
   const Char_t *s = 0;

   s = vLTT==0 ? "all angular distributions are isotropic" :
       vLTT==1 ? "the data are given as Legendre expansion coefficients" :
       vLTT==2 ? "the data are given as tabulated probability distributions" :
       vLTT==3 ? "low energy region is represented by as Legendre coefficients; higher region is represented by tabulated data" :
                "Un-documented";
   cout << "\tLTT = " << vLTT << " : " << s << endl;
   Int_t vLI = GetLI();
   s = vLI==0 ? "not all isotropic" :
       vLI==1 ? "all isotropic" :
               "Un-documented";
   cout << "\tLI = " << vLI << " : " << s << endl;
   Int_t vLCT = GetLCT();
   s = vLCT==1 ? "the data are given in the LAB system" :
       vLCT==2 ? "the data are given in the CM system" :
                "Un-documented";
   cout << "\tLCT = " << vLCT << " : " << s << endl;
}

//______________________________________________________________________________
void TNuSec04::SetTransient()
{
   // sets the transient pointers and ranges

   fTab2List = fTab2Tab1 = 0;
   fYmin = -1;
   fYmax =  1;

   if (IsIsotropic()) {
      fXmin = 1.E-5;
      fXmid = fXmin;
      fXmax = GetParentMat()->GetEMAX();
      return;
   }

   fXmin = ((TNuTab2*) BodyFirst())->GetXmin();
   fXmax = ((TNuTab2*) BodyLast())->GetXmax();
   
   if (GetLTT()==1) {
      fXmid = fXmax;
      fTab2List = (TNuTab2*) BodyFirst();
   }
   else if (GetLTT()==2) {
      fXmid = fXmin;
      fTab2Tab1 = (TNuTab2*) BodyLast();
   }
   else if (GetLTT()==3) {
      fXmid = ((TNuTab2*) BodyFirst())->GetXmax();
      fTab2List = (TNuTab2*) BodyFirst();
      fTab2Tab1 = (TNuTab2*) BodyLast();
   }
   else {
      Error("SetTransient", "Unsupported value of LTT=%d and LI=%d", GetLTT(), GetLI());
   }
}

//______________________________________________________________________________
Double_t TNuSec04::EvalF2(Double_t Ein, Double_t mu, Double_t* /*ps*/) const
{
   // returns normalized d sigma/ d mu for a given incident energy E

   if (IsIsotropic()) return 0.5;

   if (Ein < fXmin || Ein > fXmax) return 0;

   return (Ein <= fXmid) ? fTab2List->EvalF2(Ein, mu)
                         : fTab2Tab1->EvalF2(Ein, mu);
}

