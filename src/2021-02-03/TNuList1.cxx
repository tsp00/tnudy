// TNuList1.cxx  =====================================================
// Author: Tae-Sun Park   Feb 24 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuList1
//
// -- Service class for TNuList with TNuVF1
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuList1.h"
#include "TNuEndfIO.h"
//#include "TF1.h"

ClassImp(TNuList1)

//______________________________________________________________________________
TNuList1::TNuList1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuList(c1,c2,l1,l2,n1,n2), TNuVF1()
{
   // ctor of TNuList1 importing ENDF data
}

//______________________________________________________________________________
TNuList1::TNuList1(TNuEndfIO &src, const Char_t* label)
  : TNuList(src, label), TNuVF1()
{
   // ctor of TNuList1 importing ENDF data
}
