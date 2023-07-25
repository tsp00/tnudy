// TNuList2KalbachMann.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuList2KalbachMann                                                       //
//                                                                           //
//  --- 2 dimensional functor represented as a single LIST                   //
//                                                                           //
//   0.0, En, ND, NA, NW, NEP/                                               //
//   E_0',   b_0(En, E_0'),   b_1(En, E_0'),   ... , b_NA(En, E_0')          //
//   E_1',   b_0(En, E_1'),   b_1(En, E_1'),   ... , b_NA(En, E_1')          //
//   E_2',   b_0(En, E_2'),   b_1(En, E_2'),   ... , b_NA(En, E_2')          //
//    ...                                                                    //
//   E_M',   b_0(En, E_M'),   b_1(En, E_M'),   ... , b_NA(En, E_M')          //
//                                                                           //
//  where M= NEP-1.                                                          //
//                                                                           //
//  Kalbach-Mann :                                                           //
//                                                                           //
//  NA=1 : b_0 = f_0, b_1 = r                                                //
//  NA=2 : b_0 = f_0, b_1 = r, b_2 = a                                       //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuList2KalbachMann.h"
#include "TNuEndfIO.h"
#include "TMath.h"

//#include "TNuSec06.h"
#include "TNuDEpDMu.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuList2KalbachMann)

