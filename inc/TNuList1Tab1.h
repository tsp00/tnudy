// TNuList1Tab1.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuList1Tab1
#define ROOT_TNuList1Tab1

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuList1Tab1                                                              //
//                                                                           //
//  --- TNuTab1 represented as a TNuList                                     //
//                                                                           //
//   0.0, E,  LANG,   0, NW, NL/                                            //
//   Double_t fData[]                                                        //
//                                                                           //
//  where NW = 2*NL, and LANG - 10 = interpolation law                       //
//  and fData[] = x_0, y_0, x_1, y_1, ..., x_{NL-1}, y_{NL-1}                //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuList1.h"
//#include "TNuVTab.h"
//#include "TNuVF1.h"

class TNuEndfIO;

class TNuList1Tab1 : public TNuList1
{
public:
   TNuList1Tab1() : TNuList1() {}
   TNuList1Tab1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuList1Tab1(TNuEndfIO &src, const Char_t* label=" 0.0, E,  LANG,   0, NW, NL");
   TNuList1Tab1(const TNuList1Tab1 &list);
   virtual ~TNuList1Tab1();

   void       What() const; // *MENU*

   Double_t   GetE() const { return GetC2(); }
   Int_t      GetLANG() const { return GetL1(); }
   Int_t      GetNW() const { return GetN1(); }
   Int_t      GetNL() const { return GetN2(); }

   Double_t   GetX(Int_t n) const { return At(2*n); }
   Double_t   GetY(Int_t n) const { return At(2*n+1); }
   Int_t      GetInterpolationLaw(Int_t /*pos*/) const { return GetLANG()-10; }

   Double_t   EvalF1(Double_t x, Double_t *ps = 0) const;

protected:
   void       SetTransient();


   ClassDef(TNuList1Tab1, 0) // TNuTab1 represented as a TNuList
};

#endif
