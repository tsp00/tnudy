// TNuList2Legendre.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuList2Legendre
#define ROOT_TNuList2Legendre

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

#include "TNuList2.h"

class TNuEndfIO;

class TNuList2Legendre : public TNuList2
{
public:
   TNuList2Legendre() : TNuList2() {}
   TNuList2Legendre(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuList2Legendre(TNuEndfIO &src, const Char_t* label=" 0.0, E, ND, NA, NW, NEP");
   TNuList2Legendre(const TNuList2Legendre &list);
   virtual ~TNuList2Legendre();

   Bool_t   IsF2() const { return kTRUE; }
   void               DrawTF2() { Draw("surf"); } // *MENU*

   Double_t   GetX(Int_t n) const { return GetEAt(n); }
   Double_t   EvalAt(Int_t n, Double_t y, Double_t* ps = 0) const;
   Int_t      GetInterpolationLaw(Int_t /*pos*/) const { return 2; }

   ClassDef(TNuList2Legendre, 0) // TNuList2 where a sub-list is for Legendre coefficients
};

#endif
