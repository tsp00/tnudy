// TNuMat.cxx  =====================================================
// Author: Tae-Sun Park   Jun 22 2011

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuMat (default class for a section data)                          //
//                                                                    //
// TNuMat.cxx:                                                        //
// Routine to handle a single ENDF Section                            //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuMat.h"

#include "TROOT.h"

#include "TObjString.h"
//#include "TObject.h"

#include "TNudy.h"
#include "TNuLib.h"
#include "TNuEndfIO.h"
#include "TNuSec01451.h"
#include "TNuSection.h"
#include "TNuTab1.h"
#include "TNuListTaylor.h"
#include "TNuFile.h"
#include "TNuProject.h"

// for pghysics
#include "TNuSec01.h"
#include "TNuSec03.h"
#include "TNuSec04.h"
#include "TNuSec05.h"

#include "TNuPrinter.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuMat)

//______________________________________________________________________________
TNuMat::TNuMat(Int_t mat) : TNuLazyCollection(), fMAT(mat)
{
   // TNuMat ctor
}

//______________________________________________________________________________
TNuMat::~TNuMat()
{
   // TNuMat dtor

}


//______________________________________________________________________________
void TNuMat::What() const
{
   TNuObject::What();
   const Char_t* s;
   cout << "Params" << endl;
   cout << "\tZAI    = " << GetZAI()    << " : 10 * (1000*Z + A) + LISO" << endl;
   cout << "\tMAT    = " << GetMAT()    << " : Material identifier, 100*Z + I" << endl;
   cout << "\tZA     = " << GetZA()     << " : 1000*Z + A, Z = " << GetZ() << ", A = " << GetA() << endl;
   cout << "\tAWR    = " << GetAWR()    << " : Ratio of mass of the material to that of the neutron" << endl;
   s= fLRP ==-1 ? "no File 2 is given (not allowed for incident neutrons)" :
      fLRP == 0 ? "no resonance parameter data are given, but a File 2 is present containing the effective scattering radius" :
      fLRP == 1 ? "resolved and/or unresolved parameter data are given in File 2 and cross sections computed from them must be added" :
      fLRP == 2 ? "parameters are given in File 2, but cross sections derived from them are not to be added to the cross sections in File 3" :
      "Un-documented";
   cout << "\tLRP    = " << GetLRP()    << " : " << s << endl;
   s= fLFI == 1 ? "this material does not fission" :
      fLFI == 2 ? "this material fissions" :
      "Un-documented";
   cout << "\tLFI    = " << GetLFI()    << " : " << s << endl;
   cout << "\tNLIB   = " << GetNLIB()   << " : Library identifier" << endl;
   cout << "\tNMOD   = " << GetNMOD()   << " : Modification number for this material" << endl;
   cout << "\tELIS   = " << GetELIS()   << " : Excitation energy of the target nucleus relative to 0.0 for the ground state" << endl;
   s= fSTA == 0 ? "stable nucleus" :
      fSTA == 1 ? "unstable nucleus" :
      "Un-documented";
   cout << "\tSTA    = " << GetSTA()    << " : " << s << endl;
   cout << "\tLIS    = " << GetLIS()    << " : State number of the target nucleus. The ground state is indicated by LIS=0" << endl;
   cout << "\tLISO   = " << GetLISO()   << " : Isomeric state number. The ground state is indicated by LISO=0" << endl;
   cout << "\tNFOR   = " << GetNFOR()   << " : Library format" << endl;
   cout << "\tAWI    = " << GetAWI()    << " : Mass of the projectile in neutron mass units" << endl;
   cout << "\tEMAX   = " << GetEMAX()   << " : Upper limit of the energy range for evaluation" << endl;
   cout << "\tLREL   = " << GetLREL()   << " : Library release number" << endl;
   cout << "\tNSUB   = " << GetNSUB()   << " : Sub-library number" << endl;
   cout << "\tNVER   = " << GetNVER()   << " : Library version number" << endl;
   cout << "\tTEMP   = " << GetTEMP()   << " : Target temperature (Kelvin)" << endl;
   cout << "\tLDRV   = " << GetLDRV()   << " : Special derived material flag that distinguishes between different evaluations (LDRV=0 for primary evaluation)" << endl;
   cout << "\tNWD    = " << GetNWD()    << " : Number of records with descriptive text for this material" << endl;
   cout << "\tNXC    = " << GetNXC()    << " : Number of records in the directory for this material" << endl;
   cout << "\tZSYNAM = " << GetZSYNAM() << " : Character representation of the material" << endl;
   cout << "\tALAB   = " << GetALAB()   << " : Mnemonic for the originating laboratory(s)" << endl;
   cout << "\tEDATE  = " << GetEDATE()  << " : Date of evaluation" << endl;
   cout << "\tAUTH   = " << GetAUTH()   << " : Author(s)" << endl;
   cout << "\tREF    = " << GetREF()    << " : Primary reference for the evaluation" << endl;
   cout << "\tDDATE  = " << GetDDATE()  << " : Original distribution date" << endl;
   cout << "\tRDATE  = " << GetRDATE()  << " : Date and number of the last revision to this evaluation" << endl;
   cout << "\tENDATE = " << GetENDATE() << " : Master File entry date" << endl;
   cout << "\tHSUB[0]= " << GetHSUB(0)  << endl;
   cout << "\tHSUB[1]= " << GetHSUB(1)  << endl;
   cout << "\tHSUB[2]= " << GetHSUB(2)  << endl;
}

