// TNuSec01.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec01
#define ROOT_TNuSec01

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSec01                                                           //
//                                                                    //
// Neutron Yields                                                     //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF1.h"
//#include "TNuEndfIO.h"
class TNuEndfIO;

class TNuSec01 : public TNuSection, public TNuVF1
{
public:
   TNuSec01() : TNuSection(), TNuVF1() {}
   TNuSec01(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec01();

   const Char_t* GetSymbol() const {
      if (fMT==452) return "#bar{#nu}";
      else if (fMT == 455) return "#bar{#nu}_d";
      else if (fMT == 456) return "#bar{#nu}_p";
      else return "";
   }
   const Char_t* GetXAxisTitle() const { return "E [eV]"; }


   Bool_t   IsF1() const {
      return (fMT==452 || fMT==455 || fMT==456);
   }

   Double_t EvalF1(Double_t Ein, Double_t *ps=0) const;
   void     DrawNeutronYield() { Draw(); } // *MENU*

   Int_t    GetLNU() const { return GetL2(); }
   void     ImportEndfData(TNuEndfIO& src);

protected:
   void     SetTransient();

private:
   ClassDef(TNuSec01, 1) // Neutron yields (MT=452 for total, MT=455 for delayed, MT=456 for prompt)
};


#endif

