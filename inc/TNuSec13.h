// TNuSec13.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

#ifndef ROOT_TNuSec13
#define ROOT_TNuSec13

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec13 - Photon production cross sections
// 
//
/*
The purpose of File 13 is the same as that of File 12, namely, it can be used to represent
the neutron and photon energy dependence of photon production cross sections. In File 13,
however, absolute cross sections in barns are tabulated, and there is no need to refer to the
cross sections in File 3.
---------------- head
HeadAt(0) = TNuCont for
[MAT, 13, MT/ ZA, AWR, 0, 0, NK, 0]HEAD

HeadAt(1) = TNuTab1 (optional if NK > 1) for
[MAT, 13, MT/ 0.0, 0.0, 0, 0, NR, NP/ Eint/ #sigma_{total}^#{gamma} TAB1 (if NK>1)

---------------- body (NK elements)
BodyAt(n) = TNuTab1 for
[MAT, 13, MT/ EG, ES, LP, LF, NR, NP/ Eint / y(E)] TAB1
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuTab1.h"
#include "TNuEndfIO.h"


class TNuSec13 : public TNuSection
{
public:
   TNuSec13() {}
   TNuSec13(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec13();

   void          What() const; // *MENU*
   //const Char_t* GetLRDescription() const;
   Int_t         GetNK() const {return GetN1(); }

   const Char_t* GetSymbol() const { return "Y(E)"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   //Bool_t   IsF1() const { return kTRUE; }

   //Double_t EvalF1(Double_t Ein, Double_t *ps=0) {
   //   return GetTab1()->EvalF1(Ein, ps);
   //}
   //Double_t XSect(Double_t Ein, Double_t *ps=0) { return EvalF1(Ein, ps); }
   //void     DrawXSect() { Draw(); } // *MENU*

   Double_t GetEGAt(Int_t n) const { return GetTab1At(n)->GetC1(); }
   Double_t GetESAt(Int_t n) const { return GetTab1At(n)->GetC2(); }
   Int_t    GetLPAt(Int_t n) const { return GetTab1At(n)->GetL1(); }
   Int_t    GetLFAt(Int_t n) const { return GetTab1At(n)->GetL2(); }

   TNuTab1* GetTab1At(Int_t n) const { return (TNuTab1*) BodyAt(n); }

   void     ImportEndfData(TNuEndfIO& src);

private:

   ClassDef(TNuSec13, 1)//Photon production cross sections
};

#endif

