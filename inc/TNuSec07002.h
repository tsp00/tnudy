// TNuSec07002.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuSec07002
#define ROOT_TNuSec07002

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

#include "TNuSection.h"

#include "TNuEndfIO.h"

class TNuSec07002 : public TNuSection
{
public:
   TNuSec07002() : TNuSection() {}
   TNuSec07002(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec07002();

   Int_t    GetLTHR() const { return GetL1(); } // which type of thermal data
   Bool_t   IsCoherent() const { return GetLTHR() == 1; }
   Int_t    GetLT() const { return BodyFirst()->HeadCont()->GetL1(); } // Flag for temperature dependence
   Int_t    GetNTemperatures() const { return GetLT() + 1; } // number of data of different temeratures

   void     ImportEndfData(TNuEndfIO& src);
private:

   ClassDef(TNuSec07002, 1) //Thermal neutron scattering data (E < 5 eV)
};

#endif

