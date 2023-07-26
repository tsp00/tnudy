{
   //
   // Print existing values of MF and MT, scanning all the data of the library

   gSystem->Load("libNudy");
   
   //TArrayI array;
   //std::list<int> array;

   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   TNuSublib *proj = lib->GetSublib("n");
fprintf(stderr, "p =%s\n", proj->GetName()); fflush(stderr);
   proj->ResetCounter();
   for(TNuMat* mat; mat=proj->NextMat();) {
      mat->ResetCounter();
      TNuFile *f33 = mat->GetFile(33);
      if (f33) {
         TNuSec33 *s33;
f33->Touch();
         TIter nextsec(f33->GetCollection());
         while ((s33 = (TNuSec33*) nextsec())) {
            //TNuCovMatrix *cm = dynamic_cast<TNuCovMatrix*>(s33->HeadCont());
            TNuCovMatrix *cm = s33->GetCovMatrix();
            if (!cm) { fprintf(stderr, "null Cov Matrix for i=%d, ZAI=%d\n", 
                i, mat->GetZAI()); continue; }
            for (Int_t nl=0;  nl< cm->GetNL(); nl++) {
                //TNuContListsCov33* c33= cm->GetSingleCovMatrix(nl);
                TNuContListsCov33* c33= (TNuContListsCov33*) cm->BodyAt(nl);
            if (!c33) { fprintf(stderr, "null c33 for nl=%d/%d, ZAI=%d\n", 
                nl, cm->GetNL(), mat->GetZAI()); continue; }
                int nc = c33->GetNC();
                if (nc > 0) {
fprintf(stderr, "\nm =%s\n", mat->GetName()); fflush(stderr);
fprintf(stderr, "s33 =%s, ", s33->GetName()); fflush(stderr);
fprintf(stderr, "cm =%s, %s, ", cm->GetName(), cm->ClassName()); fflush(stderr);
fprintf(stderr, "nc=%d, c33 =%s\n", nc, c33->GetName()); fflush(stderr);
c33->HeadCont()->Print();
                   for (int n=0; n < nc; n++) {
                      //TNuContListNC* c = c33->GetContListNCAt(n);
                      //TNuContListNC* c = dynamic_cast<TNuContListNC*>(c33->GetContListNCAt(n));
                      //TNuContListNC* c = (TNuContListNC*)(c33->GetContListNCAt(n+1));
                      TNuContListNC* c = (TNuContListNC*)c33->At(n+1);
fprintf(stderr, "n=%d/%d, c =%s\n", n, nc, c ? c->ClassName() : "xx"); fflush(stderr);
                      if (c) c->Print();
                      //if (c && c->GetLTY()) c->Print();
                   }
                }
            }
         }
      }
   }
}
