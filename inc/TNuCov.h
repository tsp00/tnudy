// TNuContListNC.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuContListNC
#define ROOT_TNuContListNC

///////////////////////////////////////////////////////////////////////////////
//
// TNuContListNC  - 
//   NC-type subsections may be used to describe the covariance matrices 
//   in energy ranges where the cross sections in (MAT,3,MT) 
//   can be described in terms of other evaluated cross sections 
//   in the same energy range.
//
/*
For LTY = 0 :
[MAT,33,MT/ 0.0, 0.0, 0, LTY=0, 0, 0]CONT 
[MAT,33,MT/ E1, E2, 0, 0, 2*NCI, NCI/{CI, XMTI}]LIST
//
For LTY = 1, 2, 3
MAT,33,MT/ 0.0, 0.0, 0, LTY, 0, 0]CONT 
[MAT,33,MT/ E1, E2, MATS, MTS, 2*NEI+2, NEI/ (XMFS,XLFSS), {EI,WEI} ]LIST
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuContList.h"

class TNuEndfIO;
class TH1D;
class TH2D;
class TNuMat;

class TNuContListNC : public TNuContList
{
public:
   TNuContListNC() : TNuContList() {}
   TNuContListNC(TNuEndfIO &src, const Char_t* label=
      "0.0, 0.0, 0, LTY, 0, 0");
   virtual ~TNuContListNC() {}

   Int_t         GetLTY() const { return GetL2(); }  // flag
   Double_t      GetE1() const { return GetList()->GetC1(); }  //
   Double_t      GetE2() const { return GetList()->GetC2(); }  //
   Int_t         GetMATS() const { return GetList()->GetL1(); }  // MAT_S
   Int_t         GetMTS() const { return GetList()->GetL2(); }  // MT_S
   Int_t         GetNCI() const { return GetList()->GetN2(); }  //
   Int_t         GetNEI() const { return GetList()->GetN2(); }  //

   void          What() const; // *MENU*

   ClassDef(TNuContListNC, 1) // fission product yield data at an energy
};

#endif


// TNuListNI.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuListNI
#define ROOT_TNuListNI

///////////////////////////////////////////////////////////////////////////////
//
// TNuListNI - 
//    NI-type sub-subsections are used to describe explicitly the various
//     components of the covariance matrix given in the subsection.
//
/*
[MAT,33,MT/ 0.0, 0.0, LT,   LB, NT, NP/ {Ek,Fk}{El,Fl}]LIST (for LB = 0,1,2,3,4
[MAT,33,MT/ 0.0, 0.0, LS, LB=5, NT, NER/ {Ek}{Fk,k′}] LIST.
[MAT,33,MT/ 0.0, 0.0, 0,  LB=6, NT, NE/ {Ekl}{Fk,l}]LIST
[MAT,33,MT/ 0.0, 0.0, LT,   LB, NT, NP/ {Ek,Fk}]LIST (LT=0,LB=8 or 9)
*/
//
///////////////////////////////////////////////////////////////////////////////

//#include "TNuSection.h"
//#include "TNuTab1.h"
//#include "TNuEndfIO.h"
#include "TNuList.h"

class TNuEndfIO;
class TH1D;
class TH2D;
class TNuMat;

class TNuListNI : public TNuList
{
public:
   TNuListNI() : TNuList(), fTH2(0) {}
   TNuListNI(TNuEndfIO &src, const Char_t* label=
      "0.0, 0.0, LT, LB, NT, NP");
//      "0.0, 0.0, LT, LB, NT, NP ; ZAFP, FPS, Y, +-");
   virtual ~TNuListNI() {}

   Int_t         GetLT() const { return GetL1(); } // Number of 2nd {El, Fl} pairs
   Int_t         GetLB() const { return GetL2(); } // flag
   Int_t         GetNT() const { return GetN1(); } // 2*NP
   Int_t         GetNP() const { return GetN2(); } // Total number of {Ek, Fk}{El, Fl} 

   Double_t      DirectEvalF2(Double_t Ei, Double_t Ej) const;
   Double_t      EvalF2(Double_t Ei, Double_t Ej) const;

   void          MakeTH2() const;

   void          DrawTH2(Option_t* opt = "lego2"); // *MENU*

