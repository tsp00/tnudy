// TNuSec26.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuSec26
#define ROOT_TNuSec26


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec26 : Secondary distributions for photo- and electro-atomic data
//                                                                           //
//                                                                           //
// ------------------ head --------------------------------------------------//
// HeadAt(0) :
// [MAT,26, MT/ ZA, 0.0, 0, 0, NK, 0]HEAD                                //
//
// ------------------ body --------------------------------------------------//
// At(n) = n-th TNuDEpDMu, n=0, NK-1                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec06.h"
//#include "TNuVF1.h"
//#include "TNuVF1s.h"
//#include "TNuVF3.h"

//#include "TNuRecsWithTab1.h"
//#include "TNuTab1.h"
//#include "TNuTab2.h"
//#include "TNuTab3.h"
//#include "TNuMat.h"
//#include "TNudy.h"
//#include "TNuList2.h"

//#include "TNuDEpDMu.h"

//class TNuSec03;

class TNuEndfIO;

class TNuSec26 : public TNuSec06
{
public:
   TNuSec26() : TNuSec06() {}
   TNuSec26(Int_t mat, Int_t mf, Int_t mt) : TNuSec06(mat,mf,mt) {}
   virtual ~TNuSec26() {}

   const Char_t* GetSymbol() const { return "Energy-Angle distribution"; }
   //void     DrawYields(); // *MENU*

   const Char_t* GetXAxisTitle() const { return "E [eV]"; }

   Int_t         GetNK() const { return GetN1(); }
   Int_t         NComponents() const { return GetNK(); }
   Double_t      EvalF1At(Int_t n, Double_t En, Double_t* ps) const;
   const Char_t* GetSymbolAt(Int_t n) const;

   void          ImportEndfData(TNuEndfIO& src);

protected:
   void          SetTransient();

private:

   ClassDef(TNuSec26, 1) // Secondary distributions for photo- and electro-atomic data
};

#endif
