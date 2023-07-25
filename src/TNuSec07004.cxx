// TNuSec07004.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec07004 - Thermal neutron inelastic scattering data (E < 5 eV)
//
/*
--------------- head (2 elements)
HeadAt(0) = TNuCont for
[MAT, 7, 4 / ZA, AWR, 0, LAT, LASYM, 0]HEAD

HeadAt(1) = TNuList for
[MAT, 7, 4 / 0.0, 0.0, LLN, 0, NI, NS/B(N) ] LIST

-------------- body (0 or 1 element)

BodyAt(0) = TNuTab3 for the S(#alpha, #beta, T)

with

At(0)->At(n) = TNuTab1Lists for the S(#alpha, #beta_n, T)

with

At(0)->At(n)->At(j) = TNuList for the S(#alpha, #beta_n, T_j),
[MAT, 7, 4 / T, #beta, LI, 0, NP, 0/ S(#alpha, #beta, T) ] LIST

-------------- tail (optional)

TailAt(k) = TNuTab1 for the k-th T_eff(T),
[MAT, 7, 4 / 0.0, 0.0, 0, 0, NR, NT/ Tint / Teff(T) ] TAB1
--------------

[MAT, 7, 4 / 0.0, 0.0, 0, 0, NR, NB/B(N)] TAB2
[MAT, 7, 4 / T0, beta1, LT, 0, NR, NP/ S(alpha, betaT0) ] TAB1
[MAT, 7, 4 / T1,beta1, LI, 0, NP, 0/ S(alpha, beta, T) ] LIST
------------------------------
<continue with LIST records for T2,T3,...TLT+1>
------------------------------
[MAT, 7, 4 / T0, beta2, LT, 0, NR, NP/S(alpha,beta,T0) ] TAB1
------------------------------
<continue with TAB1 and LIST records for remaining values of beta and
T >
------------------------------
[MAT, 7, 4 / 0.0, 0.0, 0, 0, NR, NT/ Tint / Teff0(T) ] TAB1
------------------------------
<continue with TAB1 records for Teff1, Teff2 and/ or Teff3 if the
corresponding value of a1, a2, or a3 in B(7), B(13), or B(19) is zero>
------------------------------
[MAT, 7, 0 / 0.0, 0.0, 0, 0, 0, 0] SEND

If the scattering law data are completely specified by analytic functions (no principal scattering
atom type, as indicated by B(1)=0), tabulated values of S(alpha, beta) are omitted and the
TAB2 and TAB1 records are not given.
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec07004.h"
#include "TF1.h"
#include "TNuList.h"
#include "TNuTab3Tab1Lists.h"
#include "TNuTab1Lists.h"
#include "TNuTab1ListsSub.h"

#include <iostream>

ClassImp(TNuSec07004)

//______________________________________________________________________________
TNuSec07004::TNuSec07004(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt), TNuVF3()
{
   // TNuSec07004 ctor
}

//______________________________________________________________________________
TNuSec07004::~TNuSec07004()
{
   // TNuSec07004 dtor
}

//______________________________________________________________________________
void TNuSec07004::What() const
{
   using namespace std;
   TNuSection::What();

}

//______________________________________________________________________________
void TNuSec07004::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of MF=7, MT=4
   //

   SetHead(new TNuCont(src, "ZA, AWR, 0, LAT, LASYM, 0/HEAD"));
   TNuList *list= new TNuList(src, "0.0, 0.0, LLN, 0, NI, NS"
      "; M*f, #epsilon, A, Emax, , M/B(N)");
   AddToHead(list);

   // if B(0) =0, no more data
   if (list->At(0) == 0) return;

   TNuTab3Tab1Lists *tab3 = new TNuTab3Tab1Lists(src, "0.0, 0.0, 0, 0, NR, NB/#beta");

   for (Int_t i=0; i < tab3->GetN2(); i++) {
      TNuTab1Lists *tab1lists = new TNuTab1Lists();
      TNuTab1 *tab1 = new TNuTab1(src,
         "T, #beta, LT, 0, NR, NP/#alpha/ S(#alpha; #beta, T)");
      tab1lists->SetTab1(tab1);
      Int_t LT = tab1lists->GetL1();
      for (Int_t j=1; j <= LT; j++) { // it is not up to LT+1, as given in the manual
         tab1lists->Add(new TNuTab1ListsSub(src,
            "T, #beta, LI, 0, NP, 0/ S(#alpha; #beta, T)"));
      }
      tab3->Add(tab1lists);
   }
   Add(tab3);

   while (!src.IsSEND()) {
      Add(new TNuTab1(src,
         "0.0, 0.0, 0, 0, NR, NT/Teff(T)"));
   }
}

//______________________________________________________________________________
void TNuSec07004::SetTransient()
{
   // Sets the range

   TNuTab3 *tab3 = GetTab3();

   fXmin = tab3->GetXmin();
   fXmax = tab3->GetXmax();
   fYmin = tab3->GetYmin();
   fYmax = tab3->GetYmax();
   fZmin = tab3->GetZmin();
   fZmax = tab3->GetZmax();
}

