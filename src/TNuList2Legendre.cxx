// TNuList2Legendre.cxx  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuList2Legendre                                                          //
//                                                                           //
//  --- TAB2 of LISTs but represented by a single LIST                       //
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
// {b_0, b_1, ..., b_NA} : coefficients of (unnormalized) Legendre poly.     //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuList2Legendre.h"
#include "TNuEndfIO.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuList2Legendre)

//______________________________________________________________________________
TNuList2Legendre::TNuList2Legendre(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuList2(c1,c2,l1,l2,n1,n2)
{
   // TNuList2Legendre ctor
}

//______________________________________________________________________________
TNuList2Legendre::TNuList2Legendre(TNuEndfIO &src, const Char_t* label)
  : TNuList2(src, label)
{
   // ctor of TNuList2Legendre importing ENDF data
}

//______________________________________________________________________________
TNuList2Legendre::TNuList2Legendre(const TNuList2Legendre &list)
  : TNuList2(list)
{
   // TNuList2Legendre copy ctor
}

//______________________________________________________________________________
TNuList2Legendre::~TNuList2Legendre()
{
   // TNuList2Legendre dtor
}

/*
//______________________________________________________________________________
void TNuList2Legendre::What() const
{
using namespace std;
   TNuList2::What();
}
*/


//______________________________________________________________________________
Double_t TNuList2Legendre::EvalAt(Int_t n, Double_t y, Double_t* /*ps*/) const
{
   // returns the evaluated value at n-th sub record

   Double_t *bs = GetDataArrayAt(n);
   //
   Double_t sum = 0.5*bs[0];
   Double_t Plm1 = 0;
   Double_t Pl = 1;
   Double_t Plsav;
   for (Int_t l=1; l <= GetNA(); l++, Plm1 = Plsav) {
      Plsav = Pl;
      Pl = ((2*l-1) * y * Pl - (l-1) * Plm1) /l;
      sum += (2l+1)*Pl/2 * bs[l];
   }
   return sum;
}