   void          What() const; // *MENU*

protected:
   mutable TH2D* fTH2; //!

   ClassDef(TNuListNI, 1) // fission product yield data at an energy
};

#endif


// TNuContListsCov33.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuContListsCov33
#define ROOT_TNuContListsCov33

///////////////////////////////////////////////////////////////////////////////
//
// TNuContListsCov33 - SubSection of Sec33.
//    Each subsection of the section (MAT,33,MT) is used to describe
//     a single covariance matrix. It is the covariance matrix of:
//     - 1st set of energy-dependent cross sections given in section (MAT,3,MT) and
//     - 2nd set of energy-dependent cross sections given in section 
//       (MAT1,MF1,MT1) when MF1=3 or (MAT1,MF1,MT1.LFS1) when MF1=10 
/*
[MAT,MF, MT/ XMF1, XLFS1, MAT1, MT1, NC, NI] CONT
first TNuContListNC
-------------------------------
-------------------------------
NC-th TNuContListNC
first TNuListNI_1
-------------------------------
-------------------------------
NI-th TNuListNI_NI
*/
//
///////////////////////////////////////////////////////////////////////////////

//#include "TNuSection.h"
//#include "TNuTab1.h"
//#include "TNuEndfIO.h"
#include "TNuContLists.h"

class TNuEndfIO;
class TH1D;
class TH2D;
class TNuMat;

class TNuContListsCov33 : public TNuContLists
{
public:
   TNuContListsCov33() : TNuContLists() {}
   TNuContListsCov33(TNuEndfIO &src, const Char_t* label=
      "XMF1, XLFS1, MAT1, MT1, NC, NI");
   virtual ~TNuContListsCov33() {}

   Int_t         GetXMF1() const { return GetC1(); } //
   Int_t         GetXLFS1() const { return GetC2(); } //
   Int_t         GetMF1() const { return (Int_t) GetC1(); } //
   Int_t         GetLFS1() const { return (Int_t) GetC2(); } //
   Int_t         GetMAT1() const { return GetL1(); } //
   Int_t         GetMT1() const { return GetL2(); } //
   Int_t         GetNC() const { return GetN1(); } //
   Int_t         GetNI() const { return GetN2(); } //

   TNuContListNC* GetContListNCAt(Int_t nc) {return (TNuContListNC*) HeadAt(nc); }
   TNuListNI*     GetListNIAt(Int_t ni) {return (TNuListNI*) BodyAt(ni); }

   void          What() const; // *MENU*

   ClassDef(TNuContListsCov33, 1) // fission product yield data at an energy
};

#endif


// TNuCovMatrix.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuCovMatrix
#define ROOT_TNuCovMatrix

///////////////////////////////////////////////////////////////////////////////
//
// TNuCovMatrix - 
//              
//
/*
//[MAT,MF, MT/ QM, QI, IZAP, LFS, 0, NL]CONT
//<TNuContListsCov33 for n = 1>
//...
//<TNuContListsCov33 for n = NL>
*/
//
///////////////////////////////////////////////////////////////////////////////

//#include "TNuSection.h"
//#include "TNuTab1.h"
//#include "TNuEndfIO.h"
#include "TNuList.h"

class TNuEndfIO;
class TH1D;
class TH2D;
class TNuMat;

class TNuCovMatrix : public TNuRecsWithCont
{
public:
   TNuCovMatrix() : TNuRecsWithCont() {}
   TNuCovMatrix(TNuEndfIO &src, const Char_t* label=
      "QM, QI, IZAP, LFS, 0, NL");
   virtual ~TNuCovMatrix() {}

   Double_t      GetQM() const { return GetC1(); }
   Double_t      GetQI() const { return GetC2(); }
   Int_t         GetIZAP() const { return GetL1(); }  //
   Int_t         GetLFS() const { return GetL2(); }  //
   Int_t         GetNL() const { return GetN2(); } //

   TNuContListsCov33* GetSingleCovMatrix(Int_t n) const { return 
      (TNuContListsCov33*) At(n); }
 
   void          What() const; // *MENU*

   ClassDef(TNuCovMatrix, 1) // fission product yield data at an energy
};

#endif



