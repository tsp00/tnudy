// TNuLib.h  =====================================================
// Author: Tae-Sun Park   09/18/09 (revived at Jun 29 12:48:16 2011)

#ifndef ROOT_TNuLib
#define ROOT_TNuLib

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuLib                                                             //
//                                                                    //
// Set of all the ENDF data that belong to a ENDF library,            //
// ENDF6, ENDF7, JEFF, ...                                            //
//                                                                    //
////////////////////////////////////////////////////////////////////////

//#include <map>
//#include "TNuObject.h"
#include "TNuLazyCollection.h"
//#include "TFile.h"
//#include "TList.h"
//#include "TBrowser.h"
#include "TObjArray.h"

#include "TNuSublib.h"
class TFile;
class TNuEndfIO;
class TNuLib;
//class TNuSublib;
class TNuMat;
class TNuFile;
class TNuSection;
class TNuLabel;

//class TNuLib: public TNuObject
class TNuLib: public TNuLazyCollection
{
public:
   TNuLib();
   TNuLib(TFile *target, const Char_t *libName, const Char_t *libTitle);
   virtual ~TNuLib();

   //
   //Int_t        LibraryNumber() const          { return fNLIB; }
   //
   //Int_t        GetNLIB() const   { return fNLIB; }  // library number

   TNuSublib*    GetSublib(Int_t nsub) const;
   TNuSublib*    GetSublib(const Char_t* projName) const;

   //TList*         GetListOfProjects() const { return (TList*) &fProjects; }
   //TList*         GetCollection() const { return GetListOfProjects(); }

   //TNuObject*     At(Int_t n) const { return (TNuObject*) GetListOfProjects()->At(n); }

   TNuMat*        GetMat(Int_t zai) const;
   TNuMat*        GetMat(const Char_t *target) const;
   TNuMat*        GetMat(const Char_t *project, const Char_t *target) const;

   //const Char_t*  GetPath() const { return fHomeDir.Data(); }

   void           SetTFile(TFile *tfile) { fTNuRootFile = tfile; }
   TFile*         GetTFile() const { return fTNuRootFile; }

   Int_t          ImportAsciiEndf(const Char_t* asciiEndfFilename);
   Int_t          ImportMultipleAsciiEndf(const Char_t *listOfAsciiEndfFilenames);
   Int_t          ImportAsciiEndfDir(const Char_t *dirname, const char *ext="*", bool extract_zip=kTRUE);
   void           ImportAsciiEndf(TNuEndfIO& src);
   void           ImportAsciiEndf(TNuEndfIO& src, TFile *tfile);
   void           ImportAsciiEndf(TList &filelist, TFile *tfile);

   static Int_t   MergeAsciiEndfDir(FILE* dest, const Char_t *dirname, const char *ext="*", bool extract_zip=kTRUE);
   static Int_t   MergeAsciiEndfDir(const Char_t* dest_name, const Char_t *dirname, const char *ext="*", bool extract_zip=kTRUE);

   Bool_t         IsFolder() const  { return kTRUE; }

   void           ls(Option_t* option="") const; // *MENU*
   void           Print(Option_t *opt) const; // *MENU*

   const Char_t*  GetObjName(UShort_t id) const;
   const Char_t*  GetObjTitle(UShort_t id) const;
   TNuLabel*      GetObjLabel(UShort_t id) const;

   UShort_t       SetObjName(const Char_t* name);
   UShort_t       SetObjTitle(const Char_t* title);
   UShort_t       SetObjLabel(const Char_t* label);

   void           ShowObjNames();
   void           ShowObjTitles();
   void           ShowObjLabels();

   TNuLib*        GetParentLib() const { return (TNuLib*) this; }

   TNuSublib*    GetCurSublib() const { return (TNuSublib*) GetCurObject(); } // pointer to current TNuSublib

//   virtual const Char_t*  GetName()  const { return fName.Data(); }
//   virtual const Char_t*  GetTitle() const { return fTitle.Data(); }

   TNuSublib*    NextSublib() { return (TNuSublib*) TNuCollection::Next(); }

   ROOT::Internal::TRangeDynCastIterator<TNuSublib> begin() const { return GetCollection()->begin(); }
   ROOT::Internal::TRangeDynCastIterator<TNuSublib> end() const { return GetCollection()->end(); }

private:

   Int_t          fNLIB;         // library number
   TFile*         fTNuRootFile;        //! the TFile of the data
   //TString        fHomeDir;      // the home directory of this

   TString        fName;
   TString        fTitle;

   //TList          fProjects; //

   // for TNuObject's name/title/label
   TObjArray      fObjNames;   // Array of Name strings
   TObjArray      fObjTitles;  // Array of Title strings
   TObjArray      fObjLabels;  // Array of Label strings

   ClassDef(TNuLib, 1) //Set of all the ENDF data that belong to a ENDF library
};

#endif
