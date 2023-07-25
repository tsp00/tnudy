//  TNuVTab.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuVTab
#define ROOT_TNuVTab

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuVTab                                                                   //
//                                                                           //
// Abstract class for handling tabulated data of ENDF                        //
//                                                                           //
// Derived class should override                                             //
//                                                                           //
//   DoubLe_t GetX(Int_t n) const;                                           //
//   Int_t    GetInterpolationLaw(Int_t pos);                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuCont.h"

class TNuEndfIO;

class TNuVTab
{
public:
   //TNuVTab() {}
   virtual ~TNuVTab() {}

   static Double_t  Interpolation(Int_t interp, Double_t x, Double_t *xys);
   static Double_t  InterpolationXY(Int_t interp, Double_t x, Double_t *xys, Int_t size);
   static Double_t  InterpolationLaw6(Double_t x, Double_t *xys, Double_t qValue);

   Int_t             BinarySearch(Double_t x, Int_t size) const;
   Int_t             BinarySearch(Double_t x, Int_t size, Bool_t isAscending) const;

   // derived classes should provide following methods
   //
   //virtual Double_t GetX(Int_t at) const = 0;
   //virtual Int_t    GetInterpolationLaw(Int_t pos) const = 0;
   //
   // Declaring the above methods as pure virtual functions causes problems, why ?
   //
   virtual Double_t GetX(Int_t /*at*/) const { return 0; }
   virtual Int_t    GetInterpolationLaw(Int_t /*pos*/) const { return 0; }

protected:
   TNuVTab() {}

   ClassDef(TNuVTab, 0) // Abstract class for handling tabulated ENDF data
};

#endif