// TNuSec31.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec31
#define ROOT_TNuSec31

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSec31                                                           //
//                                                                    //
// Neutron Yields                                                     //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF1.h"
//#include "TNuEndfIO.h"
class TNuEndfIO;

//class TNuSec31 : public TNuSection, public TNuVF1
class TNuSec31 : public TNuSection
{
public:
   //TNuSec31() : TNuSection(), TNuVF1() {}
   //TNuSec31(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), TNuVF1() {}
   TNuSec31() : TNuSection() {}
   TNuSec31(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt) {}
   virtual ~TNuSec31() {}

   void     ImportEndfData(TNuEndfIO& src);
   void          What() const; // *MENU*
/*
   const Char_t* GetSymbol() const {
      if (fMT==452) return "#bar{#nu}";
      else if (fMT == 455) return "#bar{#nu}_d";
      else if (fMT == 456) return "#bar{#nu}_p";
      else return "";
   }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }


   Bool_t   IsF1() const {
      return (fMT==452 || fMT==455 || fMT==456);
   }

   Double_t EvalF1(Double_t Ein, Double_t *ps=0) const;
   void     DrawNeutronYield() { Draw(); } // *MENU*

   Int_t    GetLNU() const { return GetL2(); }
*/
   ClassDef(TNuSec31, 1) // Neutron yields (MT=452 for total, MT=455 for delayed, MT=456 for prompt)
};


#endif


// TNuSec33.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec33
#define ROOT_TNuSec33

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec33 - reaction cross sections
/* Begin_Latex
#sigma_{c}(E_{n})
End_Latex
where En is the indident energy (in eV) and
c is the channel index given by the MT value.
*/
//
//with
// [MAT, 33, MT/ ZA, AWR, 0,    0,  0, NL] TNuCovMatrix
// [MAT, 33,  0/ 0.0, 0.0,  0,  0,  0,  0] SEND
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF1.h"

#include "TNuTab1.h"
#include "TNuEndfIO.h"

//class TNuSec33 : public TNuSection, public TNuVF1
class TNuSec33 : public TNuSection
{
public:
   //TNuSec33() : TNuSection(), TNuVF1() {}
   //TNuSec33(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), TNuVF1() {}
   TNuSec33() : TNuSection() {}
   TNuSec33(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt) {}
   virtual ~TNuSec33() {}

   void     ImportEndfData(TNuEndfIO& src);
   void          What() const; // *MENU*
/*
   //const Char_t* GetLRDescription() const;

   const Char_t* GetSymbol() const { return "#sigma(E)"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   Bool_t   IsF1() const { return kTRUE; }

   Double_t EvalF1(Double_t Ein, Double_t *ps=0) const {
      return GetTab1()->EvalF1(Ein, ps);
   }
   Double_t XSect(Double_t Ein, Double_t *ps=0) const { return EvalF1(Ein, ps); }
   //void     DrawXSect() { Draw(); } // *MENU*
   //void     DrawXSect() const; // *MENU*
   //void     DrawXSectWithReso() const; // *MENU*
   //TGraph*  GetXSectWithResoGraph() const;
   //TGraph*  GetResoGraph() const;

   //Double_t GetMassDifference() const { return GetQM(); }
   //Double_t GetQM() const { return GetTab1()->GetC1(); }
   //Double_t GetQValue() const { return GetQI(); }
   //Double_t GetQI() const { return GetTab1()->GetC2(); }
   //Int_t    GetLR() const { return GetTab1()->GetL2(); }

   //TNuTab1* GetTab1() const { return (TNuTab1*) BodyFirst(); }
   TNuTab1* GetTab1() const { return fTab1; }
   //void     AddResonance(); // this does not work yet
*/
protected:
   TNuTab1* fTab1; //! TNuTab1 with the resonance contribution added

   ClassDef(TNuSec33, 1) //Reaction cross sections
};

#endif


// TNuContListsCov34.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuContListsCov34
#define ROOT_TNuContListsCov34

///////////////////////////////////////////////////////////////////////////////
//
// TNuContListsCov34 - 
//              
//
//for 
//[MAT,34,MT/ 0.0, 0.0, L , L1, LCT, NI]CONT
//[MAT,34,MT/ 0.0, 0.0, LS_1 , LB_1 , NT_1 , NE_1 / {Data_1 }] LIST
//----------------------------------
//----------------------------------
//[MAT,34,MT/ 0.0, 0.0, LS_NI , LBS_NI , NTS_NI, NE_NI /{Data_NI}] LIST
//
// {Data} is For LB=5, sequence {Ek} {Fk,k};
// for LB=6, sequence {Ek} {Fk,l} (as in File 33)
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuContLists.h"

