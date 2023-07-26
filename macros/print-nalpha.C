{
   //
   // Searches the appearence of TNuList2KalbachMann data structure
   // and prints their NA values.
   //
   // The TNuList2KalbachMann data structures reside in
   // TNuSec06 (MF=6)
   //    nk-th TNuDEpDMuContinuum (TNuDEpDmu with LAW=1)
   //       Tab3 with LANG= 2

   gSystem->Load("libNudy");
   
   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   TNuSublib *prj=lib->GetSublib("n");
   
   TNuMat* mat;
   for(prj->ResetCounter(); (mat=prj->NextMat());) {
      double na02, na10;
      TNuFile *f3= mat->GetFile(3);
      if (!f3) continue;
      for (int iii=0; iii< 2; iii++) {
      int mt=107;
      if (iii>0) mt= 22;
      TNuSec03 *s107= (TNuSec03*) f3->GetSection(mt);
      if (s107) {
         double xx[21];
         double xmax=0;
         int jmax=0;
         for (int i=1; i < 21; i++) {
            xx[i]= s107->XSect(((double) i) * 1.e6);
            if (xx[i] > xmax) {xmax= xx[i]; jmax=i;}
         }
         if (xmax > 0.1) {
            printf("%3d:: %13s, x[%3d]=%12.3f : ", mt, mat->GetName(), jmax, xmax);
            //for (int i=1; i < 21; i++) printf(" x[%3d]=%6.3f", i, xx[i]);
            for (int i=1; i < 21; i++) printf(" %6.3f", xx[i]);
            printf("\n");        
         //na02= s107->XSect(2.e6);
         //na10= s107->XSect(10.e6);
         //if (na02 >= 0.1 || na10 > 0.1) {
         //         printf("%15s, na(2)=%12.3f, na(10)=%12.3f, Z=%6d, A= %6d, ZAI=%d, %s\n",
         //            mat->GetName(), na02, na10, mat->GetZ(), mat->GetA(), mat->GetZAI(), mat->GetName());

         }
      } 
   }
}
}
