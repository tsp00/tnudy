// TNuSec12.cxx  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec12 - Multiplicities and transition probability arrays
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
[MAT, 9, MT/ ZA, AWR, LIS, 0, NS, 0]HEAD

---------------- body (NS elements)
BodyAt(n) = TNuTab1 for
[MAT, 9, MT/ QM, QI, IZAP, LFS, NR, NP/ Eint / Y (E)]TAB1
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec12.h"
#include "TF1.h"
#include "TMath.h"

#include <iostream>

ClassImp(TNuSec12)

//______________________________________________________________________________
TNuSec12::TNuSec12(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec12 ctor
}

//______________________________________________________________________________
TNuSec12::~TNuSec12()
{
   // TNuSec12 dtor
}

//______________________________________________________________________________
void TNuSec12::What() const
{
   using namespace std;
   TNuSection::What();

   cout << "\tLO = " << GetLO() << endl;
}

