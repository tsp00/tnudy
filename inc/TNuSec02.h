// TNuSec02.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuSec02
#define ROOT_TNuSec02
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec02 : Resonance parameter data                                     //
//                                                                           //
// [MAT, 2,151/ ZA, AWR, 0, 0, NIS, 0/HEAD                                   //
// (i-th TNuSubIsotope, i=0,NIS-1)                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuRecsWithCont.h"
#include "TNuVResonance.h"

class TNuEndfIO;
class TNuTab1;
class TNuResonance;
class TNuSubIsotope;
//class TArrayD;
#include "TArrayD.h"

class TNuSec02 : public TNuSection, public TNuVResonance
{
   // [MAT, 2,151/ ZA, AWR, 0, 0, NIS, 0/HEAD
   // (i-th TNuSubIsotope, i=0,NIS-1)
public:
   TNuSec02();
   TNuSec02(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec02();

   Int_t    GetNIS() const { return GetN1(); }

   void     ImportEndfData(TNuEndfIO& src);

   TNuSubIsotope* BodyAt(Int_t n) const { return (TNuSubIsotope*) this->TNuSection::BodyAt(n); }

   Bool_t    IsMeshed() const { return fIsMeshed; }
   void      GenMesh();

   void      EvalRP(Double_t Ein, Double_t sig[]) const;
   TArrayD&  GetMesh();
   TArrayD*  GetSig() { return fSig; }

   TNuSec02* GetParentSec02() const { return (TNuSec02*) this; }
   Int_t       GetAccuracy() const { return fAccuracy; }
   void        SetAccuracy(Int_t accuracy);             // *MENU*

   //Int_t     GetLRP() const { return GetParentMat()->GetLRP(); }

private:
   TArrayD  fMesh;//! the meshes for Ein
   TArrayD  fSig[4]; //! for the sig[elastic, cap, fission, total
   Bool_t   fIsMeshed;  //! if the mesh has been generated

   Int_t    fAccuracy; //! target accuracy for evaluation

   void     SetTransient();
   ClassDef(TNuSec02, 1) // Resonance data section, MF=2, MT=151
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSubIsotope : public TNuRecsWithCont                                    //
//                                                                           //
//   = Resonance parameters for an isotope                                   //
//                                                                           //
// [MAT, 2,151/ ZAI, ABN, 0, LFW, NER, 0]CONT (isotope)                      //
// (n-th TNuResonance, n=0, NER-1)                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class TNuSubIsotope : public TNuRecsWithCont, public TNuVResonance
{
   // [MAT, 2,151/ ZAI, ABN, 0, LFW, NER, 0]CONT (isotope)
   // (n-th TNuSubRange, n=0, NER-1)
public:
   TNuSubIsotope() : TNuRecsWithCont(), TNuVResonance() {}
   virtual ~TNuSubIsotope() {}

   Double_t GetZAI() const { return GetC1(); }
   Double_t GetABN() const { return GetC2(); }
   Int_t    GetLFW() const { return GetL2(); }
   Int_t    GetNER() const { return GetN1(); }
   Int_t    GetEffectiveNER() const;

   TNuSec02*   GetParentSec02() const { return (TNuSec02*) GetParent(); }
   TNuResonance* BodyAt(Int_t n) const { return (TNuResonance*) TNuRecsWithCont::BodyAt(n); }

   void     EvalRP(Double_t Ein, Double_t sig[]) const;
   Int_t    GenerateMeshPoints(TArrayD& mesh) const;

private:
   void     SetTransient();
   ClassDef(TNuSubIsotope, 1) // Resonance parameters for an isotope
};

#endif

