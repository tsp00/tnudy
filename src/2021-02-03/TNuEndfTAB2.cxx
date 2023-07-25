//  TNuEndfTAB2.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuEndfTAB2
//
// Class for the ENDF TAB2:
//   C1 C2 L1 L2 NR NZ
//   (NBT(n), INT(n), n=1,NR)
//
// Since TAB2 appears only with following other records,
// this class is mainly for backward compatibility.
// It serves also as the base class for TNuTab1.
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuEndfTAB2.h"
#include "TNuEndfIO.h"
#include "TMath.h"
#include "TNuPrinter.h"
#include "TNudy.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuEndfTAB2)

//______________________________________________________________________________
TNuEndfTAB2::TNuEndfTAB2(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuCont(c1,c2,l1,l2,n1,n2), TNuVTab(), fNBT(0), fINT(0)
{
   // TNuEndfTAB2 ctor
   fNBT = new Int_t[fN1];
   fINT = new Int_t[fN1];
}

//______________________________________________________________________________
TNuEndfTAB2::TNuEndfTAB2(const TNuEndfTAB2 &rhs) : TNuCont(rhs), TNuVTab()
{
   // TNuEndfTAB2 copy ctor
   fNBT = new Int_t[fN1];
   fINT = new Int_t[fN1];
   for (Int_t n = 0; n < fN1; n++) {
      fNBT[n] = rhs.GetNBT(n);
      fINT[n] = rhs.GetINT(n);
   }
}

//______________________________________________________________________________
TNuEndfTAB2::TNuEndfTAB2(TNuEndfIO &src, const Char_t* label) : TNuCont(), TNuVTab()
{
   // ctor of TNuEndfTAB2 importing ENDF data
   ImportEndfData(src);
   SetLabel(label);
}

//______________________________________________________________________________
void TNuEndfTAB2::ImportEndfData(TNuEndfIO &src)
{
   // importing ENDF data

/*
[MAT,MF,MT/ C1, C2, L1, L2, NR, NZ/ Zint]TAB2,

The TAB2 record can be read with the following FORTRAN statements:
   READ(LIB,10)C1,C2,L1,L2,NR,NZ,MAT,MF,MT,NS
10 FORMAT(2E11.0,4I11,I4,I2,I3,I5)
   READ(LIB,20)(NBT(N),INT(N),N=1,NR)
20 FORMAT(6I11)
*/
   TNuCont::ImportEndfData(src);

   fNBT = new Int_t[fN1];
   fINT = new Int_t[fN1];

   for (Int_t n=0; n < GetNR(); n++) {
      Int_t k = n % 3;
      Int_t ints[6];
      int m = 2*(GetNR() - n);
      if (m > 6) m = 6;
      if (k == 0) src.ReadIntegers(ints, m);
      SetNBT(ints[2*k], n);
      SetINT(ints[2*k + 1], n);
   }
}

//______________________________________________________________________________
TNuEndfTAB2::~TNuEndfTAB2()
{
   // TNuEndfTAB2 dtor

   ClearHeap();
}

//______________________________________________________________________________
void TNuEndfTAB2::ClearHeap()
{
   // delete arrays constructed on heap

   if (fNBT) delete [] fNBT;
   if (fINT) delete [] fINT;
   fNBT = 0;
   fINT = 0;
}

//______________________________________________________________________
TNuEndfTAB2& TNuEndfTAB2::operator=(const TNuEndfTAB2 &rhs)
{
   // TNuEndfTAB2 assignment operator

   if (this != &rhs) {
      ClearHeap();
      TNuCont::operator=(rhs);
      fNBT = new Int_t[fN1];
      fINT = new Int_t[fN1];
      for (Int_t i=0; i < fN1; i++) {
         fNBT[i] = rhs.fNBT[i];
         fINT[i] = rhs.fINT[i];
      }
   }
   return *this;
}

//______________________________________________________________________________
void TNuEndfTAB2::SetCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
{
   // Copy cont data and initialize fNBT and fINT

   ClearHeap();
   TNuCont::SetCont(c1,c2,l1,l2,n1,n2);
   fNBT = new Int_t[fN1];
   fINT = new Int_t[fN1];
}


//______________________________________________________________________________
void TNuEndfTAB2::SetNR(Int_t nr)
{
   // Copy cont data and initialize fNBT and fINT

   if (nr == fN1) return;

   ClearHeap();
   fN1 = nr;
   fNBT = new Int_t[fN1];
   fINT = new Int_t[fN1];
}

//______________________________________________________________________________
void TNuEndfTAB2::What() const
{
   TNuObject::What();
   cout << "Params" << endl;
   cout << "\tNR = fN1 = " << GetNR() << " : Number of ranges" << endl;
   if (strstr(ClassName(),"TNuTab1")==0)
      cout << "\tNP = fN2 = " << fN2 << " : Number of (x,y) pairs" << endl;
   else
      cout << "\tNZ = fN2 = " << GetNZ() << " : Number of entries" << endl;
   for (Int_t n=0; n < GetNR(); n++) {
      Int_t n1 = (n==0) ? 0 : fNBT[n-1]-1;
      Int_t n2 = fNBT[n] -1;
      Int_t interp = fINT[n] % 10;
      cout << Form("\t\tINT(%d) = %d for n=%d~%d : ",
         n, fINT[n], n1, n2);
      const Char_t* s = 0;
      if (interp == 2)      s = "(linear-linear) y is linear in x";
      else if (interp == 1) s = "histogram";
      else if (interp == 3) s = "(linear-log) y is linear in log(x)";
      else if (interp == 4) s = "(log-linear) log y is linear in x";
      else if (interp == 5) s = "(log-log) log y is linear in log x";
      else                  s = "Unknown interpolation scheme";
      cout << s << endl;
   }
}

//______________________________________________________________________________
Int_t TNuEndfTAB2::GetInterpolationLaw(Int_t pos) const
{
   //
   // Returns the interpolation law corresponding pos,
   // where pos is the position of E, i.e., the biggest value of n with
   // fX[n] <= E and constrainted by n < NP-1
   //
   for (Int_t i=0; i < fN1; i++)
      if (pos < fNBT[i])
         return fINT[i];
   return 0;
}

//______________________________________________________________________________
void TNuEndfTAB2::Print(Option_t *opt) const
{
   // prints this

   //TNuPrinter::GetInstance().Set(this, opt);
   //TNuPrinter::GetInstance().PrintTAB2(this);
   TNudy::GetPrinter().Set(this, opt);
   TNudy::GetPrinter().PrintTAB2(this);
}

