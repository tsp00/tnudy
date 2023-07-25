// TNuTab2List1.h  =====================================================
// Author: Tae-Sun Park   Mar 06 2012

#ifndef ROOT_TNuTab2List1
#define ROOT_TNuTab2List1

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab2List1
//
// TAB2 of TNuList1
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th TNuObject>, m=1,NZ)
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab2.h"
#include "TNuList1.h"

class TNuVF1;
class TNuEndfIO;

class TNuTab2List1 : public TNuTab2
{
public:
   TNuTab2List1() : TNuTab2() {}
   TNuTab2List1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuTab2List1(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NR, NZ");
   virtual ~TNuTab2List1();

   virtual TNuVF1*  FirstVF1() const { return (TNuList1*) BodyFirst(); }
   virtual TNuVF1*  LastVF1() const { return (TNuList1*) BodyLast(); }
   virtual TNuVF1*  GetVF1At(Int_t n) const { return (TNuList1*) BodyAt(n); }

   ClassDef(TNuTab2List1, 1) // 2-dimensional functor(TAB2 of TNuList1)
};

#endif
