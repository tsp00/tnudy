// TNuResoAdlerAdler.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuResoAdlerAdler
#define ROOT_TNuResoAdlerAdler

#include "TNuResoResolved.h"

class TNuEndfIO;
class TNuTab1;


class TNuResoAdlerAdler : public TNuResoResolved
{
   // [MAT, 2,151/ SPI, AP, 0, 0, NLS, 0]CONT
public:
   TNuResoAdlerAdler() : TNuResoResolved() {}
   virtual ~TNuResoAdlerAdler() {}
   void          ImportEndfData(TNuEndfIO& src);

   ClassDef(TNuResoAdlerAdler, 1) // Resonance data in Adler-Adler (LRF=4) format
};


#endif
