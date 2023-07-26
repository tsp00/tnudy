// For merging ENDF-B-VII.1
void merger()
{
   gSystem->Load("libNudy");

   printf("Type in the data_dir and the target filename(???.endf)\n"); 
   std::string data_dir, fname;
   std::cout << "Type-in the data directory: ";
   std::getline(std::cin, data_dir);
   std::cout << "Type-in the target filename(???.endf)data directory: ";
   std::getline(std::cin, data_dir);
   
   cin > 
   const char* data_dir = "../data/download/ENDF-B-VII.1";
   const char* fname =    "../data/ENDF-B-VII.1.endf";

   TNuLib::MergeAsciiEndfDir(fname, data_dir);
}
