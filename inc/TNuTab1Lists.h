// TNuTab1Lists.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuTab1Lists
#define ROOT_TNuTab1Lists

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuTab1Lists
//
//   -- a 2D functor S(T, E) on a retangular grid, which
//      consists of 1 TNuTab1 and subsequent TNuList elements
//
// ------------- head (1 element)
// HeadAt(0) = TNuTab1 for
//  [T_0, C2, LT, L2, NR, NP/S(E; T_0)] TAB1
//
// ------------- body (LT elements)
// At(n) = TNuTab1ListsSub for
//  [T_n, C2, LI, L2, NR, NP/S(E; T_n)] LIST
//
// where the y-grid is that of TAB1,
// and LI plays the role of INT of TAB1 (interpolation law).
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuRecs.h"
#include "TNuVTab.h"
#include "TNuVF2.h"

#include "TNuTab1.h"

class TNuEndfIO;
//class TNuTab1;
class TNuList;
class TNuTab1ListsSub;

class TNuTab1Lists : public TNuRecs, public TNuVF2, public TNuVTab
{
public:
   TNuTab1Lists() : TNuRecs(), TNuVF2() {}
   //TNuTab1Lists(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   //TNuTab1Lists(TNuEndfIO &src, const Char_t* label=" T, 0.0, LT, 0, NR, NP");
   //TNuTab1Lists(const TNuTab1Lists &list2);
   //TNuTab1Lists& operator=(const TNuTab1Lists &rhs);
   virtual ~TNuTab1Lists();

   void          What() const; // *MENU*
   //const         Char_t* GetEndfName() const { return "LIST"; }

   TNuTab1*      GetTab1() const { return (TNuTab1*) HeadCont(); }
   void          SetTab1(TNuTab1 *tab1) { SetHead(tab1); }

   Int_t         GetLT() const { return GetL1(); } // number of list records
   Int_t         GetLI() const { return ((TNuCont*) BodyLast())->GetL1(); } // interpolation law

   Int_t         GetNR() const { return GetN1(); }
   Int_t         GetNP() const { return GetN2(); }

   Double_t      GetX(Int_t n) const {
      return (n == 0) ? GetC1() : ((TNuCont*) BodyAt(n-1))->GetC1();
   }

   Bool_t        IsF2() const { return kTRUE; }
   Double_t      EvalF2(Double_t x, Double_t y, Double_t *ps = 0) const;
   void          DrawTF2() { Draw("surf"); } // *MENU*

   Int_t         GetInterpolationLaw(Int_t /*pos*/) const { return GetLI(); }

   Double_t*     GetEmesh() const { return GetTab1()->GetX(); }

   Double_t      EvalAt(Int_t n, Double_t y, Double_t* ps = 0) const;

protected:
   void          SetTransient();

   ClassDef(TNuTab1Lists, 0) // 2D functor S(T, E) on a retangular grid
};

#endif
