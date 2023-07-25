// TNuSec05.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec05 : Energy Distributions                                         //
//
/*
It provides
Begin_Latex
f(E_{n}, E_{p}) = #frac{#sigma_{c}(E_{n})}{dE_{p}} / #sigma_{c}(E_{n})
with #int_{0}^{E_{p,max}} f(E_{n}, E_{p}) dE_{p} = 1,
End_Latex
where En and Ep are the the indident outgoing energies (in eV) and
c is the channel index given by the MT value.
Distribution is given as sum of different representations,
Begin_Latex
f(E_{n}, E_{p}) = sum_{k} p_{k}(E_{n}) f_{k}(E_{n}, E_{p})
with #int_{0}^{E_{p,max}} p_{k}(E_{n}) dE_{n} = 1,
End_Latex
p_k(En) is the probability of the representation indexed by k.
*/
//                                                                           //
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) = a TNuCont for
// [MAT, 5, MT/ ZA, AWR, 0, 0, NK, 0]HEAD                                    //
//
// ------------------ body --------------------------------------------------//
// BodyAt(n) = n-th TNuESpectrum, n=0, NK-1                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec05.h"
#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab2Tab1.h"
#include "TNudy.h"
#include "TNuMat.h"
#include "TNuMath.h"

ClassImp(TNuSec05)

//______________________________________________________________________________
void TNuSec05::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 5
   //
/*
[MAT, 5, MT/ ZA, AWR, 0, 0, NK, 0]HEAD
<subsection for k = 1 >
<subsection for k = 2 >
-----------------------
-----------------------
<subsection for k = NK>
*/
   SetHead(new TNuCont(src, " ZA, AWR, 0, 0, NK, 0/HEAD"));

   for (Int_t k=0; k < GetNK(); k++) {
      // begin of k-th subsection
      TNuESpectrum *sub = 0;
      TNuTab1 *tab1 = new TNuTab1(src, "U, 0.0, 0, LF, NR, NP/p(E)");
      Int_t fLF= tab1->GetL2();

      if (fLF == 1) {
         // Arbitrary Tabulated Function (LF=1)
         sub = new TNuESpectrumTabulated();
         sub->SetTab1(tab1);
         TNuTab2Tab1 *tab2 = new TNuTab2Tab1(src, "0.0, 0.0, 0, 0, NR, NE");
         for (Int_t n=0; n < tab2->GetN2(); n++)
            tab2->Add(new TNuTab1(src, "0.0, E_i, 0, 0, NR, NF"));
         sub->Add(tab2);
         sub->SetTitle("Arbitrary Tabulated Function (LF=1)");
      }
      else if (fLF == 5) {
         // General Evaporation Spectrum (LF=5)
         sub = new TNuESpectrumGeneralEvaporation();
         sub->SetTab1(tab1);
         sub->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NE/#theta(E)"));
         sub->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NF/g(x)"));
         sub->SetTitle("General Evaporation Spectrum (LF=5)");
      }
      else if (fLF == 7) {
         // Simple Maxwellian Fission Spectrum (LF=7)
         sub = new TNuESpectrumMaxwellian();
         sub->SetTab1(tab1);
         sub->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NE/#theta(E)"));
         sub->SetTitle("Simple Maxwellian Fission Spectrum (LF=7)");
      }
      else if (fLF == 9) {
         // Evaporation Spectrum (LF=9)
         sub = new TNuESpectrumEvaporation();
         sub->SetTab1(tab1);
         sub->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NE/#theta(E)"));
         sub->SetTitle("Evaporation Spectrum (LF=9)");
      }
      else if (fLF == 11) {
         // Energy-Dependent Watt Spectrum (LF=11)
         sub = new TNuESpectrumWatt();
         sub->SetTab1(tab1);
         sub->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NE/a(E)"));
         sub->Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NE/b(E)"));
         sub->SetTitle("Energy-Dependent Watt Spectrum (LF=11)");
      }
      else if (fLF == 12) {
         // Energy-Dependent Fission Neutron Spectrum (Madland and Nix) (LF=12)
         sub = new TNuESpectrumMadlandNix();
         sub->SetTab1(tab1);
         sub->Add(new TNuTab1(src, "EFL, EFH, 0, 0, NR, NE/T_M(E)"));
         sub->SetTitle("Energy-Dependent Fission Neutron Spectrum (Madland and Nix) (LF=12)");
      }
      else {
         Error("ImportEndfData", "Unsupported value of LF=%d", fLF);
      }
      Add(sub);
   }
}

