{
   gSystem->Load("libNudy");
   

   TNuLib *lib = TNudy::LoadRootFile("Th232.root");

   TBrowser *b = TNudy::GetBrowser();
}
