// TNuFile.cxx  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuFile (NUclear Data librarY IO routines)                         //
//                                                                    //
// TNuFile.cxx:                                                       //
// Routine to handle a single ENDF file                               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuFile.h"
#include "TNuCollection.h"

#include "TROOT.h"
#include "TString.h"

#include "TKey.h"

#include "TNudy.h"
#include "TNuSection.h"
#include "TNuCont.h"
#include "TNuMat.h"
//#include "TNuEndfIO.h"

//#include "TNuVF1.h"
//#include "TNuVF2.h"
//#include "TNuVF3.h"

#include "TNuPrinter.h"
#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuFile)

//______________________________________________________________________________
TNuFile::TNuFile(Int_t mat, Int_t mf) : TNuLazyCollection(), fMAT(mat), fMF(mf)
{
}

//______________________________________________________________________________
TNuFile::~TNuFile()
{
}


//______________________________________________________________________________
const Char_t* TNuFile::GetFileDescription(Int_t mf)
{
   // Returns the file description for the given MF value mf

   static const struct {
      Int_t         MF;
      const TString Description;
   } kFileDescription[] = {
   { 1, "General information"},
   { 2, "Resonance parameter data"},
   { 3, "Reaction cross sections"},
   { 4, "Angular distributions for emitted particles"},
   { 5, "Energy distributions for emitted particles"},
   { 6, "Energy-angle distributions for emitted particles"},
   { 7, "Thermal neutron scattering law data"},
   { 8, "Radioactivity and fission-product yield data"},
   { 9, "Multiplicities for radioactive nuclide production"},
   {10, "Cross sections for radioactive nuclide production"},
   {12, "Multiplicities for photon production"},
   {13, "Cross sections for photon production"},
   {14, "Angular distributions for photon production"},
   {15, "Energy distributions for photon production"},
   {23, "Photo- or electro-atomic interaction cross sections"},
   {26, "Electro-atomic angle and energy distribution"},
   {27, "Atomic form factors or scattering functions for photo-atomic interactions"},
   {28, "Atomic relaxation data"},
   {30, "Data covariances obtained from parameter covariances and sensitivities"},
   {31, "Data covariances for nu(bar)"},
   {32, "Data covariances for resonance parameters"},
   {33, "Data covariances for reaction cross sections"},
   {34, "Data covariances for angular distributions"},
   {35, "Data covariances for energy distributions"},
   {39, "Data covariances for radionuclide production yields"},
   {40, "Data covariances for radionuclide production cross sections"}};

   Int_t m = 0;
   for (Int_t k = 0; (m = kFileDescription[k].MF) <= 40; k++)
      if (m == mf) return kFileDescription[k].Description;
   return "";
}

//______________________________________________________________________________
void TNuFile::Init()
{
   // Initialization of TNuFile
   // This should be called only after reading of ENDF data

   // Set default name and title
   SetName(Form("file_%02d", fMF));
   SetTitle(GetFileDescription(fMF));
   SetLabel("");
}

//______________________________________________________________________________
Int_t TNuFile::GetMAT() const
{
   // returns MAT number
   return fMAT;
}

//______________________________________________________________________________
TNuSection* TNuFile::GetSection(Int_t mft) const
{
   // in case it is called with the MT value
   if (mft < 1000) mft += 1000 * fMF;
   return (TNuSection*) GetObjectByNuID(mft);
}

//______________________________________________________________________________
void TNuFile::Print(Option_t *opt) const
{
   // print a file data

   TNuLazyCollection::Print(opt);
   TNudy::GetPrinter().PrintEND(fMAT, 0, 0, 0, "FEND");
}

