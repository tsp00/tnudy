// TNuListLegendre.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuListLegendre
#define ROOT_TNuListLegendre


///////////////////////////////////////////////////////////////////////////////
//
// TNuListLegendre
//
// List of normalized Legendre polynomial coefficients
//
// f(mu) = 1/2 + sum_{l=1}^{NL} (2l+1)/2 a_l P_l(mu),
// where a_l = At(l-1) = fData[l-1], NL = GetNL()
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuList1.h"
//#include "TNuVF1.h"

class TNuEndfIO;

class TNuListLegendre : public TNuList1
{
public:
   TNuListLegendre() : TNuList1() {}
   TNuListLegendre(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuListLegendre(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NPL, N2");
   //TNuListLegendre(TNuCont *cont);
   virtual ~TNuListLegendre() {}

   Int_t    GetNL() const { return GetN1(); }

   Double_t EvalF1(Double_t x, Double_t *ps = 0) const;

   Int_t    GetNPar() const { return 0; }

protected:
   void     SetTransient();

   ClassDef(TNuListLegendre, 1) // TNuList for normalized Legendre polynomial coefficients
};

#endif

