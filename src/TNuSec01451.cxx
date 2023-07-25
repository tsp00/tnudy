// TNuSec01451.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011


/**********************************************************************
 **********************************************************************/


/////////////////////////////////////////////////////////////////////////////
//
// TNuSec01451 (default class for a section data)
//
// ------------------ head --------------------------------------------------
// HeadAt(0)
//   [   ZA,   AWR,   LRP,   LFI,  NLIB,  NMOD]/TNuCont
//
// HeadAt(1)
//   [ ELIS,   STA,   LIS,  LISO,     0,  NFOR]/TNuCont
//
// HeadAt(2)
//   [  AWI,  EMAX,  LREL,     0,  NSUB,  NVER]/TNuCont
//
// HeadAt(3)
//   [ TEMP,   0.0,  LDRV,     0,   NWD,   NXC]/TNuCont
//
// ------------------ body --------------------------------------------------
// At(0) = fDescription
//
// At(1) = fDirs
//
/////////////////////////////////////////////////////////////////////////////

#include "TROOT.h"
#include "TNuSec01451.h"
#include "TObjString.h"
//#include "TObject.h"

#include "TNudy.h"
#include "TNuEndfIO.h"


ClassImp(TNuSec01451)

//______________________________________________________________________________
TNuSec01451::TNuSec01451(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,1,451)
{
   // TNuSec01451 ctor
   if (mf != 1 || mt != 451) {
      Warning("TNuSec01451::TNuSec01451", "MF=%d, MT=%d is not 1, 451", mf, mt);
   }
}

//______________________________________________________________________________
TNuSec01451::~TNuSec01451()
{
}

//______________________________________________________________________________
void TNuSec01451::ShowDescription() const
{
   // Has to be implemented
}


//______________________________________________________________________________
void TNuSec01451::ShowDir() const
{
   // Has to be implemented
}

//______________________________________________________________________________
void TNuSec01451::ImportEndfData(TNuEndfIO& src)
{
   // import Ascii Endf data for MF=1 and MT=451 data and create TNuSec01451 accordingly
   //

   // first section of a mat date should be MF=1 and MT=451
   if (src.GetMF() != 1 || src.GetMT() != 451) {
      Fatal("TNuSec01451::TNuSec01451",
         "Cannot find MF=1 and MT=151: MAT= %d, MF=%d, MT=%d", src.GetMAT(), src.GetMF(), src.GetMT());
   }

   // Note that SubLibrary is not firmly set,
   // which can be done only after reading MF=1 and MT=451 section

   // import MF=1 and MT=451 section data
   //TNuSec01451 *pSec1451 = new TNuSec01451();

   TNuCont *cont;
   // HeadAt(0)
   cont = new TNuCont(src, "   ZA,   AWR,   LRP,   LFI,  NLIB,  NMOD");
   SetHead(cont);
   //Info("", "ZA=%8.1f, AWR=%8.3f, LRP=%2d, LFI=%2d, NLIB=%3d, NMOD=%2d",
   //   cont->GetC1(), cont->GetC2(), cont->GetL1(), cont->GetL2(), cont->GetN1(), cont->GetN2());

   //  HeadAt(1)
   AddToHead(new TNuCont(src, " ELIS,   STA,   LIS,  LISO,     0,  NFOR"));

   //  HeadAt(2)
   AddToHead(new TNuCont(src, "  AWI,  EMAX,  LREL,     0,  NSUB,  NVER"));

   //  HeadAt(3)
   cont = new TNuCont(src, " TEMP,   0.0,  LDRV,     0,   NWD,   NXC");
   fNWD = cont->GetN1();
   fNXC = cont->GetN2();
   AddToHead(cont);

   TNuDescription* desc = new TNuDescription(fNWD);
   for (Int_t n = 0 ; n < fNWD; n++) {
      //TObjString *s = new TObjString(src.ReadTEXT());
      //fDescription.Add(s);
      desc->Add(src.ReadTEXT());
   }
   Add(desc);

   TNuDirs* dirs= new TNuDirs(fNXC);
   for (Int_t n = 0; n < fNXC; n++) {
      if (src.IsSEND()) {
         // For the exceptional case where fNXC is wrongly writtem,
         // example:ROSFOND-2010, actual NXC = 18, written NXC = 19
         Warning("ImportEndfData", "NXC=%d is reset to %d", fNXC, n);
         fNXC = n;
         dirs->SetSize(fNXC);
         break;
      }
      //fDirs.Add(new TNuCont(src, "blank, blank, MF, MT, NC, MOD"));
      dirs->Add(new TNuCont(src, "blank, blank, MF, MT, NC, MOD"));
   }
   Add(dirs);
}
