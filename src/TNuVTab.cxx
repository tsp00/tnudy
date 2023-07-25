//  TNuVTab.cxx  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

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

#include "TNuVTab.h"
#include "TMath.h"
#include "TNuObject.h"

ClassImp(TNuVTab)

/*
//______________________________________________________________________________
Double_t TNuVTab::Interpolation(Double_t x, Int_t np)
{
   // Interpolate between (x1,y1) and (x2,y2).
   // These points are to be obtained by GetX(n) and GetY(n),
   // and the inperpolation law is to be determined from fINT and fNBT.

   // Bisection routine to find the biggest value of n with the condition
   // x >= GetX(n) and n < NP-1

   if (x < GetX(0) || x > GetX(np-1)) return 0;

   Int_t n = BinarySearch(x, np);

   // find the interpolatio law
   Int_t interp= GetInterpolationLaw(n);


   // now do the interpolation

   Double_t xys[4];

   xys[0] = GetX(n);
   xys[1] = GetY(n);
   xys[2] = GetX(n+1);
   xys[3] = GetY(n+1);

   return Interpolation(interp, x, xys);
}
*/

//______________________________________________________________________________
Double_t TNuVTab::InterpolationXY(Int_t interp, Double_t x, Double_t *xys, Int_t np)
{
   // Interpolate for a given array of the form
   //  x_0, y_0, x_1, y_1, ..., x_{np-1}, y_{np-1}.

   if (x < xys[0] || x > xys[2*np-2]) return 0;

   Int_t n, nabove, nbelow, middle;
   nabove = np+1;
   nbelow = 0;

   while(nabove-nbelow > 1) {
      middle = (nabove+nbelow)/2;
      if (x == xys[2*(middle-1)]) break;
      if (x  < xys[2*(middle-1)]) nabove = middle;
      else                        nbelow = middle;
   }
   n = nbelow-1;

   return Interpolation(interp, x, &xys[2*n]);
}

//______________________________________________________________________________
Double_t TNuVTab::Interpolation(Int_t interp, Double_t x, Double_t *xys)
{
   // Interpolate between (x1, y1) and (x2, y2)

   using namespace TMath;

   Double_t &x1 = xys[0];
   Double_t &y1 = xys[1];
   Double_t &x2 = xys[2];
   Double_t &y2 = xys[3];

   if (x1 == x2) return y1;
   if (y1 == y2) return y1;

   if (interp >= 10) {
      //fprintf(stderr, "Warning in TNuVTab::Interpolation: Interpolation law = %d is rescaled to %d\n",
      //   interp, interp%10);
      interp %= 10;
   }

   Double_t y;
   if (interp == 2)       // linear-linear : y is linear in x
   {
      y = y1 + (y2-y1) * (x-x1) / (x2-x1);
   }
   else if (interp == 1)  // histogram
   {
      y = y1;
   }
   else if (interp == 3)  // linear-log : y is linear in log(x)
   {
      y = y1 + (y2-y1) * Log(x/x1) / Log(x2/x1);
   }
   else if (interp == 4)  // log-linear : log y is linear in x
   {
      if (y1 <= 0) return 0;
      y = y1 * Exp(Log(y2/y1) * (x - x1) / (x2-x1));
   }
   else if (interp == 5)  // log-log : log y is linear in log x
   {
      if (y1 <= 0) return 0;
      y = y1 * Exp(Log(y2/y1) * Log(x/x1) / Log(x2/x1));
   }
   /*
   else if (interp == 6)  // interpolation law for the charged particles
   {
      TNuObject *obj = (TNuObject*) this;
      Double_t qValue = obj->HeadCont()->GetC2(); // QI = C2.
      Double_t threshold = (qValue > 0) ? 0 : qValue;
      if (x1-threshold <=0 || x2-thresold <=0) {
         fprintf(stderr, "x1=%e or x2=%e is smaller than threshold=%e, C2=%e\n", x1,x2,threshold, qValue);
         y=0;
      }
      else {
         Double_t vB = Log(x2*y2/(x1*y1))/(1./Sqrt(x1-threshold) -  1./Sqrt(x2-threshold));
         Double_t vA = Exp(vB/Sqrt(x1-threshold))*x1*y1;
         y = vA/x * Exp(-vB/Sqrt(x-threshold));
      }
   }
   */
   else {
      fprintf(stderr, "Error in TNuVTab::Interpolation: "
         "Unrecognized interpolation law = %d\n",
         interp);
      y = 0;
   }
   return y;
}

