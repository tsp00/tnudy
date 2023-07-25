// TNuDEpDMu.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuDEpDMu
#define ROOT_TNuDEpDMu


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec06 : d2XdEdmu = Energy-Angle Distributions                          //
//                                                                           //
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) :                                                               //
// [MAT, 6, MT/ ZA, AWR, 0, LCT, NK, 0]HEAD                                  //
//                                                                           //
// ------------------ body --------------------------------------------------//
// At(n) = n-th TNuDEpDMu, n=0, NK-1                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

//#include "TNuSection.h"
#include "TNuVF3.h"

#include "TNuRecsWithTab1.h"
class TNuTab1;
class TNuTab3;

class TNuSec03;
//class TNuSec06;
#include "TNuSec06.h"
class TNuEndfIO;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMu : TNuRecsWithTab1                                              //
//                                                                           //
//  TNuTab1 for p(E), the fractional probability                             //
//  LAW-dependent subsection for the energy distribution spectrum            //
// [MAT, 6, MT/   ZAP, AWP, LIP, LAW, NR, NP/ Eint /p(E)]TAB1                //
// [MAT, 6, MT/   LAW-dependent structures                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMu : public TNuRecsWithTab1//, public TNuVF3
{
public:
   TNuDEpDMu() : TNuRecsWithTab1() {}
   virtual ~TNuDEpDMu() {}

   Int_t         GetZAP() const { return (Int_t) GetTab1()->GetC1() + 0.5; }
   Double_t      GetAWP() const { return GetTab1()->GetC2(); }
   Int_t         GetLIP() const { return GetTab1()->GetL1(); }
   Int_t         GetLAW() const { return GetTab1()->GetL2(); }

   Int_t         GetZAIP() const { return 10*GetZAP() + GetLIP(); }

   void          What() const; // *MENU*
   void          DrawYield(); // *MENU*
   Double_t      Yield(Double_t Ein) const { return Tab1Eval(Ein); }

   virtual Bool_t  IsF3() const { return kFALSE; }
   virtual Bool_t  IsF2() const { return kFALSE; }
   const Char_t* GetSymbol() const { return "Energy-angle distribution"; }
   const Char_t* GetFigTitle() const;

   //void          DrawEnergyAngleDist() { Draw(); } // *MENU*

   // default x-, y-, z-axis titles
   //const         Char_t* GetXAxisTitle() const { return "E [eV]"; }
   //const         Char_t* GetYAxisTitle() const { return "E' [eV]"; }
   //const         Char_t* GetZAxisTitle() const { return "#mu"; }
   //Double_t      EvalF3(Double_t /*Ein*/, Double_t /*Eout*/, Double_t /*mu*/, Double_t * /*ps*/=0) {
   //   return 0;
   //}

   //Double_t      D2XDEpDMu(Double_t En, Double_t Ep, Double_t mu, Double_t* ps = 0);
   //void          DrawD2XDEpDMu(Option_t *opt="iso"); // *MENU*

   //void     SetQI(Double_t qi) { fQIcopy = qi; }
   //Double_t GetQI() const { return fQIcopy; }

   TNuSec06*   GetSec6000() const { return (TNuSec06*) GetParent(); }
   Int_t         GetMT() const { return GetSec6000()->GetMT(); }
   Double_t      GetQI() const { return GetSec6000()->GetQI(); }
   TNuSec03*   GetSec3000() const { return GetSec6000()->GetSec3000(); }

   //Int_t         GetNSUB() const { return GetParentSublib()->GetNSUB(); }
   //Int_t         GetProjectileZA() const { return GetNSUB()/10; }
   //Double_t      GetProjectileAWR() const { return GetParentMat()->ProjectileMass(); }
   //Int_t         GetTargetZA() const { return GetParentSection()->GetZA(); }
   //Double_t      GetTargetAWR() const { return GetParentSection()->GetAWR(); }
   Int_t         GetEmittedZA() const { return GetZAP(); }
   Double_t      GetEmittedAWR() const { return GetAWP(); }

   Double_t      ELab2ECM(Double_t En) const;

protected:

   ClassDef(TNuDEpDMu, 1) // Law-dependent energy-angle distribution
};


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMuF3 : TNuDEpDMu with TNuVF3                                     //
//                                                                           //
//  TNuTab1 for p(E), the fractional probability                             //
//  LAW-dependent subsection for the energy distribution spectrum            //
// [MAT, 6, MT/   ZAP, AWP, LIP, LAW, NR, NP/ Eint /p(E)]TAB1                //
// [MAT, 6, MT/   LAW-dependent structures                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMuF3 : public TNuDEpDMu, public TNuVF3
{
public:
   TNuDEpDMuF3() : TNuDEpDMu(), TNuVF3() {}
   virtual ~TNuDEpDMuF3() {}


   Bool_t        IsF3() const { return kTRUE; }
   const Char_t* GetSymbol() const { return "Energy-Angle distribution"; }

   // default x-, y-, z-axis titles
   virtual const Char_t* GetXAxisTitle() const { return "E [eV]"; }
   virtual const Char_t* GetYAxisTitle() const { return "E' [eV]"; }
   virtual const Char_t* GetZAxisTitle() const { return "#mu"; }
   Double_t      EvalF3(Double_t /*Ein*/, Double_t /*Eout*/, Double_t /*mu*/, Double_t * /*ps*/=0) const {
      return 0;
   }

   Double_t      D2XDEpDMu(Double_t En, Double_t Ep, Double_t mu, Double_t* ps = 0) const;
   void          DrawD2XDEpDMu(Option_t *opt="box"); // *MENU*
   void          DrawEnergyAngleDistAt(double ein) { DrawF2At("x", ein); } // *MENU*


protected:

   void          SetTransient();

   ClassDef(TNuDEpDMuF3, 1) // TNuDEpDMu with TNuVF3
};


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMuUnknwon                                                         //
//                                                                           //
// --- Unknown Distribution (LAW=0)                                          //
//                                                                           //
// [MAT, 6, MT/   ZAP, AWP, LIP, LAW, NR, NP/ Eint /p(E)]TAB1                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMuUnknwon : public TNuDEpDMuF3
{
public:
   TNuDEpDMuUnknwon() : TNuDEpDMuF3() {}
   TNuDEpDMuUnknwon(TNuEndfIO &src);
   virtual ~TNuDEpDMuUnknwon() {}

   Double_t      EvalF3(Double_t /*Ein*/, Double_t /*Eout*/, Double_t /*mu*/, Double_t * /*ps*/=0) const {
      return 0;
   }

   ClassDef(TNuDEpDMuUnknwon, 1)//Unknown Distribution (LAW=0)
};


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMuContinuum                                                       //
//                                                                           //
// --- Continuum Energy-Angle Distributions (LAW=1)                          //
/*
This law is used to describe particles emitted in multi-body reactions
or combinations of several reactions,
such as scattering through a range of levels or reactions at high energies
where many channels are normally open.
For isotropic reactions, it is very similar to File 5,
LF=1 except for a special option to represent sharp peaks
as delta functions and the use of LIST instead of TAB1 record.
The following quantities are defined for LAW=1:
LANG Indicator which selects the angular representation to be used; if
   LANG=1, Legendre coefficients are used,
   LANG=2, Kalbach-Mann systematics are used,
   LANG=11-15, a tabulated angular distribution is given
      using NA/2 cosines and the interpolation scheme
      specified by LANG-10
      (for example, LANG=12 selects linear-linear interpolation).
LEP Interpolation scheme for secondary energy;
   LEP=1 for histogram,
   LEP=2 for linear-linear, etc.
*/
// [MAT, 6, MT/   ZAP, AWP,  LIP, LAW, NR, NP/ Eint /p(E)]TAB1               //
// [MAT, 6, MT/   0.0, 0.0, LANG, LEP, NR, NE/ Eint]TAB2                     //
// [MAT, 6, MT/   (n-th LIST, n=0, NE-1)                                     //
//                                                                           //
// (n-th LIST) =                                                             //
// [MAT, 6, MT/ 0.0, E1, ND, NA, NW, NEP/                                    //
//   E_1',   b_0(En, E_1'),   b_1(En, E_1'),   ... , b_NA(En, E_1')          //
//   E_2',   b_0(En, E_2'),   b_1(En, E_2'),   ... , b_NA(En, E_2')          //
//    ...                                                                    //
//   E_NEP', b_0(En, E_NEP'), b_1(En, E_NEP'), ... , b_NA(En, E_NEP')        //
//                                                                           //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMuContinuum : public TNuDEpDMuF3
{
public:
   TNuDEpDMuContinuum() : TNuDEpDMuF3() {}
   TNuDEpDMuContinuum(TNuEndfIO &src);
   virtual ~TNuDEpDMuContinuum() {}

   Double_t      EvalF3(Double_t Ein, Double_t Eout, Double_t mu, Double_t *ps=0) const;

protected:
   void          SetTransient();
private:

   ClassDef(TNuDEpDMuContinuum, 1)//Continuum Energy-Angle Distributions (LAW=1)
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMuNBodyPhaseSpace                                                 //
//                                                                           //
// --- N-Body Phase-Space Distributions (LAW=6)                              //
/*
*/
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMuNBodyPhaseSpace : public TNuDEpDMuF3
{
public:
   TNuDEpDMuNBodyPhaseSpace() : TNuDEpDMuF3() {}
   TNuDEpDMuNBodyPhaseSpace(TNuEndfIO &src);
   virtual ~TNuDEpDMuNBodyPhaseSpace() {}

   Double_t GetAPSX() const { return ((TNuCont*) BodyAt(0))->GetC1(); }
   Double_t GetNPSX() const { return ((TNuCont*) BodyAt(0))->GetN2(); }
   Double_t      EvalF3(Double_t Ein, Double_t Eout, Double_t mu, Double_t *ps=0) const;

private:

   ClassDef(TNuDEpDMuNBodyPhaseSpace, 0)//N-Body Phase-Space Distributions (LAW=6)
};


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMuLaboratory                                                      //
//                                                                           //
// --- Laboratory Angle-Energy Law (LAW=7)                                   //
/*
*/
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMuLaboratory : public TNuDEpDMuF3
{
public:
   TNuDEpDMuLaboratory() : TNuDEpDMuF3() {}
   TNuDEpDMuLaboratory(TNuEndfIO &src);
   virtual ~TNuDEpDMuLaboratory() {}

   TNuTab3*      GetTab3() const { return  (TNuTab3*) BodyFirst() ; }

   Double_t      EvalF3(Double_t Ein, Double_t Eout, Double_t mu, Double_t* ps=0) const;

protected:
   void          SetTransient();


   ClassDef(TNuDEpDMuLaboratory, 0)//Laboratory Angle-Energy Law (LAW=7)
};

#endif
