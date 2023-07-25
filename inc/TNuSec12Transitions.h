// TNuSec12Transitions.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

#ifndef ROOT_TNuSec12Transitions
#define ROOT_TNuSec12Transitions

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec12Transitions - Multiplicities (LO=1)
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

12.2.2 Option 2: Transition Probability Arrays (LO=2)
With this option, the only data required are the level energies, de-excitation transition
probabilities, and (where necessary) conditional photon emission probabilities. Given this
information, the photon energies and their multiplicities can readily be calculated. Photon
production cross sections can then be computed for any given level from the excitation
cross sections in File 3, along with the transition probability array. Similarly, multiplicities
and photon production cross sections can be constructed for the total cascade. For any
given level, the transition and photon emission probability data given in the section are for
photons originating at that level only; any further cascading is determined from the data
for the lower levels.

---------------- head
HeadAt(0) = TNuCont for
[MAT, 12, MT/ ZA, AWR, LO, 0, NK, 0]HEAD (LO=1)

HeadAt(1) = TNuTab1 (optional if NK > 1) for
[MAT, 12, MT/ 0.0, 0.0, 0, 0, NR, NP/Eint / Y (E)] TAB1 (if NK>1)

---------------- body (NK elements)
BodyAt(n) = TNuTab1 for
[MAT, 12, MT/ Eg, ES, LP, LF, NR, NP/ Eint / y(E)] TAB1
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec12.h"
#include "TNuTab1.h"
#include "TNuList.h"
#include "TNuEndfIO.h"


class TNuSec12Transitions : public TNuSec12
{
public:
   TNuSec12Transitions() {}
   TNuSec12Transitions(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec12Transitions();

   void          What() const; // *MENU*
   //const Char_t* GetLRDescription() const;
   //Int_t         GetLO() const {return GetL1(); }
   //Int_t         GetNS() const {return GetN1(); }

   const Char_t* GetSymbol() const { return "Y(E)"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   //Bool_t   IsF1() const { return kTRUE; }

   //Double_t EvalF1(Double_t Ein, Double_t *ps=0) {
   //   return GetTab1()->EvalF1(Ein, ps);
   //}
   //Double_t XSect(Double_t Ein, Double_t *ps=0) { return EvalF1(Ein, ps); }
   //void     DrawXSect() { Draw(); } // *MENU*

   Int_t    GetLG() const { return GetL2(); }
   //Int_t    GetNS() const { return GetN1(); }

   Double_t GetES() const { return GetList()->GetC1(); }
   Int_t    GetLP() const { return GetList()->GetL1(); }

   TNuList* GetList() const { return (TNuList*) BodyAt(0); }

   void     ImportEndfData(TNuEndfIO& src);
private:

   ClassDef(TNuSec12Transitions, 1) // Multiplicities in transitions
};

#endif

