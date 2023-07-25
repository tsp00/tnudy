// TNuTab3Tab2.h  =====================================================
// Author: Tae-Sun Park   Mar 06 2012

#ifndef ROOT_TNuTab3Tab2
#define ROOT_TNuTab3Tab2

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab3Tab2
//
// TAB2 of TNuTab2
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th Tab2>, m=1,NZ)
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab3.h"
#include "TNuTab2.h"

class TNuVF2;

class TNuTab3Tab2 : public TNuTab3
{
public:
   TNuTab3Tab2() : TNuTab3() {}
   TNuTab3Tab2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuTab3Tab2(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NR, NZ");
   virtual ~TNuTab3Tab2();

   virtual TNuVF2*  FirstVF2() const { return (TNuTab2*) BodyFirst(); }
   virtual TNuVF2*  LastVF2() const { return (TNuTab2*) BodyLast(); }
   virtual TNuVF2*  GetVF2At(Int_t n) const { return (TNuTab2*) BodyAt(n); }

   ClassDef(TNuTab3Tab2, 1)// 3-dimensional functor (TAB2 of TNuTab2)
};

#endif
