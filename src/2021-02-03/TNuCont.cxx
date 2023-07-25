// TNuCont.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

/**********************************************************************
 **********************************************************************/

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuCont  -- ENDF CONT record                                       //
//                                                                    //
// [MAT,MF,MT/C1,C2,L1,L2,N1,N2]CONT                                  //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuCont.h"

#include "TNudy.h"
#include "TNuEndfIO.h"
#include "string.h"
#include "TNuLabel.h"
#include "TNuPrinter.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuCont)

//______________________________________________________________________________
TNuCont::TNuCont() : TNuObject(), fC1(0), fC2(0), fL1(0), fL2(0), fN1(0), fN2(0)
{
   // TNuCont ctor
}

//______________________________________________________________________________
TNuCont::TNuCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
   : TNuObject(), fC1(c1), fC2(c2), fL1(l1), fL2(l2), fN1(n1), fN2(n2)
{
   // ctor of TNuCont with all members variables
}

//______________________________________________________________________________
TNuCont::TNuCont(TNuEndfIO &src, const Char_t* label) : TNuObject()
{
   // ctor of TNuCont importing ENDF data

   ImportEndfData(src);
   SetLabel(label);
}


//______________________________________________________________________________
void TNuCont::ImportEndfData(TNuEndfIO &src)
{
TString guess = src.GuessRecType();
if ((guess=="LIST" && InheritsFrom("TNuList"))
   || (guess=="TAB1" && InheritsFrom("TNuTab1"))
   || (guess=="TAB2" && InheritsFrom("TNuEndfTAB2"))
   || (guess=="INTG" && InheritsFrom("TNuIntg"))
   || (guess=="CONT")) {
} else {
Warning("ImportEndfData", "[Error] : Guess = %s, class = %s, at %ld\n[%s]",
   guess.Data(), ClassName(), src.GetLineNum(), src.GetLineData());
}


   // importing ENDF data

   Double_t c1, c2;
   Int_t    l1, l2, n1, n2;

   src.ReadCONT(c1,c2,l1,l2,n1,n2);
   fC1 = c1;
   fC2 = c2;
   fL1 = l1;
   fL2 = l2;
   fN1 = n1;
   fN2 = n2;
}

//______________________________________________________________________________
TNuCont::TNuCont(const TNuCont &cont) : TNuObject(cont),
   fC1(cont.fC1), fC2(cont.fC2),
   fL1(cont.fL1), fL2(cont.fL2), fN1(cont.fN1), fN2(cont.fN2)
{
   // TNuCont copy ctor
}

//______________________________________________________________________________
TNuCont& TNuCont::operator=(const TNuCont &rhs)
{
   // TNuCont assignment operator

   if (this != &rhs) {
      TNuObject::operator=(rhs);
      fC1 = rhs.fC1;
      fC2 = rhs.fC2;
      fL1 = rhs.fL1;
      fL2 = rhs.fL2;
      fN1 = rhs.fN1;
      fN2 = rhs.fN2;
   }
   return *this;
}

/*
//______________________________________________________________________________
void TNuCont::SetCont(const TNuCont *cont)
{
   // set cont data

   if (!cont) return;

   if (this != cont) {
      TNuObject::operator=(*cont);
      fC1 = cont->fC1;
      fC2 = cont->fC2;
      fL1 = cont->fL1;
      fL2 = cont->fL2;
      fN1 = cont->fN1;
      fN2 = cont->fN2;
   }
}
*/

//______________________________________________________________________________
TNuCont::~TNuCont()
{
      // TNuCont dtor
}


//______________________________________________________________________________
void TNuCont::ls(Option_t* /*option*/) const
{
   // ls of TNuCont

/*
   cout << " " << setw(11) << GetC1();
   cout << " " << setw(11) << GetC2();
   cout << " ";
   cout << " " << setw(8) << GetL1();
   cout << " " << setw(8) << GetL2();
   cout << " ";
   cout << " " << setw(8) << GetN1();
   cout << " " << setw(8) << GetN2();
*/
   TNuLabel* label= GetLabel();

   cout << " " << setw(11+4) << Form("%s=%#9G", label->HeadAt(0), GetC1());
   cout << " " << setw(11+4) << Form("%s=%#9G", label->HeadAt(1), GetC2());
   cout << " ";
   cout << " " << setw(11) << Form("%s=%d", label->HeadAt(2), GetL1());
   cout << " " << setw(11) << Form("%s=%d", label->HeadAt(3), GetL2());
   cout << " ";
   cout << " " << setw(11) << Form("%s=%d", label->HeadAt(4), GetN1());
   cout << " " << setw(11) << Form("%s=%d", label->HeadAt(5), GetN2());

   cout << " : " << GetName();
   if (GetTitleID()) cout << "/" << GetTitle();
   cout << endl;
}

//______________________________________________________________________________
void TNuCont::Print(Option_t *opt) const
{
   // print
   TNudy::GetPrinter().Set(this, opt);
   TNudy::GetPrinter().PrintCont(this);
}
