// TNuVF3.cxx  =====================================================
// Author: Tae-Sun Park   Jan 30 2012

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

#include "TNuVF3.h"
#include "TNuSection.h"
#include "TNudy.h"

#include "TClass.h"
#include "TMath.h"

#include "TF3.h"
#include "TH3.h"
#include "TH3F.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TPad.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuVF3)

Double_t TNuVF3::fXYZ = 0; // value along X, Y or Z
//Int_t    TNuVF3::fCase = 0; // = 0, 1 or 2 if the fixed axis is X, Y or Z

//______________________________________________________________________________
void TNuVF3::VirtualWhat() const
{
   using namespace std;

   cout << "\t3D functor on " << GetXmin() << " <= " << GetXAxisTitle() << " <= " << GetXmax();
   cout << ", "  << GetYmin() << " <= " << GetYAxisTitle() << " <= " << GetYmax();
   cout << ", "  << GetZmin() << " <= " << GetZAxisTitle() << " <= " << GetZmax() << endl;

}

//______________________________________________________________________________
TF3* TNuVF3::GetTF3()
{
   // creates a TF3 instance and returns it
   using namespace std;

   ClearFunctor();

   TNuObject *my = dynamic_cast<TNuObject*>(this);

   fgFunctor = new TF3(my->GetName(), this,
      GetXmin(), GetXmax(), GetYmin(), GetYmax(), GetZmin(), GetZmax(),
      GetNPar(), my->ClassName());

   if (!fgFunctor) {
      fprintf(stderr, "Error in GetTF3: failed to create the functor\n");
      return 0;
   }

   Double_t xs[3];
   xs[0] = (GetXmin() + GetXmax())/2;
   xs[1] = (GetYmin() + GetYmax())/2;
   xs[2] = (GetZmin() + GetZmax())/2;
   cout << "results = " << ((TF3*) fgFunctor)->EvalPar(xs) << endl;

/*
   const Char_t *figTitle, *xTitle, *yTitle, *zTitle;//, *wTitle;
   TNuSection* sec = my->GetParentSection();
   TNuVF3* vf3 = dynamic_cast<TNuVF3*>(sec);

   if(vf3) {
      figTitle = sec->GetFigTitle();
      xTitle = vf3->GetXAxisTitle();
      yTitle = vf3->GetYAxisTitle();
      zTitle = vf3->GetZAxisTitle();
      //wTitle = sec->GetSymbol();
   } else {
      TNuObject* parent = my->GetParent();
      while(parent) {
         vf3 = dynamic_cast<TNuVF3*>(parent);
         if(vf3 && strcmp(vf3->GetZAxisTitle(), "z")) break;
         parent = parent->GetParent();
      }

      if(vf3) {
         figTitle = parent->GetFigTitle();
         xTitle = GetXAxisTitle();
         yTitle = GetYAxisTitle();
         zTitle = GetZAxisTitle();
         //wTitle = parent->GetSymbol();
      } else {
         figTitle = my->GetFigTitle();
         xTitle = GetXAxisTitle();
         yTitle = GetYAxisTitle();
         zTitle = GetZAxisTitle();
         //wTitle = my->GetSymbol();
      }
   }
*/
   const Char_t *figTitle = my->GetFigTitle();
   const Char_t *xTitle =  GetXAxisTitle();
   const Char_t *yTitle =  GetYAxisTitle();
   const Char_t *zTitle =  GetZAxisTitle();
   
   const Char_t* title= Form("%s;%s;%s;%s;%s", figTitle, xTitle, \
                             yTitle, zTitle, "");
   //printf("title:%s\n", title);
   fgFunctor->SetTitle(title);
   fgFunctor->GetXaxis()->CenterTitle();
   fgFunctor->GetXaxis()->SetTitleOffset(1.5f);
   fgFunctor->GetXaxis()->SetLabelOffset(0);
   fgFunctor->GetYaxis()->CenterTitle();
   fgFunctor->GetYaxis()->SetTitleOffset(2.0f);
   fgFunctor->GetYaxis()->SetLabelOffset(0);
   fgFunctor->GetZaxis()->CenterTitle();
   fgFunctor->GetZaxis()->SetTitleOffset(1.2f);
   fgFunctor->GetZaxis()->SetLabelOffset(0);
   fgFunctorMaker = (size_t) this;

   return (TF3*) fgFunctor;
}

//______________________________________________________________________________
void TNuVF3::VirtualDraw(Option_t* option)
{
   // if it is a functor, create TFn and execute Draw()

   TCanvas *c1 = TNudy::GetCanvas();
   GetTF3();
   if (fgFunctor)
      ((TF3*) fgFunctor)->Draw(option);

   c1->Update();
}

