// TNuListCoulomb.cxx  =====================================================
// Author: Tae-Sun Park Feb 13 2012

///////////////////////////////////////////////////////////////////////////////
//
// TNuListCoulomb
//
// Elastic Coulomb scattering cross section
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuListCoulomb.h"
#include "TNuEndfIO.h"
#include "TF1.h"

#include "TNuSec03.h"
#include "TNuMat.h"
#include "TNuMath.h"
#include "TNudy.h"
#include "TMath.h"
#include "TCanvas.h"

ClassImp(TNuListCoulomb)

static int fMode = 0; // 0 for elastic, 1 for Coulomb, 2 for Residual

//______________________________________________________________________________
TNuListCoulomb::TNuListCoulomb(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2)
 : TNuList1(c1,c2,l1,l2,n1,n2)
{
   // ctor of TNuListCoulomb importing ENDF data
}

//______________________________________________________________________________
TNuListCoulomb::TNuListCoulomb(TNuEndfIO &src, const Char_t* label)
  : TNuList1(src, label)
{
   // ctor of TNuListCoulomb importing ENDF data
}

//______________________________________________________________________________
void TNuListCoulomb::SetTransient()
{
   // Sets the range
   fXmin = IsIdentical() ? 0 : -1;
   fXmax = +1;

   if (GetLTP() > 10) {
      fXmin = fData[0];
      fXmax = fData[2*(GetNL()-1)];
   }

   // Sets fk and feta
   // fk = center of momentum in 1/(10 fm)
   // feta = Coulomb paramneter
   using namespace TMath;
   Double_t Ein = GetC2();

   TNuMat* mat = GetParentMat();
   Double_t frac = mat->TargetMassFraction(); // A/(1+A)
   Double_t m1 = mat->GetAWI() * TNuMath::MassOfNeutron();
   fk = Sqrt(2*m1*Ein)*frac/TNuMath::HbarEv10fm();

   Int_t z1 = mat->GetNSUB() / 10000;
   Int_t z2 = mat->GetZAI() / 10000;
   Double_t alpha = TNuMath::FineStructureConstant();
   //Double_t u = TNuMath::AMU();
   feta = z1 * z2 * alpha * Sqrt(m1/2/Ein);
}

//______________________________________________________________________________
Double_t TNuListCoulomb::EvalF1(Double_t mu, Double_t* ps) const
{
   //
   return (fMode == 1) ? CoulombXSectDMu(mu, ps) :
          (fMode == 2) ? ResidualXSectDMu(mu, ps) :
                         ElasticXSectDMu(mu, ps);
}

//______________________________________________________________________________
Double_t TNuListCoulomb::CoulombXSectDMu(Double_t mu, Double_t * /*ps*/) const
{
   // Differential coulomb cross section
   using namespace TMath;
   Double_t spin = GetSPI();
   Double_t k2 = fk * fk;
   Double_t eta = feta;


   Double_t x = eta * eta / k2;

   const Double_t tol = 1e-20;
   
   if (IsIdentical()) {
      if (Abs(Abs(mu)-1) <= tol) {
         fprintf(stderr, "CoulombXSectDMu:: Abs of mu=%f is too close to 1, it is rescaled to %f\n",  mu, mu*(1- tol));
         mu *= 1 - tol;
      }
      Double_t mu2 = mu*mu;
      x /= 1 - mu2;
      x *= (1+mu2)/(1-mu2)
         + Power(-1, 2*spin)/(2*spin+1) * Cos(eta * (1+mu)/(1-mu));
   } else {
      if (Abs(mu-1) <= tol) {
         fprintf(stderr, "CoulombXSectDMu:: mu=%f is too close to 1, it is rescaled to %f\n",  mu, mu*(1- tol));
         mu *= 1 - tol;
      }
      x /= (1-mu) * (1-mu);
   }
   return x;
}

