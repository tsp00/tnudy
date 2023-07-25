// TNuSec12.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

#ifndef ROOT_TNuSec12
#define ROOT_TNuSec12

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec12 - Multiplicities and transition probability arrays
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
referred. The use of multiplicities is the recommended method of presenting (n,) capture -
ray cross sections, provided, of course, that the (n,) cross section is adequately represented
in File 2 and/or File 3.
For well-established level decay schemes, the use of transition probability arrays offers
a concise method for presenting (n,x) information. With this method, the actual decay
scheme of the residual nucleus for a particular reaction (defined by MT number) is entered in
File 12. This information can then be used by a processing code together with discrete level
excitation cross sections from File 3 to calculate discrete -ray production cross sections.
This option cannot be used to represent the integrals of continuous photon spectra.


---------------- head
HeadAt(0) = TNuCont for
[MAT, 12, MT/ ZA, AWR, LO,  0, NK, 0]HEAD (for LO=1)
[MAT, 12, MT/ ZA, AWR, LO, LG, NS, 0]HEAD (for LO=2)

The structure of body depends on LO.
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuTab1.h"
#include "TNuEndfIO.h"

class TNuSec12 : public TNuSection
{
public:
   TNuSec12() {}
   TNuSec12(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec12();

   void          What() const; // *MENU*

   Int_t         GetLO() const {return GetL1(); }
   Int_t         GetNS() const {return GetN1(); }


   const Char_t* GetSymbol() const { return "Y(E)"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   //Bool_t   IsF1() const { return kTRUE; }

   //Double_t EvalF1(Double_t Ein, Double_t *ps=0) {
   //   return GetTab1()->EvalF1(Ein, ps);
   //}
   //Double_t XSect(Double_t Ein, Double_t *ps=0) { return EvalF1(Ein, ps); }
   //void     DrawXSect() { Draw(); } // *MENU*

private:

   ClassDef(TNuSec12, 1) // Multiplicities and transition probability arrays
};

#endif

