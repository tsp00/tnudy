#include "TH2F.h"
#include "TCanvas.h"
#include "../inc/TNudy.h"
#include "../inc/TNuSublib.h"
#include "../inc/TNuFile.h"
#include "../inc/TNuSec03.h"
#include "../inc/TNuSec06.h"
#include "../inc/TNuDEpDMu2Body.h"
#include "../inc/TNuDEpDMu.h"

TH2F* GetDist2D(TNuMat* mat, const char* product_name, Double_t Ein, const char* energy_unit = "MeV", int n_mu=100, int n_Eout=200) 
{
   if (!mat) return 0;
   
   TNuFile *f3 = mat->GetFile(3);
   TNuFile *f6 = mat->GetFile(6);
   if (!f3 || !f6) return 0;
  
   double e_unit = 1;
   TString unit_str(energy_unit);
   if (unit_str.EqualTo("eV", TString::kIgnoreCase)) {
      unit_str= "eV";
      e_unit = 1;
   } else if (unit_str.EqualTo("KeV", TString::kIgnoreCase)) {
      unit_str= "keV";
      e_unit = 1000;
   } else if (unit_str.EqualTo("MeV", TString::kIgnoreCase)) {
      unit_str= "MeV";
      e_unit = 1000000;
   } else {
      printf("\nUnsupported energy unit %s, it should be one of eV, keV or MeV\n");
      unit_str= "eV";
      e_unit = 1;
   }
   
   Ein *= e_unit; // incident energy in eV
                 
   double enMax = 0;
   for (int nsec = 0; nsec < f6->GetEntries(); nsec++) 
   {
      TNuSec06 *s6 = (TNuSec06*) f6->At(nsec);
      TNuDEpDMu *depdmu = s6->GetDEpDMu(product_name);
      if (depdmu) {
         enMax = TMath::Max(enMax, Ein + depdmu->GetQI());
         //double en=Ein + depdmu->GetQI();
         //if (en > enMax) enMax = en;
      }
   }
   if (enMax < 0) return 0;
   
   double den = enMax / n_Eout;
   double dmu = 2./ n_mu;
 
   TString title=Form("Energy-Angle dist of %s from %s on %s. E_{in}=%f %s",
      product_name, mat->GetParentSublib()->GetShortName(), mat->GetDefaultName("LateX"), Ein/e_unit, unit_str.Data());
       
   TH2F *th2 = new TH2F("Dist", title.Data(),
             n_mu, -1, 1, n_Eout, 0, enMax/e_unit);
  
   for (int nsec = 0; nsec < f6->GetEntries(); nsec++) 
   {
      TNuSec06 *s6 = (TNuSec06*) f6->At(nsec);
      Int_t mt = s6->GetMT();
      printf("Processing mt=%d\n", mt);
      TNuSec03 *s3 = s6->GetSec3000();
      double  xsect = s3->XSect(Ein);

      TNuDEpDMu *depdmu = s6->GetDEpDMu(product_name);
      if (!depdmu) continue;
      double  yield = depdmu->Yield(Ein); 
      if (xsect == 0 || yield == 0) continue;

      TNuDEpDMu2Body *depdmuF2 = 0;
      TNuDEpDMuF3 *depdmuF3 = 0;
      if (depdmu->IsF3()) {
         depdmuF3 = dynamic_cast<TNuDEpDMuF3*>(depdmu);
      } else if (depdmu->IsF2()) {
         depdmuF2 = dynamic_cast<TNuDEpDMu2Body*>(depdmu);
      }

      double mu, en, frac;
      double en_2body = (depdmuF2) ? depdmuF2->GetEout(Ein) : 0;
      for (mu= -1 + dmu/2; mu < 1; mu += dmu) {
         if (depdmuF3) {
            for (en = den/2; en < enMax; en += den) {
               frac = depdmuF3->D2XDEpDMu(Ein, en, mu); //frac = xsect * yield * depdmuF3->EvalF3(Ein, en, mu);
               th2->Fill(mu, en/e_unit, frac * dmu * den);
            }
         } else if (depdmuF2) {
            en = en_2body;
            frac = xsect * yield * depdmuF2->DXDMu(Ein, mu);
            th2->Fill(mu, en/e_unit, frac * dmu);
         }
      }
   }

   return th2;
}

void DrawDist2D() {
   // Plot energy angle distribution of neutrons produced by 
   // 30 MeV proton beam on Be9.
  
   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
  
   TNuMat *mat = lib->GetSublib("p")->GetMat("Be9");
   
   TH2F *th2 = GetDist2D(mat, "n", 30, "MeV", 50, 200);

   if (th2) {
      TCanvas *c1 = (TCanvas*)(gROOT->GetListOfCanvases())->FindObject("Canvas 1");
      th2->Draw("lego2");
   }
}
