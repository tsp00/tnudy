// TNuDEpDMu2Body.cxx  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec06 : d2XdEdmu = Energy-Angle Distributions                        //
//                                                                           //
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) :
// [MAT, 6, MT/ ZA, AWR, 0, LCT, NK, 0]HEAD                                  //
//
// ------------------ body --------------------------------------------------//
// At(n) = n-th TNuDEpDMu, n=0, NK-1                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuDEpDMu2Body.h"

#include "TNuSec06.h"
#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab2List1.h"

#include "TNuListLegendre.h"
#include "TNuList1Tab1.h"

#include "TNuListCoulomb.h"
#include "TNuMath.h"

#include <iostream>
#include <iomanip>
using namespace std;


ClassImp(TNuDEpDMu2Body)
//______________________________________________________________________________
void TNuDEpDMu2Body::SetTransient()
{
   // Sets the ranges
   if (NBodies()==0) {
      fXmin = GetTab1()->GetXmin();
      fXmax = GetTab1()->GetXmax();
      fYmin = -1;
      fYmax = +1;
      return;
   }

   // range of E is given by that of TNuTab2 at 0:
   TNuTab2 *tab2 = (TNuTab2*) BodyFirst();

   // range on En
   fXmin = tab2->GetXmin();
   fXmax = tab2->GetXmax();

   // range on mu
   fYmin = tab2->GetYmin();
   fYmax = tab2->GetYmax();
}

//______________________________________________________________________________
Double_t TNuDEpDMu2Body::GetEout(Double_t Ein) const
{
   // returns the energy of the product particle in CM frame

   const Double_t mn = TNuMath::MassOfNeutron();
   Double_t Q = GetQI(); // q-value in eV
   
   // masses of the initial state in m_n
   Double_t m0 = GetProjectileAWR();
   Double_t M0 = GetTargetAWR();
   Double_t m_init = m0 + M0;

   // square-root of s in m_n
   Double_t sqrt_s = TMath::Sqrt(m_init * m_init + 2*M0*Ein/mn);
      
   // masses of the final state in m_n
   Double_t m = GetAWP();
   Double_t M = m_init - m - Q/mn;

   // product particle's energy in eV
   Double_t  ek = (sqrt_s - m + M)/(sqrt_s + m + M) / sqrt_s * (
      Q * (m_init + Q/2/mn) + M0 * Ein);

   return ek;
}

ClassImp(TNuDEpDMu2BodyScattering)
//______________________________________________________________________________
TNuDEpDMu2BodyScattering::TNuDEpDMu2BodyScattering(TNuEndfIO &src)
 : TNuDEpDMu2Body()
{
   // Discrete Two-Body Scattering (LAW=2)
   TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
   SetTab1(tab1);

   TNuTab2List1 *tab2 = new TNuTab2List1(src, "0.0, 0.0, 0, 0, NR, NE");
   for (Int_t n=0; n < tab2->GetN2(); n++) {
      Int_t LANG = src.GetL1();
      TNuList *list1 = 0;
      const Char_t* label= "0.0, E1,LANG, 0, NW, NL/A(E)";
      if (LANG == 0) {
         list1 = new TNuListLegendre(src, label);
      }
      else if (LANG >=11 && LANG <= 15) {
         list1 = new TNuList1Tab1(src, label);
      }
      else {
         Error("TNuDEpDMu2BodyScattering", "Unsupported value of LANG=%d", LANG);
      }
      tab2->Add(list1);
   }
   Add(tab2);
   SetTitle("Discrete Two-Body Scattering (LAW=2)");
}

//______________________________________________________________________________
Double_t TNuDEpDMu2BodyScattering::EvalF2(Double_t Ein, Double_t mu, Double_t *ps) const
{
   TNuTab2 *tab2 = (TNuTab2*) BodyAt(0);
   return tab2->EvalF2(Ein, mu, ps);
}

ClassImp(TNuDEpDMu2BodyIsotropic)
//______________________________________________________________________________
TNuDEpDMu2BodyIsotropic::TNuDEpDMu2BodyIsotropic(TNuEndfIO &src)
 : TNuDEpDMu2Body()
{
   // Isotropic Discrete Emission (LAW=3)
   TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
   SetTab1(tab1);

   SetTitle("Isotropic Discrete Emission (LAW=3)");
}

//______________________________________________________________________________
Double_t TNuDEpDMu2BodyIsotropic::EvalF2(Double_t /*Ein*/, Double_t /*mu*/, Double_t* /*ps*/) const
{
   return 0.5;
}

ClassImp(TNuDEpDMu2BodyRecoil)
//______________________________________________________________________________
TNuDEpDMu2BodyRecoil::TNuDEpDMu2BodyRecoil(TNuEndfIO &src)
 : TNuDEpDMu2Body()
{
   // Discrete Two-Body Recoils (LAW=4)
   TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
   SetTab1(tab1);

   SetTitle("Discrete Two-Body Recoils (LAW=4)");
}

//______________________________________________________________________________
Double_t TNuDEpDMu2BodyRecoil::EvalF2(Double_t Ein, Double_t /*mu*/, Double_t* ps) const
{
   // this part may not be sensible ...
   return GetTab1()->EvalF1(Ein, ps);
}

ClassImp(TNuDEpDMu2BodyCoulomb)
//______________________________________________________________________________
TNuDEpDMu2BodyCoulomb::TNuDEpDMu2BodyCoulomb(TNuEndfIO &src)
 : TNuDEpDMu2Body()
{
   // Charged-Particle Elastic Scattering (LAW=5)
   TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
   SetTab1(tab1);

   TNuTab2 *tab2 = new TNuTab2List1(src, "SPI, 0.0, LIDP, 0, NR, NE");
   for (Int_t n=0; n < tab2->GetN2(); n++) {
      TNuList1 *list = new TNuListCoulomb(src, "0.0, E, LTP, 0, NW, NL/ A(E)]");
      tab2->Add(list);
   }
   Add(tab2);
   SetTitle("Charged-Particle Elastic Scattering (LAW=5)");
}

//______________________________________________________________________________
//Double_t TNuDEpDMu2BodyCoulomb::EvalF2(Double_t Ein, Double_t mu, Double_t *ps)
Double_t TNuDEpDMu2BodyCoulomb::EvalF2(Double_t /*Ein*/, Double_t /*mu*/, Double_t* /*ps*/) const
{
   return 0;
}
