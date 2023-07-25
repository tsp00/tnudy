// TNuList2.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuList2
#define ROOT_TNuList2

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuList2                                                                  //
//                                                                           //
//  --- TAB2 of LISTs but represented by a single LIST                       //
//                                                                           //
//   0.0, En, ND, NA, NW, NEP/                                               //
//   E_0',   b_0(En, E_0'),   b_1(En, E_0'),   ... , b_NA(En, E_0')          //
//   E_1',   b_0(En, E_1'),   b_1(En, E_1'),   ... , b_NA(En, E_1')          //
//   E_2',   b_0(En, E_2'),   b_1(En, E_2'),   ... , b_NA(En, E_2')          //
//    ...                                                                    //
//   E_M',   b_0(En, E_M'),   b_1(En, E_M'),   ... , b_NA(En, E_M')          //
//                                                                           //
//  where M= NEP-1.                                                          //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuList.h"
#include "TNuVTab.h"
#include "TNuVF2.h"

#include "TNuTab3.h"


class TNuEndfIO;
class TNuDEpDMu;

class TNuList2 : public TNuList, public TNuVF2, public TNuVTab
{
public:
   TNuList2() : TNuList() {}
   TNuList2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuList2(TNuEndfIO &src, const Char_t* label=" 0.0, E, ND, NA, NW, NEP");
   TNuList2(const TNuList2 &list2);
   TNuList2& operator=(const TNuList2 &rhs);
   virtual ~TNuList2();

   void          What() const; // *MENU*
   const         Char_t* GetEndfName() const { return "LIST"; }

   Double_t      GetEin() const { return fC2; }
   Int_t         GetND() const { return fL1; } // number of discrete levels
   Int_t         GetNA() const { return fL2; }
   Int_t         GetNW() const { return fN1; } // = NEP * (NA+2)
   Int_t         GetNEP() const { return fN2; }
   Double_t      GetEAt(Int_t n) const {
      return n>=0 && n < GetNEP() ? At(n*(GetNA()+2)) : 0;
   }
   Double_t      GetDataAt(Int_t i, Int_t j) const {
      return (i >= 0 && i < GetNEP() && j >= 0 && j <= GetNA()) ? At(i*(GetNA()+2) + j) : 0;
   }

   Double_t*     GetDataArrayAt(Int_t i) const {
      return i>=0 && i < GetNEP() ? &fData[i*(GetNA()+2)+1] : 0;
   }

   Bool_t             IsF2() const { return kTRUE; }
   Double_t           EvalF2(Double_t x, Double_t y, Double_t *ps = 0) const;
   void               DrawTF2() { Draw("surf"); } // *MENU*

   Bool_t             IsAscending() const{ return GetX(GetNEP()-1) >= GetX(0); }

   // //Int_t              GetLANG() const { return fLANG; }
   // //Int_t              GetLEP() const { return fLEP; }

   //Int_t              GetLANG() const { return ((TNuTab3*) GetParent())->GetL1(); }
   //Int_t              GetLEP() const { return ((TNuTab3*) GetParent())->GetL2(); }

   //void               SetLANG(Int_t lang) { fLANG = lang; }
   //void               SetLEP(Int_t lep)   { fLEP  = lep; }

   TNuTab3*           GetParentTab3() const { return (TNuTab3*) GetParent(); }

   Int_t              GetLANG() const { return GetParentTab3()->GetL1(); }
   Int_t              GetLEP() const  { return GetParentTab3()->GetL2(); }

   TNuDEpDMu*         GetParentDEpDMu() const { return (TNuDEpDMu*) GetParentTab3()->GetParent(); }

   Int_t              GetInterpolationLaw(Int_t /*pos*/) const { return GetLEP(); }

   Double_t           GetX(Int_t n) const { return GetEAt(n); }
   virtual Double_t   EvalAt(Int_t n, Double_t y, Double_t* ps = 0) const = 0;

protected:
   //Short_t            fLANG; // Indicator which selects the angular representation to be used
   //Short_t            fLEP;  // Interpolation scheme for secondary energy
   void               SetTransient();

   ClassDef(TNuList2, 0) // TAB2 of LISTs but represented by a single LIST
};

#endif
