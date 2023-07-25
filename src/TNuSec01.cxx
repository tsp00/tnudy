// TNuSec01.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSec01                                                         //
//                                                                    //
// Neutron Yields                                                     //
/*

[Data structure for MT=452] // total number of neutrinos per fission
HeadAt(0) = TNuCont for "ZA, AWR, 0, LNU, 0, 0"
BodyAt(0) = TNuListTaylor or TNuTab1 for nubar(E)

[Data structure for MT=455] // delayed neutron data
HeadAt(0) = TNuCont for "ZA, AWR, LDG, LNU, 0, 0"
if (LDG==0 && (lnu ==2 || lnu == 1))
BodyAt(0) = TNuList for {lambda}
BodyAt(1) = TNuTab1 for bar_nu(E)

else if (LDG==1 && (lnu ==2 || lnu == 1))
BodyAt(0) = TNuTab2 for {#lambda(E), #alpha(E)}
BodyAt(1) = TNuTab1 for nu(E)

[Data structure for MT=456] // prompt neutrons per fission
HeadAt(0) = TNuCont for "ZA, AWR, 0, LNU, 0, 0"
BodyAt(0) = TNuListTaylor or TNuTab1 for nu(E)

*/
//                                                                    //
////////////////////////////////////////////////////////////////////////


#include "TNuSec01.h"
#include "TNuEndfIO.h"

#include "TROOT.h"
#include "TString.h"
//#include "TObject.h"

#include "TNudy.h"
#include "TNuEndfIO.h"
#include "TNuListTaylor.h"
#include "TNuTab1.h"
#include "TNuTab2List1.h"

ClassImp(TNuSec01)

//______________________________________________________________________________
TNuSec01::TNuSec01(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt), TNuVF1()
{
   // TNuSec01 ctor
   if (mf != 1) {
      Warning("TNuSec01::TNuSec01", "MF=%d is not 1", mf);
   }
}

//______________________________________________________________________________
void TNuSec01::SetTransient()
{
   fXmin = dynamic_cast<TNuVF1*>(BodyLast())->GetXmin();
   fXmax = dynamic_cast<TNuVF1*>(BodyLast())->GetXmax();
}

//______________________________________________________________________________
TNuSec01::~TNuSec01()
{
}

//______________________________________________________________________________
void TNuSec01::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of a File (default/blind routine)
   //

   //Int_t nrecs = 0;
   Int_t mt = fMT;

   if (mt==452) {
      // total number of neutrinos per fission
      SetHead(new TNuCont(src, "ZA, AWR, 0, LNU, 0, 0"));
      Int_t lnu= GetL2();
      if (lnu == 1) {
         Add(new TNuListTaylor(src, "0.0, 0.0, 0, 0, NC, 0"));
      }
      else if (lnu == 2) {
         Add(new TNuTab1(src,
         "0.0, 0.0, 0, 0, NR, NP/#bar{#nu}(E)"));
      }
      else {
         Error("TNuSec01", "Unsupported value of LNU=%d", lnu);
      }
   }
   else if (mt == 455) {
      // delayed neutron data
      SetHead(new TNuCont(src, "ZA, AWR, LDG, LNU, 0, 0"));
      Int_t ldg = GetL1();
      Int_t lnu = GetL2();
      if (ldg == 0 && lnu ==2) {
         Add(new TNuList(src, "0.0, 0.0, 0, 0, NNF, 0/{#lambda}"));
         Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/#bar{#nu}_d(E)"));
      }
      else if (ldg == 0 && lnu == 1) {
         Add(new TNuList(src, "0.0, 0.0, 0, 0, NNF, 0/{#lambda}"));
         // Following line is written as TAB1 in the manual, 
         // but I guess it is a LIST
         Add(new TNuList(src, "0.0, 0.0, 0, 0, 1, 0/#bar{#nu}_d"));
      }
      else if (ldg == 1 && (lnu == 2 || lnu ==1)) {
         TNuTab2List1 *tab2 = new TNuTab2List1(src, "0.0, 0.0, 0, 0, NR, NE");
         for (Int_t i = 0 ; i < tab2->GetNZ(); i++) {
            // TNuList is not an TNuList1 !!
            tab2->Add(new TNuList(src,
            "0.0, E_i, 0, 0, NNF*2, 0/{#lambda(E), #alpha(E)}"));
         }
         Add(tab2);
         Add(new TNuTab1(src,
            "0.0, 0.0, 0, 0, NR, NP/#bar{#nu}_d(E)"));
      }
      else {
         Error("TNuSec01", "Unsupported value of LDG=%d and LNU=%d", ldg,lnu);
      }
   }

   else if (mt == 456) {
      // prompt neutrons per fission
      SetHead(new TNuCont(src, "ZA, AWR, 0, LNU, 0, 0"));
      Int_t lnu = GetL2();
      if (lnu == 2) {
         Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/ #bar{#nu}_p(E)"));
      }
      else if (lnu == 1) {
         Add(new TNuListTaylor(src, "0.0, 0.0, 0, 0, 1, 0/#bar{#nu}_p(E)"));
      }
      else {
         Error("TNuSec01", "Unsupported value of LNU=%d", lnu);
      }
   }

   else {
      Error("TNuSec01", "Unsupported section, MT = %d", mt);
      /*
      Info("TNuSec01", "Invoking the default loader ...");
      TNuSection *pSec = new TNuSection(src,mf,mt);
      delete this;
      this = (TNuSec01*) pSec;
      */
   }
}

//______________________________________________________________________________
Double_t TNuSec01::EvalF1(Double_t Ein, Double_t *) const
{
   // returns the neutron yield
   //
   // (fMT == 452) total number of neutrinos per fission
   // (fMT == 455) delayed neutron data
   // (fMT == 456) prompt neutrons per fission

   return dynamic_cast<TNuVF1*>(BodyLast())->EvalF1(Ein);
}

