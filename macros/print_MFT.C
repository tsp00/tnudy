{
   //
   // Print existing values of MF and MT, scanning all the data of the library

   gSystem->Load("libNudy");
   
   //TArrayI array;
   std::list<int> array;

   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   lib->ResetCounter();
   TNuSublib *proj;
   while ((proj=lib->NextSublib())) {
      proj->ResetCounter();
      TNuMat* mat;
      for(; mat=proj->NextMat();) {
         mat->ResetCounter();
         TNuFile *f1;
         for(; f1=mat->NextFile();) {
            Int_t mf=f1->GetMF();
            for (Int_t i=0; i < f1->GetEntries(); i++) {
               mt=f1->GetMTAt(i);
               array.push_back(1000*mf+ mt);
            }
         }
      }
   }
   array.sort();
   array.unique();
   std::list<int>::iterator iter;
   for (iter= array.begin(); iter != array.end(); iter++) {
     Int_t mft= *iter;
     printf("MF=%2d, MT=%3d\n", mft/1000, mft %1000); 
   }
}
