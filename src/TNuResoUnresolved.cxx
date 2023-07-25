// TNuResoUnresolved.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuResoUnresolved: public TNuResonance                                    //
//                                                                           //
//   = Ubresolved Resonance Parameters (LRU=2)                               //
//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuResoUnresolved.h"

//#include "TNuSec02151.h"
#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2.h"
#include "TNuRecsWithCont.h"
#include "TNuContLists.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TPad.h"

#include "TNuMath.h"
#include "TArrayD.h"

using namespace TMath;
using namespace std;

ClassImp(TNuResoUnresolved)

#define LOCAL

//______________________________________________________________________________
Int_t LOCAL GNRL3(Double_t GNX, Double_t GGX, Double_t GFX, Double_t GXX,
   Int_t mun,Int_t muf,Int_t mux,
   Double_t *RN, Double_t *RC, Double_t *RF)
{
   // It calculates the fluctuation functions for
   // elastic, capture and fission.
   //
   // Code is from SUBROUTINE GNRL3 of recent.f of PREPRO07.

   // if Abs(den) < epsilon, generates errors
   const Double_t epsilon = 1.E-20;
   Int_t errors = 0;

   const Double_t X[10][5] = {
      {1.0, 3.0013465E-03, 1.3219203E-02, 1.0004488E-03, 1.3219203E-02},
      {0.0, 7.8592886E-02, 7.2349624E-02, 2.6197629E-02, 7.2349624E-02},
      {0.0, 4.3282415E-01, 1.9089473E-01, 1.4427472E-01, 1.9089473E-01},
      {0.0, 1.3345267E+00, 3.9528842E-01, 4.4484223E-01, 3.9528842E-01},
      {0.0, 3.0481846E+00, 7.4083443E-01, 1.0160615E+00, 7.4083443E-01},
      {0.0, 5.8263198E+00, 1.3498293E+00, 1.9421066E+00, 1.3498293E+00},
      {0.0, 9.9452656E+00, 2.5297983E+00, 3.3150885E+00, 2.5297983E+00},
      {0.0, 1.5782128E+01, 5.2384894E+00, 5.2607092E+00, 5.2384894E+00},
      {0.0, 2.3996824E+01, 1.3821772E+01, 7.9989414E+00, 1.3821772E+01},
      {0.0, 3.6216208E+01, 7.5647525E+01, 1.2072069E+01, 7.5647525E+01}
   };  // Gaussian points
   const Double_t W[10][5] = {
      {1.0, 1.1120413E-01, 3.3773418E-02, 3.3376214E-04, 1.7623788E-03},
      {0.0, 2.3546798E-01, 7.9932171E-02, 1.8506108E-02, 2.1517749E-02},
      {0.0, 2.8440987E-01, 1.2835937E-01, 1.2309946E-01, 8.0979849E-02},
      {0.0, 2.2419127E-01, 1.7652616E-01, 2.9918923E-01, 1.8797998E-01},
      {0.0, 1.0967668E-01, 2.1347043E-01, 3.3431475E-01, 3.0156335E-01},
      {0.0, 3.0493789E-02, 2.1154965E-01, 1.7766657E-01, 2.9616091E-01},
      {0.0, 4.2930874E-03, 1.3365186E-01, 4.2695894E-02, 1.0775649E-01},
      {0.0, 2.5827047E-04, 2.2630659E-02, 4.0760575E-03, 2.5171914E-03},
      {0.0, 4.9031965E-06, 1.6313638E-05, 1.1766115E-04, 8.9630388E-10},
      {0.0, 1.4079206E-08, 0.0000000E+00, 5.0989546E-07, 0.0000000E+00}
   }; // Gaussian weights

   *RN=0;
   *RC=0;
   *RF=0;

   if(GNX <= 0 || GGX <= 0.0 || GFX < 0) return 0;

   if(mun < 0 || mun > 4) mun=0;
   if(mux < 0 || mux > 4) mux=0;
   if(muf < 0 || muf > 4) muf=0;

   for (Int_t j=0; j < 10; j++) {
      Double_t XJ=X[j][mun];
      for (Int_t k=0; k < 10; k++) {
         Double_t XK=X[k][muf];
         for(Int_t l=0; l<10; l++) {
            Double_t XL=X[l][mux];
            Double_t den = GNX*XJ + GGX + GFX*XK + GXX*XL;
            if (TMath::Abs(den) < epsilon) {
               den= epsilon;
               if (errors++ < 10)
                  fprintf(stderr, "Warning : "
                    "Too small denominator,  %e -> %e\n", den, epsilon);
            }
            Double_t factor= W[l][mux]*W[k][muf]*W[j][mun]*XJ/den;
            *RN += XJ*factor;
            *RC +=    factor;
            *RF += XK*factor;

         }
      }
   }
   return errors;
}

