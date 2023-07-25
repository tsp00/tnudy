// TNuListTaylor.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuListTaylor
//
// List of Taylor polynomial
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuListTaylor.h"

#include "TNuEndfIO.h"
#include "TNudy.h"
#include "TNuMat.h"
#include "TF1.h"

ClassImp(TNuListTaylor)

//______________________________________________________________________________
TNuListTaylor::TNuListTaylor(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuList1(c1,c2,l1,l2,n1,n2)
{
   // ctor of TNuListTaylor importing ENDF data
}

//______________________________________________________________________________
TNuListTaylor::TNuListTaylor(TNuEndfIO &src, const Char_t* label) : TNuList1(src, label)
{
   // ctor of TNuListTaylor importing ENDF data
}

//______________________________________________________________________________
void TNuListTaylor::SetTransient()
{
   // Sets the range
   // NB. Followings should be checked if sensible.
   fXmin = 1.E-5;
   fXmax = GetParentMat()->GetEMAX();
}

//______________________________________________________________________________
Double_t TNuListTaylor::EvalF1(Double_t x, Double_t* /*ps*/) const
{
   Double_t y = 0;
   Double_t en = 1;
   for (Int_t n = 0; n < GetNC(); en *= x, n++)
      y += At(n) * en;
   return y;
}

