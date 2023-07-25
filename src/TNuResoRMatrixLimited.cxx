// TNuResoRMatrixLimited.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

/////////////////////////////////////////////////////////////////////////////
//
// TNuResoRMatrixLimited : public TNuResoResolved
//
// R-Matrix Limited Format (LRF=7)
//
// ------------------ head --------------------------------------------------
//
// HeadAt(0) = RangeCont() =
// [MAT, 2,151/  EL,  EH, LRU, LRF, NRO, NAPS]CONT (range)
//
// HeadAt(1) = GetAPE() =
// [MAT, 2,151/ 0.0, 0.0,   0,   0,  NR,   NP/AP(E) if NRO > 0
//
// HeadAt(2) = SpinCont() = a TNuContList for
//
//[MAT,2,151/ 0.0, 0.0, IFG, KRM, NJS, KRL ]CONT
//(The following record provides all particle-pair descriptions. For KRM=1,2, or 3, the first
//particle-pair is the gamma plus compound nucleus pair.)
//[MAT,2,151/0.0,   0.0,    NPP,    0,     12*NPP, 2*NPP/
//           MA1,   MB1,    ZA1,    ZB1,   IA1,    IB1,
//           Q1,    PNT1,   SHF1,   MT1,   PA1,    PB1,
//           MA2,   MB2,    ZA2,    ZB2,   IA2,    IB1,
//           Q2,    PNT2,   SHF2,   MT2,   PA2,    PB1,
//           -------------------------------------------
//           MANPP, MBNPP,  ZANPP,  ZBNPP, IANPP,  IBNPP ,
//           QNPP,  PNTNPP, SHFNPP, MTNPP, PANPP,  PBNPP ]LIST
//
//
// ------------------ body --------------------------------------------------
//
// At(n) : n-th subsection (for a given L or J) of the resonance data
//  = a TNuRecs
//
//[MAT,2,151/ AJ,     PJ,   KBK,    KPS,    6*NCH,  NCH/
//            IPP1,   L1,   SCH1,   BND1,   APE1,   APT1,
//            IPP2,   L2,   SCH2,   BND2,   APE2,   APT2,
//            -----------------------------------------------
//            IPPNCH, LNCH, SCHNCH, BNDNCH, APENCH, APTNCH]LIST
//(The following record gives the values for resonance energy and widths for each resonance
//in this spin group.)
//[MAT,2,151/ 0.0, 0.0, 0, NRS, 6*NX, NX/
//            ER1, GAM1,1, GAM2,1, GAM3,1, GAM4,1, GAM5,1,
//            GAM6,1, ------------------------- GAMNCH,1,
//            ER2, GAM1,2, GAM2,2, GAM3,2, GAM4,2, GAM5,2,
//            GAM6,2, -------------------------- GAMNCH,2,
//            -----------------------------------------------
//            ERNRS, GAM1, NRS, GAM2,NRS, GAM3,NRS, GAM4,NRS, GAM5,NRS,
//            GAM6,  NRS, ------------------------  GAMNCH,NRS ]LIST
//
// ------------------ notes -------------------------------------------------
//
//
//(If the number of resonances is zero for a spin group, then NRS=0 but NX=1 in this record.)
//Other records may be included here, as described below. If KBK is greater than zero,
//a background R-matrix is given. If KPS is greater than zero, tabulated values exist for
//phase shifts. If KBK=0 and KPS=0, no additional records are needed.
//The above two records, beginning with channel descriptions, are repeated until each
//of the NJS J^pi spin groups has been fully specified.
//
/////////////////////////////////////////////////////////////////////////////

#include "TNuResoRMatrixLimited.h"

//#include "TNuSec02151.h"
#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2.h"
#include "TNuRecsWithCont.h"
#include "TNuContList.h"
#include "TNuContLists.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TPad.h"

#include "TNuMath.h"

using namespace TMath;
using namespace std;

ClassImp(TNuResoRMatrixLimited)