//______________________________________________________________________________
TNuFile* TNuMat::GetFile(Int_t mf) const
{
   // Get TNuFile for the MF value.
   return (TNuFile*) GetObjectByNuID(mf);
}

//______________________________________________________________________________
TNuSection* TNuMat::GetSection(Int_t mft) const
{
   // Get section, mft may be either mf*1000 + mt or mt

   if ((mft >= 1000 && GetFile(mft/1000)) || (mft < 1000 && GetCurFile())) {
      return GetCurFile()->GetSection(mft);
   }
   else return 0;
}

//______________________________________________________________________________
TNuSection* TNuMat::GetSection(Int_t mf, Int_t mt) const
{
   if (GetFile(mf)) {
      return GetCurFile()->GetSection(mt);
      }
   else return 0;
}

//______________________________________________________________________________
TNuMat::TNuMat(TNuEndfIO &src, Int_t mat, TNuLib* lib)
: TNuLazyCollection(), fMAT(mat)
{
   // Read ENDF MAT data from ASCII ENDF file

   if (src.GetMF() != 1 || src.GetMT() != 451) {
      Fatal("TNuMat", "The first section is not 1451, MF=%d, MT=%d",
         src.GetMF(), src.GetMT());
      src.GotoMEND();
      return;
   }

   while (!src.IsMEND())
   {
      //  Import all the data for a given MF value

      Int_t mf = src.GetMF();

      TNuFile *pFile = new TNuFile(mat,mf);
      pFile->SetParent(this);

      while(!src.IsFEND()) 
      {
         // Import all the data for a given MT value

         Int_t mt = src.GetMT();
         TNuSection *pSec = 0;

         if (mf ==1 && mt==451) {
            // read MF=1 and MT=451 section
            fMAT = src.GetMAT();
            TNuSec01451* pSec1451 = new TNuSec01451(mat,1,451);
            pSec1451->ImportEndfData(src);
            pSec1451->SetName(Form("sec_%02d%03d", mf, mt));

            pSec1451->SetTitle (Form("Descriptive data for MAT=%d", fMAT));
            // initialize 'this' using pSec1451
            Init(pSec1451, lib);
            fprintf(stderr,
               "%-18s: LVRMD=%2d.%2d.%2d.%2d.%2d MAT=%5d ZA=%6d AWR=%8.3f T=%4d\n",
               GetName(),
               GetNLIB(), GetNVER(), GetLREL(), GetNMOD(), GetLDRV(),
               GetMAT(), GetZA(), GetAWR(), (Int_t) (GetTEMP()+0.5));

            //fprintf(stderr,
            //   "LVRMD=%2d.%2d.%2d.%2d.%2d, NSUB=%6d, MAT=%5d, T=%4d, ZA=%6d, AWR=%8.3f, %11s\n",
            //   GetNLIB(), GetNVER(), GetLREL(), GetNMOD(), GetLDRV(),
            //   GetNSUB(), GetMAT(), (Int_t) (GetTEMP()+0.5),
            //   GetZA(), GetAWR(), ChemicalSymbol());

            //Info("\t", "test, dir = %s", gDirectory->GetPath());

            delete pFile;
            pFile = 0;
            pFile = new TNuFile(mat,mf);
            pFile->SetParent(this);
            pSec = pSec1451;
         }
         else {
            // Create TNuSection depending on the mf and mt values
            // and import the ascii ENDF section data

            pSec = TNuSection::CreateSection(src, pFile, mf, mt);
         }

         src.ReadSEND();

         pFile->Init();
         pFile->Add(pSec);
      }


      Add(pFile);
//
      if (!gDirectory->cd(GetPath())) {
         if (!gDirectory->mkdir(GetPath())) {
            fprintf(stderr, "1Error in making %s directory", GetPath());
         } else
            gDirectory->cd(GetPath());

      }
      //const char* dir = pFile->GetPath();
      const char* dir = pFile->GetName();
      gDirectory->mkdir(dir);
      if (!gDirectory->cd(dir)) {
         if (!gDirectory->mkdir(dir)) {
            fprintf(stderr, "\n2Error in making %s directory\n", dir);
         } else
            gDirectory->cd(dir);
      }
//
pFile->SaveContents();
      src.ReadFEND();

   }
   fprintf(stderr,"\n"); // end of importing mat data
SaveContents();
}


