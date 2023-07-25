// TNuTab3Tab1Lists.cxx  =====================================================
// Author: Tae-Sun Park   Mar 06 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab3Tab1Lists
//
// TAB2 of TNuTab1Lists
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th Tab2>, m=1,NZ)
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab3Tab1Lists.h"
#include "TNuTab1Lists.h"

#include "TNuVF2.h"

#include "TBrowser.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuTab3Tab1Lists)

//______________________________________________________________________________
TNuTab3Tab1Lists::TNuTab3Tab1Lists(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuTab3(c1,c2,l1,l2,n1,n2)
{
   // TNuTab3Tab1Lists ctor
}


//______________________________________________________________________________
TNuTab3Tab1Lists::TNuTab3Tab1Lists(TNuEndfIO &src, const Char_t* label) : TNuTab3(src, label)
{
   // ctor of TNuTab3Tab1Lists importing ENDF data
}

//______________________________________________________________________________
TNuTab3Tab1Lists::~TNuTab3Tab1Lists()
{
}
