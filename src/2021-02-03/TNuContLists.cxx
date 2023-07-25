// TNuContLists.cxx  =====================================================
// Author: Tae-Sun Park   Jul 21 2011

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

#include "TNuContLists.h"

ClassImp(TNuContLists)


//______________________________________________________________________________
void TNuContLists::Add(TNuList* obj)
{
   // Add one TNuList element

   if (obj && !obj->InheritsFrom("TNuList")) {
      Error("Add", "The obj = %p = %s should be TNuList-derived class",
         obj, obj->ClassName());
      return;
   }
   TNuRecs::Add(obj);
}
