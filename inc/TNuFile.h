// TNuFile.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuFile
#define ROOT_TNuFile

///////////////////////////////////////////////////////////////////////////////
//
// TNuFile : class for ENDF FILE
//
///////////////////////////////////////////////////////////////////////////////

//#include "TNuObject.h"
#include "TNuLazyCollection.h"
//#include "TBrowser.h"

class TNuEndfIO;

#include "TNuSection.h"
class TNuCont;
//class TNuSection;
class TNuMat;
class TNuSublib;
class TNuLib;

class TKey;
//#include <map>

class TNuFile : public TNuLazyCollection
{

public:
   TNuFile() : TNuLazyCollection() {}
   TNuFile(Int_t mat, Int_t mf);
   virtual ~TNuFile();

   static const Char_t* GetFileDescription(Int_t mf);
   void           Init();

   Int_t          GetMF() const { return fMF; }
   Int_t          GetMAT() const;

   TNuSection*    GetCurSection() const { return (TNuSection*) GetCurObject(); }
   TNuSection*    GetSection(Int_t mft) const;

   Int_t          GetMFTAt(Int_t n) const { return GetNuIDAt(n); } // get the n-th MFT value of the file
   Int_t          GetMTAt(Int_t n) const { return GetMFTAt(n) % 1000; }  // get the n-th MFT value of the file
   TNuSection*    SectionAt(Int_t n) const { return (TNuSection*) At(n); }  // get the n-th section of the file

   Int_t            GetNuID() const { return fMF; }

   Bool_t        IsFolder() const  { return kTRUE; }

   //void           ls(Option_t* option="") const; // *MENU*
   void           Print(Option_t *opt) const; // *MENU*

   Bool_t         IsFile() const { return kTRUE; } // check if it is a TNuFile 
   TNuFile*       GetParentFile() const { return (TNuFile*) this; }
   TNuMat*        GetParentMat() const { return (TNuMat*) GetParent(); }

   ROOT::Internal::TRangeDynCastIterator<TNuSection> begin() const { return GetCollection()->begin(); }
   ROOT::Internal::TRangeDynCastIterator<TNuSection> end() const { return GetCollection()->end(); }

private:
   Short_t        fMAT;
   Short_t        fMF;

   ClassDef(TNuFile, 1) // A set of TNuSection data with a common MF value
};

#endif
