{
   gSystem->Load("libNudy");

   TNuLib *lib = TNudy::LoadRootFile("TENDL-2012.root");

   TBrowser *b = TNudy::GetBrowser();
}

