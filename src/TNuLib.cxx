// TNuLib.cxx  =====================================================
// Author: Tae-Sun Park   09/18/09 (revived at Jun 29 12:48:16 2011)

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuLib                                                    //
//                                                                    //
// Set of all the ENDF data that belong to a ENDF library,   //
// ENDF6, ENDF7, JEFF, ...                                   //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TFile.h"

#include "TNuLib.h"
#include "TNuLazyCollection.h"
#include "TROOT.h"

#include "TNuEndfIO.h"
#include "TNudy.h"

#include "TNuSublib.h"
#include "TNuSection.h"
#include "TNuSec01451.h"
#include "TNuFile.h"
#include "TNuMat.h"
#include "TNuLabel.h"

#include "TNuPrinter.h"
#include "TSystem.h"
#include "TSystemDirectory.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuLib)

//______________________________________________________________________________
TNuLib::TNuLib() : TNuLazyCollection(), fNLIB(0), fTNuRootFile(0)
{
   // TNuLib ctor

   gNuLib = this;

   // try to put the pointers for
   // incident neutron particle,
   // the 1st material
   // and section 1, 451.
   if (gNuLib) {
   
      // append this to TNudy::GetListOfLibs() if this is new
      TList *list = TNudy::GetListOfLibs();
      //
      //TNuLib *found = (TNuLib*) list->FindObject(this);
      //if (!found) {
      //   list->Add(this);
      //}
      if (list) {
         list->Add(this);
      } else {
         Error("", "TNudy::GetListOfLibs() is null !!");
      }
   }
}

//______________________________________________________________________________
TNuLib::TNuLib(TFile *target, const Char_t *libName, const Char_t *libTitle)
: TNuLazyCollection(), fNLIB(0), fTNuRootFile(target)
{
   // Create a library (name = libName, title = libTatile)
   // and save it in the TFile *tfile.

   gNuLib = this;

   // first call SetName/Title/Label with null string
   // to ensure that fNameID/fTitleID/fLabelID=0 corresponds to trivial cases
   SetName("");
   SetTitle("");
   SetLabel("");

   SetName(libName);
   SetTitle(libTitle);
}

//______________________________________________________________________________
TNuLib::~TNuLib()
{
   // TNuLib dtor
}

//______________________________________________________________________________
TNuSublib* TNuLib::GetSublib(Int_t nsub) const
{
   // Load TNuSublib
   return (TNuSublib*) GetObjectByNuID(nsub);
}

//______________________________________________________________________________
TNuSublib* TNuLib::GetSublib(const Char_t* proj) const
{
   Int_t nsub;

   static const struct NsubTableStruc {
      Int_t nsub;
      Char_t fullname[32], shortname[8], shortname2[8];
   } nsubTable[] = {
   {    0, "Photonuclear",               "g",     "g"},
   {    3, "Photo-atomic",               "photo", "photoat"},
   {    4, "Radioactive decay",          "decay", "dec"},
   {    5, "Spontenous fission yields",  "s/fpy", "sfy"},
   {    6, "Atomic relaxation",          "ard",   "atom"},
   {   10, "Neutron",                    "n",     "nn"},
   {   11, "Neutron fission yields",     "n/fpy", "nfy"},
   {   12, "Thermal scattering",         "tsl",   "tsl"},
   {   19, "Standards",                  "std",   "std"},
   {  113, "Electro-atomic",             "e",     "e"},
   {10010, "Proton",                     "p",     "p"},
   {10020, "Deuteron",                   "d",     "d"},
   {10030, "Triton",                     "t",     "t"},
   {20030, "3He",                        "he3",   "he3"}
   };

   for (unsigned n=0; n < sizeof(nsubTable)/sizeof(nsubTable[0]); n++) {
      if (!strcasecmp(proj, nsubTable[n].fullname) ||
          !strcasecmp(proj, nsubTable[n].shortname) ||
          !strcasecmp(proj, nsubTable[n].shortname2)) {
             return GetSublib(nsubTable[n].nsub);
          }
   }

   nsub=TNudy::ZAIof(proj);
   return (nsub >= 0) ? GetSublib(nsub) : 0;
}


