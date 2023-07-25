// TNuResoResolved.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuResoResolved
#define ROOT_TNuResoResolved

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuResoResolved: public TNuResonance                                      //
//                                                                           //
//   = Resolved Resonance Parameters (LRU=1)                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuResonance.h"
//#include "TNuRecsWithCont.h"

//class TNuEndfIO;
//class TNuTab1;
class TArrayD;

class TNuResoResolved : public TNuResonance
{
public:
   TNuResoResolved() : TNuResonance() {}
   virtual ~TNuResoResolved() {}
   Int_t    MakeSubIntervals(TArrayD &energies, TArrayD &widths, TArrayD& mesh) const;

   ClassDef(TNuResoResolved, 1) // Resolved Resonance Parameters (LRU=1)
};

#endif
