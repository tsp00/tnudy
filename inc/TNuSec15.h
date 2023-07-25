// TNuSec15.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

#ifndef ROOT_TNuSec15
#define ROOT_TNuSec15

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec15 --- File 15 : Continuous photon energy spectra
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) = TNuCont for
// [MAT, 15, MT/ ZA, AWR, 0, 0, NC, 0] HEAD
//
// ------------------ body --------------------------------------------------//
// BodyAt(j) = (i < NC) TNuRecsWithTab1
// [MAT, 15, MT/ 0.0, 0.0, 0, LF, NR, NP/ Eint/ pj(E)] TAB1 (LF=1)
//[MAT, 15, MT/ 0.0, 0.0, 0, 0, NR, NE/ Eint ] TNuTab2 (TAB2 of TAB1)
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF2.h"

#include "TNuTab1.h"
#include "TNuTab2.h"
#include "TNuRecsWithTab1.h"
class TNuEndfIO;

class TNuSec15 : public TNuSection, public TNuVF2
{
public:
   TNuSec15() : TNuSection(), TNuVF2() {}
   TNuSec15(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt) {}

   virtual ~TNuSec15() {}

   void          What() const; // *MENU*

   Int_t         GetNC() const  { return GetN1(); }

   const Char_t* GetSymbol() const { return "f(E, E_#gamma)"; }
   Bool_t        IsF2() const { return kTRUE; }
   void          DrawDXDmuNormalized() { Draw("surf"); } // *MENU*


   // default x-, y-axis labels
   const         Char_t* GetXAxisTitle() const { return "E [eV]"; }
   const         Char_t* GetYAxisTitle() const { return "E_#gamma [eV]"; }

   Double_t      EvalF2(Double_t En, Double_t mu, Double_t *ps=0) const;
   Double_t      DXDmuNormalized(Double_t E, Double_t mu) const { return EvalF2(E, mu); }

   void          ImportEndfData(TNuEndfIO& src);

   TNuTab1*      GetTab1At(Int_t n) const { return
      (n>=0 && n<GetNC()) ? (TNuTab1*) ((TNuRecsWithTab1*) BodyAt(n))->GetTab1() : 0; }

   TNuTab2*      GetTab2At(Int_t n) const { return
      (n>=0 && n<GetNC()) ? (TNuTab2*) ((TNuRecsWithTab1*) BodyAt(n))->BodyFirst() : 0; }

protected:
   void          SetTransient();


   ClassDef(TNuSec15, 1)//Continuous photon energy spectra
};

#endif

