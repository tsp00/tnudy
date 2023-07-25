// TNuMath.cxx  =====================================================
// Author: Tae-Sun Park   Nov. 05, 2011

#include "TNuMath.h"
#include "TComplex.h"
#include "TNuVTab.h"

NamespaceImp(TNuMath)

//______________________________________________________________________________
void TNuMath::HardsphereFactors(Int_t L, Double_t z, Double_t *p, Double_t *s)
{
   // returns the P_l (penetration factor) and S_l (shift factor)
   if( L < 0) {
      fprintf(stderr, "HardsphereFactorsi: Negative L=%d is not allowed\n", L);
      return;
   }
   *p = z;
   *s = 0;
   if (L == 0) return;
   Double_t z2 = z*z;
   for (Int_t ltmp=1; ltmp <= L; ltmp++) {
      Double_t denom = TMath::Power((ltmp - *s),2) + TMath::Power(*p, 2);
      Double_t ptmp = z2*(*p)/denom;
      *s = z2 * (ltmp-(*s))/denom - ltmp;
      *p = ptmp;
   }
}

//______________________________________________________________________________
Double_t TNuMath::HardspherePhaseShift(Int_t L, Double_t z)
{
   // returns the (negative of the) hardssphere phase shift phi_l(z)
   if (L < 0) L = -L -1;
   if (L == 0) return z;
   Double_t z2 = z*z;
   if (L == 1) return z - TMath::ATan(z);
   //Double_t z4 = z2*z2;
   if (L == 2) return z - TMath::ATan(3*z/(3-z2));
   //Double_t z6 = z4*z2;
   if (L == 3) return z - TMath::ATan(z*(15-z2)/(15-6*z2));

   //Bl = (Blm1 + Xl)/(1 - Blm1 Xl) with Xl = Plm1/(l-Slm1)
   Double_t Bl = 0;
   for (Int_t ltmp = 1; ltmp <= L; ltmp++) {
      Double_t Plm1, Slm1;
      HardsphereFactors(ltmp-1, z, &Plm1, &Slm1);
      Double_t Xl = Plm1 / (ltmp - Slm1);
      Bl= (Bl + Xl)/(1 - Bl * Xl);
   }
   return z - TMath::ATan(Bl);
}

//______________________________________________________________________________
void TNuMath::InverseSymmetricComplex3x3Matrix(TComplex m[3][3])
{
   // Get inverse of 3 by 3 symmetric complex matrix

   // There much be more efficient and neater way
   // and below is just a work-around at the moment

   TComplex d[3]; // for diagonal elements, m_ii
   TComplex o[3]; // for off-diagonal elements, m_ij with i != j

   for (Int_t i=0; i < 3; i++) {
      d[i] = m[i][i];
      o[i] = m[(i+1) %3][(i+2) %3];
   }

   TComplex det = d[0]*d[1]*d[2] + 2.0*o[0]*o[1]*o[2] \
      - d[0]*o[0]*o[0] - d[1]*o[1]*o[1]  - d[2]*o[2]*o[2];

   if (TComplex::Abs(det) < 1.E-30) {
      fprintf(stderr, "Warning in TNuMath::InverseSymmetricComplex3x3Matrix:"
         "Determinant = %e + i %e is too small, we give up.\n", det.Re(), det.Im());
      return;
   }

   for (Int_t i=0; i < 3; i++) {
      Int_t i1= (i+1) % 3;
      Int_t i2= (i+2) % 3;
      m[i][i] = (d[i1] * d[i2] -o[i]*o[i])/det;
      m[i][i1] = m[i1][i] = (o[i]*o[i1] - d[i2]*o[i2])/det;
   }
}

//______________________________________________________________________________
Int_t TNuMath::BinarySearch(Int_t np, Double_t *data, Double_t E, Int_t width)
{
   // Perform the binary search for a data of type
   //
   // E_0      d_0 d_1 ...  d_{w-1} // d_i = d_i(E_0)
   // E_1      d_0 d_1 ...  d_{w-1} // d_i = d_i(E_1)
   // ...
   // E_{np-1} d_0 d_1 ...  d_{w-1} // d_i = d_i(E_{np-1})
   //

/*
   if (E < data[0] || E > data[width*(np-1)]) {
      fprintf(stderr,"Bound error, it should be %e <= %e <= %e\n",
         data[0], E, data[width*(np-1)]);
      return -1;
   }
*/

   if (width < 1) {
      fprintf(stderr,"The width = %d should be positive\n", width);
      return -1;
   }
   if (E < data[0]) return 0;
   if (E > data[width*(np-1)]) return np-2;

   Int_t n, nabove, nbelow, middle;
   nabove = np+1;
   nbelow = 0;

   while(nabove-nbelow > 1) {
      middle = (nabove+nbelow)/2;
      if (E == data[width*(middle-1)]) {
         nbelow = middle;
         break;
      }
      if (E  < data[width*(middle-1)]) nabove = middle;
      else                             nbelow = middle;
   }
   n = nbelow-1;

   if (n<0) n=0;
   if (n >= np-1) n= np -2;
   return n;
}

