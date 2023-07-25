// TNuContListNC.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012


#include "TNuCov.h" //#include "TNuContListNC.h"
#include "TNuEndfIO.h"
#include "TF1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TNuMat.h"

//#include "TNuList.h"

#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////
//
// TNuContListNC - fission product yield data at an energy
//
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuContListNC)

//______________________________________________________________________________
TNuContListNC::TNuContListNC(TNuEndfIO &src, const Char_t* label)
  : TNuContList()
{
   // ctor of TNuContListNC
//For LTY = 0 :
//[MAT,33,MT/ 0.0, 0.0, 0, LTY=0, 0, 0]CONT 
//[MAT,33,MT/ E1, E2, 0, 0, 2*NCI, NCI/{CI, XMTI}]LIST
//
//For LTY = 1, 2, 3
//MAT,33,MT/ 0.0, 0.0, 0, LTY, 0, 0]CONT 
//[MAT,33,MT/ E1, E2, MATS, MTS, 2*NEI+2, NEI/ (XMFS,XLFSS), {EI,WEI} ]LIST

   SetCont(new TNuCont(src, label));
   if (GetLTY() == 0) 
      SetList(new TNuList(src, "E1, E2, 0, 0, 2*NCI, NCI; CI, XMTI"));
   else
      SetList(new TNuList(src, "E1, E2, MATS, MTS, 2*NEI+2, NEI")); // ; (XMFS,XLFSS), {EI,WEI} ]LIST
}

//______________________________________________________________________________
void TNuContListNC::What() const
{
using namespace std;
   TNuContList::What();
   cout << "  LTY = " << GetLTY() << " : flag" << endl;
}

//==============


// TNuListNI.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012


#include "TNuCov.h" //#include "TNuListNI.h"
#include "TNuEndfIO.h"
#include "TF1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TNuMat.h"
#include "TCanvas.h"

//#include "TNuList.h"

#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////
//
// TNuListNI - fission product yield data at an energy
//
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuListNI)


//______________________________________________________________________________
TNuListNI::TNuListNI(TNuEndfIO &src, const Char_t* label)
  : TNuList(src, label), fTH2(0)
{
   // ctor of TNuListNI
}

//______________________________________________________________________________
Double_t TNuListNI::DirectEvalF2(Double_t Ei, Double_t Ej) const
{
   // returns Cov(X_i, Y_j) (for LB=0) or Cov(X_i, Y_j)/(X_i Y_j) (for LB > 0)
   //

   Int_t LB = GetLB();

   if (LB == 0 || LB == 1 || LB==8 || LB==9) {
      // = S_i^k S_j^k F_k
      for (Int_t k=0; k < GetNP(); k++) {
         if (Ei >= fData[2*k]) 
            return (Ej >= fData[2*k] && Ej <= fData[2*k+2]) ?  fData[2*k+1] : 0;
      }
   }
   else if (LB == 2) {
      // = S_i^k S_j^kp F_k F_kp
      for (Int_t k=0; k < GetNP(); k++) {
         if (Ei >= fData[2*k]) {
            for (Int_t kp=0; kp < GetNP(); kp++) {
               if (Ej >= fData[2*kp]) 
                  return fData[2*k+1] * fData[2*kp+1];
            }
         }
      }
   }
   else if (LB == 3) {
      // = S_i^k S_j^l F_k F_l
      for (Int_t k=0; k < GetNP()- GetLT(); k++) {
         if (Ei >= fData[2*k]) {
            for (Int_t l= GetNP()-GetLT(); l < GetNP(); l++) {
               if (Ej >= fData[2*l]) return fData[2*k+1] * fData[2*l+1];
            }
         }
      }
   }
   else if (LB == 4) {
      // = S_i^k S_i^l S_j^k S_j^lp F_k F_l F_lpl
      for (Int_t k=0; k < GetNP()- GetLT(); k++) {
         if (Ei >= fData[2*k]) {
            if (Ej >= fData[2*k] && Ej <= fData[2*k+2]) {
               for (Int_t l= GetNP()-GetLT(); l < GetNP(); l++) {
                  if (Ei >= fData[2*l]) {
                     for (Int_t lp= GetNP()-GetLT(); lp < GetNP(); l++) {
                        if (Ej >= fData[2*lp]) return 
                           fData[2*k+1]*fData[2*l+1]*fData[2*lp+1];
                     }
                  }
               }
            }
         }
      }
   }
   else if (LB == 5) {
      // = S_i^k S_j^kp F_k,kp
      for (Int_t k=0; k < GetNP()- GetLT(); k++) {
         if (Ei >= fData[k]) {
            for (Int_t kp=0; kp < GetNP()- GetLT(); kp++) {
               if (Ej >= fData[kp] && Ej <= fData[kp+1]) {
                  Int_t LS = GetLT();
                  Int_t NE = GetN2();
                  if (LS==0) return fData[NE + (NE-1)*k + kp];
                  else {
                     Int_t i = TMath::Min(k, kp);
                     Int_t j = TMath::Max(k, kp);
                     return fData[NE + i * (2*NE - i - 3)/2 + j];
                  }
               }
            }
         }
      }
   }
   else if (LB == 6) {
      // = S_i^k S_j^l F_k,l
      Int_t NER = GetN2();
      Int_t NEC = (GetNT()-1)/NER;
      for (Int_t k=0; k < NER; k++) {
         if (Ei >= fData[k]) {
            for (Int_t l=0; l < NEC; l++) {
               if (Ej >= fData[NER+l] && Ej <= fData[NER+l+1]) {
                  return fData[NER + NEC + k*(NEC-1) + l];
               }
            }
         }
      }
   }
   else {
      Warning("EvalF2", "Unsupported value of LB=%d", LB);
      return 0;
   }

   Warning("EvalF2", "Out of range: Ei=%e, Ej=%e", Ei, Ej);
   return 0;
}

