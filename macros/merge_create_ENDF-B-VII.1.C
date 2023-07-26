// Create a TNudy (ROOT) data file for the
// ASCII ENDF data files given in a directory

{
   gSystem->Load("libNudy");

   const char* data_dir = "../data/download/ENDF-B-VII.1";
   const char* lib_name = "endf71";
   const char* lib_desc = "ENDF/B-VII.1 U.S. Evaluated Nuclear Data Library, issued in 2011";

   const char* filename = Form("%s.root", lib_name);
   const char* file_desc = Form("ROOT file for %s, %s", lib_name, lib_desc);
   TFile f(filename, "RECREATE", file_desc,1);
   TNuLib *lib = new TNuLib(&f, lib_name, lib_desc);
   lib->ImportAsciiEndfDir(data_dir);

   // Now saving the library
   printf("Now saving the library and closing the tfile, which takes a few minutes...\n");
   fflush(stdout);
   lib->Write();

   f.Close();
   printf("All done.\n");
}
