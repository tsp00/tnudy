// TNuDirs.h  =====================================================
// Author: Tae-Sun Park   Feb 03 2011

#ifndef ROOT_TNuDirs
#define ROOT_TNuDirs

///////////////////////////////////////////////////////////////////////////////
//
// TNuDirs
//
// This record is used to give the comments in File 1.
// It is indicated by the following shorthand notation
// [MAT, MF, MT/ HL] TEXT
// where HL is 66 characters of text information.
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuObject.h"
#include "TArrayS.h"
class TNuCont;

class TNuDirs : public TNuObject
{
public:
   TNuDirs() : TNuObject(), fSize(0), fEntries(0) {}
   TNuDirs(Int_t n) : TNuObject(), fSize(n), fEntries(0) { Set(n); }
   virtual ~TNuDirs();

   void          Set(Int_t n);

   void          Add(Short_t data[4]);
   void          Add(TNuCont *data);

   Short_t* operator[](Int_t n) const { return At(n); }
   Short_t* At(Int_t n) const { return (n>=0 && n < fSize) ? (Short_t*) fData.GetArray() + 4*n : 0; }
   //Short_t* First() const { return At(0); }
   //Short_t* Last() const { return fEntries ? At(fEntries-1) : 0; }

   Int_t GetMFAt(Int_t n) const  { return (n>=0 && n < fSize) ? fData[4*n] : 0; }
   Int_t GetMTAt(Int_t n) const  { return (n>=0 && n < fSize) ? fData[4*n+1] : 0; }
   Int_t GetNCAt(Int_t n) const  { return (n>=0 && n < fSize) ? fData[4*n+2] : 0; }
   Int_t GetMODAt(Int_t n) const { return (n>=0 && n < fSize) ? fData[4*n+3] : 0; }

   TNuCont*      GetContAt(Int_t n) const;
   TNuCont*      GetContAt(Int_t n, TNuCont* cont) const;

   Int_t         GetEntries() const { return fEntries; }
   Int_t         GetSize() const { return fSize; }
   void          SetSize(Int_t nxc) { fSize = nxc; }
   Int_t         NRecords() const { return GetSize(); }

   virtual void  Print(Option_t *opt) const; // *MENU*
   void          What() const; // *MENU*

private:
   Int_t         fSize; // number of lines
   Int_t         fEntries; //! current position

   TArrayS       fData; // short data of length 4*fSize

   ClassDef(TNuDirs, 1) // class for text data
};

#endif