//______________________________________________________________________________
Double_t TNuListNI::EvalF2(Double_t Ei, Double_t Ej) const
{
   // returns Cov(X_i, Y_j) (for LB=0) or Cov(X_i, Y_j)/(X_i Y_j) (for LB > 0)
   //
   if (!fTH2) MakeTH2();
   if (!fTH2) return 0;
   Int_t bin = fTH2->FindBin(Ei, Ej);
   return fTH2->GetBinContent(bin);
}

//______________________________________________________________________________
void TNuListNI::MakeTH2() const
{
   // Make TH2D for Cov(X_i, Y_j) (for LB=0) or Cov(X_i, Y_j)/(X_i Y_j) (for LB > 0)
   //

   if (fTH2) return;

   const Char_t* name = "NI";
   const Char_t* title = "NI";

   Int_t LB = GetLB();

   if (LB == 0 || LB == 1 || LB==8 || LB==9) {
      // = S_i^k S_j^k F_k
      Int_t Nk= GetNP();
      TArrayD Ek(Nk);
      for (Int_t k=0; k < Nk; k++) Ek[k]= fData[2*k];
      fTH2= new TH2D(name, title, Nk-1, Ek.GetArray(), Nk-1, Ek.GetArray());
      
      for (Int_t k=0; k < Nk-1; k++) {
         fTH2->SetBinContent(k+1, k+1, fData[2*k+1]);
      }
   }
   else if (LB == 2) {
      // = S_i^k S_j^kp F_k F_kp
      Int_t Nk= GetNP();
      TArrayD Ek(Nk);
      for (Int_t k=0; k < Nk; k++) Ek[k]= fData[2*k];
      fTH2= new TH2D(name, title, Nk-1, Ek.GetArray(), Nk-1, Ek.GetArray());

      for (Int_t k=0; k < Nk-1; k++) {
         for (Int_t kp=0; kp < Nk-1; kp++) {
            fTH2->SetBinContent(k+1, kp+1, fData[2*k+1] * fData[2*kp+1]);
         }
      }
   }
   else if (LB == 3) {
      // = S_i^k S_j^l F_k F_l
      Int_t Nk= GetNP() - GetLT(), Nl= GetLT();
      TArrayD Ek(Nk), El(Nl);
      for (Int_t k=0; k < Nk; k++) Ek[k] = fData[2*k];
      for (Int_t l=0; l < Nl; l++) El[l] = fData[2*(Nk+l)];
      fTH2= new TH2D(name, title, Nk-1, Ek.GetArray(), Nl-1, El.GetArray());

      for (Int_t k=0; k < Nk-1; k++) {
         for (Int_t l= 0; l < Nl-1; l++) {
            fTH2->SetBinContent(k+1, l+1, fData[2*k+1] * fData[2*(Nk+l)+1]);
         }
      }
   }
   else if (LB == 4) {
      // = S_i^k S_i^l S_j^k S_j^lp F_k F_l F_lpl
      Int_t Nk= GetNP() - GetLT(), Nl= GetLT();
      TArrayD Ekl(Nk+Nl);
      TArrayI kTab(Nk+Nl), lTab(Nk+Nl);
      Int_t a=0, k=0, l=0, lp=0;

      while ((k < Nk) && (l < Nl)) {
         double ek = fData[2*k];
         double el = fData[2*(Nk + l)];
         kTab[a]=k; lTab[a]=l;
//fprintf(stderr, "a=%d, k=%d/%d, ek=%e,  l=%d/%d, el=%e : ", a, k, Nk, ek, l, Nl, el);
         if (ek <= el) {
            Ekl[a] = ek; k++; a++;
            if (ek == el) l++;
         } else {
            Ekl[a] = el; l++; a++;
         } 
//fprintf(stderr, "  Ekl= %e ::  k=%d, l=%d\n", Ekl[a-1], k, l);
      }
      fTH2= new TH2D(name, title, a-1, Ekl.GetArray(), a-1, Ekl.GetArray());
      for (Int_t i=0; i < a-1; i++) {
         k = kTab[i];
         l = Nk + lTab[i];
         for (Int_t j=0; j < a-1; j++) {
            if (kTab[j] == k) {
               lp = Nk + lTab[j];
               fTH2->SetBinContent(i+1, j+1,
                        fData[2*k+1] * fData[2*l+1] * fData[2*lp+1]);
            }
         }
      }
   }
   else if (LB == 5) {
      // = S_i^k S_j^kp F_k,kp
      Int_t Nk= GetN2();
      fTH2= new TH2D(name, title, Nk-1, fData, Nk-1, fData);
      for (Int_t k=0; k < Nk-1; k++) {
         for (Int_t kp=0; kp < Nk-1; kp++) {
            Int_t LS = GetL1();
            Int_t NE = GetN2();
            Int_t ind;
            if (LS==0) ind = NE + (NE-1)*k + kp;
            else {
               Int_t i = TMath::Min(k, kp);
               Int_t j = TMath::Max(k, kp);
               ind = NE + i * (2*NE - i - 3)/2 + j;
            }
            fTH2->SetBinContent(k+1, kp+1, fData[ind]);
         }
      }
   }
   else if (LB == 6) {
      // = S_i^k S_j^l F_k,l
      Int_t NER = GetN2();
      Int_t NEC = (GetN1()-1)/NER;

      fTH2= new TH2D(name, title, NER-1, fData, NEC-1, fData+NER);
      for (Int_t k=0; k < NER-1; k++) {
         for (Int_t l=0; l < NEC-1; l++) {
            fTH2->SetBinContent(k+1, l+1, fData[NER + NEC + k*(NEC-1) + l]);
         }
      }
   }
   else {
      Warning("MakeTH2", "Unsupported value of LB=%d", LB);
   }
   if (fTH2) fTH2->SetStats(kFALSE);
}