//______________________________________________________________________________
void TNuResoRMatrixLimited::ImportEndfData(TNuEndfIO& src)
{
   // R-Matrix Limited Format (LRF=7)
   //

   // head already has been read
   //SetCont(new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range"));
   //if (GetNRO())
   //   Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));

   //TNuRecsWithCont *data = new TNuRecsWithCont();

   // read cont+list and save them to sub
   TNuContList *clist = new TNuContList();
   clist->SetCont(new TNuCont(src, "0.0, 0.0, IFG, KRM, NJS, KRL"));
   clist->SetList(new TNuList(src, "0.0, 0.0, NPP, 0, 12*NPP, 2*NPP"
      "; MA, MB, ZA, ZB, IA, IB, Q, PNT, SHF, MT, PA, PB"));
   SetSpinCont(clist);

   for (Int_t njs=0; njs < GetNJS(); njs++) {
      // Each spin-group consists of two LISTs and other optional records
      TNuRecs *spinGroup = new TNuRecs();

      TNuList *list1 = new TNuList(src, "AJ, PJ, KBK, KPS, 6*NCH, NCH"
                         "; IPP, L, SCH, BND, APE, APT");
      spinGroup->SetHead(list1);
      TNuList *list2 = new TNuList(src);
      // set label for list2 = "0.0, 0.0, 0, NRS, 6*NX, NX"
      // "; ER, GAM_1, GAM_2, GAM_3, GAM_4, GAM_5 ... GAM_NCH"
      Int_t nch = list1->GetN2();
      TString s("0.0, 0.0, 0, NRS, 6*NX, NX; ER");
      for (Int_t i=1; i <= nch; i++) s.Append(Form(" GAM_%d", i));
      list2->SetLabel(s.Data());

      spinGroup->Add(list2);
      //
      Int_t kbk = list1->GetL1();
      Int_t kps = list1->GetL2();
      if (kbk > 0) {
         // background
         Int_t lbk = src.GetN1();
         if (lbk == 0) {
            // Dummy resonances (LBK=0)
            spinGroup->Add(new TNuList(src, "0.0, 0.0, 0, 0, LBK, 1"));
         }
         else if (lbk == 1) {
            // Option 1. Tabulated complex function of energy (LBK=1)
            spinGroup->Add(new TNuList(src, "0.0, 0.0, 0, 0, LBK, 1"));
            spinGroup->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/ RBR(E)"));
            spinGroup->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/ RBI(E)"));
         }
         else if (lbk == 2) {
            // SAMMY's logarithmic parameterization (LBK=2)
            spinGroup->Add(new TNuList(src, "ED, EU, 0, 0, LBK, 1"
                                        "; R0, R1, R2, S0, S1, 0.0"));
         }
         else if (lbk == 3) {
            // Froehner's parameterization (LBK=3)
            spinGroup->Add(new TNuList(src, "ED, EU, 0, 0, LBK, 1"
                                       "; R0, SO, GA, 0.0, 0.0, 0.0"));
         }
         else {
            Error("ImportEndfData","Unsupported value of LBK=%d", lbk);
         }
      }

      if (kps == 1) {
         // Tabulated phase shifts (KPS=1)
         Int_t lps = src.GetN1();
         if (lps == 0) {
            // Option 0. Hard-sphere phase shifts (LPS=0)
            spinGroup->Add(new TNuList(src, "0.0, 0.0, 0, 0, LPS, 1"
               "; 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"));
         }
         else if (lps == 1) {
            // Option 1. Phase shift is a tabulated complex function of energy (LPS=1)
            spinGroup->Add(new TNuList(src, "0.0, 0.0, 0, 0, LPS, 1"
               "; 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"));
            spinGroup->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/ PSR(E)"));
            spinGroup->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/ PSI(E)"));
         }
         else {
            Error("ImportEndfData","Unsupported value of LPS=%d", lps);
         }
      }

      Add(spinGroup);
   }
}

