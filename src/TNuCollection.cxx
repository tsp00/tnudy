// TNuCollection.cxx  =====================================================
// Author: Tae-Sun Park   Feb 22 2016

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuCollection = Abstract class for a container
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuCollection.h"
#include "TNuObject.h"
#include "TCollection.h"
#include "TBrowser.h"

ClassImp(TNuCollection)

//______________________________________________________________________________
TNuObject* TNuCollection::GetObjectByNuID(Int_t nuid) const
{
   // Find an object by NuID, and set the pointer of it to fCurObject.
   if (GetCurObject() && nuid == GetCurObject()->GetNuID()) return GetCurObject();

   TNuObject* obj;
   TIter nextobj(GetCollection());
   while ((obj = (TNuObject*) nextobj())) {
      if (nuid == obj->GetNuID()) {
         SetCurObject(obj);
         return obj;
      }
   }
   return 0;
}

//______________________________________________________________________________
void TNuCollection::Add(TNuObject* obj)
{
   // Add an object
   if (!obj) return;

   // first remove the old entry with the same ZAI value
   TNuObject *old = GetObjectByNuID(obj->GetNuID());
   if (old) {
fprintf(stderr,"TNuCollection::Add::replace, obj = %p, old=%p\n", obj, old); fflush(stderr);
      GetCollection()->Remove(old);
      SetCurObject(obj);
   }

   GetCollection()->Add(obj);
}

//______________________________________________________________________________
void TNuCollection::Browse(TBrowser *b)
{
   // Browse

   if(b) {
      TNuObject* obj;
      TIter nextobj(GetCollection());
      while ((obj = (TNuObject*) nextobj())) {
         obj->SetParent(this);
         b->Add(obj);
      }
   }
}

//______________________________________________________________________
TNuObject* TNuCollection::Next()
{
   TNuObject *obj;
   while(fCursor < GetSize()) {
     if ((obj = (TNuObject *) At(fCursor++))) return obj;
   }
   return (TNuObject*) 0; // if failed
}

ClassImp(TNuIter)
