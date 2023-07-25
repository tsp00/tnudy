// TNuSec02.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

/////////////////////////////////////////////////////////////////////////////
//
// TNuSec02 : Resonance parameter data
//
// [MAT, 2,151/ ZA, AWR, 0, 0, NIS, 0/HEAD
// (i-th TNuSubIsotope, i=0,NIS-1)
//
//------------- head (1 element)
//HeadAt(0) = a TNuCont for
//[MAT, 2,151/ ZA, AWR, 0, 0, NIS, 0]HEAD
//
//------------- body (NIS elements)
//At(n) = n-th TNuSubIsotope, n=[0, NIS).
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// TNuSubIsotope : public TNuRecsWithCont
//
//   = Resonance parameters for an isotope
//
//------------- head (1 element)
//HeadAt(0) = a TNuCont for
//[MAT, 2,151/ ZAI, ABN, 0, LFW, NER, 0]CONT (isotope)
//
//------------- body (NER elements)
//At(n) = n-th TNuResonance, n=0, NER-1
//
/////////////////////////////////////////////////////////////////////////////

#include "TNuSec02.h"
#include "TNuResonance.h"

#include "TNuResoResolved.h"
#include "TNuResoBrightWigner.h"
#include "TNuResoReichMoore.h"
#include "TNuResoAdlerAdler.h"
#include "TNuResoRMatrixLimited.h"


#include "TNuResoUnresolved.h"

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

using namespace TMath;
using namespace std;

ClassImp(TNuSec02)

//______________________________________________________________________________
TNuSec02::TNuSec02() : TNuSection(), TNuVResonance(), fIsMeshed(kFALSE)
{
   // ctor

   fAccuracy = GetDefaultAccuracy();
}


//______________________________________________________________________________
TNuSec02::TNuSec02(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), TNuVResonance(), fIsMeshed(kFALSE)
{
   // ctor

   fAccuracy = GetDefaultAccuracy();
}

//______________________________________________________________________________
TNuSec02::~TNuSec02()
{
   // dtor
}

//______________________________________________________________________________
void TNuSec02::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 5
   //

   SetHead(new TNuCont(src, " ZA, AWR, 0, 0, NIS, 0/HEAD"));
   for (Int_t iso=0; iso < GetNIS(); iso++) {
      TNuSubIsotope *subIsotope = new TNuSubIsotope();
      subIsotope->SetTitle("Isotope subsection");
      TNuCont *cont = new TNuCont(src, "ZAI, ABN, 0, LFW, NER, 0 /isotope");
      subIsotope->SetCont(cont);
      for (Int_t ner=0; ner < subIsotope->GetNER(); ner++) {

         // EL, EH, LRU, LRF, NRO, NAPS /range cont

         TNuCont *range = new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range");

         Int_t LRU = range->GetL1();
         Int_t LRF = range->GetL2();

         TNuResonance *resonance = 0;
         if (LRU == 0) {
            resonance = new TNuResonance();
         }
         else if (LRU == 1) {
            // Resolved Resonance Parameters (LRU=1)
            if (LRF==1) {
               // SLBW (LRF=1)
               resonance= new TNuResoSLBW();
            }
            else if (LRF==2) {
               // MLBW (LRF=2)
               resonance = new TNuResoMLBW();
            }
            else if (LRF == 3) {
               // Reich-Moore (LRF=3)
               resonance = new TNuResoReichMoore();
            }
            else if (LRF == 4) {
               // Adler-Adler (LRF=4)
               resonance = new TNuResoAdlerAdler();
            }
            else if (LRF==7) {
               // R-Matrix Limited Format (LRF=7)
               resonance = new TNuResoRMatrixLimited();
            }
            else {
               Error("ImportEndfData", "Unsupported value of LRF = %d", LRF);
               return;
            }
         }
         else if (LRU == 2) {
            // Unresolved Resonance Parameters (LRU=2)
            Int_t LFW = subIsotope->GetLFW();
            if (LFW == 0 && LRF == 1) {
               // Case A : LFW=0 (fission widths not given)
               //          LRF=1 (all parameters are energy-independent)
               resonance = new TNuResoUnresolvedA();
            }
            else if (LFW==1 && LRF==1) {
               // Case B : LFW=1 (fission widths given)
               //          LRF=1 (only fission widths are energy-dependent;
               //                 the rest are energy-independent).
               resonance = new TNuResoUnresolvedB();
            }
            else if ((LFW == 0 || LFW == 1) && LRF==2) {
               // Case C : LFW=0 or 1 (does not depend on LFW).
               //          LRF=2 (all energy-dependent parameters).
               resonance = new TNuResoUnresolvedC();
            }
            else {
              Error("ImportEndfData","Unsupported value of LFW=%d and LRF=%d", LFW, LRF);
              return;
            }
         }
         else {
            Error("ImportEndfData", "Unsupported value of LRU = %d", LRU);
            return;
         }

         // set the head of the resonance data
         resonance->SetRangeCont(range);
         if (range->GetN1()) // if NRO != 0
            resonance->SetAPE(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));
         // and important only the remaining data
         resonance->ImportEndfData(src);
         subIsotope->Add(resonance);
      }
      Add(subIsotope);
   }
}