//______________________________________________________________________________
void TNuMat::Init(TNuSec01451* pSec1451, TNuLib *lib)
{
   // Initialize TNuMat using the informations given in pSec1451

   // 0th line (HEAD)
   TNuCont *cont;
   //cont = src.ReadCont("   ZA,   AWR,   LRP,   LFI,  NLIB,  NMOD");
   //cont->Scan(           dumf,  fAWR,  fLRP,  fLFI, fNLIB, fNMOD);
   cont = (TNuCont*)pSec1451->HeadAt(0);
   fZA  = (Int_t) cont->GetC1() + 0.5;
   fAWR = cont->GetC2();
   fLRP = cont->GetL1();
   fLFI = cont->GetL2();
   fNLIB= cont->GetN1();
   fNMOD= cont->GetN2();

   // 1st line
   //cont = src.ReadCont(" ELIS,   STA,   LIS,  LISO,     0,  NFOR");
   //cont->Scan(          fELIS,  fSTA,  fLIS, fLISO,  dumi, fNFOR);
   cont = (TNuCont*) pSec1451->HeadAt(1);
   fELIS= cont->GetC1();
   fSTA = (Int_t) cont->GetC2() + 0.5;
   fLIS = cont->GetL1();
   fLISO= cont->GetL2();
   fNFOR= cont->GetN2();
   fZAI = 10*fZA + fLISO;


   // 2nd line
   //cont = src.ReadCont("  AWI,  EMAX,  LREL,     0,  NSUB,  NVER");
   //cont->Scan(           fAWI, fEMAX, fLREL,  dumi, fNSUB, fNVER);
   cont = (TNuCont*) pSec1451->HeadAt(2);
   fAWI = cont->GetC1();
   fEMAX= cont->GetC2();
   fLREL= cont->GetL1();
   fNSUB= cont->GetN1();
   fNVER= cont->GetN2();

   // 3rd line
   //cont = src.ReadCont(" TEMP,   0.0,  LDRV,     0,   NWD,   NXC");
   //cont->Scan(          fTEMP,  dumf, fLDRV,   dumi, fNWD,  fNXC);
   cont = (TNuCont*) pSec1451->HeadAt(3);
   fTEMP = cont->GetC1();
   fLDRV = cont->GetL1();
   fNWD  = cont->GetN1();
   fNXC  = cont->GetN2();

   // 4th line
   const Char_t *text;
   //text = src.ReadTEXT(); //ZSYMAM, ALAB, EDATE, AUTH ]TEXT
   //text = pSec1451->DescriptionAt(0)->String();
   text = pSec1451->DescriptionAt(0);
   strncpy(fZSYNAM, text,   11); fZSYNAM[11]='\0';//  1-11
   strncpy(  fALAB, text+11,11); fALAB[11]='\0';  // 12-22
   strncpy( fEDATE, text+22,10); fEDATE[10]='\0'; // 23-32
   strncpy(  fAUTH, text+33,33); fAUTH[33]='\0';  // 34-66

   // 5th line
   //text = src.ReadTEXT();// REF, DDATE, RDATE, ENDATE ]TEXT
   text = pSec1451->DescriptionAt(1);
   strncpy(   fREF, text+1, 21); fREF[21]='\0';   //  2-22
   strncpy( fDDATE, text+22,10); fDDATE[10]='\0'; // 23-32
   strncpy( fRDATE, text+33,10); fRDATE[10]='\0'; // 34-43
   strncpy(fENDATE, text+55, 8); fENDATE[8]='\0'; // 56-63

   // 6,7,8th line
   //text = src.ReadTEXT();// HSUB[0,1,2]
   text = pSec1451->DescriptionAt(2);
   strncpy(fHSUB[0], text, 66); fHSUB[0][66]='\0';
   text = pSec1451->DescriptionAt(3);
   strncpy(fHSUB[1], text, 66); fHSUB[1][66]='\0';
   text = pSec1451->DescriptionAt(4);
   strncpy(fHSUB[2], text, 66); fHSUB[2][66]='\0';

   // Set default name and title
   SetName(GetProjTargetName("-"));
   SetTitle(Form("%s of %s (NSUB=%d, ZAI=%d, MAT=%d)",
      TNuProject::GetFullName(fNSUB),
      GetDefaultMatName(fZAI),
      fNSUB, fZAI, fMAT));
   //SetName(Form("mat_%s", GetDefaultMatName(fZAI)));
   //SetTitle(Form("%s with NSUB=%d, ZAI=%d, MAT=%d",
      //fZSYNAM, fNSUB, fZAI, fMAT));

   // set the parent sub-library
   TNuProject* fParentProject = 0;
   fParentProject = lib->GetProject(fNSUB);
   SetParent(fParentProject);
   if (!fParentProject) {
      // it this sub-library is new,
      // create one, and register it to the library
      fParentProject = new TNuProject(fNSUB);
      fParentProject->SetParent(lib);
      fParentProject->Init();
      SetParent(fParentProject);
      lib->Add(fParentProject);
   }

   // move to the directory for the sub-library
   gDirectory->cd(lib->GetPath());
   const Char_t *sublibHome = fParentProject->GetName();
   if(!gDirectory->GetDirectory(sublibHome)) {
      gDirectory->mkdir(sublibHome);
   }
   gDirectory->cd(sublibHome);

   // move to the directory for the mat
   const Char_t *home = GetName();
   if(!gDirectory->GetDirectory(home)) {
      gDirectory->mkdir(home);
   }
   gDirectory->cd(home);
   // set current directory as the home directory of the this mat
   fHomeDir = Form("%s/%s/%s", lib->GetPath(), sublibHome, home);
}

