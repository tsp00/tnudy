// TNuResoUnresolved.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuResoUnresolved
#define ROOT_TNuResoUnresolved

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuResoUnresolved: public TNuResonance                                    //
//                                                                           //
//   = Ubresolved Resonance Parameters (LRU=2)                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuResonance.h"

class TArrayD;

class TNuResoUnresolved : public TNuResonance
{
public:
   TNuResoUnresolved() : TNuResonance() {}
   virtual ~TNuResoUnresolved() {}
   Int_t         GenerateMeshPoints(TArrayD& mesh) const;

   Int_t         GetLSSF() const { return SpinCont()->GetL1(); }
   virtual void  EvalRP(Double_t Ein, Double_t out[]) const = 0;

   Bool_t        IsValid(Double_t Ein) const { return (Ein >= GetEL() && Ein <= GetEH()); } // check if it is in the valid region

protected:

   static void   EvalEachRP(Double_t p, Double_t gJ, Double_t phiL,
      Double_t d, Double_t gX, Double_t gN, Double_t gG, Double_t gF,
      Double_t amuX, Double_t amuN, Double_t amuF,
      Double_t sig[]);

   ClassDef(TNuResoUnresolved, 1) // Ubresolved Resonance Parameters (LRU=2)
};

class TNuResoUnresolvedA : public TNuResoUnresolved
{
   // [MAT, 2,151/SPI, AP, LSSF, 0, NLS, 0]CONT
public:
   TNuResoUnresolvedA() : TNuResoUnresolved() {}
   virtual ~TNuResoUnresolvedA() {}
   void          ImportEndfData(TNuEndfIO& src);
   void          EvalRP(Double_t Ein, Double_t out[]) const;

   ClassDef(TNuResoUnresolvedA, 1) // Ubresolved Resonance Parameters (LRU=2), Case A
};

class TNuResoUnresolvedB : public TNuResoUnresolved
{
   // [MAT, 2,151/ SPI, AP, LSSF, 0, NE, NLS]CONT
public:
   TNuResoUnresolvedB() : TNuResoUnresolved() {}
   virtual ~TNuResoUnresolvedB() {}
   void          ImportEndfData(TNuEndfIO& src);
   void          EvalRP(Double_t Ein, Double_t out[]) const;

   Int_t         GetLSSF() const { return SpinCont()->GetL1(); }
   Int_t         GetNE() const { return SpinCont()->GetN1(); }
   Int_t         GetNLS() const { return SpinCont()->GetN2(); }

   ClassDef(TNuResoUnresolvedB, 1) // Ubresolved Resonance Parameters (LRU=2), Case B
};


class TNuResoUnresolvedC : public TNuResoUnresolved
{
   // [MAT, 2,151/SPI, AP, LSSF, 0, NLS, 0]CONT
public:
   TNuResoUnresolvedC() : TNuResoUnresolved() {}
   virtual ~TNuResoUnresolvedC() {}
   void          ImportEndfData(TNuEndfIO& src);

   void          EvalRP(Double_t Ein, Double_t out[]) const;

   ClassDef(TNuResoUnresolvedC, 1) // Ubresolved Resonance Parameters (LRU=2), Case C
};

#endif
