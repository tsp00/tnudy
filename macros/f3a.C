#include "TNudy.h"
#include "TNuLib.h"
#include "TNuSublib.h"
#include "TNuMat.h"
#include "TNuSec03.h"

void run(TNuMat* mat)
{
   if (!mat) return;
   TNuSec03* sec = (TNuSec03*) mat->GetSection(3102);
   if (!sec) return;
   double x1 = sec->XSect(1.e6);
   if (x1 > 0.3) printf(" %-12s :%10.3f\n", mat->GetName(), x1);
}

void find_big_capture(int method)
{
   // Searches the materials whose capture cross sections are bigger than 
   // 0.3 mb at En = 1 MeV.

   //gSystem->Load("libNudy");
   
   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   TNuSublib *sub=lib->GetSublib("n");
   
   if (method == 0) {
      return;
   } else if (method == 1) {
      // method 1 : making a ROOT::TIter with MakeIter()
      TIter mats = sub->MakeIter();
      TNuMat* mat;
      while ((mat = (TNuMat*) mats())) run(mat);
   } else if (method == 2) {
      // method 2 : making a TNuIter
      TNuIter mats(sub);
      TNuMat* mat;
      while ((mat = (TNuMat*) mats())) run(mat);
   } else if (method == 3) {
      // method 3 : using ResetCounter() & Next()
      sub->ResetCounter();
      TNuMat* mat;
      while ((mat = (TNuMat*) sub->Next())) run(mat);
   } else if (method == 4) {
      // method 4: using ResetCounter & NextXXX()
      sub->ResetCounter();
      TNuMat* mat;
      while ((mat = sub->NextMat())) run(mat);
   } else if (method == 5) {
      // method 5: using GetSize() & At(i)
      for (int i = 0; i < sub->GetSize(); i++) {
         TNuMat* mat = (TNuMat*) sub->At(i);
         if (mat) run(mat);
      }
   } else {
      // method 6: using GetEntries() & At(i)
      for (int i = 0; i < sub->GetEntries(); i++) {
         TNuMat* mat = (TNuMat*) sub->At(i);
         if (mat) run(mat);
      }
   }
}