//______________________________________________________________________________
void TNuMat::ls(Option_t* option) const
{
   TNuLazyCollection::ls(option);
/*
   TObject::ls(option);
   cout << endl;
   cout << "Table of TNuFiles" << endl;

   //fFiles.ls(option);
   TIter next(GetCollection());
   TNuFile* obj;
   if(this) {
      cout << setw(17) << "Name" << " : MF : Title" << endl;
      while ((obj = (TNuFile*) next())) {
         cout << "(TNuFile) " << setw(7) << obj->GetName() << " : ";
         cout << setw(2)<< obj->GetMF() << " : " << obj->GetTitle() << endl;
      }
   }
*/
}

//______________________________________________________________________________
void TNuMat::Print(Option_t *opt) const
{
   // print a mat data
   TNuLazyCollection::Print(opt);
   TNudy::GetPrinter().PrintEND(0, 0, 0, 0, "MEND");
}

//______________________________________________________________________________
const Char_t* TNuMat::GetDefaultMatName(Int_t zai, Option_t* opt)
{
   // static routine to obtain mat's name from the ZAI value

   const struct {
      Int_t mat;
      const Char_t* endfname; // the name found in the ENDF data
      const Char_t* name;     // the name given in the manual
   } compounds[] = {
      { 1, "H(H2O)",   "Water"},
      { 2, "para-H",   "Para-H"},
      { 3, "ortho-H",  "Ortho-H"},
      { 7, "H(ZrH)",   "H(ZrH)"},
      { 8, "H(Cah2)",  "H(Cah2)"},
      {11, "D(D2O)",   "Heavy Water"},
      {12, "para-d",   "Para-d"},
      {13, "ortho-d",  "Ortho-d"},
      {26, "Be metal", "Be"},
      {27, "O(BeO)",   "BeO"},
      {28, "Be2C",     "Be2C"},// {28, "O(BeO)",   "BeO"}, // which one is correct ??
      {29, "Be(BeO)",  "Be(BeO)"},
      {31, "Graphite", "Graphite"},
      {33, "l-CH4",    "Liquid Methane"},
      {34, "s-CH4",    "Solid Methane"},
      {37, "H(CH2)",   "Polyethylene"},
      {40, "BENZINE",  "Benzene"},
      {46, "O(BeO)",   "O(BeO)"},
      {47, "SiO2",     "SiO2"},//from ENDF-B-VII.1 data file (2011-12-19)
      {48, "U(UO2)",   "U(UO2)"},//from ENDF-B-VII.1 data file (2011-12-19), what is the 76?
      {52, "24-Mg",    "Mg"},
      {53, "27-Al",    "Al"},//from ENDF-B-VII.1 data file (2011-12-19)
      {56, "56-Fe",    "Fe"},//from ENDF-B-VII.1 data file (2011-12-19)
      {58, "Zr(ZrH)",  "Zr(ZrH)"},
      {59, "Ca(CaH2)", "Ca(CaH2)"},
      {75, "O(UO2)",   "UO2"},
      {76, "U(UO2)",   "UC"},
      { 0, "Unknown",  "Unknown"}
      };


   if (zai >1000 && zai < 2000 && (zai%10) == 0) {
      // these are ZAI numbers for compounds
      Int_t mat = (zai - 1000) / 10;
      Int_t m;
      for (Int_t n=0; (m = compounds[n].mat) != 0; n++) {
         if (m == mat) {
            if (opt && opt[0]) return compounds[n].endfname;
            else               return compounds[n].name;
         }
      }
      cerr << "Warning in TNuMat::GetDefaultMatName : " <<
              "Unrecognized ZAI =" << zai << " or MAT =" << mat << endl;
      cerr << "We name it as " << Form("MAT_%d", mat) << endl;
      return Form("MAT_%d", mat);
   }

   // zai = 10*(1000*z + a) + i
   Int_t z = zai / 10000;
   Int_t a = (zai / 10) % 1000;
   Int_t i = zai % 10;

   Int_t zmax = (Int_t) sizeof(kChemicalSymbols)/sizeof(kChemicalSymbols[0]);
   const Char_t* symbol;
   if (z>=0 && z < zmax) symbol = kChemicalSymbols[z];
   else symbol = Form("Z%d", z);
   if (zai == 0) symbol = "g";

   const Char_t* iso;
   if (i==0) iso = "";
   else if (i==1) iso = "M";
   else iso = Form("M%d",i);

  // TString name;   fixed to below line, 2012.8.11
   Char_t* name;
   if (strstr(opt, "ENDF") || strstr(opt,"Endf")) {
      name = Form("%2d-%2s-%3d%s", z, symbol,a,iso);
   }
   else if (strstr(opt, "Compact")) {
      if (zai == 0)        return "g";
      else if (zai==10)    return "n";
      else if (zai==10010) return "p";
      else if (zai==10020) return "d";
      else if (zai==10030) return "t";

      name = Form("%d%s%d%s", z,symbol,a,iso);
   }
   else if (strstr(opt, "Latex")) {
      if (zai == 0)        return "#gamma";
      else if (zai==10)    return "n";
      else if (zai==10010) return "p";
      else if (zai==10020) return "d";
      else if (zai==10030) return "t";

      name = Form("^{%d%s}%s", a, iso, symbol);
   }
   else if (!strcmp(opt, "-")) {
      name = Form("%d-%s-%d%s", z,symbol,a,iso);
   }
   else {
      //name = Form("%02d_%-2s_%03d%s", z,symbol,a,iso);
      name = Form("%02d_%s_%03d%s", z,symbol,a,iso);
   }

   return name;
}