//______________________________________________________________________________
TNuMat* TNuLib::GetMat(Int_t zai) const
{
   return GetCurSublib() ? GetCurSublib()->GetMat(zai) : 0;
}

//______________________________________________________________________________
TNuMat* TNuLib::GetMat(const Char_t *target) const
{
   return GetCurSublib() ? GetCurSublib()->GetMat(target) : 0;
}

//______________________________________________________________________________
TNuMat* TNuLib::GetMat(const Char_t *projectile, const Char_t *target) const
{
   TNuSublib* proj = GetSublib(projectile);
   return (proj) ? proj->GetMat(target) : 0;
}

//______________________________________________________________________________
Int_t TNuLib::ImportAsciiEndf(const Char_t *asciiEndfFilename)
{
   // Import an ASCII ENDF data file (i.e., ENDF TAPE) into root TFile

   TNuEndfIO src(asciiEndfFilename);
   if (!src.IsEndfTape()) {
      fprintf(stderr, "TNuLib::ImportAsciiEndf: File %s is not an ENDF tape !",
         asciiEndfFilename);
      return 0;
   }

   ImportAsciiEndf(src);
   //Write();
   return 1;
}


//______________________________________________________________________________
Int_t TNuLib::ImportMultipleAsciiEndf(const Char_t *listOfAsciiEndfFilenames)
{
   // Import multiple ASCII ENDF data files into root TFile
   //
   // The file named listOfAsciiEndfFilenames contains the list of
   // ENDF data files to be imported, where the lines that begin with
   // "#" or "!" are for comments and ignored.
   //
   // And it returns the number of the ENDF data files imported.

   FILE *fp = fopen(listOfAsciiEndfFilenames,"r");
   if (!fp) {
      fprintf(stderr,"Error in opening %s\n",listOfAsciiEndfFilenames);
      return 0;
   }

   Int_t nfiles = 0; // number of the ENDF data files imported
   Char_t srcfile[1024];
   while(0 < fscanf(fp,"%s", srcfile)) {
      if (*srcfile=='#' || *srcfile=='!') {
         // comment lines
         Char_t c;
         while((c=fgetc(fp)) && c != '\n' && c != EOF);
         continue;
      }
      nfiles += ImportAsciiEndf(srcfile);
   }
   fclose(fp);
   return nfiles;
}

//______________________________________________________________________________
Int_t TNuLib::ImportAsciiEndfDir(const Char_t *dirname, const char *ext, bool extract_zip)
{
   // Import ASCII ENDF data from a directory.
   // 1. ext is the file extention for the ENDF file, 
   //   assign it "*" (default) to test all the files.
   //   In fact, if the last character is equal to '*',
   //       it tries to test all files.  
   // 2. if extract_zip == kTRUE (default), it expands zipped files
    
   Int_t nfiles = 0;
   Int_t n_ext = (Int_t) strlen(ext);
   bool test_all = (n_ext == 0) || (ext[n_ext-1] == '*');

   static int depth = 0;
   printf("\n\n");
   for (int i=0; i<depth; i++) printf("\t");
   printf("Depth = %d. Entering TNuLib::ImportAsciiEndfDir for dir=%s with ext=%s\n", depth, dirname, ext);
   depth++;
   int nzip = 0;
   TString unzipdir;
   TString cmd;

   TSystemDirectory dir(dirname, dirname);

   TList *files = dir.GetListOfFiles();
   int nnn = 0;
   if (files) {
      files->Sort();
      TSystemFile *file;
      //TString fname;
      TIter next(files);
      while ((file=(TSystemFile*)next())) {
         nnn++;
         TString fname1(file->GetName());
         if (fname1 == "." || fname1 == "..") continue;
         //fname = Form("%s/%s", dirname, file->GetName());
         TString fname(Form("%s/%s", dirname, file->GetName()));
         fname.ReplaceAll("//", "/");
         if (file->IsDirectory()) {
            //ImportAsciiEndfDir(fname.Data(), ext);
            char * new_dir = new char[fname.Length()+1];
            sprintf(new_dir, "%s", fname.Data());
            ImportAsciiEndfDir(new_dir, ext);
         } else {
            if (extract_zip && fname.EndsWith(".zip", TString::kIgnoreCase)) {
               // extract zip file
               if (nzip == 0) {
                  // creating a temp directory for unzip
                  for (int trial = 0; ; trial++) {
                     unzipdir = Form("%s/nudy-tmp-dir-%d", gSystem->TempDirectory(), trial);
                     if (gSystem->mkdir(unzipdir.Data()) == 0) break; // succeeded
                     else if (trial >= 99) {
                        fprintf(stderr, "Error in creating temp directory [%s], we exit !\n\n", unzipdir.Data());
                        return -1;
                     }
                  }
               }
               nzip++;
               cmd = Form("unzip -q \"%s\" -d %s", fname.Data(), unzipdir.Data());
               int ret = gSystem->Exec(cmd.Data());
               if (ret) {
                  fprintf(stderr, "Error in unzipping %s to %s, return value = %d\n", fname.Data(), unzipdir.Data(), ret);
               }
            } else if (test_all || fname.EndsWith(ext, TString::kIgnoreCase)) {
               if (TNuEndfIO::IsEndfTape(fname.Data()))
                  nfiles += ImportAsciiEndf(fname.Data());
            } 
         }
      }
   }
   
   if (nzip > 0) {
      // treat extracted files in the temp directory
      nfiles += ImportAsciiEndfDir(unzipdir.Data(), ext);

      gSystem->Exec(Form("rm -r %s", unzipdir.Data()));
   }
   return nfiles;
}


