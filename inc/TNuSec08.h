// TNuSec08.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuSec08
#define ROOT_TNuSec08

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuTab1.h"
#include "TNuEndfIO.h"

class TNuSec08 : public TNuSection
{
public:
   TNuSec08() {}
   TNuSec08(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec08();

   void          What() const; // *MENU*

   void     ImportEndfData(TNuEndfIO& src);
private:

   ClassDef(TNuSec08, 1) // Decay data
};

#endif

