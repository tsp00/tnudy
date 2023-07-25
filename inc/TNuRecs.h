//  TNuRecs.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuRecs
#define ROOT_TNuRecs

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

#include "TNuObject.h"
#include "TNuCont.h"
#include "TBrowser.h"
#include "TObjArray.h"

class TNuEndfIO;

class TNuRecs : public TNuObject
{
public:
   TNuRecs();
   virtual ~TNuRecs();

   //--------------------------------
   // basic routines
   //--------------------------------

   Bool_t        IsFolder() const  { return kTRUE; }
   void          Browse(TBrowser *b);
   void          SetLineage();

   void          What() const; // *MENU*

   virtual void  ls(Option_t* option="") const; // *MENU*
   virtual void  Print(Option_t *option="") const; // *MENU*

   Int_t         GetEntries() const { return fNHeads + fNBodies + fNTails; }
   Int_t         GetSize() const   { return GetEntries(); }

   TObjArray*    GetRecords() const { return (TObjArray*) &fRecs; }
   //TObjArray*&   GetRecords() { return (TObjArray*) &fRecs; }

   TNuObject*    At(Int_t at) const{ return (TNuObject*) fRecs.At(at); }
   TNuObject*    VAt(Int_t at) const { return At(at); }
   //TNuObject*&   operator[](Int_t at) { return (TNuObject*&) At(at); }
   TNuObject*    operator[](Int_t at) const{ return (TNuObject*) At(at); }

   //--------------------------------
   // methods for head
   //--------------------------------

   //virtual TNuCont* GetHead() const;

   TNuCont*      HeadCont() const; // retrieve the 1st TNuCont-derived record in head

   Double_t      GetC1() const { return HeadCont()->GetC1(); }
   Double_t      GetC2() const { return HeadCont()->GetC2(); }
   Int_t         GetL1() const { return HeadCont()->GetL1(); }
   Int_t         GetL2() const { return HeadCont()->GetL2(); }
   Int_t         GetN1() const { return HeadCont()->GetN1(); }
   Int_t         GetN2() const { return HeadCont()->GetN2(); }

   void          AddToHead(TObject *obj);

   void          SetHead(TNuObject* obj);
   void          SetCont(TNuCont* cont);


   TNuObject*    HeadAt(Int_t at) const;
   TNuObject*&   HeadAt(Int_t at);
   TNuObject*    GetHeadAt(Int_t at) const { return HeadAt(at); }

   Int_t         NHeads() const { return fNHeads; }

   TNuObject*    HeadFirst() const { return HeadAt(0); }
   TNuObject*    HeadLast() const { return  HeadAt(fNHeads - 1); }


   //--------------------------------
   // methods for body
   //--------------------------------
   void          Add(TObject* obj);

   TNuObject*    BodyAt(Int_t at) const;
   TNuObject*&   BodyAt(Int_t at);

   Int_t         NBodies() const { return fNBodies; }


   TNuObject*    BodyFirst() const { return BodyAt(0); }
   TNuObject*    BodyLast() const { return  BodyAt(fNBodies - 1); }

   //--------------------------------
   // methods for tail
   //--------------------------------

   void          AddToTail(TObject *obj);

   TNuObject*    TailAt(Int_t at) const;
   TNuObject*&   TailAt(Int_t at);
   TNuObject*    GetTailAt(Int_t at) const { return TailAt(at); }

   Int_t         NTails() const { return fNTails; }

   TNuObject*    TailFirst() const { return TailAt(0); }
   TNuObject*    TailLast() const { return  TailAt(fNTails - 1); }

protected:

   Int_t         fNHeads; // Number of head entries (including empty elements)
   Int_t         fNBodies;  // Number of body entries (including empty elements)
   Int_t         fNTails;  // Number of tail entries (including empty elements)

private:
   TObjArray     fRecs; // TObjArray of records that belong to this subsection

   ClassDef(TNuRecs, 1) // Base class for the collection of TNuObject elements.
};

//---- inlines -----------------------------------------------------------------

//--------------------------------
// methods for head
//--------------------------------

//______________________________________________________________________________
inline TNuObject* TNuRecs::HeadAt(Int_t at) const
{
   // Returns the n-th element in the head part

   if (at < 0 || at >= fNHeads) {
      return 0;
   }
   return (TNuObject*) fRecs[at];
}


//______________________________________________________________________________
inline TNuObject*& TNuRecs::HeadAt(Int_t at)
{
   // Returns the n-th element in the head part

   if (at < 0 || at >= fNHeads) {
      Warning("HeadAt", "The position at=%d is not in [0, %d)", at, fNHeads);
   }
   return (TNuObject*&) fRecs[at];
}


//______________________________________________________________________________
inline TNuCont* TNuRecs::HeadCont() const
{
   // find the first record that inherits from TNuCont

   return GetEntries() ? ((TNuObject*) fRecs.At(0))->HeadCont() : 0;
}

//--------------------------------
// methods for body
//--------------------------------

//______________________________________________________________________________
inline TNuObject* TNuRecs::BodyAt(Int_t at) const
{
   // Returns the n-th element in the data part

   if (at < 0 || at >= fNBodies) {
      return 0;
   }
   return (TNuObject*) fRecs[at + fNHeads];
}


//______________________________________________________________________________
inline TNuObject*& TNuRecs::BodyAt(Int_t at)
{
   // Returns the n-th element in the data part

   if (at < 0 || at >= fNBodies) {
      Warning("BodyAt", "The position at=%d is not in [0, %d)", at, fNBodies);
   }
   return (TNuObject*&) fRecs[at + fNHeads];
}


//--------------------------------
// methods for tail
//--------------------------------

//______________________________________________________________________________
inline TNuObject* TNuRecs::TailAt(Int_t at) const
{
   // Returns the n-th element in the tail part

   if (at < 0 || at >= fNTails) {
      return 0;
   }
   return (TNuObject*) fRecs[at + fNHeads + fNBodies];
}


//______________________________________________________________________________
inline TNuObject*& TNuRecs::TailAt(Int_t at)
{
   // Returns the n-th element in the tail part

   if (at < 0 || at >= fNTails) {
      Warning("TailAt", "The position at=%d is not in [0, %d)", at, fNTails);
   }
   return (TNuObject*&) fRecs[at + fNHeads + fNBodies];
}

#endif
