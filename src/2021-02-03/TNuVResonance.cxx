// TNuVResonance.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuVResonance                                                             //
//                                                                           //
// Abstract class to provide a uniform interfaces                            //
// for the classes related to the resonance data                             //
//                                                                           //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#include "TNuVResonance.h"

#include "TNuSec02.h"
#include "TNuResonance.h"
#include "TNuMat.h"
#include "TNudy.h"

#include "TArrayD.h"

#include "TMath.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TMultiGraph.h"
#include "TPad.h"

#include "stdio.h"

ClassImp(TNuVResonance)

Int_t TNuVResonance::fDefaultAccuracy = 3;

//______________________________________________________________________________
//---- static const data
const static Char_t* fFigTitles[4] = {
   "elastic", "capture", "fission", "total"
   };

//______________________________________________________________________________
TNuVResonance::TNuVResonance() : TNuVF1s()
{
   // ctor

   InitVirtualPart();
}


//______________________________________________________________________________
void TNuVResonance::InitVirtualPart()
{
   // resets

   fNLo = fNHi = -1;
   for (Int_t c=0; c < 4; c++) {
      fSigMin[c] = fSigMax[c] = 0;
   }
   fLastEvaluator = 0;
}

//______________________________________________________________________________
const Char_t* TNuVResonance::GetSymbolAt(Int_t n) const
{
   const static Char_t* fYLabels[4] = {
      "#sigma_{elastic} [barn]",
      "#sigma_{capture} [barn]",
      "#sigma_{fission} [barn]",
      "#sigma_{total} [barn]"
      };

   return fYLabels[n];
}

//______________________________________________________________________________
Double_t TNuVResonance::EvalF1At(Int_t n, Double_t Ein, Double_t* /*ps*/) const
{
   Double_t sig[4];
   EvalF1s(Ein, sig);
   return sig[n];
}

//______________________________________________________________________________
void TNuVResonance::SetBounds() const
{
   // find fNLo and fNHi such that GetEL = fMesh[fNLo] and GetEH = fMesh[fNHi]

   if (!HaveResonanceParameters()) return;

   // no need to evaluate twice
   if (fNLo >= 0 && fNHi > 0) {
      // already done
      return;
   }

   TNuSec02* sec = GetParentSec02();
   // get meshes
   TArrayD fMesh = sec->GetMesh();
   Int_t size = fMesh.GetSize();
   if (size==0) return;

   fNLo = TMath::BinarySearch(size, fMesh.GetArray(), GetEL());
   if (fMesh[fNLo] < GetEL()) fNLo++;

   fNHi  = TMath::BinarySearch(size, fMesh.GetArray(), GetEH());

   if (fNLo < 0 || fNLo >= size) {
      fprintf(stderr, "Lower bound error: EL = %e and fNLo = %d\n", GetEL(), fNLo);
   }
   if (fNHi <= 0 || fNHi >= size) {
      fprintf(stderr, "Upper bound error: ER = %e and fNHi = %d\n", GetEH(), fNHi);
   }
}

//______________________________________________________________________________
void TNuVResonance::Evaluate() const
{
   // Generates the resonance contributions, and add up to fSig

   if (!HaveResonanceParameters()) return;

   SetBounds();

   // no need to evaluate twice
   if (IsEvaluated()) return;

   // gen meshes
   TNuSec02* sec = GetParentSec02();
   TArrayD fMesh = sec->GetMesh();
   TArrayD* fSig = sec->GetSig();

   if (fNLo < 0 || fNHi <= 0) {
      fprintf(stderr,"Bound error in Evaluate, fNLo=%d fNHi=%d\n", fNLo, fNHi);
      return;
   }

   for (Int_t n=fNLo; n <= fNHi; n++) {
      //for (Int_t c=0; c < 4; c++) fSig[c][n] = 0;
      Double_t Ein = fMesh[n];
      Double_t sig[4];
      EvalRP(Ein, sig);
      for (Int_t c=0; c < 4; c++) fSig[c][n] = sig[c];
   }

   for (Int_t c=0; c < 4; c++) {
      fSigMin[c]= TMath::MinElement(fNHi-fNLo +1, fSig[c].GetArray() + fNLo);
      fSigMax[c]= TMath::MaxElement(fNHi-fNLo +1, fSig[c].GetArray() + fNLo);
   }
   fLastEvaluator = (size_t) this;
}

//______________________________________________________________________________
void TNuVResonance::PrintSummary() const
{
   // prints the summary of the evaluated resoanance contributions

   if (!IsEvaluated()) Evaluate();

   TNuSec02* sec = GetParentSec02();
   TArrayD fMesh = sec->GetMesh();

   printf("\n--------------------------------------------------------\n");
   printf("Range: (E[%d]=%e) <= Ein <= (E[%d] = %e)\n",
      fNLo, fMesh[fNLo], fNHi, fMesh[fNHi]);
   printf("Resonance contributions ---> \n");
   for (Int_t c=0; c < 4; c++) {
      printf("sig(%8s) : min = %e, max = %e\n", fFigTitles[c],
         GetSigMin(c), GetSigMax(c));
   }
}

