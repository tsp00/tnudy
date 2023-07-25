// TNuDEpDMu.cxx  =====================================================
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

#include "TNuDEpDMu.h"

#include "TNuSec06.h"
#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab2Tab1.h"
#include "TNuTab3Tab2.h"
#include "TNuTab3List2.h"
#include "TNuList2.h"
#include "TNuListLegendre.h"
#include "TNuList1Tab1.h"
#include "TNuList2Legendre.h"
#include "TNuList2KalbachMann.h"
#include "TNuList2Tab1.h"
//#include "TNuListCoulomb.h"
#include "TNudy.h"
#include "TNuMat.h"

#include "TF1.h"
#include "TF3.h"
#include "TLegend.h"
#include "THStack.h"

#include "TNuSec03.h"
#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuDEpDMu)

//______________________________________________________________________________
void TNuDEpDMu::What() const
{
   TNuRecsWithTab1::What();
   //cout << "Params" << endl;
   //cout << "   NPL = fN1 = " << GetNPL() << " : Number of data points in fData" << endl;
   cout << "  ZAP = " << GetZAP() << " : Product identifier 1000 * Z + A" << endl;
   cout << "  AWP = " << GetAWP() << " : Product mass in neutron units" << endl;
   cout << "  LIP = " << GetLIP() << " : Product modifier flag (0 for ground state)" << endl;
   cout << "  LAW = " << GetLAW() << " : Representation identifier" << endl;
}


//______________________________________________________________________________
const Char_t* TNuDEpDMu::GetFigTitle() const
{
   // Returns the title of the figure

   const Char_t *head = GetParentMat()->GetProjTargetName(" + ", "Latex");
   const Char_t *title = Form("%s production in %s. %s",
      TNuMat::GetDefaultMatName(GetZAIP(), "Latex"),
      head, GetParent()->GetTitle());
   return title;
}

#include "TCanvas.h"
//______________________________________________________________________________
void TNuDEpDMu::DrawYield()
{
   // plot the yield of product

   TCanvas *c1 = TNudy::GetCanvas();
   TF1 *tf1 = GetTab1()->GetTF1();
   tf1->SetTitle(GetFigTitle());
   tf1->Draw();
   c1->Update();
}

//______________________________________________________________________________
Double_t TNuDEpDMu::ELab2ECM(Double_t EnLab) const
{
   // convert incident energy from Lab frame to CM frame
   return EnLab * GetTargetAWR()/(GetTargetAWR()+GetProjectileAWR());
}

ClassImp(TNuDEpDMu)

//______________________________________________________________________________
void TNuDEpDMuF3::SetTransient()
{
   // Sets the ranges
   if (NBodies()==0) {
      // What shall we do ?
      fXmin = fYmin = fZmin = 0;
      fXmax = fYmax = fZmax = 1;
      return;
   }

   // range on En
   fXmin = GetTab1()->GetXmin();
   fXmax = GetTab1()->GetXmax();

   // range on Ep
   fYmin = 0;
   fYmax = fXmax;

   // range on mu
   fZmin = -1;
   fZmax = +1;
}
//______________________________________________________________________________
Double_t TNuDEpDMuF3::D2XDEpDMu(Double_t En, Double_t Ep, Double_t mu, Double_t* /*ps*/) const
{
   // evaluates the double differential x-sect
   // = X(En) * y(En) * f(En,Ep,mu) = x-sect * yield * distribution

   TNuSec03 * sec3000= GetSec3000();
   if (!sec3000) {
      Error("EvalD2XDEpDMu", "Failed in getting corresponding section in file 3");
      return 0;
   }

   Double_t sig = sec3000->EvalF1(En);
   Double_t y = GetTab1()->EvalF1(En);
   Double_t f = EvalF3(En, Ep, mu);
   return (sig * y * f);
}

//______________________________________________________________________________
void TNuDEpDMuF3::DrawD2XDEpDMu(Option_t *opt)
{
   // draw the double differential x-sect
   // = X(En) * y(En) * f(En,Ep,mu) = x-sect * yield * distribution

   //TCanvas *c1 = TNudy::GetCanvas();
   //TNuVF3::TNuEvalF3_t fcn =static_cast<TNuVF3::TNuEvalF3_t>(&TNuDEpDMuF3::D2XDEpDMu);
   //GetTF3(fcn)->Draw(opt);
   //c1->Update();
   PlotTH3(opt);
}

