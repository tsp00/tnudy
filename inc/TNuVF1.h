// TNuVF1.h  =====================================================
// Author: Tae-Sun Park   Jan 30 2012

#ifndef ROOT_TNuVF1
#define ROOT_TNuVF1

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuVF1 = Abstract class for 1D functor                             //
//                                                                    //
// Derived 1D functor classes must override
//
//    Double_t EvalF1(ouble_t x, Double_t *ps=0));
// and
//    Int_t GetNPar() const; // if there are params
//    Double_t GetXmin() const;
//    Double_t GetXmax() const;
//
// And, optionally, override
//   virtual const Char_t* GetXAxisTitle() const { return "x"; }
// for the axis labels.
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TNuObject.h"
//#include "TNuLabel.h"

class TF1;

class TNuVF1
{
public:
   virtual ~TNuVF1();

   virtual Int_t NDimensions() const { return 1; }
   virtual Int_t NComponents() const { return 1; }

   virtual Double_t EvalF1(Double_t x, Double_t *ps=0) const = 0;

   virtual Int_t    GetNPar() const { return 0; } // number of params for Eval

   Double_t GetXmin() const { return fXmin; }
   Double_t GetXmax() const { return fXmax; }
   void     SetXmin(Double_t min) { fXmin = min; }
   void     SetXmax(Double_t max) { fXmax = max; }

   // get x-, y-, z-axis labels
   virtual const Char_t* GetXAxisTitle() const;
   virtual const Char_t* GetYAxisTitle() const;
   virtual const Char_t* GetZAxisTitle() const;

   // EvalPar calls one of EvalF1/F2/F3 depending on IsF1/F2/F3.
   virtual Double_t EvalPar(Double_t* xs, Double_t* ps=0) {
      return EvalF1(xs[0], ps); }

   // EvalFn(x,y,...) can be called by operator(x,y,...)
   Double_t operator()(Double_t x, Double_t *ps=0) {
       return EvalF1(x,ps);
   }

   virtual Double_t operator()(Double_t* xs, Double_t *ps=0) {
       return EvalPar(xs, ps);
   }

   // EvalFn(x,y,...) can be called also by Eval(x,y,...)
   Double_t Eval(Double_t x, Double_t *ps=0) {
      return EvalF1(x,ps);
   }

   virtual Double_t Eval(Double_t* xs, Double_t *ps=0) {
      return EvalPar(xs, ps);
   }

   void             ClearFunctor();
   void             ReleaseFunctor();

   typedef Double_t (TNuVF1::*TNuEvalF1_t)(Double_t, Double_t *) const;
   TF1*             GetTF1();

   // the symbol that represents the class
   //virtual const Char_t* GetSymbol() const { return GetName(); }

   virtual void     VirtualWhat() const; // *MENU*

   virtual void     VirtualDraw(Option_t* option="");
   virtual void     VirtualPaint(Option_t* option="");

   //static void     Update();

   static Bool_t    RangeOK(Double_t v, Double_t min, Double_t max, Bool_t warn=kFALSE) {
      if (v >= min && v <= max) return kTRUE;
      if (warn) fprintf(stderr,"The value %e is out of range [%e, %e]\n", v, min, max);
      return kFALSE;
   }

   Bool_t           XRangeOK(Double_t x, Bool_t warn=kFALSE) {
      return RangeOK(x, fXmin, fXmax, warn);
   }

protected:
   TNuVF1() {}
   Bool_t           HaveFunctor() { return fgFunctor && fgFunctorMaker == (size_t) this; }

   Double_t         fXmin; //! min of X-axis
   Double_t         fXmax; //! max of X-axis

   static TF1*      fgFunctor;       // static functor instance
   static size_t    fgFunctorMaker;  // the address of the maker of the functor
private:

   ClassDef(TNuVF1, 1) //Abstract class for 1D functor
};
#endif
