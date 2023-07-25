// TNuDirs.cxx  =====================================================
// Author: Tae-Sun Park   Feb 03 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuDirs
//
// [MAT,MF,MT/ C1, C2, L1, L2, NPL, N2/ Bn] LIST
//
///////////////////////////////////////////////////////////////////////////////

#include "TNudy.h"
#include "TNuDirs.h"
#include "TNuEndfIO.h"

#include "TNuCont.h"
#include "TNuLabel.h"
#include "TNuPrinter.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuDirs)

//______________________________________________________________________________
TNuDirs::~TNuDirs()
{
   // TNuDirs dtor
}

//______________________________________________________________________________
void TNuDirs::Set(Int_t n)
{
   // Initialize fData

   fData.Set(4*n);
}

//______________________________________________________________________________
void TNuDirs::Add(Short_t data[4])
{
   // add text data

   for (Int_t i=0; i < 4; i++)
      fData[4 * fEntries + i] = data[i];
   fEntries++;
}

//______________________________________________________________________________
void TNuDirs::Add(TNuCont *cont)
{
   // add text data

   if (fEntries >= fSize) {
      Error("Add","Too many data, fEntries = %d and fSize=%d", fEntries, fSize);
      return;
   }
   Short_t *t = &fData[4 * fEntries];
   t[0] = cont->GetL1();
   t[1] = cont->GetL2();
   t[2] = cont->GetN1();
   t[3] = cont->GetN2();

   fEntries++;
}

//______________________________________________________________________________
TNuCont* TNuDirs::GetContAt(Int_t n, TNuCont* cont) const
{
   // add text data

   if (n < 0 || n >= fSize || !cont) return 0;
   Short_t *t = (Short_t*) fData.GetArray() + 4 * n;
   cont->SetCont(0, 0, t[0], t[1], t[2], t[3]);
   return cont;
}


//______________________________________________________________________________
TNuCont* TNuDirs::GetContAt(Int_t n) const
{
   // add text data

   if (n < 0 || n >= fEntries) return 0;

   TNuCont* cont= new TNuCont();
   return GetContAt(n, cont);
}

//______________________________________________________________________________
void TNuDirs::What() const
{
   TNuObject::What();
   cout << "First 10 lines" << endl;
   cout << Form(" %11s %11s %11s %11s", "MF", "MT", "NC", "MOD") << endl;
   for (Int_t i = 0; i < 10; i++) {
      if (i >= fSize -1) break;
      for (Int_t j=0; j < 4; j++)
         cout << Form(" %11d", fData[4*i+j]);
      cout << endl;
   }
}

//______________________________________________________________________________
void TNuDirs::Print(Option_t *opt) const
{
   // print
   TNuPrinter& printer = TNudy::GetPrinter();
   printer.Set(this, opt);
   TNuCont cont;
   cont.SetLabel(",,MF,MT,NC,MOD");
   for (Int_t i = 0; i < fSize; i++) {
      GetContAt(i, &cont);
      printer.PrintCont(&cont);
   }
}
