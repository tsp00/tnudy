// TNuSec08454.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec08454 - fission product yield data (MT=454 and 459)
//              for fissionable materials
//
/*
   It provides y_fp(E) +/- Delta y_fp(E),
   where y_fp(E) is the yield of fission product "fp" that is defined by
   the ZAFP and FPS, FPS = n for n-th excited state.

   y_fp(E) is independent yield if MT= 454,
           and cumulative yield if MT= 459.


*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec08454.h"
#include "TF1.h"

#include "TNuListFPY.h"

#include <iostream>

ClassImp(TNuSec08454)

//______________________________________________________________________________
TNuSec08454::TNuSec08454(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec08454 ctor
}

//______________________________________________________________________________
TNuSec08454::~TNuSec08454()
{
   // TNuSec08454 dtor
}

//______________________________________________________________________________
void TNuSec08454::What() const
{
   using namespace std;
   TNuSection::What();
}

//______________________________________________________________________________
void TNuSec08454::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 8, MT= 454 and 459
   //

   // fission product yield data (MT=454 and 459) for fissionable materials
   //
   SetHead(new TNuCont(src, "ZA, AWR, LE+1, 0, 0, 0/HEAD"));
   for (Int_t n=0; n < GetL1(); n++) {
      TString label = Form("%s;%s",
         (n==0) ? "E, 0.0, LE, 0, NN, NFP" : "E, 0.0, I, 0, NN, NFP",
         (fMT==454) ? "ZAFP, FPS, YI, +-" : "ZAFP, FPS, YC, +-");
      Add(new TNuListFPY(src, label));
   }
   return;
}

