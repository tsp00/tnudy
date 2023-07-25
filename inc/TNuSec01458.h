// TNuSec01458.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSec01458
#define ROOT_TNuSec01458

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSec01458                                                         //
//                                                                    //
// Components of energy release due to fission                        //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
//#include "TNuEndfIO.h"
class TNuEndfIO;

class TNuSec01458 : public TNuSection
{
public:
   TNuSec01458() : TNuSection() {}
   TNuSec01458(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec01458();

   const Char_t* GetSymbol() const {
      return "";
   }
   //const Char_t* GetXAxisTitle() const { return "E [eV]"; }


   Bool_t   IsF1() const {
      return kFALSE;
   }
   //Double_t GetXmin() const;
   //Double_t GetXmax() const;
   //Double_t EvalF1(Double_t Ein, Double_t *ps=0);
   //void     DrawNeutronYield() { Draw(); } // *MENU*

   //void     SetTransient(){}

   Int_t    GetLNU() const { return GetL2(); }
   void     ImportEndfData(TNuEndfIO& src);

private:

   ClassDef(TNuSec01458, 1) // Fission energy released
};


#endif

