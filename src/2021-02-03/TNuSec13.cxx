// TNuSec13.cxx  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec13 - Photon production cross sections
// 
//
/*
The purpose of File 13 is the same as that of File 12, namely, it can be used to represent
the neutron and photon energy dependence of photon production cross sections. In File 13,
however, absolute cross sections in barns are tabulated, and there is no need to refer to the
cross sections in File 3.
---------------- head
HeadAt(0) = TNuCont for
[MAT, 13, MT/ ZA, AWR, 0, 0, NK, 0]HEAD

HeadAt(1) = TNuTab1 (optional if NK > 1) for
[MAT, 13, MT/ 0.0, 0.0, 0, 0, NR, NP/ Eint/ #sigma_{total}^#{gamma} TAB1 (if NK>1)

---------------- body (NK elements)
BodyAt(n) = TNuTab1 for
[MAT, 13, MT/ EG, ES, LP, LF, NR, NP/ Eint / y(E)] TAB1
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec13.h"
#include "TNuMat.h"
#include "TF1.h"
#include "TMath.h"

#include <iostream>

ClassImp(TNuSec13)

//______________________________________________________________________________
TNuSec13::TNuSec13(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec13 ctor
}

//______________________________________________________________________________
TNuSec13::~TNuSec13()
{
   // TNuSec13 dtor
}

//______________________________________________________________________________
void TNuSec13::What() const
{
   using namespace std;
   TNuSection::What();

   cout << "\tNK  = " << GetNK() << " : Number of final states for which multiplicities are given" << endl;
   cout << "-------------------------------------------------------------------" << endl;
   cout << "The cross sections for " << GetParentMat()->GetProjTargetName() << endl;
   cout << "-------------------------------------------------------------------" << endl;
   for (Int_t k=0; k < GetNK(); k++) {
      cout << "EG = " << GetEGAt(k) << " eV, "
         << "  ES = " << GetESAt(k)
         << "  LP = " << GetLPAt(k)
         << "  LF = " << GetLFAt(k) << endl;
   }}

//______________________________________________________________________________
void TNuSec13::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 13
   //

   SetHead(new TNuCont(src, "ZA, AWR, LO, 0, NK, 0/HEAD"));
   if (GetNK() > 1) AddToHead(new TNuTab1(src, 
      "0.0, 0.0, 0, 0, NR, NP/Y(E)"));
   for (Int_t k=0; k < GetNK(); k++) {
      Add(new TNuTab1(src,
         "EG, ES, LP, LF, NR, NP/ Eint / y(E)"));
   }
}
