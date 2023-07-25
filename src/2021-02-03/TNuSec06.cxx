// TNuSec06.cxx  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec06 : d2XdEdmu = Energy-Angle Distributions                        //
//                                                                           //
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) :
// [MAT, 6, MT/ ZA, AWR, 0, LCT, NK, 0]HEAD                                  //
//
// ------------------ body --------------------------------------------------//
// At(n) = n-th TNuDEpDMu, n=0, NK-1                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec06.h"
#include "TNuDEpDMu.h"
#include "TNuDEpDMu2Body.h"

#include "TMath.h"
#include "TNuEndfIO.h"

#include "TNudy.h"
#include "TNuMat.h"

#include "TF1.h"
#include "TF3.h"
#include "TLegend.h"
#include "THStack.h"
#include "TCanvas.h"

#include "TNuSec03.h"
#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuSec06)

//______________________________________________________________________________
void TNuSec06::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 6
   //
/*
[MAT, 6, MT/ ZA, AWR, 0, LCT, NK, 0]HEAD
<subsection for k = 1 >
<subsection for k = 2 >
-----------------------
-----------------------
<subsection for k = NK>
*/

   // first copy the QI of File 3
   Double_t qi = 0;
   TNuMat *mat = GetParentMat();
   if (mat) {
      TNuSec03 *s3000 = (TNuSec03*) mat->GetSection(3, fMT);
      if (s3000) {
//s3000->Dump();
//s3000->SetLineage();
         qi = s3000->GetQI(); // this line is problematic !!!
         GetParentMat()->GetSection(6, fMT);
      } else {
         Error("","No corresponding Section for MAT=%d, MF=%d, MT=%d", fMAT, fMF, fMT);
      }
      SetQI(qi);
      //Info("sec_6000", "QI = %f has been set for MAT=%d, MF=%d, MT=%d",
      //   GetQI(), fMAT, fMF, fMT);
   }
   else {
      Error("","No parent TNuMat for MAT=%d", fMAT);
   }

   SetHead(new TNuCont(src, "ZA, AWR, 0, LCT, NK, 0/HEAD"));
   for (Int_t k=0; k < GetNK(); k++) {
      // begin of k-th subsection
      TNuDEpDMu *sub = 0;
      //TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
      //sub->SetTab1(tab1);

      Int_t LAW = src.GetL2();

      if (LAW == 0) {
         // Unknown Distribution (LAW=0)
         sub = new TNuDEpDMuUnknwon(src);
      }
      else if (LAW == 1) {
         // Continuum Energy-Angle Distributions (LAW=1)
         sub = new TNuDEpDMuContinuum(src);
      }
      else if (LAW == 2) {
         // Discrete Two-Body Scattering (LAW=2)
         sub = new TNuDEpDMu2BodyScattering(src);
      }
      else if (LAW == 3) {
         // Isotropic Discrete Emission (LAW=3)
         sub = new TNuDEpDMu2BodyIsotropic(src);
      }
      else if (LAW == 4) {
         // Discrete Two-Body Recoils (LAW=4)
         sub = new TNuDEpDMu2BodyRecoil(src);
      }
      else if (LAW == 5) {
         // Charged-Particle Elastic Scattering (LAW=5)
         sub = new TNuDEpDMu2BodyCoulomb(src);
      }
      else if (LAW == 6) {
         // N-Body Phase-Space Distributions (LAW=6)
         sub = new TNuDEpDMuNBodyPhaseSpace(src);
      }
      else if (LAW == 7) {
         // Laboratory Angle-Energy Law (LAW=7)
         sub = new TNuDEpDMuLaboratory(src);
      }
      else {
         Error("ImportEndfData", "Unsupported value of LAW=%d", LAW);
      }
      //sub->SetQI(qi);
      Add(sub);
   }
}

//______________________________________________________________________________
void TNuSec06::SetTransient()
{
   // Sets the ranges

   fXmin = ((TNuDEpDMu*) BodyFirst())->GetTab1()->GetXmin();
   fXmax = ((TNuDEpDMu*) BodyLast())->GetTab1()->GetXmax();

   // Sets fSec3000
   fSec3000 = (TNuSec03*) GetParentMat()->GetSection(3, GetMT());
   if (!fSec3000) {
      Error("SetTransient", "Failed in getting corresponding section in file 3 for MT=%d", fMT);
      return;
   }

   fQI = fSec3000->GetQI();
}