//______________________________________________________________________________
void TNuListNI::DrawTH2(Option_t* opt)
{
   // 
   if (!fTH2) MakeTH2();
   if (fTH2) {
      fTH2->Draw(opt); 
      //TCanvas *c1 = TNudy::GetCanvas();
      //if (c1) c1->Update();
   }
}

//______________________________________________________________________________
void TNuListNI::What() const
{
using namespace std;
   TNuList::What();
   //cout << "  LTY = " << GetLTY() << " : flag" << endl;
}

//===

// TNuContListsCov33.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012


#include "TNuCov.h" //#include "TNuContListsCov33.h"
#include "TNuEndfIO.h"
#include "TF1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TNuMat.h"

//#include "TNuList.h"

#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////
//
// TNuContListsCov33 - fission product yield data at an energy
//
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuContListsCov33)


//______________________________________________________________________________
TNuContListsCov33::TNuContListsCov33(TNuEndfIO &src, const Char_t* label)
  : TNuContLists()
{
   // ctor of TNuContListsCov33
// TNuContListsCov33 - SubSection of Sec33.
//    Each subsection of the section (MAT,33,MT) is used to describe
//     a single covariance matrix. It is the covariance matrix of:
//     - 1st set of energy-dependent cross sections given in section (MAT,3,MT) 
//     - 2nd set of energy-dependent cross sections given in section 
//       (MAT1,MF1,MT1) when MF1=3 or (MAT1,MF1,MT1.LFS1) when MF1=10 
/*
[MAT,MF, MT/ XMF1, XLFS1, MAT1, MT1, NC, NI] CONT
first TNuContListNC
-------------------------------
-------------------------------
NC-th TNuContListNC
first TNuListNI_1
-------------------------------
-------------------------------
NI-th TNuListNI_NI
*/

   SetCont(new TNuCont(src, label));
   for (Int_t nc = 0; nc < GetNC(); nc++)
      AddToHead(new TNuContListNC(src));
   for (Int_t ni = 0; ni < GetNI(); ni++)
      Add(new TNuListNI(src));
}

//______________________________________________________________________________
void TNuContListsCov33::What() const
{
using namespace std;
   TNuContLists::What();
   //cout << "  LTY = " << GetLTY() << " : flag" << endl;
}

//===

// TNuContListsCov34.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012


#include "TNuCov.h" //#include "TNuContListsCov34.h"
#include "TNuEndfIO.h"
#include "TF1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TNuMat.h"

//#include "TNuList.h"

#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////
//
// TNuContListsCov34 - 
//              
//
//for 
//[MAT,34,MT/ 0.0, 0.0, L , L1, LCT, NI]CONT
//[MAT,34,MT/ 0.0, 0.0, LS_1 , LB_1 , NT_1 , NE_1 / {Data_1 }] LIST
//----------------------------------
//----------------------------------
//[MAT,34,MT/ 0.0, 0.0, LS_NI , LBS_NI , NTS_NI, NE_NI /{Data_NI}] LIST
//
// {Data} is For LB=5, sequence {Ek} {Fk,k};
// for LB=6, sequence {Ek} {Fk,l} (as in File 33)`
//
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuContListsCov34)


//______________________________________________________________________________
TNuContListsCov34::TNuContListsCov34(TNuEndfIO &src, const Char_t* label)
  : TNuContLists()
{
   // ctor of TNuContListsCov34
   SetCont(new TNuCont(src, label));
   for (Int_t ni = 0; ni < GetNI(); ni++)
      Add(new TNuListNI(src));
}

//______________________________________________________________________________
void TNuContListsCov34::What() const
{
using namespace std;
   TNuContLists::What();
   //cout << "  LTY = " << GetLTY() << " : flag" << endl;
}

//====

// TNuCovMatrix.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012


#include "TNuCov.h" //#include "TNuCovMatrix.h"
#include "TNuEndfIO.h"
#include "TF1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TNuMat.h"

//#include "TNuList.h"

#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////
//
// TNuCovMatrix - fission product yield data at an energy
//
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuCovMatrix)

//______________________________________________________________________________
TNuCovMatrix::TNuCovMatrix(TNuEndfIO &src, const Char_t* label)
  : TNuRecsWithCont()
{
   // ctor of TNuCovMatrix
//[MAT,MF, MT/ QM, QI, IZAP, LFS, 0, NL]CONT
//<TNuContListsCov33 for n = 1>
//...
//<TNuContListsCov33 for n = NL>

   SetCont(new TNuCont(src, label));
   for (Int_t n = 0; n < GetNL(); n++)
      Add(new TNuContListsCov33(src));
}

//______________________________________________________________________________
void TNuCovMatrix::What() const
{
using namespace std;
   TNuRecsWithCont::What();
   //cout << "  LTY = " << GetLTY() << " : flag" << endl;
}

//====

// TNuSubSec34.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012


#include "TNuCov.h" //#include "TNuSubSec34.h"
#include "TNuEndfIO.h"
#include "TF1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TNuMat.h"

//#include "TNuList.h"

#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////
//
// TNuSubSec34 - 
//              
//
//for 
//[MAT,34,MT/ 0.0, 0.0, MAT1, MT1, NL, NL1]CONT (MAT1=0)
//[0.0, 0.0,   L_1,   L1_1, LCT,   NI_1 ] TNuContListsCov34 
//----------------------------------
//----------------------------------
//[0.0, 0.0, L_NSS, L1_NSS, LCT, NI_NSS ] TNuContListsCov34 
// 
// with NSS = NL * NL1
//
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuSubSec34)

