// TNuTab1.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuTab1
#define ROOT_TNuTab1

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab1 : Class for the ENDF TAB1 record
//
// [MAT,MF,MT/ C1, C2, L1, L2, NR, NP/xint/y(x)]TAB1
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuEndfTAB2.h"
//#include "TNuVTab.h"
#include "TNuVF1.h"

class TNuEndfIO;
class TGraph;

class TNuTab1 : public TNuEndfTAB2, public TNuVF1
{
public:
   TNuTab1() : TNuEndfTAB2(), TNuVF1(), fX(0), fY(0) {}
   TNuTab1(const TNuTab1& rhs);
   TNuTab1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuTab1(const Double_t* xs, const Double_t* ys, Int_t np, Int_t interp);

   //TNuTab1(const TNuTab1 &tab1);
   TNuTab1(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NR, NP");
   TNuTab1& operator=(const TNuTab1 &rhs);

   virtual ~TNuTab1();

   void          ImportEndfData(TNuEndfIO &src);

   const         Char_t* GetEndfName() const { return "TAB1"; }

   Double_t*     GetX() const { return fX; }
   Double_t      GetX(Int_t i) const {
      return BoundsOk(i) ? fX[i] : 0;
   }

   Double_t*     GetY() const { return fY; }
   Double_t      GetY(Int_t i) const {
      return BoundsOk(i) ? fY[i] : 0;
   }
   Int_t         GetNP() const { return fN2; }
   virtual void  SetNP(Int_t np);

   void          SetX(Double_t x, Int_t i) {
      if (BoundsOk(i)) fX[i] = x;
   }
   void          SetY(Double_t y, Int_t i) {
      if (BoundsOk(i)) fY[i] = y;
   }
   void          SetXY(Double_t x, Double_t y, Int_t i) {
      if (BoundsOk(i)) {
         fX[i] = x;
         fY[i] = y;
      }
   }

   virtual void  SetCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);

   Bool_t        IsF1() const { return kTRUE; }
   Double_t      EvalF1(Double_t x, Double_t *ps = 0) const;
   void          DrawTF1() { Draw(); } // *MENU*

   void          SetTransient();

   virtual void  Print(Option_t *opt = "") const; // *MENU*

   Int_t         GetInterpolationLaw(Int_t pos) const {
      return TNuEndfTAB2::GetInterpolationLaw(pos);
   }

   void          SetSubIntervals(Int_t subIntervals) {
      fgSubIntervals = (subIntervals < 0) ?  0 :
                       (subIntervals > 999) ? 999 : subIntervals;
                       } // *MENU*

   void          PlotGraph() const; // *MENU*
   Int_t         GetInterpolatedXY(Double_t** x_in, Double_t** y_in) const;
   TGraph*       GetGraph() const;
   TGraph*       GetGraph(const TGraph& rhs) const;
   TNuTab1&      Add(const Double_t* xs, const Double_t* ys, Int_t np);
   TNuTab1&      Add(const TNuTab1& tab1);
   TNuTab1       operator+(const TNuTab1& rhs) const;
   TNuTab1       operator+(const TGraph& rhs) const;

private:
   void          ClearHeap();
   void          Init();
   Double32_t*   fX;    //[fN2]
   Double32_t*   fY;    //[fN2]

   Bool_t        BoundsOk(Int_t at) const {
      if (at >= 0 && at < fN2) return kTRUE;
      Warning("BoundsOk","%d is out of range [0, %d)", at, fN2);
      return kFALSE;
   }

   static Int_t  fgSubIntervals; //! number of points for plot between mesh points

   ClassDef(TNuTab1, 1) // Class for the ENDF TAB1 record
};

#endif
