// TNuRecsWithTab1.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuRecsWithTab1                                                           //
//                                                                           //
// sub-structure of the form                                                 //
//    Tab1 for (E, y(E))                                                     //
//    < one or more records>                                                 //
//                                                                           //
// The Tab1, y(E), serves as yield or multiplicity or probability.           //
// This form heavilly appears in File 5 & 6.                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuRecsWithTab1.h"

ClassImp(TNuRecsWithTab1)

//______________________________________________________________________________
TNuRecsWithTab1::~TNuRecsWithTab1()
{
   //TNuRecsWithTab1 dtor
}


//______________________________________________________________________________
void TNuRecsWithTab1::SetTab1(TNuTab1 *tab1)
{
   // Set the TNuTab1 record as the head of this

   if (!tab1) {
      Error("SetCont", "The cont may not be empty");
      return;
   }

   if (!tab1->InheritsFrom("TNuTab1")) {
      Error("SetTab1", "The tab1 = %p = %s does not inherits from TNuTab1",
         tab1, tab1->ClassName());
      return;
   }

   TNuRecs::SetHead(tab1);
}

//______________________________________________________________________________
void TNuRecsWithTab1::What() const
{
   TNuRecs::What();
   //cout << "   Entries = " << GetEntries() << endl;
}
