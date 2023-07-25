// TNuMat.h  =====================================================
// Author: Tae-Sun Park   Jun 22 2011

#ifndef ROOT_TNuMat
#define ROOT_TNuMat

////////////////////////////////////////////////////////////////////////
//
// TNuMat  - a class for a material of ENDF, set of TNuSection
//
// ENDF MAT
//
////////////////////////////////////////////////////////////////////////

//#include "TNuObject.h"
#include "TNuLazyCollection.h"
//#include <map>
//#include "TNuMapper.h"
//#include "TList.h"
//#include "TBrowser.h"

//#include "TNuSublib.h"
#include "TNuFile.h"

class TNuSection;
class TNuSec01451;
//class TNuFile;
class TNuSublib;
class TNuLib;
class TNuEndfIO;

class TNuMat: public TNuLazyCollection
{
public:
   TNuMat(Int_t mat = 0);
   TNuMat(TNuEndfIO &src, Int_t mat, TNuLib* lib);
   virtual ~TNuMat();

   void      What() const; // *MENU*

   //TList*    GetListOfFiles() const { return (TList*) &fFiles; }
   //TList*    GetCollection() const { return GetListOfFiles(); }

   //
   // Informations of the ENDF MAT
   //
   Int_t     LibraryNumber() const          { return fNLIB; }
   Int_t     VersionNumber() const          { return fNVER; }
   Int_t     ModificationNumber() const     { return fNMOD; }
   Int_t     IsDerived() const              { return fLDRV; }
   Double_t  Temperature() const            { return fTEMP; }  // Temperature in degree
   Int_t     ProjectileID() const           { return fNSUB; }  // NSUB, specify the projectile

   Int_t     GetZ() const                   { return fZA / 1000; }
   Int_t     GetA() const                   { return fZA % 1000; }

   Double_t  MaterialMass() const           { return fAWR; }   // mass of the material [in unit of m_n]
   Double_t  TargetMass() const             { return fAWR; }   // mass of the material [in unit of m_n]
   Double_t  TargetMassFraction() const       { return fAWR / (fAWR + fAWI); } // (target mass)/(total mass)
   Int_t     ResonanceParameterFlag() const { return fLRP; }   // Resonance paramter flag, -1:none, 0: no, 1: yes, 2: yes
   Int_t     IsFissionable() const          { return fLFI; }   // is fissionalbe ?
   Double_t  ExcitationEnergy() const       { return fELIS; }  // excitation energy[eV] relative to 0 for ground
   Double_t  IsStable() const               { return fSTA; }   // 0=stable, 1=radioactive
   Int_t     StateNumber() const            { return fLIS; }   // state number, 0 for ground state
   Int_t     IsomericStateNumber() const    { return fLISO; }  // isomeric state number, 0 for ground state, >= LIS
   Int_t     LibraryFormatNumber() const    { return fNFOR; }  // library format, 6 for ENDF/6
   Double_t  ProjectileMass() const            { return fAWI; }   // mass of projectile [in unit of m_n]
   Double_t  UpperEnergyLimit() const       { return fEMAX; }  // upper limit of energy range
   Int_t     ReleaseNumber() const          { return fLREL; }  // Release number
   Int_t     DescriptionSizes() const       { return fNWD; }   // number of records (lines)
   Int_t     DirectorySize() const          { return fNXC; }   // number of records

   const Char_t*  ChemicalSymbol() const         { return fZSYNAM; }
   const Char_t*  LaboratoryMnemonic() const     { return fALAB; }
   const Char_t*  EvaluationDate() const         { return fEDATE; }
   const Char_t*  Author() const                 { return fAUTH; }
   const Char_t*  PrimaryReference() const       { return fREF; }
   const Char_t*  DistributionDate() const       { return fDDATE; }
   const Char_t*  RevisionDate() const           { return fRDATE; }
   const Char_t*  MasterFileEntryDate() const    { return fENDATE; }


   //
   // In terms of ENDF language
   //
   Int_t     GetNLIB() const   { return fNLIB; }  // library number
   Int_t     GetNVER() const   { return fNVER; }  // version number
   Int_t     GetNMOD() const   { return fNMOD; } // modification number
   Int_t     GetLDRV() const   { return fLDRV; }  // is derived ?
   Double_t  GetTEMP() const   { return fTEMP; }  // Temperature in degree
   Int_t     GetNSUB() const   { return fNSUB; }  // NSUB, specify the projectile
   Int_t     GetZAI() const    { return fZAI; }   // ZAI number, = 10*ZA+LISO
   Int_t     GetNuID() const    { return GetZAI(); }   // ZAI number, = 10*ZA+LISO

   Int_t     GetMAT() const    { return fMAT; }   // MAT, specify the target

   Int_t     GetZA() const     { return fZA; }    // 1000*Z + A
   Double_t  GetAWR() const    { return fAWR; }   // mass of the material [in unit of m_n]
   Int_t     GetLRP() const    { return fLRP; }   // Resonance paramter flag, -1:none, 0: no, 1: yes, 2: yes
   Int_t     GetLFI() const    { return fLFI; }   // is fissionalbe ?
   Double_t  GetELIS() const   { return fELIS; }  // excitation energy[eV] relative to 0 for ground
   Int_t     GetSTA() const    { return fSTA; }   // 0=stable, 1=radioactive
   Int_t     GetLIS() const    { return fLIS; }   // state number, 0 for ground state
   Int_t     GetLISO() const   { return fLISO; }  // isomeric state number, 0 for ground state, >= LIS
   Int_t     GetNFOR() const   { return fNFOR; }  // library format, 6 for ENDF/6
   Double_t  GetAWI() const    { return fAWI; }   // mass of projectile [in unit of m_n]
   Double_t  GetEMAX() const   { return fEMAX; }  // upper limit of energy range
   Int_t     GetLREL() const   { return fLREL; }  // Release number
   Int_t     GetNWD() const    { return fNWD; }   // number of records (lines)
   Int_t     GetNXC() const    { return fNXC; }   // number of records

