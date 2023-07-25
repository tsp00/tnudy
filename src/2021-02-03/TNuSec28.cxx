// TNuSec28.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec28 - Atomic relaxation data
//
/*


An atom can be ionized due to a variety of interactions. For example, due to photon or
electron interactions the probability of ionizing a particular subshell of the atomic structure
(K, L1, L2, etc.) is determined by using the subshell cross sections (MT=534-599). For
example, if an incident photon of energy E ionizes the K subshell with binding energy EK,
the atom will emit an electron with energy E - EK, and the atomic structure will be left
ionized, with a hole in the K subshell. One way the atom can proceed to fill this hole is
to bring down an electron from a higher energy level, for example L1, with the simultaneous
emission of an X-ray of energy EK - EL1. This is a radiative transition. An alternative
path is to bring down an electron from a higher level with the simultaneous emission of an
electron from that level or a higher one. As an example, you might see an electron of energy
EK - EL1 - EM1, which fills the vacancy in the K shell and leaves new holes in the L1 and M1
shells. These are called non-radiative transitions. The process will then continue by filling
the new holes from higher levels, etc., until all the ionization energy has been accounted for
by the emission of X-rays and electrons.
The electrons produced by this atomic relaxation can be used as a source for a subsequent
electron transport calculation, or their energy can just be added to the local heating. The
X-rays can be transported elsewhere to cause additional photo-atomic reactions. In general,
the use of File 28 is indicated when high-Z materials are present and photon energies of less
than 1 MeV are of interest.
This file is provided to give the information necessary to compute the emission of Xrays
and electrons associated with atomic relaxation cross section. It is based on EADL, the
Evaluated Atomic Data Library developed by D. E. (Red) Cullen at the Lawrence Livermore
National Laboratory (LLNL).
This file gives the subshell energies, emission energies, transition probabilities, and other
quantities needed to compute the X-ray and electron spectra from ionized atoms. It always
uses MT=533. It works together

HeadAt(0) = TNuCont for
[MAT,28,533/ ZA, AWR, 0, 0, NSS, 0]HEAD

BodyAt(n) = a TNuList, n=[0, NSS)
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec28.h"
#include "TF1.h"

#include "TNuList.h"

#include <iostream>

ClassImp(TNuSec28)

//______________________________________________________________________________
TNuSec28::TNuSec28(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec28 ctor
}

//______________________________________________________________________________
TNuSec28::~TNuSec28()
{
   // TNuSec28 dtor
}

//______________________________________________________________________________
void TNuSec28::What() const
{
   using namespace std;
   TNuSection::What();
}

//______________________________________________________________________________
void TNuSec28::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of MF=28 and MT=?
   //

   // Atomic relaxation data
   //
   SetHead(new TNuCont(src, "ZA, AWR, 0, 0, NSS, 0]HEAD"));
   for (Int_t n=0; n < GetNSS(); n++) {
      Int_t ntr= src.GetN2();
      const Char_t *label = Form("%s %s",
         "SUBI, 0.0, 0, 0, NW, NTR" // NW=6*(1+NTR)"
         ";EBI1, ELN1, 0.0, 0.0, 0.0, 0.0",
         (ntr > 0) ?  "&SUBJ, SUBK, ETR, FTR, 0.0, 0.0" : "");
      Add(new TNuList(src, label));
   }
   return;
}

