// TNuSec14.h  =====================================================
// Author: Tae-Sun Park   Feb 05 2012

#ifndef ROOT_TNuSec14
#define ROOT_TNuSec14

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec14 --- File 14 : Photon angular distributions
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) :
// ZA, AWR, LI, LTT, NK, NI]HEAD                                //                               //
//
// ------------------ body --------------------------------------------------//
// BodyAt(i) = (i < NI) TNuCont for
// [MAT, 14, MT/ EGk, ESk, 0, 0, 0, 0] CONT
//                                                    //
// BodyAt(k) [k=NI, NK) = TNuTab2                       //
//                                                                           //
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF2.h"

#include "TNuTab2.h"
class TNuEndfIO;

class TNuSec14 : public TNuSection//, public TNuVF2
{
public:
   TNuSec14() : TNuSection()  {}
   TNuSec14(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt) {}

   virtual ~TNuSec14() {}

   void          What() const; // *MENU*

   Int_t         IsIsotropic() const { return GetLI() == 1; }

   Int_t         GetLI() const  { return GetL1(); } //{ return fLI; }
   Int_t         GetLTT() const { return GetL2(); } //{ return fLTT; }
   Int_t         GetNK() const  { return GetN1(); }
   Int_t         GetNI() const { return GetN2(); }

   const Char_t* GetSymbol() const { return "#frac{d #sigma(E)}{d #mu} [barn/radian]"; }
   //Bool_t        IsF2() const { return kTRUE; }
   //void          DrawDXDmuNormalized() { Draw("surf"); } // *MENU*

   // default x-, y-axis labels
   const         Char_t* GetXAxisTitle() const { return "E [eV]"; }
   const         Char_t* GetYAxisTitle() const { return "#mu"; }

   //Double_t      EvalF2(Double_t E, Double_t mu, Double_t *ps=0);
   //Double_t      DXDmuNormalized(Double_t E, Double_t mu) { return EvalF2(E, mu); }

   void          ImportEndfData(TNuEndfIO& src);

   TNuTab2*      GetTab2At(Int_t n) const { return 
      (n>=GetNI() && n<GetNK()) ? (TNuTab2*) BodyAt(n) : 0; }

private:
   void          SetTransient();
   Double_t      fXmin; //! lower bound
   Double_t      fXmid; //! upper bound of fTab2List
   Double_t      fXmax; //! upper bound

   ClassDef(TNuSec14, 1)//Photon angular distributions
};

#endif

