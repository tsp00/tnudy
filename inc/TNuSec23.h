// TNuSec23.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2011

#ifndef ROOT_TNuSec23
#define ROOT_TNuSec23

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

#include "TNuSection.h"
#include "TNuVF1.h"

#include "TNuTab1.h"
#include "TNuEndfIO.h"

class TNuSec23 : public TNuSection, public TNuVF1
{
public:
   TNuSec23() : TNuSection(), TNuVF1() {}
   TNuSec23(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec23();

   void          What() const; // *MENU*

   const Char_t* GetSymbol() const { return "#sigma(E) [barn]"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   Bool_t   IsF1() const { return kTRUE; }

   TNuTab1* GetTab1() const { return (TNuTab1*) BodyFirst(); }

   Double_t EvalF1(Double_t Ein, Double_t *ps=0) const {
      return GetTab1()->EvalF1(Ein, ps);
   }
   Double_t XSect(Double_t Ein, Double_t *ps=0) const { return EvalF1(Ein, ps); }
   void     DrawXSect() { Draw(); } // *MENU*

   Double_t GetEPE() const { return GetTab1()->GetC1(); }
   Double_t GetEPL() const { return GetTab1()->GetC2(); }

   void     ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();

   ClassDef(TNuSec23, 1)//Smooth photon interaction cross sections
};

#endif

