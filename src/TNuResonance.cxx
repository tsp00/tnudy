// TNuResonance.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

/////////////////////////////////////////////////////////////////////////////
//
// TNuResonance : public TNuRecsWithCont
//
//   = A specific representation of resonance parameters
//
// ------------------ head --------------------------------------------------
//
// HeadAt(0) = RangeCont() =
// [MAT, 2,151/  EL,  EH, LRU, LRF, NRO, NAPS]CONT (range)
//
// HeadAt(1) = GetAPE() =
// [MAT, 2,151/ 0.0, 0.0,   0,   0,  NR,   NP/AP(E) if NRO > 0
//
// HeadAt(2) = SpinCont() =
// [MAT, 2,151/ SPI, AP, 0, 0, NLS, 0]CONT
//
// ------------------ body --------------------------------------------------
//
// At(n) : n-th subsection (for a given L or J) of the resonance data
//
// ------------------ notes -------------------------------------------------
//
//
/////////////////////////////////////////////////////////////////////////////

#include "TNuResonance.h"

#include "TNuSec02.h"


//#include "TNuResoResolved.h"
//#include "TNuResoUnresolved.h"

#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2.h"
#include "TNuContLists.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TPad.h"

#include "TNuMath.h"

#include "TArrayD.h"

#include <iostream>
#include <iomanip>
using namespace std;
using namespace TMath;

ClassImp(TNuResonance)

//______________________________________________________________________________
Double_t TNuResonance::GetAPE(Double_t Ein) const
{
   TNuTab1 *tab1 = GetAPE();
   if (tab1) return tab1->Eval(Ein);
   else      return 0;
}


//______________________________________________________________________________
void TNuResonance::What() const
{
   TNuObject::What();

   if (RangeCont())    RangeCont()->What();
   if (GetAPE())      GetAPE()->What();
   if (SpinCont()) SpinCont()->What();
   //cout << "Params" << endl;
   cout << "   Entries = " << GetEntries() << endl;
}

//______________________________________________________________________________
void TNuResonance::ls(Option_t* option) const
{
   cout << Form("(%s) %s at %p: ",ClassName(), GetName(), this);
   cout << " / " << GetTitle() << endl;

   if (RangeCont())    RangeCont()->ls(option);
   if (GetAPE())      GetAPE()->ls(option);
   if (SpinCont()) SpinCont()->ls(option);

   //cout << "Table of records" << endl;
   for (Int_t n=0; n< GetSize(); n++) {
      TNuObject *obj = BodyAt(n);
      if (obj) {
         cout << endl;
         cout << setw(5) << n << ". ";
         obj->ls(option);
      }
   }
}

//______________________________________________________________________________
void TNuResonance::ImportEndfData(TNuEndfIO& src)
{
   // Default case (LRU = 0)
   //
   // head is already read
   //SetCont(new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range"));
   //if (GetNRO())
   //   Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));

   SetSpinCont(new TNuCont(src, "SPI, AP, 0, 0, NLS, 0"));
}

//______________________________________________________________________________
void TNuResonance::EvalRP(Double_t /*Ein*/, Double_t* /*sig*/) const
{
   // Evaluate resonance parameters
   // Ein : incident energy [in eV]
   // sig[4] : resonance contribution to ...
}

//______________________________________________________________________________
Double_t TNuResonance::GetRadius(Double_t Ein) const
{
   // Scattering radius for the evaluation of the shift and penetration factors

   Int_t NRO= GetNRO();
   Int_t NAPS = GetNAPS();

   if (NAPS ==0) {
      const Double_t c4 = 1.00866491578;
      Double_t a = 0.123 * Power(c4*GetAWRI(),1./3.) + 0.08; // Channel radius, in 10-12 cm.
      return a;
   }
   else if (NAPS==1 && NRO==1) {
      Double_t APE = GetAPE(Ein);
      return APE;
   }
   else {
      return GetAP();
   }
}

//______________________________________________________________________________
void TNuResonance::HardsphereFactors(Int_t L, Double_t k, Double_t Ein, Double_t *p, Double_t *s) const
{
   // returns the P_L (penetration factor) and S_L (shift factor)
   Double_t rho = k * GetRadius(Ein);
   TNuMath::HardsphereFactors(L, rho, p, s);
}

//______________________________________________________________________________
Double_t TNuResonance::Getpcm(Double_t Ein) const
{
   // Calculates the CM momentum p in 1/10^(-12) fm
   // for a given Lab energy Ein

   Double_t AWRI = GetAWRI();
   Double_t p1 = Sqrt(2*TNuMath::MassOfNeutron())*AWRI/(AWRI+1)/TNuMath::HbarEv10fm();
   return p1 * TMath::Sqrt(Ein);
}

//______________________________________________________________________________
Double_t TNuResonance::GetHardspherePhaseShift(Int_t L, Double_t Ein, Double_t p) const
{
   // Calculates the hard sphere phase shift phi_L,
   // for a given angular momentum L and Lab energy Ein (with p_CM = p)

   Double_t hat_radius = (GetNRO() == 0) ? GetAP() : GetAPE(Ein);
   return TNuMath::HardspherePhaseShift(L, p * hat_radius);
}

//______________________________________________________________________________
Int_t TNuResonance::GenerateMeshPoints(TArrayD& mesh) const
{
   // default mesh generator

   // Generates meshes for Ein
   using namespace TMath;

   // no need to meshing twice
   //if (IsMeshed()) return;

   // for the time being, try simplest choice ...
   Int_t npts = 100*GetAccuracy();
   Double_t eL = GetEL();
   Double_t eH = GetEH();

   if (eL >= eH) npts=0;

   mesh.Set(npts);
   for (Int_t n=0; n < npts; n++) {
      Double_t loge= Log(eL) + n * (Log(eH) - Log(eL)) / (npts-1);
      mesh[n] = Exp(loge);
      if (n==0) mesh[n]= eL;
      if (n==npts-1) mesh[n]= eH;
   }
   return npts;
}

//______________________________________________________________________________
void TNuResonance::SetTransient()
{
   fXmin = RangeCont()->GetC1();
   fXmax = RangeCont()->GetC2();

   // Reset the TNuVResonance parameters
   InitVirtualPart();
}
