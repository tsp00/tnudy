// TNuDEpDMuETransfer.cxx  =====================================================
// Author: Tae-Sun Park   Aug 8 2011

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNuDEpDMuETransfer :
// Energy transfer during electro-atomic excitation or bremsstrahlung (LAW=8)
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TNuDEpDMuETransfer.h"
#include "TMath.h"
#include "TNuEndfIO.h"

//#include "TNuSec03.h"
#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuDEpDMuETransfer)
//______________________________________________________________________________
TNuDEpDMuETransfer::TNuDEpDMuETransfer(TNuEndfIO &src)
 : TNuDEpDMu()
{
   // Energy transfer during electro-atomic excitation or bremsstrahlung (LAW=8)
   TNuTab1 *tab1 = new TNuTab1(src, "ZAP, 0.0, 0, LAW, NR, NP/y(E)");
   SetTab1(tab1);

   Add(new TNuTab1(src, "0.0, 0.0, 0, 0, NR, NP/ Eint / ET(E)"));
}


//______________________________________________________________________________
void TNuDEpDMuETransfer::What() const
{
   TNuRecsWithTab1::What();
   //cout << "Params" << endl;
   //cout << "   NPL = fN1 = " << GetNPL() << " : Number of data points in fData" << endl;
   cout << "  ZAP = " << GetZAP() << " : Product identifier 1000 * Z + A" << endl;
   cout << "  AWP = " << GetAWP() << " : Product mass in neutron units" << endl;
   cout << "  LIP = " << GetLIP() << " : Product modifier flag (0 for ground state)" << endl;
   cout << "  LAW = " << GetLAW() << " : Representation identifier" << endl;
}


//______________________________________________________________________________
void TNuDEpDMuETransfer::SetTransient()
{
   fXmin = ((TNuTab1*) BodyFirst())->GetXmin();
   fXmax = ((TNuTab1*) BodyFirst())->GetXmax();
}
