{
   gSystem->Load("libNudy");

   TNuLib *lib = TNudy::LoadRootFile("TENDL-2021.root");

   TBrowser *b = TNudy::GetBrowser();
}

