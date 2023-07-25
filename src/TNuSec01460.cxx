// TNuSec01460.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSec01460                                                         //
//                                                                    //
// Delayed photon data                                                //
//                                                                    //
////////////////////////////////////////////////////////////////////////


#include "TNuSec01460.h"
#include "TNuEndfIO.h"

#include "TROOT.h"
#include "TString.h"
//#include "TObject.h"

#include "TNudy.h"
#include "TNuEndfIO.h"
#include "TNuListTaylor.h"
#include "TNuTab1.h"
#include "TNuTab2.h"

ClassImp(TNuSec01460)

//______________________________________________________________________________
TNuSec01460::TNuSec01460(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec01460 ctor
   if (mf != 1) {
      Warning("TNuSec01460::TNuSec01460", "MF=%d is not 1", mf);
   }
}

//______________________________________________________________________________
TNuSec01460::~TNuSec01460()
{
}

//______________________________________________________________________________
void TNuSec01460::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of a section MF=1 and MT=460 (Delayed photon data)
   //

   Int_t lo = src.GetL1();
   if (lo == 1) {
      SetHead(new TNuCont(src, "ZA, AWR, LO=1, 0, NG, 0"));
      Int_t ng = GetN1();
      for (Int_t i=1; i <= ng; i++)
         Add(new TNuTab1(src, "E_i, 0.0, i, 0, NR, NP/ T_i(t)"));
   }
   else if (lo == 2) {
      SetHead(new TNuCont(src, "ZA, AWR, LO=2, 0, 0, 0"));
      Add(new TNuList(src, "0.0, 0.0, 0, 0, NNF, 0/{#lambda}"));
   }
   else {
      Error("TNuSec01460", "Unsupported value of LO=%d", lo);
   }
}

