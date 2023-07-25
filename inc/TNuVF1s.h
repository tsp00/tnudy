// TNuVF1s.h  =====================================================
// Author: Tae-Sun Park   Jan 30 2012

#ifndef ROOT_TNuVF1s
#define ROOT_TNuVF1s

////////////////////////////////////////////////////////////////////////
//
// TNuVF1s = Abstract class for a set of 1D functors
//
// Derived functor classes must override
//
//    Double_t EvalF1s(ouble_t x, Double_t *out,  Double_t *ps=0));
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

#include "TNuVF1.h"

#include "TString.h"
class TF1;

class TNuVF1s : public TNuVF1
{
public:
   virtual ~TNuVF1s() {}

   virtual Int_t NComponents() const = 0; // number of components to be evaluated

   // turn off the derived methods for 1-D.
   Double_t EvalF1(Double_t /*x*/, Double_t * /*ps*/ = 0) const { return 0; }

   // following methods should be overridden
   // Note that we are sharing the output place with the optional parameter place
   //
   virtual Double_t EvalF1At(Int_t n, Double_t x, Double_t* ps=0) const = 0;

   virtual const Char_t* GetSymbolAt(Int_t n) const { return Form("n=%d", n); }

   virtual void EvalF1s(Double_t x, Double_t* out) const ;

/*
   virtual void EvalPar(Double_t* xs, Double_t* out) {
      //return EvalF1s(xs[0], out);
      EvalF1s(xs[0], out);
   }

   void operator()(Double_t x, Double_t* out) {
       EvalF1s(x,out);
       //return EvalF1s(x,out);
   }

   virtual void operator()(Double_t* xs, Double_t* ps) {
      EvalPar(xs, ps);
   }
*/


   //virtual TF1*     GetTF1At(Int_t n);

   virtual void     VirtualWhat() const;

   virtual void     VirtualDraw(Option_t* option="");

protected:
   TNuVF1s() : TNuVF1() {}

   //Double_t         StaticEvalF2(Double_t* xs, Double_t* ps);
   //static Double_t  (*fgPtrEvalF2)(Double_t, Double_t, Double_t *);
   //static TNuEvalF2_t* fgEvalF2;


private:

   ClassDef(TNuVF1s, 1) //Abstract class for a set of 1D functors
};
#endif