//______________________________________________________________________________
Int_t TNuLib::MergeAsciiEndfDir(FILE* dest, const Char_t *dirname, const char *ext, bool extract_zip)
{
   // Merge ASCII ENDF data files of an directory into a single ASCII ENDF file.
   // 1. ext is the file extention for the ENDF file, 
   //   assign it "*" (default) to test all the files.
   //   In fact, if the last character is equal to '*',
   //       it tries to test all files.  
   // 2. if extract_zip == kTRUE (default), it expands zipped files
    
   Int_t nfiles = 0;
   Int_t n_ext = (Int_t) strlen(ext);
   bool test_all = (n_ext == 0) || (ext[n_ext-1] == '*');

   static int depth = 0;
   TString tab; // line indent
   for (int i=0; i<depth; i++) tab.Append("\t");
   
   printf("\n\n%sDepth = %d. TNuLib::MergeAsciiEndfDir for dir=%s with ext=%s\n", tab.Data(), depth, dirname, ext);
   depth++;
   int nzip = 0;
   TString unzipdir;
   TString cmd;

   TSystemDirectory dir(dirname, dirname);

   TList *files = dir.GetListOfFiles();
   int nnn = 0;
   if (files) {
      files->Sort();
      TSystemFile *file;
      //TString fname;
      TIter next(files);
      while ((file=(TSystemFile*)next())) {
         nnn++;
         TString fname1(file->GetName());
         if (fname1 == "." || fname1 == "..") continue;
         //fname = Form("%s/%s", dirname, file->GetName());
         TString fname(Form("%s/%s", dirname, file->GetName()));
         fname.ReplaceAll("//", "/");
         if (file->IsDirectory()) {
            char * new_dir = new char[fname.Length()+1];
            sprintf(new_dir, "%s", fname.Data());
            nfiles += MergeAsciiEndfDir(dest, new_dir, ext, extract_zip);
         } else {
            if (extract_zip && fname.EndsWith(".zip", TString::kIgnoreCase)) {
               // extract zip file
               if (nzip == 0) {
                  // creating a temp directory for unzip
                  for (int trial = 0; ; trial++) {
                     unzipdir = Form("%s/nudy-tmp-dir-%d", gSystem->TempDirectory(), trial);
                     if (gSystem->mkdir(unzipdir.Data()) == 0) break; // succeeded
                     else if (trial >= 99) {
                        fprintf(stderr, "Error in creating temp directory [%s], we exit !\n\n", unzipdir.Data());
                        return -1;
                     }
                  }
               }
               nzip++;
               cmd = Form("unzip -q \"%s\" -d %s", fname.Data(), unzipdir.Data());
               int ret = gSystem->Exec(cmd.Data());
               if (ret) {
                  fprintf(stderr, "Error in unzipping %s to %s, return value = %d\n", fname.Data(), unzipdir.Data(), ret);
               }
            } else if (test_all || fname.EndsWith(ext, TString::kIgnoreCase)) {
               if (TNuEndfIO::IsEndfTape(fname.Data())) {
                  TNuEndfIO src(fname.Data());
                  if (src.IsEndfTape()) {
                     src.AppendToEndf(dest);
                     nfiles++;
                     printf("%s%d. merging %s\n", tab.Data(), nfiles, fname.Data());
                  } else {
                     fprintf(stderr, "Error, %s is not an ENDF tape\n\n", fname.Data());
                  }
               }
            } 
         }
      }
   }
   
   if (nzip > 0) {
      // treat extracted files in the temp directory
      nfiles += MergeAsciiEndfDir(dest, unzipdir.Data(), ext, kFALSE);
      gSystem->Exec(Form("rm -r %s", unzipdir.Data()));
   }
   depth--;
   return nfiles;
}

