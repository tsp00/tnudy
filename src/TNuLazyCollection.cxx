// TNuLazyCollection.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuLazyCollection : class for lazy loading collection
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuLazyCollection.h"
#include "TNuCollection.h"

#include "TROOT.h"
#include "TString.h"

#include "TKey.h"

#include "TNudy.h"
#include "TNuSection.h"
#include "TNuCont.h"
#include "TNuMat.h"
//#include "TNuEndfIO.h"

//#include "TNuVF1.h"
//#include "TNuVF2.h"
//#include "TNuVF3.h"

#include "TNuPrinter.h"
#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuLazyCollection)

//______________________________________________________________________________
TNuObject* TNuLazyCollection::IsLoaded(Int_t nuid) const
{
   // return the ptr of the object with nuid if it is already loaded

   TNuObject *obj;
   TIter nextobj(&fLoaded);
   while ((obj = (TNuObject*) nextobj())) {
       if (nuid == (Int_t) obj->GetNuID()) return obj;
   }
   return 0;
}

//______________________________________________________________________________
TNuObject* TNuLazyCollection::GetObjectByNuID(Int_t nuid) const
{
   // return the ptr of the object with nuid
   // check first if it is already loaded
   // and then search the disk

   ((TNuLazyCollection*) this)->fCurObject = IsLoaded(nuid);
   if (fCurObject) {
      return fCurObject;
   }

   if(fIsTouched) return 0;

   TNuDiscMap_t::const_iterator iter2 = fDiskDir.begin();
   iter2=fDiskDir.find(nuid);
   if (iter2 != fDiskDir.end()) {
      TKey *tkey = iter2->second;
      TNuObject* obj = tkey ?  (TNuObject*) tkey->ReadObj() : 0;
      if (obj) {
         obj->SetParent(this);
         obj->SetLineage();
         ((TNuLazyCollection*) this)->fLoaded.Add(obj);
         ((TNuLazyCollection*) this)->fCurObject = obj;
//printf("XXX, %p, %s, size=%d=%d\n", obj, obj->GetName(), fLoaded.GetSize(), fLoaded.GetEntries());
      } else {
         Error("GetObjectByNuID", "ReadObj() of TKey(=%p) is null for nuid=%d", tkey, nuid);
      }
      return fCurObject;
   }
   return 0;
}

//______________________________________________________________________________
Int_t TNuLazyCollection::GetNuIDAt(Int_t n) const
{
   // returns the n-th NuID value

   if (n<0 || n>= GetEntries()) return 0;
   
   TNuDiscMap_t::const_iterator iter=fDiskDir.begin();
   Int_t i = 0;
   for (iter=fDiskDir.begin(); iter != fDiskDir.end(); ++iter, ++i)
      if (i==n) return iter->first;
   // TODO the default return value should be negative, huh? 2023-0518
   return 0;
}

//______________________________________________________________________________
TNuObject* TNuLazyCollection::At(Int_t n) const
{
   // returns the n-th object

   Int_t nuid = GetNuIDAt(n);
   if (nuid>=0)
      return GetObjectByNuID(nuid);
   else
      return 0;
}

//______________________________________________________________________________
Int_t TNuLazyCollection::GetEntries() const
{
   // returns the number of sections of the file

   return fDiskDir.size();
}

//______________________________________________________________________________
void TNuLazyCollection::Add(TNuObject* obj)
{
   // Add an object
   if (obj) {
      obj->SetParent(this);
      fLoaded.Add(obj);
   }
}