//______________________________________________________________________________
void TNuResoUnresolved::EvalEachRP(Double_t p, Double_t gJ, Double_t phiL,
   Double_t d, Double_t gX, Double_t gN, Double_t gG, Double_t gF,
   Double_t amuX, Double_t amuN, Double_t amuF,
   Double_t sig[])
{
   // Evaluate resonance parameters
   // p     = incident CM energy [in 1/ 10^(-12) cm]
   // phiL  = phase shift
   // gJ    = (2 * Abs(AJ) + 1)/(4*GetSPI()+2)
   // nuL = P_L / rho
   //
   // d   = Average level spacing for resonances with spin J
   // gX  = Average competitive reaction width, given only when LRF=2
   // gN0 = Average reduced neutron width.
   // gN  = Average neutron width.
   // gG  = Average radiation width.
   // gF  = Average fission width.
   //
   // amuX = dof in the competitive width distribution.
   // amuN = dof in the neutron width distribution.
   // amuG = dof in the radiation width distribution.
   // amuF = dof in the fission width distribution.
   //
   // sig[4] : resonance contribution to each component of the cross sections

   using namespace TMath;
   static int dataerror=0;

   //for (Int_t i=0; i< 4; i++) sig[i]=0;

   // The degrees of freedom
   Int_t muX= amuX+0.1; // in the competitive width distribution.
   Int_t muN= amuN+0.1; // in the neutron width distribution.
   //Int_t muG= amuG+0.1; // in the radiation width distribution.
   Int_t muF= amuF+0.1; // in the fission width distribution.

   //Double_t gN = amuN * gN0 * nuL; // Average neutron width

   Double_t rN, rC, rF; // fluctuation functions
   Int_t errors = 0;
   errors = GNRL3(gN, gG, gF, gX, muN, muF, muX, &rN, &rC, &rF);

   Double_t gT = gN + gG + gF + gX; // average total width G_l,J
   Double_t factor = 2*Pi()*Pi()/(p*p) * gJ / d;

   // for debugging
   if ((Abs(d) < 1.E-10 || Abs(gT) < 1.E-10 || !(Abs(factor) < 1.E10)) && dataerror < 30 ) {
      dataerror++;
      printf("xxxxxxxxxxxxxxx-- errors = %d\n", errors);
      printf("D=%e, GN=%e, GG=%e, GF=%e, GX=%e\n", d, gN, gG, gF, gX);
      printf("GT=%e, GN = %e, gJ=%e, factor = %e\n", gT, gN, gJ, factor);
   }

   Double_t sinphi2 = Sin(phiL) * Sin(phiL);

   sig[kElastic] += factor * gN * (gN * rN - 2 * sinphi2);
   sig[kCapture] += factor * gN * gG * rC;
   sig[kFission] += factor * gN * gF * rF;

   sig[kTotal] = sig[kElastic] + sig[kCapture] + sig[kFission];
}

