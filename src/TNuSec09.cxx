// TNuSec09.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec09 - Multiplicities with respect to LFS, level number of the product
//
//
/*
HeadAt(0) = TNuCont for
[MAT, 9, MT/ ZA, AWR, LIS, 0, NS, 0]HEAD

---------------- body (NS elements)
BodyAt(n) = TNuTab1 for
[MAT, 9, MT/ QM, QI, IZAP, LFS, NR, NP/ Eint / Y (E)]TAB1
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec09.h"
#include "TF1.h"
#include "TMath.h"
#include "TNuMat.h"

#include <iostream>

ClassImp(TNuSec09)

//______________________________________________________________________________
TNuSec09::TNuSec09(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt)
{
   // TNuSec09 ctor
}

//______________________________________________________________________________
TNuSec09::~TNuSec09()
{
   // TNuSec09 dtor
}

//______________________________________________________________________________
void TNuSec09::What() const
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
         << " ZAP = " << GetZAPAt(ns) << " (" << TNuMat::GetDefaultMatName(GetZAPAt(ns)) << "),"
         << " LFS = " << GetLFSAt(ns) << endl;
   }
}

//______________________________________________________________________________
void TNuSec09::SetTransient()
{
   // Sets the minimum and maximum values of E

   for (Int_t ns=0; ns < GetNS(); ns++) {
      TNuTab1* tab1= (TNuTab1*) BodyAt(ns);
      fXmin = (ns == 0) ? tab1->GetXmin() : TMath::Min(fXmin, tab1->GetXmin());
      fXmax = (ns == 0) ? tab1->GetXmax() : TMath::Max(fXmax, tab1->GetXmax());
   }
}

//______________________________________________________________________________
const Char_t* TNuSec09::GetSymbolAt(Int_t n) const
{
   // Returns the symbol for the n-th entry

   if (n<0 || n>= GetNS()) return "";

   Int_t zaip = GetZAPAt(n)*10 + GetLFSAt(n);
   return TNuMat::GetDefaultMatName(zaip, "Latex");
}

//______________________________________________________________________________
void TNuSec09::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 3
   //

   SetHead(new TNuCont(src, "ZA, AWR, LIS, 0, NS, 0/HEAD"));
   for (Int_t ns=0; ns < GetNS(); ns++) {
      Add(new TNuTab1(src,
         "QM, QI, IZAP, LFS, NR, NP/Y(E)"));
   }
}