ClassImp(TNuDEpDMuUnknwon)
//______________________________________________________________________________
TNuDEpDMuUnknwon::TNuDEpDMuUnknwon(TNuEndfIO &src)
 : TNuDEpDMuF3()
{
   // Unknown Distribution (LAW=0)
   TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
   SetTab1(tab1);

   SetTitle("Unknown Distribution (LAW=0)");
}

ClassImp(TNuDEpDMuContinuum)

//______________________________________________________________________________
TNuDEpDMuContinuum::TNuDEpDMuContinuum(TNuEndfIO &src)
 : TNuDEpDMuF3()
{
   // Continuum Energy-Angle Distributions (LAW=1)
   TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
   SetTab1(tab1);

   TNuTab3List2 *tab3 = new TNuTab3List2(src, "0.0, 0.0, LANG, LEP, NR, NE");
   Int_t LANG = tab3->GetL1();
   //Int_t LEP = tab3->GetL2();
   for (Int_t n=0; n < tab3->GetN2(); n++) {
      TNuList2 *list2 = 0;
      const Char_t *label;
      Int_t nNA = src.GetL2();
      if (LANG == 1) {
         // Legendre Coefficients Representation (LANG=1)
         label = "0.0, En, ND, NA, NW, NEP; Ep";
         for (Int_t na =0; na <= nNA; na++)
            label = Form("%s, b_{%d}", label, na);
         list2 = new TNuList2Legendre(src, label);
      }
      else if (LANG == 2) {
         // Kalbach-Mann Systematics Representation (LANG=2)
         label = Form("0.0, En, ND, NA, NW, NEP; Ep, f_{0}, r%s",
                  (nNA == 2) ? ", a" : "");
         list2 = new TNuList2KalbachMann(src, label);
      }
      else if (LANG >= 11 && LANG <= 15) {
         // Tabulated Function Representation (LANG=11-15)
         label = Form("0.0, En, ND, NA, NW, NEP; Ep, f_{0}");
         for (Int_t na2=0; na2 < nNA/2; na2++)
            label = Form("%s, #mu_{%d}, y_{%d}", label, na2, na2);
         list2 = new TNuList2Tab1(src, label);
      }
      else {
         Error("TNuDEpDMuContinuum", "Unsupported value of LANG=%d", LANG);
      }
      //list2->SetLabel("0.0, E1, ND, NA, NW, NEP/bs");
      //list2->SetLANG(LANG);
      //list2->SetLEP(LEP);
      tab3->Add(list2);
   }
   //TNuList2 *list20= (TNuList2*) tab3->At(0);
   Add(tab3);
   //
   // --- Why these LANG and LEP cannot be stored correctly in the root file ??? ???
   //
   SetTitle("Continuum Energy-Angle Distributions (LAW=1)");
}

//______________________________________________________________________________
void TNuDEpDMuContinuum::SetTransient()
{
   // Sets the ranges
   TNuTab3 *tab3 = (TNuTab3*) BodyFirst();
   // range on En
   fXmin = tab3->GetXmin();
   fXmax = tab3->GetXmax();

   // range on Ep
   fYmin = tab3->GetYmin();
   fYmax = tab3->GetYmax();

   // range on mu
   fZmin = tab3->GetZmin();
   fZmax = tab3->GetZmax();
}

//______________________________________________________________________________
Double_t TNuDEpDMuContinuum::EvalF3(Double_t Ein, Double_t Eout, Double_t mu, Double_t *ps) const
{
   TNuTab3 *tab3 = (TNuTab3*) BodyAt(0);
   return tab3->EvalF3(Ein, Eout, mu, ps);
}



ClassImp(TNuDEpDMuNBodyPhaseSpace)
//______________________________________________________________________________
TNuDEpDMuNBodyPhaseSpace::TNuDEpDMuNBodyPhaseSpace(TNuEndfIO &src)
 : TNuDEpDMuF3()
{
   // N-Body Phase-Space Distributions (LAW=6)
   TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
   SetTab1(tab1);

   Add(new TNuCont(src, "APSX, 0.0, 0, 0, 0, NPSX"));
   SetTitle("N-Body Phase-Space Distributions (LAW=6)");
}