//______________________________________________________________________________
Int_t TNuLib::MergeAsciiEndfDir(const Char_t* dest_name, const Char_t *dirname, const char *ext, bool extract_zip)
{
   // Merge ASCII ENDF data files of an directory into a single ASCII ENDF file.
   // 1. ext is the file extention for the ENDF file, 
   //   assign it "*" (default) to test all the files.
   //   In fact, if the last character is equal to '*',
   //       it tries to test all files.  
   // 2. if extract_zip == kTRUE (default), it expands zipped files

   printf("\nTNuLib::MergeAsciiEndfDir: Merging ENDF ASCII files of %s (ext = %s) into %s, %s checking zip files...\n", 
      dirname, ext, dest_name, extract_zip ? "with" : "without");
   fflush(stderr); fflush(stdout); 
   
   FILE *dest = fopen(dest_name, "w");
   if (!dest) {
      fprintf(stderr, "Error in TNuLib::MergeAsciiEndfDir: Cannot open the file %s\n", dest_name);
      return -1;
   }
   
   Int_t nfiles = MergeAsciiEndfDir(dest, dirname, ext, extract_zip);
   fprintf(dest, "%11.1f%11.1f%11d%11d%11d%11d%4d%2d%3d%5d\n",0.,0., 0,0,0,0, -1,0,0, 0);
   fclose(dest);
   printf("\nTNuLib::MergeAsciiEndfDir: Done. %d ENDF ASCII files have been merged into %s\n\n", nfiles, dest_name);
   fflush(stderr); fflush(stdout); 
   return nfiles;
}

//______________________________________________________________________________
void TNuLib::ImportAsciiEndf(TNuEndfIO& src)
{
   // Import an ASCII ENDF data file (i.e., ENDF TAPE) into root TFile

   fprintf(stdout, "\nTNuLib::ImportAsciiEndf: Importing %s ...\n", src.GetFileName());
   fflush(stdout); fflush(stderr);

   //// set the home directory of this
   //const Char_t *data_base_dir = "__raw_data__";
   //const Char_t *dir;
   ////dir = Form("%s.Data", GetName());
   //dir = GetName();
   
   //gDirectory->cd("/");
   //if(!gDirectory->GetDirectory(data_base_dir)) {
   //   gDirectory->mkdir(data_base_dir, "Directory for TNudy Raw Data");
   //}   
   //gDirectory->cd(data_base_dir);
      
   //if(!gDirectory->GetDirectory(dir)) {
   //   gDirectory->mkdir(dir, Form("Directory for the Raw Data of %s", GetName()));
   //}
   //gDirectory->cd(dir);
   //fHomeDir = Form("/%s/%s", data_base_dir, dir);
   CdToDataDir();

   while (!src.IsTEND())
   {
      TNuMat *pMat = new TNuMat(src, src.GetMAT(), this);

      src.ReadMEND();
      
      //fCurSublib = pMat->GetParentSublib();
      //fCurSublib->Add(pMat);
      SetCurObject(pMat->GetParentSublib());
      GetCurSublib()->Add(pMat);
      //pMat->Delete();
   }
   //src.ReadTEND();
   gDirectory->cd("/");
}

