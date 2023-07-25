// TNuSec10.cxx  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec10 - Product cross sections
//
//
/*
Neutron activation cross sections [such as the (n,p) and (n,2n) cross sections] and cross
sections for a particular state of a radioactive target are given in File 10. These cross
sections are given as a function of energy E, where E is the incident particle or photon
energy (in eV) in the laboratory system. They are given as energy-cross-section pairs. An
interpolation scheme must specify the energy variation of the data for energies between a
given energy point and the next higher energy point.
File 10 is divided into sections, each section containing the data for a particular reaction
type (MT number). The sections are ordered by increasing MT number. Within a section for
a given MT are subsections for different final states (LFS) of the daughter product nucleus.
File 10 is allowed only for evaluations that represent the data for single isotopes.

---------------- head
HeadAt(0) = TNuCont for
[MAT, 9, MT/ ZA, AWR, LIS, 0, NS, 0]HEAD

---------------- body (NS elements)
At(n) = TNuTab1 for
[MAT, 9, MT/ QM, QI, IZAP, LFS, NR, NP/ Eint / Y (E)]TAB1
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec10.h"
#include "TNuMat.h"
#include "TF1.h"
#include "TMath.h"

#include <iostream>

ClassImp(TNuSec10)

//______________________________________________________________________________
TNuSec10::TNuSec10(Int_t mat, Int_t mf, Int_t mt)
 : TNuSection(mat, mf, mt), TNuVF1s()
{
   // TNuSec10 ctor
}

//______________________________________________________________________________
TNuSec10::~TNuSec10()
{
   // TNuSec10 dtor
}

//______________________________________________________________________________
void TNuSec10::What() const
{
   using namespace std;
   TNuSection::What();

   cout << "\tLIS = " << GetLIS() << " : The level number of the target" << endl;
   cout << "\tNS  = " << GetNS() << " : Number of final states for which multiplicities are given" << endl;
   cout << "-------------------------------------------------------------------" << endl;
   cout << "The multiplicities for " << GetParentMat()->GetProjTargetName() << endl;
   cout << "-------------------------------------------------------------------" << endl;
   for (Int_t ns=0; ns < GetNS(); ns++) {
      cout << "QI = " << GetQIAt(ns) << " eV, "
         << "IZAP = " << GetIZAPAt(ns) << " (" << TNuMat::GetDefaultMatName(GetIZAPAt(ns)) << "),"
         << " LFS = " << GetLFSAt(ns) << endl;
   }
}

//______________________________________________________________________________
void TNuSec10::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 10

   SetHead(new TNuCont(src, "ZA, AWR, LIS, 0, NS, 0/HEAD"));
   for (Int_t ns=0; ns < GetNS(); ns++) {
      if (src.IsSEND()) {
         // For the exceptional case where written NS is bigger than the
         // actual number of subsections (example: ROSFOND-2010)
         Warning("ImportEndfData", "NS=%d is understood as %d", GetNS(), ns);
         break;         
      }
      Add(new TNuTab1(src,
         "QM, QI, IZAP, LFS, NR, NP/Y(E)"));
   }
}

//______________________________________________________________________________
void TNuSec10::SetTransient()
{
   // Sets the range
   fXmin = fXmax = 0;
   for (Int_t ns=0; ns < GetNS(); ns++) {
      TNuTab1* tab1= (TNuTab1*) BodyAt(ns);
      fXmin = (ns == 0) ? tab1->GetXmin() : TMath::Min(fXmin, tab1->GetXmin());
      fXmax = (ns == 0) ? tab1->GetXmax() : TMath::Max(fXmax, tab1->GetXmax());
   }
}
