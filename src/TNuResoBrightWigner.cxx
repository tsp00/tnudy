// TNuResoBrightWigner.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

/////////////////////////////////////////////////////////////////////////////
//
// TNuResoBrightWigner : public TNuResoResolved
//
// LRF= 1 (for single level) or 2 (for multi level)
//
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
// [MAT, 2,151/ SPI,   AP,    0,     0,     NLS,   0]CONT
//
// ------------------ body --------------------------------------------------
//
// At(n) = n-th subsection for a given L (n=0, NLS-1) =
// = a TNuList fo
//
//[MAT, 2,151/ AWRI,  QX,    L,     LRX,   6*NRS, NRS
//             ER1,   AJ1,   GT1,   GN1,   GG1,   GF1,
//             ER2,   AJ2,   GT2,   GN2,   GG2,   GF2,
//             ERNRS, AJNRS, GTNRS, GNNRS, GGNRS, GFNRS] LIST
//
// The values of ER for each l-value are given in increasing order.
//
// ------------------ notes -------------------------------------------------
//
//
/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuResoSLBW : public TNuResoBrightWigner
//
// LRF= 1
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuResoMLBW : public TNuResoBrightWigner
//
// LRF= 2
//                                                                           //
///////////////////////////////////////////////////////////////////////////////


#include "TNuResoBrightWigner.h"

//#include "TNuSec02151.h"
#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2.h"
#include "TNuRecsWithCont.h"
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

ClassImp(TNuResoBrightWigner)

//______________________________________________________________________________
// locals
//
struct BrightWignerStruct {
   Double_t ER; // Resonance energy (in the laboratory system).
   Double_t AJ; // The floating-point value of +/- J
   Double_t GT; // Total width, Gamma, evaluated at the resonance energy ER.
   Double_t GN; // Neutron width Gamma_n evaluated at the resonance energy ER.
   Double_t GG; // Radiation width, Gamma_gamma, a constant
   Double_t GF; // Fission width, Gamma_f, a constant.
};

//______________________________________________________________________________
void TNuResoBrightWigner::ImportEndfData(TNuEndfIO& src)
{
   // SLBW and MLBW (LRF=1 or 2)
   //

   // head is already read
   //SetCont(new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range"));
   //if (GetNRO())
   //   Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));


   SetSpinCont(new TNuCont(src, "SPI, AP, 0, 0, NLS, 0"));

   for (Int_t nls=0; nls < GetNLS(); nls++) {
      TNuList *list = new TNuList(src, "AWRI, QX, L, LRX, 6*NRS, NRS"
         "; ER, AJ, GT, GN, GG, GF");
      Add(list);
   }
}

