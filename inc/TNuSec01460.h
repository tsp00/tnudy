// TNuSec01460.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec01460
#define ROOT_TNuSec01460

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSec01460                                                         //
//                                                                    //
// Delayed photon data                                                //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
//#include "TNuEndfIO.h"
class TNuEndfIO;

class TNuSec01460 : public TNuSection
{
public:
   TNuSec01460() : TNuSection() {}
   TNuSec01460(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec01460();

   const Char_t* GetSymbol() const {
      return "";
   }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   Bool_t   IsF1() const { return kFALSE; }

   //Double_t EvalF1(Double_t Ein, Double_t *ps=0);
   //void     DrawNeutronYield() { Draw(); } // *MENU*

   Int_t    GetLNU() const { return GetL2(); }
   void     ImportEndfData(TNuEndfIO& src);

private:

   ClassDef(TNuSec01460, 1) // Delayed photon data
};


#endif

