// TNuCont.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuCont
#define ROOT_TNuCont

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuCont  -- ENDF CONT record                                       //
//                                                                    //
// [MAT,MF,MT/C1,C2,L1,L2,N1,N2]CONT                                  //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuObject.h"

class TNuEndfIO;

class TNuCont : public TNuObject
{
public:
   TNuCont();
   TNuCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuCont(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, N1, N2");
   TNuCont(const TNuCont &cont);
   TNuCont&      operator=(const TNuCont &rhs);
   virtual      ~TNuCont();

   virtual void  ImportEndfData(TNuEndfIO &src);
   virtual void  ls(Option_t* option="") const; // *MENU*
   virtual void  Print(Option_t* option="") const; // *MENU*

   TNuCont*      HeadCont() const { return (TNuCont*) this; }
   const         Char_t* GetEndfName() const { return "CONT"; }

   Double_t      GetC1() const { return fC1; }
   Double_t      GetC2() const { return fC2; }
   Int_t         GetL1() const { return fL1; }
   Int_t         GetL2() const { return fL2; }
   Int_t         GetN1() const { return fN1; }
   Int_t         GetN2() const { return fN2; }

   void          SetC1(Double_t c1) { fC1 = c1; }
   void          SetC2(Double_t c2) { fC2 = c2; }
   void          SetL1(Int_t l1)    { fL1 = l1; }
   void          SetL2(Int_t l2)    { fL2 = l2; }
   void          SetN1(Int_t n1)    { fN1 = n1; }
   void          SetN2(Int_t n2)    { fN2 = n2; }

   virtual void  SetCont (Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
                  { fC1=c1; fC2=c2; fL1=l1; fL2=l2; fN1=n1; fN2=n2; }

   //virtual void  SetCont(const TNuCont *cont);

   void          Scan(Double_t *c1, Double_t *c2, Int_t *l1, Int_t *l2, Int_t *n1, Int_t *n2) const
                  { *c1=fC1; *c2=fC2; *l1=fL1; *l2=fL2; *n1=fN1; *n2=fN2; }

   void          Scan(Double_t &c1, Double_t &c2, Int_t &l1, Int_t &l2, Int_t &n1, Int_t &n2) const
                  { c1=fC1; c2=fC2; l1=fL1; l2=fL2; n1=fN1; n2=fN2; }


   virtual Int_t NRecords() const { return 1; }

protected:
   Double32_t fC1; // C1 data of CONT record
   Double32_t fC2; // C2 data of CONT record
   Int_t      fL1; // L1 data of CONT record
   Int_t      fL2; // L2 data of CONT record
   Int_t      fN1; // N1 data of CONT record
   Int_t      fN2; // N2 data of CONT record

   ClassDef(TNuCont, 1) // Class for the ENDF CONT record
};
#endif
