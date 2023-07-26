{
// example macro for comparison different data
// Target is B-10, compare Total cross section (MF = 3 MT = 1) and
// Elastic cross section (MF =3 MT = 2)

   gSystem->Load("libNudy");

   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   TNuSublib *proj=lib->GetSublib("n");

   TNuMat* pB10 = lib->GetMat("B10");
   TNuSec03 *pMF3MT001 = pB10->GetSection(3,1);
   TNuSec03 *pMF3MT002 = pB10->GetSection(3,2);

   new TCanvas();

   TF1* pMT001 = pMF3MT001->GetTF1();
   pMT001->SetLineColor(1);
   pMT001->SetLineWidth(1);
   pMT001->SetNpx(pMF3MT001->GetTab1()->GetN2());
   gPad->SetLogy();
   pMT001->SetTitle("Comparison between \"MT=1, #sigma_{Total}\" and \"MT=2, #sigma_{Elastic}\";
                     Incident Energy [eV];
                     #sigma [barn] - log scale");
   pMT001->Draw("L");

   TF1* pMT002 = pMF3MT002->GetTF1();
   pMT002->SetLineColor(2);
   pMT002->SetLineWidth(1);
   pMT002->SetNpx(pMF3MT002->GetTab1()->GetN2());
   pMT002->Draw("LSAME");

   TPaveText *pt = new TPaveText(0.7,0.7,0.85,0.85,"NDC");
   TText *t1 = pt->AddText("MT = 1, #sigma_{Total}");
   TText *t2 = pt->AddText("MT = 2, #sigma_{Elastic}");
   t2.SetTextColor(2);
   pt->Draw();

}
