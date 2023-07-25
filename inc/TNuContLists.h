// TNuContLists.h  =====================================================
// Author: Tae-Sun Park   Jul 21 2011

#ifndef ROOT_TNuContLists
#define ROOT_TNuContLists

///////////////////////////////////////////////////////////////////////////////
//
// TNuContLists
//
// A special case of TNuRecsWithCont where the structure is
//
// TNuCont
// (i-th TNuList, i=1, N)
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuRecsWithCont.h"
#include "TNuList.h"

class TNuContLists : public TNuRecsWithCont
{
public:
   TNuContLists() : TNuRecsWithCont() {}
   virtual ~TNuContLists() {}

   void          Add(TNuList* obj);

   TNuList*      BodyAt(Int_t i) const { return (TNuList*) TNuRecs::BodyAt(i); }

   //TNuList*&     operator[](Int_t i) { return (TNuList*&) fRecs[i]; }
//   TNuList*      operator[](Int_t i) const{ return At(i); }

   TNuObject*    BodyFirst() const { return (TNuList*) TNuRecs::BodyFirst(); }
   TNuObject*    BodyLast() const { return (TNuList*) TNuRecs::BodyLast(); }

   ClassDef(TNuContLists, 1) // TNuCont + (i-th TNuList, i=1, N)
};

#endif

