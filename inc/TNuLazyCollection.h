// TNuLazyCollection.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuLazyCollection
#define ROOT_TNuLazyCollection

///////////////////////////////////////////////////////////////////////////////
//
// TNuLazyCollection : class for lazy loading collection
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCollection.h"
#include "TBrowser.h"

class TNuEndfIO;

//#include "TNuMat.h"
class TNuCont;
class TNuSection;
class TNuMat;
class TNuSublib;
class TNuLib;

class TKey;
#include <map>
#include "TList.h"

class TNuLazyCollection : public TNuCollection
{
public:
   TNuLazyCollection() : TNuCollection(), fIsTouched(kFALSE) {}
   virtual ~TNuLazyCollection() {}

   TNuObject*    IsLoaded(Int_t nuid) const;

   //TNuObject*    GetCurObject() const { return fCurObject; }
   TNuObject*    GetObjectByNuID(Int_t nuid) const;

   Int_t         GetNuIDAt(Int_t n) const;  // get the n-th MFT value of the file
   TNuObject*    At(Int_t n) const;  // get the n-th section of the file
   Int_t         GetEntries() const;  // returns the number of sections
   Int_t         GetSize() const { return GetEntries(); }

   void          Add(TNuObject* obj);
   void          SaveContents();
   virtual Int_t Write(const char *name=0, Int_t option=0, Int_t bufsize=0) const;

   void          Touch() const;
   Bool_t        IsTouched() const { return fIsTouched; }

   Bool_t        IsFolder() const { return kTRUE; }
   void          Browse(TBrowser *b);

   void          ls(Option_t* option="") const; // *MENU*
   void          Print(Option_t *opt) const; // *MENU*

   //TList*        GetCollection() const { return (TList*) &fLoaded; }

   TList*        GetLoaded() const { return (TList*) &fLoaded; }
   TList*        GetCollection() const { Touch(); return GetLoaded(); }

   virtual void  ResetCounter() { Touch(); TNuCollection::ResetCounter(); }

private:

   Bool_t        fIsTouched;//! true if all the data are loaded
   TList         fLoaded; //! Container for the loaded sections

   typedef std::map<Int_t, TKey*> TNuDiscMap_t;
   TNuDiscMap_t  fDiskDir;

   ClassDef(TNuLazyCollection, 1) // class for lazy loading collection
};

#endif
