// TNuSec14.cxx  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec14 --- File 14 : Photon angular distributions
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) :
// ZA, AWR, LI, LTT, NK, NI]HEAD                                //                               //
//
// ------------------ body --------------------------------------------------//
// BodyAt(i) = (i < NI) TNuCont for
// [MAT, 14, MT/ EGk, ESk, 0, 0, 0, 0] CONT
//                                                    //
// BodyAt(k) [k=NI, NK) = TNuTab2                       //
//                                                                           //
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec14.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2Tab1.h"
#include "TNuTab2List1.h"
#include "TNuListLegendre.h"

#include <iostream>
using namespace std;

ClassImp(TNuSec14)

//______________________________________________________________________________
void TNuSec14::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 14
   //
   SetHead(new TNuCont(src, "ZA, AWR, LI, LTT, NK, NI]HEAD"));
   //Int_t vLTT = GetLTT();
   //Int_t vLI  = GetLI();

   if (GetLI()==1) return;

   for (Int_t i = 0; i < GetNI(); i++)
      Add(new TNuCont(src, "EG, ES, 0, 0, 0, 0"));

   for (Int_t k = GetNI(); k < GetNK(); k++) {
      if (GetLI()==0 && GetLTT()==1) {
         TNuTab2List1 *tab2 = new TNuTab2List1(src, "EG, ES, 0, 0, NR, NE");
         for (Int_t n=0; n < tab2->GetN2(); n++)
            tab2->Add(new TNuListLegendre(src, "0.0, Ep, 0, 0, NL, 0/ a(E_i)"));
         Add(tab2);
      }
      else if (GetLI()==0 && GetLTT()==2) {
         TNuTab2Tab1 *tab2 = new TNuTab2Tab1(src, "EG, ES, 0, 0, NR, NE");
         for (Int_t n=0; n < tab2->GetN2(); n++)
            tab2->Add(new TNuTab1(src, "0.0, Ep, 0, 0, NR, NP/ p_k(mu,E)"));
         Add(tab2);
      }
      else {
         Error("ImportEndfData", "Unsupported value of LTT=%d and LI=%d",
            GetLTT(), GetLI());
      }
   }
}

//______________________________________________________________________________
void TNuSec14::What() const
{
   TNuSection::What();
   Int_t vLTT=GetLTT();
   const Char_t *s = 0;

   s = vLTT==0 ? "all angular distributions are isotropic" :
       vLTT==1 ? "the data are given as Legendre expansion coefficients" :
       vLTT==2 ? "the data are given as tabulated probability distributions" :
                 "Unrecognized value of LTT";
   cout << "\tLTT = " << vLTT << " : " << s << endl;
   Int_t vLI = GetLI();
   s = vLI==0 ? "not all isotropic" :
       vLI==1 ? "all isotropic" :
               "Un-documented";
   cout << "\tLI = " << vLI << " : " << s << endl;
}

//______________________________________________________________________________
void TNuSec14::SetTransient()
{
   // sets the transient pointers and ranges

   //fTab2List = fTab2Tab1 = 0;

   if (IsIsotropic()) {
      fXmin = fXmid = fXmax = 0;
      return;
   }

   fXmin = BodyFirst()->HeadCont()->GetC1();
   fXmid = BodyAt(GetNI())->HeadCont()->GetC1();
   fXmax = BodyLast()->HeadCont()->GetC1();
}