//______________________________________________________________________________
Int_t TNuResoUnresolved::GenerateMeshPoints(TArrayD& mesh) const
{
   // Generates mesh points for the range  EL < ER < EH
   // according to the accuracy

   Double_t logEL= TMath::Log(GetEL());
   Double_t logEH= TMath::Log(GetEH());
   Int_t accuracy = GetAccuracy();
   Int_t size = accuracy*10 + 2;
   //TArrayD mesh(size+1);
printf("accuracy =%d, size=%d\n", accuracy, size);
   mesh.Set(size);
   for (Int_t n=0; n < size; n++) {
      // logE = n/size (logEH - logEL) + logEL
      Double_t logE = n*(logEH-logEL)/(size-1.) + logEL;
      Double_t en= (n==0) ? GetEL() : TMath::Exp(logE);
//printf("n=%d/%d, en=%e\n", n,size, en);
      mesh.AddAt(en, n);
   }
   mesh[size-1] = GetEH();
   return size;
}

/////////////////////////////////////////////////////////////////////////////
//
// TNuResoUnresolvedA : public TNuResoUnresolved
//
// Case A : LFW=0 (fission widths not given)
//          LRF=1 (all parameters are energy-independent)
//
// ------------------ head --------------------------------------------------
//
// HeadAt(0) = RangeCont() =
// [MAT, 2,151/  EL,   EH,   LRU,  LRF,  NRO,   NAPS]CONT (range)
//
// HeadAt(1) = GetAPE() =
// [MAT, 2,151/ 0.0,  0.0,  0,    0,    NR,    NP/Eint/AP(E)]TAB1 (if NRO!=0)
//
// HeadAt(2) = SpinCont() =
// [MAT, 2,151/ SPI,  AP,   LSSF,   0,     NLS,   0] CONT
//
// ------------------ body --------------------------------------------------
//
// At(n) : n-th subsection (for a given L or J) of the resonance data
//  = a TNuList :
//
//[MAT, 2,151/ AWRI, 0.0,  L,      0,     6*NJS, NJS/
//             D_1,  AJ_1, AMUN_1, GN0_1, GG_1,  0.0,
//             D_2,  AJ_2, AMUN_2, GN0_2, GG_2,  0.0,
//             --------------------------------------
//             D_N,  AJ_N, AMUN_N, GN0_N, GG_N,  0.0] LIST (with N=NJS)
// The LIST record is repeated until data for all l-values have been
// specified. In this example, AMUG is assumed to be zero, and
// there is no competitive width.
//
// ------------------ notes -------------------------------------------------
//
//
/////////////////////////////////////////////////////////////////////////////

ClassImp(TNuResoUnresolvedA)

//______________________________________________________________________________
void TNuResoUnresolvedA::ImportEndfData(TNuEndfIO& src)
{
   // Case A : LFW=0 (fission widths not given)
   //          LRF=1 (all parameters are energy-independent)

   //SetCont(new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range"));
   //if (GetNRO())
   //   Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));

   SetSpinCont(new TNuCont(src, "SPI, AP, LSSF, 0, NLS, 0"));

   for (Int_t nls=0; nls < GetNLS(); nls++) {
      Add(new TNuList(src, "AWRI, 0.0, L, 0, 6*NJS, NJS"
         "; D, AJ, AMUN, GN0, GG, 0.0"));
   }
}

