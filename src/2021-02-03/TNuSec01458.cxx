// TNuSec01458.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSec01458                                                         //
//                                                                    //
// Components of energy release due to fission                        //
//                                                                    //
////////////////////////////////////////////////////////////////////////


#include "TNuSec01458.h"
#include "TNuEndfIO.h"

#include "TROOT.h"
#include "TString.h"
//#include "TObject.h"

#include "TNudy.h"
#include "TNuEndfIO.h"
#include "TNuListTaylor.h"
#include "TNuTab1.h"
#include "TNuTab2.h"

ClassImp(TNuSec01458)

//______________________________________________________________________________
TNuSec01458::TNuSec01458(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec01458 ctor
   if (mf != 1) {
      Warning("TNuSec01458::TNuSec01458", "MF=%d is not 1", mf);
   }
}

//______________________________________________________________________________
TNuSec01458::~TNuSec01458()
{
}

//______________________________________________________________________________
void TNuSec01458::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of a File (default/blind routine)
   //

   // components of energy release due to fission
   SetHead(new TNuCont(src, "ZA, AWR, 0, 0, 0, 0"));
   Add(new TNuList(src, "0.0, 0.0, 0, NPLY, 18*(NPLY+1), 9*(NPLY+1)"
         "; EFR, +-, ENP, +-, END, +-, EGP, +-, EGD, +-, EB, +-, ENU, +-, ER, +-, ET, +-"));
}

