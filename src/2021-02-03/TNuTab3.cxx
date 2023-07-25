// TNuTab3.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab3
//
// TAB2 of TAB2
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th Tab2>, m=1,NZ)
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab3.h"

#include "TNuVF2.h"

#include "TBrowser.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuTab3)

//______________________________________________________________________________
TNuTab3::TNuTab3(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuRecsWithTAB2(c1,c2,l1,l2,n1,n2), TNuVF3()
{
   // TNuTab3 ctor
}


//______________________________________________________________________________
TNuTab3::TNuTab3(TNuEndfIO &src, const Char_t* label) : TNuRecsWithTAB2(src, label)
{
   // ctor of TNuTab3 importing ENDF data
}

//______________________________________________________________________________
TNuTab3::~TNuTab3()
{
}

//______________________________________________________________________________
void TNuTab3::SetTransient()
{
   fXmin = GetRangeMin();
   fXmax = GetRangeMax();
   fYmin = FirstVF2()->GetXmin();
   fYmax = LastVF2()->GetXmax();
   fZmin = FirstVF2()->GetYmin();
   fZmax = LastVF2()->GetYmax();
}

//______________________________________________________________________________
Double_t TNuTab3::EvalF3(Double_t x, Double_t y, Double_t z, Double_t *ps) const
{
   // Evaluate Tab3 (a 3-dim functor)


   if (x < GetXmin() || x > GetXmax()) return 0;

   Int_t n = BinarySearch(x, GetNZ());

   // find the interpolatio law
   Int_t interp= GetInterpolationLaw(n);

   // now do the interpolation
   Double_t xys[4];
   Double_t &x1 = xys[0];
   Double_t &y1 = xys[1];
   Double_t &x2 = xys[2];
   Double_t &y2 = xys[3];

   x1 = GetX(n);
   x2 = GetX(n+1);

   TNuVF2 *f1 = GetVF2At(n);
   TNuVF2 *f2 = GetVF2At(n+1);


   // Here we make a dangerous assumption that the unit-based transform
   // is implemented with interp > 20 (not >10).
   if (interp > 20) {
     // unit-based transformation
     Double_t emin = f1->GetXmin() + (x - x1)/(x2- x1)* (f2->GetXmin() - f1->GetXmin());
     Double_t emax = f1->GetXmax() + (x - x1)/(x2- x1)* (f2->GetXmax() - f1->GetXmax());
     Double_t wron1 = (f1->GetXmax() - f1->GetXmin()) / (emax - emin);
     Double_t ep1 = f1->GetXmin() + (y - emin) * wron1;
     y1 = f1->EvalF2(ep1, z, ps) * wron1;
     Double_t wron2 = (f2->GetXmax() - f2->GetXmin()) / (emax - emin);
     Double_t ep2 = f2->GetXmin() + (y - emin) * wron2;
     y2 = f2->EvalF2(ep2, z, ps) * wron2;
   } else {
     y1 = f1->EvalF2(y, z, ps);
     y2 = f2->EvalF2(y, z, ps);
   }
/*
   Double_t xys[4];

   xys[0] = GetX(n);
   xys[1] = (dynamic_cast<TNuVF2*>(BodyAt(n)))->EvalF2(y, z, ps);

   xys[2] = GetX(n+1);
   xys[3] = (dynamic_cast<TNuVF2*>(BodyAt(n+1)))->EvalF2(y, z, ps);
*/

   //return Interpolation(interp, x, xys);
   Double_t f = Interpolation(interp % 10, x, xys);

   // for debugging
   //if (f) Info("","x=%e, y=%e, z=%e, n= %d, interp=%d, ((x1=%e, y1= %e), (x2=%e, y2=%e), f=%e)", x,y,z,n,interp, xys[0],xys[1],xys[2],xys[3],f);
   return f;
}

