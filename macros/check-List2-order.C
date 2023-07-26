{
   //
   // Scan all the List2 strutures, and check if they are ascending order.

   gSystem->Load("libNudy");
   
   //TArrayI array;
   std::list<int> array;

   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   TNuSublib *proj;
   TIter nextproj(lib->GetCollection());
   while ((proj=(TNuSublib*) nextproj())) {
      TNuMat* mat;
      TIter nextmat(proj->GetCollection());
      while((mat=(TNuMat*) proj->Next())) {
//mat->What();
         TNuFile *f6 = mat->GetFile(6);
         if (!f6) continue;
         TNuSec06 *sec;
         for(f6->ResetCounter(); sec=(TNuSec06*) f6->Next();) {
            for (int ndep=0; ndep < sec->NBodies(); ndep++) {
               TNuDEpDMu *dep = sec->BodyAt(ndep);
               //if (!dep->InheritsFrom(TNuDEpDMuContinuum)) continue;
               if (!dep->InheritsFrom("TNuDEpDMu")) continue;
               for(int ntab3=0; ntab3 < dep->NBodies(); ntab3++) {
                  TNuTab3 *tab3 = (TNuTab3*) dep->BodyAt(ntab3);
                  if (!tab3->InheritsFrom("TNuTab3")) continue;
                  for (int nlist2=0; nlist2 < tab3->NBodies(); nlist2++) {
                     TNuList2 *list2= (TNuList2*) tab3->BodyAt(nlist2);
                     if (!list2->InheritsFrom("TNuList2")) continue;
                     Bool_t asc = list2->IsAscending();
                     //if(asc) continue;
printf("%s : MT=%3d, %3d-th Dep, %3d-th tab3, %3d-th list2, %3d-steps from  %12.3f to %12.3f: %s\n",
mat->GetProjTargetName(), sec->GetMT(), ndep, ntab3, nlist2,
list2->GetNEP(), list2->GetX(0), list2->GetX(list2->GetNEP()-1),
asc ? "Ascending" : "Decending");
                }
             }
          }
       }
    }
  }
}
