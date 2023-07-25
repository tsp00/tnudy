// TNuTab2Tab1.h  =====================================================
// Author: Tae-Sun Park   Mar 06 2012

#ifndef ROOT_TNuTab2Tab1
#define ROOT_TNuTab2Tab1

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab2Tab1
//
// TAB2 of TNuTab1
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th TNuObject>, m=1,NZ)
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab2.h"
#include "TNuTab1.h"

class TNuVF1;
class TNuEndfIO;

class TNuTab2Tab1 : public TNuTab2
{
public:
   TNuTab2Tab1() : TNuTab2() {}
   TNuTab2Tab1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuTab2Tab1(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NR, NZ");
   virtual ~TNuTab2Tab1();

   virtual TNuVF1*  FirstVF1() const { return (TNuTab1*) BodyFirst(); }
   virtual TNuVF1*  LastVF1() const { return (TNuTab1*) BodyLast(); }
   virtual TNuVF1*  GetVF1At(Int_t n) const { return (TNuTab1*) BodyAt(n); }

   ClassDef(TNuTab2Tab1, 1) // 2-dimensional functor(TAB2 of TNuTab1)
};

#endif
