// TNuSec15.cxx  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec15 --- File 15 : Continuous photon energy spectra
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) = TNuCont for
// [MAT, 15, MT/ ZA, AWR, 0, 0, NC, 0] HEAD
//
// ------------------ body --------------------------------------------------//
// BodyAt(j) = (i < NC) TNuRecsWithTab1
// [MAT, 15, MT/ 0.0, 0.0, 0, LF, NR, NP/ Eint/ pj(E)] TAB1 (LF=1)
//[MAT, 15, MT/ 0.0, 0.0, 0, 0, NR, NE/ Eint ] TNuTab2 (TAB2 of TAB1)
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec15.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2Tab1.h"
#include "TNuListLegendre.h"

#include <iostream>
using namespace std;

ClassImp(TNuSec15)

//______________________________________________________________________________
void TNuSec15::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 14
   //

   SetHead(new TNuCont(src, "ZA, AWR, 0, 0, NC, 0/ HEAD"));

   for (Int_t j = 0; j < GetNC(); j++) {
      TNuRecsWithTab1 *recs = new TNuRecsWithTab1();
      recs->SetTab1(new TNuTab1(src, "0.0, 0.0, 0, LF, NR, NP/ Eint/ pj(E)"));
      Int_t vLF= recs->GetL2();
      if (vLF!=1) {
        fprintf(stderr, "Warning, LF =%d is not 1, j=%d, MT=%d\n", vLF, j, GetMT());
      }
      TNuTab2Tab1 *tab2= new TNuTab2Tab1(src, "0.0, 0.0, 0, 0, NR, NE/ Eint");
      for (Int_t n=0; n < tab2->GetN2(); n++)
         tab2->Add(new TNuTab1(src, "0.0, Ep, 0, 0, NR, NP/ g"));
      recs->Add(tab2);
      Add(recs);
   }
}

//______________________________________________________________________________
void TNuSec15::What() const
{
   TNuSection::What();

   cout << "\tNC = " << GetNC() << " components: " << endl;
}


//______________________________________________________________________________
void TNuSec15::SetTransient()
{
   // Sets the range of TNuVF2
   for (Int_t n=0; n < GetNC(); n++) {
      TNuTab2* tab2 = GetTab2At(n);
      fXmin = (n == 0) ? tab2->GetXmin() : TMath::Min(fXmin, tab2->GetXmin());
      fXmax = (n == 0) ? tab2->GetXmax() : TMath::Max(fXmax, tab2->GetXmax());
      fYmin = (n == 0) ? tab2->GetYmin() : TMath::Min(fYmin, tab2->GetYmin());
      fYmax = (n == 0) ? tab2->GetYmax() : TMath::Max(fYmax, tab2->GetYmax());
   }
}

//______________________________________________________________________________
Double_t TNuSec15::EvalF2(Double_t En, Double_t mu, Double_t *ps) const
{
   // evaulates
   Double_t sum=0;
   for (Int_t n=0; n < GetNC(); n++) {
      TNuTab2* tab2 = GetTab2At(n);
      sum += tab2->EvalF2(En, mu, ps);
   }
   return sum;
}
