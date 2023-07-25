// TNuSection.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSection (default class for a section data)                      //
//                                                                    //
// TNuSection.cxx:                                                    //
// Routine to handle a ENDF Section                                   //
/*


[Plan for renaming section class names]

I am planning to change the names of sections from TNuSecMFT to TNuSecXXX
by imposing
typedef TNuSecXXX TNuSecMFT

Here, MFT means the 1000*MF + MT, and XXX is more sensible names listed below.

Class names for each MF and MT
------------------------------------------------------
     MFT TNuSecXXX
------------------------------------------------------
   01    TNuSecNeutronYield //(MT=452 for total, 455 for delayed, 456 for prompt)
   01451 TNuSecDescription
   01458 TNuSecFissionEnergyRelease
   01460 TNuSecDelayedPhoton
   02    TNuSecResonance //Resonance parameter data
   03    TNuSecXn //Reaction cross sections
   04    TNuSecDMu //Angular distributions for emitted particles
   05    TNuSecDEp // Energy distributions for emitted particles
   06    TNuSecDEpDMu //Energy-angle distributions for emitted particles
   07002 TNuSecThermalElastic // Thermal elastic neutron scattering law data
   07004 TNuSecThermalInelastic // Thermal inelastic neutron scattering law data
   08000 TNuSecDecay
   08454 TNuSecFissionYield //Radioactivity and fission-product yield data (for independent)
   08459 TNuSecFissionYield //Radioactivity and fission-product yield data (for cumulative)
   08457 TNuSecSpontaneousDecay
   09    TNuSecMultiplicityRN //Multiplicities for radioactive nuclide production
   10    TNuSecXnRN //Cross sections for radioactive nuclide production
   12    TNuSecMultiplicityPhoton //Multiplicities for photon production
   13    TNuSecXnPhoton //Cross sections for photon production
   14    TNuSecDMuPhoton // Angular distributions for photon production
   15    TNuSecDEpPhoton //Energy distributions for photon production
   23    TNuSecXnSmoothPhoton // Photo- or electro-atomic interaction cross sections
   26    TNuSecDEpDMuElectro //Electro-atomic angle and energy distribution
   27    TNuSecAtomicFormFactor //Atomic form factors or scattering functions for photo-atomic interactions
   28    TNuSecAtomicRelaxation //Atomic relaxation data
   30    TNuSecCov //Data covariances obtained from parameter covariances and sensitivities
   30001 TNuSecCovDir//Data covariances directory
   30002 TNuSecCovMatrix//Data covariances matrix
   31    TNuSecCovNu //Data covariances for nu(bar)
   32    TNuSecCovResonance //Data covariances for resonance parameters
   33    TNuSecCovXn //Data covariances for reaction cross sections
   34    TNuSecCovDMu //Data covariances for angular distributions
   35    TNuSecCovDEp //Data covariances for energy distributions
   39    TNuSecCovYieldRN //Data covariances for radionuclide production yields
   40    TNuSecCovXnRN //Data covariances for radionuclide production cross sections

*/
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"

#include "TROOT.h"
#include "TString.h"

#include "TNudy.h"
#include "TNuEndfIO.h"
#include "TNuFile.h"

#include "TNuSec01.h"
#include "TNuSec01451.h"
#include "TNuSec01458.h"
#include "TNuSec01460.h"

#include "TNuSec02.h"

#include "TNuSec03.h"

#include "TNuSec04.h"

#include "TNuSec05.h"

#include "TNuSec06.h"

#include "TNuSec07002.h"
#include "TNuSec07002Coherent.h"
#include "TNuSec07002Incoherent.h"
#include "TNuSec07004.h"

#include "TNuSec08.h"
#include "TNuSec08454.h"
#include "TNuSec08457.h"

#include "TNuSec09.h"
#include "TNuSec10.h"
#include "TNuSec12.h"
#include "TNuSec12Yields.h"
#include "TNuSec12Transitions.h"
#include "TNuSec13.h"
#include "TNuSec14.h"
#include "TNuSec15.h"
#include "TNuSec23.h"
#include "TNuSec26.h"
#include "TNuSec27.h"
#include "TNuSec28.h"
#include "TNuCov.h"
#include "TNuMat.h"
#include "TNuSublib.h"

