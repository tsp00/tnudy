// TNuTab1ListsSub.cxx  =====================================================
// Author: Tae-Sun Park  Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuTab1ListsSub
//
//   -- the LIST that appears as a data element of TNuTab1Lists
//
//  It is a 1D functor that contains only y-points, y(0), y(1), ..., y(np-1),
//  where x-mesh and other informations for the interpolation is embodied
//  in the GetTab1() of the parent TNuTab1Lists.
//
//  Its ENDF format is
//
//  [T_n, C2, LI, L2, NR, NP/S(E; T_n)] LIST
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab1ListsSub.h"

#include "TNuTab1Lists.h"
#include "TNuTab1.h"

#include "TNuEndfIO.h"
#include "TNuMath.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuTab1ListsSub)

//______________________________________________________________________________
TNuTab1ListsSub::TNuTab1ListsSub(TNuEndfIO &src, const Char_t* label)
  : TNuList1(src, label) //TNuList(src, label)
{
   // ctor of TNuTab1ListsSub importing ENDF data
}

//______________________________________________________________________________
TNuTab1ListsSub::~TNuTab1ListsSub()
{
   // TNuTab1ListsSub dtor
}

//______________________________________________________________________________
void TNuTab1ListsSub::What() const
{
using namespace std;
   TNuList::What();
}

//______________________________________________________________________________
TNuTab1* TNuTab1ListsSub::GetTab1() const
{
   // returns the TNuTab1 of the parent TNuTab1Lists
   return ((TNuTab1Lists*) GetParent())->GetTab1();
}

//______________________________________________________________________________
void TNuTab1ListsSub::SetTransient()
{
   // Sets the range
   fXmin = GetTab1()->GetXmin();
   fXmax = GetTab1()->GetXmax();
}

//______________________________________________________________________________
Double_t TNuTab1ListsSub::EvalF1(Double_t E, Double_t* /*ps*/) const
{
   // returns the f(E; T_n) as a function of E

   TNuTab1* tab1 = GetTab1();

   Double_t* xp=tab1->GetX();

   Int_t n = TNuMath::BinarySearch(GetNP(), xp, E, 1);
   if (n < 0) return 0;
   Int_t interp = tab1->GetInterpolationLaw(n);

   // now do the interpolation
   Double_t xys[4];

   xys[0] = xp[n];
   xys[1] = At(n);

   xys[2] = xp[n+1];
   xys[3] = At(n+1);

   return Interpolation(interp, E, xys);
}
