// TNuSec08457.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec08457 - spontaneous radioactive decay data (MT=457)
//
/*
HeadAt(0) = TNuCont for
 "ZA, AWR, LIS, LISO, NST, NSP/HEAD";

 LIS State of the original nuclide (LIS=0, ground state, LIS=1, first excited state,
 LISO Isomeric state number for the original nuclide (LISO=0, ground state;
LISO=1, first isomeric state;
 NST Nucleus stability flag (NST=0, radioactive; NST=1, stable)
 NSP Total number of radiation types (STYP) for which spectral information is
given (NSP may be zero).

HeadAt(1) = a TNuList for
   "T12, +-, 0, 0, 2*NC, 0; Ex, +-";

   T12 half-life of the original nuclide (seconds).
   Ex : Average decay energy (eV) of radiation x

HeadAt(2) = a TNuList for
   "SPI, PAR, 0, 0, 6*NDK, NDK; RTYP, RFS, Q, +-, BR, +-";

   SPI Spin of the nuclide in its LIS state.
       (SPI=-77.777 implies spin unknown)
   PAR Parity of the nuclide in its LIS state (+/- 1.0).
   NDK Total number of decay modes given.
   RTYP Mode of decay of the nuclide in its LIS state.
   RTYP Decay Mode
       0. gamma gamma-ray (not used in MT457)
       1. beta Beta decay
       2. e.c., beta+ Electron capture and/or positron emission
       3. IT Isomeric transition (will in general be present only when the
           state being considered is an isomeric state)
       4. alpha Alpha decay
       5. n Neutron emission (not delayed neutron decay, see below)
       6. SF Spontaneous fission
       7. p Proton emission
       10. Unknown origin
   RFS Isomeric state flag for daughter nuclide.
       RFS=0.0, ground state;
       RFS=1.0, first isomeric state
   Q Total decay energy (eV) available in the corresponding decay process.
   BR Fraction of the decay of the nuclide in its LIS state.

BodyAt(n) = a TNuSFYSub, n=[0, NSP)
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec08457.h"
#include "TF1.h"

#include "TNuTab1.h"
#include "TNuMat.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuSec08457)



//______________________________________________________________________________
TNuSec08457::TNuSec08457(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec08457 ctor
}

//______________________________________________________________________________
TNuSec08457::~TNuSec08457()
{
   // TNuSec08457 dtor
}

//______________________________________________________________________________
void TNuSec08457::What() const
{
   using namespace std;
   TNuSection::What();
}

//______________________________________________________________________________
void TNuSec08457::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of MF=8 and MT=457
   //

   // spontaneous radioactive decay data (MT=457)
   //
   SetHead(new TNuCont(src, "ZA, AWR, LIS, LISO, NST, NSP/HEAD"));
   Int_t NST = GetN1();
   Int_t NSP = GetN2();
   if (NST == 0) {
      AddToHead(new TNuList(src,
         "T12, +-, 0, 0, 2*NC, 0; Ex, +-"));
      AddToHead(new TNuList(src,
         "SPI, PAR, 0, 0, 6*NDK, NDK"
         "; RTYP, RFS, Q, +-, BR, +-"));
      for (Int_t n=0; n < NSP; n++) {
         TNuSFYSub* sub = new TNuSFYSub();
         sub->ImportEndfData(src);
         Add(sub);
      }
   }
   else if (NST == 1) {
      AddToHead(new TNuList(src,
         "0.0, 0.0, 0, 0, 6, 0"
         "; 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"));
      AddToHead(new TNuList(src,
         "SPI, PAR, 0, 0, 6, 0"
         "; 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"));
   }
   return;
}


//______________________________________________________________________________
void TNuSec08457::ShowData() const
{
   // Display the contents of this section (MT=457)

   static const struct {
      Int_t index;
      const Char_t* symbol;
      Int_t DeltaZ;
      Int_t DeltaA;
      const Char_t* description;
   } kDecayModes[] = {
      {0, "#gamma",    0,  0, "gamma-ray (not used in MT457)"},
      {1, "#beta^{-}", 1,  0, "Beta decay"},
      {2, "EC",       -1,  0, "e.c., beta+ Electron capture and/or positron emission"},
      {3, "IT",        0,  0,  "Isomeric transition"},
      {4, "#alpha",   -2, -4, "Alpha decay"},
      {5, "n",         0, -1, "Neutron emission (not delayed neutron decay)"},
      {6, "SF",        0,  0, "Spontaneous fission"},
      {7, "p",        -1, -1, "Proton emission"},
      {8, "?8",        0,  0, "Unregistered"},
      {9, "?9",        0,  0, "Unregistered"},
      {10, "?",        0,  0, "Unknown origin"}
   };

   static const struct {
      const Char_t* symbol;
      const Char_t* description;
   } kDecayEnergies[] = {
      {"E_{LP}",     "Average energy of all light particles."},
      {"E_{EM}",     "Average energy of all electromagnetic radiation."},
      {"E_{HP}",     "Average energy of all heavy particles."},
      {"E_{#beta-}", "Average beta- energy."},
      {"E_{#beta+}", "Average beta+ energy."},
      {"E_{Ae-}",    "Average Auger-electron energy."},
      {"E_{ce-}",    "Average conversion-electron energy."},
      {"E_{#gamma}", "Average gamma-ray energy."},
      {"E_{X-ray}",  "Average X-ray energy."},
      {"E_{inB}",    "Average internal Bremsstrahlung energy."},
      {"E_{annih.rad.}", "Average annihilation energy."},
      {"E_{#alpha}", "Average alpha energy."},
      {"E_{recoil}", "Average recoil energy."},
      {"E_{SF}",     "Average SF energy."},
      {"E_{n}",      "Average prompt and/or delayed neutron energy."},
      {"E_{p}",      "Average proton energy."},
      {"E_{#nu}",    "Average neutrino or antineutrino energy."}
   };

   const Double_t kMeV = 1.e6;

   cout << endl;
   cout << TNuMat::GetDefaultMatName(10*GetZA()+GetLISO());
   //const Char_t* j= (GetTwoSpin()%2==1) ? Form("%d/2", GetTwoSpin()) :
   //                                       Form("%d", GetTwoSpin()/2) ;
   //if (GetTwoSpin()==-1) j = "?";
   //cout << Form(" (J^{#pi} = %s^{%c})", j, (GetParity()==1) ? '+' : '-');
   cout << Form(", Spin = %5.1f, Parity = %s : ", GetSPI(), (GetParity()==1) ? "+1" : "-1");
   cout << endl;

   cout << Form("Atomic mass = %f u = %d m_H + %d m_n - (%12.5f MeV)",
      GetA() + GetMassExcess(), GetZ(), GetN(), GetBindingEnergy()/kMeV);
   cout << endl;

   const Char_t* t12 = (IsStable()) ? "Stable " :
      Form("T_{1/2} = %e #pm %e s", GetT12(), GetDeltaT12());
   cout << t12 << endl;
   if (IsStable()) return;

   cout << "Everage decay energies [MeV]" << endl;
   for (Int_t c=0; c < GetNC(); c++) {
      Double_t* ex = GetExTable() + 2*c;
      cout << Form("%12s : %11.6f #pm %11.6f MeV ; %s\n",
         kDecayEnergies[c].symbol, ex[0]/kMeV, ex[1]/kMeV,
         kDecayEnergies[c].description);
   }

   if (GetNDK()) cout << "Decay modes" << endl;
   //const Char_t* parent = TNuMat::GetDefaultMatName(10*GetZA()+GetLISO(), "-");

   for (Int_t ndk = 0; ndk < GetNDK(); ndk++) {
      Double_t* data = GetListAt2()->GetData() + 6*ndk;
      Double_t rtyp = data[0];
      //cout << "rtyp= " << data[0] << endl;
      TString mode;
      Bool_t isX = kFALSE;
      Int_t z= GetZ(), a=GetA();
      //for (; mode[0]==0 || rtyp > 0.01 ;) {
      cout << Form("%3d. %s (", ndk+1, TNuMat::GetDefaultMatName(10*GetZA()+GetLISO(), "-"));
      for (Int_t i=0; i==0 || rtyp > 0.01 ; i++) {
         const Double_t eps = 0.5e-10;
         Int_t r = (Int_t) (rtyp + eps);
         //mode = mode.Append(Form(",%s", kDecayModes[r].symbol));
         //mode = Form("%s,%s", mode.Data(), kDecayModes[r].symbol);
         cout << Form(", %s", kDecayModes[r].symbol);
         z += kDecayModes[r].DeltaZ;
         a += kDecayModes[r].DeltaA;

         if (r == 6 || r >= 8) isX = kTRUE;
         rtyp = 10* (rtyp - r);
         //cout << endl << "z=" << z << " a=" << a << " RFS=" <<  GetRFS(ndk) << " r =" << r << " mode=" << mode << endl;
        //cout << isX ? "" : TNuMat::GetDefaultMatName(10*(1000*z + a)+GetRFS(ndk), "Latex") << endl;
      }
      cout << ") ";
      const Char_t* daughter = (isX) ? "" : TNuMat::GetDefaultMatName(10*(1000*z + a)+GetRFS(ndk), "-");
      cout << daughter;
      //cout << Form("%3d. %s (%s) %s ", ndk+1, parent, mode.Data(), daughter);
      cout << Form(", BR = %f #pm %f ", GetBR(ndk), GetDeltaBR(ndk));
      cout << Form(", Q = %f #pm %f MeV",  GetQ(ndk)/kMeV, GetDeltaQ(ndk)/kMeV);
      cout << endl;
   }
   cout << endl <<endl;
}


///////////////////////////////////////////////////////////////////////////////
//
// TNuSFYSub - subsection of TNuSec08457, data for spontaneous fission products
//
/*
HeadAt(0) = a TNuList for
  "0.0, STYP, LCON, 0, 6, NER; FD, +-, ER_AV, +-, FC, +-");

  STYP : Decay radiation type
     0. gamma Gamma rays
     1. beta- Beta rays
     2. e.c. beta+ Electron capture and/or positron emission
     4. alpha Alpha particles
     5. n Neutrons
     6. SF Spontaneous fission fragments
     7. p Protons
     8. e- Discrete electrons
     9. x X-rays and annihilation radiation (photons not arising as transitions
between nuclear states)

  NER  :Total number of tabulated discrete energies for a given spectral type (STYP).
  FD   : Discrete spectrum normalization factor (absolute intensity/relative intensity).
  FC   : Continuum spectrum normalization factor (absolute intensity/relative intensity).
  ERAV : Average decay energy of radiation produced.
  LCON : Continuum spectrum flag
     LCON=0, no continuous spectrum given
     LCON=1, only continuous spectrum given
     LCON=2, both discrete and continuum spectra.

BodyAt(n) = a TNuList for
  "ER, +-, 0, 0, NT, 0; RTYP, TYPE, RI, +-, RIS, +-",
      (Abs(STYP) < 0.1) ? ", RICC, +-, RICK, +-, RICL, +-" : "");
  n = [0, NER)

  ER discrete energy (eV) of radiation produced
  NT Number of entries given for each discrete energy (ER).
  RI intensity of discrete radiation produced (relative units).
  RIS Internal pair formation coefficient (STYP=0.0)
     STYP=2.0, positron intensity,
     STYP=0.0 otherwise.
  RICC Total internal conversion coefficient (STYP=0.0 only)
  RICK K-shell internal conversion coefficient (STYP=0.0 only)
  RICL L-shell internal conversion coefficient (STYP=0.0 only)

TailAt(0) = optional (if LCON>0) TNuTab1 for
   "RTYP, 0.0, 0, LCOV, NR, NP/ Eint / RP(E)");

   LCOV Flag if covariance data are given for continuum spectrum data.
      LCOV=0, no covariance data given.
      LCOV=1, covariance data given.

TailAt(1) = optional (if LCON > 0 && LCOV >0) TNuList for
          "0.0, 0.0, 0, LB, 2*NPP, NPP/ (Ek,Fk)"));
   LB Flag indicating the meaning of the numbers given in the array {Ek,Fk}.
   (Only LB=2 presently allowed, See chapter 33).
*/
//
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuSFYSub)

