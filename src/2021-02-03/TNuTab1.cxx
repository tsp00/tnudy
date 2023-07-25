// TNuTab1.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

///////////////////////////////////////////////////////////////////////////////
//
// TNuTab1 : class for the TAB1 record
//
// [MAT,MF,MT/ C1, C2, L1, L2, NR, NP/xint/y(x)]TAB1
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuTab1.h"
#include "TNudy.h"
#include "TNuEndfIO.h"
#include "TNuPrinter.h"
#include "TNuCanvasPrinter.h"
#include "TNuMat.h"
#include "TNuSection.h"

#include "TGraph.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TLatex.h"
#include "TAxis.h"

ClassImp(TNuTab1)

Int_t TNuTab1::fgSubIntervals = 3; // default value of number of points for plot between meshes

//______________________________________________________________________________
TNuTab1::TNuTab1(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuEndfTAB2(c1,c2,l1,l2,n1,n2), TNuVF1(), fX(0), fY(0)
{
   // TNuTab1 ctor
   Init();
}


//______________________________________________________________________________
TNuTab1::TNuTab1(const TNuTab1& rhs)
 : TNuEndfTAB2(rhs), TNuVF1(), fX(0), fY(0)
{
   // TNuTab1 assignment operator

   Init();
   for(Int_t n=0;  n < rhs.GetNP(); n++) {
      fX[n] = rhs.GetX(n);
      fY[n] = rhs.GetY(n);
   }
   SetTransient();
}

//______________________________________________________________________________
TNuTab1::TNuTab1(TNuEndfIO &src, const Char_t* label)
 : TNuEndfTAB2(), TNuVF1()
{
   ImportEndfData(src);
   SetLabel(label);
}


//______________________________________________________________________________
void TNuTab1::ImportEndfData(TNuEndfIO &src)
{
   // TNuTab1 importing ENDF data

   TNuEndfTAB2::ImportEndfData(src);

/*
[MAT,MF,MT/ C1, C2, L1, L2, NR, NP/xint/y(x)]TAB1

The TAB1 record can be read with the following FORTRAN statements:
   READ(LIB,10)C1,C2,L1,L2,NR,NP,MAT,MF,MT,NS
10 FORMAT(2E11.0,4I11,I4,I2,I3,I5)
   READ(LIB,20)(NBT(N),INT(N),N=1,NR)
20 FORMAT(6I11)
   READ(LIB,30)(X(N),Y(N),N=1,NP)
30 FORMAT(6E11.0)
*/

   Init();

   for (Int_t n=0; n < GetNP(); n++) {
      Int_t k = n % 3;
      Double_t floats[6];
      int m = 2*(GetNP() - n);
      if (m > 6) m = 6;
      if (k == 0) src.ReadFloats(floats, m);
      SetX(floats[2*k], n);
      SetY(floats[2*k + 1], n);
   }
}

//______________________________________________________________________________
TNuTab1::TNuTab1(const Double_t* xs, const Double_t* ys, Int_t np, Int_t interp)
: TNuEndfTAB2(0,0, 0,0, 1, np), TNuVF1()
{
   // Creates TNuTab1 for the given (x,y) points data

   fN2 = np;

   fNBT[0] = fN2;
   fINT[0] = interp;

   Init();

   for (Int_t n=0; n < GetNP(); n++) {
      SetX(xs[n], n);
      SetY(ys[n], n);
   }
   SetTransient();
}

//______________________________________________________________________________
TNuTab1& TNuTab1::operator=(const TNuTab1 &rhs)
{
   // TNuTab1 assignment operator

   if (this != &rhs) {
      if (fX || fY) ClearHeap();
      TNuEndfTAB2::operator=(rhs);
      Init();
      for (Int_t i=0; i < fN1; i++) {
         fX[i] = rhs.fX[i];
         fY[i] = rhs.fY[i];
      }
      SetTransient();
   }
   return *this;
}


//______________________________________________________________________________
TNuTab1& TNuTab1::Add(const Double_t* xs, const Double_t* ys, Int_t np)
{
   // adds the given (x,y) points data

   if (fN1 != 1) {
      Error("Adopt", "It works only for fN1(%d) = 1", fN1);
      return *this;
   }

   //TNuTab1* tab1= new TNuTab1(xs, ys, np, GetINT(0));
   //return Add(*tab1);
   TNuTab1 tab1(xs, ys, np, GetINT(0));
   return Add(tab1);

}

//______________________________________________________________________________
TNuTab1& TNuTab1::Add(const TNuTab1& tab1)
{
   // adds the given (x,y) points data

   std::vector<Double_t> xs;

   for (Int_t n=0; n < tab1.GetNP(); n++) xs.push_back(tab1.GetX(n));
   for (Int_t n=0; n < GetNP(); n++) xs.push_back(GetX(n));
   std::sort(xs.begin(), xs.end());

   std::vector<Double_t> ys;
   Int_t nsize = (Int_t) xs.size();
   for (Int_t n=0; n < nsize; n++) {
      Double_t x = xs[n];
      Double_t y = EvalF1(x) + tab1.EvalF1(x);
      ys.push_back(y);
   }

   fN2 += tab1.GetNP();
if (fN2 != nsize) {
   printf("Error, fN2 = %d, size = %d, tab1NP= %d\n", fN2, nsize, tab1.GetNP());
}
   fNBT[0] = fN2;

   Init();

   for (Int_t n=0; n < GetNP(); n++) {
      SetX(xs[n], n);
      SetY(ys[n], n);
   }
   return *this;
}

//______________________________________________________________________________
TNuTab1::~TNuTab1()
{
   // TNuEndfTab1 dtor

   ClearHeap();
}

//______________________________________________________________________________
TNuTab1 TNuTab1::operator+(const TNuTab1& rhs) const
{
   // Creates a TNuTab1 by adding rhs to this

   Int_t j1=0, j2=0;
   Int_t np1 = GetNP(), np2 = rhs.GetNP();
   Double_t *xp1 = fX, *xp2= rhs.GetX();
   Double_t *yp1 = fY, *yp2= rhs.GetY();

   std::vector<Double_t> xs;
   std::vector<Double_t> ys;
   xs.reserve(np1 + np2);
   ys.reserve(np1 + np2);

   while(j1 < np1 && j2 < np2) {
      if (xp1[j1] == xp2[j2]) {
         xs.push_back(xp1[j1]);
         ys.push_back(yp1[j1++] + yp2[j2++]);
      }
      else if (xp1[j1] < xp2[j2]) {
         Double_t x = xp1[j1];
         xs.push_back(x);
         ys.push_back(yp1[j1++] + rhs.EvalF1(x));
      }
      else {
         Double_t x = xp2[j2];
         xs.push_back(x);
         ys.push_back(yp2[j2++] + EvalF1(x));
      }
   }

   for (; j1 < np1; j1++) {
      xs.push_back(xp1[j1]);
      ys.push_back(yp1[j1]);
   }
   for (; j2 < np2; j2++) {
      xs.push_back(xp2[j2]);
      ys.push_back(yp2[j2]);
   }

   Int_t interp=0;
   for (Int_t n=0; n < GetNR(); n++)
      if (GetINT(n) > interp) interp= GetINT(n);

   Int_t np = (Int_t) xs.size();
   printf("Tab1: np=%d, interp=%d\n", np, interp);
   return TNuTab1(&xs[0], &ys[0], np, interp);
}


//______________________________________________________________________________
TNuTab1 TNuTab1::operator+(const TGraph& rhs) const
{
   // Creates a TNuTab1 by adding rhs to this

   // for debugging
   {
      Bool_t ascend = kTRUE;
      Double_t *xp= rhs.GetX();
      for (Int_t n=1; n < rhs.GetN(); n++) {
         if (xp[n] < xp[n-1]) {
            printf("X[%d] = %e > X[%d] = %e, we sort\n", n-1,xp[n-1],n,xp[n]);
            ascend = kFALSE;
            break;
         }
      }
      if (!ascend) {
         // turn off the constness of rhs, and do the sort
         const_cast<TGraph*>(&rhs)->Sort();
      }
   }

   Int_t j1=0, j2=0;
   Int_t np1 = GetNP(), np2 = rhs.GetN();
   Double_t *xp1 = fX, *xp2= rhs.GetX();
   Double_t *yp1 = fY, *yp2= rhs.GetY();

   Double_t *xs = new Double_t[np1 + np2];
   Double_t *ys = new Double_t[np1 + np2];

   Int_t n = 0;

   while(j1 < np1 && j2 < np2) {
      if (xp1[j1] == xp2[j2]) {
         xs[n] = xp1[j1];
         ys[n] = yp1[j1++] + yp2[j2++];
      }
      else if (xp1[j1] < xp2[j2]) {
         Double_t x = xp1[j1];
         xs[n] = x;
         ys[n] = yp1[j1++] + rhs.Eval(x);
      }
      else {
         Double_t x = xp2[j2];
         xs[n] = x;
         ys[n] = yp2[j2++] + EvalF1(x);
      }
      n++;
   }

   for (; j1 < np1; j1++, n++) {
      xs[n] = xp1[j1];
      ys[n] = yp1[j1];
   }
   for (; j2 < np2; j2++, n++) {
      xs[n] = xp2[j2];
      ys[n] = yp2[j2];
   }

   Int_t interp=0;
   for (Int_t nr=0; nr < GetNR(); n++)
      if (GetINT(nr) > interp) interp= GetINT(nr);

   Int_t np = n;
   printf("Tab1: np=%d, interp=%d\n", np, interp);
   for (Int_t j =0 ; j < np; j++) {
      printf("n = %6d, x = %15.6e, y = %15.6e\n", j, xs[j], ys[j]);
   }

   return TNuTab1(xs, ys, np, interp);
}

//______________________________________________________________________________
void TNuTab1::ClearHeap()
{
   // delete arrays constructed on heap

   if (fX) delete [] fX;
   if (fY) delete [] fY;
   fX = 0;
   fY = 0;
   printf("call TNuTab1::ClearHeap()\n");
}

//______________________________________________________________________________
void TNuTab1::Init()
{
   // Initialize fX and fY

   fX = new Double_t[fN2];
   fY = new Double_t[fN2];
}

//______________________________________________________________________________
void TNuTab1::SetNP(Int_t np)
{
   if (np == fN2) return;
   ClearHeap();
   fN2 = np;
   Init();
}

//______________________________________________________________________________
void TNuTab1::SetTransient()
{
   // sets the range

   fXmin = fX[0];
   fXmax = fX[fN2-1];
}

//______________________________________________________________________________
void TNuTab1::SetCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
{
   // Copy cont data and initialize fX and fY

   ClearHeap();
   TNuEndfTAB2::SetCont(c1,c2,l1,l2,n1,n2);
   Init();
}

//______________________________________________________________________________
Double_t TNuTab1::EvalF1(Double_t x, Double_t* /* ps */) const
{
   // Evaluate Tab1 (a 1-dim functor)
   using namespace TMath;

   if (x < GetXmin() || x > GetXmax()) return 0;

   Int_t n = BinarySearch(x, fN2);

   // find the interpolatio law
   Int_t interp= GetInterpolationLaw(n);

   if (interp == 6) {
      Double_t x1 = fX[n];
      Double_t y1 = fY[n];
      Double_t x2 = fX[n+1];
      Double_t y2 = fY[n+1];
      if (y1 <= 0 || y2 <= 0) return 0;

      Double_t qValue = GetC2(); // QI = C2.
      Double_t threshold = (qValue > 0) ? 0 : qValue;
      if (x1-threshold <=0 || x2-threshold <=0) {
         fprintf(stderr, "x1=%e or x2=%e is smaller than threshold=%e, C2=%e\n", x1,x2,threshold, qValue);
         return 0;
      }
      else {
         Double_t vB = Log(x2*y2/(x1*y1))/(1./Sqrt(x1-threshold) -  1./Sqrt(x2-threshold));
         Double_t vA = Exp(vB/Sqrt(x1-threshold))*x1*y1;
         return  vA/x * Exp(-vB/Sqrt(x-threshold));
      }
   }

   // now do the interpolation
   Double_t xys[4];

   xys[0] = fX[n];
   xys[1] = fY[n];
   xys[2] = fX[n+1];
   xys[3] = fY[n+1];

   return Interpolation(interp, x, xys);
}


//______________________________________________________________________________
void TNuTab1::Print(Option_t *opt) const
{
   // print Tab1
   if(opt!=NULL && strcmp(opt, "Graph")==0) {
      TNudy::GetPrinter().PrintGraph(this);
   } else {
      TNudy::GetPrinter().Set(this, opt);
      TNudy::GetPrinter().PrintTab1(this);
   }
}

/*
//______________________________________________________________________________
void TNuTab1::SaveAsText() const
{
   TNudy::GetPrinter().OpenSaveToTextDlg(this, kSaveGraph);
}
*/
//______________________________________________________________________________
void TNuTab1::PlotGraph() const
{
   // plots the TGraph of TNuTab1

   TCanvas *c1 = TNudy::GetCanvas();
   TGraph *gr = GetGraph();

   if (!gr) return;

   gr->Draw("AL");

   c1->Update();
}

//______________________________________________________________________________
Int_t TNuTab1::GetInterpolatedXY(Double_t** x_in, Double_t** y_in) const
{
   using namespace TMath;
   Bool_t isHistogram = (GetInterpolationLaw(0) == 1); // is it a histogram
   // number of points between adjacent mesh points
   Int_t subIntervals = (isHistogram) ? 1 : fgSubIntervals;
   Int_t size = (subIntervals + 1) * (GetNP() - 1);
   if (!isHistogram) size += 1;
   if (size <=1 || GetNP() <= 1) return 0;

   Double_t* arrX = new Double_t[size];
   Double_t* arrY = new Double_t[size];
   *x_in = arrX;
   *y_in = arrY;

   Int_t n=0;
   for (Int_t i=0; i < GetNP()-1; i++) {
      Double_t x1 = GetX(i);
      Double_t x2 = GetX(i+1);
      if (isHistogram) {
         const Double_t eps = 1.E-30;
         Double_t y1= EvalF1(x1+eps);
         arrX[n] = x1;
         arrY[n++] = y1;
         arrX[n] = x2;
         arrY[n++] = y1;
         //gr->SetPoint(n++, x1, y1);
         //gr->SetPoint(n++, x2, y1);
      }
      else {
         Int_t interp = GetInterpolationLaw(i);
         Bool_t isLogX = (interp == 3) || (interp == 5); // is it linear in log(x)
         for(Int_t j=0; j <= subIntervals; j++) {
            Double_t t = ((Double_t) j) / (subIntervals+1);
            Double_t x = (isLogX) ?
               Exp(Log(x1) + t * (Log(x2) - Log(x1))) : x1 + t * (x2-x1);
            arrX[n] = x;
            arrY[n++] = EvalF1(x);
            //gr->SetPoint(n++, x, EvalF1(x));
         }

      }
   }

   if (!isHistogram) {
       // add last point
       Double_t x= GetXmax();
       arrX[n] = x;
       arrY[n++] = EvalF1(x);
       //gr->SetPoint(n++, x, EvalF1(x));
   }

   return n;
}
//______________________________________________________________________________
TGraph* TNuTab1::GetGraph() const
{
   // return TGraph of TNuTab1
   Double_t *x, *y;
   Int_t size = GetInterpolatedXY(&x, &y);

   TGraph *gr = new TGraph(size, x, y);
   //TNuMat* mat = GetParentMat();

   TNuSection* sec = GetParentSection();
   if(sec) {
      //const Char_t *xAxisTitle = GetRealXAxisTitle(dynamic_cast<TNuObject*>(sec));
      const Char_t *xAxisTitle = GetXAxisTitle();

      gr->GetXaxis()->SetTitle(xAxisTitle);
      gr->GetXaxis()->CenterTitle();

      gr->SetTitle(GetFigTitle());
      gr->GetYaxis()->SetTitle(sec->GetSymbol());
   }
   gr->SetTitle(GetFigTitle());
   delete[] x;
   delete[] y;

   return gr;
}


//______________________________________________________________________________
TGraph* TNuTab1::GetGraph(const TGraph& rhs) const
{
   // Creates a TGraph for the this + rhs data

   // for debugging
   {
      Bool_t ascend = kTRUE;
      Double_t *xp= rhs.GetX();
      for (Int_t n=1; n < rhs.GetN(); n++) {
         if (xp[n] < xp[n-1]) {
            printf("X[%d] = %e > X[%d] = %e, we sort\n", n-1,xp[n-1],n,xp[n]);
            ascend = kFALSE;
            break;
         }
      }
      if (!ascend) {
         // turn off the constness of rhs, and do the sort
         const_cast<TGraph*>(&rhs)->Sort();
      }
   }

   Int_t j1=0, j2=0;
   Int_t np1 = GetNP(), np2 = rhs.GetN();
   Double_t *xp1 = fX, *xp2= rhs.GetX();
   Double_t *yp1 = fY, *yp2= rhs.GetY();

   TGraph *graph = new TGraph(np1 + np2);
   Int_t n = 0;

   Double_t x, y;
   while(j1 < np1 && j2 < np2) {
      if (xp1[j1] == xp2[j2]) {
         x = xp1[j1];
         y = yp1[j1++] + yp2[j2++];
      }
      else if (xp1[j1] < xp2[j2]) {
         x = xp1[j1];
         y = yp1[j1++];
         if (x >= xp2[0] && x <= xp2[np2-1]) y += rhs.Eval(x);
      }
      else {
         x = xp2[j2];
         y = yp2[j2++];
         if (x >= xp1[0] && x <= xp1[np1-1]) y += EvalF1(x);
      }
      graph->SetPoint(n++, x, y);
   }

   for (; j1 < np1; j1++) {
      graph->SetPoint(n++, xp1[j1], yp1[j1]);
   }
   for (; j2 < np2; j2++) {
      graph->SetPoint(n++, xp2[j2], yp2[j2]);
   }

   graph->Set(n);

   Int_t interp=0;
   for (Int_t nr=0; nr < GetNR(); nr++)
      if (GetINT(nr) > interp) interp= GetINT(nr);

   graph->SetTitle(GetFigTitle());
   return graph;
}
