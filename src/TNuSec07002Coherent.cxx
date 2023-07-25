// TNuSec07002Coherent.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec07002 - Thermal neutron elastic coherent scattering data (E < 5 eV)
//
/*
This section describes the scattering data
Begin_Latex
#frac{d^{2}#sigma(E_{n}, E_{p}, #mu, T)}{dE_{p} d#Omega} = #frac{d#sigma(E_{n}, #mu, T)}{d#Omega} #delta(E_{n}-E_{p}),
End_Latex
for the thermal neutron energy range (En < 5 eV).

LTHR = GetL1() = 1, meaning that it is coherent scattering data  and provides
Begin_Latex
S(T, E) = #sum_{i}^{E_{i} < E} S_{i}(T)
End_Latex
such that
Begin_Latex
#frac{d#sigma(E, #mu, T)}{d#Omega} = #frac{1}{E} #sum_{i}^{E_{i}<E} S_{i}(T) #delta(#mu - #mu_{i}) /2#pi,
End_Latex
where #mu_{i} = 1 -2 E_{i}/E, T is the moderator temperature
and E_{i} are energies of the Bragg edges.

---------------- head (1 element)
HeadAt(0) = TNuCont for
[MAT, 7, 2/ ZA, AWR, LTHR, 0, 0, 0] HEAD LTHR=1

---------------- body (1 element)
BodyAt(0) = TNuTab1Lists for
[MAT, 7, 2/ T0, 0.0, LT, 0, NR, NP/ Eint / S(E,T0) ] TAB1
[MAT, 7, 2/ T1, 0.0, LI, 0, NP, 0/ S(Ei,T1) ] LIST
---------------------------
<repeat LIST for T2, T3, ...TLT>
--------------------------
[MAT, 7, 0/0.0, 0.0, 0, 0, 0, 0] SEND
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec07002Coherent.h"
#include "TF1.h"

#include "TNuTab1Lists.h"
#include "TNuTab1ListsSub.h"

#include <iostream>

ClassImp(TNuSec07002Coherent)

//______________________________________________________________________________
TNuSec07002Coherent::TNuSec07002Coherent(Int_t mat, Int_t mf, Int_t mt)
 : TNuSec07002(mat, mf, mt), TNuVF2()
{
   // TNuSec07002Coherent ctor
}

//______________________________________________________________________________
TNuSec07002Coherent::~TNuSec07002Coherent()
{
   // TNuSec07002Coherent dtor
}

//______________________________________________________________________________
void TNuSec07002Coherent::What() const
{
   using namespace std;
   TNuSection::What();

}

//______________________________________________________________________________
void TNuSec07002Coherent::SetTransient()
{
   // range on T and E of S(T,E)
   TNuTab1Lists* tabs = GetTab1Lists();

   fXmin = tabs->GetXmin();
   fXmax = tabs->GetXmax();
   fYmin = tabs->GetYmin();
   fYmax = tabs->GetYmax();
}
