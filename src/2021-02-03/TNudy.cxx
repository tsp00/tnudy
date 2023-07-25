// TNudy.cxx  =====================================================
// Author: Tae-Sun Park   09/18/09 (revived at Jun 29 12:48:16 2011)

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNudy                                                           //
//                                                                           //
// The master rootT class of the TNudy (rooT NUclear Data librarY) //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNudy.h"

#include "TROOT.h"
#include "TFile.h"
#include "TKey.h"

#include "TNuEndfIO.h"

#include "TNuLib.h"
#include "TNuSublib.h"
#include "TNuSection.h"
//#include "TNuSec01451.h"
#include "TNuFile.h"
#include "TNuMat.h"
//#include "TNuLabel.h"
#include "TNuObject.h"

#include "TList.h"
#include "TNuPrinter.h"
#include "TNuCanvasPrinter.h"

#include "TBrowser.h"
#include "TRootBrowser.h"
#include "TGTab.h"

//#include "TObjArray.h"

#include <iostream>
#include <iomanip>

Bool_t TNudy::fNeedsCanvasCleared = kTRUE;   //

//NamespaceImp(TNudy)
ClassImp(TNudy)

TList         gNuListOfLibs;     //! TList of TNuLibs
TNuLib        *gNuLib = 0;      //! pointer to current TNuLib
TNuObject     *gNuObject = 0;   //! pointer to current TNuObject

Bool_t TNudy::fPrintType=kFALSE;


//______________________________________________________________________________
TNuLib* TNudy::LoadRootFile(const Char_t *filename)
{
   // Read TNudy from given in the TFile tfile.

   TFile *tfile = new TFile(filename);
   return LoadRootFile(tfile);
}
   
//______________________________________________________________________________
TNuLib* TNudy::LoadRootFile(TFile *tfile)
{
   // Read TNudy from given in the TFile tfile.

   if (!tfile || tfile->IsZombie()) {
      //Error("TNudy::LoadRootFile","TFile is either NULL or a Zombie");
      return 0;
   }

   // the library should reside in the root directory of tfile
   tfile->cd();
   TIter next(tfile->GetListOfKeys());
   
   TKey *key;
   while ((key = (TKey*) next())) {
      if (strcmp(key->GetClassName(), "TNuLib")==0) {
         TNuLib *lib = (TNuLib*) key->ReadObj();
         if (lib) {
            printf("Loading %s: %s\n", lib->GetName(), lib->GetTitle());
            lib->SetTFile(tfile);
            gNuLib = lib;
         } else {
            printf("Oops, error in loading %s: %s\n", key->GetClassName(), key->GetName());
         } 
      } else {
         if (strcmp(key->GetName(), "__raw_data__")) {
            // generate warning if it is not the raw-data directory, "__raw_data__"
            printf ("Skipping %s: %s\n", key->GetClassName(), key->GetName());
         }
      }
   } 
   
   return gNuLib;
}

//______________________________________________________________________________
TList*  TNudy::GetListOfLibs()
{
   return &gNuListOfLibs;
}

//______________________________________________________________________________
Int_t TNudy::GetEntries()
{
   return gNuListOfLibs.GetEntries();
}
   
//______________________________________________________________________________
void TNudy::ShowLibs()
{
   // shows the loaded libs

   TIter next(GetListOfLibs());   
   TNuLib *lib;
   for (Int_t n = 0; (lib = (TNuLib*) next()); n++) {
      printf("%d. %s: %s\n", n, lib->GetName(), lib->GetTitle());
   }
}


//______________________________________________________________________________
TNuLib* TNudy::FindLib(const Char_t *libname)
{
   // load TNuLib by its name

   TNuLib *lib = (TNuLib*) GetListOfLibs()->FindObject(libname);
   if (lib) gNuLib = lib;
   return lib;
}

//______________________________________________________________________________
TNuLib* TNudy::GetLibAt(Int_t lib_pos)
{
   // load TNuLib by its position (index)
   
   Int_t idx = lib_pos;
   if (idx < 0) idx = GetListOfLibs()->GetSize() - lib_pos;

   TNuLib *lib = (TNuLib*) GetListOfLibs()->At(idx);   
   if (lib) {
      gNuLib = lib;
      TFile* tfile = lib->GetTFile();
      if (tfile) {
         tfile->cd();
      }
   }
   return lib;
}

//______________________________________________________________________________
TNuLib* TNudy::OpenLib(TFile *tfile, const Char_t* libName)
{
   // Read TNudy from given in the TFile tfile.

   if (!tfile || tfile->IsZombie()) {
      //Error("TNudy::TNudy","TFile is either NULL or a Zombie");
      return 0;
   }

   gNuLib = 0;
   
   // the library should reside in the root directory of tfile
   tfile->cd("/");
   TNuLib *lib;

   printf("OpenLib()::libName:%s, gDir:%p\n", libName, gDirectory);
   //lib = (TNuLib*) gDirectory->Get(Form("%s.Data", libName));
   gDirectory->GetObject(libName, lib);
   //fTFile = tfile;

   printf("OpenLib()::TNuLib:%p, gNuLib:%p\n",lib, gNuLib);

   return lib;
}

