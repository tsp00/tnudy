// For merging JENDL-4.0u
{
   gSystem->Load("libNudy");

   const char* data_dir = "../data/download/JENDL-4.0u";
   const char* fname =    "../data/JENDL-4.0u.endf";

   TNuLib::MergeAsciiEndfDir(fname, data_dir);
}
