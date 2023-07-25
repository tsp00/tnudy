// TNuResoRMatrixLimited.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuResoRMatrixLimited
#define ROOT_TNuResoRMatrixLimited

#include "TNuResoResolved.h"
//#include "TNuRecsWithCont.h"

class TNuEndfIO;
class TNuTab1;


class TNuResoRMatrixLimited : public TNuResoResolved
{
   // [MAT, 2,151/ 0.0, 0.0, IFG, KRM, NJS, KRL]CONT
public:
   TNuResoRMatrixLimited() : TNuResoResolved() {}
   virtual ~TNuResoRMatrixLimited() {}
   void          ImportEndfData(TNuEndfIO& src);
   Int_t         GetIFG() const { return SpinCont()->GetL1(); }
   Int_t         GetKRM() const { return SpinCont()->GetL2(); }
   Int_t         GetNJS() const { return SpinCont()->GetN1(); }
   Int_t         GetKRL() const { return SpinCont()->GetN2(); }

   ClassDef(TNuResoRMatrixLimited, 1) // Resonance data in R-Matrix Limited (LRF=7) format
};

#endif