//______________________________________________________________________________
TNuPrinter& TNudy::GetPrinter()
{
   return (fPrintType) ? TNuCanvasPrinter::GetInstance() : TNuPrinter::GetInstance();
}

//______________________________________________________________________________
TNuLib* TNudy::ImportAsciiEndf(const Char_t *libName, const Char_t *libTitle,
              const Char_t *asciiEndfFilename, TFile *tfile)
{
   // Create a library (name = libName, title = libTatile)
   // and save it in the TFile *tfile.

   TNuLib *lib = new TNuLib(tfile, libName, libTitle);

   lib->ImportAsciiEndf(asciiEndfFilename);

   // All done.
   return lib;
}

//______________________________________________________________________________
TNuLib* TNudy::ImportAsciiEndf(const Char_t *libName, const Char_t *libTitle,
              TList &filelist, TFile *tfile)
{
   // Create a library (name = libName, title = libTatile)
   // and save it in the TFile *tfile.

   TNuLib *lib = new TNuLib(tfile, libName, libTitle);

   lib->ImportAsciiEndf(filelist, tfile);

   // All done.
   return lib;
}

//______________________________________________________________________________
void TNudy::ls(Option_t* /*option*/)
{
   // prints the status of global variables
   using namespace std;

   cout << "gNuLib     = ";
   if (gNuLib)
      cout << gNuLib->GetName() << " : " << gNuLib->GetTitle() << " at " << gNuLib << endl;
   else
      cout << "0x0" << endl;
}


//______________________________________________________________________________
Int_t TNudy::ZAof(const char* isotope)
{
   //   return the ZA value of the isotope
   //   return -1 on failure
   
   Int_t iso;
   return ZAof(isotope, iso);
}

//______________________________________________________________________________
Int_t TNudy::ZAof(const char* isotope, Int_t& iso)
{
   //   return the ZA value of the isotope and set the value of iso,
   //   return -1 on failure

   iso = 0;
   Int_t i,j,z1=0,z=0,a=0;
   const Int_t max_char=20;
   Char_t c, src[max_char+1], *s, *name, *name_end;

   for (i=j=0; (c=isotope[i]) && j<max_char ; i++) {
      if (isalnum(c)) src[j++]=tolower(c);
      else if (c!='-' && c!='_' && c!=' ') {
         fprintf(stderr,"Error in ZAof, invalid chars %s\n",isotope);
         return -1;
      }
   }
   src[j]=0;
   if (c) {
      fprintf(stderr,"Too long isotope name, %s\n",isotope);
      return -1;
   }

   s=src;
   if(!strcmp(s,"p") || !strcmp(s,"proton"))
      return 1001;
   else if(!strcmp(s,"d") || !strcmp(s,"deuteron"))
      return 1002;
   else if(!strcmp(s,"t") || !strcmp(s,"triton"))
      return 1003;
   else if(!strcmp(s,"a") || !strcmp(s,"alpha"))
      return 2004;
   else if(!strcmp(s,"n") || !strcmp(s,"nn")|| !strcmp(s,"neutron"))
      return 1;
   else if(!strcmp(s,"g") || !strcmp(s,"gam")||!strcmp(s,"gamma"))
      return 0;

   z1=0;
   while (isdigit(*s)) z1= 10*z1 + *s++ - '0';

   name=s;
   while (isalpha(*s)) s++;
   name_end=s;

   a=0;
   while (isdigit(*s)) a= 10*a + *s++ - '0';
   *name_end=0;

   if (*s=='m') {
      s++;
      if (!*s) iso=1;
      else if (isdigit(*s)) iso= *s++ - '0';
      else {
         fprintf(stderr,"Error in ZAof, %s\n",isotope);
         return -1;
      }
   }

   if (*s) {
      if (*s=='g') iso=0;
      else iso=*s - 'm' + 1;
      s++;
      if (iso < 0 || iso > 9 || *s) {
         fprintf(stderr,"Error in ZAof, invalid ends %s, %s\n",isotope,s);
         return -1;
      }
   }

   UInt_t imax = sizeof(kChemicalSymbols)/sizeof(kChemicalSymbols[0]);
   for(i=0; (unsigned) i< imax; i++) {
      if (strcasecmp(name,kChemicalSymbols[i])==0) {
         //z=i+1;
         z=i;
         if (z1 && z && a && (z!=z1)) {
            fprintf(stderr,"Error in ZAof, z1=%d, z[%s]=%d in %s\n",
               z1,name,z,isotope);
            return -1;
         }
         if (a==0 && z!=z1) a=z1;
         return 1000*z+a;
         break;
      }

      if (!strcmp(name,"d") && (z1==1 || a==2)) return 1002;
      else if ((!strcmp(name,"t")) && (z1==1 || a==3)) return 1003;
   }
   fprintf(stderr,"Unknown Error in ZAIof, %s, z=%d, z1=%d, a=%d\n",isotope,z,z1,a);
   return -1;
}

