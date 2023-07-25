// TNuList2Tab1.cxx  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuList2Tab1                                                              //
//                                                                           //
//  --- 2 dimensional functor represented as a single LIST                   //
//                                                                           //
//   0.0, En, ND, NA, NW, NEP/                                               //
//   E_0',   b_0(En, E_0'),   b_1(En, E_0'),   ... , b_NA(En, E_0')          //
//   E_1',   b_0(En, E_1'),   b_1(En, E_1'),   ... , b_NA(En, E_1')          //
//   E_2',   b_0(En, E_2'),   b_1(En, E_2'),   ... , b_NA(En, E_2')          //
//    ...                                                                    //
//   E_M',   b_0(En, E_M'),   b_1(En, E_M'),   ... , b_NA(En, E_M')          //
//                                                                           //
//  where M= NEP-1.                                                          //
//                                                                           //
//                                                                           //
//  b_0 : f_0                                                                //
//  b_1 = mu_1, b_2 = y(mu_1)                                                //
//  b_3 = mu_2, b_4 = y(mu_2)                                                //
//  ... ...                                                                  //
//              b_NA= y(mu_NA/2)                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuList2Tab1.h"
#include "TNuEndfIO.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuList2Tab1)

//______________________________________________________________________________
TNuList2Tab1::TNuList2Tab1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuList2(c1,c2,l1,l2,n1,n2)
{
   // TNuList2Tab1 ctor
}

//______________________________________________________________________________
TNuList2Tab1::TNuList2Tab1(TNuEndfIO &src, const Char_t* label)
  : TNuList2(src, label)
{
   // ctor of TNuList2Tab1 importing ENDF data
}

//______________________________________________________________________________
TNuList2Tab1::TNuList2Tab1(const TNuList2Tab1 &list)
  : TNuList2(list)
{
   // TNuList2Tab1 copy ctor
}

//______________________________________________________________________________
TNuList2Tab1::~TNuList2Tab1()
{
   // TNuList2Tab1 dtor
}

/*
//______________________________________________________________________________
void TNuList2Tab1::What() const
{
using namespace std;
   TNuList2::What();
}
*/

//______________________________________________________________________________
void TNuList2Tab1::SetTransient()
{
   // Sets the range
   fXmin =  GetEAt(0);
   fXmax =  GetEAt(GetNEP()-1);

   for (Int_t n=0; n < GetNEP(); n++) {
      Double_t y1 = GetDataAt(n,1);
      Double_t y2 = GetDataAt(n, GetNA()-1);
      if (n==0) {
         fYmin = y1;
         fYmax = y2;
      } else {
         fYmin = TMath::Min(fYmin, y1);
         fYmax = TMath::Max(fYmax, y2);
      }
   }
}

//______________________________________________________________________________
Double_t TNuList2Tab1::EvalAt(Int_t n, Double_t y, Double_t* /*ps*/) const
{
   // returns the evaluated value at n-th sub record

   Double_t *bs = GetDataArrayAt(n);
   //
   Int_t interp = GetLANG() - 10;
   Double_t f = InterpolationXY(interp, y, bs+1, GetNA()/2);
   return 2 * bs[0] * f;
}
