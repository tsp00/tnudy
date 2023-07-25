// TNuSec07002Coherent.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuSec07002Coherent
#define ROOT_TNuSec07002Coherent

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec07002 - Thermal neutron elastic coherent scattering data (E < 5 eV)
//
/*
This section describes the scattering data
Begin_Latex
#frac{d^{2}#sigma(E_{n}, E_{p}, #mu, T)}{dE_{p} d#Omega} = #frac{d#sigma(E_{n}, #mu, T)}{d#Omega} #delta(E_{n}-E_{p}),
End_Latex
for the thermal neutron energy range (En < 5 eV).

LTHR = GetL1() = 1, meaning that it is coherent scattering data  and provides
Begin_Latex
S(T, E) = #sum_{i}^{E_{i} < E} S_{i}(T)
End_Latex
such that
Begin_Latex
#frac{d#sigma(E, #mu, T)}{d#Omega} = #frac{1}{E} #sum_{i}^{E_{i}<E} S_{i}(T) #delta(#mu - #mu_{i}) /2#pi,
End_Latex
where #mu_{i} = 1 -2 E_{i}/E, T is the moderator temperature
and E_{i} are energies of the Bragg edges.

---------------- head (1 element)
HeadAt(0) = TNuCont for
[MAT, 7, 2/ ZA, AWR, LTHR, 0, 0, 0] HEAD LTHR=1

---------------- body (1 element)
BodyAt(0) = TNuTab1Lists for
[MAT, 7, 2/ T0, 0.0, LT, 0, NR, NP/ Eint / S(E,T0) ] TAB1
[MAT, 7, 2/ T1, 0.0, LI, 0, NP, 0/ S(Ei,T1) ] LIST
---------------------------
<repeat LIST for T2, T3, ...TLT>
--------------------------
[MAT, 7, 0/0.0, 0.0, 0, 0, 0, 0] SEND
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec07002.h"
#include "TNuVF2.h"

#include "TNuTab1Lists.h"


class TNuSec07002Coherent : public TNuSec07002, public TNuVF2
{
public:
   TNuSec07002Coherent() : TNuSec07002(), TNuVF2() {}
   TNuSec07002Coherent(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec07002Coherent();

   void          What() const; // *MENU*

   const Char_t* GetSymbol() const { return "S(T,E)"; }
   const Char_t* GetXAxisTitle() const { return "T [K]"; }
   const Char_t* GetYAxisTitle() const { return "E [eV]"; }

   Bool_t   IsF2() const { return IsCoherent(); }

   TNuTab1Lists* GetTab1Lists() const { return (TNuTab1Lists*) BodyFirst(); }
   Double_t EvalF2(Double_t T, Double_t Ein, Double_t * ps=0) const {
      return GetTab1Lists()->EvalF2(T, Ein, ps);
   }
   Double_t EvalS(Double_t T, Double_t Ein) const { return EvalF2(T, Ein); }

   Int_t    GetLTHR() const { return GetL1(); } // which type of thermal data
   Bool_t   IsCoherent() const { return GetLTHR() == 1; }
   Int_t    GetLT() const { return BodyFirst()->HeadCont()->GetL1(); } // Flag for temperature dependence
   Int_t    GetNTemperatures() const { return GetLT() + 1; } // number of data of different temeratures

   //void     ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();

   ClassDef(TNuSec07002Coherent, 1) //Thermal neutron elastic coherent scattering data (E < 5 eV)
};


#endif

