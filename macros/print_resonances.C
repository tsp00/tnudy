{
   //
   // print overall statistics of Section 151

   gSystem->Load("libNudy");
   
   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   TNuSublib *proj=lib->GetSublib("n");
   
   TNuMat* mat;
   while ((mat=(TNuMat*) proj->Next())) {
      if (mat->GetLRP() <= 0) continue;
      TNuSec02 *sec= (TNuSec02*) mat->GetSection(2151);
      if (!sec) break;
      //printf("%s : NIS=%2d\n", mat->GetSymbol(), sec->GetNIS());
      printf("%s : NIS=%2d\n", mat->GetZSYNAM(), sec->GetNIS());
      for (Int_t nis = 0; nis < sec->GetNIS(); nis++)
      {
         TNuSubIsotope *iso= (TNuSubIsotope*) sec->BodyAt(nis);
         if (!iso || !iso->InheritsFrom("TNuSubIsotope")) continue;
         for (Int_t ner=0; ner < iso->GetNER(); ner++)
         {
            TNuResonance *reso = (TNuResonance*) iso->BodyAt(ner);
            printf("                       [%12.3f < E < %12.3f] %s\n",
               reso->GetEL(), reso->GetEH(), reso->ClassName());
         }
      }
   }
}