//______________________________________________________________________________
void TNuResoUnresolvedA::EvalRP(Double_t Ein, Double_t sig[]) const
{
   // Evaluate resonance parameters
   // Ein : incident energy [in eV]
   // sig[4] : resonance contribution to each component of the cross sections
   // [MAT, 2,151/ SPI, AP, LSSF, 0, NLS, 0] CONT

   using namespace TMath;
   //static int dataerror=0;

   for (Int_t i=0; i< 4; i++) sig[i]=0;
   if (!IsValid(Ein)) return;

   //Double_t hat_radius = (GetNRO() == 0) ? GetAP() : GetAPE(Ein);

   // CM momentum p when Ein = 1 eV in [1/10^(-12) cm]
   Double_t p = Getpcm(Ein);

   for (Int_t n=0; n < GetNLS(); n++) {
      // loop over for each value of L
      // AWRI, 0.0,  L,      0,     6*NJS, NJS/
      // D_1,  AJ_1, AMUN_1, GN0_1, GG_1,  0.0,
      // D_2,  AJ_2, AMUN_2, GN0_2, GG_2,  0.0,
      // --------------------------------------
      // D_N,  AJ_N, AMUN_N, GN0_N, GG_N,  0.0] LIST (with N=NJS)

      TNuList *sub = (TNuList*) BodyAt(n);
      Int_t L = sub->GetL1();
      Int_t NJS=sub->GetN2();

      Double_t rho = p * GetRadius(Ein);
      Double_t Sl, Pl; // S_l(|Ein|) and P_l(|E|)
      TNuMath::HardsphereFactors(L, rho, &Pl, &Sl);

      Double_t phiL = GetHardspherePhaseShift(L, Ein, p);
      Double_t nuL = Pl/rho;

      sig[kElastic] += 4 * Pi()/(p*p) * (2*L + 1) * Sin(phiL) * Sin(phiL) ;

      Double_t *data = sub->GetData();

      for (Int_t njs=0; njs < NJS; njs++, data += 6) {
         // loop over for each value of J = AJ
         // D_n,  AJ_n, AMUN_n, GN0_n, GG_n,  0.0,

         Double_t AJ  = data[1]; // Floating-point value of J

         // The degrees of freedom
         Double_t amuX = 0; // in the competitive width distribution.
         Double_t amuN = data[2];// in the neutron width distribution.
         //Double_t amuG= list->At(4); // in the radiation width distribution.
         Double_t amuF = 0; // in the fission width distribution.

         Double_t d=    data[0];  // Average level spacing for resonances with spin J
         Double_t gX =  0;  // Average competitive reaction width, given only when LRF=2
         Double_t gN0 = data[3];  // Average reduced neutron width.
         Double_t gG =  data[4]; // Average radiation width.
         Double_t gF =  0; // Average fission width.

         // Average neutron width.
         Double_t gN = amuN * gN0 *nuL *Sqrt(Ein);

         Double_t gJ = (2 * Abs(AJ) + 1)/(4*GetSPI()+2);

         TNuResoUnresolved::EvalEachRP(p, gJ, phiL,
            d, gX, gN, gG, gF, amuX, amuN, amuF, sig);
      }
   }
   sig[kTotal] = sig[kElastic] + sig[kCapture] + sig[kFission];
}



/////////////////////////////////////////////////////////////////////////////
//
// TNuResoUnresolvedB : public TNuResoUnresolved
//
// Case B : LFW=1 (fission widths given)
//          LRF=1 (only fission widths are energy-dependent;
//                 the rest are energy-independent).
//
// ------------------ head --------------------------------------------------
//
// HeadAt(0) = RangeCont() =
// [MAT, 2,151/  EL,   EH,   LRU,  LRF,  NRO,   NAPS]CONT (range)
//
// HeadAt(1) = GetAPE() =0.0,  0.0,  0,    0,    NR,    NP/Eint/AP(E)]TAB1 (if NRO!=0)
// [MAT, 2,151/
//
// HeadAt(2) = SpinCont() =
//[MAT, 2,151/ SPI, AP, LSSF, 0, NE, NLS]CONT
//             ES1, ES2, ES3, ------------
//             ------------------------- ESNE]LIST
//
// ------------------ body --------------------------------------------------
//
// At(n) : n-th subsection (for a given L or J) of the resonance data
//  = a TNuContLists :
//
//[MAT, 2,151/AWRI, 0.0, L, 0, NJS, 0]CONT
//[MAT, 2,151/ 0.0, 0.0, L, MUF, NE+6, 0/
//             D, AJ, AMUN, GN0, GG, 0.0,
//             GF1, GF2, GF3,--------------
//             ------------------------- GFNE]LIST
// The last LIST record is repeated for each J-value
// (there will be NJS such LIST records).
// A new CONT(l) record will then be given which will be followed
// by its NJS LIST records until data for all l-values have been specified
// (there will be NLS sets of data).
// In the above section, no provision was made for INT, and interpolation
// is assumed to be linear-linear. AMUG is assumed to be zero,
// AMUF equals MUF, and there is no competitive width.
//
// ------------------ notes -------------------------------------------------
//
//
/////////////////////////////////////////////////////////////////////////////

