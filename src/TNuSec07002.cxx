// TNuSec07002.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec07002 - Thermal neutron scattering data (E < 5 eV)
//
/*
This section describes the scattering data
Begin_Latex
#frac{d^{2}#sigma(E_{n}, E_{p}, #mu, T)}{dE_{p} d#Omega} = #frac{d#sigma(E_{n}, #mu, T)}{d#Omega} #delta(E_{n}-E_{p}),
End_Latex
for the thermal neutron energy range (En < 5 eV).

Depending on the value of LTHR = GetL1(), it is one of the two:

LTHR=1 : TNuSec07002Coherent for coherent scattering data,

LTHR=2 : TNuSec07002Incoherent for incoherent scattering data.
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec07002.h"
#include "TF1.h"

#include "TNuTab1Lists.h"
#include "TNuTab1ListsSub.h"

#include <iostream>

ClassImp(TNuSec07002)

//______________________________________________________________________________
TNuSec07002::TNuSec07002(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec07002 ctor
}

//______________________________________________________________________________
TNuSec07002::~TNuSec07002()
{
   // TNuSec07002 dtor
}

//______________________________________________________________________________
void TNuSec07002::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of MF=7, MT=2
   //

   SetHead(new TNuCont(src, "ZA, AWR, LTHR, 0, 0, 0/HEAD"));
   if (GetLTHR()==1) {
      // LTHR=1 for coherent elastic scattering
      TNuTab1Lists *tab1lists = new TNuTab1Lists();
      TNuTab1 *tab1 = new TNuTab1(src,
         "T_0, 0.0, LT, 0, NR, NP/ S(E;T_0)");
      tab1lists->SetTab1(tab1);
      for (Int_t lt=1; lt <= tab1lists->GetLT(); lt++) {
         TString label = Form("T_%d, 0.0, LI, 0, NP, 0/ S(E;T_%d)", lt,lt);
         tab1lists->Add(new TNuTab1ListsSub(src, label));
      }
      Add(tab1lists);
   }
   else if (GetLTHR()==2) {
      // LTHR=2 for incoherent elastic scattering
      Add(new TNuTab1(src,
         "SB, 0.0, 0, 0, NR, NP/ Tint / W'(T)"));
   }
   else {
      Error("ImportEndfData", "Unsupported value of LTHR=%d", GetLTHR());
   }
}