//______________________________________________________________________________
Double_t TNuVTab::InterpolationLaw6(Double_t x, Double_t *xys, Double_t qValue)
{
   // Interpolate for the charged particles, interp = 6

   using namespace TMath;

   Double_t &x1 = xys[0];
   Double_t &y1 = xys[1];
   Double_t &x2 = xys[2];
   Double_t &y2 = xys[3];

   if (x1 == x2) return y1;
   if (y1 == y2) return y1;

   Double_t threshold = (qValue > 0) ? 0 : qValue;
   if (x1-threshold <=0 || x2-threshold <=0) {
      fprintf(stderr, "x1=%e or x2=%e is smaller than threshold=%e, C2=%e\n", x1,x2,threshold, qValue);
      return 0;
   }
   else {
      Double_t vB = Log(x2*y2/(x1*y1))/(1./Sqrt(x1-threshold) -  1./Sqrt(x2-threshold));
      Double_t vA = Exp(vB/Sqrt(x1-threshold))*x1*y1;
      return vA/x * Exp(-vB/Sqrt(x-threshold));
   }
}

//______________________________________________________________________________
Int_t TNuVTab::BinarySearch(Double_t x, Int_t np) const
{
   // Bisection routine to find the biggest value of n with the condition
   // x >= GetX(n) and n < np-1

   if (x <= GetX(0)) return 0;
   if (x >= GetX(np-1)) return np-2;

   Int_t n, nabove, nbelow, middle;
   nabove = np+1;
   nbelow = 0;

   while(nabove-nbelow > 1) {
      middle = (nabove+nbelow)/2;
      if (x == GetX(middle-1)) {
         nbelow= middle;
         break;
      }
      if (x  < GetX(middle-1)) nabove = middle;
      else                     nbelow = middle;
   }
   n = nbelow-1;

   if (n < 0 || n >= np-1) {
      fprintf(stderr, "Warning in TNuVTab::BinarySearch: "
         "Something wrong here, x=%f, n=%d, X(0)= %f, X(%d-1)=%f\n",
         x,n,GetX(0),np,GetX(np-1));
      for (Int_t i=0; i < np; i++) {
         fprintf(stderr, "X(%d) = %f, x= %f\n", i, GetX(i), x);
      }
      n = (n < 0) ? 0 : np-2;
   }
   return n;
}


//______________________________________________________________________________
Int_t TNuVTab::BinarySearch(Double_t x, Int_t np, Bool_t isAscending) const
{
   // Binary search for either ascending or decending ordered data.
   //
   // For ascending case,
   // it finds the biggest value of n with the condition
   // x >= GetX(n) and n < np-1.
   //
   // For decending case,
   // it finds the biggest value of n with the condition
   // x <= GetX(n) and n < np-1.

   if (isAscending) {
      if (x <= GetX(0) || np <= 2) return 0;
      if (x >= GetX(np-2)) return np-2;
   }
   else {
      if (x >= GetX(0) || np <= 2) return 0;
      if (x <= GetX(np-2)) return np-2;
   }

   int low=0;
   int high = np-1;
   int mid;
   while (high - low > 1 ) {
      mid = (low+high)/2;
      //if (x == data[mid]) return mid;
      if (isAscending) {
         if (x < GetX(mid)) high = mid;
         else                low  = mid;
      }
      else {
         if (x > GetX(mid)) high = mid;
         else                low  = mid;
      }
   }
   //return low;

   // for check
   int n = low;

   if (n < 0 || n >= np-1) {
      fprintf(stderr, "Warning in TNuVTab::BinarySearch: "
         "Something wrong here, x=%f, n=%d, X(0)= %f, X(%d-1)=%f\n",
         x,n,GetX(0),np,GetX(np-1));
      for (Int_t i=0; i < np; i++) {
         fprintf(stderr, "X(%d) = %f, x= %f\n", i, GetX(i), x);
      }
      n = (n < 0) ? 0 : np-2;
   }
   return low;
}