//______________________________________________________________________________
void TNuLib::ImportAsciiEndf(TNuEndfIO& src, TFile *tfile)
{
   // Import the entire of the
   // ASCII ENDF data file (i.e., ENDF TAPE) into root TFile
   //
   //Int_t nmats = 0;

   fTNuRootFile = tfile;

   Info("ImportAsciiEndf", "Begin to read ENDF ASCII data ...");
   Info("\t", "Library Name=%s",        GetName());
   Info("\t", "Library Title=%s",       GetTitle());
   Info("\t", "(target) tfile name=%s", fTNuRootFile->GetName());
   //Info("\t", "(source)        src=%s", src.GetFileName());
   Info("", "----------------------------------------------------------------");

   ImportAsciiEndf(src);

   // saving TNuLib into the TFile
   Write();

   //fTNuRootFile->Close();
   Info("","----------------------------------------------------------------");
   Info("","Creation of %s finished.\n", fTNuRootFile->GetName());
   Info("","----------------------------------------------------------------");
}

//______________________________________________________________________________
void TNuLib::ImportAsciiEndf(TList &filelist, TFile *tfile)
{
   // Import the entire of the
   // ASCII ENDF data file into root TFile

   fTNuRootFile = tfile;

   Info("ImportAsciiEndf", "Begin to read ENDF ASCII data ...");
   Info("\t", "Library Name=%s",        GetName());
   Info("\t", "Library Title=%s",       GetTitle());
   Info("\t", "(target) tfile name=%s", fTNuRootFile->GetName());

   for(Int_t i=0; i<filelist.GetSize();i++){
      TObject *src_path = (TObject*) filelist.At(i);
      TNuEndfIO src(Form("%s",src_path->GetName()));
      ImportAsciiEndf(src);
   }
   // saving TNuLib into the TFile
   Write();
   //fTNuRootFile->Close();
   Info("","----------------------------------------------------------------");
   Info("","Creation of %s finished.\n", fTNuRootFile->GetName());
   Info("","----------------------------------------------------------------");

}

//______________________________________________________________________________
void TNuLib::ls(Option_t* option) const
{
   TNuLazyCollection::ls(option);
/*
   TObject::ls(option);
   cout << endl;
   cout << "Table of TNuSublib (Sub-Library)" << endl;

   TIter next(GetCollection());
   TNuSublib* obj;
   cout << setw(20) << "(TNuSublib) Name" << " : ";
   cout << setw(6) << "NSUB" << " : " << "Title" << endl;
   if (this) {
      while ((obj = (TNuSublib*) next())) {
         cout << setw(20) << obj->GetName() << " : ";
         cout << setw(6) << obj->GetNSUB() << " : " << obj->GetTitle() << endl;
      }
   }
*/
}

//______________________________________________________________________________
void TNuLib::Print(Option_t *opt) const
{
   // print a library data
   TNuLazyCollection::Print(opt);
   TNudy::GetPrinter().PrintEND(-1, 0, 0, 0, "TEND");
}

// --- routines to set/get name/title/label of TNuObject ---
//______________________________________________________________________
const Char_t* TNuLib::GetObjName(UShort_t id) const
{
   // fetch object's name from the table

   // TString str = ((TObjString*) fObjNames[id])->String();
   const Char_t* objName = ((TObjString*)fObjNames[id])->String().Data(); 
   return objName;//str.Data();
}

//______________________________________________________________________
const Char_t* TNuLib::GetObjTitle(UShort_t id) const
{
   // fetch object's title from the table

   //TString str = ((TObjString*) fObjTitles[id])->String();
  const Char_t* objTitle = ((TObjString*) fObjTitles[id])->String().Data();
  return objTitle;
}

//______________________________________________________________________
TNuLabel* TNuLib::GetObjLabel(UShort_t id) const
{
   // fetch object's label from the table
   return (TNuLabel*) fObjLabels[id];
}

//______________________________________________________________________
UShort_t TNuLib::SetObjName(const Char_t* name)
{
   // Assign id corresponding to the name
   // and add the name to the fObjNames if it is new

   TString s = name;
   s.Strip(TString::kBoth);

   Int_t nmax = fObjNames.GetEntries();

   for (Int_t n=0; n < nmax; n++) {
      TString str = ((TObjString*) fObjNames[n])->String();
      if (str.CompareTo(s) == 0) {
         return n;
      }
   }

   // the name is new ...
   //fObjNames.Add(new TObjString(s.Data()));

   TObjString* tostr = new TObjString(s.Data());
   fObjNames.Add(tostr);
   return nmax;
}