//______________________________________________________________________________
void TNuVF3::DrawF2At(const Char_t* fixedAxis, Double_t value, Option_t* option)
{
   // draw with fixing an axis "at" to a value "value"

   TCanvas *c1 = TNudy::GetCanvas();
   Char_t fixed = (strlen(fixedAxis) == 1) ? tolower(fixedAxis[0]) : 0;

   ClearFunctor();

   TNuObject *my = dynamic_cast<TNuObject*>(this);

   const Char_t* title;
   const Char_t* head = my->GetFigTitle();

   fXYZ = value;
   if (fixed == 'x') {
      if (!XRangeOK(value, kTRUE)) return;
      fCase = 1;
      fgFunctor = new TF2(my->GetName(), this, &TNuVF3::EvalF2ofF3,
         GetYmin(), GetYmax(), GetZmin(), GetZmax(),
         GetNPar(), my->ClassName(), "EvalF2ofF3");
      head= Form("At fixed %s = %e. %s", GetXAxisTitle(), value, head);
      title= Form("%s;%s;%s;%s", head, GetYAxisTitle(), GetZAxisTitle(), my->GetSymbol());
   }
   else if (fixed == 'y') {
      if (!YRangeOK(value, kTRUE)) return;
      fCase = 2;
      fgFunctor = new TF2(my->GetName(), this, &TNuVF3::EvalF2ofF3,
         GetXmin(), GetXmax(), GetZmin(), GetZmax(),
         GetNPar(), my->ClassName(), "EvalF2ofF3");
      head= Form("At fixed %s = %e. %s", GetYAxisTitle(), value, head);
      title= Form("%s;%s;%s;%s", head, GetXAxisTitle(), GetZAxisTitle(), my->GetSymbol());
   }
   else if (fixed == 'z') {
      if (!ZRangeOK(value, kTRUE)) return;
      fCase = 3;
      fgFunctor = new TF2(my->GetName(), this, &TNuVF3::EvalF2ofF3,
         GetXmin(), GetXmax(), GetYmin(), GetYmax(),
         GetNPar(), my->ClassName(), "EvalF2ofF3");
      head= Form("At fixed %s = %e. %s", GetZAxisTitle(), value, head);
      title= Form("%s;%s;%s;%s", head, GetXAxisTitle(), GetYAxisTitle(), my->GetSymbol());
   } else {
      fprintf(stderr, "The fixedAxis must be one of \"x\", \"y\" or \"z\"\n");
      return;
   }

   fgFunctor->SetTitle(title);
   fgFunctorMaker = (size_t) this;
   ((TF2*) fgFunctor)->Draw(option);

   c1->Update();
}

//______________________________________________________________________________
Double_t TNuVF3::EvalF2ofF3(Double_t* xs, Double_t* ps)
{
   // Create a TF3 instance using a member function (*ftn)(x, y, z, ps).
   // This indirect way is due to the fact that TF3 requires
   // (Double_t *, Double_t*) signiture.

   Double_t f;
   f = (fCase == 1) ? EvalF3(fXYZ, xs[0], xs[1], ps) :
       (fCase == 2) ? EvalF3(xs[0], fXYZ, xs[1], ps) :
       (fCase == 3) ? EvalF3(xs[0], xs[1], fXYZ, ps) :
       0;

   return f;
}


//______________________________________________________________________________
Double_t TNuVF3::EvalF1ofF3(Double_t* xs, Double_t* ps)
{
   // Create a TF3 instance using a member function (*ftn)(x, y, z, ps).
   // This indirect way is due to the fact that TF3 requires
   // (Double_t *, Double_t*) signiture.

   Double_t f;
   f = (fCase == -1) ? EvalF3(xs[0], fXYZ,   fXY, ps) :
       (fCase == -2) ? EvalF3(fXYZ, xs[0],   fXY, ps) :
       (fCase == -3) ? EvalF3(fXYZ,   fXY, xs[0], ps) :
       0;

   return f;
}

