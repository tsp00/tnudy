// TNuListTaylor.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuListTaylor
#define ROOT_TNuListTaylor

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuListTaylor                                                             //
//                                                                           //
// List of Taylor polynomial                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuList1.h"
//#include "TNuVF1.h"

class TNuEndfIO;

class TNuListTaylor : public TNuList1
{
public:
   TNuListTaylor() : TNuList1() {}
   TNuListTaylor(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuListTaylor(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NC, N2");
   virtual ~TNuListTaylor() {}

   Int_t    GetNC() const { return GetN1(); }

   Double_t EvalF1(Double_t x, Double_t *ps = 0) const;

protected:
   void     SetTransient();

   ClassDef(TNuListTaylor, 1) // TNuList for Taylor polynomial coefficients
};

#endif
