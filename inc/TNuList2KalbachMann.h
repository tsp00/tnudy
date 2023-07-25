// TNuList2KalbachMann.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuList2KalbachMann
#define ROOT_TNuList2KalbachMann

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuList2KalbachMann                                                       //
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
//  Kalbach-Mann :                                                           //
//                                                                           //
//  NA=1 : b_0 = f_0, b_1 = r                                                //
//  NA=2 : b_0 = f_0, b_1 = r, b_2 = a                                       //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuList2.h"

class TNuEndfIO;

class TNuList2KalbachMann : public TNuList2
{
public:
   TNuList2KalbachMann() : TNuList2() {}
   TNuList2KalbachMann(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuList2KalbachMann(TNuEndfIO &src, const Char_t* label=" 0.0, E, ND, NA, NW, NEP");
   TNuList2KalbachMann(const TNuList2KalbachMann &list);
   virtual ~TNuList2KalbachMann();

   //Double_t           GetY(Int_t n) const;
   Double_t   EvalAt(Int_t n, Double_t y, Double_t* ps = 0) const;

   Double_t GetSepEnergyInMeV(Int_t z, Int_t n) const;
   Double_t GetSlopeValue(Int_t n) const;
   Double_t GetSlopeValue(Double_t EaLab, Double_t EbCM) const;

   // for check of the routine for the calc of the slope values
   void CheckSlopeValues() const; // *MENU*

   ClassDef(TNuList2KalbachMann, 0) // TNuList2 where a sub-list is for Kalbach-Mann coefficients
};

#endif
