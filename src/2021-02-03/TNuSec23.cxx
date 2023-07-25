// TNuSec23.cxx  =====================================================
// Author: Tae-Sun Park   Feb 05 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec23 - Smooth photon interaction cross sections
//
// = [MAT, 23, MT/ ZA, AWR, 0, 0, 0, 0] HEAD
//   [MAT, 23, MT/ EPE, EFL, 0, 0, NR, NP/ Eint/sig(E)]TAB1
//   [MAT, 3,  0/ 0.0, 0.0,  0,  0,  0,  0] SEND
/*
Photon interaction data are divided into two files. File 23 is analogous to File 3 and contains
the smooth cross sections. File 27 contains the coherent scattering form factors and
incoherent scattering functions (see Chapter 27).
Electron interaction data are divided into two different files. The smooth cross sections
for elastic scattering, bremsstrahlung, excitation, and the ionization of different atomic
subshells are given in File 23. File 26 is used to give the angular distribution for elastically
scattered electrons, the outgoing photon spectra and energy loss for bremsstrahlung, the
energy transfer for excitation, and the spectra of the scattered and recoil electrons associated
with subshell ionization.
Both photo-atomic and electro-atomic reactions can leave the atom in an ionized state.
See Section 28 for a description of the atomic relaxation data needed to compute the outgoing
X-ray and electron spectra as an ionized atom relaxes back to neutrality.
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec23.h"
#include "TF1.h"

#include <iostream>

ClassImp(TNuSec23)

//______________________________________________________________________________
TNuSec23::TNuSec23(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt), TNuVF1()
{
   // TNuSec23 ctor
}

//______________________________________________________________________________
TNuSec23::~TNuSec23()
{
   // TNuSec23 dtor
}

//______________________________________________________________________________
void TNuSec23::What() const
{
   using namespace std;
   TNuSection::What();

   cout << "\tEPE = " << GetEPE() << " : Subshell binding energy (equal to the photoelectric edge energy) in eV." << endl;
   cout << "\tEPL = " << GetEPL() << " : Fluorescence yield (eV/photoionization)." << endl;
}

//______________________________________________________________________________
void TNuSec23::SetTransient()
{
   fXmin = GetTab1()->GetXmin();
   fXmax = GetTab1()->GetXmax();
}

//______________________________________________________________________________
void TNuSec23::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 3
   //

   SetHead(new TNuCont(src, "ZA, AWR, 0,  0,  0,  0/HEAD"));
   Add(new TNuTab1(src, "EPE, EFL, 0, 0, NR, NP/#sigma(E)"));
}
