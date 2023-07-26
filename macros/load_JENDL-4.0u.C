{
   gSystem->Load("libNudy");

   TNuLib *lib = TNudy::LoadRootFile("JENDL-4.0u.root");

   TBrowser *b = TNudy::GetBrowser();
}

