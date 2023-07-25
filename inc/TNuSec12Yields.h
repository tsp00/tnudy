// TNuSec12Yields.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

#ifndef ROOT_TNuSec12Yields
#define ROOT_TNuSec12Yields

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec12Yields - Multiplicities (LO=1)
//
//
/*
File 12 can be used to represent the neutron energy dependence of photon production cross
sections or delayed photon source functions by means of either multiplicities or transition
probability arrays. Both methods rely upon processing codes that use either neutron cross
sections from File 2 and/or File 3 to generate absolute photon production cross sections or
time constants from File 1 (MT=460) to generate delayed photon source functions.
Multiplicities can be used to represent the cross sections of discrete photons and/or the
integrated cross sections of continuous photon spectra. The MT numbers in File 12 designate
the particular neutron cross sections (File 2 and/or File 3) to which the multiplicities are
referred. The use of multiplicities is the recommended method of presenting (n,#gamma) capture #gamma-
ray cross sections, provided, of course, that the (n,#gamma) cross section is adequately represented
in File 2 and/or File 3.
For well-established level decay schemes, the use of transition probability arrays offers
a concise method for presenting (n,x #gamma) information. With this method, the actual decay
scheme of the residual nucleus for a particular reaction (defined by MT number) is entered in
File 12. This information can then be used by a processing code together with discrete level
excitation cross sections from File 3 to calculate discrete #gamma-ray production cross sections.
This option cannot be used to represent the integrals of continuous photon spectra.


---------------- head
HeadAt(0) = TNuCont for
[MAT, 12, MT/ ZA, AWR, LO, 0, NK, 0]HEAD (LO=1)

HeadAt(1) = TNuTab1 (optional if NK > 1) for
[MAT, 12, MT/ 0.0, 0.0, 0, 0, NR, NP/Eint / Y(E)] TAB1 (if NK>1)

---------------- body (NK elements)
BodyAt(n) = TNuTab1 for
[MAT, 12, MT/ Eg, ES, LP, LF, NR, NP/ Eint / y(E)] TAB1
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec12.h"
#include "TNuTab1.h"
#include "TNuEndfIO.h"
#include "TNuVF1s.h"

class TNuSec12Yields : public TNuSec12, public TNuVF1s
{
public:
   TNuSec12Yields() : TNuSec12(), TNuVF1s() {}
   TNuSec12Yields(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec12Yields();

   void          What() const; // *MENU*
   //const Char_t* GetLRDescription() const;
   Int_t         GetLO() const {return GetL1(); }
   Int_t         GetNK() const {return GetN1(); }


   const Char_t* GetSymbol() const { return "Y(E)"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   //Bool_t   IsF1() const { return kTRUE; }

   //Double_t EvalF1(Double_t Ein, Double_t *ps=0) {
   //   return GetTab1()->EvalF1(Ein, ps);
   //}
   //Double_t XSect(Double_t Ein, Double_t *ps=0) { return EvalF1(Ein, ps); }


   TNuTab1* GetTab1() const { return
      (GetNK() > 1) ? (TNuTab1*) HeadAt(1) : (TNuTab1*) BodyFirst(); }

   Double_t EvalF1(Double_t En, Double_t* ps=0) const { return GetTab1()->EvalF1(En, ps); }
   Double_t TotalYield(Double_t En) const { return EvalF1(En); }
   void     DrawTotalYield() { GetTab1()->Draw(); } // *MENU*

   Double_t GetEGAt(Int_t n) const { return GetTab1At(n)->GetC1(); }
   Double_t GetESAt(Int_t n) const { return GetTab1At(n)->GetC2(); }
   Int_t    GetLPAt(Int_t n) const { return GetTab1At(n)->GetL1(); }
   Int_t    GetLFAt(Int_t n) const { return GetTab1At(n)->GetL2(); }

   TNuTab1* GetTab1At(Int_t n) const { return (TNuTab1*) BodyAt(n); }
   Double_t EvalF1At(Int_t n, Double_t En, Double_t* ps) const { return
      (n>=0 && n < GetNK()) ? GetTab1At(n)->EvalF1(En, ps) : 0; }
   const Char_t* GetSymbolAt(Int_t n) const;
   Int_t    NComponents() const { return GetNK(); }

   void     ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();

   ClassDef(TNuSec12Yields, 1)//Multiplicities in yields
};

#endif

