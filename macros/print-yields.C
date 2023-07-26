{
   //
   // Plots the yields of products for (z,2n,alpha) of n + Pb208.

   gSystem->Load("libNudy");
   
   fprintf(stderr,"hi0");
   TNuLib *lib = TNudy::LoadRootFile("TENDL-2015.root");
   fprintf(stderr,"hi1");
   
   TNuSublib *proj=lib->GetSublib("p");
   printf("hi2");
   TNuMat *mat = proj->GetMat("Ar40");
   printf("hi3");
   TNuSec06 *sec = (TNuSec06*) mat->GetSection(605);
   printf("hi4");
   Int_t npx = TMath::Min(1000000, 100*GetNK());
   printf("hi5");
   for (Int_t k=0; k < GetNK(); k++) {
      print("k=%d",k);
      TNuTab1 *tab1= ((TNuDEpDMu*) BodyAt(k))->GetTab1();
      TF1 *tf1 = tab1->GetTF1();
      tf1->SetNpx(npx);
      // only one instance of tab1->GetTF1() can exist, so we have to copy it
      /*
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
      */
      const char* sym= GetSymbolAt(k);
      //printf("%s, e= 100 MeV, y=%f",sym, tf1->Eval(100.));
      printf("%s, e= 100 MeV, y=",sym);
//   legend->SetHeader(GetSymbol());
   }


}
