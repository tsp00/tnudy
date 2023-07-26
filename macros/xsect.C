#include "TCanvas.h"
#include "TPad.h"
#include "TPaveLabel.h"
#include "TLatex.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TFrame.h"
#include "TString.h"

#include "../inc/TNuMat.h"
#include "../inc/TNuSec03.h"
#include "../inc/TNuSec02.h"

void DrawXSect(TNuMat *mat, Double_t emin, Double_t emax, Double_t smin, Double_t smax);

void xsect(const Char_t *isotope = "Th232")
{
   //
   // Plot cross sections for selected isotopes

   const Double_t emin = 1.e-3;
   const Double_t emax = 2.e+7;
   const Double_t smin = 1.e-6;
   const Double_t smax = 1.e+4;

   //gSystem->Load("libRIO");
   //gSystem->Load("libHist");
   //gSystem->Load("libNudy");
   
//   TCanvas *c1 = (TCanvas*)(gROOT->GetListOfCanvases())->FindObject("Canvas 1");
   TCanvas *c1 = new TCanvas("XSects", "Cross sections with reso",
      10, 40, 800, 600);
   c1->SetFillColor(40);
   c1->SetLogx();
   c1->SetLogy();
   c1->SetGridx();
   c1->SetGridy();
   c1->DrawFrame(emin,smin, emax, smax);
   c1->GetFrame()->SetFillColor(19);
   //c1->RangeAxis(emin, smin, emax, smax);
   //c1->Draw();

   //c1->Range(0,0,25,25);

   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   lib->ResetCounter();
   TNuSublib *proj = lib->GetSublib("n");

   TNuMat* mat = proj->GetMat(isotope);
   if (!mat) {
      printf("Warning : failed to get TNuMat for %s\n", isotope);
      continue;
   }

   DrawXSect(mat, emin, emax, smin, smax);

   c1->Modified();
   c1->Update();
}

void DrawXSect(TNuMat *mat, Double_t emin, Double_t emax, Double_t smin, Double_t smax)
{
   //
   // Plot cross sections for selected isotopes
   if (!mat) {
      printf("Warning : Null TNuMatfor\n");
      return;
   }

/*
   static const struct {
      Int_t     mt;
      Int_t     color;
      const Char_t *desc;
   } kChannels[] = {
      {  1,  3, "Total"},
      {  2,  1, "Elastic"},
      { 18,  2, "Fission"},
      {102,  4, "Radiative Capture"},
      {  4, 12, "Production of one neutron"},
      { 16, 41, "(n,2n)"},
      { 17, 46, "(n,3n)"}
   };
   Int_t nChannels = (int) sizeof(kChannels)/sizeof(kChannels[0]);
*/
   Int_t nChannels = 5;
   const Int_t mts[] =    {1,  2, 18,102, 16};
   const Int_t colors[] = {11,  1,  2,  4,  8};

   TPaveLabel *pl = new TPaveLabel(emin,1.2*smax,emax, 9*smax, 
      Form("Cross sections (barns) of %s with respect to En (eV)",
         mat->ChemicalSymbol()), "br");
   pl->SetFillColor(18);
   //pl->SetTextFont(32);
   //pl->SetTextColor(49);
   pl->Draw();

 //  TMultiGraph *mg = new TMultiGraph();
 //  mg->SetTitle(Form("Cross sections of %s", mat->GetSymbol()));

   for (int nchan = 0; nchan < nChannels; nchan++) {
/*
printf("n=%d : mt = %d, color = %d\n",
nchan,
kChannels[nchan].mt,
kChannels[nchan].color);
//kChannels[nchan].desc);
      Int_t mt = kChannels[nchan].mt;
*/
      Int_t mt = mts[nchan];
      TNuSec03 *s3 = mat->GetSection(3, mt);
      if (!s3) {
         printf("Warning : null section for MT =%d\n", mt);
         continue;
      }
      TGraph *gr = s3->GetXSectWithResoGraph();
      if (gr) {
         gr->SetLineColor(colors[nchan]);
         gr->Draw("L");
         //mg->Add(gr);
      }
      else {
         printf("Warning : null graph for MT =%d\n", mt);
      }
   }
   //mg->Draw("AL");
   //mg->SetMinimum(smin);
   //mg->SetMaximum(smax);
   //mg->GetXaxis()->SetLimits(emin, emax);
   //TAxis *xaxis = mg->GetXaxis();
   //xaxis->SetRangeUser(1.e-3, 20.e+6);
}
