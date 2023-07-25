// TNuTab3.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuTab3
#define ROOT_TNuTab3

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab3
//
// TAB2 of TAB2
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th Tab2>, m=1,NZ)
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuRecsWithTAB2.h"
#include "TNuVF3.h"

class TNuVF2;

class TNuTab3 : public TNuRecsWithTAB2, public TNuVF3
{
public:
   TNuTab3() : TNuRecsWithTAB2(), TNuVF3() {}
   TNuTab3(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuTab3(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NR, NZ");
   virtual ~TNuTab3();

   virtual TNuVF2*  FirstVF2() const = 0;
   virtual TNuVF2*  LastVF2() const = 0;
   virtual TNuVF2*  GetVF2At(Int_t n) const = 0;

   Double_t         EvalF3(Double_t x, Double_t y, Double_t z, Double_t *ps = 0) const;
   void             DrawTF3() { PlotTH3(); } // *MENU*

protected:
   void             SetTransient();

   ClassDef(TNuTab3, 1)// 3-dimensional functor (example: TAB2 of TNuTab2)
};

#endif
