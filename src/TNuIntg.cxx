// TNuIntg.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuIntg
//
// 1 CONT + NM INTG lines
//
// [MAT,32,151/ 0.0, 0.0, NDIGIT, NNN, NM, 0 ]CONT
// [MAT,32,151/ II, JJ, KIJ ]INTG
// [MAT,32,151/ II, JJ, KIJ ]INTG
// < Continue until a total of NM of INTG records are read >
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuIntg.h"
#include "TNuEndfIO.h"

ClassImp(TNuIntg)

//______________________________________________________________________
TNuIntg::TNuIntg(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuCont(c1,c2,l1,l2,n1,n2), fI(0), fJ(0), fK(0)
{
   // TNuIntg ctor with TNuCont*

   Init();
}

//______________________________________________________________________________
TNuIntg::TNuIntg(TNuEndfIO &src, const Char_t* label) : TNuCont()
{
   // ctor of TNuIntg importing ENDF data
   ImportEndfData(src);
   SetLabel(label);
}


//______________________________________________________________________________
void TNuIntg::ImportEndfData(TNuEndfIO &src)
{
   // Read 1 CONT record and NM=N1 INTG records
   TNuCont::ImportEndfData(src);

   Init();

/*
INTG, or INTeGer, records are used to store a correlation matrix in integer format.  The
shorthand notation is

[MAT,  MF,  MT / II, JJ, KIJ ] INTG

where II and JJ are position locators, and KIJ is an array whose dimension is specified by the
number of digits NDIGIT to be used for representing the values.  NDIGIT can have any value
from 2 to 6; the corresponding dimensions (NROW) are 18, 13, 11, 9, and 8, respectively.
The INTG record can be read with the following FORTRAN statements:
   DIMENSION KIJ(NROW)
   IF (NDIGIT.EQ.2) READ (LIB,20) II, JJ, KIJ, MAT, MF, MT, NS
   IF (NDIGIT.EQ.3) READ (LIB,30) II, JJ, KIJ, MAT, MF, MT, NS
   IF (NDIGIT.EQ.4) READ (LIB,40) II, JJ, KIJ, MAT, MF, MT, NS
   IF (NDIGIT.EQ.5) READ (LIB,50) II, JJ, KIJ, MAT, MF, MT, NS
   IF (NDIGIT.EQ.6) READ (LIB,60) II, JJ, KIJ, MAT, MF, MT, NS
 20 FORMAT (2I5, 1X, 18I3, 1X,  I4, I2, I3, I5)
 30 FORMAT (2I5, 1X, 13I4, 3X,  I4, I2, I3, I5)
 40 FORMAT (2I5, 1X, 11I5,      I4, I2, I3, I5)
 50 FORMAT (2I5, 1X,  9I6, 1X,  I4, I2, I3, I5)
 60 FORMAT (2I5,      8I7,      I4, I2, I3, I5)
*/

   Int_t ndigit = GetNDIGIT();

   for (Int_t m= 0; m < GetNM(); m++) {
      Short_t kij[18];
      Int_t i,j;
      src.ReadINTG(i, j, kij, ndigit);
      SetAt(i,j,kij, m);
   }
}


//______________________________________________________________________________
void TNuIntg::Init()
{
   // Initialize fI, fJ and fK

   // transient variables
   int ndigit = GetNDIGIT();
   fNRow = (ndigit == 2) ? 18 :
           (ndigit == 3) ? 13 :
           (ndigit == 4) ? 11 :
           (ndigit == 5) ? 9 :
           (ndigit == 6) ? 8 : 0;
   if (fNRow == 0) {
      Error("Init", "Unsupported value of NDIGIT = %d", ndigit);
      return;
   }

   fKsize = GetNM() * fNRow;

   fI  = new Short_t[GetNM()];
   fJ  = new Short_t[GetNM()];
   fK  = new Short_t[fKsize];

   fScaleFactor = 1;
   for (int i=0; i < ndigit; i++) fScaleFactor /= 10;
}

//______________________________________________________________________________
Double_t TNuIntg::GetCorrelation(Int_t i, Int_t j) const
{
   // Evaluate the correlation between i-th and j-th variables

   if (!RangeOk(i, GetNNN()) || !RangeOk(j, GetNNN())) return 0;
   if (i < j) {
     int k = i;
     i=j;
     j=k;
   } else if (i == j) return 1;

   for (int n = 0; n < GetNM(); n++) {
      if ((i+1) == fI[n]) {
         int m = j+1 - fJ[n];
         if (m >= 0 && m < fNRow) {
            int k = fK[n*fNRow + m];
            if (k > 0) return (k + 0.5)*fScaleFactor;
            else if (k < 0) return (k - 0.5)*fScaleFactor;
            else return 0;
         }
      }
   }
   return 0;
}

//______________________________________________________________________________
void TNuIntg::SetCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
{
   // Copy cont to this

   ClearHeap();

   TNuCont::SetCont(c1,c2,l1,l2,n1,n2);

   Init();
}

//______________________________________________________________________________
TNuIntg::~TNuIntg()
{
   // TNuIntg dtor
   ClearHeap();
}


//______________________________________________________________________________
void TNuIntg::ClearHeap()
{
   // delete member arrays on heap
   if(fI) delete fI;
   if(fJ) delete fJ;
   if(fK) delete fK;
   fI = 0;
   fJ = 0;
   fK = 0;
}

//______________________________________________________________________________
void TNuIntg::SetAt(Int_t i, Int_t j, Short_t kij[], Int_t n)
{
   //if (!RangeOk(i, GetNNN()) || !RangeOk(j, GetNNN())) return;
   if (!RangeOk(i-1, GetNNN()) || !RangeOk(j-1, GetNNN())) return;
   if (!RangeOk(n, GetNM())) return;
   if (i == j) {
      Warning("SetAt", "i=%d > j=%d should be satisfied", i, j);
      return;
   }
   if (i < j) {
      int k = i;
      i = j;
      j = k;
   }
   fI[n] = i;
   fJ[n] = j;
   for (Int_t m=0; m < fNRow; m++) fK[n*fNRow + m]= kij[m];
}

