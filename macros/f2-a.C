//#include "TNudy.h"
//#include "TNuLib.h"
//#include "TNuSublib.h"
//#include "TNuMat.h"
//#include "TNuSec03.h"

void rr(TNuMat* mat)
{
      if (!mat) return;
      TNuSec03* sec = (TNuSec03*) mat->GetSection(3102);
      if (!sec) return;
      double x1 = sec->XSect(1.e6);
      if (x1 > 0.3) 
          printf(" %-12s :%10.3f\n", mat->GetName(), x1);
}

void f2(int method)
{
   //
   // Searches the materials whose capture cross sections are bigger than 
   // 0.1 mb at En = 1 MeV.
   //

   gSystem->Load("libNudy");
   
   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   TNuSublib *pro=lib->GetSublib("n");
   
   if (method == 0) {
      // ---------------------------- method 1 : making a ROOT::TIter
      TIter mats = pro->MakeIter();
      TNuMat* mat;
      while ((mat = (TNuMat*) mats())) rr(mat);
   } else if (method == 1) {
      // ---------------------------- method 2 : making a TNuIter
      TNuIter mats(pro);
      TNuMat* mat;
      while ((mat = (TNuMat*) mats())) rr(mat);
   } else if (method == 2) {
      // ---------------------------- method 3 : using ResetCounter & Next()
      pro->ResetCounter();
      TNuMat* mat;
      while ((mat = (TNuMat*) pro->Next())) rr(mat);
   } else if (method == 3) {
      // ---------------------------- method 3a: using ResetCounter & NextXXX()
      pro->ResetCounter();
      TNuMat* mat;
      while ((mat = pro->NextMat())) rr(mat);
   } else if (method == 4) {
      // ---------------------------- method 4: using GetSize() & At(i)
printf("4: size=%d\n", pro->GetSize());
TList* list=pro->GetCollection();
printf("4: %p, size2=%d=%d, %s\n", list, list->GetSize(), list->GetEntries(), list ? list->GetName() : "no");
      for (int i = 0; i < pro->GetSize(); i++) {
         TNuMat* mat = (TNuMat*) pro->At(i);
         if (mat) rr(mat);
      }
   } else {
      // ---------------------------- method 5a: using GetEntries() & MatAt(i)
printf("5: entr=%d\n", pro->GetEntries());
TList* list=pro->GetCollection();
printf("5: %p, size2=%d=%d, %s\n", list, list->GetSize(), list->GetEntries(), list ? list->GetName() : "no");
      for (int i = 0; i < pro->GetEntries(); i++) {
         TNuMat* mat = (TNuMat*) pro->At(i);
         if (mat) rr(mat);
      }
   }
}
