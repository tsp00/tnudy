// TNuCollection.h  =====================================================
// Author: Tae-Sun Park   Feb 22 2016

#ifndef ROOT_TNuCollection
#define ROOT_TNuCollection

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuCollection = Abstract class for a container
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuObject.h"
//class TCollection;
#include "TCollection.h"
class TBrowser;

class TNuCollection : public TNuObject
{
public:
   TNuCollection() : TNuObject(), fCursor(0), fCurObject(0) {}
   TNuCollection(const TNuObject &rec) : TNuObject(rec), fCursor(0), fCurObject(0) {}
   virtual ~TNuCollection() {}

   virtual TCollection* GetCollection() const = 0;

   operator TCollection* () const { return GetCollection(); }

   TNuObject* GetCurObject() const { return fCurObject; }
   void       SetCurObject(TNuObject* obj) const { 
      ((TNuCollection*)this)->fCurObject = obj; }

   virtual TNuObject*  GetObjectByNuID(Int_t nuid) const;

   virtual Int_t GetSize() const { return GetCollection()->GetSize(); }
   virtual Int_t GetEntries() const { return GetCollection()->GetEntries(); }

   Bool_t        IsFolder() const  { return kTRUE; }

   virtual void  Add(TNuObject* obj);
   void          Browse(TBrowser *b);

   TNuObject*    First() const { return GetEntries() > 0 ? At(0) : 0; }
   TNuObject*    Last() const { return GetEntries() > 0 ? At(GetEntries()-1) : 0; }

   virtual TNuObject* At(Int_t n) const = 0;
   virtual void       ResetCounter() { fCursor = 0; }
   virtual TNuObject* Next();

   TIter         MakeIter(Bool_t dir=kIterForward) { return TIter(GetCollection(), dir); }
   static TIter  MakeIter(TNuCollection *col, Bool_t dir=kIterForward) {
      return TIter(col ? col->GetCollection() : 0, dir); }

protected:
   Int_t         fCursor; //! current position of the iterator
   TNuObject*    fCurObject; //! Currently active TNuObject ptr


   ClassDef(TNuCollection, 0) //Abstract class for a container
};

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TNuIter                                                              //
//                                                                      //
// Iter wrapper. Constructed on top of TIter
//                                                                      //
//////////////////////////////////////////////////////////////////////////

class TNuIter : public TIter
{
public:
   TNuIter(const TCollection *col, Bool_t dir = kIterForward)
         : TIter(col, dir) { }
   TNuIter(const TNuCollection *col, Bool_t dir = kIterForward)
      : TIter(col ? col->GetCollection() : static_cast<TCollection*>(nullptr), dir) {}
   TNuIter(TNuCollection* c) : TIter(c ? c->GetCollection() : 0) {}
   virtual ~TNuIter() {}

protected:
   TNuIter() : TIter() {}
   ClassDef(TNuIter, 0)
};

#endif
