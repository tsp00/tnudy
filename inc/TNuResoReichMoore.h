// TNuResoReichMoore.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuResoReichMoore
#define ROOT_TNuResoReichMoore

#include "TNuResoResolved.h"

class TNuEndfIO;
class TArrayD;

class TNuResoReichMoore : public TNuResoResolved
{
   // [MAT, 2,151/ SPI, AP, LAD, 0, NLS, NLSC]CONT
public:
   TNuResoReichMoore() : TNuResoResolved() {}
   virtual ~TNuResoReichMoore() {}
   Int_t         GetLAD() const { return SpinCont()->GetL1(); }
   Int_t         GetNLSC() const { return SpinCont()->GetN2(); }
   void          ImportEndfData(TNuEndfIO& src);
   void          EvalRP(Double_t Ein, Double_t out[]) const;
   Int_t GenerateMeshPoints(TArrayD& mesh) const;


protected:
   struct ReichMooreStruct {
      Double_t ER;  // Resonance energy (in the laboratory system).
      Double_t AJ;  // The floating-point value of +/- J
      Double_t GN;  // Neutron width Gamma_n evaluated at the resonance energy ER.
      Double_t GG;  // Radiation width, Gamma_gamma, a constant
      Double_t GFA; // 1st partial fission width, Gamma_fA, a constant.
      Double_t GFB; // 1st partial fission width, Gamma_fB, a constant.
   };
   ClassDef(TNuResoReichMoore, 1) // Resonance data in Reich-Moorer (LRF=3) format
};


#endif