//______________________________________________________________________________
void TNuSec02::EvalRP(Double_t Ein, Double_t sig[]) const
{
   // Evaluate resonance parameters
   // Ein : incident energy [in eV]
   // sig[4] : resonance contribution to ...

   for(Int_t c=0; c < 4; c++) sig[c] = 0;

   for(Int_t i=0; i < GetNIS(); i++) {
      TNuSubIsotope *iso = (TNuSubIsotope *) BodyAt(i);
      Double_t isoContrib[4];
      Double_t abn = iso->GetABN();
      iso->EvalRP(Ein, isoContrib);
      for (Int_t c=0; c < 4; c++) sig[c] += abn * isoContrib[c];
   }
}

//______________________________________________________________________________
void TNuSec02::SetTransient()
{
   // Calculate the lower bound in Ein
   Double_t eL = 0;
   for (Int_t i = 0; i < GetNIS(); i++) {
      TNuSubIsotope *iso = (TNuSubIsotope *) BodyAt(i);
      eL = (i==0)? iso->GetEL() : TMath::Min(eL, iso->GetEL());
   }
   fXmin = eL;

   // Calculate the upper bound in Ein
   Double_t eH = 0;
   for (Int_t i = 0; i < GetNIS(); i++) {
      TNuSubIsotope *iso = (TNuSubIsotope *) BodyAt(i);
      eH = (i==0)? iso->GetEH() : TMath::Max(eH, iso->GetEH());
   }
   fXmax = eH;

   // Reset the TNuVResonance parameters
   InitVirtualPart();
}

//______________________________________________________________________________
void TNuSec02::GenMesh()
{
   // Generates meshes for Ein
   using namespace TMath;

   // no need to meshing twice
   if (IsMeshed()) return;

   if (GetNIS() <= 0) return;

   TNuSubIsotope *iso = (TNuSubIsotope *) BodyAt(0);
   Int_t npts = iso->GenerateMeshPoints(fMesh);

   //printf("\nMesh generated : %d points for %e <= E <= %e\n", npts, GetEL(), GetEH());

   if (npts <= 0) return;

   if (fMesh[0] != GetEL() || fMesh[npts-1] != GetEH()) {
      printf("Warning in at bounds:\n");
      printf("fMesh: %e - %e, npts=%d\n", fMesh[0], fMesh[npts-1], npts);
      printf("ELEH: %e - %e\n", GetEL(), GetEH());
      fMesh[0]= GetEL();
      fMesh[npts-1]= GetEH();
   }

   fIsMeshed = kTRUE;
   // now set sizes of fSig
   for (Int_t c=0; c<4; c++) fSig[c].Set(npts);
}