//______________________________________________________________________________
void TNuVF3::DrawAt2(const Char_t* fixedAxes, Double_t val1, Double_t val2, Option_t* option)
{
   // draw with fixing two axess at to value val1 and val2

   TCanvas *c1 = TNudy::GetCanvas();

   Char_t fixed1 = (strlen(fixedAxes) == 2) ? tolower(fixedAxes[0]) : 0;
   Char_t fixed2 = (strlen(fixedAxes) == 2) ? tolower(fixedAxes[1]) : 0;

   Double_t v1 = (fixed1 < fixed2) ? val1 : val2;
   Double_t v2 = (fixed1 < fixed2) ? val2 : val1;

   ClearFunctor();

   TNuObject *my = dynamic_cast<TNuObject*>(this);

   const Char_t* title;
   const Char_t* head = my->GetFigTitle();

   TString fixed(fixedAxes);
   fixed.ToLower();

   fXYZ = v1;
   fXY = v2;

   if (fixed.Contains("x") && fixed.Contains("y")) {
      if (!YRangeOK(v1, kTRUE)) return;
      if (!ZRangeOK(v2, kTRUE)) return;
      fCase = -3;
      fgFunctor = new TF1(my->GetName(), this, &TNuVF3::EvalF1ofF3,
         GetZmin(), GetZmax(),
         GetNPar(), my->ClassName(), "EvalF1ofF3");
      head= Form("At fixed %s = %e and %s = %e. %s", GetXAxisTitle(), v1, GetYAxisTitle(), v2, head);
      title= Form("%s;%s;%s", head, GetZAxisTitle(), my->GetSymbol());
   }
   else if (fixed.Contains("x") && fixed.Contains("z")) {
      if (!XRangeOK(v1, kTRUE)) return;
      if (!ZRangeOK(v2, kTRUE)) return;
      fCase = -2;
      fgFunctor = new TF1(my->GetName(), this, &TNuVF3::EvalF1ofF3,
         GetYmin(), GetYmax(),
         GetNPar(), my->ClassName(), "EvalF1ofF3");
      head= Form("At fixed %s = %e and %s = %e. %s", GetXAxisTitle(), v1, GetZAxisTitle(), v2, head);
      title= Form("%s;%s;%s", head, GetYAxisTitle(), my->GetSymbol());
   }
   else if (fixed.Contains("y") && fixed.Contains("z")) {
      if (!YRangeOK(v1, kTRUE)) return;
      if (!ZRangeOK(v2, kTRUE)) return;
      fCase = -1;
      fgFunctor = new TF1(my->GetName(), this, &TNuVF3::EvalF1ofF3,
         GetXmin(), GetXmax(),
         GetNPar(), my->ClassName(), "EvalF1ofF3");
      head= Form("At fixed %s = %e and %s = %e. %s", GetYAxisTitle(), v1, GetZAxisTitle(), v2, head);
      title= Form("%s;%s;%s", head, GetXAxisTitle(), my->GetSymbol());
   } else {
      fprintf(stderr, "The fixedAxes must be one of \"xy\", \"yz\" or \"zx\"\n");
      return;
   }

   fgFunctor->SetTitle(title);
   fgFunctorMaker = (size_t) this;
   ((TF1*) fgFunctor)->Draw(option);

   c1->Update();
}

//______________________________________________________________________________
void TNuVF3::Plot3D(Option_t* option)
{
   // plots 3d

   const Int_t max = 20;
   TCanvas *c1 = TNudy::GetCanvas();

   TNuObject *my = dynamic_cast<TNuObject*>(this);

   //set title
   const Char_t *figTitle, *xTitle, *yTitle, *zTitle, *wTitle;
   TNuSection* sec = my->GetParentSection();
   TNuVF3* vf3 = dynamic_cast<TNuVF3*>(sec);

   if(vf3) {
      figTitle = sec->GetFigTitle();
      xTitle = vf3->GetXAxisTitle();
      yTitle = vf3->GetYAxisTitle();
      zTitle = vf3->GetZAxisTitle();
      wTitle = sec->GetSymbol();
   } else {
      TNuObject* parent = my->GetParent();
      while(parent) {
         vf3 = dynamic_cast<TNuVF3*>(parent);
         if(vf3 && strcmp(vf3->GetZAxisTitle(), "z")) break;
         parent = parent->GetParent();
      }

      if(vf3) {
         figTitle = parent->GetFigTitle();
         xTitle = GetXAxisTitle();
         yTitle = GetYAxisTitle();
         zTitle = GetZAxisTitle();
         wTitle = parent->GetSymbol();
      } else {
         figTitle = my->GetFigTitle();
         xTitle = GetXAxisTitle();
         yTitle = GetYAxisTitle();
         zTitle = GetZAxisTitle();
         wTitle = my->GetSymbol();
      }
   }

   const Char_t* title= Form("%s;%s;%s;%s;%s", figTitle, xTitle, \
                             yTitle, zTitle, wTitle);
   //printf("title:%s\n", title);

   TH3F *h3 = new TH3F(my->GetName(), title,
                 max+1, GetXmin(), GetXmax(),
                 max+1, GetYmin(), GetYmax(),
                 max+1, GetZmin(), GetZmax());

   for (Int_t i=0; i < max; i++) {
      Double_t x = GetXmin() + (i*(GetXmax() - GetXmin()))/max;
      for (Int_t j=0; j < max; j++) {
         Double_t y = GetYmin() + (j*(GetYmax() - GetYmin()))/max;
         for (Int_t k=0; k < max; k++) {
            Double_t z = GetZmin() + (k*(GetZmax() - GetZmin()))/max;
            Double_t val = EvalF3(x,y,z);
            val = (val <= 1.E-30)? 0 : TMath::Log(val);
            h3->Fill(x,y,z,val);
         }
      }
   }

   h3->SetTitle(title);
   h3->GetXaxis()->CenterTitle();
   h3->GetXaxis()->SetTitleOffset(1.5f);
   h3->GetXaxis()->SetLabelOffset(0);
   h3->GetYaxis()->CenterTitle();
   h3->GetYaxis()->SetTitleOffset(2.0f);
   h3->GetYaxis()->SetLabelOffset(0);
   h3->GetZaxis()->CenterTitle();
   h3->GetZaxis()->SetTitleOffset(1.2f);
   h3->GetZaxis()->SetLabelOffset(0);

   h3->Draw(option);
   c1->Update();
}


