// TNuResoResolved.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuResoResolved: public TNuResonance                                      //
//                                                                           //
//   = Resolved Resonance Parameters (LRU=1)                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuResoResolved.h"

/*
//#include "TNuSec02151.h"
#include "TMath.h"
#include "TNuEndfIO.h"
#include "TNuTab1.h"
#include "TNuTab2.h"
#include "TNuRecsWithCont.h"
#include "TNuContLists.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TPad.h"

#include "TNuMath.h"
*/
#include "TArrayD.h"
#include "TMath.h"


ClassImp(TNuResoResolved)


//______________________________________________________________________________
Int_t TNuResoResolved::MakeSubIntervals(TArrayD &energies,
 TArrayD &widths, TArrayD& mesh) const
{
   // for a given resonance energies and widths, genrate fine mesh
   // and returns the number of meshes.
   // The accuracy governs the target get accuracy, the bigger the better,
   // and roughly it corresponds to the number of sub intervals between
   // ER and ER + Gamma/2.

   // For each sub-intervals,
   // we try
   // E_k = ER + (Gamma/2) Tan(x_k), k = [-k0, k0],
   // with
   // x_k = Pi() k / (|k| + k0 + 1).
   // When k= +/- (k0+1)/3 = +/- accuracy, x_k = Pi()/4
   // and E_k = ER +/- Gamma/2.

   using namespace TMath;

   // sort the energies and widths in ascending manner
   Int_t nrs = energies.GetSize();
   Int_t *index = new Int_t[nrs];
   TMath::Sort(nrs, energies.GetArray(), index, kFALSE);

   // skip ER < EL
   Int_t r0=0;
   while(energies[index[r0]] < GetEL()) r0++;

   Double_t norm = GetAccuracy();
   if (norm < 1) norm = 1;

   // rough guess for the number of mesh points
   Int_t mesh_size = (18 * norm + 2) * nrs + 1;
   mesh.Set(mesh_size);

   Int_t im=0;
   mesh.AddAt(GetEL(), im++);

   Double_t Ebegin = GetEL();
   Double_t Eend = energies[index[r0]] - widths[index[r0]];
   Int_t n3=0;
   if (Ebegin < Eend) n3= norm * Log(Eend/Ebegin);
   for (Int_t n=0; n< n3 ;n++) {
      Ebegin = GetEL() * Exp(n/norm);
      mesh.AddAt(Ebegin, im++);
   }

   for (Int_t r=r0; r < nrs; r++) {
      const Double_t eps = 1.e-3; // minimum decay width in eV
      Double_t e1 = energies[index[r]];
      Double_t w1 = widths[index[r]] + eps;
      if (r < nrs -1) {
         Double_t e2 = energies[index[r+1]];
         Double_t w2 = widths[index[r+1]] + eps;
         Eend = (w1 * e2 + w2* e1)/(w1 + w2);
         if (Eend > GetEH()) Eend = GetEH();
         //printf("Ebegin=%e, Eend=%e, (E1=%e, w1=%e, E2=%e, w2=%e), n=%d, im=%d\n", Ebegin, Eend, E1,w1,E2,w2, n, im);
      }
      else
         Eend = GetEH();

      if (Eend <= Ebegin) continue;

      Int_t n1, n2;
      n1 = - norm * Log(1+ (e1-Ebegin)/w1);
      n2 =   norm * Log(1+ (Eend-e1)/w1);

      for (Int_t n = n1; n <= n2; n++) {
         Double_t dx = (n<0) ? - Exp(-n/norm) + 1 : Exp(n/norm) -1;
         Double_t e = e1 + w1*dx;
         if ( e > mesh[im-1] && e < Eend) mesh.AddAt(e, im++);
      }
      mesh.AddAt(Eend, im++);
      if (Eend >= GetEH()) break;

      Ebegin = Eend;
   }
   if (mesh[im-1] < GetEH()) mesh.AddAt(GetEH(), im++);

   printf("%s::MakeSubIntervals (accuracy =%d)\n", ClassName(), GetAccuracy());
   printf("%d (<= %d) mesh points generated for %e <= E <= %e\n", im, mesh_size, GetEL(), GetEH());

   delete [] index;
   mesh.Set(im);
   return im;
}
