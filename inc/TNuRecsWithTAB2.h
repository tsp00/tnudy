// TNuRecsWithTAB2.h  =====================================================
// Author: Tae-Sun Park   Aug 16 2011

#ifndef ROOT_TNuRecsWithTAB2
#define ROOT_TNuRecsWithTAB2

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuRecsWithTAB2                                                           //
//                                                                           //
// Array of records with ENDF TAB2 as head                                   //
// =                                                                         //
//  C1 C2 L1 L2 NR NZ                                                        //
//  (NBT(n), INT(n), n=1,NR)                                                 //
//  (<m-th TNuObject>, m=1,NZ)                                               //
//                                                                           //
// TNuTab2 and TNuTab3 belong to this class                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuRecs.h"
#include "TNuVTab.h"
#include "TNuEndfTAB2.h"

class TNuEndfIO;

class TNuRecsWithTAB2 : public TNuRecs, public TNuVTab
{
public:
   TNuRecsWithTAB2() : TNuRecs() {}
   TNuRecsWithTAB2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuRecsWithTAB2(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, NR, NZ");
   virtual ~TNuRecsWithTAB2();

   void               What() const; // *MENU*
   virtual void       ls(Option_t* option="") const; // *MENU*

   TNuEndfTAB2*       GetTAB2() const           { return (TNuEndfTAB2*) HeadFirst(); }
   void               SetTAB2(TNuEndfTAB2* endfTAB2);

   TNuEndfTAB2*       GetHead() const { return (TNuEndfTAB2*) HeadFirst(); }

   Double_t           GetRangeMin() const { return (GetNZ()>0) ? BodyFirst()->HeadCont()->GetC2() : 0; }
   Double_t           GetRangeMax() const { return (GetNZ()>0) ? BodyLast()->HeadCont()->GetC2() : 1; }

   Double_t           GetX(Int_t n) const;//  { return ((TNuCont*) BodyAt(n))->GetC2(); }

   Int_t              GetInterpolationLaw(Int_t pos) const {
      return GetTAB2()->GetInterpolationLaw(pos);
   }

   // copy relevant member ftns of TNuEndfTAB2 here
   //
   Int_t    GetNR() const { return GetTAB2()->GetNR(); }
   Int_t    GetNZ() const { return GetTAB2()->GetNZ(); }

protected:
   //TNuEndfTAB2*       fTAB2; // ENDF TAB2 record

   ClassDef(TNuRecsWithTAB2, 1) // subsection with TAB2
};

#endif