//______________________________________________________________________________
TNuList2KalbachMann::TNuList2KalbachMann(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuList2(c1,c2,l1,l2,n1,n2)
{
   // TNuList2KalbachMann ctor
}

//______________________________________________________________________________
TNuList2KalbachMann::TNuList2KalbachMann(TNuEndfIO &src, const Char_t* label)
  : TNuList2(src, label)
{
   // ctor of TNuList2KalbachMann importing ENDF data
}

//______________________________________________________________________________
TNuList2KalbachMann::TNuList2KalbachMann(const TNuList2KalbachMann &list)
  : TNuList2(list)
{
   // TNuList2KalbachMann copy ctor
}

//______________________________________________________________________________
TNuList2KalbachMann::~TNuList2KalbachMann()
{
   // TNuList2KalbachMann dtor
}

/*
//______________________________________________________________________________
void TNuList2KalbachMann::What() const
{
using namespace std;
   TNuList2::What();
}
*/

//______________________________________________________________________________
Double_t TNuList2KalbachMann::GetSepEnergyInMeV(Int_t z, Int_t n) const
{
   // simple formula for the separation energy in MeV
   using namespace TMath;
   Int_t a = z + n;
   Int_t diff = (n - z) * (n - z);
   Double_t zz = z * z;
   Double_t a13 = Power(a, 1./3.);
   Double_t a23 = a13 * a13;
   Double_t a43 = a23 * a23;

   Double_t S; // separation energy in MeV
   S =  15.68 * a - 18.56 * a23 - 0.717 * zz / a13
      - 28.07 * diff/a  + 33.22*diff/a43 + 1.211 * zz / a;
   return S;
}

//______________________________________________________________________________
Double_t TNuList2KalbachMann::EvalAt(Int_t n, Double_t mu, Double_t* /*ps*/) const
{
   // returns the evaluated value at n-th sub record
   using namespace TMath;

   Double_t *bs = GetDataArrayAt(n);
   Double_t f0 = bs[0];
   Double_t r = bs[1];
   Double_t a = GetSlopeValue(n);

   Double_t f;
   f = a*f0/(2*SinH(a)) * ( CosH(a*mu) + r*SinH(a*mu));
   return f;
}


//______________________________________________________________________________
void TNuList2KalbachMann::CheckSlopeValues() const
{
   // check the slope value a(Ea, Eb) at n-th point


   printf("\nPrinting the slope values, NA=%d, Ein=%f\n",
      GetNA(), GetEin());

   if (GetNA() != 1 && GetNA() != 2) {
      Error("", "Unsupported value of NA = %d", GetNA());
      return;
   }

   for (int n=0; n < GetNEP(); n++) {
      Double_t *bs = GetDataArrayAt(n);
      //Double_t f0, r, a=1, EaLab, EbCM;
      printf("n=%3d, Ep=%f, f0=%e, r=%f",
         n, GetEAt(n), bs[0], bs[1]);
      if (GetNA() == 2)
         printf(", a= %f", bs[2]);
      printf(", slope = %f\n", GetSlopeValue(GetEin(), GetEAt(n)));
   }
}


//______________________________________________________________________________
Double_t TNuList2KalbachMann::GetSlopeValue(Int_t n) const
{
   // returns the slope value a(Ea, Eb) at n-th point

   Double_t a = 1;

   if (GetNA() == 2) {
      Double_t *bs = GetDataArrayAt(n);
      a = bs[2];
   }
   else if (GetNA() == 1) {
      Double_t EaLab = GetEin(); // energy of incident particle at Lab frame
      Double_t EbCM = GetEAt(n); // energy of emitted particle at CM frame
      a = GetSlopeValue(EaLab, EbCM);
   }
   else {
      Error("", "Unsupported value of NA = %d", GetNA());
   }
   return a;
}

//______________________________________________________________________________
Double_t TNuList2KalbachMann::GetSlopeValue(Double_t EaLab, Double_t EbCM) const
{
   // returns the slope value a(Ea, Eb)
   // a(Ea, Eb) = C1 X1 + C2 X1^3 + C3 Ma mb X3^4

   TNuDEpDMu *parent = GetParentDEpDMu();

   // a + A -> C -> b + B

   // Seperation energies in MeV
   // incident
   Int_t za_a = parent->GetProjectileZA();
   Int_t z_a = za_a/1000, n_a = za_a % 1000 - z_a;
   if (n_a < 0) n_a = parent->GetProjectileAWR() + 0.5 - z_a;
   // target
   Int_t za_A = parent->GetTargetZA();
   Int_t z_A = za_A/1000, n_A = za_A % 1000 - z_A;
   if (n_A < 0) n_A = parent->GetTargetAWR() + 0.5 - z_A;
   Double_t sep_A = GetSepEnergyInMeV(z_A, n_A); // sep energy in MeV
   // emitted
   Int_t za_b = parent->GetZAP();
   Int_t z_b = za_b/1000, n_b = za_b % 1000 - z_b;
   if (n_b < 0) n_b = parent->GetEmittedAWR() + 0.5 - z_b;
   // compound
   Int_t z_C = z_a + z_A, n_C = n_a + n_A;
   Double_t sep_C = GetSepEnergyInMeV(z_C, n_C); // sep energy in MeV
   // residual
   Int_t z_B = z_C - z_b, n_B= n_C - n_b;
   Double_t sep_B = GetSepEnergyInMeV(z_B, n_B); // sep energy in MeV

   struct KalbachMannTable {
      Int_t       fZA;      // ZA
      Double_t    fBreakup; // break up energy in MeV
      Double_t    fMassA;   // mass parameter M
      Double_t    fMassB;   // mass parameter m
   } kmTable[] = {
      {   0, 0.00, 0.0, 0.0},  // gamma
      {   1, 0.00, 1.0, 0.5},  // n
      {1001, 0.00, 1.0, 1.0},  // p
      {1002, 2.22, 1.0, 1.0},  // d
      {1003, 8.48, 1.0, 1.0},  // t
      {2003, 7.72, 1.0, 1.0},  // He3
      {2004, 28.3, 0.0, 1.0}   // He4
   };

   // indices for incident and emitted particles
   Int_t iIncident=-1, iEmitted=-1;

   for (Int_t i=0; i < 7; i++) {
      if (kmTable[i].fZA == za_a) iIncident = i;
      if (kmTable[i].fZA == za_b) iEmitted = i;
   }

   if (iIncident == -1) {
      fprintf(stderr, "Warning in TNuList2KalbachMann::GetSlopeValue"
         "Un-documented value of ZA_a = %d\n", za_a);
      iIncident = 0;
   }

   if (iEmitted == -1) {
      fprintf(stderr, "Warning in TNuList2KalbachMann::GetSlopeValue"
         "Un-documented value of ZA_b = %d\n", za_b);
      iEmitted = 0;
   }

   // mass parameter of the incident and emitted particles
   Double_t Ma = kmTable[iIncident].fMassA;
   Double_t mb = kmTable[iEmitted].fMassB;

   // separation energy of the incident and emitted particles
   Double_t Sa = sep_C - sep_A - kmTable[iIncident].fBreakup;
   Double_t Sb = sep_C - sep_B - kmTable[iEmitted].fBreakup;

  // energy of incident particle at CM frame
   Double_t EaCM = GetParentDEpDMu()->ELab2ECM(EaLab);
   Double_t ea = EaCM + Sa;
   Double_t eb = EbCM + Sb;

   const Double_t C1 = 0.04; // in 1/MeV
   const Double_t C2 = 1.8E-6; // in 1/MeV^3
   const Double_t C3 = 6.7E-7; // in 1/MeV^4
   const Double_t Et1 = 130; // in MeV
   const Double_t Et3 =  41; // in MeV

   Double_t R1 = TMath::Min(ea, Et1);
   Double_t R3 = TMath::Min(ea, Et3);
   Double_t X1 = R1*eb/ea;
   Double_t X3 = R3*eb/ea;

   //printf("\n>>(%d,%d) + (%d,%d) -> (%d, %d) -> (%d, %d) + (%d, %d)\n",
   //   z_a,n_a,z_A,n_A,z_C,n_C, z_b, n_b, z_B, n_B);
   //printf("\n>>s_C=%f, s_A=%f, s_B=%f, ii=%d, b_i=%f, ie=%d, b_e=%f\n",
   //   sep_C, sep_A, sep_B, iIncident, kmTable[iIncident].fBreakup, iEmitted, kmTable[iEmitted].fBreakup);
   //printf("::Ma=%e, mb=%e, Sa=%e, Sb=%e, EaCM=%e, EbCM=%e, ea=%e, eb=%e, R1=%e, R3=%e, X1=%e, X3=%e\n",
   //   Ma,mb,Sa,Sb,EaCM,EbCM, ea,eb,R1,R3,X1,X3);

   Double_t a = C1*X1 + C2*TMath::Power(X1,3) + C3*Ma*mb*TMath::Power(X3,4);
   return a;
}