#include "TNuTab1.h"
#include "TNuTab2.h"
#include "TNuIntg.h"
#include "TNuList.h"

#include "TNuPrinter.h"

#include "TNuMath.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuSection)

//______________________________________________________________________________
TNuSection::TNuSection() : TNuRecs(), fMAT(0), fMF(0), fMT(0)
{
   // TNuSection ctor
}


//______________________________________________________________________________
TNuSection::TNuSection(Int_t mat, Int_t mf, Int_t mt)
: TNuRecs(), fMAT(mat), fMF(mf), fMT(mt)
{
   // TNuSection ctor
}

//______________________________________________________________________________
TNuSection::~TNuSection()
{
   // TNuSection dtor
}


//______________________________________________________________________________
Double_t TNuSection::GetMassExcess() const
{
   // mass excess in AMU
   return TNuMath::GetMassExcess(GetA(), GetAWR());
}

//______________________________________________________________________________
Double_t TNuSection::GetBindingEnergy() const
{
   // (N*m_n + Z*m_p - m)*c^2 in eV
   return TNuMath::GetBindingEnergy(GetZ(), GetA(), GetAWR());
}

//______________________________________________________________________________
void TNuSection::What() const
{
   TNuObject::What();
   cout << "Params" << endl;
   cout << "\tMAT    = " << GetMAT()    << " : Material identifier, 100*Z + I" << endl;
   cout << "\tMF     = " << GetMF()     << " : File identifier" << endl;
   cout << "\tMT     = " << GetMT()     << " : Section (reaction) identifier" << endl;
   cout << "\tZA     = " << GetZA()     << " : 1000*Z + A" << endl;
   cout << "\tAWR    = " << GetAWR()    << " : Ratio of mass of the material to that of the neutron" << endl;
}

//______________________________________________________________________________
void TNuSection::ls(Option_t* option) const
{
   //cout << Form("(%s) %s at %x: ",TObject::GetName(), GetName(), this);
   //cout << " / " << GetTitle() << endl;
   std::cout << std::endl;

   //cout << "Table of records" << endl;
   this->TNuRecs::ls(option);
}

//______________________________________________________________________________
void TNuSection::Print(Option_t *opt) const
{
   // print a section data

   TNuRecs::Print(opt);
   TNudy::GetPrinter().PrintEND(fMAT, fMF, 0, 99999, "SEND");
}

//______________________________________________________________________________
const Char_t* TNuSection::GetDefSymbol(Int_t mt)
{
   // returns symbol and title corresponding to MT value
   const Char_t* symbol;
   const Char_t* title;
   GetDefSymbolTitle(mt, symbol, title);
   return symbol;
}

//______________________________________________________________________________
const Char_t* TNuSection::GetDefTitle(Int_t mt)
{
   // returns symbol and title corresponding to MT value
   const Char_t* symbol;
   const Char_t* title;
   GetDefSymbolTitle(mt, symbol, title);
   return title;
}

//______________________________________________________________________________
const Char_t* TNuSection::GetChannelSymbol() const
{
   // returns (n,p), (n,2np), etc

   const Char_t* symbol;
   const Char_t* title;
   GetDefSymbolTitle(fMT, symbol, title);

   if (strstr(symbol, "(z,") == symbol) {
      // if it begins with (z,
      const Char_t *proj_name = TNuSublib::GetShortName(GetParentMat()->GetNSUB());
      TString s = TString(symbol);
      if (*proj_name) {
         // E.g., (z,z_0) -> (n,n_0) or (p,p_0) and so on 
         s.ReplaceAll("(z", Form("(%s",proj_name));
         s.ReplaceAll(",z", Form(",%s",proj_name));
         return Form("%s", s.Data());
      }
   }
   return symbol;
}

//______________________________________________________________________________
const Char_t*  TNuSection::GetFigTitle() const
{
   // returns the title of its figures 
   
   TNuMat *mat = GetParentMat();
   const Char_t *target_name = mat->GetDefaultName("Latex");
   const Char_t *channel_name = GetChannelSymbol();

   return Form("%s of %s%s. MT=%d. %s",
      GetSymbol(),
      target_name,
      channel_name,
      GetMT(),
      GetDefTitle(fMT));
}