class TNuEndfIO;
class TH1D;
class TH2D;
class TNuMat;

class TNuContListsCov34 : public TNuContLists
{
public:
   TNuContListsCov34() : TNuContLists() {}
   TNuContListsCov34(TNuEndfIO &src, const Char_t* label=
      "0.0, 0.0, L, L1, LCT, NI");
   virtual ~TNuContListsCov34() {}

   Int_t         GetL() const { return GetL1(); }  //
   Int_t         GetL1() const { return GetL2(); }  //
   Int_t         GetLCT() const { return GetN1(); }  //
   Int_t         GetNI() const { return GetN2(); } //

   void          What() const; // *MENU*

   ClassDef(TNuContListsCov34, 1) // fission product yield data at an energy
};

#endif


// TNuSubSec34.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuSubSec34
#define ROOT_TNuSubSec34

///////////////////////////////////////////////////////////////////////////////
//
// TNuSubSec34 - 
//              
//
//for 
//[MAT,34,MT/ 0.0, 0.0, MAT1, MT1, NL, NL1]CONT (MAT1=0)
//[0.0, 0.0,   L_1,   L1_1, LCT,   NI_1 ] TNuContListsCov34 
//----------------------------------
//----------------------------------
//[0.0, 0.0, L_NSS, L1_NSS, LCT, NI_NSS ] TNuContListsCov34 
// 
// with NSS = NL * NL1
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

//#include "TNuSection.h"
//#include "TNuTab1.h"
//#include "TNuEndfIO.h"
#include "TNuRecsWithCont.h"

class TNuEndfIO;
class TH1D;
class TH2D;

class TNuSubSec34 : public TNuRecsWithCont
{
public:
   TNuSubSec34() : TNuRecsWithCont() {}
   TNuSubSec34(TNuEndfIO &src);
   //TNuSubSec34(TNuEndfIO &src, const Char_t* label=
   //   "0.0, 0.0, MAT1, MT1, NL, NL1");
   virtual ~TNuSubSec34() {}

   Int_t         GetMAT1() const { return GetL1(); }  //
   Int_t         GetMT1() const { return GetL2(); } //
   Int_t         GetNL() const { return GetN1(); }  //
   Int_t         GetNL1() const { return GetN2(); } //
   Int_t         GetNSS() const { return
      (GetParentSection()->GetMT() == GetMT1()) ? GetNL() * (GetNL()+1)/2 : GetNL() * GetNL1(); }

   void          What() const; // *MENU*

   ClassDef(TNuSubSec34, 1) // fission product yield data at an energy
};

#endif


// TNuSec34.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec34
#define ROOT_TNuSec34
/////////////////////////////////////////////////////////////////////////////
//
// TNuSec34 --- File 34 contains covariances for angular distributions 
// of secondary particles.
// It is assumed that uncertainties will not be required on all quantities in File 4.
//
/* Begin_Latex
f(E_{n}, #mu) = #frac{#sigma_{c}(E_{n})}{d#mu} / #sigma_{c}(E_{n})
with #int_{-1}^{1} f(E_{n}, #mu) d#mu = 1,
End_Latex
where En is the indident energy (in eV), #mu is cos(theta) and
c is the channel index given by the MT value.
*/
//
// ------------------ head --------------------------------------------------
// HeadAt(0) :
//[MAT,34,MT/ ZA, AWR, 0, LTT, 0, NMT1]HEAD
//
// ------------------ body --------------------------------------------------
// At(n) :
// n-th TNuSubSec34
//
/////////////////////////////////////////////////////////////////////////////


#include "TNuSection.h"
#include "TNuVF2.h"

#include "TNuTab2.h"
class TNuEndfIO;

//class TNuSec34 : public TNuSection, public TNuVF2
class TNuSec34 : public TNuSection
{
public:
   //TNuSec34() : TNuSection(), TNuVF2()  {}
   //TNuSec34(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), TNuVF2() {}
   TNuSec34() : TNuSection()  {}
   TNuSec34(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt) {}

