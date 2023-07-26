{
   //
   // It prints the fission product yields and plot using TH2D

   gSystem->Load("libNudy");
   
   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   
   TNuSublib *proj=lib->GetSublib("nfy");
   TNuMat *mat = proj->First();
   TNuSec08454 *sec = mat->GetSection(8454);
   TNuListFPY *fpy = (TNuListFPY*) sec->BodyFirst();
   fpy->What(); 
   
   // default plot, Y(N, Z)
   // For relevant options, "COLZ", "LEGO", "LEGO2", "BOX"
   fpy->PlotFPY("lego2");

   //
   //TH2D *h2 = fpy->GetTH2D();
   
}