//______________________________________________________________________________
const Char_t* TNuMat::GetDefaultName(Option_t *opt) const
{
   // returns the default mat name, e.g., "1-H-1", "82-Pb-208"
   return TNuMat::GetDefaultMatName(fZAI, opt);
}

//______________________________________________________________________________
const Char_t* TNuMat::GetProjTargetName(const Char_t* between, Option_t *opt) const
{
   // returns the project and target name,
   // e.g., "n_82-Pb-208" if between = "_'
   //       "n + 82-Pb-208" if between = " + "

   return Form("%s%s%s",
      //GetParentProject()->GetShortName(),
      TNuProject::GetShortName(fNSUB),
      between,
      GetDefaultMatName(fZAI, opt));
}

// --------- Physics -----------------------------------------------------------
//______________________________________________________________________________
Double_t TNuMat::Nubar(Double_t Ein)
{
   // Total number of neutrons per fission, MFT=1,452.
   TNuSec01 *sec = (TNuSec01*) GetSection(1,452);
   if (sec) return sec->EvalF1(Ein);
/*
   if (sec) {
      TNuObject *obj  = sec->BodyAt(1);
      Int_t LNU = sec->GetL2();
      if (LNU == 1) return ((TNuListTaylor*) obj)->Eval(Ein);
      else          return ((TNuTab1*) obj)->Eval(Ein);
   }
*/
   Warning("Nubar", "No 1,452 section for this mat, ZAI = %d, MAT=%d", GetZAI(), GetMAT());
   return 0;
}