   virtual ~TNuSec34() {}

   Int_t         GetNMT1() const { return GetN2(); }
   void          What() const; // *MENU*
   void          ImportEndfData(TNuEndfIO& src);

/*
   Int_t         IsIsotropic() const { return GetLI() == 1; }
   const Char_t* ReferenceFram() const { return GetLCT()==1 ? "LAB" : (GetLCT()==2 ? "CM" : "Unknown"); } // ??? ???
   Bool_t        IsLabFrame() const { return GetLCT()==1; }
   Bool_t        IsCMFrame() const { return GetLCT()==2; }

   Int_t         GetLTT() const { return ((TNuCont*) HeadAt(0))->GetL2(); } //{ return fLTT; }
   Int_t         GetLI() const  { return ((TNuCont*) HeadAt(1))->GetL1(); } //{ return fLI; }
   Int_t         GetLCT() const { return ((TNuCont*) HeadAt(1))->GetL2(); } //{ return fLCT; }

   const Char_t* GetSymbol() const { return "Angular distribution"; }
   Bool_t        IsF2() const { return kTRUE; }
   void          DrawDXDmuNormalized() { Draw("surf"); } // *MENU*

   // default x-, y-axis labels
   const         Char_t* GetXAxisTitle() const { return "E [eV]"; }
   const         Char_t* GetYAxisTitle() const { return "#mu"; }

   Double_t      EvalF2(Double_t E, Double_t mu, Double_t *ps=0) const { return 0; }
   Double_t      DXDmuNormalized(Double_t E, Double_t mu) const { return EvalF2(E, mu); }


   TNuTab2*      GetTab2List() const { return fTab2List; }
   TNuTab2*      GetTab2Tab1() const { return fTab2Tab1; }
*/

private:
   // These transient members should be set at creation by Init()
   //void          Init(); // set transient members
   //Int_t fLTT; //! Representation flat, 0(isotropic), 1(Legendre), 2(tabulated), 3(low-Legenrem high-tabulated)
   //Int_t fLI;  //! 0(not all isotropic), 1(all isotropic)
   //Int_t fLCT;  //! 1(LAB), 2(CM)
   TNuTab2*      fTab2List; //! Tab2 of ListLegendre
   TNuTab2*      fTab2Tab1; //! Tab2 of Tab1
   Double32_t    fXmid;  // upper bound of fTab2List

   ClassDef(TNuSec34, 1) // Angular distributions
};

#endif

// TNuSec35.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec35
#define ROOT_TNuSec35
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec35 : dXdE = Energy Distributions                          //
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
// [MAT,35,MT/ ZA, AWR, 0, 0, NK, 0] HEAD
//
// ------------------ body --------------------------------------------------//
// At(n) = n-th TNuListNI, n=0, NK-1                                 //
//
//       = [MAT,35,MT/ E1, E2, LS, LB, NT, NE/{E'_k},{F_k,k′}] LIST (LS=1,LB=7)
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF2.h"

#include "TNuRecsWithTab1.h"
#include "TNuTab1.h"
#include "TNuTab2.h"

class TNuEndfIO;

//class TNuSec35 : public TNuSection, public TNuVF2
class TNuSec35 : public TNuSection
{
public:
   //TNuSec35() : TNuSection(), TNuVF2() {}
   //TNuSec35(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), TNuVF2() {}
   TNuSec35() : TNuSection() {}
   TNuSec35(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt) {}
   virtual ~TNuSec35() {}

   void          ImportEndfData(TNuEndfIO& src);
   void          What() const; // *MENU*
   Int_t    GetNK() const { return GetN1(); }

/*
   Bool_t   IsF2() const { return kTRUE; }
   const Char_t* GetSymbol() const { return "Energy distribution"; }

   const    Char_t* GetXAxisTitle() const { return "E [eV]"; }
   const    Char_t* GetYAxisTitle() const { return "E' [eV]"; }

   Double_t DXDENormalized(Double_t Ein, Double_t Eout) const { return EvalF2(Ein, Eout); }
   Double_t EvalF2(Double_t Ein, Double_t Eout, Double_t *ps=0) const { return 0; }
   Int_t    GetNK() const { return GetN1(); }
   void     DrawDXDENormalized() { Draw("surf"); } // *MENU*

*/