   const Char_t*  GetZSYNAM() const      { return fZSYNAM; }
   const Char_t*  GetALAB() const        { return fALAB; }
   const Char_t*  GetEDATE() const       { return fEDATE; }
   const Char_t*  GetAUTH() const        { return fAUTH; }
   const Char_t*  GetREF() const         { return fREF; }
   const Char_t*  GetDDATE() const       { return fDDATE; }
   const Char_t*  GetRDATE() const       { return fRDATE; }
   const Char_t*  GetENDATE() const      { return fENDATE; }
   const Char_t*  GetHSUB(Int_t n) const { return (n>=0 && n < 3) ? fHSUB[n] : ""; }

   //Bool_t         SetFile(Int_t mf) const;
   TNuFile*       GetFile(Int_t mf) const;
   //TNuFile*       FileAt(Int_t n) const { return (TNuFile*) GetListOfFiles()->At(n); }
   //TNuObject*     At(Int_t n) const { return (TNuObject*) FileAt(n); }

   TNuSection*    GetSection(Int_t mft) const;
   TNuSection*    GetSection(Int_t mf, Int_t mt) const;

   //const Char_t*  GetPath() const { return fHomeDir.Data(); }

   Bool_t        IsFolder() const  { return kTRUE; }

   void           ls(Option_t* option="") const; // *MENU*
   void           Print(Option_t *opt) const; // *MENU*

   static const Char_t* GetDefaultMatName(Int_t zai, Option_t* opt="");
   const Char_t*  GetDefaultName(Option_t *opt="") const;
   const Char_t*  GetProjTargetName(const Char_t* between = " + ", Option_t *opt="") const;
   const Char_t*  GetSymbol() const { return GetProjTargetName(" + ", "Latex"); }

   Bool_t         IsMat() const { return kTRUE; } // check if it is a TNuMat 
   TNuMat*        GetParentMat() const { return (TNuMat*) this; }
   TNuSublib*    GetParentSublib() const { return (TNuSublib*) GetParent(); }
   //TNuLib*        GetParentLib() const { return GetParentSublib()->GetParentLib(); }

   // --------- Physics --------------------------------------------------------

   void           DrawXSects() const; //*MENU*

   Double_t       Nubar(Double_t Ein);
   Double_t       NubarDelayed(Double_t Ein);
   Double_t       NubarPrompt(Double_t Ein);

   // total cross section
   Double_t       XSect(Int_t mt, Double_t Ein);
   // angular distribution
   Double_t       DXDmuNormalized(Int_t mt, Double_t Ein, Double_t mu);
   // energy distribution
   Double_t       DXDENormalized(Int_t mt, Double_t Ein, Double_t Eout);

   TNuFile*       GetCurFile() const { return (TNuFile*) GetCurObject(); }

   // mini iterator
   TNuFile*       NextFile() { return (TNuFile*) TNuCollection::Next(); }

   ROOT::Internal::TRangeDynCastIterator<TNuFile> begin() const { return GetCollection()->begin(); }
   ROOT::Internal::TRangeDynCastIterator<TNuFile> end() const { return GetCollection()->end(); }

private:
   void      Init(TNuSec01451* pSec1451, TNuLib* lib);

   Int_t     fNLIB;     // library number
   Int_t     fNVER;     // version number
   Int_t     fNMOD;     // modification number
   Int_t     fLDRV;     // is derived ?
   Double_t  fTEMP;     // Temperature in degree
   Int_t     fNSUB;     // NSUB, specify the projectile
   Int_t     fZAI;      // ZAI number, = 10*((Int_t) ZA+0.5)+LISO
   Int_t     fMAT;      // MAT, specify the target

   //Double_t  fZA;     // 1000.*Z + A
   Int_t     fZA;       // 1000*Z + A
   Double_t  fAWR;      // mass of the material [in unit of m_n]
   Int_t     fLRP;      // Resonance paramter flag, -1:none, 0: no, 1: yes, 2: yes
   Int_t     fLFI;      // is fissionalbe ?
   Double_t  fELIS;     // excitation energy[eV] relative to 0 for ground
   Int_t     fSTA;      // 0=stable, 1=radioactive
   Int_t     fLIS;      // state number, 0 for ground state
   Int_t     fLISO;     // isomeric state number, 0 for ground state, >= LIS
   Int_t     fNFOR;     // library format, 6 for ENDF/6
   Double_t  fAWI;      // mass of projectile [in unit of m_n]
   Double_t  fEMAX;     // upper limit of energy range
   Int_t     fLREL;     // Release number
   Int_t     fNWD;      // number of records (lines)
   Int_t     fNXC;      // number of records

   Char_t    fZSYNAM[12];
   Char_t    fALAB[12];
   Char_t    fEDATE[11];
   Char_t    fAUTH[34];
   Char_t    fREF[22];
   Char_t    fDDATE[11];
   Char_t    fRDATE[11];
   Char_t    fENDATE[9];
   Char_t    fHSUB[3][67];

   //TList          fFiles;
   //TString        fHomeDir; // the directory name for the mat data

   ClassDef(TNuMat, 1) // data for a material of ENDF
};

#endif
