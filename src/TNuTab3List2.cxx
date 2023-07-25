// TNuTab3List2.cxx  =====================================================
// Author: Tae-Sun Park   Mar 06 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab3List2
//
// TTAB2 of TNuList2
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th Tab2>, m=1,NZ)
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab3List2.h"
#include "TNuList2.h"

#include "TNuVF2.h"

#include "TBrowser.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuTab3List2)

//______________________________________________________________________________
TNuTab3List2::TNuTab3List2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuTab3(c1,c2,l1,l2,n1,n2)
{
   // TNuTab3List2 ctor
}


//______________________________________________________________________________
TNuTab3List2::TNuTab3List2(TNuEndfIO &src, const Char_t* label) : TNuTab3(src, label)
{
   // ctor of TNuTab3List2 importing ENDF data
}

//______________________________________________________________________________
TNuTab3List2::~TNuTab3List2()
{
}
