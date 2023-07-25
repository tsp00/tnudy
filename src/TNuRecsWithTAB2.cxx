// TNuRecsWithTAB2.cxx  =====================================================
// Author: Tae-Sun Park   Aug 16 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuRecsWithTAB2                                                           //
//                                                                           //
// Array of records with ENDF TAB2 as head                                   //
// =                                                                         //
//  C1 C2 L1 L2 NR NZ                                                        //
//  (NBT(n), INT(n), n=1,NR)                                                 //
//  (<m-th TNuObject>, m=1,NZ)                                               //
//                                                                           //
// TNuTab2 and TNuTab3 belong to this class                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////


#include "TNuRecsWithTAB2.h"
#include "TNuEndfIO.h"

#include "TBrowser.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuRecsWithTAB2)

//______________________________________________________________________________
TNuRecsWithTAB2::TNuRecsWithTAB2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
// : TNuEndfTAB2(c1,c2,l1,l2,n1,n2)
{
   // TNuRecsWithTAB2 ctor
   SetTAB2(new TNuEndfTAB2(c1,c2,l1,l2,n1,n2));
}

//______________________________________________________________________________
TNuRecsWithTAB2::TNuRecsWithTAB2(TNuEndfIO &src, const Char_t* label)
// : TNuEndfTAB2(src, label)
{
   // ctor of TNuRecsWithTAB2 importing ENDF data
   SetTAB2(new TNuEndfTAB2(src, label));
}

//______________________________________________________________________________
TNuRecsWithTAB2::~TNuRecsWithTAB2()
{
   // dtor of TNuRecsWithTAB2
}


//______________________________________________________________________________
void TNuRecsWithTAB2::SetTAB2(TNuEndfTAB2* tab2)
{
   // Set the TNuEndfTAB2 record as the head of this

   if (!tab2) {
      Error("SetCont", "The tab2 may not be empty");
      return;
   }

   if (!tab2->InheritsFrom("TNuEndfTAB2")) {
      Error("SetCont", "The tab2 = %p = %s does not inherits from TNuEndfTAB2",
         tab2, tab2->ClassName());
      return;
   }

   TNuRecs::SetHead(tab2);
}

//______________________________________________________________________________
Double_t TNuRecsWithTAB2::GetX(Int_t n) const
{
   return ((TNuCont*) BodyAt(n))->GetC2();
}

//______________________________________________________________________________
void TNuRecsWithTAB2::What() const
{
   GetTAB2()->What();
}

//______________________________________________________________________________
void TNuRecsWithTAB2::ls(Option_t* option) const
{
   cout << Form("(%s) %s at %p: ", ClassName(), GetName(), this);
   cout << " / " << GetTitle() << endl;

   // ls TNuEndfTAB2
   GetTAB2()->ls(option);

   cout << "Table of records" << endl;
   for (Int_t n=0; n< GetSize(); n++) {
      TNuObject *obj = BodyAt(n);
      if (obj) {
         cout << setw(5) << n << ". ";
         obj->ls(option);
      }
   }
}