//______________________________________________________________________________
void TNuSec05::SetTransient()
{
   // sets the range of E and E'

   fXmin = fXmax = fYmin = fYmax = 0;
   for (Int_t k=0; k < GetNK(); k++) {
      TNuESpectrum *tab1sub = (TNuESpectrum*) BodyAt(k);
      if (k==0) {
         fXmin = tab1sub->GetXmin();
         fXmax = tab1sub->GetXmax();
         fYmin = tab1sub->GetYmin();
         fYmax = tab1sub->GetYmax();
      }
      else {
         fXmin = TMath::Min(fXmin, tab1sub->GetXmin());
         fXmax = TMath::Max(fXmax, tab1sub->GetXmax());
         fYmin = TMath::Min(fYmin, tab1sub->GetYmin());
         fYmax = TMath::Max(fYmax, tab1sub->GetYmax());
      }
   }
}

//______________________________________________________________________________
Double_t TNuSec05::EvalF2(Double_t Ein, Double_t Eout, Double_t *ps) const
{
   Double_t dXdE=0;
   for (Int_t k=0; k < GetNK(); k++) {
      TNuESpectrum *tab1sub = (TNuESpectrum*) BodyAt(k);
      Double_t pk = tab1sub->Tab1Eval(Ein);
      Double_t fk = tab1sub->EvalF2(Ein, Eout, ps);
      dXdE += pk * fk;
   }
   return dXdE;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrum                                                        //
/*
Generic class for a specific representation of energy distribution,
which provides p_k(En) and f_k(En, Ep) such that
Begin_Latex
f(E_{n}, E_{p}) = sum_{k} p_{k}(E_{n}) f_{k}(E_{n}, E_{p})
with #int_{0}^{E_{p,max}} p_{k}(E_{n}) dE_{n} = 1,
End_Latex
p_k(En) is the probability of the representation indexed by k.

The concrete class of this is one of followings:
TNuESpectrumTabulated : Arbitrary Tabulated Function (LF=1)
TNuESpectrumGeneralEvaporation : General Evaporation Spectrum (LF=5)
TNuESpectrumMaxwellian         : Simple Maxwellian Fission Spectrum (LF=7)
TNuESpectrumEvaporation        : Evaporation Spectrum (LF=9)
TNuESpectrumWatt               : Energy-Dependent Watt Spectrum (LF=11)
TNuESpectrumMadlandNix         : Energy-Dependent Fission Neutron Spectrum (Madland and Nix) (LF=12)
*/
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuESpectrum)
void TNuESpectrum::SetTransient()
{
   fYmin = 0;
   fYmax = GetXmax() - GetU();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumTabulated                                            //
//                                                                           //
// --- Arbitrary Tabulated Function (LF=1)                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuESpectrumTabulated)

//______________________________________________________________________________
Double_t TNuESpectrumTabulated::EvalF2(Double_t Ein, Double_t Eout, Double_t *) const
{
   if (Ein < GetXmin() || Ein >GetXmax()) return 0;
   if (Eout > Ein - GetU()) return 0;
   return ((TNuTab2*) BodyAt(0))->EvalF2(Ein, Eout);
}

//______________________________________________________________________________
void TNuESpectrumTabulated::SetTransient()
{
   fXmin = ((TNuTab2*) BodyAt(0))->GetXmin();
   fXmax = ((TNuTab2*) BodyAt(0))->GetXmax();
   fYmin = ((TNuTab2*) BodyAt(0))->GetYmin();
   fYmax = ((TNuTab2*) BodyAt(0))->GetYmax();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumGeneralEvaporation                                            //
//                                                                           //
// --- General Evaporation Spectrum (LF=5)                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuESpectrumGeneralEvaporation)


//______________________________________________________________________________
Double_t TNuESpectrumGeneralEvaporation::EvalF2(Double_t Ein, Double_t Eout, Double_t *) const
{
   if (Ein < GetXmin() || Ein >GetXmax()) return 0;
   if (Eout > Ein - GetU()) return 0;
   Double_t theta = ((TNuTab1*) BodyAt(0))->Eval(Ein);
   return ((TNuTab1*) BodyAt(1))->Eval(Eout/theta);
}

//______________________________________________________________________________
void TNuESpectrumGeneralEvaporation::SetTransient()
{
   fXmin = ((TNuTab1*) BodyAt(0))->GetXmin();
   fXmax = ((TNuTab1*) BodyAt(0))->GetXmax();
   TNuESpectrum::SetTransient();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumMaxwellian                                                    //
//                                                                           //
// --- Simple Maxwellian Fission Spectrum (LF=7)                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuESpectrumMaxwellian)


//______________________________________________________________________________
Double_t TNuESpectrumMaxwellian::EvalF2(Double_t Ein, Double_t Eout, Double_t *) const
{
   using namespace TMath;

   if (Ein < GetXmin() || Ein >GetXmax()) return 0;
   if (Eout > Ein - GetU()) return 0;
   Double_t theta = ((TNuTab1*) BodyAt(0))->Eval(Ein);
   Double_t z = (Ein - GetU())/theta; // (E- U)/theta
   Double_t zSqrt = Sqrt(z);

   Double_t I = Power(theta, 1.5)*(Sqrt(Pi())/2*Erf(zSqrt) - zSqrt*Exp(-z));
   return Sqrt(Eout)*Exp(-Eout/theta)/I;
}

//______________________________________________________________________________
void TNuESpectrumMaxwellian::SetTransient()
{
   fXmin = ((TNuTab1*) BodyAt(0))->GetXmin();
   fXmax = ((TNuTab1*) BodyAt(0))->GetXmax();
   TNuESpectrum::SetTransient();
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumEvaporation                                                   //
//                                                                           //
// --- Evaporation Spectrum (LF=9)                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuESpectrumEvaporation)

//______________________________________________________________________________
Double_t TNuESpectrumEvaporation::EvalF2(Double_t Ein, Double_t Eout, Double_t *) const
{
   using namespace TMath;

   if (Ein < GetXmin() || Ein >GetXmax()) return 0;
   if (Eout > Ein - GetU()) return 0;
   Double_t theta = ((TNuTab1*) BodyAt(0))->Eval(Ein);
   Double_t z = (Ein - GetU())/theta; // (E- U)/theta
   Double_t normI = theta*theta*(1 - Exp(-z)*(1+z));
   return Eout*Exp(-Eout/theta)/normI;
}
//______________________________________________________________________________
void TNuESpectrumEvaporation::SetTransient()
{
   fXmin = ((TNuTab1*) BodyAt(0))->GetXmin();
   fXmax = ((TNuTab1*) BodyAt(0))->GetXmax();
   TNuESpectrum::SetTransient();
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumWatt                                                          //
//                                                                           //
// --- Energy-Dependent Watt Spectrum (LF=11)                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuESpectrumWatt)

//______________________________________________________________________________
Double_t TNuESpectrumWatt::EvalF2(Double_t Ein, Double_t Eout, Double_t *) const
{
   using namespace TMath;

   if (Ein < GetXmin() || Ein >GetXmax()) return 0;
   if (Eout > Ein - GetU()) return 0;
   Double_t a = ((TNuTab1*) BodyAt(0))->Eval(Ein);
   Double_t b = ((TNuTab1*) BodyAt(1))->Eval(Ein);

   Double_t z = (Ein - GetU())/a; // (E- U)/a
   Double_t zSqrt = Sqrt(z);
   Double_t ab4 = a*b/4;
   Double_t ab4Sqrt = Sqrt(ab4);

   Double_t normI =
      (a/2)*Sqrt(Pi()*ab4)*Exp(ab4)*(Erf(zSqrt - ab4Sqrt) + Erf(zSqrt + ab4Sqrt))
      - a*Exp(-z)*SinH(Sqrt(b*(Ein-GetU())));
   return Exp(-Eout/a)*SinH(Sqrt(b*Eout))/normI;
}

//______________________________________________________________________________
void TNuESpectrumWatt::SetTransient()
{
   fXmin = ((TNuTab1*) BodyAt(0))->GetXmin();
   fXmax = ((TNuTab1*) BodyAt(0))->GetXmax();
   TNuESpectrum::SetTransient();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumMadlandNix                                                    //
//                                                                           //
// --- Energy-Dependent Fission Neutron Spectrum (Madland and Nix) (LF=12)   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuESpectrumMadlandNix) //

//______________________________________________________________________________
Double_t MadlandNixTemp(Double_t ep, Double_t ef, Double_t tm)
{
   // temporary function for easy evaluation of TNuESpectrumMadlandNix
   using namespace TMath;

   Double_t u1= (ep + ef - 2*Sqrt(ep*ef))/tm;
   Double_t u2= (ep + ef + 2*Sqrt(ep*ef))/tm;
   double e1u1 = TNuMath::ExpIntegralE1(u1); 
   double e1u2 = TNuMath::ExpIntegralE1(u2); 
   return (Power(u2,1.5)*e1u2 - Power(u1,1.5)*e1u1
      + Gamma(1.5, u2) - Gamma(1.5, u1))
      /(3*Sqrt(ef*tm));
}

//______________________________________________________________________________
Double_t TNuESpectrumMadlandNix::EvalF2(Double_t Ein, Double_t Eout, Double_t *) const
{
   using namespace TMath;

   if (Ein < GetXmin() || Ein >GetXmax()) return 0;
   if (Eout > Ein - GetU()) return 0;
   TNuTab1 *tab1 = (TNuTab1*) BodyAt(0);
   Double_t tm = tab1->Eval(Ein);
   Double_t efl = tab1->GetC1();
   Double_t efh = tab1->GetC2();
   return (MadlandNixTemp(Eout, efl, tm) + MadlandNixTemp(Eout, efh, tm))/2;
}

//______________________________________________________________________________
void TNuESpectrumMadlandNix::SetTransient()
{
   fXmin = ((TNuTab1*) BodyAt(0))->GetXmin();
   fXmax = ((TNuTab1*) BodyAt(0))->GetXmax();
   TNuESpectrum::SetTransient();
}

