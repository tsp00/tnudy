// TNuVF2.cxx  =====================================================
// Author: Tae-Sun Park   Jan 30 2012

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

//#include "TNuVF2.h"
#include "TNuVF3.h"
#include "TNuSection.h"
#include "TNudy.h"

#include "TClass.h"

#include "TF2.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TAxis.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuVF2)

Double_t TNuVF2::fXY = 0; // value along X or Y
Int_t    TNuVF2::fCase = 0; // = 1 or 2 if the fixed axis is X or Y
                            // = 1 2 or 3 if the fixed axis is X, Y or Z
//______________________________________________________________________________
void TNuVF2::VirtualWhat() const
{
   using namespace std;

   cout << "\t2D functor on " << GetXmin() << " <= " << GetXAxisTitle() << " <= " << GetXmax();
   cout << ", "  << GetYmin() << " <= " << GetYAxisTitle() << " <= " << GetYmax() << endl;

}

//______________________________________________________________________________
TF2* TNuVF2::GetTF2()
{
   // creates a TF2 instance and returns it

   ClearFunctor();

   TNuObject *my = dynamic_cast<TNuObject*>(this);

   fgFunctor = new TF2(my->GetName(), this,
      GetXmin(), GetXmax(), GetYmin(), GetYmax(),
      GetNPar(), my->ClassName());

   if (!fgFunctor) {
      fprintf(stderr, "Error in GetTF2: failed to create the functor\n");
      return 0;
   }

   const Char_t *figTitle = my->GetFigTitle();
   const Char_t *xTitle =  GetXAxisTitle();
   const Char_t *yTitle =  GetYAxisTitle();

   const Char_t* title= Form("%s;%s;%s;%s", figTitle, xTitle, yTitle, "");
   fgFunctor->SetTitle(title);
   fgFunctor->GetXaxis()->CenterTitle();
   fgFunctor->GetXaxis()->SetTitleOffset(1.5f);
   fgFunctor->GetXaxis()->SetLabelOffset(0);
   fgFunctor->GetYaxis()->CenterTitle();
   fgFunctor->GetYaxis()->SetTitleOffset(2.0f);
   fgFunctor->GetYaxis()->SetLabelOffset(0);
   fgFunctor->GetZaxis()->SetTitleOffset(1.2f);
   fgFunctor->GetZaxis()->SetLabelOffset(0);
   fgFunctorMaker = (size_t) this;

   return (TF2*) fgFunctor;
}


//______________________________________________________________________________
void TNuVF2::DrawAt(const Char_t* fixedAxis, Double_t value, Option_t* option)
{
   // draw with fixing an axis "at" to a value "value"

   Char_t fixed = (strlen(fixedAxis) == 1) ? tolower(fixedAxis[0]) : 0;
   TCanvas *c1 = TNudy::GetCanvas();

   ClearFunctor();

   TNuObject *my = dynamic_cast<TNuObject*>(this);

   const Char_t* title;
   const Char_t* head = my->GetFigTitle();

   fXY = value;
   if (fixed == 'x') {
      if (!XRangeOK(value, kTRUE)) return;
      fCase = 1;
      fgFunctor = new TF1(my->GetName(), this, &TNuVF2::EvalF1ofF2,
         GetYmin(), GetYmax(),
         GetNPar(), my->ClassName(), "EvalF1ofF2");
      head= Form("At fixed %s = %e. %s", GetXAxisTitle(), value, head);
      title= Form("%s;%s;%s", head, GetYAxisTitle(), my->GetSymbol());
   }
   else if (fixed == 'y') {
      if (!YRangeOK(value, kTRUE)) return;
      fCase = 2;
      fgFunctor = new TF1(my->GetName(), this, &TNuVF2::EvalF1ofF2,
         GetXmin(), GetXmax(),
         GetNPar(), my->ClassName(), "EvalF1ofF2");
      head= Form("At fixed %s = %e. %s", GetYAxisTitle(), value, head);
      title= Form("%s;%s;%s", head, GetXAxisTitle(), my->GetSymbol());
   } else {
      fprintf(stderr, "The fixedAxis must be one of \"x\" or \"y\"\n");
      return;
   }

   fgFunctor->SetTitle(title);
   fgFunctorMaker = (size_t) this;
   ((TF1*) fgFunctor)->Draw(option);

   c1->Update();
}

//______________________________________________________________________________
Double_t TNuVF2::EvalF1ofF2(Double_t* xs, Double_t* ps)
{
   // Create a TF3 instance using a member function (*ftn)(x, y, z, ps).
   // This indirect way is due to the fact that TF3 requires
   // (Double_t *, Double_t*) signiture.

   Double_t f;
   f = (fCase == 1) ? EvalF2(  fXY, xs[0], ps) :
       (fCase == 2) ? EvalF2(xs[0],   fXY, ps) :
       0;
   return f;
}

//______________________________________________________________________________
void TNuVF2::VirtualDraw(Option_t* option)
{
   // if it is a functor, create TFn and execute Draw()

   TCanvas *c1 = TNudy::GetCanvas();

   GetTF2();
   if (fgFunctor)
      ((TF2*) fgFunctor)->Draw(option);

   c1->Update();
}

