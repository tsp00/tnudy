// TNuTab2List1.cxx  =====================================================
// Author: Tae-Sun Park   Mar 06 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab2List1
//
// TAB2 of TNuList1
// =
//  C1 C2 L1 L2 NR NZ
//  (NBT(n), INT(n), n=1,NR)
//  (<m-th TNuObject>, m=1,NZ)
//
///////////////////////////////////////////////////////////////////////////////


#include "TNuTab2List1.h"
#include "TNuList1.h"

#include "TNuVF1.h"

//#include "TNuEndfIO.h"

#include "TBrowser.h"

#include <iostream>
#include <iomanip>
using namespace std;

#include "TNudy.h"
#include "TNuSection.h"

ClassImp(TNuTab2List1)

//______________________________________________________________________________
TNuTab2List1::TNuTab2List1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuTab2(c1,c2,l1,l2,n1,n2)
{
   // TNuTab2List1 ctor
}

//______________________________________________________________________________
TNuTab2List1::TNuTab2List1(TNuEndfIO &src, const Char_t* label)
 : TNuTab2(src, label)
{
   // ctor of TNuTab2List1 importing ENDF data
}

//______________________________________________________________________________
TNuTab2List1::~TNuTab2List1()
{
   // dtor of TNuTab2List1
}
