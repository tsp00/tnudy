// TNuVF2.h  =====================================================
// Author: Tae-Sun Park   Jan 30 2012

#ifndef ROOT_TNuVF2
#define ROOT_TNuVF2

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuVF2 = Abstract class for 2D functor                             //
//                                                                    //
// Derived 3D functor classes must override
//
//    Double_t EvalF2(ouble_t x, Double_t y, Double_t z, Double_t *ps=0));
// and
//    Int_t GetNPar() const; // if there are params
//    Double_t GetXmin() const;
//    Double_t GetXmax() const;
//    Double_t GetYmin() const;
//    Double_t GetYmax() const;
//
// And, optionally, override
//   virtual const Char_t* GetXAxisTitle() const { return "x"; }
//   virtual const Char_t* GetYAxisTitle() const { return "y"; }
// for the axis labels.
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuVF1.h"

class TF2;

class TNuVF2 : public TNuVF1
{
public:
   virtual ~TNuVF2() {}

   Int_t NDimensions() const { return 2; }
   Int_t NComponents() const { return 1; }

   // turn off the derived methods for 1-D.
   Double_t EvalF1(Double_t /*x*/, Double_t * /*ps*/ = 0) const { return 0; }

   // following methods should be overridden
   //
   virtual Double_t EvalF2(Double_t x, Double_t y, Double_t* ps=0) const = 0;

   Double_t GetYmin() const { return fYmin; }
   Double_t GetYmax() const { return fYmax; }
   void     SetYmin(Double_t min) { fYmin = min; }
   void     SetYmax(Double_t max) { fYmax = max; }

   virtual Double_t EvalPar(Double_t* xs, Double_t* ps=0) {
      return EvalF2(xs[0], xs[1], ps);
   }

   Double_t operator()(Double_t x, Double_t y, Double_t *ps=0) {
       return EvalF2(x,y,ps);
   }

   virtual Double_t operator()(Double_t* xs, Double_t* ps=0) {
      return EvalPar(xs, ps);
   }

   //Double_t Eval(Double_t x, Double_t y, Double_t *ps=0) {
   //   return EvalF2(x,y,ps);
   //}

   typedef Double_t (TNuVF2::*TNuEvalF2_t)(Double_t, Double_t, Double_t *) const;
   TF2*             GetTF2();

   virtual void     VirtualWhat() const;

   virtual void     VirtualDraw(Option_t* option="");

   virtual void     DrawAt(const Char_t* at, Double_t value, Option_t* option="");
   virtual void     DrawAtX(Double_t value, Option_t* option="") { DrawAt("x", value, option); } // *MENU*
   virtual void     DrawAtY(Double_t value, Option_t* option="") { DrawAt("y", value, option); } 

   Bool_t           YRangeOK(Double_t y, Bool_t warn=kFALSE) {
      return RangeOK(y, fYmin, fYmax, warn);
   }

protected:
   TNuVF2() : TNuVF1() {}

   Double_t         fYmin; //! min of Y-axis
   Double_t         fYmax; //! max of Y-axis

   static Double_t  fXY; // value along X or Y
   static Int_t     fCase; // = 1, or 2 if the fixed axis is X or Y
   Double_t         EvalF1ofF2(Double_t* xs, Double_t* ps); // evaluates fixing one axis value

private:

   ClassDef(TNuVF2, 1) //Abstract class for 2D functor
};
#endif