//______________________________________________________________________________
TH3* TNuVF3::GetTH3(Int_t nx, Int_t ny, Int_t nz)
{
   // creates a TH3 instance and returns it
   using namespace std;

   //ClearFunctor();

   TNuObject *my = dynamic_cast<TNuObject*>(this);

   double x1 = GetXmin(), x2 = GetXmax(), dx = (x2 - x1) / nx;
   double y1 = GetYmin(), y2 = GetYmax(), dy = (y2 - y1) / ny;
   double z1 = GetZmin(), z2 = GetZmax(), dz = (z2 - z1) / nz;
   TH3F *h3 = new TH3F(my->GetName(), my->GetTitle(),
                 nx, x1, x2,  ny, y1, y2, nz, z1, z2);

   for (Int_t i=1; i <= nx; i++) {
      Double_t x = x1 + (i-0.5) * dx;
      for (Int_t j=1; j <= ny; j++) {
         Double_t y = y1 + (j-0.5)*dy;
         for (Int_t k=1; k <= nz; k++) {
            Double_t z = z1 + (k-0.5)*dz;
            Double_t val = EvalF3(x,y,z);
            h3->SetBinContent(i,j,k, val);
         }
      }
   }
   return h3;
}


//______________________________________________________________________________
void TNuVF3::PlotTH3(Option_t* option)
{
   // plots 3d

   const Int_t nx = 20, ny=20, nz=20;
   TCanvas *c1 = TNudy::GetCanvas();

   TNuObject *my = dynamic_cast<TNuObject*>(this);

   //set title
   const Char_t *figTitle, *xTitle, *yTitle, *zTitle, *wTitle;
   TNuSection* sec = my->GetParentSection();
   TNuVF3* vf3 = dynamic_cast<TNuVF3*>(sec);

   if(vf3) {
      figTitle = sec->GetFigTitle();
      xTitle = vf3->GetXAxisTitle();
      yTitle = vf3->GetYAxisTitle();
      zTitle = vf3->GetZAxisTitle();
      wTitle = sec->GetSymbol();
   } else {
      TNuObject* parent = my->GetParent();
      while(parent) {
         vf3 = dynamic_cast<TNuVF3*>(parent);
         if(vf3 && strcmp(vf3->GetZAxisTitle(), "z")) break;
         parent = parent->GetParent();
      }

      if(vf3) {
         figTitle = parent->GetFigTitle();
         xTitle = GetXAxisTitle();
         yTitle = GetYAxisTitle();
         zTitle = GetZAxisTitle();
         wTitle = parent->GetSymbol();
      } else {
         figTitle = my->GetFigTitle();
         xTitle = GetXAxisTitle();
         yTitle = GetYAxisTitle();
         zTitle = GetZAxisTitle();
         wTitle = my->GetSymbol();
      }
   }

   const Char_t* title= Form("%s;%s;%s;%s;%s", figTitle, xTitle, \
                             yTitle, zTitle, wTitle);
   //printf("title:%s\n", title);

   TH3 *h3 = GetTH3(nx,ny,nz);

   h3->SetTitle(title);
   h3->GetXaxis()->CenterTitle();
   h3->GetXaxis()->SetTitleOffset(1.5f);
   h3->GetXaxis()->SetLabelOffset(0);
   h3->GetYaxis()->CenterTitle();
   h3->GetYaxis()->SetTitleOffset(2.0f);
   h3->GetYaxis()->SetLabelOffset(0);
   h3->GetZaxis()->CenterTitle();
   h3->GetZaxis()->SetTitleOffset(1.2f);
   h3->GetZaxis()->SetLabelOffset(0);

   h3->Draw(option);
   c1->Update();
}
