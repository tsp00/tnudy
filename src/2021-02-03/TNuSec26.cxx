// TNuSec26.cxx  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec26 : Secondary distributions for photo- and electro-atomic data
//                                                                           //
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) :
// [MAT,26, MT/ ZA, 0.0, 0, 0, NK, 0]HEAD
//
// ------------------ body --------------------------------------------------//
// At(n) = n-th TNuDEpDMu, n=0, NK-1                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec26.h"
#include "TNuMat.h"
#include "TMath.h"
#include "TNuEndfIO.h"

#include "TNuDEpDMu.h"
#include "TNuDEpDMu2Body.h"
#include "TNuDEpDMuETransfer.h"


#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuSec26)

//______________________________________________________________________________
void TNuSec26::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 6
   //
/*
[MAT,26, MT/ ZA, 0.0, 0, 0, NK, 0]HEAD
<subsection for k = 1 >
<subsection for k = 2 >
-----------------------
-----------------------
<subsection for k = NK>
*/

   SetHead(new TNuCont(src, "ZA, 0.0, 0, 0, NK, 0/HEAD"));
   for (Int_t k=0; k < GetNK(); k++) {
      // begin of k-th subsection
      TNuDEpDMu *sub = 0;
      //TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
      //sub->SetTab1(tab1);

      Int_t LAW = src.GetL2();

      if (LAW == 0) {
         // Unknown Distribution (LAW=0)
         sub = new TNuDEpDMuUnknwon(src);
      }
      else if (LAW == 1) {
         // Continuum Energy-Angle Distributions (LAW=1)
         sub = new TNuDEpDMuContinuum(src);
      }
      else if (LAW == 2) {
         // Discrete Two-Body Scattering (LAW=2)
         sub = new TNuDEpDMu2BodyScattering(src);
      }
      else if (LAW == 8) {
         // Energy transfer during electro-atomic excitation or bremsstrahlung (LAW=8)
         sub = new TNuDEpDMuETransfer(src);
      }
      else {
         Error("ImportEndfData", "Unsupported value of LAW=%d", LAW);
      }
      //sub->SetQI(qi);
      Add(sub);
   }
}

//______________________________________________________________________________
void TNuSec26::SetTransient()
{
   // Sets the ranges

   if (NBodies()==0) {
      fXmin = 0;
      fXmax = 1;
   } else {
      fXmin = ((TNuDEpDMu*) BodyFirst())->GetTab1()->GetXmin();
      fXmax = ((TNuDEpDMu*) BodyLast())->GetTab1()->GetXmax();
   }
}


//______________________________________________________________________________
Double_t TNuSec26::EvalF1At(Int_t n, Double_t En, Double_t* /*ps*/) const
{
   // Evaluates n-th yield

   if (n < 0 || n > GetNK()) return 0;
   TNuDEpDMu *tab1sub = (TNuDEpDMu*) BodyAt(n);
   return tab1sub->Tab1Eval(En);
}

//______________________________________________________________________________
const Char_t* TNuSec26::GetSymbolAt(Int_t n) const
{
   // Returns the symbol for the n-th entry

   Int_t zaip = ((TNuDEpDMu*) BodyAt(n))->GetZAIP();
   return TNuMat::GetDefaultMatName(zaip, "Latex");
}
