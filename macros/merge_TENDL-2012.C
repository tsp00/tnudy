// For merging TENDL-2012
{
   gSystem->Load("libNudy");

   const char* data_dir = "../data/download/TENDL-2012";
   const char* fname =    "../data/TENDL-2012.endf";

   TNuLib::MergeAsciiEndfDir(fname, data_dir);
}
