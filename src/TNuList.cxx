// TNuList.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuList
//
// [MAT,MF,MT/ C1, C2, L1, L2, NPL, N2/ Bn] LIST
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuList.h"
#include "TNuEndfIO.h"

#include "TNuLabel.h"
#include "TNudy.h"
#include "TNuPrinter.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuList)

//______________________________________________________________________________
TNuList::TNuList(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuCont(c1,c2,l1,l2,n1,n2), fData(0)
{
   // TNuList ctor

   Init();
}

//______________________________________________________________________________
TNuList::TNuList(TNuEndfIO &src, const Char_t* label) : TNuCont()
{
   // ctor of TNuList importing ENDF data
   ImportEndfData(src);
   SetLabel(label);
}

//______________________________________________________________________________
void TNuList::ImportEndfData(TNuEndfIO &src)
{

//[MAT,MF,MT/ C1, C2, L1, L2, NPL, N2/ Bn] LIST
//
//The LIST record can be read with the following FORTRAN statements:
//   READ(LIB,10)C1,C2,L1,L2,NPL,N2,MAT,MF,MT,NS
//10 FORMAT(2E11.0,4I11,I4,I2,I3,I5)
//   READ(LIB,20)(B(N),N=1,NPL)
//20 FORMAT(6E11.0)

// xxx

   TNuCont::ImportEndfData(src);

   Init();

   for (Int_t n=0; n < GetNPL(); n++) {
      Int_t k = n % 6;
      Double_t floats[6];
      int m = GetNPL() - n;
      if (m > 6) m=6;
      if (k == 0) src.ReadFloats(floats, m);
      SetAt(floats[k], n);
   }
}

//______________________________________________________________________________
TNuList::TNuList(const TNuList &list) : TNuCont(list), fData(0)
{
   // TNuList copy ctor

   //SetCont((TNuCont*) &list);
   SetData(list.GetData());
}

//______________________________________________________________________________
TNuList& TNuList::operator=(const TNuList &rhs)
{
   // TNuList assignment operator

   if (this != &rhs) {
      ClearHeap();
      TNuCont::operator=(rhs);
      Init();
      SetData(rhs.GetData());
   }
   return *this;
}

//______________________________________________________________________________
TNuList::~TNuList()
{
   // TNuList dtor

   ClearHeap();
}

//______________________________________________________________________________
void TNuList::ClearHeap()
{
   // delete arrays constructed on heap

   if (fData) delete [] fData;
   fData = 0;
}

//______________________________________________________________________________
void TNuList::Init()
{
   // Initialize fData

   fData = new Double_t[fN1];
}

//______________________________________________________________________________
void TNuList::SetCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
{
   // Set Cont data and initialize fData

   ClearHeap();
   TNuCont::SetCont(c1,c2,l1,l2,n1,n2);
   Init();
}

//______________________________________________________________________________
void TNuList::What() const
{
   TNuObject::What();
   cout << "Params" << endl;
   cout << "   NPL = fN1 = " << GetNPL() << " : Number of data points in fData" << endl;
}

//______________________________________________________________________________
void TNuList::SetAt(Double_t y, Int_t i)
{
   if (i>=0 && i < fN1)
      fData[i] = y;
   else
      Error("TNuList", "Out of range, i=%d, range=[0, %d)", i, fN1);
}

//______________________________________________________________________________
void TNuList::SetData(const Double_t *data)
{
   for(Int_t n=0; n < fN1; n++)
      fData[n] = data[n];
}

//______________________________________________________________________________
void TNuList::Print(Option_t *opt) const
{
   // print
   TNudy::GetPrinter().Set(this, opt);
   TNudy::GetPrinter().PrintList(this);
}
