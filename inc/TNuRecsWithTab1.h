// TNuRecsWithTab1.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuRecsWithTab1
#define ROOT_TNuRecsWithTab1

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuRecsWithTab1                                                           //
//                                                                           //
// sub-structure of the form                                                 //
//    Tab1 for (E, y(E))                                                     //
//    < one or more records>                                                 //
//                                                                           //
// The Tab1, y(E), serves as yield or multiplicity or probability.           //
// This form heavilly appears in File 5 & 6.                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuRecs.h"
#include "TNuTab1.h"

class TNuRecsWithTab1 : public TNuRecs
{
public:
   TNuRecsWithTab1() : TNuRecs() {}
   virtual ~TNuRecsWithTab1();

   void     What() const; // *MENU*

   TNuTab1* GetHead() const           { return GetTab1(); }
   TNuTab1* GetTab1() const           { return (TNuTab1*) HeadFirst(); }

   void     SetTab1(TNuTab1 *tab1);

   Double_t GetRangeMin() const { return GetTab1()->GetXmin(); }
   Double_t GetRangeMax() const { return GetTab1()->GetXmax(); }

   Double_t Tab1Eval(Double_t Ein) const   { return GetTab1()->Eval(Ein); }
   Double_t Yield(Double_t Ein) const      { return Tab1Eval(Ein); }
   Double_t Probability(Double_t Ein) const { return Tab1Eval(Ein); }

private:
   //TNuTab1* fTab1;

   ClassDef(TNuRecsWithTab1, 1) //  Class for Tab1 for (E, y(E)) + sub-structure
};
#endif
