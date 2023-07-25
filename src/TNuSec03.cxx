// TNuSec03.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec03 - reaction cross sections
/* Begin_Latex
#sigma_{c}(E_{n})
End_Latex
where En is the indident energy (in eV) and
c is the channel index given by the MT value.
*/
//
// = [MAT, 3, MT/  ZA, AWR,  0,  0,  0,  0] HEAD
//   [MAT, 3, MT/  QM,  QI,  0, LR, NR, NP/ Eint/ sigma(E)]TAB1
//   [MAT, 3,  0/ 0.0, 0.0,  0,  0,  0,  0] SEND
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuSec03.h"
#include "TNuMat.h"
#include "TNudy.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
//#include "TROOT.h"

#include <iostream>

ClassImp(TNuSec03)

//______________________________________________________________________________
TNuSec03::TNuSec03(Int_t mat, Int_t mf, Int_t mt) : TNuSection(mat, mf, mt), TNuVF1()
{
   // TNuSec03 ctor
}

//______________________________________________________________________________
TNuSec03::~TNuSec03()
{
   // TNuSec03 dtor
}

//______________________________________________________________________________
void TNuSec03::What() const
{
   using namespace std;
   TNuSection::What();

   cout << "\tQM = " << GetQM() << " : Mass-difference Q value (eV)" << endl;
   cout << "\tQI = " << GetQI() << " : Reaction Q value (eV)" << endl;
   cout << "\tLR = " << GetLR() << " : " << GetLRDescription() << endl;
}

//______________________________________________________________________________
const Char_t* TNuSec03::GetLRDescription() const
{
   // returns description for the residual breakup
   Int_t lr;
   for (Int_t n=0; (lr = kResidualBreakupTable[n].LR); n++) {
      if (lr == GetLR())
         return kResidualBreakupTable[n].Description;
   }
   return "";
}
//______________________________________________________________________________
void TNuSec03::SetTransient()
{
   fTab1 = (TNuTab1*) BodyFirst();
   fXmin = GetTab1()->GetXmin();
   fXmax = GetTab1()->GetXmax();
}

#include "TNuSec02.h"
//______________________________________________________________________________
void TNuSec03::AddResonance()
{
   // includes the resonance contributions,
   // assigning the resulting TNuTab1 to fTab1

   if (GetParentMat()->GetLRP() != 1) return;
   Int_t mt = GetMT();
   if (mt != 1 && mt != 2 && mt != 3 && mt != 5 && mt != 18 && mt != 101 && mt != 102)
      return;

   // now it is the case where the resonance contributions should be added

   TNuSec02 *s2151 = (TNuSec02*) (GetParentMat()->GetSection(2151));
   if (!s2151) {
      Error("SetTransient", "Null Sec2151 for MT = %d", mt);
      return;
   }

   TGraph *res = 0;
   if (mt == 1) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kTotal);
   else if (mt == 2) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kElastic);
   else if (mt == 18) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kFission);
   else if (mt == 102 || mt ==101) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kCapture);
   if (!res || res->GetN()==0) {
      Warning("SetTransient", "Null Graph for MT = %d", mt);
      return;
   }

   fTab1->What();
   fTab1->Print();

   TNuTab1 *tab1 = new TNuTab1();
   *tab1 = *fTab1 + *res;
   fTab1 = tab1;

   fTab1->What();
   //fTab1->Print();
}

//______________________________________________________________________________
void TNuSec03::SetTransient2()
{
   fTab1 = (TNuTab1*) BodyFirst();
   fXmin = GetTab1()->GetXmin();
   fXmax = GetTab1()->GetXmax();

// following routines does not work !!!

   if (GetParentMat()->GetLRP() != 1) return;
   Int_t mt = GetMT();
   if (mt != 1 && mt != 2 && mt != 3 && mt != 5 && mt != 18 && mt != 101 && mt != 102)
      return;

   // now it is the case where the resonance contributions should be added

   TNuSec02 *s2151 = (TNuSec02*) (GetParentMat()->GetSection(2151));
   if (!s2151) {
      Error("SetTransient", "Null Sec2151 for MT = %d", mt);
      return;
   }

   TGraph *res = 0;
   if (mt == 1) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kTotal);
   else if (mt == 2) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kElastic);
   else if (mt == 18) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kFission);
   else if (mt == 102 || mt ==101) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kCapture);
   if (!res || res->GetN()==0) {
      Warning("SetTransient", "Null Graph for MT = %d", mt);
      return;
   }

   Int_t zeros = 0;
   while(s2151->GetEH() >= fTab1->GetX(zeros)) zeros++;

   Bool_t okay = zeros >= 2
     && s2151->GetEL() == fTab1->GetX(0) && s2151->GetEH() == fTab1->GetX(zeros-1);
