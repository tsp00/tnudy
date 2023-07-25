// TNuSec27.cxx  =====================================================
// Author: Tae-Sun Park   Feb 05 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec27 - Atomic form factors or scattering functions
//
/*
The ENDF system for neutron and photon production data allows two alternatives for
storing angular distribution data. One is by probability per unit cos(#theta) vs. cos(#theta), and
the other is by Legendre coefficients. Actually, neither of these is a natural method
for photons. The natural method would be atomic form factors or incoherent scattering
functions.
*/
// = [MAT, 27, MT/ ZA, AWR, 0, 0, 0, 0] HEAD
//   [MAT, 27, MT/ 0.0, Z, 0, 0, NR, NP/ qint / H(q;Z)]TAB1
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec27.h"
#include "TF1.h"

#include <iostream>

ClassImp(TNuSec27)

//______________________________________________________________________________
TNuSec27::TNuSec27(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt), TNuVF1()
{
   // TNuSec27 ctor
}

//______________________________________________________________________________
TNuSec27::~TNuSec27()
{
   // TNuSec27 dtor
}

//______________________________________________________________________________
void TNuSec27::What() const
{
   using namespace std;
   TNuSection::What();

   cout << "\tZ = " << GetZ() << " : charge Z" << endl;
}

//______________________________________________________________________________
void TNuSec27::SetTransient()
{
   fXmin = GetTab1()->GetXmin();
   fXmax = GetTab1()->GetXmax();
}

//______________________________________________________________________________
void TNuSec27::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 3
   //

   SetHead(new TNuCont(src, "ZA, AWR, 0,  0,  0,  0/HEAD"));
   Add(new TNuTab1(src, "0.0, Z, 0, 0, NR, NP/H(q;Z)"));
}
