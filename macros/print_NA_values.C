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
   TNuSublib *proj=lib->GetSublib("n");
   
   TNuMat* mat;
   for(proj->ResetCounter(); mat=proj->NextMat();) {
      TNuFile *f6= mat->GetFile(6);
      if (!f6) continue;
        f6->ResetCounter();
        TNuSec06* psec;
        while ((psec=(TNuSec06*) f6->Next())) {
         if(!psec) continue;
         // FILE 6 with MT=mt found
         Int_t na = -1;
         for (Int_t nk=0; nk < psec->GetNK(); nk++) {
            TNuDEpDMu *depdmu= psec->BodyAt(nk);
            assert(depdmu && depdmu->InheritsFrom("TNuDEpDMu"));
            Int_t law= depdmu->GetLAW();
            if (law != 1) continue;
            // TNuDEpDMuContinuum found
            TNuTab3 *tab3= (TNuTab3*) depdmu->BodyAt(0);
            assert(tab3 && tab3->InheritsFrom("TNuTab3"));
            Int_t lang=tab3->GetL1();
            if (lang != 2) continue;
            // KalbachMann found
            for (Int_t n=0; n < tab3->NBodies(); n++) {
               TNuList2KalbachMann *km= (TNuList2KalbachMann*) tab3->BodyAt(n);
               assert(km && km->InheritsFrom("TNuList2KalbachMann"));
               Int_t new_na= km->GetNA();
               if(new_na != na) {
                  na=new_na;
                  printf("na=%d, ZA=%6d, MF=%2d, MT=%3d, nk=%d, n=%d\n", 
                     na, psec->GetZA(), psec->GetMF(), psec->GetMT(), nk, n);
               }
            }
         }
      }
   }
}
