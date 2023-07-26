// For merging TENDL-2012
{
   gSystem->Load("libNudy");

   const char* data_dir = "../data/ENDF-data/tendl-2021";
   const char* fname =    "../data/ENDF-data/TENDL-2021.endf";

   TNuLib::MergeAsciiEndfDir(fname, data_dir);
}
