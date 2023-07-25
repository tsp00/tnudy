// TNuSec08454.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuSec08454
#define ROOT_TNuSec08454

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec08454 - fission product yield data (MT=454 and 459)
//              for fissionable materials
//
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuTab1.h"
#include "TNuEndfIO.h"

class TNuSec08454 : public TNuSection
{
public:
   TNuSec08454() {}
   TNuSec08454(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec08454();

   void          What() const; // *MENU*

   void     ImportEndfData(TNuEndfIO& src);
private:

   ClassDef(TNuSec08454, 1) // Fission product yield data (MT=454 for independent, MT=459 for cumulative)
};

#endif

