// TNuListFPY.h  =====================================================
// Author: Tae-Sun Park   Jan 16 2012

#ifndef ROOT_TNuListFPY
#define ROOT_TNuListFPY

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec08454 - fission product yield data (MT=454 and 459)
//              for fissionable materials
//
/*
*/
//
///////////////////////////////////////////////////////////////////////////////

//#include "TNuSection.h"
//#include "TNuTab1.h"
//#include "TNuEndfIO.h"
#include "TNuList.h"

class TNuEndfIO;
class TH1D;
class TH2D;
class TNuMat;

class TNuListFPY : public TNuList
{
public:
   TNuListFPY();
   TNuListFPY(TNuEndfIO &src, const Char_t* label=
      "E, 0.0, I, 0, NN, NFP ; ZAFP, FPS, Y, +-");
   virtual ~TNuListFPY() {}

   Double_t      GetE() const { return GetC1(); }
   Double_t      GetInterpolationLaw() const { return GetL1(); }
   Int_t         GetNN() const { return GetN1(); }  // 4*NFP
   Int_t         GetNFP() const { return GetN2(); } // Number of fission product nuclide states

   Int_t         GetZA(Int_t n) const { return (Int_t) (At(4*n) + 0.5); }
   Int_t         GetFPS(Int_t n) const { return (Int_t) (At(4*n+1) + 0.5); }
   Int_t         GetZAI(Int_t n) const { return 10*GetZA(n) + GetFPS(n); }
   const Char_t* GetSymbolFP(Int_t n) const;

   Double_t      GetY(Int_t n) const { return At(4*n + 2); }
   Double_t      GetDY(Int_t n) const { return At(4*n + 3); }

   TH2D*         GetTH2D();
   void          PlotFPY(Option_t* opts="colz"); // *MENU*

/*
   TH1D*         GetTH1DAt(const Char_t *by, Int_t value) const;
   TH1D*         GetTH1DAtZ(Int_t z) const { return GetTH1DAt("Z", z); }
   TH1D*         GetTH1DAtN(Int_t n) const { return GetTH1DAt("N", n); }
   TH1D*         GetTH1DAtA(Int_t a) const { return GetTH1DAt("A", a); }

   void          PlotAt(const Char_t *by, Int_t value) const; // *MENU*
   void          PlotAtZ(Int_t z) const { PlotAt("Z", z); } // *MENU*
   void          PlotAtN(Int_t n) const { PlotAt("N", n); } // *MENU*
   void          PlotAtA(Int_t a) const { PlotAt("A", a); } // *MENU*

   void          ShowMostProbableProducts(Int_t n); // *MENU*
*/
   void          SetFPS(Int_t fps) { fFPS = fps; }
   Int_t         GetFPS() const { return fFPS; }

   void          What() const; // *MENU*

private:
   void         SetTransient();

   typedef struct {
      Double_t ZAFP;
      Double_t FPS;
      Double_t Y;
      Double_t DY;
   } ListFPY_t;

   Int_t  fFPS; //! selection for FPS. If fFPS >=0, then select only FPS = fFPS. If fFPS < 0, then sum all the FPS.

   Int_t  fAmax;   //! max of A 
   Int_t  fAmin;   //! min of A 
   Int_t  fZmax;   //! max of Z 
   Int_t  fZmin;   //! min of Z 
   Int_t  fNmax;   //! max of N 
   Int_t  fNmin;   //! min of N 
   Int_t  fFPSmax; //! max of FPS
   Int_t  fFPSmin; //! min of FPS

   ClassDef(TNuListFPY, 1) // fission product yield data at an energy
};

#endif

