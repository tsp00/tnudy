// TNuSec03.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec03
#define ROOT_TNuSec03

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec03 - reaction cross sections
/* Begin_Latex
#sigma_{c}(E_{n})
End_Latex
where En is the indident energy (in eV) and
c is the channel index given by the MT value.
*/
//
// = [MAT, 3, MT/  ZA, AWR,  0,  0,  0,  0] HEAD
//   [MAT, 3, MT/  QM,  QI,  0, LR, NR, NP/ Eint/ sigma(E)]TAB1
//   [MAT, 3,  0/ 0.0, 0.0,  0,  0,  0,  0] SEND
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF1.h"

#include "TNuTab1.h"
#include "TNuEndfIO.h"

class TNuSec03 : public TNuSection, public TNuVF1
{
public:
   TNuSec03() : TNuSection(), TNuVF1() {}
   TNuSec03(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec03();

   void          What() const; // *MENU*
   const Char_t* GetLRDescription() const;

   const Char_t* GetSymbol() const { return "#sigma(E)"; }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   Bool_t   IsF1() const { return kTRUE; }

   Double_t EvalF1(Double_t Ein, Double_t *ps=0) const {
      return GetTab1()->EvalF1(Ein, ps);
   }
   Double_t XSect(Double_t Ein, Double_t *ps=0) const { return EvalF1(Ein, ps); }
   //void     DrawXSect() { Draw(); } // *MENU*
   void     DrawXSect() const; // *MENU*
   void     DrawXSectWithReso() const; // *MENU*
   TGraph*  GetXSectWithResoGraph() const;
   TGraph*  GetResoGraph() const;

   Double_t GetMassDifference() const { return GetQM(); }
   Double_t GetQM() const { return GetTab1()->GetC1(); }
   Double_t GetQValue() const { return GetQI(); }
   Double_t GetQI() const { return GetTab1()->GetC2(); }
   Int_t    GetLR() const { return GetTab1()->GetL2(); }

   //TNuTab1* GetTab1() const { return (TNuTab1*) BodyFirst(); }
   TNuTab1* GetTab1() const { return fTab1; }
   void     AddResonance(); // this does not work yet
   void     ImportEndfData(TNuEndfIO& src);
protected:
   void     SetTransient();
   void     SetTransient2(); // this does not work
   TNuTab1* fTab1; //! TNuTab1 with the resonance contribution added

   ClassDef(TNuSec03, 1) //Reaction cross sections
};

const struct {
   Int_t LR;
   const Char_t* Description;
} kResidualBreakupTable[] =
{
   {0, "Simple reaction. Identity of product is implicit in MT. Only gamma rays may be emitted additionally"},
   {1, "Complex or breakup reaction. The identity and multiplicity of all products are given explicitly in File 6"},
   {22, "#alpha emitted (plus residual, if any)"},
   {23, "3#alpha emitted (plus residual, if any)"},
   {24, "n#alpha emitted (plus residual, if any)"},
   {25, "2n#alpha emitted (plus residual, if any)"},
   {28, "p emitted (plus residual, if any)"},
   {29, "2#alpha emitted (plus residual, if any)"},
   {30, "n2#alpha emitted (plus residual, if any)"},
   {31, "Residual nucleus decays only by gamma emission"},
   {32, "d emitted (plus residual, if any)"},
   {33, "t emitted (plus residual, if any)"},
   {34, "3He emitted (plus residual, if any)"},
   {35, "d2#alpha emitted (plus residual, if any)"},
   {36, "t2#alpha emitted (plus residual, if any)"},
   {39, "Internal conversion"},
   {40, "Electron-positron pair formation"},
   {-1, ""}
};

#endif

