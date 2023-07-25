// TNuList2Tab1.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuList2Tab1
#define ROOT_TNuList2Tab1

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

#include "TNuList2.h"

class TNuEndfIO;

class TNuList2Tab1 : public TNuList2
{
public:
   TNuList2Tab1() : TNuList2() {}
   TNuList2Tab1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuList2Tab1(TNuEndfIO &src, const Char_t* label=" 0.0, E, ND, NA, NW, NEP");
   TNuList2Tab1(const TNuList2Tab1 &list);
   virtual ~TNuList2Tab1();

   Double_t   EvalAt(Int_t n, Double_t y, Double_t* ps = 0) const;
   Int_t      GetInterpolationLaw(Int_t /*pos*/) const { return GetLANG()-10; }

protected:
   void               SetTransient();

   ClassDef(TNuList2Tab1, 0) // TNuList2 where a sub-list is for TAB1 data
};

#endif