//     && fTab1->GetY(0) == 0 && fTab1->GetY(zeros) == 0;

   if (!okay) {
      Warning("SetTransient","Something wrong here..., MT= %d, zeros=%d", mt, zeros);
      printf("s2151->GetEL() = %e\n", s2151->GetEL());
      printf("fTab1->GetX(0) = %e\n", fTab1->GetX(0));
      printf("s2151->GetEH()= %e\n", s2151->GetEH());
      printf("fTab1->GetX(%d) = %e\n", zeros, fTab1->GetX(zeros));
      printf("fTab1->GetX(%d+1) = %e\n", zeros, fTab1->GetX(zeros+1));
      printf("fTab1->GetY(0)= %e\n", fTab1->GetY(0));
      printf("fTab1->GetY(%d)= %e\n", zeros, fTab1->GetY(zeros));
      printf("fTab1->GetY(%d+1)= %e\n", zeros,fTab1->GetY(zeros+1));
   }

   printf("Generating new tab1 ...\n");
   // first copy fTab1 to a new tab1
   TNuTab1 *tab1 = new TNuTab1(*fTab1);
   tab1->SetNP(fTab1->GetNP() + res->GetN() - zeros);
   for (Int_t nr = 0; nr < tab1->GetNR(); nr++) {
      Int_t nbt = tab1->GetNBT(nr) + res->GetN() - zeros;
      tab1->SetNBT(nbt, nr);
   }
   Double_t *xs = res->GetX();
   Double_t *ys = res->GetY();
   Int_t n= 0;
   for (Int_t np = 0; np < res->GetN(); np++, n++) {
      tab1->SetX(xs[np], n);
      tab1->SetY(ys[np] + fTab1->EvalF1(xs[np]), n);
   }
   for (Int_t np = zeros; np < fTab1->GetNP(); np++, n++) {
      tab1->SetX(xs[np], n);
      tab1->SetY(ys[np], n);
   }
   fTab1 = tab1;
   printf("Generation done ...\n");

   return;
}

//______________________________________________________________________________
void TNuSec03::ImportEndfData(TNuEndfIO& src)
{
   // Import Section data of File 3
   //

   SetHead(new TNuCont(src, "ZA, AWR, 0,  0,  0,  0/HEAD"));
   Add(new TNuTab1(src, "QM,  QI, 0, LR, NR, NP/#sigma(E)"));
}


//______________________________________________________________________________
void TNuSec03::DrawXSect() const
{
   // plots the cross section

   TCanvas *c1 = TNudy::GetCanvas();
   TGraph *gr = GetTab1()->GetGraph();

   if (!gr) return;
/*
   const Char_t *head = TNuMat::GetDefaultMatName(GetParentMat()->GetZAI(), "Latex");
   const Char_t *symbol = GetDefSymbol(GetMT());
   const Char_t *title = Form("XSect in %s %s. MT=%d.",
      head, symbol, GetMT());
*/
   const Char_t *title = GetFigTitle();
   
   gr->SetTitle(title);
   gr->SetMinimum(0);

   gr->Draw("AL");
   gr->GetXaxis()->SetTitle(GetXAxisTitle());
   gr->GetXaxis()->CenterTitle();
   //gr->GetYaxis()->SetTitle(GetSymbol());

   c1->Update();
}

#include "TNuSec02.h"

//______________________________________________________________________________
void TNuSec03::DrawXSectWithReso() const
{
   // plots the cross section with the resonance contributions added

   TCanvas *c1 = TNudy::GetCanvas();

   TGraph *gr = GetXSectWithResoGraph();
   if (!gr) return;

   gr->Draw("AL");
   c1->Update();
}


//______________________________________________________________________________
TGraph* TNuSec03::GetXSectWithResoGraph() const
{
   // returns the graph for the cross section with the resonance contributions added

   TGraph *res = GetResoGraph();
   TGraph *x =  (!res || res->GetN()==0) ? GetTab1()->GetGraph() : GetTab1()->GetGraph(*res);
   if (x) x->SetTitle(GetFigTitle());
   return x;
}

//______________________________________________________________________________
TGraph* TNuSec03::GetResoGraph() const
{
   // returns the graph for the resonance contributions given in Sec2151

   if (GetParentMat()->GetLRP() != 1) return 0;
   Int_t mt = GetMT();
   if (mt != 1 && mt != 2 && mt != 3 && mt != 5 && mt != 18 && mt != 101 && mt != 102)
      return 0;

   // now it is the case where the resonance contributions should be added

   TNuSec02 *s2151 = (TNuSec02*) (GetParentMat()->GetSection(2151));
   TGraph *res = 0;
   if (mt == 1) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kTotal);
   else if (mt == 2) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kElastic);
   else if (mt == 18) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kFission);
   else if (mt == 102 || mt ==101) res = s2151->GetGraphOfSigmaOf(TNuVResonance::kCapture);

   return res;
}