//______________________________________________________________________
UShort_t TNuLib::SetObjTitle(const Char_t* title)
{
   // Assign id corresponding to the title
   // and add the title to the fObjTitles if it is new

   TString s = title;
   s.Strip(TString::kBoth);

   Int_t nmax = fObjTitles.GetEntries();
   for (Int_t n=0; n < nmax; n++) {
      TString str = ((TObjString*) fObjTitles[n])->String();
      if (str.CompareTo(s) == 0) {
         return n;
      }
   }

   // the name is new ...
   fObjTitles.Add(new TObjString(s.Data()));
   return nmax;
}

//______________________________________________________________________
UShort_t TNuLib::SetObjLabel(const Char_t* label)
{
   // Assign id corresponding to the "label/title"
   // and add the label/title to the fObjLabels/fObjTitles if they are new}

   const Char_t* slash = strchr(label, '/');
   if (slash) {
      // (slash+1) is the title string
      SetObjTitle(slash + 1);
   }

   // create TNuLabel
   TNuLabel *newlabel = new TNuLabel(label);

   // check if we already have the label in the fObjLabels
   Int_t nmax = fObjLabels.GetEntries();
   for (Int_t n=0; n < nmax; n++) {
      if (newlabel->IsEqualTo((TNuLabel*) fObjLabels[n])) {
         delete newlabel;
         return n;
      }
   }

   // for check
   /*
   fflush(stderr);
   fprintf(stderr,"\nLibLabel: n =%4d, s=[%s]\n", nmax, label);
   TNuLabel *x = newlabel;

      cout << setw(5) << nmax << " : [";
      for (Int_t i=0; i < x->NHeads(); i++)
         cout << setw(11) << x->HeadAt(i);
      cout << "]" << endl;

      if (x->NBodies()) {
         cout << setw(5) << "--> ;" << " : (";
         for (Int_t i=0; i < x->NBodies(); i++)
            cout << setw(11) << x->BodyAt(i);
         cout << ")" << endl;
      }
      if (x->NTails()) {
         cout << setw(5) << "==> &" << " : {";
         for (Int_t i=0; i < x->NTails(); i++)
            cout << setw(11) << x->TailAt(i);
         cout << "}" << endl;
      }
      fflush(stderr);
*/

   // the label is new ...
   fObjLabels.Add(newlabel);
   return nmax;
}

//______________________________________________________________________
void TNuLib::ShowObjNames()
{
   for (Int_t n=0; n < fObjNames.GetEntries(); n++) {
      cout << setw(5) << n << " : [";
      cout << ((TObjString*) fObjNames[n])->String() << "]" << endl;
   }
}

//______________________________________________________________________
void TNuLib::ShowObjTitles()
{
   for (Int_t n=0; n < fObjTitles.GetEntries(); n++) {
      cout << setw(5) << n << " : [";
      cout << ((TObjString*) fObjTitles[n])->String() << "]" << endl;
   }
}

//______________________________________________________________________
void TNuLib::ShowObjLabels()
{
   for (Int_t n=0; n < fObjLabels.GetEntries(); n++) {
      TNuLabel *label = (fObjLabels[n]) ? (TNuLabel*) fObjLabels[n] : 0;

      if (!label) continue;

      cout << setw(5) << n << " : [";
      for (Int_t i=0; i < label->NHeads(); i++)
         cout << setw(11) << label->HeadAt(i);
      cout << "]" << endl;

      if (label->NBodies()) {
         cout << setw(5) << "--> ;" << " : (";
         for (Int_t i=0; i < label->NBodies(); i++)
            cout << setw(11) << label->BodyAt(i);
         cout << ")" << endl;
      }
      if (label->NTails()) {
         cout << setw(5) << "==> &" << " : {";
         for (Int_t i=0; i < label->NTails(); i++)
            cout << setw(11) << label->TailAt(i);
         cout << "}" << endl;
      }
      //cout << ((TNuLabel*) fObjLabels[n])->HeadLabels() << "]" << endl;
   }
}

