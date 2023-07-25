// TNuSec27.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2011

#ifndef ROOT_TNuSec27
#define ROOT_TNuSec27

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec27 - Atomic form factors or scattering functions
//
/*
The ENDF system for neutron and photon production data allows two alternatives for
storing angular distribution data. One is by probability per unit cos(#theta) vs. cos(#theta), and
the other is by Legendre coefficients. Actually, neither of these is a natural method
for photons. The natural method would be atomic form factors or incoherent scattering
functions.
*/
// = [MAT, 27, MT/ ZA, AWR, 0, 0, 0, 0] HEAD
//   [MAT, 27, MT/ 0.0, Z, 0, 0, NR, NP/ qint / H(q;Z)]TAB1
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF1.h"

#include "TNuTab1.h"
#include "TNuEndfIO.h"

class TNuSec27 : public TNuSection, public TNuVF1
{
public:
   TNuSec27() : TNuSection(), TNuVF1() {}
   TNuSec27(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec27();

   void          What() const; // *MENU*

   const Char_t* GetSymbol() const { return "#sigma(E) [barn]"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   Bool_t   IsF1() const { return kTRUE; }

   Double_t EvalF1(Double_t Ein, Double_t *ps=0) const {
      return GetTab1()->EvalF1(Ein, ps);
   }
   Double_t H(Double_t Ein, Double_t *ps=0) const { return EvalF1(Ein, ps); }
   void     DrawH() { Draw(); } // *MENU*

   Double_t GetZ() const { return GetTab1()->GetC2(); }

   TNuTab1* GetTab1() const { return (TNuTab1*) BodyFirst(); }

   void     ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();

   ClassDef(TNuSec27, 1) //Atomic form factors or scattering functions
};

#endif

