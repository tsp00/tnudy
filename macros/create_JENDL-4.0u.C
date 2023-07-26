{
   gSystem->Load("libNudy");

   const char* base_dir = "../data/";
   const char* lib_name = "JENDL-4.0u";
   const char* lib_title = "Japanese evaluated nuclear data library";

   const char* source_name = Form("%s%s.endf", base_dir, lib_name);
   const char* target_name = Form("%s.root", lib_name);

   TFile f(target_name, "RECREATE", lib_title, 1);
   TNuLib *lib = new TNuLib(&f, lib_name, lib_title);
   lib->ImportAsciiEndf(source_name);
   lib->Write();

   // Now saving the library
   printf("Now saving the library and closing the tfile, which takes a few minutes...\n");
   f.Close();
   printf("All done.\n");
}