//______________________________________________________________________________
Double_t TNuDEpDMuNBodyPhaseSpace::EvalF3(Double_t Ein, Double_t Eout, Double_t mu, Double_t* /*ps*/) const
{
   //
   using namespace TMath;
   Int_t n = GetNPSX(); // number of particles distributed according to the phase-space law
   Double_t apsx = GetAPSX(); // total mass

   if (n < 3 || n > 5) {
      Error("EvalF3", "NPSX = %d is out of range", n);
      return 0;
   }

   //const TNuSec06* pSec = (TNuSec06*) GetParent();
   //const TNuMat* pMat = pSec->GetParentMat();

   // target mass
   Double_t mTarget = GetTargetAWR();
   // projectile mass
   Double_t mProj = GetProjectileAWR();
   // reaction QI value from File 3
   Double_t qi = GetQI();
   // The energy available in CM for one-step reactions
   Double_t Ea = mTarget * Ein / (mProj + mTarget) + qi;
   // a fraction of the energy available in CM
   Double_t Eimax = (apsx - GetAWP())/apsx * Ea;

   // normalization factor
   Double_t Cn =
      (n == 3) ? 4. / (Pi() * Power(Eimax, 2)) :
      (n == 4) ? 105. / ( 32 * Power(Eimax, 3.5)) :
      (n == 5) ? 256. / ( 14 * Pi() * Power(Eimax, 5)) :
                 0;

   // E^star
   Double_t Estar = Ein * mProj / (mTarget +  GetAWP());

   Double_t dE = Eimax - (Estar + Eout - 2*mu*Sqrt(Estar*Eout));
   Double_t PiLab = 0;
   if (dE > 0)
      PiLab = Cn * Sqrt(Eout) * Power(dE, 1.5*n - 4);
   return PiLab;
}

ClassImp(TNuDEpDMuLaboratory)
//______________________________________________________________________________
TNuDEpDMuLaboratory::TNuDEpDMuLaboratory(TNuEndfIO &src)
 : TNuDEpDMuF3()
{
   // Laboratory Angle-Energy Law (LAW=7)
   TNuTab1 *tab1 = new TNuTab1(src, "ZAP, AWP, LIP, LAW, NR, NP/y(E)");
   SetTab1(tab1);

   TNuTab3Tab2 *tab3 = new TNuTab3Tab2(src, "0.0, 0.0, 0, 0, NR, NE");
   for (Int_t n=0; n < tab3->GetN2(); n++) {
      TNuTab2Tab1 *tab2= new TNuTab2Tab1(src, "0.0, E1, 0, 0, NRM, NMU");
      for (Int_t m=0; m < tab2->GetN2(); m++) {
         tab2->Add(new TNuTab1(src, "0.0, mu, 0, 0, NRP, NEP"));
      }
      tab3->Add(tab2);
   }
   Add(tab3);
   SetTitle("Laboratory Angle-Energy Law (LAW=7)");
}

//______________________________________________________________________________
void TNuDEpDMuLaboratory::SetTransient()
{
   // Sets the ranges
   // NB. The arguments of Tab3 in Laboratory Angle-Energy Law (LAW=7)
   // are ordered as (E_in, mu, E_out).

   TNuTab3 *tab3 = (TNuTab3*) BodyFirst();
   // range on En
   fXmin = tab3->GetXmin();
   fXmax = tab3->GetXmax();

   // range on Ep
   fYmin = tab3->GetZmin();
   fYmax = tab3->GetZmax();

   // range on mu
   fZmin = tab3->GetYmin();
   fZmax = tab3->GetYmax();
}

//______________________________________________________________________________
Double_t TNuDEpDMuLaboratory::EvalF3(Double_t Ein, Double_t Eout, Double_t mu, Double_t *ps) const
{
   TNuTab3 *tab3 = (TNuTab3*) BodyAt(0);
   // NB. The arguments of Tab3 in Laboratory Angle-Energy Law (LAW=7)
   // are ordered as (E_in, mu, E_out).
   return tab3->EvalF3(Ein, mu, Eout, ps);
}

