// For merging ENDF-B-VII.1
{
   gSystem->Load("libNudy");

   const char* data_dir = "../data/download/ENDF-B-VII.1";
   const char* fname =    "../data/ENDF-B-VII.1.endf";

   TNuLib::MergeAsciiEndfDir(fname, data_dir);
}
