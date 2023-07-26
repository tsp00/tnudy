{
gSystem->Load("libNudy");

//TNudy *nudy = new TNudy();

printf("\nTFile f(\"Th232.root\");\n");
TFile f("Th232.root");

printf("\nf.ls();\n");
f.ls();

printf("\nTNuLib *nudy = TNudy::OpenLib(&f, \"Th232\");\n");
TNuLib *nudy = TNudy::OpenLib(&f, "Th232");

TBrowser browser;

// to list the Names
//nudy->ShowObjNames();

// to list the Titles
//nudy->ShowObjTitles();

printf("\n//to list the Labels");
printf("\nnudy->ShowObjLabels();\n");
nudy->ShowObjLabels();

printf("\n//to set incident particle = neutron");
printf("\nnudy->GetSublib(\"n\");\n");
nudy->GetSublib("n");

printf("\n// to get 90-Th-232 Mat data");
printf("\nTNuMat *th232 = nudy->GetMat(\"Th232\");\n");
TNuMat *th232 = nudy->GetMat("Th232");

printf("\n// get MAT value");
printf("\nth232->GetMAT();\n");
th232->GetMAT();

printf("\n//get ZAI value");
printf("\nth232->GetZAI();\n");
th232->GetZAI();

printf("\n// to get MF=3 and MT=1 data");
printf("\nTNuSection *sec3001 = th232->GetSection(3,1);\n");
TNuSection *sec3001 = th232->GetSection(3,1);

printf("\n// printing with ENDF format");
printf("\nsec3001->Print(\"--ENDF\");\n");
sec3001->Print("--ENDF");

printf("\n\n// now enjoy ... \n");

TNuSec06 *sec = th232->GetSection(6016); // (n,2n)
TNuDEpDMuContinuum *obj = (TNuDEpDMuContinuum*) sec->BodyAt(2); // photon
obj->What();

//obj->Plot3D();
   const Int_t max = 20;
   TNuVF3 *t3 = dynamic_cast<TNuVF3*>(obj);
   TH3D *h3 = new TH3D(obj->GetName(), obj->GetTitle(), 
                 max+1, t3->GetXmin(), t3->GetXmax(),
                 max+1, t3->GetYmin(), t3->GetYmax(),
                 max+1, t3->GetZmin(), t3->GetZmax());
   for (Int_t i=0; i < max; i++) {
      Double_t x = t3->GetXmin() + (i*(t3->GetXmax() - t3->GetXmin()))/max;
      for (Int_t j=0; j < max; j++) {
         Double_t y = t3->GetYmin() + (j*(t3->GetYmax() - t3->GetYmin()))/max;
         for (Int_t k=0; k < max; k++) {
            Double_t z = t3->GetZmin() + (k*(t3->GetZmax() - t3->GetZmin()))/max;
            Double_t val = t3->EvalF3(x,y,z);
            //val = (val <= 1.E-30)? 0 : TMath::Log(val);
            h3->Fill(x,y,z,val);
         }
      }
   }
   h3->Draw("iso");
}
}

