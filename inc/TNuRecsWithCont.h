// TNuRecsWithCont.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuRecsWithCont
#define ROOT_TNuRecsWithCont

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuRecsWithCont                                                           //
//                                                                           //
//A subsection of the form                                                   //
//   C1 C2 L1 L2 N1 N2 : CONT (as a member data)                             //
//   TNuRecs (as inheritance)                                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuRecs.h"
#include "TNuCont.h"

/*
This form is heavily used for FILE 2.
In fact, the section of File2 is simply one instance of
TNuRecstionCont, an array of <isotope-subsections>.
And each <isotope-subsection> is also an instance of
TNuRecstion, an array of <range-subsection>.
And a large part of the <range-subsection> is also
written as TNuRecstion, for the sum of L, S, J
and resonances.
*/

class TNuRecsWithCont : public TNuRecs
{
public:
   TNuRecsWithCont() : TNuRecs() {}
   virtual ~TNuRecsWithCont();

   //TNuCont* HeadCont() const           { return (TNuCont*) HeadFirst(); }

   void SetCont(TNuCont *cont);

   TNuCont* GetCont() const { return HeadCont(); }

private:
   //TNuCont* fCont; // the head TNuCont

   ClassDef(TNuRecsWithCont, 1) // Class for the data of the form TNuCont + subsection
};



#endif