//______________________________________________________________________________
Double_t TNuSec06::EvalF1At(Int_t n, Double_t En, Double_t* /*ps*/) const
{
   // Evaluates n-th yield

   if (n < 0 || n > GetNK()) return 0;
   TNuDEpDMu *tab1sub = (TNuDEpDMu*) BodyAt(n);
   return tab1sub->Tab1Eval(En);
}

//______________________________________________________________________________
const Char_t* TNuSec06::GetSymbolAt(Int_t n) const
{
   // Returns the symbol for the n-th entry

   Int_t zaip = ((TNuDEpDMu*) BodyAt(n))->GetZAIP();
   return TNuMat::GetDefaultMatName(zaip, "Latex");
}

//______________________________________________________________________________
void TNuSec06::Add(TObject* obj)
{
   // Adding TNuDEpDMu objects with naming xx-ClassName style

   if (obj) {
      Int_t zaip = ((TNuDEpDMu*) obj)->GetZAIP();
      const Char_t* symbol = TNuMat::GetDefaultMatName(zaip, "Latex");
      ((TNuObject*)obj)->SetName(Form("%s_%s", symbol, obj->GetName()));
      TNuRecs::Add(obj);
   }
}

//______________________________________________________________________________
void TNuSec06::DrawYields()
{
   // plot yields of products

   TCanvas *c1 = TNudy::GetCanvas();

   THStack *hs = new THStack(GetName(), GetTitle());
   TLegend *legend = new TLegend(0.8,0.7,0.96,0.96);
   TList h1s;

   TH1D *h1;
   Int_t npx = TMath::Min(1000000, 100*GetNK());
   for (Int_t k=0; k < GetNK(); k++) {
      TNuTab1 *tab1= ((TNuDEpDMu*) BodyAt(k))->GetTab1();
      TF1 *tf1 = tab1->GetTF1();
      tf1->SetNpx(npx);
      // only one instance of tab1->GetTF1() can exist, so we have to copy it
      h1 = new TH1D(*(dynamic_cast<TH1D*>(tf1->GetHistogram())));
      h1->SetName(Form("DrawYields_%d", k));
      h1s.Add(h1);
      Int_t color=k+1;
      h1->SetFillColor(color);
      h1->SetMarkerStyle(21);
      h1->SetMarkerColor(color);
      h1->SetFillStyle(3001+k);
      hs->Add(h1);
      //Int_t zaip = tab1sub->GetZAIP();
      //legend->AddEntry(h1,TNuMat::GetDefaultMatName(zaip),"f");
   }

   Int_t ncol = (GetNK() + 9) / 10;
   if (ncol > 1) {
      legend->SetNColumns(ncol);
   }

   // to make 1st-in element at the bottom of legend
   for (Int_t k=GetNK()-1; k >=0; k--) {
      h1 = (TH1D*) h1s.At(k);
      legend->AddEntry(h1, GetSymbolAt(k),"f");
   }

   legend->SetHeader(GetSymbol());

   hs->Draw();
   legend->Draw();

   hs->GetXaxis()->SetTitle("E_{in} [eV]");

   c1->Update();
   TNudy::NeedsCanvasCleared(kTRUE);
}

//______________________________________________________________________________
TNuDEpDMu* TNuSec06::GetDEpDMu(const Char_t* product_name) const
{
   // find and return the TNuDEpDMu subsection with given product name

   return GetDEpDMuByZAIP(TNudy::ZAIof(product_name));
}

//______________________________________________________________________________
TNuDEpDMu* TNuSec06::GetDEpDMuByZAP(Int_t zap) const
{
   // find and return the TNuDEpDMu subsection with given za
   
   for (Int_t k=0; k < GetNK(); k++) {
      TNuDEpDMu* sub = GetDEpDMuAt(k);
      if (sub->GetZAP() == zap) return sub;
   }
   return 0;
}

//______________________________________________________________________________
TNuDEpDMu* TNuSec06::GetDEpDMuByZAIP(Int_t zaip) const
{
   // find and return the TNuDEpDMu subsection with given zai
   
   for (Int_t k=0; k < GetNK(); k++) {
      TNuDEpDMu* sub = GetDEpDMuAt(k);
      if (sub->GetZAIP() == zaip) return sub;
   }
   return 0;
}
