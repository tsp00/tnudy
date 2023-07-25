// TNuTab1Lists.cxx  =====================================================
// Author: Tae-Sun Park  Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuTab1Lists
//
//   -- a 2D functor S(T, E) on a retangular grid, which
//      consists of 1 TNuTab1 and subsequent TNuList elements
//
// ------------- head (1 element)
// HeadAt(0) = TNuTab1 for
//  [T_0, C2, LT, L2, NR, NP/S(E; T_0)] TAB1
//
// ------------- body (LT elements)
// At(n) = TNuTab1ListsSub for
//  [T_n, C2, LI, L2, NR, NP/S(E; T_n)] LIST
//
// where the y-grid is that of TAB1,
// and LI plays the role of INT of TAB1 (interpolation law).
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab1Lists.h"

#include "TNuTab1ListsSub.h"
#include "TNuTab1.h"
#include "TNuList.h"

#include "TNuEndfIO.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuTab1Lists)

/*
//______________________________________________________________________________
TNuTab1Lists::TNuTab1Lists(TNuEndfIO &src, const Char_t* label)
  : TNuRecs() //TNuList(src, label)
{
   // ctor of TNuTab1Lists importing ENDF data
}
*/

//______________________________________________________________________________
TNuTab1Lists::~TNuTab1Lists()
{
   // TNuTab1Lists dtor
}

//______________________________________________________________________________
void TNuTab1Lists::What() const
{
using namespace std;
   TNuRecs::What();

   cout << "   LT = " << (Int_t) GetLT() << " : Flag for temperature dependence, = the number of list records" << endl;
   cout << "   LI = " << (Int_t) GetLI()  << " : The interpolation law between different temperatures" << endl;
}

//______________________________________________________________________________
void TNuTab1Lists::SetTransient()
{
   // Sets the range

   fXmin = GetC1();
   fXmax = ((TNuCont*) BodyLast())->GetC1();

   fYmin = GetTab1()->GetXmin();
   fYmax = GetTab1()->GetXmax();
}

//______________________________________________________________________________
Double_t TNuTab1Lists::EvalAt(Int_t n, Double_t E, Double_t* ps) const
{
   // returns the f(x,y_n)
   if (n==0) return GetTab1()->EvalF1(E, ps);

   TNuTab1ListsSub* list = (TNuTab1ListsSub*) BodyAt(n-1);
   return list->EvalF1(E, ps);
}

//______________________________________________________________________________
Double_t TNuTab1Lists::EvalF2(Double_t x, Double_t y, Double_t *ps) const
{
   // Evaluate Tab2 (a 2-dim functor)

   if (x < GetXmin() || x > GetXmax()) return 0;

   Int_t n = BinarySearch(x, GetLT()+1);

   // find the interpolatio law
   Int_t interp= GetLI(); // GetInterpolationLaw(n);

   // now do the interpolation
   Double_t xys[4];

   xys[0] = GetX(n);
   xys[1] = EvalAt(n, y, ps);

   xys[2] = GetX(n+1);
   xys[3] = EvalAt(n+1, y, ps);

   return Interpolation(interp, x, xys);
}