//______________________________________________________________________________
void TNuLazyCollection::SaveContents()
{
//Info("Save", "1"); fflush(stderr);
   // find out the directory where the obj should be stored
   //const Char_t *dir= GetParentMat()->GetPath();
   // and update the fDiscMap
   //const Char_t *dir= GetPath();
   //if (!gDirectory->cd(dir)) {
   //   Warning("SaveContents", "Failed to move to %s", dir);
   //   gDirectory->mkdir(dir);  
   //   if (!gDirectory->cd(dir)) {
   //      Error("SaveContents", "Failed to move to %s", dir);
   //      return;
   //   }
   //}
   CdToDataDir();

   TNuObject *obj;
   TIter nextobj(&fLoaded);
   while ((obj = (TNuObject*) nextobj())) {
      obj->Write();
      Int_t nuid = obj->GetNuID();
      TKey *key = gDirectory->FindKey(obj->GetName());
      if (!key) {
         Error("TNuLazyCollection::Add", "Failed to find key for pSec=%s", obj->GetName());
         //Error("", "dir = %s", dir);
         Error("", "nuid = %d", nuid);
         Error("", "gdir = %p", gDirectory);
         std::cerr << "gDirectory=" << gDirectory;
      }
      fDiskDir.insert(std::pair<Int_t, TKey*>(nuid, key));
   }
   fLoaded.SetOwner();
   fLoaded.Clear();
   fIsTouched = kFALSE;
}

//______________________________________________________________________________
Int_t TNuLazyCollection::Write(const char *name, Int_t option, Int_t bufsize) const
{
   const char *cwd = gDirectory->GetPath();
//fprintf(stderr,"Lazy Writing ... ... %s with %s\n", GetName(), cwd);
   ((TNuLazyCollection*)this)->SaveContents();
   //return ((TObject*)this)->Write(name, option, bufsize);
   gDirectory->cd(cwd);
   Int_t res = TObject::Write(name, option, bufsize);
   return res;
}

//______________________________________________________________________________
void TNuLazyCollection::Touch() const
{
   // Load the all the data from the disk

   if (fIsTouched) return;

   TNuDiscMap_t::const_iterator iter;

   for (iter = fDiskDir.begin(); iter != fDiskDir.end(); ++iter) {
      Int_t nuid = iter->first;
      GetObjectByNuID(nuid);
   }
   ((TNuLazyCollection*) this)->fIsTouched = kTRUE;
}

//______________________________________________________________________________
void TNuLazyCollection::Browse(TBrowser *b)
{
   // Browse

   if(b) {
      Touch();
      TNuObject *obj;
      TIter nextobj(&fLoaded);
      while ((obj = (TNuObject*) nextobj())) {
         b->Add(obj);
      }
   }
/*
      TNuDiscMap_t::const_iterator iter;

      for (iter = fDiskDir.begin(); iter != fDiskDir.end(); ++iter) {
         Int_t nuid = iter->first;
         TNuObject *sec = GetObjectByNuID(nuid);
         if (sec) b->Add(sec);
      }
   }
   fIsTouched = kTRUE;
*/
}

//______________________________________________________________________________
void TNuLazyCollection::ls(Option_t* /* option */) const
{
   cout << Form("(%s) %s at %p: ", TObject::GetName(), GetName(), this);
   cout << " / " << GetTitle() << endl;
   cout << endl;
   cout << "Table of contents" << endl;

   TNuDiscMap_t::const_iterator iter;

   cout << setw(20) << "Name" << " : Title" << endl;
   for (iter = fDiskDir.begin(); iter != fDiskDir.end(); ++iter) {
      Int_t nuid = iter->first;
      TObject *obj = (TNuObject*) IsLoaded(nuid);
      if (!obj) obj = (TKey*) iter->second;
      TString str = Form("(%s) %s", obj->TObject::GetName(), obj->GetName());
      cout << left << setw(20) << str << right << " : ";
      cout << obj->GetTitle() << endl;
   }
}

//______________________________________________________________________________
void TNuLazyCollection::Print(Option_t *opt) const
{
   // print

   TNuDiscMap_t::const_iterator iter;

   for (iter = fDiskDir.begin(); iter != fDiskDir.end(); ++iter) {
      Int_t nuid = iter->first;
      TNuObject *obj = GetObjectByNuID(nuid);
      if (obj) obj->Print(opt);
      else {
         Warning("Print", "The TNuObject for NuID=%d is null", nuid);
      }
   }
}