   ClassDef(TNuSec35, 1) // Energy Distributions
};

#endif


// TNuSec40.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

#ifndef ROOT_TNuSec40
#define ROOT_TNuSec40

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec40 - Product cross sections
//
// File 40 contains the covariances of neutron activation 
// cross-section information appearing in File 10.
//  This file is based on File 33, which should be consulted for
//  further information, and on File 10.
//
/*
Neutron activation cross sections [such as the (n,p) and (n,2n) cross sections] and cross
sections for a particular state of a radioactive target are given in File 10. These cross
sections are given as a function of energy E, where E is the incident particle or photon
energy (in eV) in the laboratory system. They are given as energy-cross-section pairs. An
interpolation scheme must specify the energy variation of the data for energies between a
given energy point and the next higher energy point.
File 10 is divided into sections, each section containing the data for a particular reaction
type (MT number). The sections are ordered by increasing MT number. Within a section for
a given MT are subsections for different final states (LFS) of the daughter product nucleus.
File 10 is allowed only for evaluations that represent the data for single isotopes.

---------------- head
HeadAt(0) = TNuCont for
[MAT,40,MT/ ZA, AWR, LIS, 0, NS, 0] HEAD

---------------- body (NS elements)
At(n) = TNuCovMatrix for
[MAT,40, MT/ QM, QI, IZAP, LFS, 0, NL] TNuCovMatrix
*/
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuTab1.h"
#include "TNuVF1s.h"
#include "TNuEndfIO.h"

//class TNuSec40 : public TNuSection, TNuVF1s
class TNuSec40 : public TNuSection
{
public:
   //TNuSec40() : TNuSection(), TNuVF1s() {}
   //TNuSec40(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), TNuVF1s() {}
   TNuSec40() : TNuSection() {}
   TNuSec40(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt) {}
   virtual ~TNuSec40() {}

   void          What() const; // *MENU*
   void     ImportEndfData(TNuEndfIO& src);
   Int_t         GetLIS() const {return GetL1(); }
   Int_t         GetNS() const {return GetN1(); }
/*
   //const Char_t* GetLRDescription() const;
   Int_t         NComponents() const { return GetNS(); }


   const Char_t* GetSymbol() const { return "Y(E)"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   //Bool_t   IsF1() const { return kTRUE; }

   //Double_t EvalF1(Double_t Ein, Double_t *ps=0) {
   //   return GetTab1()->EvalF1(Ein, ps);
   //}
   //Double_t XSect(Double_t Ein, Double_t *ps=0) { return EvalF1(Ein, ps); }
   //void     DrawXSect() { Draw(); } // *MENU*

   Double_t GetMassDifferenceAt(Int_t n) const { return GetQMAt(n); }
   Double_t GetQMAt(Int_t n) const { return GetTab1At(n)->GetC1(); }
   //Double_t GetQValueAt(n) const   { return GetTab1At(n)->GetC2(); }
   Double_t GetQIAt(Int_t n) const { return GetTab1At(n)->GetC2(); }
   Int_t    GetIZAPAt(Int_t n) const { return GetTab1At(n)->GetL1(); }
   Int_t    GetLFSAt(Int_t n) const { return GetTab1At(n)->GetL2(); }

   TNuTab1* GetTab1At(Int_t n) const { return (TNuTab1*) BodyAt(n); }
   Double_t EvalF1At(Int_t n, Double_t En, Double_t* ps=0) const { return GetTab1At(n)->EvalF1(En, ps); }
*/

   ClassDef(TNuSec40, 1)  // Product cross sections
};

#endif

// TNuSec32.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuSec32
#define ROOT_TNuSec32
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec32 : Resonance parameter data                                     //
//                                                                           //
// [MAT, 2,151/ ZA, AWR, 0, 0, NIS, 0/HEAD                                   //
// (i-th TNuSubIsotopeCov, i=0,NIS-1)                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuRecsWithCont.h"
#include "TNuVResonance.h"

class TNuEndfIO;
class TNuTab1;
class TNuResonanceCov;
class TNuSubIsotopeCov;
//class TArrayD;
#include "TArrayD.h"

