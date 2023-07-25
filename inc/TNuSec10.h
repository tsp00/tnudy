// TNuSec10.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

#ifndef ROOT_TNuSec10
#define ROOT_TNuSec10

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec10 - Product cross sections
//
//
/*
Neutron activation cross sections [such as the (n,p) and (n,2n) cross sections] and cross
sections for a particular state of a radioactive target are given in File 10. These cross
sections are given as a function of energy E, where E is the incident particle or photon
energy (in eV) in the laboratory system. They are given as energy-cross-section pairs. An
interpolation scheme must specify the energy variation of the data for energies between a
given energy point and the next higher energy point.
File 10 is divided into sections, each section containing the data for a particular reaction
type (MT number). The sections are ordered by increasing MT number. Within a section for
a given MT are subsections for different final states (LFS) of the daughter product nucleus.
File 10 is allowed only for evaluations that represent the data for single isotopes.

---------------- head
HeadAt(0) = TNuCont for
[MAT, 9, MT/ ZA, AWR, LIS, 0, NS, 0]HEAD

---------------- body (NS elements)
At(n) = TNuTab1 for
[MAT, 9, MT/ QM, QI, IZAP, LFS, NR, NP/ Eint / Y (E)]TAB1
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuTab1.h"
#include "TNuVF1s.h"
#include "TNuEndfIO.h"

class TNuSec10 : public TNuSection, TNuVF1s
{
public:
   TNuSec10() : TNuSection(), TNuVF1s() {}
   TNuSec10(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec10();

   void          What() const; // *MENU*
   //const Char_t* GetLRDescription() const;
   Int_t         GetLIS() const {return GetL1(); }
   Int_t         GetNS() const {return GetN1(); }
   Int_t         NComponents() const { return GetNS(); }


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
   Int_t    GetIZAPAt(Int_t n) const { return GetTab1At(n)->GetL1(); }
   Int_t    GetLFSAt(Int_t n) const { return GetTab1At(n)->GetL2(); }

   TNuTab1* GetTab1At(Int_t n) const { return (TNuTab1*) BodyAt(n); }
   Double_t EvalF1At(Int_t n, Double_t En, Double_t* ps=0) const { return GetTab1At(n)->EvalF1(En, ps); }

   void     ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();

   ClassDef(TNuSec10, 1)  // Product cross sections
};

#endif

