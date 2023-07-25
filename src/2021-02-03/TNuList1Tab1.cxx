// TNuList1Tab1.cxx  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuList1Tab1
//
// [MAT,MF,MT/ C1, C2, L1, L2, NPL, N2/ Bn] LIST
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuList1Tab1.h"
#include "TNuEndfIO.h"
#include "TNuMath.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuList1Tab1)

//______________________________________________________________________________
TNuList1Tab1::TNuList1Tab1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuList1(c1,c2,l1,l2,n1,n2)
{
   // TNuList1Tab1 ctor
}

//______________________________________________________________________________
TNuList1Tab1::TNuList1Tab1(TNuEndfIO &src, const Char_t* label)
  : TNuList1(src, label)
{
   // ctor of TNuList1Tab1 importing ENDF data
}

//______________________________________________________________________________
TNuList1Tab1::TNuList1Tab1(const TNuList1Tab1 &list)
  : TNuList1(list)
{
   // TNuList1Tab1 copy ctor
}

//______________________________________________________________________________
TNuList1Tab1::~TNuList1Tab1()
{
   // TNuList1Tab1 dtor
}

//______________________________________________________________________________
void TNuList1Tab1::What() const
{
using namespace std;
   TNuList::What();
   cout << "    E = " << GetE() << " : Incident energy" << endl;
   cout << " LANG = " << GetLANG() << " : 10 + (interpolation law)" << endl;
   cout << "   NL = " << GetNL() << " : number of tabulated data points" << endl;
}

//______________________________________________________________________________
void TNuList1Tab1::SetTransient()
{
   // Sets the range
   fXmin = GetX(0);
   fXmax = GetX(GetNL()-1);
}

//______________________________________________________________________________
Double_t TNuList1Tab1::EvalF1(Double_t x, Double_t* /*ps*/) const
{
   // Evaluate TNuList1Tab1 (a 1-dim functor)

   if (x < GetXmin() || x > GetXmax()) return 0;

   // find the interpolatio law
   Int_t interp= GetLANG()-10;

   // now do the interpolation
   Double_t out[2];
   TNuMath::Interpolation(x, fData, interp, fN2, 2, out);
   return out[1];
}
