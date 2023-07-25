// TNuTab2.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab2
//
// TAB2 of TNuRecF1D (TAB1 or LIST)
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th TNuObject>, m=1,NZ)
//
///////////////////////////////////////////////////////////////////////////////


#include "TNuTab2.h"

#include "TNuVF1.h"

//#include "TNuEndfIO.h"

#include "TBrowser.h"

#include <iostream>
#include <iomanip>
using namespace std;

#include "TNudy.h"
#include "TNuSection.h"

ClassImp(TNuTab2)

//______________________________________________________________________________
TNuTab2::TNuTab2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuRecsWithTAB2(c1,c2,l1,l2,n1,n2), TNuVF2()
{
   // TNuTab2 ctor
}

//______________________________________________________________________________
TNuTab2::TNuTab2(TNuEndfIO &src, const Char_t* label)
 : TNuRecsWithTAB2(src, label), TNuVF2()
{
   // ctor of TNuTab2 importing ENDF data
}

//______________________________________________________________________________
TNuTab2::~TNuTab2()
{
   // dtor of TNuTab2
}

//______________________________________________________________________________
void TNuTab2::SetTransient()
{
   fXmin = GetRangeMin();
   fXmax = GetRangeMax();

   fYmin = FirstVF1()->GetXmin();
   fYmax = LastVF1()->GetXmax();
}


//______________________________________________________________________________
Double_t TNuTab2::EvalF2(Double_t x, Double_t y, Double_t *ps) const
{
   // Evaluate Tab2 (a 2-dim functor)

   if (x < GetXmin() || x > GetXmax()) return 0;

   Int_t n = BinarySearch(x, GetNZ());

   // find the interpolatio law
   Int_t interp= GetTAB2()->GetInterpolationLaw(n);

   // now do the interpolation
   Double_t xys[4];
   Double_t &x1 = xys[0];
   Double_t &y1 = xys[1];
   Double_t &x2 = xys[2];
   Double_t &y2 = xys[3];

   x1 = GetX(n);
   x2 = GetX(n+1);

   TNuVF1 *f1 = GetVF1At(n);
   TNuVF1 *f2 = GetVF1At(n+1);

   if (interp > 10) {
     // unit-based transformation
     Double_t emin = f1->GetXmin() + (x - x1)/(x2- x1)* (f2->GetXmin() - f1->GetXmin());
     Double_t emax = f1->GetXmax() + (x - x1)/(x2- x1)* (f2->GetXmax() - f1->GetXmax());
     Double_t wron1 = (f1->GetXmax() - f1->GetXmin()) / (emax - emin);
     Double_t ep1 = f1->GetXmin() + (y - emin) * wron1;
     y1 = f1->EvalF1(ep1, ps) * wron1;
     Double_t wron2 = (f2->GetXmax() - f2->GetXmin()) / (emax - emin);
     Double_t ep2 = f2->GetXmin() + (y - emin) * wron2;
     y2 = f2->EvalF1(ep2, ps) * wron2;
     interp -= 10;
   } else {
     y1 = f1->EvalF1(y, ps);
     y2 = f2->EvalF1(y, ps);
   }

   //xys[0] = GetX(n);
   //xys[1] = dynamic_cast<TNuVF1*>(BodyAt(n))->EvalF1(y, ps);

   //xys[2] = GetX(n+1);
   //xys[3] = dynamic_cast<TNuVF1*>(BodyAt(n+1))->EvalF1(y, ps);

   return Interpolation(interp, x, xys);
}
