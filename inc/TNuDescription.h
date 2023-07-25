// TNuDescription.h  =====================================================
// Author: Tae-Sun Park   Feb 03 2011

#ifndef ROOT_TNuDescription
#define ROOT_TNuDescription

///////////////////////////////////////////////////////////////////////////////
//
// TNuDescription
//
// This record is used to give the comments in File 1.
// It is indicated by the following shorthand notation
// [MAT, MF, MT/ HL] TEXT
// where HL is 66 characters of text information.
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuObject.h"
#include "TString.h"

class TNuDescription : public TNuObject
{
public:
   TNuDescription() : TNuObject(), fSize(0) {}
   TNuDescription(Int_t n) : TNuObject(), fSize(n) { Set(n); }
   virtual ~TNuDescription();

   void           Set(Int_t n);
   void           Add(const Char_t *text);

   const Char_t*  operator[](Int_t i) const { return At(i); }
   const Char_t*  At(Int_t i) const { return (i>=0 && i < fSize) ? fData(67*i, 66).Data() : 0; }
   //const Char_t*  First() const { return At(0); }
   //const Char_t*  Last() const { return fSize ? At(fSize-1) : 0; }

   Int_t          GetEntries() const { return GetSize(); }
   Int_t          GetSize() const { return fSize; }
   Int_t          NRecords() const { return GetSize(); }
   const TString& GetString() const { return fData; }
   virtual void   Print(Option_t *opt) const; // *MENU*
   void           What() const; // *MENU*

private:
   Int_t          fSize; // number of lines
   TString        fData; // string data of length (66+1)*fSize

   ClassDef(TNuDescription, 1) // class for text data
};

#endif
