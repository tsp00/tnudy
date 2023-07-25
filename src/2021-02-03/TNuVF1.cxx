// TNuVF1.cxx  =====================================================
// Author: Tae-Sun Park   Jan 30 2012

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

//#include "TNuVF1.h"
//#include "TNuVF2.h"
#include "TNuVF3.h"
#include "TNuSection.h"
#include "TNudy.h"

#include "TClass.h"

#include "TF1.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TAxis.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuVF1)

size_t TNuVF1::fgFunctorMaker = 0;
TF1*   TNuVF1::fgFunctor = 0;

//______________________________________________________________________________
TNuVF1::~TNuVF1()
{
   // TNuVF1 dtor

   ClearFunctor();
}

//______________________________________________________________________________
void TNuVF1::VirtualWhat() const
{
   // What() for the functor
   using namespace std;

   cout << "\t1D functor on " << GetXmin() << " <= " << GetXAxisTitle() << " <= " << GetXmax() << endl;
}


//______________________________________________________________________________
void TNuVF1::ClearFunctor()
{
   // delete functor if esists

   if (fgFunctor) {
      delete fgFunctor;
      fgFunctor = 0;
   }
   fgFunctorMaker = 0;
}

//______________________________________________________________________________
const Char_t* TNuVF1::GetXAxisTitle() const
{
   // Returns the title of x-axis

   TNuVF1* vf = 0;
   TNuObject *my = dynamic_cast<TNuObject*>((TNuVF1*) this);
   TNuObject* parent = my->GetParent();
   while(parent) {
      vf = dynamic_cast<TNuVF1*>(parent);
      if(vf && vf->NDimensions() >= NDimensions()) break;
      parent = parent->GetParent();
   }

   //TNuSection* sec = my->GetParentSection();

   //if(sec && sec->InheritsFrom("TNuVF1")) {
   if(vf) {
      //TNuVF1* vf = dynamic_cast<TNuVF1*>(sec);
      Int_t shift = vf->NDimensions() - NDimensions();
      return (shift == 0) ? vf->GetXAxisTitle() :
             (shift == 1) ? vf->GetYAxisTitle() :
             (shift == 2) ? vf->GetZAxisTitle() :
             "?";
   }
   return "x";
}


//______________________________________________________________________________
const Char_t* TNuVF1::GetYAxisTitle() const
{
   // Returns the title of y-axis

   TNuVF1* vf = 0;
   TNuObject *my = dynamic_cast<TNuObject*>((TNuVF1*) this);
   TNuObject* parent = my->GetParent();
   while(parent) {
      vf = dynamic_cast<TNuVF1*>(parent);
      if(vf && vf->NDimensions() >= NDimensions()) break;
      parent = parent->GetParent();
   }

   if(vf) {
      Int_t shift = vf->NDimensions() - NDimensions();
      return (shift == 0) ? vf->GetYAxisTitle() :
             (shift == 1) ? vf->GetZAxisTitle() :
             "?";
   }
   return "y";
}

//______________________________________________________________________________
const Char_t* TNuVF1::GetZAxisTitle() const
{
   // Returns the title of z-axis

   TNuVF1* vf = 0;
   TNuObject *my = dynamic_cast<TNuObject*>((TNuVF1*) this);
   TNuObject* parent = my->GetParent();

   while(parent) {
      vf = dynamic_cast<TNuVF1*>(parent);
      if(vf && vf->NDimensions() >= NDimensions())
         return vf->GetZAxisTitle();
      parent = parent->GetParent();
   }

   return "z";
}

//______________________________________________________________________________
void TNuVF1::ReleaseFunctor()
{
   // Sets fgFunctor = fgFunctorMaker = 0
   // but without deleting the functor itself.
   // It is the user's responsibility to delete the generated functors,
   // and it is to be used when one needs to create several functors.

   fgFunctor = 0;
   fgFunctorMaker = 0;
}

//______________________________________________________________________________
TF1* TNuVF1::GetTF1()
{
   // creates a TF1 instance and returns it

   ClearFunctor();

   TNuObject *my = dynamic_cast<TNuObject*>(this);

   fgFunctor = new TF1(my->GetName(), this,
      GetXmin(), GetXmax(),
      GetNPar(), my->ClassName());

   if (!fgFunctor) {
      fprintf(stderr, "Error in GetTF1: failed to create the functor\n");
      return 0;
   }

   const Char_t *figTitle = my->GetFigTitle();
   const Char_t *xTitle =  GetXAxisTitle();

   const Char_t* title= Form("%s;%s;%s", figTitle, xTitle, "");
   fgFunctor->SetTitle(title);
   fgFunctor->GetXaxis()->CenterTitle();
   fgFunctorMaker = (size_t) this;

   return (TF1*) fgFunctor;
}

//______________________________________________________________________________
void TNuVF1::VirtualDraw(Option_t* option)
{
   // if it is a functor, create TFn and execute Draw()

   TCanvas *c1 = TNudy::GetCanvas();

   if (!c1) {
      fprintf(stderr, "Warning in TNuVF1: the canvas is null, retry ... ");
      c1 = (TCanvas*)(gROOT->GetListOfCanvases())->FindObject("Canvas 1");
      fprintf(stderr, "%s !\n", (c1) ? "Succeeded" : "failed");
   }

   TF1* tf = GetTF1();
   tf->Draw(option);

   c1->Update();
}


//______________________________________________________________________________
void TNuVF1::VirtualPaint(Option_t* option)
{
   // if it is a functor, call its Paint()
   if (fgFunctor) {
      fgFunctor->Paint(option);
   }
}

