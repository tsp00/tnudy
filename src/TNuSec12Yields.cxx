// TNuSec12Yields.cxx  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec12Yields - Multiplicities (LO=1)
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

#include "TNuSec12Yields.h"
#include "TNuMat.h"
#include "TF1.h"
#include "TMath.h"

#include <iostream>

ClassImp(TNuSec12Yields)

//______________________________________________________________________________
TNuSec12Yields::TNuSec12Yields(Int_t mat, Int_t mf, Int_t mt)
 : TNuSec12(mat, mf, mt), TNuVF1s()
{
   // TNuSec12Yields ctor
}

//______________________________________________________________________________
TNuSec12Yields::~TNuSec12Yields()
{
   // TNuSec12Yields dtor
}

//______________________________________________________________________________
void TNuSec12Yields::What() const
{
   using namespace std;
   TNuSection::What();

   cout << "\tLO  = " << GetLO() << " : =1 means yields" << endl;
   cout << "\tNK  = " << GetNK() << " : Number of final states for which multiplicities are given" << endl;
   cout << "-------------------------------------------------------------------" << endl;
   cout << "The multiplicities for " << GetParentMat()->GetProjTargetName() << endl;
   cout << "-------------------------------------------------------------------" << endl;
   for (Int_t k=0; k < GetNK(); k++) {
      cout << "EG = " << GetEGAt(k) << " eV, "
         << "  ES = " << GetESAt(k)
         << "  LP = " << GetLPAt(k)
         << "  LF = " << GetLFAt(k) << endl;
   }
}

//______________________________________________________________________________
void TNuSec12Yields::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 12
   //

   SetHead(new TNuCont(src, "ZA, AWR, LO, 0, NK, 0/HEAD"));
   if (GetNK() > 1) AddToHead(new TNuTab1(src,
      "0.0, 0.0, 0, 0, NR, NP/Y(E)"));
   for (Int_t ns=0; ns < GetNK(); ns++) {
      Add(new TNuTab1(src,
         "EG, ES, LP, LF, NR, NP/ Eint / y(E)"));
   }
}

//______________________________________________________________________________
void TNuSec12Yields::SetTransient()
{
   // Sets the range
   fXmin = fXmax = 0;
   for (Int_t k=0; k < GetNK(); k++) {
      TNuTab1* tab1= (TNuTab1*) BodyAt(k);
      fXmin = (k == 0) ? tab1->GetXmin() : TMath::Min(fXmin, tab1->GetXmin());
      fXmax = (k == 0) ? tab1->GetXmax() : TMath::Max(fXmax, tab1->GetXmax());
   }
}

//______________________________________________________________________________
const Char_t* TNuSec12Yields::GetSymbolAt(Int_t n) const
{
   // Returns the symbol for the n-th entry

   if (n<0 || n>= GetNK()) return "";

   return Form("%d:%e", n, GetESAt(n));
}
