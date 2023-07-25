// TNuMath.h  =====================================================
// Author: Tae-Sun Park   Nov. 05, 2011

#ifndef ROOT_TNuMath
#define ROOT_TNuMath

#include "TMath.h"
#include "TComplex.h"

namespace TNuMath
{
   //==============================================================================
   // Constants
   //==============================================================================

   // proton's charge in [C]
   inline Double_t ElementaryCharge() { return 1.602176462E-19; }

   // inverse fine-structure constant
   inline Double_t InverseFineStructureConstant() { return 137.03599976; }

   // fine-structure constant
   inline Double_t FineStructureConstant() { return 1/InverseFineStructureConstant(); }

   // atomic mass unit (amu) [eV/c^2]
   inline Double_t AtomicMassUnit() { return 931.494013E+06; }
   inline Double_t AMU() { return AtomicMassUnit(); }

   // speed of light (in vacuum) [m/s]
   inline Double_t SpeedOfLight() { return 299792458; }

   // Plank constant [eV*s]
   inline Double_t PlankConstant() { return 4.13566727E-15; }

   // Plank constant/2 pi [eV*s]
   inline Double_t HbarEvSec() { return 6.58211889E-16; }
   inline Double_t PlankConstant2Pi() { return HbarEvSec(); }

   // hbar in [eV * 10 fm]
   inline Double_t HbarEv10fm() { return HbarEvSec() * SpeedOfLight() * 1.E+14; }

   // Boltzmann's constant [eV/K]
   inline Double_t BoltzmannConstant() { return 8.617342E-5; }

   // hbar*c
   inline Double_t HBarC() { return HbarEvSec()*SpeedOfLight(); }

   // Avogadro number [1/mol]
   inline Double_t AvogadroNumber() { return 6.02214199E+23; }

//
// masses in the unit of amu
//
//

   inline Double_t ANumberOfNeutron () { return 1.00866491578; }
   inline Double_t ANumberOfElectron() { return 5.485799110E-4; }
   inline Double_t ANumberOfProton  () { return 1.00727646688; }
   inline Double_t ANumberOfDeuteron() { return 2.01355321271; }
   inline Double_t ANumberOfTriton  () { return 3.015500713; }
   inline Double_t ANumberOfHe3     () { return 3.01493223469; }
   inline Double_t ANumberOfAlpha   () { return 4.0015061747; }

//
// masses in the unit of eV
//

   inline Double_t MassOfNeutron () { return AMU() * ANumberOfNeutron(); }
   inline Double_t MassOfElectron() { return AMU() * ANumberOfElectron(); }
   inline Double_t MassOfProton  () { return AMU() * ANumberOfProton(); }
   inline Double_t MassOfHydrogen() { return MassOfElectron() + MassOfProton(); }
   inline Double_t MassOfDeuteron() { return AMU() * ANumberOfDeuteron(); }
   inline Double_t MassOfTriton  () { return AMU() * ANumberOfTriton(); }
   inline Double_t MassOfHe3     () { return AMU() * ANumberOfHe3(); }
   inline Double_t MassOfAlpha   () { return AMU() * ANumberOfAlpha(); }

//
// Energies needed to break particles into their constituent nucleons
//
/*
   inline Double_t kBreakEnergyOfDeuteron() { return 2.22 * 1000000; }
   inline Double_t kBreakEnergyOfTriton  () { return 8.48 * 1000000; }
   inline Double_t kBreakEnergyOfHe3     () { return 7.72 * 1000000; }
   inline Double_t kBreakEnergyOfAlpha   () { return 28.3 * 1000000; }
*/
   inline Double_t BreakEnergyOfDeuteron()
     { return MassOfProton() + MassOfNeutron() - MassOfDeuteron(); }

   inline Double_t BreakEnergyOfTriton()
     { return MassOfProton() + 2*MassOfNeutron() - MassOfTriton(); }

   inline Double_t BreakEnergyOfHe3()
     { return 2*MassOfProton() + MassOfNeutron() - MassOfHe3(); }

   inline Double_t BreakEnergyOfAlpha()
     { return 2*MassOfProton() + 2*MassOfNeutron() - MassOfAlpha(); }


   // sum (2n+1)/2 f[n-1] P_n(x), n=1, NL
   //Double_t LegendreFromOne(Int_t NL, Double_t x, Double_t* f);

   // sum (2n+1)/2 f[n] P_n(x), n=0, NL
   //Double_t Legendre(Int_t NL, Double_t x, Double_t* f);

   // sum (4n+1)/2 f[n] P_2n(x), n=0, NL
   //Double_t LegendreEven(Int_t NL, Double_t x, Double_t* f);

   //==============================================================================
   // Some simple macros/functions
   //==============================================================================
   inline Double_t SignedSqrt(Double_t x) { return (x >= 0) ? TMath::Sqrt(x) : -TMath::Sqrt(-x); }

   inline Double_t GetMassExcess(Int_t a, Double_t awr) { return
      awr*MassOfNeutron()/AMU() - a; } //mass excess in AMU

   inline Double_t GetBindingEnergy(Int_t z, Int_t a, Double_t awr) { return
      (a-z-awr)*MassOfNeutron() + z*MassOfHydrogen(); } // (N*m_n + Z*m_H - m)*c^2 in eV

   //==============================================================================
   // For potential scattering of hardsphere
   //==============================================================================

   void          HardsphereFactors(Int_t L, Double_t z, Double_t *p, Double_t *s);
   Double_t      HardspherePhaseShift(Int_t L, Double_t z);


   //==============================================================================
   // Inverse of complex 3x3 symmetric matrix
   //==============================================================================
   void          InverseSymmetricComplex3x3Matrix(TComplex m[3][3]);

   //==============================================================================
   // Perform the binary search for a data of type
   //
   // E_0      d_0 d_1 ...  d_{w-1} // d_i = d_i(E_0)
   // E_1      d_0 d_1 ...  d_{w-1} // d_i = d_i(E_1)
   // ...
   // E_{np-1} d_0 d_1 ...  d_{w-1} // d_i = d_i(E_{np-1})
   //
   Int_t BinarySearch(Int_t np, Double_t *data, Double_t E, Int_t width = 1);

   //==============================================================================
   // Perform the binary search and interpolation for a data of type
   //
   // E_0      d_0 d_1 ...  d_{w-1} // d_i = d_i(E_0)
   // E_1      d_0 d_1 ...  d_{w-1} // d_i = d_i(E_1)
   // ...
   // E_{np-1} d_0 d_1 ...  d_{w-1} // d_i = d_i(E_{np-1})
   //
   // First find n such that E_n <= Ein < E_{n+1},
   // then do the interpolatin for d_i, {i,0,width-1},
   // then save the output to result array as
   // result = {(Double_t) n, d_0, d_1, ..., d_{width-1}}.
   // The result array must be allocated by the user.
   //
   // It returns kTRUE is the interpolation has been successfully carried out,
   // and kFALSE if problem happened.
   //
   Bool_t Interpolation(Double_t Ein, Double_t *data,
            Int_t interp, Int_t np, Int_t width, Double_t *result);

   //==============================================================================
   // Special functions 
   //==============================================================================
   Double_t ExpIntegralE1(Double_t x);
}

#endif