//______________________________________________________________________________
Bool_t TNuMath::Interpolation(Double_t E, Double_t *data,
   Int_t interp, Int_t np, Int_t width, Double_t *result)
{
   // Perform the binary search and interpolation for a data of type
   //
   // E_0      d_0 d_1 ...  d_{w-1} // d_i = d_i(E_0)
   // E_1      d_0 d_1 ...  d_{w-1} // d_i = d_i(E_1)
   // ...
   // E_{np-1} d_0 d_1 ...  d_{w-1} // d_i = d_i(E_{np-1})
   //
   // First find n such that E_n <= Ein < E_{n+1},
   // then do the interpolatin for d_i, {i,0,width-1},
   // then save the output to result array as
   // result = {(Double_t) n, d_0, d_1, ..., d_{width-1}}.
   // The result array must be allocated by the user.
   //
   // It returns kTRUE is the interpolation has been successfully carried out,
   // and kFALSE if problem happened.

   Int_t n = TNuMath::BinarySearch(np, data, E, width);
   if (n < 0) return kFALSE;

   Double_t *r1= data + width*n;
   Double_t *r2= data + width*(n+1);
   Double_t xys[4];
   xys[0] = r1[0];
   xys[2]=  r2[0];
   for (Int_t i=1; i<width; i++) {
      xys[1]= r1[i];
      xys[3]= r2[i];
      result[i]= TNuVTab::Interpolation(interp, E, xys);
/*
if (result[i]!=0 && TMath::Abs(result[i]) < 1.E-30 && data_error++<10) {
printf("??Interp: E=%e, n=%d, interp=%d, np=%d, width=%d, i=%d\n",
E, n, interp, np, width,i);
printf("xys[0]=%e, [1]=%e, [2]=%e, [3]=%e, res=%e\n",
xys[0],xys[1],xys[2],xys[3],result[i]);
printf("data[n*width]=%e, data[n*width+1]=%e\n",data[n*width], data[n*width+i]);
}
*/
   }
   return kTRUE;
}

//#include <tr1/cmath>
#include <cmath>

//______________________________________________________________________________
Double_t TNuMath::ExpIntegralE1(Double_t x)
{
   // returns exponential integral E_1 function, defined as
   // ExpIntegralE1(x) = \int_x^\inf e^t/t dt
   
#ifdef _GLIBCXX_TR1_CMATH_H
   return - std::tr1::expint(-x);
#else
   // Following has been derived from expint.c, 
   // http://pelusa.fis.cinvestav.mx/tmatos/LaSumA/LaSumA2_archivos/NumeRCPs/ansi/recipes/expint.c
   
   const double MAXIT = 100;
   const double EULER = 0.5772156649;
   const double FPMIN = 1.0e-30;
   const double EPS = 1.0e-7;

   if (x <= 0) {
      fprintf(stderr, "Error in expint:: bad arguments, x=%e\n", x);
      return 0;
   }

   if (x > 1) {
      double a,del;
      double b = x+1;
      double c = 1.0/FPMIN;
      double d = 1.0/b;
      double h = d;
      for (int i=1; i <= MAXIT; i++) {
         //a = -i*i(nm1+i);
         a = - i*i;
         b += 2.0;
         d = 1.0/(a*d+b);
         c = b+a/c;
         del = c*d;
         h *= del;
         if (fabs(del-1) < EPS) {
            return h*exp(-x);;
         }
      }
      fprintf(stderr, "Error in expint:: continued fraction failed, x=%e\n", x);
   } else {
      double del;
      double ans = -log(x)-EULER;
      double fact = 1.0;
      for (int i=1; i <= MAXIT; i++) {
         fact *= -x/i;
         del = -fact/i;
         ans += del;
         if (fabs(del) < fabs(ans)*EPS) return ans;
      }
      fprintf(stderr, "Error in expint:: series failed, x=%e\n", x);
   }

   return 0;
#endif
}