//______________________________________________________________________________
void TNuSection::GetDefSymbolTitle(Int_t mt, const Char_t*& symbol, const Char_t*& title)
{
   // returns symbol and title corresponding to MT value

   static const struct {
      Int_t         MT;
      const TString Symbol;
      const TString Description;
   } kSecDescriptions[] = {
   {1, "(n,total)", "Neutron total cross sections."},
   {2, "(z,z_{0})", "Elastic scattering cross section for incident particles."},
   {3, "(z,nonelas.)", "Nonelastic neutron cross section."},
   {4, "(z,n)", "Production of one neutron in the exit channel. Sum of the MT=50-91."},
   {5, "(z,anything)", "Sum of all reactions not given explicitly in another MT number. This is a partial reaction to be added to obtain MT=1."},
   {10, "(z,contin.)", "Total continuum reaction; includes all continuum reactions and excludes all discrete reactions."},
   {11, "(z,2nd)", "Production of two neutrons and a deuteron, plus a residual."},
   {16, "(z,2n)", "Production of two neutrons and a residual. Sum of MT=875-891, if present."},
   {17, "(z,3n)", "Production of three neutrons and a residual."},
   {18, "(z,fission)", "Particle-induced fission (sum of MT 19, 20, 21 and 38, if present)."},
   {19, "(n,f)", "First-chance neutron-induced fission."},
   {20, "(n,nf)", "Second-chance neutron-induced fission."},
   {21, "(n,2nf)", "Third-chance neutron-induced fission."},
   {22, "(z,n#alpha)", "Production of a neutron and an alpha particle, plus a residual."},
   {23, "(n,n3#alpha)", "Production of a neutron and three alpha particles, plus a residual."},
   {24, "(z,2n#alpha)", "Production of two neutrons and an alpha particle, plus a residual."},
   {25, "(z,3n#alpha)", "Production of three neutrons and an alpha particle, plus a residual."},
   {27, "(n,abs)", "Absorption; sum of MT=18 and MT=102 through MT=117"},
   {28, "(z,np)", "Production of a neutron and a proton, plus a residual."},
   {29, "(z,n2#alpha)", "Production of a neutron and two alpha particles, plus a residual."},
   {30, "(z,2n2#alpha)", "Production of two neutrons and two alpha particles, plus a residual."},
   {32, "(z,nd)", "Production of a neutron and a deuteron, plus a residual."},
   {33, "(z,nt)", "Production of a neutron and a triton, plus a residual."},
   {34, "(z,n^3He)", "Production of a neutron and a ^3He particle, plus a residual."},
   {35, "(z,nd2#alpha)", "Production of a neutron, a deuteron, and 2 alpha particles, plus a residual."},
   {36, "(z,nt2#alpha)", "Production of a neutron, a triton, and 2 alpha particles, plus a residual."},
   {37, "(z,4n)", "Production of 4 neutrons, plus a residual."},
   {38, "(n,3nf)", "Fourth-chance fission cross section."},
   {41, "(z,2np)", "Production of 2 neutrons and a proton, plus a residual."},
   {42, "(z,3np)", "Production of 3 neutrons and a proton,plus a residual."},
   {44, "(z,n2p)", "Production of a neutron and 2 protons, plus a residual."},
   {45, "(z,np#alpha)", "Production of a neutron, a proton, and an alpha particle, plus a residual."},
//
   {101, "(n,disap)", "Neutron disappearance; equal to sum of MT=102-117."},
   {102, "(z,#gamma)", "Radiative capture."},
   {103, "(z,p)", "Production of a proton, plus a residual. Sum of MT=600-649, if present."},
   {104, "(z,d)", "Production of a deuteron, plus a residual. Sum of MT=650-699, if present."},
   {105, "(z,t)", "Production of a triton, plus a residual. Sum of MT=700-749, if present."},
   {106, "(z,^3He)", "Production of a ^3He particle plus a residual. Sum of MT=750-799, if present."},
   {107, "(z,#alpha)", "Production of an alpha particle, plus a residual. Sum of MT=800-849, if present."},
   {108, "(z,2#alpha)", "Production of 2 alpha particles, plus a residual."},
   {109, "(z,3#alpha)", "Production of 3 alpha particles, plus a residual."},
   {111, "(z,2p)", "Production of 2 protons, plus a residual."},
   {112, "(z,p#alpha)", "Production a proton and an alpha particle, plus a residual."},
   {113, "(z,t2#alpha)", "Production of a triton and 2 alpha particles, plus a residual."},
   {114, "(z,d2#alpha)", "Production of a deuteron and 2 alpha particles, plus a residual."},
   {115, "(z,pd)", "Production of proton and a deuteron, plus a residual."},
   {116, "(z,pt)", "Production of proton and a triton, plus a residual."},
   {117, "(z,d#alpha)", "Production of deuteron and an alpha particle, plus a residual."},
   {151, "(n,RES)", "Resonance parameters that can be used to calculate cross sections at different temperatures in the resolved and unresolved energy regions."},
   {201, "(z,Xn)", "Total neutron production."},
   {202, "(z,X#gamma)", "Total gamma production."},
   {203, "(z,Xp)", "Total proton production."},
   {204, "(z,Xd)", "Total deuteron production."},
   {205, "(z,Xt)", "Total triton production."},
   {206, "(z,X^3He)", "Total ^3He production."},
   {207, "(z,X#alpha)", "Total alpha particle production."},
   {208, "(z,X#pi^{+})", "Total #pi^{+} production."},
   {209, "(z,X#pi^{0})", "Total #pi^{0} production."},
   {210, "(z,X#pi^{-})", "Total #pi^{-} production."},
   {211, "(z,X#mu^{+})", "Total #mu^{+} production."},
   {212, "(z,X#mu^{-})", "Total #mu^{-} production."},
   {213, "(z,X#kappa^{+})", "Total #kappa^{+} production."},
   {214, "(z,X#kappa^{0}_{long})", "Total #kappa^{0}_{long} production."},
   {215, "(z,X#kappa^{0}_{short})", "Total #kappa^{0}_{short} production."},
   {216, "(z,X#kappa^{-})", "Total #kappa^{-} production."},
   {217, "(z,X#bar{p})", "Total anti-proton production."},
   {218, "(z,X#bar{n})", "Total anti-neutron production."},
   {251, "#mu", "Average cosine of the scattering angle (laboratory system) for elastic scattering of neutrons."},
   {252, "#xi", "Average logarithmic energy decrement for elastic scattering of neutrons."},
   {253, "#gamma", "Average of the square of the logarithmic energy decrement divided by twice the average logarithmic energy decrement, for elastic scattering of neutrons."},
//
   {451, "", "Heading or title information; given in File 1 only."},
   {452, "#nu_{T}", "Average total (prompt plus delayed) number of neutrons released per fission event."},
   {454, "", "Independent fission product yield data."},
   {455, "#nu_{d}", "Average number of delayed neutrons released per fission event."},
   {456, "#nu_{p}", "Average number of prompt neutrons released per fission event."},
   {457, "", "Radioactive decay data."},
   {458, "", "Energy release in fission for incident neutrons."},
   {459, "", "Cumulative fission product yield data."},
   {500, "", "Total charged-particle stopping power."},
   {501, "", "Total photon interaction."},
   {502, "", "Photon coherent scattering."},
   {504, "", "Photon incoherent scattering."},
   {505, "", "Imaginary scattering factor."},
   {506, "", "Real scattering factor."},
   {515, "", "Pair production, electron field."},
   {516, "", "Pair production; sum of MT=515, 517."},
   {517, "", "Pair production, nuclear field."},
   {522, "", "Photoelectric absorption."},
   {523, "", "Photo-excitation cross section."},
   {526, "", "Electro-atomic scattering."},
   {527, "", "Electro-atomic bremsstrahlung."},
   {528, "", "Electro-atomic excitation cross section."},
   {533, "", "Atomic relaxation data."},
   {534, "K", "(1s1/2) subshell photoelectric or electroatomic cross section."},
   {535, "L1", "(2s1/2) subshell photoelectric or elctroatomic cross section."},
   {536, "L2", "(2p1/2) subshell photoelectric or elctroatomic cross section."},
   {537, "L3", "(2p3/2) subshell photoelectric or elctroatomic cross section."},
   {538, "M1", "(3s1/2) subshell photoelectric or elctroatomic cross section."},
   {539, "M2", "(3p1/2) subshell photoelectric or elctroatomic cross section."},
   {540, "M3", "(3p3/2) subshell photoelectric or elctroatomic cross section."},
   {541, "M4", "(3d3/2) subshell photoelectric or elctroatomic cross section."},
   {542, "M5", "(3d5/2) subshell photoelectric or elctroatomic cross section."},
   {543, "N1", "(4s1/2) subshell photoelectric or elctroatomic cross section."},
   {544, "N2", "(4p1/2) subshell photoelectric or elctroatomic cross section."},
   {545, "N3", "(4p3/2) subshell photoelectric or elctroatomic cross section."},
   {546, "N4", "(4d3/2) subshell photoelectric or elctroatomic cross section."},
   {547, "N5", "(4d5/2) subshell photoelectric or elctroatomic cross section."},
   {548, "N6", "(4f5/2) subshell photoelectric or elctroatomic cross section."},
   {549, "N7", "(4f7/2) subshell photoelectric or elctroatomic cross section."},
   {550, "O1", "(5s1/2) subshell photoelectric or elctroatomic cross section."},
   {551, "O2", "(5p1/2) subshell photoelectric or elctroatomic cross section."},
   {552, "O3", "(5p3/2) subshell photoelectric or elctroatomic cross section."},
   {553, "O4", "(5d3/2) subshell photoelectric or elctroatomic cross section."},
   {554, "O5", "(5d5/2) subshell photoelectric or elctroatomic cross section."},
   {555, "O6", "(5f5/2) subshell photoelectric or elctroatomic cross section."},
   {556, "O7", "(5f7/2) subshell photoelectric or elctroatomic cross section."},
   {557, "O8", "(5g7/2) subshell photoelectric or elctroatomic cross section."},
   {558, "O9", "(5g9/2) subshell photoelectric or elctroatomic cross section."},
   {559, "P1", "(6s1/2) subshell photoelectric or elctroatomic cross section."},
   {560, "P2", "(6p1/2) subshell photoelectric or elctroatomic cross section."},
   {561, "P3", "(6p3/2) subshell photoelectric or elctroatomic cross section."},
   {562, "P4", "(6d3/2) subshell photoelectric or elctroatomic cross section."},
   {563, "P5", "(6d5/2) subshell photoelectric or elctroatomic cross section."},
   {564, "P6", "(6f5/2) subshell photoelectric or elctroatomic cross section."},
   {565, "P7", "(6f7/2) subshell photoelectric or elctroatomic cross section."},
   {566, "P8", "(6g7/2) subshell photoelectric or elctroatomic cross section."},
   {567, "P9", "(6g9/2) subshell photoelectric or elctroatomic cross section."},
   {568, "P10", "(6h9/2) subshell photoelectric or elctroatomic cross section."},
   {569, "P11", "(6h11/2) subshell photoelectric or elctroatomic cross section."},
   {570, "Q1", "(7s1/2) subshell photoelectric or elctroatomic cross section."},
   {571, "Q2", "(7p1/2) subshell photoelectric or elctroatomic cross section."},
   {572, "Q3", "(7p3/2) subshell photoelectric or elctroatomic cross section."},
//
   {  0, "", ""}
};

 static const struct {
      Int_t         MT1;
      Int_t         MT2;
      const TString Symbol;
      const TString Description;
   } kSecDescriptions2[] = {
      {50, 91, "(z,n", "Production of a neutron"},
      {600, 649, "(z,p", "Production of a proton"},
      {650, 699, "(z,d", "Production of a deuteron"},
      {700, 749, "(z,t", "Production of a triton"},
      {750, 799, "(n,^3He", "Production of a ^3He"},
      {800, 849, "(z,#alpha", "Production of an alpha particle"},
      {875, 891, "(z,2n", "Production of 2 neutrons"},
      {0, 0, "", ""}
   };

   Int_t m = 0;
   for (Int_t k = 0; (m = kSecDescriptions[k].MT) > 0; k++)
      if (m == mt) {
         symbol = kSecDescriptions[k].Symbol.Data();
         title  = kSecDescriptions[k].Description.Data();
         //return Form("%s %s", symbol, title);
         return;
      }

   Int_t m1= 0, m2=0;
   for (Int_t k = 0; (m1 = kSecDescriptions2[k].MT1) > 0 ; k++) {
      m2 = kSecDescriptions2[k].MT2;
      if (mt >= m1 && mt <= m2) {
         m = mt - m1;
         symbol = Form("%s_{%s})", kSecDescriptions2[k].Symbol.Data(), mt == m2 ? "c" : Form("%d", m));
         TString tail;
         if (m == 0)
            tail = " leaving the residual nucleus in the ground state.";
         else if (m == 1)
            tail = ", with residual in the 1st excited state.";
         else if (m == 2)
            tail = ", with residual in the 2nd excited state.";
         else if (m == 3)
            tail = ", with residual in the 3rd excited state.";
         else if (mt < m2)
            tail = Form(", with residual in the %dth excited state.", m);
         else
            tail = Form(" in the continuum not included in MT=%d-%d.", m1, m2-1);
         title  = Form("%s%s", kSecDescriptions2[k].Description.Data(), tail.Data());
         //return Form("%s %s", symbol, title);
         return;
      }
   }

   if (mt >= 851 && mt <= 870) {
      symbol="";
      title ="Lumped reaction covariances.";
      //return Form("%s %s", symbol, title);
      return;
   }

   if (mt >= 301 && mt <= 450) {
      symbol= "";
      title = "Energy release parameters, for total and partial cross sections; MT= 300 plus the reaction MT number, e.g., MT=302 is the elastic scattering kerma.";
      //return Form("%s %s", symbol, title);
      return;
   }

   symbol= "";
   title=  "Unrecognized MT value";
   //return Form("%s %s", symbol, title);
   return;
}