//______________________________________________________________________________
TNuSubSec34::TNuSubSec34(TNuEndfIO &src)
  : TNuRecsWithCont()
{
   // ctor of TNuSubSec34

   SetCont(new TNuCont(src, "0.0, 0.0, MAT1, MT1, NL, NL1"));

   Int_t NSS = (src.GetMT() == GetMT1()) ? GetNL() * (GetNL()+1)/2 
                                         : GetNL() * GetNL1();
   for (Int_t n = 0; n < NSS; n++) {
      //Add(new TNuContListsCov34(src, "0.0, 0.0, L, L1, LCT, NI"));
      TNuContListsCov34* clc = new TNuContListsCov34();
      clc->SetCont(new TNuCont(src, "0.0, 0.0, L, L1, LCT, NI"));
      for (Int_t ni = 0; ni < clc->GetNI(); ni++)
         clc->Add(new TNuListNI(src, "0.0, 0.0, LS, LB, NT, NE"));
      Add(clc);
   }
}

//______________________________________________________________________________
void TNuSubSec34::What() const
{
using namespace std;
   TNuRecsWithCont::What();
   //cout << "  LTY = " << GetLTY() << " : flag" << endl;
}

//===

// TNuSec31.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec31 - reaction cross sections
/* Begin_Latex
#sigma_{c}(E_{n})
End_Latex
where En is the indident energy (in eV) and
c is the channel index given by the MT value.
*/
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCov.h" //#include "TNuSec31.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
//#include "TROOT.h"

#include <iostream>

ClassImp(TNuSec31)

//______________________________________________________________________________
void TNuSec31::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 3
   //
// [MAT, 31, MT/ ZA, AWR, 0,    0,  0, NL] TNuCovMatrix

   //SetHead(new TNuCovMatrix(src, "ZA, AWR, 0,  0,  0,  NL/HEAD"));
   TNuCovMatrix* cm = new TNuCovMatrix();
   cm->SetCont(new TNuCont(src, "ZA, AWR, 0,  0,  0,  NL"));
   for (Int_t n = 0; n < cm->GetNL(); n++) {
      TNuContListsCov33* clc = new TNuContListsCov33();
      clc->SetCont(new TNuCont(src, " XMF1, XLFS1, MAT1, MT1, NC, NI"));
      for (Int_t nc = 0; nc < clc->GetNC(); nc++)
         clc->AddToHead(new TNuContListNC(src, "0.0, 0.0, 0, LTY, 0, 0"));
      for (Int_t ni = 0; ni < clc->GetNI(); ni++)
         clc->Add(new TNuListNI(src, "0.0, 0.0, 0, LB, 2, 1"));
      cm->Add(clc);
   }
   SetHead(cm);
}

//______________________________________________________________________________
void TNuSec31::What() const
{
   using namespace std;
   TNuSection::What();

   //cout << "\tQM = " << GetQM() << " : Mass-difference Q value (eV)" << endl;
   //cout << "\tQI = " << GetQI() << " : Reaction Q value (eV)" << endl;
   //cout << "\tLR = " << GetLR() << " : " << GetLRDescription() << endl;
}


//===

// TNuSec33.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec33 - reaction cross sections
/* Begin_Latex
#sigma_{c}(E_{n})
End_Latex
where En is the indident energy (in eV) and
c is the channel index given by the MT value.
*/
//
// [MAT, 33, MT/ ZA, AWR, 0,    0,  0, NL] TNuCovMatrix
// [MAT, 33,  0/ 0.0, 0.0,  0,  0,  0,  0] SEND
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCov.h" //#include "TNuSec33.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
//#include "TROOT.h"

#include <iostream>

ClassImp(TNuSec33)

//______________________________________________________________________________
void TNuSec33::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 3
   //
// [MAT, 33, MT/ ZA, AWR, 0,    0,  0, NL] TNuCovMatrix

   //SetHead(new TNuCovMatrix(src, "ZA, AWR, 0,  0,  0,  NL/HEAD"));
   
   TNuCovMatrix* cm = new TNuCovMatrix();
   cm->SetCont(new TNuCont(src, "ZA, AWR, 0,  0,  0,  NL"));
   for (Int_t n = 0; n < cm->GetNL(); n++) {
      TNuContListsCov33* clc = new TNuContListsCov33();
      clc->SetCont(new TNuCont(src, " XMF1, XLFS1, MAT1, MT1, NC, NI"));
      for (Int_t nc = 0; nc < clc->GetNC(); nc++)
         clc->AddToHead(new TNuContListNC(src, "0.0, 0.0, 0, LTY, 0, 0"));
      for (Int_t ni = 0; ni < clc->GetNI(); ni++) {
         const Char_t* label = (src.GetL2()==5) ? 
            "0.0, 0.0, LS, LB=5, NT, NER" : " 0.0, 0.0, LT, LB, NT, NP";
         clc->Add(new TNuListNI(src, label));
      }
      cm->Add(clc);
   }
   SetHead(cm);
}

//______________________________________________________________________________
void TNuSec33::What() const
{
   using namespace std;
   TNuSection::What();

   //cout << "\tQM = " << GetQM() << " : Mass-difference Q value (eV)" << endl;
   //cout << "\tQI = " << GetQI() << " : Reaction Q value (eV)" << endl;
   //cout << "\tLR = " << GetLR() << " : " << GetLRDescription() << endl;
}

// xxx
//===

