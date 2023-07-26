// For merging JEFF-3.1.2
{
   gSystem->Load("libNudy");

   const char* data_dir = "../data/download/JEFF-3.1.2";
   const char* fname =    "../data/JEFF-3.1.2.endf";

   TNuLib::MergeAsciiEndfDir(fname, data_dir);
}
