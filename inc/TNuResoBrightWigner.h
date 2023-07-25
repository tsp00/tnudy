// TNuResoBrightWigner.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuResoBrightWigner
#define ROOT_TNuResoBrightWigner

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuResoResolved: public TNuResonance                                      //
//                                                                           //
//   = Resolved Resonance Parameters (LRU=1)                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuResoResolved.h"
//#include "TNuRecsWithCont.h"

class TNuEndfIO;
class TNuTab1;
class TArrayD;

//#include "TNuSec02.h"


class TNuResoBrightWigner : public TNuResoResolved
{
   // [MAT, 2,151/ SPI, AP, 0, 0, NLS, 0]CONT
public:
   TNuResoBrightWigner() : TNuResoResolved() {}
   virtual ~TNuResoBrightWigner() {}
   void          ImportEndfData(TNuEndfIO& src);
   void          EvalRP(Double_t Ein, Double_t out[]) const;

   Int_t GenerateMeshPoints(TArrayD& mesh) const;

   ClassDef(TNuResoBrightWigner, 1) // Resonance data in Breit-Wigner format
};

class TNuResoSLBW : public TNuResoBrightWigner
{
   // [MAT, 2,151/ SPI, AP, 0, 0, NLS, 0]CONT
public:
   TNuResoSLBW() : TNuResoBrightWigner() {}
   virtual ~TNuResoSLBW() {}

   ClassDef(TNuResoSLBW, 1) // Resonance data in Single-level Breit-Wigner (LRF=1) format
};

class TNuResoMLBW : public TNuResoBrightWigner
{
   // [MAT, 2,151/ SPI, AP, 0, 0, NLS, 0]CONT
public:
   TNuResoMLBW() : TNuResoBrightWigner() {}
   virtual ~TNuResoMLBW() {}

   ClassDef(TNuResoMLBW, 1) // Resonance data in Multi-level Breit-Wigner (LRF=2) format
};

#endif
