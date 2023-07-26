// For merging IRDFF-v1.05
{
   gSystem->Load("libNudy");

   const char* data_dir = "../data/download/IRDFF-v1.05";
   const char* fname =    "../data/IRDFF-v1.05.endf";

   TNuLib::MergeAsciiEndfDir(fname, data_dir);
}
