{
   gSystem->Load("libNudy");

   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");

   TBrowser *b = TNudy::GetBrowser(lib);
}

