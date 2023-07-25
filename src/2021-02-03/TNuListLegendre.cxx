// TNuListLegendre.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

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

#include "TNuListLegendre.h"
#include "TNuEndfIO.h"
#include "TF1.h"

ClassImp(TNuListLegendre)

//______________________________________________________________________________
TNuListLegendre::TNuListLegendre(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuList1(c1,c2,l1,l2,n1,n2)
{
   // ctor of TNuListLegendre importing ENDF data
}

//______________________________________________________________________________
TNuListLegendre::TNuListLegendre(TNuEndfIO &src, const Char_t* label)
  : TNuList1(src, label)
{
   // ctor of TNuListLegendre importing ENDF data
}

//______________________________________________________________________________
void TNuListLegendre::SetTransient()
{
   // Sets the range
   fXmin = -1;
   fXmax = +1;
}

//______________________________________________________________________________
Double_t TNuListLegendre::EvalF1(Double_t x, Double_t * /*ps*/) const
{
   //
   Double_t sum = 0.5;
   Double_t Plm1 = 0;
   Double_t Pl = 1;
   Double_t Plsav;
   for (Int_t l=1; l <= GetNL(); l++, Plm1 = Plsav) {
      Plsav = Pl;
      Pl = ((2*l-1) * x * Pl - (l-1) * Plm1) /l;
      sum += (2*l+1)*Pl/2 * fData[l-1];
   }
   return sum;
}