ClassImp(TNuResoUnresolvedB)

//______________________________________________________________________________
void TNuResoUnresolvedB::ImportEndfData(TNuEndfIO& src)
{
   // Case B : LFW=1 (fission widths given)
   //          LRF=1 (only fission widths are energy-dependent;
   //                the rest are energy-independent).

   //SetCont(new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range"));
   //if (GetNRO())
   //   Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));

   SetSpinCont(new TNuList(src, "SPI, AP, LSSF, 0, NE, NLS/{ES}"));

   for (Int_t nls=0; nls < GetNLS(); nls++) {
      TNuContLists* sub = new TNuContLists();

      sub->SetCont(new TNuCont(src, "AWRI, 0.0, L, 0, NJS, 0"));
      for (Int_t njs=0; njs < sub->GetN1(); njs++) {
         sub->Add(new TNuList(src, "0.0, 0.0, L, MUF, NE+6, 0"
            "; D, AJ, AMUN, GN0, GG, 0.0"
            "& GF, GF, GF, GF, GF, GF"));
      }
      Add(sub);
   }
}


//______________________________________________________________________________
void TNuResoUnresolvedB::EvalRP(Double_t Ein, Double_t sig[]) const
{
   // Evaluate resonance parameters
   // Ein : incident energy [in eV]
   // sig[4] : resonance contribution to each component of the cross sections
   // [MAT, 2,151/ SPI, AP, LSSF, 0, NE, NLS/{ES}] / LIST
   using namespace TMath;
   //static int dataerror=0;

   for (Int_t i=0; i< 4; i++) sig[i]=0;
   if (!IsValid(Ein)) return;

   // CM momentum p when Ein = 1 eV in [1/10^(-12) cm]
   Double_t p = Getpcm(Ein);

   TNuList* spincont = (TNuList*) SpinCont();
   for (Int_t nls=0; nls < GetNLS(); nls++) {
      // loop over for each value of L
      //[MAT, 2,151/ AWRI, 0.0, L, 0, NJS, 0]CONT + LIST*NLS

      TNuContLists *sub = (TNuContLists*) BodyAt(nls);
      Int_t L = sub->GetL1();
      Int_t NJS=sub->GetN1();

      Double_t rho = p * GetRadius(Ein);
      Double_t Sl, Pl; // S_l(|Ein|) and P_l(|E|)
      TNuMath::HardsphereFactors(L, rho, &Pl, &Sl);

      Double_t phiL = GetHardspherePhaseShift(L, Ein, p);
      Double_t sinphi2 = Sin(phiL) * Sin(phiL);

      Double_t nuL = Pl/rho;

      sig[kElastic] += 4 * Pi()/(p*p) * (2*L + 1) * sinphi2 ;

      for (Int_t njs=0; njs < NJS; njs++) {
         // loop over for each value of J = AJ
         /*
         [MAT, 2,151/ 0.0, 0.0, L, MUF, NE+6, 0 /
            D, AJ, AMUN, GN0, GG, 0.0,
            GF[0], ..., GF[NE-1]] LIST
         */
         TNuList *list = sub->BodyAt(njs);
         list->AssertClassName("TNuList");
         Double_t AJ  = list->At(1); // Floating-point value of J
         //??Int_t INT = list->GetL1(); // Interpolation scheme between the cross sections
         Int_t NE = list->GetN1() - 6;

         // The degrees of freedom
         Double_t amuX = 0; // in the competitive width distribution.
         Double_t amuN = list->At(2);// in the neutron width distribution.
         //Double_t amuG= list->At(4); // in the radiation width distribution.
         Double_t amuF = list->GetL2(); // in the fission width distribution.

         Double_t *data = list->GetData() + 6; // skipping the head

         Double_t d=    list->At(0);  // Average level spacing for resonances with spin J
         Double_t gX =  0;  // Average competitive reaction width, given only when LRF=2
         Double_t gN0 = list->At(3);  // Average reduced neutron width.
         Double_t gG =  list->At(4); // Average radiation width.

         Double_t gF; // Average fission width.

         Int_t n = BinarySearch(NE, spincont->GetData(), Ein);
         Double_t xys[4];

         xys[0] = spincont->At(n);
         xys[1] = data[n];
         xys[2] = spincont->At(n+1);
         xys[3] = data[n+1];

         Int_t interp = 2;
         gF = TNuVTab::Interpolation(interp, Ein, xys);

         // Average neutron width.
         Double_t gN = amuN * gN0 *nuL *Sqrt(Ein);

         Double_t gJ = (2 * Abs(AJ) + 1)/(4*GetSPI()+2);

         TNuResoUnresolved::EvalEachRP(p, gJ, phiL,
            d, gX, gN, gG, gF, amuX, amuN, amuF, sig);
      }
   }
   sig[kTotal] = sig[kElastic] + sig[kCapture] + sig[kFission];
}

