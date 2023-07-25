// TNuVF3.h  =====================================================
// Author: Tae-Sun Park   Jan 30 2012

#ifndef ROOT_TNuVF3
#define ROOT_TNuVF3

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuVF3 = Abstract class for 3D functor                             //
//                                                                    //
// Derived 3D functor classes must override
//
//    Double_t EvalF3(ouble_t x, Double_t y, Double_t z, Double_t *ps=0));
// and
//    Int_t GetNPar() const; // if there are params
//    Double_t GetXmin() const;
//    Double_t GetXmax() const;
//    Double_t GetYmin() const;
//    Double_t GetYmax() const;
//    Double_t GetZmin() const;
//    Double_t GetZmax() const;
//
// And, optionally, override
//   virtual const Char_t* GetXAxisTitle() const { return "x"; }
//   virtual const Char_t* GetYAxisTitle() const { return "y"; }
//   virtual const Char_t* GetZAxisTitle() const { return "z"; }
// for the axis labels.
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuVF2.h"

class TF3;
class TH3;

class TNuVF3 : public TNuVF2
{
public:
   virtual ~TNuVF3() {}

   Int_t NDimensions() const { return 3; }
   Int_t NComponents() const { return 1; }

   // turn off the derived methods for 1- and 2-D.
   Double_t EvalF1(Double_t /*x*/, Double_t * /*ps*/ = 0) const { return 0; }
   Double_t EvalF2(Double_t /*x*/, Double_t /*y*/, Double_t* /*ps*/) const { return 0; }

   // following methods should be overridden
   //
   virtual Double_t EvalF3(Double_t x, Double_t y, Double_t z, Double_t* ps=0) const = 0;

   Double_t GetZmin() const { return fZmin; }
   Double_t GetZmax() const { return fZmax; }
   void     SetZmin(Double_t min) { fZmin = min; }
   void     SetZmax(Double_t max) { fZmax = max; }

   virtual Double_t operator()(Double_t* xs, Double_t* ps=0) {
      return EvalPar(xs, ps);
   }

   virtual Double_t EvalPar(Double_t* xs, Double_t* ps=0) {
      return EvalF3(xs[0], xs[1], xs[2], ps);
   }

   Double_t operator()(Double_t x, Double_t y, Double_t z, Double_t *ps=0) {
       return EvalF3(x,y,z,ps);
   }

   //Double_t Eval(Double_t x, Double_t y, Double_t z, Double_t *ps=0) {
   //   return EvalF3(x,y,z,ps);
   //}

   typedef Double_t (TNuVF3::*TNuEvalF3_t)(Double_t, Double_t, Double_t, Double_t *) const;
   //typedef Double_t (*TNuEvalF3_t)(Double_t, Double_t, Double_t, Double_t *);
   virtual    TF3*     GetTF3();

   virtual void     VirtualWhat() const;

   virtual void     VirtualDraw(Option_t* option="");

   virtual void     DrawF2At(const Char_t* at, Double_t value, Option_t* option="surf");
   virtual void     DrawF2AtX(Double_t value, Option_t* option="surf") { DrawF2At("x", value, option); } // *MENU*
   virtual void     DrawF2AtY(Double_t value, Option_t* option="surf") { DrawF2At("y", value, option); } 
   virtual void     DrawF2AtZ(Double_t value, Option_t* option="surf") { DrawF2At("z", value, option); } 

   virtual void     DrawAt2(const Char_t* at, Double_t val1, Double_t val2, Option_t* option="");
   virtual void     DrawAtXY(Double_t val1, Double_t val2, Option_t* option="") { DrawAt2("xy", val1, val2, option); }
   virtual void     DrawAtYZ(Double_t val1, Double_t val2, Option_t* option="") { DrawAt2("yz", val1, val2, option); }
   virtual void     DrawAtXZ(Double_t val1, Double_t val2, Option_t* option="") { DrawAt2("xz", val1, val2, option); }

   void Plot3D(Option_t* option="iso"); // *MENU*

   TH3* GetTH3(Int_t nx, Int_t ny, Int_t nz);
   void PlotTH3(Option_t* option="box"); // *MENU*

   Bool_t           ZRangeOK(Double_t z, Bool_t warn=kFALSE) {
      return RangeOK(z, fZmin, fZmax, warn);
   }

protected:
   TNuVF3() : TNuVF2() {}

   Double_t         EvalF2ofF3(Double_t* xs, Double_t* ps); // evaluates fixing one axis value
   Double_t         EvalF1ofF3(Double_t* xs, Double_t* ps); // evaluates fixing two axes values

   Double_t         fZmin; //! min of Z-axis
   Double_t         fZmax; //! max of Z-axis

   static Double_t fXYZ; // value along X, Y or Z
   //static Int_t    fCase; // = 1, 2 or 3 if the fixed axis is X, Y or Z

   virtual void     DrawAtX(Double_t, Option_t* /*option*/="") {} // turns off the TNuVF2's methods
   virtual void     DrawAtY(Double_t, Option_t* /*option*/="") {} // turns off the TNuVF2's methods

   ClassDef(TNuVF3, 1) //Abstract class for 3D functor
};

#endif
