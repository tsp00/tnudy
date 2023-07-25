// TNuList2.cxx  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

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
// It is assumed to have the following lineage relation:                     //
// ... ...                                                                   //
// TNuSec06                                                                //
// TNuDEpDMuContinuum: public TNuDEpDMu                                      //
// TNuTab3                                                                   //
// TNuList2                                                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuList2.h"
#include "TNuEndfIO.h"

#include "TNuTab3.h"
//#include "TNuSec06.h"
#include "TNuDEpDMu.h"

#include <iostream>
#include <iomanip>

ClassImp(TNuList2)

//______________________________________________________________________________
TNuList2::TNuList2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuList(c1,c2,l1,l2,n1,n2)//, fLANG(0), fLEP(0)
{
   // TNuList2 ctor
}

//______________________________________________________________________________
TNuList2::TNuList2(TNuEndfIO &src, const Char_t* label)
  : TNuList(src, label)//, fLANG(0), fLEP(0)
{
   // ctor of TNuList2 importing ENDF data
}

//______________________________________________________________________________
TNuList2::TNuList2(const TNuList2 &list2) : TNuList(list2)
{
   // TNuList2 copy ctor
   //fLANG = list2.fLANG;
   //fLEP  = list2.fLEP;
   //Info("XYZ_copy", "list.fLANG=%d, fLANG=%d", list2.fLANG, GetLANG());
}


//______________________________________________________________________________
TNuList2& TNuList2::operator=(const TNuList2 &rhs)
{
   // TNuList2 assignment operator

   if (this != &rhs) {
      TNuList::operator=(rhs);
      //fLANG = rhs.fLANG;
      //fLEP  = rhs.fLEP;
      //Info("XYZ_assign", "rhs.fLANG=%d, fLANG=%d", rhs.fLANG, GetLANG());
   }
   return *this;
}

//______________________________________________________________________________
TNuList2::~TNuList2()
{
   // TNuList2 dtor
}

//______________________________________________________________________________
void TNuList2::What() const
{
using namespace std;
   TNuList::What();

   //cout << "  old-LANG = " << (Int_t) fLANG << " : Indicator which selects the angular representation to be used" << endl;
   //cout << "   old-LEP = " << (Int_t) fLEP  << " : LEP Interpolation scheme for secondary energy" << endl;


   cout << "  LANG = " << (Int_t) GetLANG() << " : Indicator which selects the angular representation to be used" << endl;
   cout << "   LEP = " << (Int_t) GetLEP()  << " : LEP Interpolation scheme for secondary energy" << endl;

   cout << "  E_in = " << GetEin() << " : Incident energy [eV]" << endl;
   cout << "   ND  = " << GetND() << " : Number of discrete energies given" << endl;
   cout << "   NA  = " << GetNA() << " : Number of angular parameters" << endl;
   cout << "   NW  = " << GetNW() << " : Total number of words in the LIST record; NW = NEP (NA+2)" << endl;
   cout << "   NEP = " << GetNEP() << " : Number of secondary energy points in the distribution" << endl;
}

//______________________________________________________________________________
void TNuList2::SetTransient()
{
   // Sets the range
   //fXmin =  GetEAt(GetND());
   fXmin =  GetEAt(0);
   fXmax =  GetEAt(GetNEP()-1);
   if (!IsAscending()) {
      Double_t tmp= fXmin;
      fXmin= fXmax;
      fXmax= tmp;
   }
   fYmin = -1;
   fYmax = +1;
}

//______________________________________________________________________________
Double_t TNuList2::EvalF2(Double_t x, Double_t y, Double_t *ps) const
{
   // Evaluate Tab2 (a 2-dim functor)

   if (x < GetXmin() || x > GetXmax()) return 0;

   Int_t n = BinarySearch(x, GetNEP(), IsAscending());

   // find the interpolatio law
   Int_t interp= GetInterpolationLaw(n);

   // now do the interpolation
   Double_t xys[4];

   xys[0] = GetX(n);
   xys[1] = EvalAt(n, y, ps);

   xys[2] = GetX(n+1);
   xys[3] = EvalAt(n+1, y, ps);

   if (interp == 6) {
      Double_t qValue = HeadCont()->GetC2(); // QI = C2.
      return InterpolationLaw6(x, xys, qValue);

   } else
      return Interpolation(interp, x, xys);
}
