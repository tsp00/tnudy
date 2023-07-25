// TNuSec07002Incoherent.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuSec07002Incoherent
#define ROOT_TNuSec07002Incoherent

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec07002Incoherent - Thermal neutron elastic incoherent scattering data (E < 5 eV)
/*
This section describes the scattering data
Begin_Latex
#frac{d^{2}#sigma(E_{n}, E_{p}, #mu, T)}{dE_{p} d#Omega} = #frac{d#sigma(E_{n}, #mu, T)}{d#Omega} #delta(E_{n}-E_{p}},
End_Latex
for the thermal neutron energy range (En < 5 eV).

LTHR = GetL1() = 2, meaning that it is for inelastic scattering data,
and provides Wp(T) such that
Begin_Latex
#frac{d#sigma(E_{n}, #mu, T)}{d#Omega} = #frac{#sigma_{b}}{4#pi} e^{-2 E_{n} W'(T)(1-#mu)},
End_Latex
where #sigma_{b} is the characteristic bound cross section (barns),
and Wp(T) is the DebyeWaller integral divided by the atomic mass.

---------------- head (1 element)
HeadAt(0) = TNuCont for
[MAT, 7, 2/ ZA, AWR, LTHR, 0, 0, 0] HEAD LTHR=2

---------------- body (1 element)
BodyAt(0) = TNuTab1 for
[MAT, 7, 2/ SB, 0.0, 0, 0, NR, NP/ Wp(T) ] TAB1
where SB stands for he characteristic bound cross section.
*/
//
///////////////////////////////////////////////////////////////////////////////


#include "TNuSec07002.h"
#include "TNuVF1.h"
#include "TNuTab1.h"
//#include "TNuTab1Lists.h"
//#include "TNuEndfIO.h"

class TNuSec07002Incoherent : public TNuSec07002, public TNuVF1
{
public:
   TNuSec07002Incoherent() {}
   TNuSec07002Incoherent(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec07002Incoherent();

   void          What() const; // *MENU*

   const Char_t* GetSymbol() const { return "W(T)"; }
   const Char_t* GetXAxisTitle() const { return  "T [K]"; }

   Bool_t   IsF1() const { return kTRUE; }

   TNuTab1* GetTab1() const { return (TNuTab1*) BodyFirst(); }

   Double_t EvalF1(Double_t Ein, Double_t *ps=0) const {
      return GetTab1()->EvalF1(Ein, ps);
   }

   Int_t    GetLTHR() const { return GetL1(); } // which type of thermal data
   Bool_t   IsCoherent() const { return GetLTHR() == 1; }

   //void     ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();

private:

   ClassDef(TNuSec07002Incoherent, 1) //Thermal neutron elastic incoherent scattering data (E < 5 eV)
};


#endif

