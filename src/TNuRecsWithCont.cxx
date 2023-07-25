// TNuRecsWithCont.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuRecsWithCont                                                           //
//                                                                           //
//A subsection of the form                                                   //
//   C1 C2 L1 L2 N1 N2 : CONT (as a member data)                             //
//   TNuRecs (as inheritance)                                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuRecsWithCont.h"

ClassImp(TNuRecsWithCont)

TNuRecsWithCont::~TNuRecsWithCont()
{
   // TNuRecsWithCont dtor
}

//______________________________________________________________________________
void TNuRecsWithCont::SetCont(TNuCont *cont)
{
   // Set the TNuCont record as the head of this

   if (!cont) {
      Error("SetCont", "The cont may not be empty");
      return;
   }

   if (!cont->InheritsFrom("TNuCont")) {
      Error("SetCont", "The cont = %p = %s does not inherits from TNuCont",
         cont, cont->ClassName());
      return;
   }

   TNuRecs::SetHead(cont);
}
