// TNuDEpDMuETransfer.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuDEpDMuETransfer
#define ROOT_TNuDEpDMuETransfer


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuDEpDMuETransfer :
// Energy transfer during electro-atomic excitation or bremsstrahlung (LAW=8)
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuDEpDMu.h"
#include "TNuVF1.h"

#include "TNuTab1.h"

//class TNuSec03;

class TNuEndfIO;


class TNuDEpDMuETransfer : public TNuDEpDMu, public TNuVF1
{
public:
   TNuDEpDMuETransfer() : TNuDEpDMu(), TNuVF1() {}
   TNuDEpDMuETransfer(TNuEndfIO& src);
   virtual ~TNuDEpDMuETransfer() {}

   Bool_t   IsF1() const { return kTRUE; }
   void     What() const; // *MENU*

   Double_t      EvalF1(Double_t Ein, Double_t *ps=0) const {
      return ((TNuTab1*) BodyFirst())->EvalF1(Ein, ps); }
   Double_t      EvalEnergyTransfer(Double_t Ein) {
      return EvalF1(Ein); }

   const    Char_t* GetXAxisTitle() const { return "E [eV]"; }

   void     Draw(Option_t* option="") { TNuVF1::VirtualDraw(option); }
   void     Paint(Option_t* option=""){ TNuVF1::VirtualPaint(option); }

protected:
   void     SetTransient();

private:

   ClassDef(TNuDEpDMuETransfer, 1)//Energy transfer during electro-atomic excitation or bremsstrahlung
};


#endif
