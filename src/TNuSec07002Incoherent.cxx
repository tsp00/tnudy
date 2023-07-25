// TNuSec07002Incoherent.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec07002Incoherent - Thermal neutron elastic incoherent scattering data (E < 5 eV)
/*
This section describes the scattering data
Begin_Latex
#frac{d^{2}#sigma(E_{n}, E_{p}, #mu, T)}{dE_{p} d#Omega} = #frac{d#sigma(E_{n}, #mu, T)}{d#Omega} #delta(E_{n}-E_{p}},
End_Latex
for the thermal neutron energy range (En < 5 eV).

LTHR = GetL1() = 2, meaning that it is for inelastic scattering data,
and provides Wp(T) such that
Begin_Latex
#frac{d#sigma(E_{n}, #mu, T)}{d#Omega} = #frac{#sigma_{b}}{4#pi} e^{-2 E_{n} W'(T)(1-#mu)},
End_Latex
where #sigma_{b} is the characteristic bound cross section (barns),
and Wp(T) is the DebyeWaller integral divided by the atomic mass.

---------------- head (1 element)
HeadAt(0) = TNuCont for
[MAT, 7, 2/ ZA, AWR, LTHR, 0, 0, 0] HEAD LTHR=2

---------------- body (1 element)
BodyAt(0) = TNuTab1 for
[MAT, 7, 2/ SB, 0.0, 0, 0, NR, NP/ Wp(T) ] TAB1
where SB stands for he characteristic bound cross section.
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec07002Incoherent.h"
#include "TF1.h"

#include "TNuTab1Lists.h"
#include "TNuTab1ListsSub.h"

#include <iostream>

ClassImp(TNuSec07002Incoherent)

//______________________________________________________________________________
TNuSec07002Incoherent::TNuSec07002Incoherent(Int_t mat, Int_t mf, Int_t mt) : TNuSec07002(mat, mf, mt)
{
   // TNuSec07002Incoherent ctor
}

//______________________________________________________________________________
TNuSec07002Incoherent::~TNuSec07002Incoherent()
{
   // TNuSec07002Incoherent dtor
}

//______________________________________________________________________________
void TNuSec07002Incoherent::What() const
{
   using namespace std;
   TNuSection::What();

}

//______________________________________________________________________________
void TNuSec07002Incoherent::SetTransient()
{
   // range on T of W(T)

   fXmin = GetTab1()->GetXmin();
   fXmax = GetTab1()->GetXmax();
}