//class TNuSec32 : public TNuSection, public TNuVResonance
class TNuSec32 : public TNuSection
{
   // [MAT, 2,151/ ZA, AWR, 0, 0, NIS, 0/HEAD
   // (i-th TNuSubIsotopeCov, i=0,NIS-1)
public:
   TNuSec32() : TNuSection() {}
   TNuSec32(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec32() {}

   Int_t    GetNIS() const { return GetN1(); }

   void     ImportEndfData(TNuEndfIO& src);

   TNuSubIsotopeCov* BodyAt(Int_t n) const { return (TNuSubIsotopeCov*) this->TNuSection::BodyAt(n); }

   //Bool_t    IsMeshed() const { return fIsMeshed; }
   //void      GenMesh();

   //void      EvalRP(Double_t Ein, Double_t sig[]) const;
   //TArrayD&  GetMesh();
   //TArrayD*  GetSig() { return fSig; }

   //TNuSec32* GetParentSec02() const { return (TNuSec32*) this; }
   //Int_t       GetAccuracy() const { return fAccuracy; }
   //void        SetAccuracy(Int_t accuracy);             // *MENU*

   //Int_t     GetLRP() const { return GetParentMat()->GetLRP(); }

private:
   //TArrayD  fMesh;//! the meshes for Ein
   //TArrayD  fSig[4]; //! for the sig[elastic, cap, fission, total
   //Bool_t   fIsMeshed;  //! if the mesh has been generated

   //Int_t    fAccuracy; //! target accuracy for evaluation

   ClassDef(TNuSec32, 1) // Resonance data section, MF=2, MT=151
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSubIsotopeCov : public TNuRecsWithCont                                    //
//                                                                           //
//   = Resonance parameters for an isotope                                   //
//                                                                           //
// [MAT, 2,151/ ZAI, ABN, 0, LFW, NER, 0]CONT (isotope)                      //
// (n-th TNuResonanceCov, n=0, NER-1)                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

//class TNuSubIsotopeCov : public TNuRecsWithCont, public TNuVResonance
class TNuSubIsotopeCov : public TNuRecsWithCont
{
   // [MAT, 2,151/ ZAI, ABN, 0, LFW, NER, 0]CONT (isotope)
   // (n-th TNuSubRange, n=0, NER-1)
public:
   //TNuSubIsotopeCov() : TNuRecsWithCont(), TNuVResonance() {}
   TNuSubIsotopeCov() : TNuRecsWithCont() {}
   virtual ~TNuSubIsotopeCov() {}

   Double_t GetZAI() const { return GetC1(); }
   Double_t GetABN() const { return GetC2(); }
   Int_t    GetLFW() const { return GetL2(); }
   Int_t    GetNER() const { return GetN1(); }
   //Int_t    GetEffectiveNER() const;

   //TNuSec32*   GetParentSec02() const { return (TNuSec32*) GetParent(); }
   TNuResonanceCov* BodyAt(Int_t n) const { return (TNuResonanceCov*) TNuRecsWithCont::BodyAt(n); }

   //void     EvalRP(Double_t Ein, Double_t sig[]) const;
   //Int_t    GenerateMeshPoints(TArrayD& mesh) const;

   ClassDef(TNuSubIsotopeCov, 1) // Resonance parameters for an isotope
};

#endif

// TNuResonanceCov.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

/////////////////////////////////////////////////////////////////////////////
//
// TNuResonanceCov : public TNuRecsWithCont
//
//   = A specific representation of resonance parameters
//
// ------------------ head --------------------------------------------------
//
// HeadAt(0) = RangeCont() =
// [MAT, 2,151/  EL,  EH, LRU, LRF, NRO, NAPS]CONT (range)
//
// HeadAt(1) = GetAPE() =
// [MAT, 2,151/ 0.0, 0.0,   0,   0,  NR,   NP/AP(E) if NRO > 0
//
// HeadAt(2) = SpinCont() =
// [MAT, 2,151/ SPI, AP, 0, 0, NLS, 0]CONT
//
// ------------------ body --------------------------------------------------
//
// At(n) : n-th subsection (for a given L or J) of the resonance data
//
// ------------------ notes -------------------------------------------------
//
//
/////////////////////////////////////////////////////////////////////////////

#ifndef ROOT_TNuResonanceCov
#define ROOT_TNuResonanceCov

//#include "TNuSection.h"
#include "TNuRecs.h"
#include "TNuVResonance.h"

#include "TNuCont.h"
#include "TNuTab1.h"

class TNuSec02;
class TNuSubIsotope;
class TNuRecsWithCont;

class TNuEndfIO;

class TArrayD;

//class TNuResonanceCov : public TNuRecs, public TNuVResonance
class TNuResonanceCov : public TNuRecs
{
public:
   //TNuResonanceCov() : TNuRecs(), TNuVResonance() {}
   TNuResonanceCov() : TNuRecs() {}
   virtual ~TNuResonanceCov() {}

   void What() const;// *MENU*
   void ls(Option_t* option) const;// *MENU*

   TNuCont*      RangeCont() const { return (TNuCont*) HeadCont(); }
   void          SetRangeCont(TNuCont* range) { SetHead(range); }

   //TNuCont*      GetRange() const { return fRange; }
   //Double_t      GetEL()   const { return RangeCont()->GetC1(); }
   //Double_t      GetEH()   const { return RangeCont()->GetC2(); }
   Int_t         GetLRU()  const { return RangeCont()->GetL1(); }
   Int_t         GetLRF()  const { return RangeCont()->GetL2(); }
   Int_t         GetNRO()  const { return RangeCont()->GetN1(); }
   Int_t         GetNAPS() const { return RangeCont()->GetN1(); }

   Bool_t        IsResolved() const { return GetLRU() == 1; }
   Bool_t        IsUnresolved() const { return GetLRU() == 2; }

   //void          SetAPE(TNuTab1* tab1) { AddToHead(tab1); }
   void          SetAPECov(TNuObject* c) { AddToHead(c); }

   //TNuTab1*      GetAPE() const;
   //Double_t      GetAPE(Double_t Ein) const;

   void          SetSpinCont(TNuCont* cont) { AddToHead(cont); }
   void          SetSpinCont(TNuRecsWithCont* cont) { AddToHead((TNuRecs*)cont); }

   //TNuCont*      SpinCont() const { return (TNuCont*) HeadLast(); }
   TNuCont*      SpinCont() const { return HeadLast()->HeadCont(); }
   Double_t      GetSPI() const { return SpinCont()->GetC1(); }
   Double_t      GetAP() const { return  SpinCont()->GetC2(); }
   virtual Int_t GetNLS() const { return SpinCont()->GetN1(); }

   Double_t      GetAWRI() const { return BodyAt(0)->HeadCont()->GetC1(); }

   virtual void  ImportEndfData(TNuEndfIO& src, TNuCont* range);

   //virtual void  EvalRP(Double_t Ein, Double_t sig[]) const {}

   //void          HardsphereFactors(Int_t L, Double_t k, Double_t Ein, Double_t *p, Double_t *s) const;

   //Double_t      GetRadius(Double_t Ein) const;  //  scattering radius for shift and penetration factors

   //Double_t      Getpcm(Double_t Ein) const;
   //Double_t      GetHardspherePhaseShift(Int_t L, Double_t Ein, Double_t p) const;

   //TNuSec02*   GetSec02() const { return (TNuSec02*) GetParentSection(); }

   //virtual Int_t GenerateMeshPoints(TArrayD& mesh) const;

   //enum {kElastic, kCapture, kFission, kTotal};

protected:
   //TNuCont*     fRange; //    EL,  EH, LRU, LRF, NRO, NAPS /CONT (range)
   //TNuTab1*     fAPE;   //    0.0, 0.0,   0,   0,  NR,   NP/AP(E) if NRO > 0
   //TNuCont*     fSpinCont; // SPI, AP, 0, 0, NLS, 0 / CONT

   ClassDef(TNuResonanceCov, 1) //A specific representation of resonance parameters
};


//---- inlines -----------------------------------------------------------------
/*
//______________________________________________________________________________
inline TNuTab1* TNuResonanceCov::GetAPE() const
{
   // Returns the AP(E) Tab1 if NRO != 0

   if (GetNRO() != 0) return (TNuTab1*) HeadAt(1);
   else return 0;
}
*/

#endif