/////////////////////////////////////////////////////////////////////////////
//
// TNuResoUnresolvedC : public TNuResoUnresolved
//
// Case C : LFW=0 or 1 (does not depend on LFW).
//          LRF=2 (all energy-dependent parameters).
//
// ------------------ head --------------------------------------------------
//
// HeadAt(0) = RangeCont() =
// [MAT, 2,151/  EL,   EH,   LRU,  LRF,  NRO,   NAPS]CONT (range)
//
// HeadAt(1) = GetAPE() =
// [MAT, 2,151/ 0.0,  0.0,  0,    0,    NR,    NP/Eint/AP(E)]TAB1 (if NRO!=0)
//
// HeadAt(2) = SpinCont() =
// [MAT, 2,151/ SPI,   AP,   LSSF,  0,      NLS,    0]CONT
//
// ------------------ body --------------------------------------------------
//
// At(n) : n-th subsection (for a given L or J) of the resonance data
// = a TNuContLists :
//
//[MAT, 2,151/ AWRI,  0.0,  L,     0,      NJS,    0]CONT
//[MAT, 2,151/ AJ,    0.0,  INT,   0,      6*NE+6, NE/
//             0.0,   0.0,  AMUX,  AMUN,   AMUG,   AMUF,
//             ES_1,  D_1,  GX_1,  GN0_1,  GG_1,   GF_1,
//             ES_2,  D_2,  GX_2,  GN0_2,  GG_2,   GF_2,
//             ----------------------------------------
//             ES_NE, D_NE, GX_NE, GN0_NE, GG_NE,  GF_NE] LIST
// The LIST record is repeated until all the NJS J-values have been
// specified for a given lvalue.
//
// ------------------ notes -------------------------------------------------
//
//
/////////////////////////////////////////////////////////////////////////////

ClassImp(TNuResoUnresolvedC)

//______________________________________________________________________________
void TNuResoUnresolvedC::ImportEndfData(TNuEndfIO& src)
{
   // Case C : LFW=0 or 1 (does not depend on LFW).
   //          LRF=2 (all energy-dependent parameters).

   //SetCont(new TNuCont(src, " EL, EH, LRU, LRF, NRO, NAPS /range"));
   //if (GetNRO())
   //   Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/AP(E)"));

   SetSpinCont(new TNuCont(src, "SPI, AP, LSSF, 0, NLS, 0"));

   for (Int_t nls=0; nls < GetNLS(); nls++) {
      TNuContLists* sub = new TNuContLists();

      sub->SetCont(new TNuCont(src, "AWRI, 0.0, L, 0, NJS, 0"));
      for (Int_t njs=0; njs < sub->GetN1(); njs++) {
         sub->Add(new TNuList(src, "AJ, 0.0, INT, 0, 6*NE+6, NE"
            "; 0.0, 0.0, AMUX, AMUN, AMUG, AMUF"
            "& ES, D, GX, GN0, GG, GF "));
      }
      Add(sub);
   }
}


