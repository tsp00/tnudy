// TNuResonance.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

/////////////////////////////////////////////////////////////////////////////
//
// TNuResonance : public TNuRecsWithCont
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

#ifndef ROOT_TNuResonance
#define ROOT_TNuResonance

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

class TNuResonance : public TNuRecs, public TNuVResonance
{
public:
   TNuResonance() : TNuRecs(), TNuVResonance() {}
   virtual ~TNuResonance() {}

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

   void          SetAPE(TNuTab1* tab1) { AddToHead(tab1); }

   TNuTab1*      GetAPE() const;
   Double_t      GetAPE(Double_t Ein) const;

   void          SetSpinCont(TNuCont* cont) { AddToHead(cont); }
   void          SetSpinCont(TNuRecsWithCont* cont) { AddToHead((TNuRecs*)cont); }

   //TNuCont*      SpinCont() const { return (TNuCont*) HeadLast(); }
   TNuCont*      SpinCont() const { return HeadLast()->HeadCont(); }
   Double_t      GetSPI() const { return SpinCont()->GetC1(); }
   Double_t      GetAP() const { return  SpinCont()->GetC2(); }
   virtual Int_t GetNLS() const { return SpinCont()->GetN1(); }

   Double_t      GetAWRI() const { return BodyAt(0)->HeadCont()->GetC1(); }

   virtual void  ImportEndfData(TNuEndfIO& src);

   virtual void  EvalRP(Double_t Ein, Double_t sig[]) const;

   void          HardsphereFactors(Int_t L, Double_t k, Double_t Ein, Double_t *p, Double_t *s) const;

   Double_t      GetRadius(Double_t Ein) const;  //  scattering radius for shift and penetration factors

   Double_t      Getpcm(Double_t Ein) const;
   Double_t      GetHardspherePhaseShift(Int_t L, Double_t Ein, Double_t p) const;

   TNuSec02*   GetSec02() const { return (TNuSec02*) GetParentSection(); }

   virtual Int_t GenerateMeshPoints(TArrayD& mesh) const;

   enum {kElastic, kCapture, kFission, kTotal};

protected:
   //TNuCont*     fRange; //    EL,  EH, LRU, LRF, NRO, NAPS /CONT (range)
   //TNuTab1*     fAPE;   //    0.0, 0.0,   0,   0,  NR,   NP/AP(E) if NRO > 0
   //TNuCont*     fSpinCont; // SPI, AP, 0, 0, NLS, 0 / CONT

   void           SetTransient();
   ClassDef(TNuResonance, 1) //A specific representation of resonance parameters
};


//---- inlines -----------------------------------------------------------------

//______________________________________________________________________________
inline TNuTab1* TNuResonance::GetAPE() const
{
   // Returns the AP(E) Tab1 if NRO != 0

   if (GetNRO() != 0) return (TNuTab1*) HeadAt(1);
   else return 0;
}

#endif
