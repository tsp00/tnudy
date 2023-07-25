// TNuSec12Transitions.cxx  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

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
referred. The use of multiplicities is the recommended method of presenting (n,ャ) capture ャ-
ray cross sections, provided, of course, that the (n,ャ) cross section is adequately represented
in File 2 and/or File 3.
For well-established level decay schemes, the use of transition probability arrays offers
a concise method for presenting (n,xャ) information. With this method, the actual decay
scheme of the residual nucleus for a particular reaction (defined by MT number) is entered in
File 12. This information can then be used by a processing code together with discrete level
excitation cross sections from File 3 to calculate discrete ャ-ray production cross sections.
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

#include "TNuSec12Transitions.h"
#include "TF1.h"
#include "TMath.h"

#include <iostream>

ClassImp(TNuSec12Transitions)

//______________________________________________________________________________
TNuSec12Transitions::TNuSec12Transitions(Int_t mat, Int_t mf, Int_t mt) : TNuSec12(mat, mf, mt)
{
   // TNuSec12Transitions ctor
}

//______________________________________________________________________________
TNuSec12Transitions::~TNuSec12Transitions()
{
   // TNuSec12Transitions dtor
}

//______________________________________________________________________________
void TNuSec12Transitions::What() const
{
   using namespace std;
   TNuSection::What();

   cout << "\tLO = " << GetLO() << " : =2 means transition probabilities" << endl;
   cout << "\tNS  = " << GetNS() << " : Number of final states for which multiplicities are given" << endl;
}

//______________________________________________________________________________
void TNuSec12Transitions::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 3
   //

   SetHead(new TNuCont(src, "ZA, AWR, LO, LG, NS, 0/HEAD"));

   const Char_t *label= Form("%s%s",
      "ES, 0.0, LP, 0, (LG+1)*NT, NT; ES, TP",
      (GetLG()==2) ? ", GP" : "");
   Add(new TNuList(src, label));
}