// TNuSec34.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec34 - reaction cross sections
// ------------------ head --------------------------------------------------
// HeadAt(0) :
//[MAT,34,MT/ ZA, AWR, 0, LTT, 0, NMT1]HEAD
//
// ------------------ body --------------------------------------------------
// At(n) :
// n-th TNuSubSec34
//
/* Begin_Latex
#sigma_{c}(E_{n})
End_Latex
where En is the indident energy (in eV) and
c is the channel index given by the MT value.
*/
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCov.h" //#include "TNuSec34.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
//#include "TROOT.h"

#include <iostream>

ClassImp(TNuSec34)

//______________________________________________________________________________
void TNuSec34::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 3
   //
   SetHead(new TNuCont(src, "ZA, AWR, 0, LTT, 0, NMT1"));
   for (Int_t n = 0; n < GetNMT1(); n++) {
      Add(new TNuSubSec34(src));
   }
}

//______________________________________________________________________________
void TNuSec34::What() const
{
   using namespace std;
   TNuSection::What();

   //cout << "\tQM = " << GetQM() << " : Mass-difference Q value (eV)" << endl;
   //cout << "\tQI = " << GetQI() << " : Reaction Q value (eV)" << endl;
   //cout << "\tLR = " << GetLR() << " : " << GetLRDescription() << endl;
}

//===

// TNuSec35.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec35 - reaction cross sections
/* Begin_Latex
#sigma_{c}(E_{n})
End_Latex
where En is the indident energy (in eV) and
c is the channel index given by the MT value.
*/
// ------------------ head --------------------------------------------------//
// HeadAt(0) :
// [MAT,35,MT/ ZA, AWR, 0, 0, NK, 0] HEAD
//
// ------------------ body --------------------------------------------------//
// At(n) = n-th TNuListNI, n=0, NK-1                                 //
//
//       = [MAT,35,MT/ E1, E2, LS, LB, NT, NE/{E'_k},{F_k,k′}] LIST (LS=1,LB=7)
//                                                                           //
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCov.h" //#include "TNuSec35.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
//#include "TROOT.h"

#include <iostream>

ClassImp(TNuSec35)

//______________________________________________________________________________
void TNuSec35::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 3
   //
   SetHead(new TNuCont(src, "ZA, AWR, 0, 0, NK, 0"));
   for (Int_t n = 0; n < GetNK(); n++)
      Add(new TNuListNI(src, "E1, E2, LS, LB, NT, NE")); // /{E'_k},{F_k,k′}] LIST (LS=1,LB=7)
}

//______________________________________________________________________________
void TNuSec35::What() const
{
   using namespace std;
   TNuSection::What();

   //cout << "\tQM = " << GetQM() << " : Mass-difference Q value (eV)" << endl;
   //cout << "\tQI = " << GetQI() << " : Reaction Q value (eV)" << endl;
   //cout << "\tLR = " << GetLR() << " : " << GetLRDescription() << endl;
}

//===

// TNuSec40.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec40 - reaction cross sections
/* Begin_Latex
#sigma_{c}(E_{n})
End_Latex
where En is the indident energy (in eV) and
c is the channel index given by the MT value.
*/
//
// [MAT,40,MT/ ZA, AWR, LIS, 0, NS, 0] HEAD
// 
// ---------------- body (NS elements)
// At(n) = TNuCovMatrix for
// [MAT,40, MT/ QM, QI, IZAP, LFS, 0, NL] TNuCovMatrix
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCov.h" //#include "TNuSec40.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
//#include "TROOT.h"

#include <iostream>

ClassImp(TNuSec40)

//______________________________________________________________________________
void TNuSec40::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 40
   //
   SetHead(new TNuCovMatrix(src, "ZA, AWR, LIS, 0, NS, 0"));
   for (Int_t n = 0; n < GetNS(); n++) {
      //Add(new TNuCovMatrix(src, "QM, QI, IZAP, LFS, 0, NL")); //] TNuCovMatrix
      TNuCovMatrix* cm = new TNuCovMatrix();
      cm->SetCont(new TNuCont(src, "QM, QI, IZAP, LFS, 0, NL"));
      for (Int_t n = 0; n < cm->GetNL(); n++) {
         //Add(new TNuContListsCov33(src));
         TNuContListsCov33* clc = new TNuContListsCov33();
         clc->SetCont(new TNuCont(src, " XMF1, XLFS1, MAT1, MT1, NC, NI"));
         for (Int_t nc = 0; nc < clc->GetNC(); nc++)
            clc->AddToHead(new TNuContListNC(src));
         for (Int_t ni = 0; ni < clc->GetNI(); ni++)
            clc->Add(new TNuListNI(src));
         cm->Add(clc);
      }
      Add(cm);
   } 
}

//______________________________________________________________________________
void TNuSec40::What() const
{
   using namespace std;
   TNuSection::What();

   //cout << "\tQM = " << GetQM() << " : Mass-difference Q value (eV)" << endl;
   //cout << "\tQI = " << GetQI() << " : Reaction Q value (eV)" << endl;
   //cout << "\tLR = " << GetLR() << " : " << GetLRDescription() << endl;
}

// TNuSec32.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

/////////////////////////////////////////////////////////////////////////////
//
// TNuSec32 : Resonance parameter data
//
// [MAT, 2,151/ ZA, AWR, 0, 0, NIS, 0/HEAD
// (i-th TNuSubIsotope, i=0,NIS-1)
//
//------------- head (1 element)
//HeadAt(0) = a TNuCont for
//[MAT, 2,151/ ZA, AWR, 0, 0, NIS, 0]HEAD
//
//------------- body (NIS elements)
//At(n) = n-th TNuSubIsotope, n=[0, NIS).
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// TNuSubIsotope : public TNuRecsWithCont
//
//   = Resonance parameters for an isotope
//
//------------- head (1 element)
//HeadAt(0) = a TNuCont for
//[MAT, 2,151/ ZAI, ABN, 0, LFW, NER, 0]CONT (isotope)
//
//------------- body (NER elements)
//At(n) = n-th TNuResonance, n=0, NER-1
//
/////////////////////////////////////////////////////////////////////////////

