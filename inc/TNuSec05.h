// TNuSec05.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec05
#define ROOT_TNuSec05
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec05 : dXdE = Energy Distributions                          //
/* Begin_Latex
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
// HeadAt(0) :
// [MAT, 5, MT/ ZA, AWR, 0, 0, NK, 0]HEAD                                    //
//
// ------------------ body --------------------------------------------------//
// At(n) = n-th TNuESpectrum, n=0, NK-1                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF2.h"

#include "TNuRecsWithTab1.h"
#include "TNuTab1.h"
#include "TNuTab2.h"

class TNuEndfIO;

class TNuSec05 : public TNuSection, public TNuVF2
{
public:
   TNuSec05() : TNuSection(), TNuVF2() {}
   TNuSec05(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), TNuVF2() {}
   virtual ~TNuSec05() {}

   Bool_t   IsF2() const { return kTRUE; }
   const Char_t* GetSymbol() const { return "Energy distribution"; }

   const    Char_t* GetXAxisTitle() const { return "E [eV]"; }
   const    Char_t* GetYAxisTitle() const { return "E' [eV]"; }

   Double_t DXDENormalized(Double_t Ein, Double_t Eout) const { return EvalF2(Ein, Eout); }
   Double_t EvalF2(Double_t Ein, Double_t Eout, Double_t *ps=0) const;
   Int_t    GetNK() const { return GetN1(); }
   void     DrawDXDENormalized() { Draw("surf"); } // *MENU*

   void          ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();
   //void     SetTransient();


   ClassDef(TNuSec05, 1) // Energy Distributions
};

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

class TNuESpectrum : public TNuRecsWithTab1, public TNuVF2
{
public:
   TNuESpectrum() : TNuRecsWithTab1(), TNuVF2() {}
   virtual ~TNuESpectrum() {}
   Int_t    GetLF() const { return ((TNuCont*) BodyAt(0))->GetL2(); }
   Double_t GetU()  const { return ((TNuCont*) BodyAt(0))->GetC1(); }

   Bool_t        IsF2() const { return kTRUE; }
   const Char_t* GetSymbol() const { return "Energy distribution [1/eV]"; }
   void          DrawDXDENormalized() { Draw("surf"); } // *MENU*

   // range of incident E is given by that of TNuRecsWithTab1
   // range of E' : 0 <= E' < E - U
   ////Double_t      GetYmin() const { return  0; }
   ////Double_t      GetYmax() const { return  GetXmax() - GetU(); }


   // default x-, y-axis labels
   const         Char_t* GetXAxisTitle() const { return "E [eV]"; }
   const         Char_t* GetYAxisTitle() const { return "E' [eV]"; }

protected:
   virtual void  SetTransient();

   ClassDef(TNuESpectrum, 1) //Generic class for energy distributions
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumTabulated                                            //
//                                                                           //
// --- Arbitrary Tabulated Function (LF=1)                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuESpectrumTabulated : public TNuESpectrum
{
public:
   TNuESpectrumTabulated() : TNuESpectrum() {}
   virtual ~TNuESpectrumTabulated() {}

   Double_t EvalF2(Double_t Ein, Double_t Eout, Double_t *ps=0) const;

protected:
   void     SetTransient();

   ClassDef(TNuESpectrumTabulated, 1) // Arbitrary Tabulated Function (LF=1)
};


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumGeneralEvaporation                                            //
//                                                                           //
// --- General Evaporation Spectrum (LF=5)                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuESpectrumGeneralEvaporation : public TNuESpectrum
{
public:
   TNuESpectrumGeneralEvaporation() : TNuESpectrum() {}
   virtual ~TNuESpectrumGeneralEvaporation() {}

   Double_t EvalF2(Double_t Ein, Double_t Eout, Double_t *ps=0) const;

protected:
   void     SetTransient();

private:

   ClassDef(TNuESpectrumGeneralEvaporation, 1) //General Evaporation Spectrum (LF=5)
};


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumMaxwellian                                                    //
//                                                                           //
// --- Simple Maxwellian Fission Spectrum (LF=7)                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuESpectrumMaxwellian : public TNuESpectrum
{
public:
   TNuESpectrumMaxwellian() : TNuESpectrum() {}
   virtual ~TNuESpectrumMaxwellian() {}

   Double_t EvalF2(Double_t Ein, Double_t Eout, Double_t *ps=0) const;

protected:
   void     SetTransient();

private:

   ClassDef(TNuESpectrumMaxwellian, 1) //Simple Maxwellian Fission Spectrum (LF=7)
};


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumEvaporation                                                   //
//                                                                           //
// --- Evaporation Spectrum (LF=9)                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuESpectrumEvaporation : public TNuESpectrum
{
public:
   TNuESpectrumEvaporation() : TNuESpectrum() {}
   virtual ~TNuESpectrumEvaporation() {}

   Double_t EvalF2(Double_t Ein, Double_t Eout, Double_t *ps=0) const;

protected:
   void     SetTransient();

private:

   ClassDef(TNuESpectrumEvaporation, 1) //Evaporation Spectrum (LF=9)
};


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumWatt                                                          //
//                                                                           //
// --- Energy-Dependent Watt Spectrum (LF=11)                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuESpectrumWatt : public TNuESpectrum
{
public:
   TNuESpectrumWatt() : TNuESpectrum() {}
   virtual ~TNuESpectrumWatt() {}

   Double_t EvalF2(Double_t Ein, Double_t Eout, Double_t *ps=0) const;

protected:
   void     SetTransient();

private:

   ClassDef(TNuESpectrumWatt, 1) //Energy-Dependent Watt Spectrum (LF=11)
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuESpectrumMadlandNix                                                    //
//                                                                           //
// --- Energy-Dependent Fission Neutron Spectrum (Madland and Nix) (LF=12)   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuESpectrumMadlandNix : public TNuESpectrum
{
public:
   TNuESpectrumMadlandNix() : TNuESpectrum() {}
   virtual ~TNuESpectrumMadlandNix() {}

   Double_t EvalF2(Double_t Ein, Double_t Eout, Double_t *ps=0) const;

protected:
   void     SetTransient();

private:

   ClassDef(TNuESpectrumMadlandNix, 1) //Energy-Dependent Fission Neutron Spectrum (Madland and Nix) (LF=12)
};

#endif

