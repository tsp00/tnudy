// TNuSec08457.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuSec08457
#define ROOT_TNuSec08457

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


#include "TNuSection.h"
#include "TNuList.h"
#include "TNuEndfIO.h"

#include "TNuRecs.h"
//class TNuSFYSub;
class TNuSec08457 : public TNuSection
{
public:
   TNuSec08457() {}
   TNuSec08457(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec08457();

   Int_t     GetLIS() const      { return GetL1(); }
   Int_t     GetLISO() const     { return GetL2(); }
   Int_t     GetNST() const      { return GetN1(); }  // 1 for stable, 0 for radioactive
   Bool_t    IsStable() const    { return GetNST()==1; }
   Int_t     GetNSP() const      { return GetN2(); } //Total number of radiation types (STYP) for which spectral information is given

   Double_t  GetT12() const      { return GetListAt1()->GetC1(); } //half-life of the original nuclide (seconds).
   Double_t  GetDeltaT12() const { return GetListAt1()->GetC2(); }
   Int_t     GetNC() const       { return GetListAt1()->GetN1()/2; } //Total number of decay energies (eV) given
   Double_t* GetExTable() const  { return GetListAt1()->GetData(); } // Average decay energy (eV) of radiation x

   Double_t  GetSPI() const      { return GetListAt2()->GetC1(); } // (double) spin (-77.777 for unknown)
   Int_t     GetTwoSpin() const  { return (GetSPI() < 0) ? -1 : (Int_t) (2*GetSPI() + 0.5); } // 2*spin (-1 for unknown)
   Double_t  GetPAR() const      { return GetListAt2()->GetC2(); } // (double) parity
   Int_t     GetParity() const   { return (Int_t) (GetPAR() + 0.5); } // parity (+/- 1)
   Int_t     GetNDK() const      { return GetListAt2()->GetN2(); } // Total number of decay modes given.

   Double_t  GetRTYP(Int_t n) const     { return GetListAt2()->At(6*n+0); } //Mode of decay of the nuclide in its LIS state
   Int_t     GetRFS(Int_t n) const      { return (Int_t) (GetListAt2()->At(6*n+1) + 0.5); } // (int) Isomeric state flag for daughter nuclide
   Double_t  GetQ(Int_t n) const        { return GetListAt2()->At(6*n+2); } // Total decay energy (eV) available in the corresponding decay process
   Double_t  GetDeltaQ(Int_t n) const   { return GetListAt2()->At(6*n+3); }
   Double_t  GetBR(Int_t n) const       { return GetListAt2()->At(6*n+4); } // Branching ratio
   Double_t  GetDeltaBR(Int_t n) const  { return GetListAt2()->At(6*n+5); }

   void          What() const; // *MENU*
   void          ShowData() const; // *MENU*

   void     ImportEndfData(TNuEndfIO& src);
private:
   TNuList*  GetListAt1() const { return (TNuList*) HeadAt(1); }
   TNuList*  GetListAt2() const { return (TNuList*) HeadAt(2); }

   ClassDef(TNuSec08457, 1) //spontaneous radioactive decay data (MT=457)
};


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
     8. e Discrete electrons
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

class TNuSFYSub : public TNuRecs
{
public:
   TNuSFYSub() : TNuRecs() {}
   virtual ~TNuSFYSub() {}

   Double_t GetSTYP() const { return GetC2(); }
   Int_t    GetLCON() const { return GetL1(); }
   Bool_t   HasContinuumSpectrum() { return GetLCON() != 0; }
   Bool_t   HasDiscreteSpectrum() { return GetLCON() == 2; }

   Int_t    GetNER() const {return GetN2(); }


   //void          What() const; // *MENU*
   void          ShowData() const; // *MENU*

   void     ImportEndfData(TNuEndfIO& src);
private:

   ClassDef(TNuSFYSub, 1) // Subsection of TNuSec08457, data for spontaneous fission products
};

#endif

