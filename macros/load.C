// Loader of TNudy (ENDF) root file.
//
// Usage:
// root (enter)
// 	root [] .L load.C (enter)
// 	root [] load("JEFF-3.1.2.root") (enter)
//		//... 
// 	root [] .q (enter)
 
TNuLib* load (const char * root_filename = "ENDF-B-VII.1.root")
{
   gSystem->Load("libNudy");

   TString fname(root_filename);
   if (!fname.EndsWith(".root")) {
      if (!fname.EndsWith(".")) fname.Append(".");
      fname.Append("root");
   }
   TNuLib *lib = TNudy::LoadRootFile(fname.Data());

   TBrowser *b = TNudy::GetBrowser();
   return lib;
}

