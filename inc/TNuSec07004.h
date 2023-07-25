// TNuSec07004.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuSec07004
#define ROOT_TNuSec07004

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF3.h"

#include "TNuTab3.h"
#include "TNuEndfIO.h"

class TNuSec07004 : public TNuSection, public TNuVF3
{
public:
   TNuSec07004() : TNuSection(), TNuVF3() {}
   TNuSec07004(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec07004();

   void          What() const; // *MENU*

   TNuTab3* GetTab3() const { return (TNuTab3*) BodyFirst(); }

   const Char_t* GetSymbol() const { return "S(#alpha, #beta, T)"; }

   const         Char_t* GetXAxisTitle() const { return "#alpha"; }
   const         Char_t* GetYAxisTitle() const { return "#beta"; }
   const         Char_t* GetZAxisTitle() const { return "T"; }
   Double_t      EvalF3(Double_t alpha, Double_t beta, Double_t T, Double_t * ps=0) const {
      return GetTab3()->EvalF3(alpha, beta, T, ps);
   }

   void     DrawS() { Draw(); } // *MENU*

   Double_t GetMassDifference() const { return GetQM(); }
   Double_t GetQM() const { return GetTab3()->GetC1(); }
   Double_t GetQValue() const { return GetQI(); }
   Double_t GetQI() const { return GetTab3()->GetC2(); }
   Int_t    GetLR() const { return GetTab3()->GetL2(); }

   void     ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();

   ClassDef(TNuSec07004, 1) // Thermal neutron inelastic scattering data
};

#endif