#include "TNuCov.h" // #include "TNuSec32.h"
#include "TNuResonance.h"

#include "TNuResoResolved.h"
#include "TNuResoBrightWigner.h"
#include "TNuResoReichMoore.h"
#include "TNuResoAdlerAdler.h"
#include "TNuResoRMatrixLimited.h"


#include "TNuResoUnresolved.h"

#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2.h"
#include "TNuContLists.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TPad.h"

#include "TNuMath.h"

#include "TArrayD.h"

using namespace TMath;
using namespace std;

ClassImp(TNuSec32)

//______________________________________________________________________________
//TNuSec32::TNuSec32(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), TNuVResonance(), fIsMeshed(kFALSE)
TNuSec32::TNuSec32(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt)
{
   // ctor

   //fAccuracy = GetDefaultAccuracy();
}

//______________________________________________________________________________
void TNuSec32::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 5
   //

   SetHead(new TNuCont(src, " ZA, AWR, 0, 0, NIS, 0"));
   for (Int_t iso=0; iso < GetNIS(); iso++) {
      TNuSubIsotopeCov *subIsotope = new TNuSubIsotopeCov();
      subIsotope->SetTitle("Isotope subsection");
      TNuCont *cont = new TNuCont(src, "ZAI, ABN, 0, LFW, NER, 0 /isotope");
      subIsotope->SetCont(cont);
      for (Int_t ner=0; ner < subIsotope->GetNER(); ner++) {

         // EL, EH, LRU, LRF, NRO, NAPS /range cont

         TNuCont *range = new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range");

         Int_t LRU = range->GetL1();
         Int_t LRF = range->GetL2();

         TNuResonanceCov *resonance = 0;
         if (LRU == 0) {
            //resonance = new TNuResonance();
            resonance = new TNuResonanceCov();
         }
         else if (LRU == 1) {
            // Resolved Resonance Parameters (LRU=1)
            if (LRF==1) {
               // SLBW (LRF=1)
               //resonance= new TNuResoSLBW();
               resonance = new TNuResonanceCov();
            }
            else if (LRF==2) {
               // MLBW (LRF=2)
               //resonance = new TNuResoMLBW();
               resonance = new TNuResonanceCov();
            }
            else if (LRF == 3) {
               // Reich-Moore (LRF=3)
               //resonance = new TNuResoReichMoore();
               resonance = new TNuResonanceCov();
            }
            else if (LRF == 4) {
               // Adler-Adler (LRF=4)
               //resonance = new TNuResoAdlerAdler();
               resonance = new TNuResonanceCov();
            }
            else if (LRF==7) {
               // R-Matrix Limited Format (LRF=7)
               //resonance = new TNuResoRMatrixLimited();
               resonance = new TNuResonanceCov();
            }
            else {
               Error("ImportEndfData", "Unsupported value of LRF = %d", LRF);
               return;
            }
         }
         else if (LRU == 2) {
            // Unresolved Resonance Parameters (LRU=2)
            //resonance = new TNuResoUnresolved();
            resonance = new TNuResonanceCov();
         }
         else {
            Error("ImportEndfData", "Unsupported value of LRU = %d", LRU);
            return;
         }

         // set the head of the resonance data
         //resonance->SetRangeCont(range);
         //if (range->GetN1()) // if NRO != 0
         //   //resonance->SetAPE(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));
         //   resonance->SetAPECov(new TNuContListsCov(src, "0.0, 0.0, 0, 0, 0, NI/AP(E)")); // xx
         //// and important only the remaining data
         resonance->ImportEndfData(src, range);
         subIsotope->Add(resonance);
      }
      Add(subIsotope);
   }
}

// --------------------------------------------------------------------
// Sub-sections for TNuSubRange
// --------------------------------------------------------------------
ClassImp(TNuSubIsotopeCov)

// TNuResonanceCov.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

/////////////////////////////////////////////////////////////////////////////
//
// TNuResonanceCov : public TNuRecsWithCont
//
//   = A specific representation of resonance parameters
//
// ------------------ head --------------------------------------------------
//
// HeadAt(0) = RangeCont() =
// [MAT, 2,151/  EL,  EH, LRU, LRF, NRO, NAPS]CONT (range)
//
// HeadAt(1) = GetAPE() =
// [MAT, 2,151/ 0.0, 0.0,   0,   0,  NR,   NP/AP(E) if NRO > 0
//
// HeadAt(2) = SpinCont() =
// [MAT, 2,151/ SPI, AP, 0, 0, NLS, 0]CONT
//
// ------------------ body --------------------------------------------------
//
// At(n) : n-th subsection (for a given L or J) of the resonance data
//
// ------------------ notes -------------------------------------------------
//
//
/////////////////////////////////////////////////////////////////////////////

#include "TNuCov.h" // #include "TNuResonanceCov.h"

#include "TNuSec02.h"


//#include "TNuResoResolved.h"
//#include "TNuResoUnresolved.h"

#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2.h"
#include "TNuContLists.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TPad.h"

#include "TNuMath.h"

#include "TArrayD.h"

#include <iostream>
#include <iomanip>
using namespace std;
using namespace TMath;
#include "TNuIntg.h"

ClassImp(TNuResonanceCov)

