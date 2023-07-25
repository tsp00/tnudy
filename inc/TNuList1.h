// TNuList1.h  =====================================================
// Author: Tae-Sun Park   Feb 24 2012

#ifndef ROOT_TNuList1
#define ROOT_TNuList1

///////////////////////////////////////////////////////////////////////////////
//
// TNuList1
//
// -- Service class for TNuList with TNuVF1
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuList.h"
#include "TNuVF1.h"

class TNuEndfIO;

class TNuList1 : public TNuList, public TNuVF1
{
public:
   TNuList1() : TNuList(), TNuVF1() {}
   TNuList1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuList1(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NPL, N2");
   //TNuList1(TNuCont *cont);
   virtual ~TNuList1() {}

   Int_t    GetNL() const { return GetN1(); }

   Bool_t   IsF1() const { return kTRUE; }
   Double_t EvalF1(Double_t x, Double_t *ps = 0) const = 0;
   void     DrawTF1() { Draw(); } // *MENU*

   Int_t    GetNPar() const { return 0; }

protected:
   //void     SetTransient();

   ClassDef(TNuList1, 1) //Service class for TNuList with TNuVF1
};

#endif

