// TNuSec09.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuSec09
#define ROOT_TNuSec09

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec09 - Multiplicities with respect to LFS, level number of the product
//
//
/*
HeadAt(0) = TNuCont for
[MAT, 9, MT/ ZA, AWR, LIS, 0, NS, 0]HEAD

---------------- body (NS elements)
BodyAt(n) = TNuTab1 for
[MAT, 9, MT/ QM, QI, IZAP, LFS, NR, NP/ Eint / Y (E)]TAB1
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuTab1.h"
#include "TNuEndfIO.h"
#include "TNuVF1s.h"

class TNuSec09 : public TNuSection, public TNuVF1s
{
public:
   TNuSec09() : TNuSection(), TNuVF1s() {}
   TNuSec09(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec09();

   void          What() const; // *MENU*
   //const Char_t* GetLRDescription() const;
   Int_t         GetLIS() const {return GetL1(); }
   Int_t         GetNS() const {return GetN1(); }


   const Char_t* GetSymbol() const { return "Y(E)"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   //Bool_t   IsF1() const { return kTRUE; }

   //Double_t EvalF1(Double_t Ein, Double_t *ps=0) {
   //   return GetTab1()->EvalF1(Ein, ps);
   //}
   //Double_t XSect(Double_t Ein, Double_t *ps=0) { return EvalF1(Ein, ps); }
   //void     DrawXSect() { Draw(); } // *MENU*

   Double_t GetMassDifferenceAt(Int_t n) const { return GetQMAt(n); }
   Double_t GetQMAt(Int_t n) const { return GetTab1At(n)->GetC1(); }
   //Double_t GetQValueAt(n) const   { return GetTab1At(n)->GetC2(); }
   Double_t GetQIAt(Int_t n) const { return GetTab1At(n)->GetC2(); }
   Int_t    GetZAPAt(Int_t n) const { return GetTab1At(n)->GetL1(); }
   Int_t    GetLFSAt(Int_t n) const { return GetTab1At(n)->GetL2(); }

   TNuTab1* GetTab1At(Int_t n) const { return (TNuTab1*) BodyAt(n); }
   Double_t EvalF1At(Int_t n, Double_t En, Double_t* ps) const { return
      (n>=0 && n < GetNS()) ? GetTab1At(n)->EvalF1(En, ps) : 0; }
   Int_t    NComponents() const { return GetNS(); }
   const Char_t* GetSymbolAt(Int_t n) const;

   void     ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();

   ClassDef(TNuSec09, 1) // Multiplicities of RN
};

#endif