//______________________________________________________________________________
void TNuResoUnresolvedC::EvalRP(Double_t Ein, Double_t sig[]) const
{
   // Evaluate resonance parameters
   // Ein : incident energy [in eV]
   // sig[4] : resonance contribution to each component of the cross sections
   // [MAT, 2,151/ SPI, AP, 0, 0, NLS, 0]CONT
   using namespace TMath;
   //static int dataerror=0;

   for (Int_t i=0; i< 4; i++) sig[i]=0;
   if (!IsValid(Ein)) return;

   // CM momentum p when Ein = 1 eV in [1/10^(-12) cm]
   Double_t p = Getpcm(Ein);

   for (Int_t n=0; n < GetNLS(); n++) {
      // loop over for each value of L
      //[MAT, 2,151/ AWRI,  0.0,   L,     0,      NJS,    0]CONT + LIST*NLS

      TNuContLists *sub = (TNuContLists*) BodyAt(n);
      Int_t L = sub->GetL1();
      Int_t NJS=sub->GetN1();


      Double_t rho = p * GetRadius(Ein);
      Double_t Pl, Sl; // S_l(|Ein|) and P_l(|E|)
      TNuMath::HardsphereFactors(L, rho, &Pl, &Sl);
      Double_t phiL = GetHardspherePhaseShift(L, Ein, p);
      Double_t sinphi2 = Sin(phiL) * Sin(phiL);
      Double_t nuL = Pl/rho;

      sig[kElastic] += 4 * Pi()/(p*p) * (2*L + 1) * sinphi2 ;

      for (Int_t njs=0; njs < NJS; njs++) {
         // loop over for each value of J = AJ
         /*
         [MAT, 2,151/ AJ,    0.0,   INT,   0,      6*NE+6, NE/
         0.0,   0.0,   AMUX,  AMUN,   AMUG,   AMUF,
         ES_1,  D_1,   GX_1,  GN0_1,  GG_1,   GF_1,
         ES_2,  D_2,   GX_2,  GN0_2,  GG_2,   GF_2,
         -----------------------------
         ES_NE, D)NE,  GX_NE, GN0_NE, GG_NE,  GF_NE] LIST
         */
         TNuList *list = sub->BodyAt(njs);
         list->AssertClassName("TNuList");
         Double_t AJ  = list->GetC1(); // Floating-point value of J
         Int_t interp = list->GetL1(); // Interpolation scheme between the cross sections
         Int_t NE = list->GetN2();

         // The degrees of freedom
         Double_t amuX = list->At(2);  // in the competitive width distribution.
         Double_t amuN = list->At(3);  // in the neutron width distribution.
         //Double_t amuG= list->At(4); // in the radiation width distribution.
         Double_t amuF = list->At(5);  // in the fission width distribution.

         Double_t *data = list->GetData() + 6; // skipping the head

         Double_t r[6];

         TNuMath::Interpolation(Ein, data, interp, NE, 6, r);

         Double_t d=    r[1]; // Average level spacing for resonances with spin J
         Double_t gX =  r[2]; // Average competitive reaction width, given only when LRF=2
         Double_t gN0 = r[3]; // Average reduced neutron width.
         Double_t gG =  r[4]; // Average radiation width.
         Double_t gF =  r[5]; // Average fission width.

         // Average neutron width.
         Double_t gN = amuN * gN0 *nuL *Sqrt(Ein);

         Double_t gJ = (2 * Abs(AJ) + 1)/(4*GetSPI()+2);
         TNuResoUnresolved::EvalEachRP(p, gJ, phiL,
            d, gX, gN, gG, gF, amuX, amuN, amuF, sig);
      }
   }
   sig[kTotal] = sig[kElastic] + sig[kCapture] + sig[kFission];
}
