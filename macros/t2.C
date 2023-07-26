{
   //
   // Searches the materials whose capture cross sections are bigger than 
   // 0.1 mb at En = 1 MeV.
   //

   gSystem->Load("libNudy");
   
   TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");
   TNuSublib *pro=lib->GetSublib("n");
   
// ---------------------------------- method 1 : making a ROOT::TIter
//   TIter mats = pro->MakeIter();
//   TNuMat* mat;
//   while ((mat = (TNuMat*) mats())) {
//
// ---------------------------------- method 2 : making a TNuIter
   TNuIter mats(pro);
   while (TNuMat* mat = (TNuMat*) mats()) {
//
// ---------------------------------- method 3 : using ResetCounter & Next()
//   pro->ResetCounter();
//   TNuMat* mat;
//   while ((mat = (TNuMat*) pro->Next())) {
//
// ---------------------------------- method 3a: using ResetCounter & NextXXX()
//   pro->ResetCounter();
//   //TNuMat* mat;
//   while ((TNuMat* mat = pro->NextMat())) {
//
// ---------------------------------- method 4: using GetSize() & At(i)
//   for (int i = 0; i < pro->GetSize(); i++) {
//      TNuMat* mat = (TNuMat*) pro->At(i);
//      if (!mat) continue;
//
// ---------------------------------- method 4a: using GetSize() & MatAt(i)
//   for (int i = 0; i < pro->GetSize(); i++) {
//      TNuMat* mat = pro->MatAt(i);
//      if (!mat) continue;
//
// ---------------------------------- method 5a: using GetEntries() & MatAt(i)
//   for (int i = 0; i < pro->GetEntries(); i++) {
//      TNuMat* mat = pro->MatAt(i);
//
      TNuSec03* sec = (TNuSec03*) mat->GetSection(3102);
      if (!sec) continue;
      double x1 = sec->XSect(1.e6);
      if (x1 > 0.1) 
          printf(" %-12s :%10.3f\n", mat->GetName(), x1);
   }
}