//______________________________________________________________________________
Int_t TNudy::ZAIof(const char* isotope)
{
   //   return the ZAI value of the isotope
   //   return -1 on failure

/*
   Int_t i,j,z1=0,z=0,a=0,zai=0,iso=0;
   const Int_t max_char=20;
   Char_t c, src[max_char+1], *s, *name, *name_end;

   for (i=j=0; (c=isotope[i]) && j<max_char ; i++) {
      if (isalnum(c)) src[j++]=tolower(c);
      else if (c!='-' && c!='_' && c!=' ') {
         fprintf(stderr,"Error in ZAIof, invalid chars %s\n",isotope);
         return -1;
      }
   }
   src[j]=0;
   if (c) {
      fprintf(stderr,"Too long isotope name, %s\n",isotope);
      return -1;
   }

   s=src;
   if(!strcmp(s,"p") || !strcmp(s,"proton"))
      return zai=10010;
   else if(!strcmp(s,"d") || !strcmp(s,"deuteron"))
      return zai=10020;
   else if(!strcmp(s,"t") || !strcmp(s,"triton"))
      return zai=10030;
   else if(!strcmp(s,"n") || !strcmp(s,"nn")|| !strcmp(s,"neutron"))
      return zai= 10;
   else if(!strcmp(s,"g") || !strcmp(s,"gam")||!strcmp(s,"gamma"))
      return zai= 0;

   z1=0;
   while (isdigit(*s)) z1= 10*z1 + *s++ - '0';

   name=s;
   while (isalpha(*s)) s++;
   name_end=s;

   a=0;
   while (isdigit(*s)) a= 10*a + *s++ - '0';
   *name_end=0;

   if (*s=='m') {
      s++;
      if (!*s) iso=1;
      else if (isdigit(*s)) iso= *s++ - '0';
      else {
         fprintf(stderr,"Error in ZAIof, %s\n",isotope);
         return -1;
      }
   }

   if (*s) {
      if (*s=='g') iso=0;
      else iso=*s - 'm' + 1;
      s++;
      if (iso < 0 || iso > 9 || *s) {
         fprintf(stderr,"Error in ZAIof, invalid ends %s, %s\n",isotope,s);
         return -1;
      }
   }

   UInt_t imax = sizeof(kChemicalSymbols)/sizeof(kChemicalSymbols[0]);
   for(i=0; (unsigned) i< imax; i++) {
      if (strcasecmp(name,kChemicalSymbols[i])==0) {
         //z=i+1;
         z=i;
         if (z1 && z && a && (z!=z1)) {
            fprintf(stderr,"Error in ZAIof, z1=%d, z[%s]=%d in %s\n",
               z1,name,z,isotope);
            return -1;
         }
         if (a==0 && z!=z1) a=z1;
         return zai=10*(1000*z+a) + iso;
         break;
      }

      if (!strcmp(name,"d") && (z1==1 || a==2)) return zai=10*(1002);
      else if ((!strcmp(name,"t")) && (z1==1 || a==3)) return zai=10*(1003);
   }
   fprintf(stderr,"Unknown Error in ZAIof, %s, z=%d, z1=%d, a=%d\n",isotope,z,z1,a);
   return -1;
*/
   Int_t za, iso;
   za = ZAof(isotope, iso);
   return (za < 0) ? za : 10 * za + iso; 
}

//______________________________________________________________________________
TBrowser* TNudy::GetBrowser()
{
   // create and return TBrowser with some decorations
    
   TBrowser *b;

   //b = (TBrowser*) gROOT->GetListOfBrowsers()->FindObject("TNudyBrowser");
   //if (b) return b;

   b = new TBrowser("TNudyBrowser", "TNudy Object Browser");
   if (!b) return b;

   //remove Editor tab
   TRootBrowser *bimp = (TRootBrowser*) b->GetBrowserImp();
   if (!bimp) return b;

   TGTab *btab = bimp->GetTab(1);  //Right TGTab
   if (!btab) return b;

   for(int i=0; i < btab->GetNumberOfTabs(); i++) {
      TString tab_name = btab->GetTabTab(i)->GetString();
      if(tab_name.BeginsWith("Editor")) {
         btab->RemoveTab(i);
      }
   }
   return b;
}


//______________________________________________________________________________
TCanvas* TNudy::GetCanvas()
{
   //TCanvas *c1 = (TCanvas*)(gROOT->GetListOfCanvases())->FindObject("Canvas 1");
   TCanvas *c1 = (TCanvas*) gROOT->GetListOfCanvases()->At(0);
   if (!c1) c1 = gROOT->MakeDefCanvas();
   if (NeedsCanvasCleared()) {
      c1->Clear();
      NeedsCanvasCleared(kFALSE);
   }
   return c1;
}

