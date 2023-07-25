// TNuSec04.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec04
#define ROOT_TNuSec04
/////////////////////////////////////////////////////////////////////////////
//
// TNuSec04 --- File 4 : Angular distributions
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
// [MAT, 4, MT/  ZA, AWR,  0, LTT, 0, 0]HEAD
// HeadAt(1) :
// [MAT, 4, MT/ 0.0, AWR, LI, LCT, 0, 0]CONT
//
// ------------------ body --------------------------------------------------
// At(0) :
// [MAT, 4, MT/ TNuTab2
// At(1) :
// [MAT, 4, MT/ (optional) TNuTab2 (for high-E data)
//
//
// ------------------ notes -------------------------------------------------
//
// At(0) is Tab2 of ListLegendre if LTT =1 or 3,
//      and Tab2 of Tab1 if LTT = 2.
// At(1) is, if any, Tab2 of Tab1.
//
/////////////////////////////////////////////////////////////////////////////


#include "TNuSection.h"
#include "TNuVF2.h"

#include "TNuTab2.h"
class TNuEndfIO;

class TNuSec04 : public TNuSection, public TNuVF2
{
public:
   TNuSec04() : TNuSection(), TNuVF2()  {}
   TNuSec04(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), TNuVF2() {}

   virtual ~TNuSec04() {}

   void          What() const; // *MENU*

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

   Double_t      EvalF2(Double_t E, Double_t mu, Double_t *ps=0) const;
   Double_t      DXDmuNormalized(Double_t E, Double_t mu) const { return EvalF2(E, mu); }

   void          ImportEndfData(TNuEndfIO& src);

   TNuTab2*      GetTab2List() const { return fTab2List; }
   TNuTab2*      GetTab2Tab1() const { return fTab2Tab1; }

protected:
   void          SetTransient();

private:
   // These transient members should be set at creation by Init()
   //void          Init(); // set transient members
   //Int_t fLTT; //! Representation flat, 0(isotropic), 1(Legendre), 2(tabulated), 3(low-Legenrem high-tabulated)
   //Int_t fLI;  //! 0(not all isotropic), 1(all isotropic)
   //Int_t fLCT;  //! 1(LAB), 2(CM)
   TNuTab2*      fTab2List; //! Tab2 of ListLegendre
   TNuTab2*      fTab2Tab1; //! Tab2 of Tab1
   Double32_t    fXmid;  // upper bound of fTab2List

   ClassDef(TNuSec04, 1) // Angular distributions
};

#endif

