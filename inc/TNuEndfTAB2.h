//  TNuEndfTAB2.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuEndfTAB2
#define ROOT_TNuEndfTAB2

///////////////////////////////////////////////////////////////////////////////
//
// TNuEndfTAB2
//
// Class for the ENDF TAB2:
//   C1 C2 L1 L2 NR NZ
//   (NBT(n), INT(n), n=1,NR)
//
// Since TAB2 appears only with following other records,
// this class is mainly for backward compatibility.
// It serves also as the base class for TNuTab1.
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCont.h"
#include "TNuVTab.h"

class TNuEndfIO;

class TNuEndfTAB2 : public TNuCont, public TNuVTab
{
public:
   TNuEndfTAB2() : TNuCont(), TNuVTab(), fNBT(0), fINT(0) {}
   TNuEndfTAB2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuEndfTAB2(const TNuEndfTAB2 &rhs);
   TNuEndfTAB2(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NR, NZ");
   // TNuEndfTAB2(const TNuEndfTAB2 &tab2);
   virtual ~TNuEndfTAB2();
   TNuEndfTAB2& operator=(const TNuEndfTAB2 &rhs);
   virtual void SetCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);

   void     ImportEndfData(TNuEndfIO &src);

   void     What() const; // *MENU*
   const Char_t* GetEndfName() const { return "TAB2"; }

   // const Int_t* NBT() const { return fNBT; }
   Int_t*   GetNBT() const { return fNBT; }
   Int_t    GetNBT(Int_t i) const { return (i>=0 && i < fN1) ? fNBT[i] : 0; }
   //  const Int_t* INT() const { return fINT; }
   Int_t*   GetINT() const { return fINT; }
   Int_t    GetINT(Int_t i) const { return (i>=0 && i < fN1) ? fINT[i] : 0; }
   void     SetNBT(Int_t data, Int_t at) { if (at>=0 && at < fN1) fNBT[at] = data; }
   void     SetINT(Int_t data, Int_t at) { if (at>=0 && at < fN1) fINT[at] = data; }

   Int_t    GetNR() const { return fN1; }
   Int_t    GetNZ() const { return fN2; }
   virtual void  SetNR(Int_t nr);
   virtual void  SetNZ(Int_t nz) { fN2 = nz; }

   virtual void  Print(Option_t *opt) const; // *MENU*
   Int_t    GetInterpolationLaw(Int_t pos) const;

protected:
   Int_t*   fNBT;    //[fN1]
   Int_t*   fINT;    //[fN1]

private:
   void     ClearHeap();

   ClassDef(TNuEndfTAB2, 1) // Class for the ENDF TAB2 record
};

#endif