#include "TArrayD.h"
//______________________________________________________________________________
void TNuResoBrightWigner::EvalRP(Double_t Ein, Double_t sig[]) const
{
   // Evaluate resonance parameters
   // Ein : incident energy [in eV]
   // sig[4] : resonance contribution to each component of the cross sections
   // [MAT, 2,151/ SPI, AP, 0, 0, NLS, 0]CONT
   //
   // Note: The assignment of AJ for SLBW is not quite correct,
   // for example, it reads AJ=0.5 for U-239,
   // while AJ should be an integer, since the system consists of
   // (A-odd nucleus) plus neutron.
   //
   using namespace TMath;

   for (Int_t i=0; i< 4; i++) sig[i]=0;
   if (Ein < GetEL() || Ein>GetEH()) return;

   //Double_t hat_radius = (GetNRO() == 0) ? GetAP() : GetAPE(Ein);

   // Bool_t isSLBW = (GetLRF() == 1) ? kTRUE : kFALSE;
   Bool_t isMLBW = (GetLRF() == 2)  ? kTRUE : kFALSE;

   // CM momentum p in [1/10^(-12) fm]
   Double_t p = Getpcm(Ein);

   for (Int_t nls=0; nls < GetNLS(); nls++) {
      // AWRI, QX, L, LRX, 6*NRS, NRS / {ER, AJ, GT, GN, GG, GF} LIST
      TNuList *list = (TNuList*) BodyAt(nls);
      Int_t L = list->GetL1();

      Double_t phiL = GetHardspherePhaseShift(L, Ein, p);

      Double_t Sl, Pl; // S_l(|Ein|) and P_l(|E|)
      HardsphereFactors(L, p, Ein, &Pl, &Sl);

      sig[kElastic] += (2*L+1)*4*Sin(phiL)*Sin(phiL);

      Int_t LRX = list->GetL2();
      Int_t nrs = list->GetN2();
      TArrayD xs(nrs);
      TArrayD ys(nrs);

      struct BrightWignerStruct *r = (struct BrightWignerStruct *) list->GetData();
      for (Int_t nr=0; nr < nrs; nr++, r++) {
         Double_t AJ = r->AJ;
         Double_t gJ = (2*Abs(AJ)+1)/(4*GetSPI()+2);
         // loop over resonance levels
         Double_t ER = r->ER; // Resonance energy (in the laboratory system).
         Double_t Plr, Slr;
         HardsphereFactors(L, Getpcm(TMath::Abs(ER)), ER, &Plr, &Slr);
         Double_t ERp = ER + (Slr - Sl)*r->GN / (2*Plr);

         Double_t GG = r->GG; // Radiation width, Gamma_gamma, a constant
         Double_t GF = r->GF; // Fission width, Gamma_f, a constant.
         Double_t GX = r->GT - (r->GN + GG + GF); //Competitive width, a constant.
         if (LRX == 0) GX = 0;

         Double_t GN = r->GN * Pl/Plr;  // E-dependent neutron width
         Double_t GT = GN + GG + GF + GX;  // E-dependent total width
         Double_t dE = Ein - ERp;

         Double_t factor = GN/(dE*dE + GT*GT/4);
         sig[kElastic] += gJ * factor * (GN - 2*GT*Sin(phiL)*Sin(phiL) + 2*dE*Sin(2*phiL));
         sig[kCapture] += gJ * factor * GG;
         sig[kFission] += gJ * factor * GF;
         if (isMLBW) {
            xs[nr] = factor * dE;
            ys[nr] = factor * GT/2;
            Double_t sumx=0, sumy=0;
            struct BrightWignerStruct *s = (struct BrightWignerStruct *) list->GetData();
            for (Int_t ns=0; ns < nr; ns++, s++) {
               if (Abs(AJ - s->AJ) < 0.1) {
                  sumx += xs[ns];
                  sumy += ys[ns];
               }
            }
            sig[kElastic] += 2 * gJ * (xs[nr] * sumx + ys[nr] * sumy);
         }
      }
   }

   sig[kTotal] = sig[kElastic] + sig[kCapture] + sig[kFission];
   for (Int_t i=0; i < 4; i++) sig[i] *= Pi()/(p*p);
}

//______________________________________________________________________________
Int_t TNuResoBrightWigner::GenerateMeshPoints(TArrayD& mesh) const
{
   // Generates mesh points for the range  EL < ER < EH
   // according to the accuracy

   TNuList *list0 = (TNuList*) BodyAt(0);
   Int_t NRS = 0;
   if (list0) NRS = list0->GetN2();
   if (!NRS) {
      Error("","NRS = 0");
      return 0;
   }

   TArrayD energies(NRS);
   TArrayD widths(NRS);
   Int_t ir=0;

   for (Int_t nls=0; nls < GetNLS(); nls++) {
      // AWRI, QX, L, LRX, 6*NRS, NRS / {ER, AJ, GT, GN, GG, GF} LIST
      TNuList *list = (TNuList*) BodyAt(nls);

      //Int_t L = list->GetL1();
      struct BrightWignerStruct *r = (struct BrightWignerStruct *) list->GetData();
      for (Int_t nr=0; nr < list->GetN2(); nr++, r++) {
         // loop over resonance levels
         Double_t ER = r->ER; // Resonance energy (in the laboratory system).
         //Double_t GT = r->GT; //Competitive width, a constant.
         Double_t GT = r->GN + r->GG + r->GF;
         //if (ER > GetEL() || ER < GetEH()) {
            if (ir <= energies.GetSize()) {
               Int_t size = energies.GetSize() + NRS;
               energies.Set(size);
               widths.Set(size);
            }
            energies.AddAt(ER, ir);
            widths.AddAt(GT, ir);
            ir++;
         //}
      }
   }
   energies.Set(ir);
   widths.Set(ir);
   return MakeSubIntervals(energies, widths, mesh);
}


ClassImp(TNuResoSLBW)

ClassImp(TNuResoMLBW)
