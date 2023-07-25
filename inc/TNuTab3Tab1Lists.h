// TNuTab3Tab1Lists.h  =====================================================
// Author: Tae-Sun Park   Mar 06 2012

#ifndef ROOT_TNuTab3Tab1Lists
#define ROOT_TNuTab3Tab1Lists

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab3Tab1Lists
//
// TAB2 of TNuTab1Lists
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th Tab2>, m=1,NZ)
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab3.h"
#include "TNuTab1Lists.h"

class TNuVF2;

class TNuTab3Tab1Lists : public TNuTab3
{
public:
   TNuTab3Tab1Lists() : TNuTab3() {}
   TNuTab3Tab1Lists(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuTab3Tab1Lists(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NR, NZ");
   virtual ~TNuTab3Tab1Lists();

   virtual TNuVF2*  FirstVF2() const { return (TNuTab1Lists*) BodyFirst(); }
   virtual TNuVF2*  LastVF2() const { return (TNuTab1Lists*) BodyLast(); }
   virtual TNuVF2*  GetVF2At(Int_t n) const { return (TNuTab1Lists*) BodyAt(n); }

   ClassDef(TNuTab3Tab1Lists, 1)// 3-dimensional functor (TAB2 of TNuTab1Lists)
};

#endif
