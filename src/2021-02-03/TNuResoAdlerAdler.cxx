// TNuResoAdlerAdler.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

/////////////////////////////////////////////////////////////////////////////
//
// TNuResoAdlerAdler : public TNuResoResolved
//
//   = Adler-Adler (LRF=4)
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
// [MAT, 2,151/ SPI,  AP,   0,    0,    NLS,    0  ] CONT
//
// HeadAt(3) =
// [MAT, 2,151/ AWRI, 0.0,  LI,   0,    6*NX,   NX
//              AT1,  AT2,  AT3,  AT4,  BT1,    BT2,
//              AF1, -------------------------, BF2,
//              AC1, -------------------------, BC2] LIST
//
//
// ------------------ body --------------------------------------------------
//
// At(n) = n-th subsection for a given L (n=0, NJS-1) =
// = a TNuContLists for
//
//[MAT, 2,151/ 0.0,  0.0,  L,    0,    NJS,    0  ] CONT(l)
//[MAT, 2,151/ AJ,   0.0,  0,    0,    12*NLJ, NLJ/
//             DET1, DWT1, GRT1, GIT1, DEF1,   DWF1,
//             GRF1, GIF1, DEC1, DWC1, GRC1,   GIC1,
//             DET2, DWT2, GIC2, ------------------
//             DET3,-------------------------------
//             ------------------------------------
//             -----------------------------, GICNLJ] LIST
// The last LIST record is repeated for each J-value
// (there will be NJS such LIST records).
//
// ------------------ notes -------------------------------------------------
//
// Note that if NX=2 then the quantities AF1 through BF2 will not be given
// in the first LIST record.
// Also, if LI6=7 then certain of the parameters for each level
// may be set to zero, i.e., the fields for
// parameters not given (depending on LI) will be set to zero.
//
/////////////////////////////////////////////////////////////////////////////

#include "TNuResoAdlerAdler.h"

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


ClassImp(TNuResoAdlerAdler)



//______________________________________________________________________________
void TNuResoAdlerAdler::ImportEndfData(TNuEndfIO& src)
{
   // Adler-Adler (LRF=4)
   //

   //SetCont(new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range"));
   //if (GetNRO())
   //   Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));

   // read cont+list and save them as a head
   TNuContList *clist = new TNuContList();
   clist->SetCont(new TNuCont(src, "SPI, AP, 0, 0, NLS, 0"));
   clist->SetList(new TNuList(src, "AWRI, 0.0, LI, 0, 6*NX, NX"
      "; AT1, AT2, AT3, AT4, BT1, BT"));
   SetSpinCont(clist);

   for (Int_t nls=0; nls < GetNLS(); nls++) {
      TNuContLists *clists = new TNuContLists();
      clists->SetCont(new TNuCont(src, "0.0, 0.0, L, 0, NJS, 0"));

      for (Int_t njs=0; njs < clists->GetN1(); njs++) {
         TNuList *list = new TNuList(src, "AJ, 0.0, 0, 0,12*NLJ, NLJ"
               "; DET, DWT, GRT, GIT, DEF, DWF,GRF, GIF, DEC, DWC, GRC, GIC");
         clists->Add(list);
      }
      Add(clists);
   }
}

