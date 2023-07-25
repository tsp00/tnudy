// TNuTab1ListsSub.h  =====================================================
// Author: Tae-Sun Park  Jan 16 2012

#ifndef ROOT_TNuTab1ListsSub
#define ROOT_TNuTab1ListsSub

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  TNuTab1ListsSub
//
//   -- the LIST that appears as a data element of TNuTab1Lists
//
//  It is a 1D functor that contains only y-points, y(0), y(1), ..., y(np-1),
//  where x-mesh and other informations for the interpolation is embodied
//  in the GetTab1() of the parent TNuTab1Lists.
//
//  Its ENDF format is
//
//  [T_n, C2, LI, L2, NR, NP/S(E; T_n)] LIST
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuList1.h"
#include "TNuVTab.h"
//#include "TNuVF1.h"

#include "TNuTab1.h"

class TNuEndfIO;
class TNuTab1Lists;

class TNuTab1ListsSub : public TNuList1, public TNuVTab
{
public:
   TNuTab1ListsSub() : TNuList1() {}
   //TNuTab1ListsSub(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuTab1ListsSub(TNuEndfIO &src, const Char_t* label=" T, 0.0, LI, 0, NR, NP");
   //TNuTab1ListsSub(const TNuTab1ListsSub &list2);
   //TNuTab1ListsSub& operator=(const TNuTab1ListsSub &rhs);
   virtual ~TNuTab1ListsSub();

   void          What() const; // *MENU*

   TNuTab1*      GetTab1() const;

   Int_t         GetNR() const { return GetTab1()->GetNR(); }
   Int_t         GetNP() const { return GetTab1()->GetNP(); }

   Bool_t        IsF1() const { return kTRUE; }
   Double_t      EvalF1(Double_t E, Double_t *ps = 0) const;
   void          DrawTF1() { Draw(); } // *MENU*

   Int_t         GetInterpolationLaw(Int_t n) const { return
      GetTab1()->GetInterpolationLaw(n); }

protected:
   void               SetTransient();

   ClassDef(TNuTab1ListsSub, 0) //the LIST that appears as a data element of TNuTab1Lists
};

#endif