//______________________________________________________________________________
Double_t TNuMat::NubarDelayed(Double_t Ein)
{
   // Number of delayed neutrons per fission, MFT=1,455.
   TNuSec01 *sec = (TNuSec01*) GetSection(1,455);
   if (sec) return sec->EvalF1(Ein);

   Warning("NubarDelayed", "No 1,455 section for this mat, ZAI = %d, MAT=%d", GetZAI(), GetMAT());
   return 0;
}


//______________________________________________________________________________
Double_t TNuMat::NubarPrompt(Double_t Ein)
{
   // Number of prompt neutrons per fission, MFT=1,455.
   TNuSec01 *sec = (TNuSec01*) GetSection(1,456);
   if (sec) return sec->EvalF1(Ein);

   Warning("NubarPrompt", "No 1,456 section for this mat, ZAI = %d, MAT=%d", GetZAI(), GetMAT());
   return 0;
}

//______________________________________________________________________________
Double_t TNuMat::XSect(Int_t mt, Double_t Ein)
{
   // Cross section, MF=3

   TNuSec03 *sec = (TNuSec03*) GetSection(3,mt);
   if (sec) return sec->XSect(Ein);

   Warning("XSect", "No 3,%d section for this mat, ZAI = %d, MAT=%d", mt, GetZAI(), GetMAT());
   return 0;
}

