//  TNuRecs.cxx  =====================================================
// @(#)root/meta:$Id: TNuRecs.cxx 29000 2009-06-15 13:53:52Z rdm $
// Author: Tae-Sun Park   Jun 13 2011

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuRecs                                                            //
//                                                                    //
// Base class for the collections of TNuObjects.                      //
//
//
// In TNudy, collection of records consists of three parts,
// head, body and tail parts, and stored as below
//
// [Head part]
//   HeadAt(0)         : 1st head element  = HeadFirst() = At(0)
//   HeadAt(1)         : 2nd head element                = At(1)
//   ...
//   HeadAt(fNHeads-1) : last head element = HeadLast()
//
// [Body part]
//   BodyAt(0)        : 1st data element  = BodyFirst()
//   BodyAt(1)        : 2nd data element
//   ....
//   BodyAt(fNBodies-1) : last data element = BodyLast()
//
// [Tail part]
//   TailAt(0)        : 1st data element  = TailFirst()
//   TailAt(1)        : 2nd data element
//   ....
//   TailAt(fNTails-1) : last data element = TailLast() = At(GetEntries())
//
//  Notes:
//  1. For inserting, use AddToHead(obj) for the head elements,
//     Add(obj) for the body elements,
//     and AddToTail(obj) for tail elements
//  2. One may use SetHead(obj) for the 1st head element.
//  3. TNuRecs does not inherit from TNuCont.
//     Use HeadCont() for the 1st element in head that inherits from TNuCont.
//  4. For its derived class,
//     for a unified, consistent and transparent coding,
//     it is strongly recommended to store all the TNuObjects
//     in the above form (instead of storing them
//     in their spicific separate places),
//
////////////////////////////////////////////////////////////////////////

#include "TNuRecs.h"

#include "TROOT.h"
#include "TString.h"
//#include "TObject.h"

#include "TNudy.h"
#include "TNuVF1.h"
#include "TNuVF2.h"
#include "TNuVF3.h"

#include "TNuPrinter.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuRecs)

//______________________________________________________________________________
TNuRecs::TNuRecs() : TNuObject(), fNHeads(0), fNBodies(0), fNTails(0)
{
   // TNuRecs ctor
}

//______________________________________________________________________________
TNuRecs::~TNuRecs()
{
   // TNuRecs dtor
}

//--------------------------------
// methods for head
//--------------------------------
//______________________________________________________________________________
void TNuRecs::AddToHead(TObject* obj)
{
   // Add obj to fRecs, attaching 'h' + the sequence number to the object

   if (fNBodies > 0) {
      Error("AddToHeadAt",
         "You may not add head objects if any data record has been added");
      return;
   }

   if (fNHeads==0 && !obj) {
      Error("AddToHead", "Adding NULL to the 1st head element is forbidden");
      return;
   }

   if (obj) {
      ((TNuObject*)obj)->SetName(Form("%s_h%d",obj->GetName(), fNHeads));
      fRecs.AddAt(obj, fNHeads);
   }

   fNHeads++;
}

//______________________________________________________________________________
void TNuRecs::SetHead(TNuObject* obj)
{
   // Add obj to fRecs, attaching 'h' + the sequence number to the object

   if (fNHeads>0) {
      Error("SetHead", "There are already %d element(s) in head", fNHeads);
      return;
   }

   AddToHead(obj);
}


//______________________________________________________________________________
void TNuRecs::SetCont(TNuCont* cont)
{
   // Add obj to the 1st place in head

   if (!cont->InheritsFrom("TNuCont")) {
      Error("SetCont", "The cont = %s is not inherited from TNuCont", cont->ClassName());
      return;
   }

   SetHead(cont);
}

//--------------------------------
// methods for body
//--------------------------------
//______________________________________________________________________________
void TNuRecs::Add(TObject* obj)
{
   // Add obj to data, attaching the sequence number to the object

   //if (!fNHeads) {
   //   Error("Add", "The head is empty");
   //   return;
   //}

   if (obj) {
      if (obj->GetName() == obj->ClassName())
         ((TNuObject*)obj)->SetName(Form("%s_%d",obj->GetName(), fNBodies));
      fRecs.Add(obj);
      fNBodies++;
   }
}

//--------------------------------
// methods for tail
//--------------------------------

//______________________________________________________________________________
void TNuRecs::AddToTail(TObject* obj)
{
   // Add obj to data, attaching 't' + the sequence number to the object

   //if (!(fNHeads+fNBodies)) {
   //   Error("Add", "The head and body is empty");
   //   return;
   //}

   if (obj) {
      ((TNuObject*)obj)->SetName(Form("%s_%dt",obj->GetName(), fNTails));
   }

   fRecs.Add(obj);

   fNTails++;
}

//______________________________________________________________________________
void TNuRecs::SetLineage()
{
   // set lineage of the records that belong to this

   // Firstly set parent-daughter relation as top-down
   for (Int_t n=0; n < GetSize(); n++) {
      TNuObject* obj = (TNuObject*) fRecs.At(n);
      if (obj) {
         obj->SetParent(this);
         obj->SetLineage();
      }
   }

   // for debugging
   //{
   //   printf("xxx: SetTransient of %s of %s\n", GetName(), GetParent()->GetName());
   //   GetParent()->ls();
   //}

   // Then sets the transient variables as bottom-up
   SetTransient();
}

//______________________________________________________________________________
void TNuRecs::Browse(TBrowser *b)
{
   // Browse TNuRecs

   if (!b) return;

   for (Int_t n=0; n < GetSize(); n++) {
      TNuObject* obj = (TNuObject*) fRecs.At(n);
      if (obj) b->Add(obj);
   }
}

//______________________________________________________________________________
void TNuRecs::What() const
{
   TNuObject::What();
   cout << "Params" << endl;
   cout << "   Entries = " << fNHeads << " + " << fNBodies << endl;
}

//______________________________________________________________________________
void TNuRecs::ls(Option_t* option) const
{
   // show the table of contents

   cout << Form("(%s) %s at %p: ",ClassName(), GetName(), this);
   cout << " / " << GetTitle() << endl;

   cout << "Head (" << fNHeads << " elements)" << endl;

   for (Int_t n=0; n < fNHeads; n++) {
      TNuObject* obj = (TNuObject*) HeadAt(n);
      if (obj) {
         cout << endl;
         cout << setw(5) << Form("h%d", n) << ". ";
         obj->ls(option);
      }
   }

   cout << "Body (" << fNBodies << " elements)" << endl;

   for (Int_t n=0; n < fNBodies; n++) {
      TNuObject* obj = (TNuObject*) BodyAt(n);
      if (obj) {
         cout << endl;
         cout << setw(5) << n << ". ";
         obj->ls(option);
      }
   }

   if (!fNTails) return;

   cout << "Tail (" << fNTails << " elements)" << endl;
   for (Int_t n=0; n < fNTails; n++) {
      TNuObject* obj = (TNuObject*) TailAt(n);
      if (obj) {
         cout << endl;
         cout << setw(5) << Form("t%d", n) << ". ";
         obj->ls(option);
      }
   }
}

//______________________________________________________________________________
void TNuRecs::Print(Option_t *opt) const
{
   // first set the print options and then print the contents
   TNuPrinter* printer = &TNudy::GetPrinter();
   printer->Set(this, opt);
   printer->PrintTopInfo(this);

   printer->AddIndent(+1);
   for (Int_t n=0; n < GetSize(); n++) {
      TNuObject* obj = (TNuObject*) fRecs.At(n);
      if (obj) obj->Print("-");
   }
   printer->AddIndent(-1);
}

