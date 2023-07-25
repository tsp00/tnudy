// TNuSec08.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec08 - Information concerning the decay of the reaction products
//
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec08.h"
#include "TF1.h"

#include "TNuList.h"

#include <iostream>

ClassImp(TNuSec08)

//______________________________________________________________________________
TNuSec08::TNuSec08(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec08 ctor
}

//______________________________________________________________________________
TNuSec08::~TNuSec08()
{
   // TNuSec08 dtor
}

//______________________________________________________________________________
void TNuSec08::What() const
{
   using namespace std;
   TNuSection::What();
}

//______________________________________________________________________________
void TNuSec08::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 8
   //

   // Information concerning the decay of the reaction products (any MT)
   //

   SetHead(new TNuCont(src, "ZA, AWR, LIS, LISO, NS, NO/HEAD"));
   Int_t NO=GetN2();
   for (Int_t n=0; n < GetN1(); n++) {
      if (NO ==0) {
         Add(new TNuList(src,
            "ZAP, ELFS, LMF, LFS, 6*ND, 0"
            "; HL, RTYP, ZAN, BR, END, CT"));
      }
      else if (NO==1) {
         Add(new TNuCont(src,
            "ZAP, ELFS, LMF, LFS, 0, 0"));
      }
   }
   return;
}
