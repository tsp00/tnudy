// TNuListFPY.cxx  =====================================================
// Author: Tae-Sun Park   Jan 16 2012


#include "TNuListFPY.h"
#include "TNuEndfIO.h"
#include "TF1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TNuMat.h"

//#include "TNuList.h"

#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////
//
// TNuListFPY - fission product yield data at an energy
//
/*
   It provides y_fp(E) +/- Delta y_fp(E),
   where y_fp(E) is the yield of fission product "fp" that is defined by
   the ZAFP and FPS, FPS = n for n-th excited state.

   y_fp(E) is independent yield if MT= 454,
           and cumulative yield if MT= 459.


*/
//
///////////////////////////////////////////////////////////////////////////////

ClassImp(TNuListFPY)


//______________________________________________________________________________
TNuListFPY::TNuListFPY()
  : TNuList(),
  fFPS(-1), fAmax(0), fAmin(0), fZmax(0), fZmin(0),
  fNmax(0), fNmin(0), fFPSmax(0), fFPSmin(0)
{
   // ctor of TNuListFPY
}

//______________________________________________________________________________
TNuListFPY::TNuListFPY(TNuEndfIO &src, const Char_t* label)
  : TNuList(src, label),
  fFPS(-1), fAmax(0), fAmin(0), fZmax(0), fZmin(0),
  fNmax(0), fNmin(0), fFPSmax(0), fFPSmin(0)
{
   // ctor of TNuListFPY
}

//______________________________________________________________________________
const Char_t* TNuListFPY::GetSymbolFP(Int_t n) const
{
   // returns chemical symbol corresponding to ZAFP and LFS
   return TNuMat::GetDefaultMatName(GetZAI(n), "ENDF");
}

//______________________________________________________________________________
void TNuListFPY::SetTransient()
{
   // defines extra work just after it has been read from the disk
   // set the range of Z,N,A and FPS

   //if (fAmax > 0) return; // already initialized

   for (Int_t i=0; i < GetNFP(); i++) {
      Int_t zai = GetZAI(i);
      Int_t z = zai / 10000;
      Int_t a = (zai % 10000) / 10;
      Int_t n = a-z;
      Int_t fps = zai % 10;
      if (i==0) {
         fZmax = fZmin = z;
         fAmax = fAmin = a;
         fNmax = fNmin = n;
         fFPSmax = fFPSmin = fps;
         continue;
      }
      if (z > fZmax) fZmax = z;
      else if (z < fZmin) fZmin = z;

      if (a > fAmax) fAmax = a;
      else if (a < fAmin) fAmin = a;

      if (n > fNmax) fNmax = n;
      else if (n < fNmin) fNmin = n;

      if (fps > fFPSmax) fFPSmax = fps;
      else if (fps < fFPSmin) fFPSmin = fps;
   }
}

//______________________________________________________________________________
TH2D* TNuListFPY::GetTH2D()
{
   // generates TH2D and returns its pointer, x-axis is N and y-axis is Z

   //Init();
   TH2D *h = new TH2D("name","FPY", fNmax-fNmin+1, fNmin-0.5, fNmax+0.5,
      fZmax-fZmin+1, fZmin-0.5, fZmax+0.5);
   for (Int_t i=0; i < GetNFP(); i++) {
      Int_t fps = GetFPS(i);
      if (fFPS < 0 || fFPS==fps) {
         Int_t z = GetZA(i) / 1000;
         Int_t n = (GetZA(i) % 1000) - z;
         h->Fill((Double_t) n, (Double_t) z, GetY(i));
      }
   }
   h->SetXTitle("N");
   h->SetYTitle("Z");
   return h;
}


//______________________________________________________________________________
void TNuListFPY::PlotFPY(Option_t* opts)
{
   // plots TH2D

   TH2D *h = GetTH2D();
   if(!h) return;

   h->Draw(opts);
}

//______________________________________________________________________________
void TNuListFPY::What() const
{
using namespace std;
   TNuList::What();
   cout << "    E = " << GetE() << " : Incident energy" << endl;
   cout << "    I = " << GetInterpolationLaw() << " : (interpolation law)" << endl;
   cout << "  NFP = " << GetNFP() << " : number of tabulated FPY" << endl;
   cout << endl;
   cout << "Ranges of fission products" << endl;
   cout << setw(22) <<     "Proton number : " << setw(3) << fZmin << " <=  Z  <= " << setw(3) << fZmax << endl;
   cout << setw(22) <<    "Neutron number : " << setw(3) << fNmin << " <=  N  <= " << setw(3) << fNmax << endl;
   cout << setw(22) <<       "Mass number : " << setw(3) << fAmin << " <=  A  <= " << setw(3) << fAmax << endl;
   cout << setw(22) << "Excitation number : " << setw(3) << fFPSmin << " <= LFS <= " << setw(3) << fFPSmax << endl;
   cout << endl;
   cout << "Fission product yield : " << endl << endl;
   Int_t j=0;
   for (Int_t i=0; i < GetNFP(); i++) {
      if (!GetY(i)) continue; // skip Y(E)=0 data
      cout <<  Form(" %-11s: %10.3e", GetSymbolFP(i), GetY(i));
      if (((j+1)%3) == 0) cout << endl;
      else cout << "  ";
      j++;
   }
   cout << endl;
}
