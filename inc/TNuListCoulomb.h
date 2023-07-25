// TNuListCoulomb.h  =====================================================
// Author: Tae-Sun Park Feb 13 2012

#ifndef ROOT_TNuListCoulomb
#define ROOT_TNuListCoulomb


///////////////////////////////////////////////////////////////////////////////
//
// TNuListCoulomb
//
// Elastic Coulomb scattering cross section
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuList1.h"
//#include "TNuVF1.h"
#include "TNuTab2.h"

class TNuEndfIO;


class TNuListCoulomb : public TNuList1
{
public:
   TNuListCoulomb() : TNuList1() {}
   TNuListCoulomb(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuListCoulomb(TNuEndfIO &src, const Char_t* label=" 0.0, En, LTP, 0, NW, NL/A");
   //TNuListCoulomb(TNuCont *cont);
   virtual ~TNuListCoulomb() {}

   TNuTab2* GetParentTab2() const { return (TNuTab2*) GetParent(); }
   Double_t GetSPI() const  { return GetParentTab2()->GetC1(); }
   Double_t GetLIDP() const { return GetParentTab2()->GetL1(); }
   Bool_t   IsIdentical() const { return GetLIDP() == 1; }

   Double_t GetEn() const { return GetC2(); }
   Int_t    GetLTP() const { return GetL1(); }
   Int_t    GetNW() const { return GetN1(); }
   Int_t    GetNL() const { return GetN2(); }

   Double_t EvalF1(Double_t x, Double_t *ps = 0) const;

   Int_t    GetNPar() const { return 0; }

   Double_t CoulombXSectDMu(Double_t mu, Double_t* ps=0) const;
   Double_t ResidualXSectDMu(Double_t mu, Double_t* ps=0) const;
   Double_t ElasticXSectDMu(Double_t mu, Double_t* ps=0) const;

   const Char_t* GetXAxisTitle() const { return "#mu"; }
   void     DrawCoulombXSectDMu(); // *MENU*
   void     DrawResidualXSectDMu(); // *MENU*
   void     DrawElasticXSectDMu(); // *MENU*

protected:
   void     SetTransient();
private:
   Double_t fk; //! center of momentum in 1/(10 fm)
   Double_t feta; //! Coulomb paramneter

   ClassDef(TNuListCoulomb, 1) //Elastic Coulomb scattering cross section
};

#endif

