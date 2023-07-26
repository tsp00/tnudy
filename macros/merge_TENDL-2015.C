// For merging TENDL-2012
{
   gSystem->Load("libNudy");

   const char* data_dir = "../data/download/TENDL-2015";
   const char* fname =    "../data/TENDL-2015.endf";

   TNuLib::MergeAsciiEndfDir(fname, data_dir);
}
