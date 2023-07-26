{
   //
   // Searches the appearence of TNuList2KalbachMann data structure
   // and prints their NA values.
   //
   // The TNuList2KalbachMann data structures reside in
   // TNuSec06 (MF=6)
   //    nk-th TNuDEpDMuContinuum (TNuDEpDmu with LAW=1)
   //       Tab3 with LANG= 2

   gSystem->Load("libRIO");
   gSystem->Load("libHist");
   gSystem->Load("libNudy");
   
   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   
   TNuSublib *pro=lib->GetSublib("n");
   
   TNuMat* mat;
   //TIter mats_iter(pro->GetMatList());
   //while (mat=(TNuMat*) mats_iter.Next()) {
   //   TNuFile *f6= mat->GetFile(6);
   //pro->FEchMat() SetGlobal(); TIter _NAME1_(mats_iter)(gNuSublib->GetMatList());  while (gNuMat = (TNuMat*) _NAME1_(mats_iter).Next())

// pro->SetGlobal();
   // TIter mats_iter(gNuSublib->GetMatList());
   //while (mat = (TNuMat*) mats_iter.Next()) {
   while ((mat = (TNuMat*) pro->Next())) {
      TNuFile *f3= mat->GetFile(3);
      if (!f3) continue;
      TNuSec03* sec = (TNuSec03*) f3->GetSection(3102);
      if (!sec) continue;
      double x1 = sec->XSect(1.e6);
      double x10 = sec->XSect(1.e7);
      if (x1 > 0.01 || x10 > 0.01) 
          printf("%12s : %e %e \n", mat->GetName(), x1, x10);
   }
}
