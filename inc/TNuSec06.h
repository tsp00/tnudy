// TNuSec06.h  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

#ifndef ROOT_TNuSec06
#define ROOT_TNuSec06


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuSec06 : d2XdEdmu = Energy-Angle Distributions                //
//                                                                           //
//                                                                           //
// ------------------ head ----------------------------------------//
// HeadAt(0) :                                                     //
// [MAT, 6, MT/ ZA, AWR, 0, LCT, NK, 0]HEAD                        //
//                                                                           //
// ------------------ body ----------------------------------------//
// At(n) = n-th TNuDEpDMu, n=0, NK-1                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuSection.h"
#include "TNuVF1s.h"

class TNuSec03;
class TNuEndfIO;
class TNuDEpDMu;

class TNuSec06 : public TNuSection, public TNuVF1s //, public TNuVF3
{
public:
   TNuSec06() : TNuSection(), fQI(0) {}
   TNuSec06(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat,mf,mt), fQI(0) {}
   virtual ~TNuSec06() {}

   //Bool_t   IsF3() const { return kTRUE; }
   void     DrawYields(); // *MENU*

   const    Char_t* GetXAxisTitle() const { return "E [eV]"; }
   //const    Char_t* GetYAxisTitle() const { return "E' [eV]"; }
   //const    Char_t* GetZAxisTitle() const { return "#mu"; }

   //Double_t EnergyAngleDist(Double_t Ein, Double_t Eout, Double_t mu, Double_t *ps=0) {
   //   return EvalF3(Ein, mu, Eout, ps);
   //}
   //Double_t EvalF3(Double_t Ein, Double_t Eout, Double_t mu, Double_t *ps=0);
   Int_t    GetNK() const { return GetN1(); }
   //void     DrawEnergyAngleDist() { Draw(); }
   
   TNuDEpDMu* GetDEpDMuAt(Int_t n) const { return (TNuDEpDMu*) BodyAt(n); }

   TNuDEpDMu* GetDEpDMu(const Char_t* product_name) const;   
   TNuDEpDMu* GetDEpDMuByZAP(Int_t zap) const;
   TNuDEpDMu* GetDEpDMuByZAIP(Int_t zaip) const;
   
   Int_t    NComponents() const { return GetNK(); }
   Double_t EvalF1At(Int_t n, Double_t En, Double_t* ps) const;
   const Char_t* GetSymbolAt(Int_t n) const;
   void Add(TObject* obj);

   void          ImportEndfData(TNuEndfIO& src);
   TNuSec03*   GetSec3000() const { return fSec3000; }
   void          SetQI(Double_t qi) { fQI = qi; }
   Double_t      GetQI() const { return fQI; }
   
   Int_t         GetLCT() const { return GetL2(); }
   Bool_t        IsCMFrame() const {
      return (GetLCT() == 2 || (GetLCT() == 3 && GetA() <= 4)); }
   Bool_t        IsLabFrame() const {
      return (GetLCT() == 1 || (GetLCT() == 3 && GetA() > 4)); }


protected:
   void     SetTransient();


private:
   Double32_t    fQI; // The QI value copied from File 3
   TNuSec03*   fSec3000; //! the corresponding section in File 3

   ClassDef(TNuSec06, 1) // Energy-angle distributions
};

#endif