//______________________________________________________________________________
inline const Char_t* TNuSection::GetSymbol() const
{
   return GetParentMat()->GetSymbol();
}

//______________________________________________________________________________
TNuSection* TNuSection::CreateSection(TNuEndfIO& src, TNuFile *pFile, Int_t mf, Int_t mt)
{
   // Static function which creates TNuSection corresponding to mf and mt,
   // and call appropriate import routine for the section data

   TNuSection *pSec = 0;

   Int_t mat = src.GetMAT();
   if (mf ==1) {
      if (mt == 451)
         pSec = new TNuSec01451(mat,mf,mt);
      else if (mt == 458)
         pSec = new TNuSec01458(mat,mf,mt);
      else if (mt == 460)
         pSec = new TNuSec01460(mat,mf,mt);
      else
         pSec = new TNuSec01(mat,mf,mt);
   }
   else if (mf==2) {
      pSec = new TNuSec02(mat,mf,mt);
   }
   else if (mf == 3) {
      pSec = new TNuSec03(mat,mf,mt);
   }
   else if (mf == 4) {
      pSec = new TNuSec04(mat,mf,mt);
   }
   else if (mf == 5) {
      pSec = new TNuSec05(mat,mf,mt);
   }
   else if (mf == 6) {
      pSec = new TNuSec06(mat,mf,mt);
   }
   else if (mf == 7) {
      if (mt == 2) {
         Int_t vLTHR = src.GetL1();
         if (vLTHR==1) {
            pSec = new TNuSec07002Coherent(mat,mf,mt);
         } else {
            pSec = new TNuSec07002Incoherent(mat,mf,mt);
         }
      }
      else if (mt == 4)
         pSec = new TNuSec07004(mat,mf,mt);
      else
         fprintf(stderr, "CreateSection: "
           "Unsupported value of MT=%d for MAT=%d and MF=%d\n",
           mt, mat, mf);
   }
   else if (mf == 8) {
      if (mt == 454 || mt == 459)
         pSec = new TNuSec08454(mat,mf,mt);
      else if (mt == 457)
         pSec = new TNuSec08457(mat,mf,mt);
      else
         pSec = new TNuSec08(mat,mf,mt);
   }
   else if (mf == 9) {
      pSec = new TNuSec09(mat,mf,mt);
   }
   else if (mf == 10) {
      pSec = new TNuSec10(mat,mf,mt);
   }
   else if (mf == 12) {
      Int_t vLO = src.GetL1();
      if (vLO==1)
         pSec = new TNuSec12Yields(mat,mf,mt);
      else if (vLO==2)
         pSec = new TNuSec12Transitions(mat,mf,mt);
      else {
         fprintf(stderr, "CreateSection: Unsupported value of LO=%d, for MAT=%d,  MF=%d, MF=%d\n", vLO, mat, mf, mt);
         pSec = new TNuSec12(mat,mf,mt);
      }
   }
   else if (mf == 13) {
      pSec = new TNuSec13(mat,mf,mt);
   }
   else if (mf == 14) {
      pSec = new TNuSec14(mat,mf,mt);
   }
   else if (mf == 15) {
      pSec = new TNuSec15(mat,mf,mt);
   }
   else if (mf == 23) {
      pSec = new TNuSec23(mat,mf,mt);
   }
   else if (mf == 26) {
      pSec = new TNuSec26(mat,mf,mt);
   }
   else if (mf == 27) {
      pSec = new TNuSec27(mat,mf,mt);
   }
   else if (mf == 28) {
      pSec = new TNuSec28(mat,mf,mt);
   }
   else if (mf == 31) {
      pSec = new TNuSec31(mat,mf,mt);
   }
   else if (mf == 32) {
      pSec = new TNuSec32(mat,mf,mt);
   }
   else if (mf == 33) {
      pSec = new TNuSec33(mat,mf,mt);
   }
   else if (mf == 34) {
      pSec = new TNuSec34(mat,mf,mt);
   }
   else if (mf == 35) {
      pSec = new TNuSec35(mat,mf,mt);
   }
   else if (mf == 40) {
      pSec = new TNuSec40(mat,mf,mt);
   }

   // default cases
   if (!pSec) {
         //Invoking default importing routine
      pSec = new TNuSection(mat,mf,mt);
   }
   pSec->SetParent(pFile);

   // initialize Name/Title/Label of the section
   TString symbol = TString(GetDefSymbol(mt));
   // remove the curly bracket marks
   symbol.ReplaceAll("{", "");
   symbol.ReplaceAll("}", "");
   if (!symbol.IsNull()) symbol.Prepend(":");
   pSec->SetName(Form("s_%02d%03d%s", mf, mt, symbol.Data()));
   pSec->SetLabel("");

   pSec->SetTitle (Form("MT=%d, %s %s", mt, GetDefSymbol(mt), GetDefTitle(mt)));

   // import the data
   pSec->ImportEndfData(src);

   if (!src.IsSEND()) {
      Long_t linenum = src.GetLineNum();
      fprintf(stderr,"Error in CreateSection for MAT=%d, MF=%d, MT=%d\n",
         mat, mf, mt);
      fprintf(stderr,"The following %ld-th line is\n", linenum);
      fprintf(stderr,"[%s]\n", src.GetLineData());
      fprintf(stderr,"is not SEND but %s\n", src.GuessRecType());
      src.GotoSEND();
      fprintf(stderr,"... skipped %ld lines to %ld\n",
         src.GetLineNum() - linenum, src.GetLineNum());
   }

   return pSec;
}

//______________________________________________________________________________
void TNuSection::ImportEndfData(TNuEndfIO& src)
{
   // Default routine for importing ENDF section data

   SetHead(new TNuCont(src, "ZA, AWR, L1,L2,N1,N2/HEAD"));

   while(!src.IsSEND())
   {

      TString type = src.GuessRecType();
      if (type == "CONT") {
         Add(new TNuCont(src));
      }
      else if (type == "TAB1") {
         Add(new TNuTab1(src));
      }
      else if (type == "TAB2") {
         Add(new TNuEndfTAB2(src));
      }
      else if (type == "LIST") {
         Add(new TNuList(src));
      }
      else if (type == "INTG") {
         Add(new TNuIntg(src));
      }
      else {
          Error("TNuSection::Import", "Record type [%s] is unknown", type.Data());
          //src.GotoSEND();
          return;
      }
   }
}