//______________________________________________________________________________
void TNuSFYSub::ImportEndfData(TNuEndfIO& src)
{
   // Import the subsection of MF=8 and MT=457
   //

   // spontaneous radioactive decay data (MT=457)
   //
   //TNuRecs* recs = new TNuRecs();
   SetHead(new TNuList(src,
      "0.0, STYP, LCON, 0, 6, NER"
      "; FD, +-, ER_AV, +-, FC, +-"));
   Double_t STYP = GetC2();
   Int_t LCON = GetL1();
   Int_t NER = GetN2();
   for (Int_t j=0; j < NER; j++) {
      TString label = Form("%s%s",
         "ER, +-, 0, 0, NT, 0; RTYP, TYPE, RI, +-, RIS, +-",
         (TMath::Abs(STYP) < 0.1) ? ", RICC, +-, RICK, +-, RICL, +-" : "");
      Add(new TNuList(src, label));
   }
   if (LCON != 0) {
      TNuTab1 *tab1 = new TNuTab1(src,
         "RTYP, 0.0, 0, LCOV, NR, NP/ Eint / RP(E)");
      AddToTail(tab1);
      Int_t LCOV = tab1->GetL2();
      if (LCOV != 0)
         AddToTail(new TNuList(src,
         "0.0, 0.0, 0, LB, 2*NPP, NPP/ (Ek,Fk)"));
   }
}


//______________________________________________________________________________
void TNuSFYSub::ShowData() const
{
   // Display the contents of this section (MT=457)
   //
}