//______________________________________________________________________________
Double_t TNuListCoulomb::ResidualXSectDMu(Double_t mu, Double_t * /*ps*/) const
{
   // Residual cross section
   // = (1-mu^nu) (sigma_elastic - sigma_Coulomb)
   // where nu = 1 (2) for distinguishable (identical) particles

   using namespace TMath;

   const Double_t tol = 1e-20;
   if (Abs(Abs(mu)-1) <= tol) {
      fprintf(stderr, "ResidualXSectDMu:: Abs of mu=%f is too close to 1, it is rescaled to %f\n",  mu, mu*(1- tol)); fflush(stdout); fflush(stderr);
      mu *= 1 - tol;
   }
   
   if (GetLTP() > 10) {
      if (mu < GetXmin() || mu > GetXmax()) return 0;
      Int_t interp= GetLTP() - 10;

      Double_t out[2];
      //TNuMath::Interpolation(mu, fData, interp, 2, GetNL(), out);
      TNuMath::Interpolation(mu, fData, interp, GetNL(), 2, out);
      return out[1];
   }

   Double_t eta = feta;

   Double_t Plm1 = 0;
   Double_t Pl = 1;
   Double_t Plsav;
   Double_t* bs= GetData();
   Double_t bsum = 0;
   Double_t* as = bs + ((IsIdentical())? GetNL() : 2*GetNL()) + 1;
   Double_t asum = 0;

   // exp(i eta log((1-mu)/2) = c1 + i s1
   // exp(i eta log((1+mu)/2) = c2 + i s2
   Double_t c1 = Cos(eta*Log((1-mu)/2));
   Double_t s1 = Sin(eta*Log((1-mu)/2));
   Double_t c2 = Cos(eta*Log((1+mu)/2));
   Double_t s2 = Sin(eta*Log((1+mu)/2));

   for (Int_t l=0; l <= 2*GetNL(); l++, Plm1 = Plsav) {
      if (IsIdentical()) {
         if (l%2==0) bsum += (2*l+1)*Pl/2 * bs[l/2];
      }
      else {
         bsum += (2*l+1)*Pl/2 * bs[l];
      }
      if (GetLTP()==1 && l <= GetNL()) {
         Double_t al;
         if (IsIdentical()) {
            Double_t c = (1+mu)*c1 + Power(-1, l)*(1-mu)*c2;
            Double_t s = (1+mu)*s1 + Power(-1, l)*(1-mu)*s2;
            al = c*as[2*l] - s*as[2*l+1];
         }
         else {
            al = c1*as[2*l] - s1*as[2*l+1];
         }
         asum += (2*l+1)*Pl/2 * al;
      }
      Plsav = Pl;
      Pl = ((2*l+1) * mu * Pl - (l) * Plm1) /(l+1);
   }

   if(GetLTP()==2) return bsum;

   Double_t munu = IsIdentical() ? mu*mu : mu;
   return -2*eta*asum + (1-munu)*bsum;
}

//______________________________________________________________________________
Double_t TNuListCoulomb::ElasticXSectDMu(Double_t mu, Double_t * ps) const
{
   // Elastic cross section
   // Coulomb + Residual / (1-mu^nu),
   // where nu = 1 (2) for distinguishable (identical) particles

   using namespace TMath;
   Double_t munu = IsIdentical() ? mu*mu : mu;
   const Double_t tol = 1e-20;
   if (Abs(munu-1) <= tol) {
      fprintf(stderr, "ElasticXSectDMu:: Abs munu=%f is too close to 1, it is rescaled to %f\n",  munu, (1- tol)); fflush(stdout); fflush(stderr);
      munu = 1 - tol;
   }
   if (GetLTP() > 10) {
      if (mu < GetXmin() || mu > GetXmax()) return 0;
      Int_t mt = GetParentSection()->GetMT();
      TNuSec03 *s3000 = (TNuSec03*) GetParentMat()->GetSection(3, mt);
      Double_t sigmaNI = s3000->EvalF1(GetEn(), ps);
      return CoulombXSectDMu(mu) + sigmaNI * ResidualXSectDMu(mu)/(1-munu);
   }

   return CoulombXSectDMu(mu) + ResidualXSectDMu(mu)/(1-munu);
}


//______________________________________________________________________________
void TNuListCoulomb::DrawCoulombXSectDMu()
{
   // Draws Coulomb xsect

   TCanvas *c1 = TNudy::GetCanvas();
   fMode = 1;
   TF1* tf1 = GetTF1();
   const Char_t *head = GetParentMat()->GetProjTargetName(" + ", "Latex");
   const Char_t *title = Form("Coulomb cross section in %s. E = %e eV;%s;%s",
      head, GetEn(), GetXAxisTitle(), "#sigma_{C}(E, #mu)");
   tf1->SetTitle(title);
   tf1->Draw();
   c1->Update();
}

//______________________________________________________________________________
void TNuListCoulomb::DrawResidualXSectDMu()
{
   // Draws residual xsect

   TCanvas *c1 = TNudy::GetCanvas();
   fMode = 2;
   TF1* tf1 = GetTF1();
   const Char_t *head = GetParentMat()->GetProjTargetName(" + ", "Latex");
   const Char_t *title = Form("Residual cross section in %s. E = %e eV;%s;%s",
      head, GetEn(), GetXAxisTitle(), "#sigma_{residual}(E, #mu)");
   tf1->SetTitle(title);
   tf1->Draw();
   c1->Update();
}

//______________________________________________________________________________
void TNuListCoulomb::DrawElasticXSectDMu()
{
   // Draws elastic xsect

   TCanvas *c1 = TNudy::GetCanvas();
   fMode = 0;
   TF1* tf1 = GetTF1();
   const Char_t *head = GetParentMat()->GetProjTargetName(" + ", "Latex");
   const Char_t *title = Form("Elastic cross section in %s. E = %e eV;%s;%s",
      head, GetEn(), GetXAxisTitle(), "#sigma_{el}(E, #mu)");
   tf1->SetTitle(title);
   tf1->Draw();
   c1->Update();
}