//______________________________________________________________________________
void TNuResonanceCov::What() const
{
   TNuObject::What();

   if (RangeCont())    RangeCont()->What();
   //if (GetAPE())      GetAPE()->What();
   if (SpinCont()) SpinCont()->What();
   //cout << "Params" << endl;
   cout << "   Entries = " << GetEntries() << endl;
}

//______________________________________________________________________________
void TNuResonanceCov::ls(Option_t* option) const
{
   cout << Form("(%s) %s at %p: ",ClassName(), GetName(), this);
   cout << " / " << GetTitle() << endl;

   if (RangeCont())    RangeCont()->ls(option);
   //if (GetAPE())      GetAPE()->ls(option);
   if (SpinCont()) SpinCont()->ls(option);

   //cout << "Table of records" << endl;
   for (Int_t n=0; n< GetSize(); n++) {
      TNuObject *obj = BodyAt(n);
      if (obj) {
         cout << endl;
         cout << setw(5) << n << ". ";
         obj->ls(option);
      }
   }
}

//______________________________________________________________________________
void TNuResonanceCov::ImportEndfData(TNuEndfIO& src, TNuCont* range)
{
   // Import Section data of File 5
   //

   // EL, EH, LRU, LRF, NRO, NAPS /range cont

   //TNuCont *range = new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range");
   // set the head of the resonance data
   SetRangeCont(range);
   if (range->GetN1()) // if NRO != 0
      SetAPECov(new TNuContListsCov33(src, "0.0, 0.0, 0, 0, 0, NI/AP(E)")); // xx
      //resonance->SetAPE(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));

   Int_t LRU = range->GetL1();
   Int_t LRF = range->GetL2();

   Int_t LCOMP = src.GetL2(); // [MAT,32,151/ SPI, AP, 0, LCOMP, NLS, ISR]CONT
   //Int_t NLS   = src.GetN1(); // [MAT,32,151/ SPI, AP, 0, LCOMP, NLS, ISR]CONT
   Int_t ISR   = src.GetN2(); // [MAT,32,151/ SPI, AP, 0, LCOMP, NLS, ISR]CONT

   //if (LCOMP == 0 && LRU == 1 && (LRF==1 || LRF ==2)) goto LCOMP_0;
   //else if (LCOMP == 1 && LRU == 1 && (LRF==1 || LRF==2 || LRF==3 || LRF==4 || LRF==7)) goto LCOMP_1;
   //else if (LCOMP == 2) goto LCOMP_2;
   //else return;

Info("IO", "LRU=%d, LRF=%d, LCOMP=%d", LRU, LRF, LCOMP);
   if (LRU == 1 && (LRF==1 || LRF == 2)) {
      // SLBW and MLBW (LRF=1 or 2)
      if (LCOMP == 0) { // 32.2.1 Compatible Resolved Resonance Format (LCOMP=0)
         SetSpinCont(new TNuCont(src, "SPI, AP, 0, LCOMP, NLS, ISR"));
         if (ISR > 0) Add(new TNuCont(src, "0.0, DAP, 0, 0, 0, 0"));
      
         for (Int_t nls=0; nls < GetNLS(); nls++)
            Add(new TNuList(src, "AWRI, 0.0, L, 0, 18*NRS, NRS"
               "; ER, AJ, GT, GN, GG, GF, DE2, DN2, DNDG, DG2, DNDF, DGDF, DF2, 0.0, 0.0, 0.0, 0.0"));
               //"; ER, AJ, GT, GN, GG, GF, DE2, DN2, DNDG, DG2, DNDF, DGDF, DF2, DJDN, DJDG, DJDF, DJ2"));
         return;
      } else if (LCOMP == 1) { // 32.2.2.1 General Resolved Resonance Formats (LCOMP=1)
         SetSpinCont(new TNuCont(src, "SPI, AP, 0, LCOMP=1, NLS, ISR"));
         if (ISR > 0) Add(new TNuCont(src, "0.0, DAP, 0, 0, 0, 0"));
         TNuCont* cont = new TNuCont(src, "AWRI, 0.0, 0, 0, NSRS, NLRS");
         Add(cont);

         for (Int_t n=0; n < cont->GetN1(); n++)
            Add(new TNuList(src, "0.0, 0.0, MPAR, 0, NVS+6*NRB, NRB")); //"; ER, AJ, GT, GN, GG, GF");
         //for (Int_t n=0; n < cont->GetN2(); n++)
         //   Add(new TNuListNI(src, "0.0, 0.0, IDP, LB, NT, NE")); // / { Ek }, {F(5)}] LIST 
         //return;
      }
      else if (LCOMP == 2) { // 3.2.3.1 Resolved Resonance Compact Covariance Format (LCOMP=2)
         SetSpinCont(new TNuCont(src, "SPI, AP, 0, LCOMP=2, 0, ISR"));
         if (ISR > 0) Add(new TNuCont(src, "0.0, DAP, 0, 0, 0, 0"));
         Add(new TNuList(src, "AWRI, QX, 0, LRX, 12*NRSA, NRSA"
           "; ER, AJ, GT, GN, GG, GF,  DER, 0.0, 0.0, DGN, DGG, DGF"));
         Add(new TNuIntg(src, "0.0, 0.0, NDIGIT, NNN, NM, 0"));
         return;
      }
   }
   else if (LRU == 1 && LRF == 3) {
      // Reich-Moore (LRF=3)
      //
      if (LCOMP == 1) {
         // 32.2.2.2 General Resolved Resonance Formats (LCOMP=1)
         SetSpinCont(new TNuCont(src, "SPI, AP, 0, LCOMP=1, NLS, ISR"));
         if (ISR > 0) Add(new TNuList(src, "0.0, 0.0, 0, 0, MLS, 1"));
         TNuCont* cont = new TNuCont(src, "AWRI, 0.0, 0, 0, NSRS, NLRS");
         Add(cont);
      
         Add(new TNuList(src, "AWRI, APL, 0, 0, 12*NRSA, NRSA"
           "; ER, AJ, GN, GG, GFA, GFB,  DER, 0.0, DGN, DGG, DGFA, DGFB"));
         return;
      }
      else if (LCOMP == 2) { // 32.2.3.2 Resolved Resonance Compact Covariance Format (LCOMP=2)
         Int_t ISR = src.GetN2();
         SetSpinCont(new TNuCont(src, "SPI, AP, LAD, LCOMP=2, 0, ISR"));
         if (ISR == 1) Add(new TNuList(src, "0.0, 0.0, 0, 0, MLS, 1"));
         Add(new TNuList(src, "AWRI, APL, 0, 0, 12*NRSA, NRSA"
           "; ER, AJ, GN, GG, GFA, GFB,  DER, 0.0, DGN, DGG, DGFA, DGFB"));
         Add(new TNuIntg(src, "0.0, 0.0, NDIGIT, NNN, NM, 0"));
         return;
      }
   }
   else if (LRU == 1 && LRF == 4) {
      // Adler-Adler (LRF=4)
      //
      if (LCOMP == 1) { // 32.2.2.3 General Resolved Resonance Formats (LCOMP=1)
         SetSpinCont(new TNuCont(src, "SPI, AP, 0, LCOMP=1, NLS, ISR"));
         if (ISR > 0) Add(new TNuList(src, "0.0, 0.0, 0, 0, MLS, 1"));
         TNuCont* cont = new TNuCont(src, "AWRI, 0.0, 0, 0, NSRS, NLRS");
         Add(cont);
      
         for (Int_t n=0; n < cont->GetN1(); n++)
            Add(new TNuList(src, "0.0, 0.0, MPAR, 0, NVS+6*NRB, NRB")); // "; ER, AJ, GN, GG, GFA, GFB");
// we delete belows
         //for (Int_t n=0; n < cont->GetN2(); n++)
         //   Add(new TNuListNI(src, "0.0, 0.0, IDP, LB, NT, NE")); // / { Ek }, {F(5)}] LIST 
         //return;
      }
   }
   else if (LRU == 1 && LRF == 7) {
      // R-Matrix Limited Format (LRF=7)
      //
      if (LCOMP == 1) { // 32.2.2.4 General Resolved Resonance Formats (LCOMP=1)
         SetSpinCont(new TNuCont(src, "0.0, 0.0, 0, LCOMP, 0, ISR"));
         if (ISR > 0) Add(new TNuList(src, "0.0, 0.0, 0, 0, JCH, (1+(NJCH-1)/6)"));
         TNuCont* cont = new TNuCont(src, "AWRI, 0.0, 0, 0, NSRS, NLRS");
         Add(cont);

         // // read cont+list and save them to sub
         // TNuContList *clist = new TNuContList();
         // clist->SetCont(new TNuCont(src, "0.0, 0.0, IFG, KRM, NJS, KRL"));
         // clist->SetList(new TNuList(src, "0.0, 0.0, NPP, 0, 12*NPP, 2*NPP"
         //    "; MA, MB, ZA, ZB, IA, IB, Q, PNT, SHF, MT, PA, PB"));
         // SetSpinCont(clist);
      
         //for (Int_t njs=0; njs < GetNJS(); njs++) {
         for (Int_t njs=0; njs < cont->GetN1(); njs++) {
            TNuContList* clist = new TNuContList();
            clist->SetCont(new TNuCont(src, "0.0, 0.0, NJSX, 0, 0, 0"));
            clist->SetList(new TNuList(src, "0.0, 0.0, NCH, NRB, 6*NX, NX"));
            Add(clist);
         }
         Add(new TNuList(src, "0.0, 0.0, 0, 0, N, NPARB/V"));
         return;
      }
      else if (LCOMP == 2) { // 32.2.3.3 Resolved Resonance Compact Covariance Format (LCOMP=2)
         Int_t NJS = src.GetN1();
         Int_t ISR = src.GetN2();
         SetSpinCont(new TNuCont(src, "0.0, 0.0, IFG, LCOMP, NJS, ISR"));
         if (ISR > 0) Add(new TNuList(src, "0.0, 0.0, 0, 0, NJCH, (1+(NJCH-1)/6)"));
         Add(new TNuList(src, "0.0, 0.0, NPP, NJSX, 12*NPP, 2*NPP"
           "; MA, MB, ZA, ZB, IA , IB ,  Q, PNT, SHF, MT, PA, PB"));
         for (Int_t njs=0; njs < NJS; njs++) {
            Add(new TNuList(src, "AJ, PJ, 0, 0, 6*NCH, NCH"
              "; PPI, L, SCH, BND, APE, APT"));
            Add(new TNuList(src, "0.0, 0.0, 0, NRSA, 12*NX, NX"));
         }

         Add(new TNuIntg(src, "0.0, 0.0, NDIGIT, NNN, NM, 0"));
         return;
      }
   }
   else if (LRU == 2) {
      // 32.2.4 Unresolved Resonance Parameters (LRU=2)
      SetSpinCont(new TNuCont(src, "SPI, AP, 0, 0, NLS, 0"));
      
      for (Int_t nls=0; nls < GetNLS(); nls++) {
         Add(new TNuList(src, "AWRI, 0.0, L, 0, 6*NJS, NJS"
            "; D, AJ, AMUN, GN0, GG, 0.0"));
      }
      Add(new TNuList(src, "0.0, 0.0, MPAR, 0,NP*(NP+1)/2,NPAR"));
      return;
   }
}


