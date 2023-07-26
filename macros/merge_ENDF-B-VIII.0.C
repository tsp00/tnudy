// For merging ENDF-B-VIII.0
{
   gSystem->Load("libNudy");

   const char* data_dir = "../data/ENDF-data/ENDF-B-VIII.0";
   const char* fname =    "../data/ENDF-data/ENDF-B-VIII.0.endf";

   TNuLib::MergeAsciiEndfDir(fname, data_dir);
}
