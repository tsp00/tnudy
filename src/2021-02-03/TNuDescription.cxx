// TNuDescription.cxx  =====================================================
// Author: Tae-Sun Park   Feb 03 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuDescription
//
// [MAT,MF,MT/ C1, C2, L1, L2, NPL, N2/ Bn] LIST
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuDescription.h"
#include "TNuEndfIO.h"

#include "TNuLabel.h"
#include "TNuPrinter.h"
#include "TNudy.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuDescription)

//______________________________________________________________________________
TNuDescription::~TNuDescription()
{
   // TNuDescription dtor
}

//______________________________________________________________________________
void TNuDescription::Set(Int_t /*n*/)
{
   // Initialize fData
}

//______________________________________________________________________________
void TNuDescription::Add(const Char_t* text)
{
   // add text data

   fData.Append(text, 66);
   fData.Append('\0', 1);
   fSize = fData.Length()/67;
}

//______________________________________________________________________________
void TNuDescription::What() const
{
   TNuObject::What();
   cout << "First 10 lines" << endl;
   for (Int_t i = 0; i < 10; i++) {
      if (i >= fSize -1) break;
      cout << At(i) << endl;
   }
}

//______________________________________________________________________________
void TNuDescription::Print(Option_t *opt) const
{
   // print

   TNudy::GetPrinter().Set(this, opt);
   for (Int_t i = 0; i < fSize; i++) {
      //TNuPrinter::GetInstance().PrintList(this);
      printf("%-66s\n", At(i));
   }
}
