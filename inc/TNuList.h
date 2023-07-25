// TNuList.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuList
#define ROOT_TNuList

///////////////////////////////////////////////////////////////////////////////
//
// TNuList -- ENDF LIST record
//
// [MAT,MF,MT/ C1, C2, L1, L2, NPL, N2/ Bn] LIST
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCont.h"

class TNuEndfIO;

class TNuList : public TNuCont
{
public:
   TNuList() : TNuCont(), fData(0) {}
   TNuList(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuList(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NPL, N2");
   TNuList(const TNuList &list);
   TNuList& operator=(const TNuList &rhs);
   virtual ~TNuList();

   void          ImportEndfData(TNuEndfIO &src); 

   void          What() const; // *MENU*
   const         Char_t* GetEndfName() const { return "LIST"; }

   Double_t      operator[](Int_t i) { return At(i); }
   Double_t      At(Int_t i) const { return (i>=0 && i < fN1) ? fData[i] : 0; }
   void          SetAt(Double_t y, Int_t i);

   Double_t*     GetData() const { return fData; }
   //Double_t*&    GetData() { return fData; }
   Int_t         GetNPL() const { return fN1; }

   virtual void  SetCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   void          SetData(const Double_t *data);

   virtual void  Print(Option_t *opt) const; // *MENU*

protected:
   Double32_t*   fData; //[fN1]

private:
   void          ClearHeap();
   void          Init();

   ClassDef(TNuList, 1) //Class for ENDF LIST record
};

#endif