//______________________________________________________________________________
TArrayD& TNuSec02::GetMesh()
{
   // returns fMesh (the meshes for Ein)

   // no need to meshing twice
   if (!IsMeshed()) GenMesh();

   return fMesh;
}

//______________________________________________________________________________
void TNuSec02::SetAccuracy(Int_t accuracy)
{
   // sets the target accuracy :
   // 0 for defalut accuracy,
   // 1 for minimally accurate,
   // and 12 for maximally accurate.

   if (accuracy == GetAccuracy()) return;

   if (accuracy <= 0) accuracy = 0;
   else if (accuracy > 12) accuracy = 12;

   // if accuracy is to be changed, re-mesh is also required
   fIsMeshed = kFALSE;
   fAccuracy = accuracy;

   //Reset();
   // Now notify the change in accuracy through the SetLineage()
   // which calls SetTransient() successively
   TNuRecs::SetLineage();
}

// --------------------------------------------------------------------
// Sub-sections for TNuSubRange
// --------------------------------------------------------------------
ClassImp(TNuSubIsotope)

//______________________________________________________________________________
Int_t TNuSubIsotope::GetEffectiveNER() const
{
   // return the effective number of ranges for the calculation
   // of cross sections.
   //
   Int_t ner = GetNER();
   if (ner>0) {
      TNuResonance *range = (TNuResonance *) BodyAt(ner-1);
if (!range || !range->InheritsFrom("TNuResonance")) return 0;
      if (range->IsUnresolved()) {
         if (((TNuResoUnresolved*) range)->GetLSSF() != 0) ner--;
      }
   }
   return ner;
}

//______________________________________________________________________________
void TNuSubIsotope::EvalRP(Double_t Ein, Double_t sig[]) const
{
   // Evaluate resonance parameters
   // Ein : incident energy [in eV]
   // sig[4] : resonance contribution to ...

   for(Int_t c=0; c < 4; c++) sig[c] = 0;

   for(Int_t i=0; i < GetEffectiveNER(); i++) {
      TNuResonance *range = (TNuResonance *) BodyAt(i);
      //Double_t rangeContrib[4];
      //range->EvalRP(Ein, rangeContrib);
      //for (Int_t c=0; c < 4; c++) sig[c] += rangeContrib[c];
      if (Ein >= range->GetEL() && Ein <= range->GetEH()) {
         range->EvalRP(Ein, sig);
         return;
      }
   }
}

//______________________________________________________________________________
Int_t TNuSubIsotope::GenerateMeshPoints(TArrayD& mesh) const
{
   // generates meshes
   if (GetEffectiveNER() <= 0) return 0;

   TNuResonance *range = (TNuResonance *) BodyAt(0);
   Int_t npts = range->GenerateMeshPoints(mesh);
   if (GetEffectiveNER() == 1) return npts;

   for(Int_t i=1; i < GetEffectiveNER(); i++) {
      TArrayD mesh2;
      range = (TNuResonance *) BodyAt(i);
      Int_t npts2 = range->GenerateMeshPoints(mesh2);
      if (npts2 > 0) {
         mesh.Set(npts + npts2);
         for (Int_t n = 0; n < npts2; n++)
            mesh.SetAt(mesh2[n], n + npts);
         npts += npts2;
      }
   }
   return npts;
}


//______________________________________________________________________________
void TNuSubIsotope::SetTransient()
{
   // Calculate the lower bound in Ein
   Double_t eL = 0;
   for (Int_t j = 0; j < GetEffectiveNER(); j++) {
      TNuResonance *range = BodyAt(j);
      eL = (j==0) ? range->GetEL() : TMath::Min(eL, range->GetEL());
   }
   fXmin = eL;

   // Calculate the upper bound in Ein
   Double_t eH = 0;
   for (Int_t j = 0; j < GetEffectiveNER(); j++) {
      TNuResonance *range = BodyAt(j);
      eH = (j==0) ? range->GetEH() : TMath::Max(eH, range->GetEH());
   }
   fXmax = eH;

   // Reset the TNuVResonance parameters
   InitVirtualPart();
}
