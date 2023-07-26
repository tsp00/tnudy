{
   //
   // Plots the yields of products for (z,2n,alpha) of n + Pb208.

   gSystem->Load("libNudy");
   
   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   
   TNuSublib *proj=lib->GetSublib("n");
   TNuMat *mat = proj->GetMat("Pb208");
   TNuSec06 *sec = (TNuSec06*) mat->GetSection(6024);
   sec->What(); 
   
   if (sec) sec->DrawYields();

}
