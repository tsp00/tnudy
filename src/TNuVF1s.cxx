// TNuVF1s.cxx  =====================================================
// Author: Tae-Sun Park   Jan 30 2012

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

#include "TNuVF1s.h"
#include "TNuObject.h"

#include "TClass.h"

#include "TF2.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TPad.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuVF1s)

//______________________________________________________________________________
void TNuVF1s::EvalF1s(Double_t x, Double_t* out) const
{
   // Evaluates all the F1s

   for (Int_t n=0; n < NDimensions(); n++)
      out[n+GetNPar()] = EvalF1At(n, x, out);
}

//______________________________________________________________________________
void TNuVF1s::VirtualWhat() const
{
   using namespace std;

   cout << "\t1D functor on " << GetXmin() << " <= " << GetXAxisTitle() << " <= " << GetXmax()<<endl;
   //cout << "\t" << NComponents() << "-components are to be evaluated" < endl;
}


//______________________________________________________________________________
void TNuVF1s::VirtualDraw(Option_t* /*option*/)
{
   // if it is a functor, create TFn and execute Draw()
   /*
   GetTF2();
   if (fgFunctor)
      ((TF2*) fgFunctor)->Draw(option);

   Update();
   */
}


