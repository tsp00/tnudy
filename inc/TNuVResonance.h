// TNuVResonance.h  =====================================================
// Author: Tae-Sun Park   Jan 10 2012

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuVResonance                                                             //
//                                                                           //
// Abstract class to provide a uniform interfaces                            //
// for the classes related to the resonance data                             //
//                                                                           //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef ROOT_TNuVResonance
#define ROOT_TNuVResonance

#include "TNuVF1s.h"
#include "TNuObject.h"

class TNuSec02;
class TGraph;

class TNuVResonance : public TNuVF1s
{
public:
   TNuVResonance();
   virtual ~TNuVResonance() {}

   Double_t GetEL() const { return GetXmin(); }
   Double_t GetEH() const { return GetXmax(); }

   Int_t NComponents() const { return 4; }
   const Char_t* GetSymbolAt(Int_t n) const;

   virtual void  EvalRP(Double_t Ein, Double_t sig[]) const = 0;
   void EvalF1s(Double_t Ein, Double_t sig[]) const {
      EvalRP(Ein, sig);
   }
   Double_t EvalF1At(Int_t n, Double_t Ein, Double_t* ps = 0) const;

   virtual TNuSec02* GetParentSec02() const;
   Bool_t  IsEvaluated() const { return ((size_t) this == fLastEvaluator); }

   enum {kElastic, kCapture, kFission, kTotal};

   void         SetBounds() const;
   virtual void Evaluate() const;
   virtual void PrintSummary() const;         // *MENU*
   void         InitVirtualPart();

   TGraph*      GetGraphOfSigmaOf(Int_t c) const; //
   void         PlotSigmaOf(Int_t c) const;       //
   void         PlotSigmaElastic() const;         // *MENU*
   void         PlotSigmaCapture() const;         // *MENU*
   void         PlotSigmaFission() const;         // *MENU*
   void         PlotSigmaTotal() const;           // *MENU*

   void         PlotSigmaAll() const;             // *MENU*

   Bool_t    HaveResonanceParameters() const;

   Double_t  GetSigMin(Int_t c) const {
      if (!IsEvaluated()) Evaluate();
      return fSigMin[c];
   }
   Double_t  GetSigMax(Int_t c) const {
      if (!IsEvaluated()) Evaluate();
      return fSigMax[c];
   }

   virtual Int_t GetAccuracy() const;// { return GetParentSec02()->GetAccuracy(); }
   virtual void  SetAccuracy(Int_t accuracy);             // *MENU*

   static Int_t  GetDefaultAccuracy() { return fDefaultAccuracy; }
   static void   SetDefaultAccuracy(Int_t accuracy);      // *MENU*

protected:
   mutable Int_t    fNLo;//! GetEL() = fMesh[fNLo]
   mutable Int_t    fNHi;//! GetEH() = fMesh[fNHi]
   mutable Double_t fSigMin[4];//! Min xsect
   mutable Double_t fSigMax[4];//! Max xsect

   mutable size_t   fLastEvaluator; //! which one has Evaluate() most recently ?

   static Int_t     fDefaultAccuracy; // default accuracy
   ClassDef(TNuVResonance, 1) // Abstract class to provide a uniform interfaces for the resonance data
};

#endif
