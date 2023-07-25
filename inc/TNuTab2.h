// TNuTab2.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuTab2
#define ROOT_TNuTab2

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab2
//
// TAB2 of records (TAB1 or LIST)
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th TNuObject>, m=1,NZ)
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuRecsWithTAB2.h"
#include "TNuVF2.h"

class TNuVF1;
class TNuEndfIO;

class TNuTab2 : public TNuRecsWithTAB2, public TNuVF2
{
public:
   TNuTab2() : TNuRecsWithTAB2(), TNuVF2() {}
   TNuTab2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuTab2(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NR, NZ");
   virtual ~TNuTab2();

   virtual TNuVF1*  FirstVF1() const = 0;
   virtual TNuVF1*  LastVF1() const = 0;
   virtual TNuVF1*  GetVF1At(Int_t n) const = 0;

   Double_t         EvalF2(Double_t x, Double_t y, Double_t *ps = 0) const;
   void             DrawTF2() { Draw("surf"); } // *MENU*

protected:
   void             SetTransient();

   ClassDef(TNuTab2, 1) // 2-dimensional functor(example: TAB2 of TAB1)
};

#endif