//______________________________________________________________________________
Double_t TNuMat::DXDmuNormalized(Int_t mt, Double_t Ein, Double_t mu)
{
   // Angular distribution, MF=4

   TNuSec04 *sec = (TNuSec04*) GetSection(4,mt);
   if (sec) return sec->DXDmuNormalized(Ein,mu);

   Warning("DXDmuNormalized", "No 4,%d section for this mat, ZAI = %d, MAT=%d", mt, GetZAI(), GetMAT());
   return 0;
}

//______________________________________________________________________________
Double_t TNuMat::DXDENormalized(Int_t mt, Double_t Ein, Double_t Eout)
{
   // Energy distribution, MF=5

   TNuSec05 *sec = (TNuSec05*) GetSection(5,mt);
   if (sec) return sec->DXDENormalized(Ein,Eout);

   Warning("DXDENormalized", "No 5,%d section for this mat, ZAI = %d, MAT=%d", mt, GetZAI(), GetMAT());
   return 0;
}


//______________________________________________________________________
//TNuFile* TNuMat::Next()
//{
//   // returns next TNuFile
//   TNuFile *f;
//   while(fCursor < fFiles.GetSize()) {
//     if ((f = (TNuFile *) fFiles.At(fCursor++))) return f;
//   }
//
//   // if failed
//   return 0;
//}


#include "TPaveLabel.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TLegend.h"
//______________________________________________________________________________
void TNuMat::DrawXSects() const
{
   // Plot cross sections for selected channels

   Double_t emin = 1.e-3;
   Double_t emax = 2.e+7;
   Double_t smin = 1.e-6;
   Double_t smax = 1.e+4;

   static const struct {
      Int_t     mt;
      Int_t     color;
      const Char_t *symbol;
      const Char_t *desc;
   } kChannels[] = {
      {  1, kGreen,  "total", "Total"},
      {102, kBlue,   "(n,#gamma)", "Radiative Capture"},
      { 18, kRed,    "fission", "Fission"},
      {  2, kBlack,  "elastic", "Elastic"},
      {  4, kGray,   "(n,n')", "Production of one neutron"},
      { 16, kOrange, "(n,2n)", "(n,2n)"},
      { 17, kViolet, "(n,3n)", "(n,3n)"}
   };
   Int_t nChannels = (int) sizeof(kChannels)/sizeof(kChannels[0]);

   TCanvas *c1 = TNudy::GetCanvas();
   TPad *p1 = new TPad("pad1","This is pad1",0,0,1,1,33);

   p1->SetFillColor(40);
   p1->SetLogx();
   p1->SetLogy();
   p1->SetGridx();
   p1->SetGridy();
   p1->Draw();
   p1->cd();

   p1->DrawFrame(emin,smin, emax, smax);
   p1->GetFrame()->SetFillColor(19);

   TPaveLabel *pL = new TPaveLabel(emin,1.2*smax,emax, 9*smax,
      Form("Cross sections (barns) of %s with respect to En (eV)",
         ChemicalSymbol()), "br");
   //pL->SetFillColor(18);
   //pL->SetTextFont(32);
   //pL->SetTextColor(49);
   pL->Draw();

   TLegend *legend = new TLegend(0.12, 0.13, 0.25, 0.45);
   legend->SetTextSize(0.04);
   //TLegend *legend = new TLegend(0.12, 0.12, 0.4, 0.4);
   //legend->SetHeader(ChemicalSymbol());
   //legend->SetEntrySeparation(0.01f);
   //legend->SetNColumns(2);
   for (int nchan = 0; nchan < nChannels; nchan++) {
      Int_t mt = kChannels[nchan].mt;
      TNuSec03 *s3 = (TNuSec03*) GetSection(3, mt);
      if (!s3) {
         continue;
      }
      TGraph *gr = s3->GetXSectWithResoGraph();
      if (gr) {
         gr->SetLineColor(kChannels[nchan].color);
         gr->Draw("L");
         legend->AddEntry(gr, kChannels[nchan].symbol, "l");
      }
      else {
         printf("Warning : null graph for MT =%d\n", mt);
      }
   }
   legend->Draw();

   p1->Update();

   c1->Update();
   TNudy::NeedsCanvasCleared(kTRUE);
}
