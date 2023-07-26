{
   gSystem->Load("libNudy");

   //TNudy *nudy = new TNudy();
   //TNudy *nudy = gNudy;
   //TNudy *nudy = TNudy::GetInstance();

   TFile f("Th232.root", "RECREATE", "ROOT Endf file for the n-090_Th_232 data", 1);
   TNuLib *lib = new TNuLib(&f, "Th232", "Test Lib for n-090_Th_232");
   lib->ImportAsciiEndf("../data/n-090_Th_232.endf");
   lib->Write();

   // Now saving the library
   printf("Now saving the library and closing the tfile, which takes a few minutes...\n");
   f.Close();
   printf("All done.\n");

   f.Close();
}


