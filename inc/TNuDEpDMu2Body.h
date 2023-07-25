// TNuDEpDMu2Body.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuDEpDMu2Body
#define ROOT_TNuDEpDMu2Body


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
#include "TNuVF2.h"

class TNuTab1;
class TNuTab2;

//class TNuSec03;

class TNuEndfIO;


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMu2Body                                                           //
//                                                                           //
// --- Discrete Two-Body Scattering (LAW=2)                                  //
// --- Isotropic Discrete Emission (LAW=3)                                   //
// --- Discrete Two-Body Recoils (LAW=4)                                     //
// --- Charged-Particle Elastic Scattering (LAW=5)                           //
/*
*/
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMu2Body : public TNuDEpDMu, public TNuVF2
{
public:
   TNuDEpDMu2Body() : TNuDEpDMu() {}
   virtual ~TNuDEpDMu2Body() {}

   Bool_t   IsF2() const { return kTRUE; }
   void     DrawTwoBodyDist() { Draw("surf"); } // *MENU*

   const         Char_t* GetXAxisTitle() const { return "E [eV]"; }
   const         Char_t* GetYAxisTitle() const { return "#mu"; }

   Double_t      DXDMu(Double_t Ein, Double_t mu, Double_t* ps = 0) const { return EvalF2(Ein, mu, ps); }
      
   Double_t      EvalF2(Double_t Ein, Double_t mu, Double_t *ps=0) const = 0;

   Double_t      GetEout(Double_t Ein) const;
   
   void     Draw(Option_t* option="") { TNuVF2::VirtualDraw(option); }
   void     Paint(Option_t* option=""){ TNuVF2::VirtualPaint(option); }

protected:
   void     SetTransient();

   ClassDef(TNuDEpDMu2Body, 1) // 2-body scattering data
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMu2BodyScattering                                                 //
//                                                                           //
//  --- Discrete Two-Body Scattering (LAW=2)                                 //
/*
*/
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMu2BodyScattering : public TNuDEpDMu2Body
{
public:
   TNuDEpDMu2BodyScattering() : TNuDEpDMu2Body() {}
   TNuDEpDMu2BodyScattering(TNuEndfIO &src);
   virtual ~TNuDEpDMu2BodyScattering() {}

   Double_t      EvalF2(Double_t Ein, Double_t mu, Double_t *ps=0) const;

   ClassDef(TNuDEpDMu2BodyScattering, 0) //Discrete Two-Body Scattering (LAW=2)
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMu2BodyIsotropic                                                  //
//                                                                           //
// --- Isotropic Discrete Emission (LAW=3)                                   //
/*
*/
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMu2BodyIsotropic : public TNuDEpDMu2Body
{
public:
   TNuDEpDMu2BodyIsotropic() : TNuDEpDMu2Body() {}
   TNuDEpDMu2BodyIsotropic(TNuEndfIO &src);
   virtual ~TNuDEpDMu2BodyIsotropic() {}

   Double_t      EvalF2(Double_t Ein, Double_t mu, Double_t *ps=0) const;

private:

   ClassDef(TNuDEpDMu2BodyIsotropic, 0)  //Isotropic Discrete Emission (LAW=3)
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMu2BodyRecoil                                         //
//                                                                           //
// --- Discrete Two-Body Recoils (LAW=4)                                     //
/*
*/
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMu2BodyRecoil : public TNuDEpDMu2Body
{
public:
   TNuDEpDMu2BodyRecoil() : TNuDEpDMu2Body() {}
   TNuDEpDMu2BodyRecoil(TNuEndfIO &src);
   virtual ~TNuDEpDMu2BodyRecoil() {}

   void     DrawTwoBodyDist() {} // nothing to be drawn for this
   Double_t      EvalF2(Double_t Ein, Double_t mu, Double_t *ps=0) const;

private:

   ClassDef(TNuDEpDMu2BodyRecoil, 0) //Discrete Two-Body Recoils (LAW=4)
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuDEpDMu2BodyCoulomb                                                    //
//                                                                           //
// --- Charged-Particle Elastic Scattering (LAW=5)                           //
/*
*/
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuDEpDMu2BodyCoulomb : public TNuDEpDMu2Body
{
public:
   TNuDEpDMu2BodyCoulomb() : TNuDEpDMu2Body() {}
   TNuDEpDMu2BodyCoulomb(TNuEndfIO &src);
   virtual ~TNuDEpDMu2BodyCoulomb() {}

   TNuTab2*      GetTab2() const { return  (TNuTab2*) BodyFirst() ; }

   Double_t      EvalF2(Double_t Ein, Double_t mu, Double_t *ps=0) const;


   ClassDef(TNuDEpDMu2BodyCoulomb, 0)//Charged-Particle Elastic Scattering (LAW=5)
};

#endif