//______________________________________________________________________________
TGraph* TNuVResonance::GetGraphOfSigmaOf(Int_t c) const
{
   // get the TGraph for the resonance contribution to the cross section

   if (!HaveResonanceParameters()) return 0;

   SetBounds();

   if (c < 0 || c >= 4) {
       fprintf(stderr,"The channel number c = %d should be [0 ~ 3]\n", c);
       return 0;
   }

   if (!IsEvaluated()) Evaluate();

   TGraph *gr = new TGraph(fNHi - fNLo + 1);
   gr->SetTitle(fFigTitles[c]);

   TNuSec02* sec = GetParentSec02();
   TArrayD fMesh = sec->GetMesh();
   TArrayD* fSig = sec->GetSig();

   if (fNLo < 0 || fNHi <= 0) {
      fprintf(stderr,"Bound error in GetGraphOfSigmaOf, fNLo=%d fNHi=%d\n", fNLo, fNHi);
      return 0;
   }
   for (Int_t n=fNLo; n <= fNHi; n++) {
      gr->SetPoint(n-fNLo, fMesh[n], fSig[c][n]);
   }

   gr->GetXaxis()->SetTitle("E [eV]");
   gr->GetYaxis()->SetTitle(GetSymbolAt(c));

   return gr;
}

//______________________________________________________________________________
void TNuVResonance::PlotSigmaOf(Int_t c) const
{
   // draw the resonance contribution to the cross section

   TCanvas *c1 = TNudy::GetCanvas();
   if (!HaveResonanceParameters()) return;

   TGraph *gr = GetGraphOfSigmaOf(c);

   if (!gr) return;

   gr->Draw("AL");

   c1->Update();
}

//______________________________________________________________________________
void TNuVResonance::PlotSigmaElastic() const
{
   //plot the resonance contribution to the elastic cross section
   PlotSigmaOf(kElastic);
}

//______________________________________________________________________________
void TNuVResonance::PlotSigmaCapture() const
{
   //plot the resonance contribution to the capture cross section
   PlotSigmaOf(kCapture);
}

//______________________________________________________________________________
void TNuVResonance::PlotSigmaFission() const
{
   //plot the resonance contribution to the fission cross section
   PlotSigmaOf(kFission);
}

//______________________________________________________________________________
void TNuVResonance::PlotSigmaTotal() const
{
   //plot the resonance contribution to the total cross section
   PlotSigmaOf(kTotal);
}

//______________________________________________________________________________
void TNuVResonance::PlotSigmaAll() const
{
   // plot all of the resonance contributions

   TCanvas *c1 = TNudy::GetCanvas();
   c1->Clear();
   if (!HaveResonanceParameters()) return;

   //TCanvas *c1 = new TCanvas("c1", this->GetName());
   TMultiGraph *mg = new TMultiGraph();
   mg->SetTitle("Resonance contributions to the cross section");
   TGraph *gT  = GetGraphOfSigmaOf(kTotal); // total
   TGraph *gnn = GetGraphOfSigmaOf(kElastic); // elastic
   TGraph *gng = GetGraphOfSigmaOf(kCapture); // radiative capture
   TGraph *gnf = GetGraphOfSigmaOf(kFission); // fission

   if (gT) {
      gT->SetLineColor(kGreen);
      mg->Add(gT);
   }
   if (gnn) {
      gnn->SetLineColor(kBlack);
      mg->Add(gnn);
   }
   if (gng) {
     gng->SetLineColor(kBlue);
     mg->Add(gng);
   }
   if (gnf && GetSigMax(kFission) > 0) {
     gnf->SetLineColor(kRed);
     mg->Add(gnf);
   }

   Double_t bottom = 1.e99;
   for (Int_t c=0; c < 4; c++) {
     Double_t min = GetSigMin(c);
     if(min != 0 && min < bottom) bottom = min;
   }
   mg->SetMinimum(bottom);

   mg->Draw("AL");

   c1->Update();
   TNudy::NeedsCanvasCleared(kTRUE);
   PrintSummary();
}

//______________________________________________________________________________
TNuSec02* TNuVResonance::GetParentSec02() const
{
   // returns the parent section

   TNuObject *my = dynamic_cast<TNuObject* const>((TNuVResonance*) this);
   TNuSec02 *sec = (TNuSec02*) my->GetParentSection();
   return sec;
}

//______________________________________________________________________________
Bool_t TNuVResonance::HaveResonanceParameters() const
{
   // if there are resoanance parameters (the LRP parameters are 1 or 2)

   TNuSec02 *sec = GetParentSec02();
   if (!sec) {
      Error("HaveResonanceParameters", "No parent Sec02");
      return kFALSE;
   }
   return (sec->GetParentMat()->GetLRP() > 0);
}

//______________________________________________________________________________
Int_t TNuVResonance::GetAccuracy() const
{
   // returns the target accuracy :
   // 0 for defalut accuracy,
   // 1 for minimally accurate,
   // and 12 for maximally accurate.

   return GetParentSec02()->GetAccuracy();
}

//______________________________________________________________________________
void TNuVResonance::SetAccuracy(Int_t accuracy)
{
   // sets the target accuracy :
   // 0 for defalut accuracy,
   // 1 for minimally accurate,
   // and 12 for maximally accurate.

   if (accuracy == GetAccuracy()) return;

   GetParentSec02()->SetAccuracy(accuracy);
}

//______________________________________________________________________________
void TNuVResonance::SetDefaultAccuracy(Int_t accuracy)
{
   // sets the default target accuracy in a global manner :
   // 0 for defalut accuracy,
   // 1 for minimally accurate,
   // and 12 for maximally accurate.

   if (accuracy == GetDefaultAccuracy()) return;

   if (accuracy <= 0) accuracy = 0;
   else if (accuracy > 12) accuracy = 12;
   fDefaultAccuracy = accuracy;
}

