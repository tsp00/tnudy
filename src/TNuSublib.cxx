// TNuSublib.cxx  =====================================================
// Author: Tae-Sun Park   Jun 29 12:48:16 2011


////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSublib  --- ENDF sub-library                                   //
//                                                                    //
// Collection of TNuMat for a given incident particle                 //
// Characterized by NSUB value                                        //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuSublib.h"

#include "TROOT.h"

#include "TObjString.h"
//#include "TObject.h"

#include "TNudy.h"
#include "TNuEndfIO.h"
//#include "TNuSec01451.h"
//#include "TNuMapper.h"
#include "TNuMat.h"

#include "TNuPrinter.h"

#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuSublib)

//______________________________________________________________________________
TNuSublib::TNuSublib(Int_t nsub) : TNuLazyCollection(), fNSUB(nsub)
{
   // ctor
}

//______________________________________________________________________________
TNuSublib::~TNuSublib()
{
}

//______________________________________________________________________________
void TNuSublib::Init()
{
   // Set name and title of this.
   // It should be called only when reading ENDF data

   SetName(Form("%s_%s", GetShortName(), GetFullName()));
   //SetName (GetFullName());
   SetTitle(GetFullName());
   Info("Init", "Init with fNSUB =%d, name=%s", fNSUB, GetFullName());
}

/*
//______________________________________________________________________________
void TNuSublib::Streamer(TBuffer &R__b)
{
   // Set parent

   TObject::Streamer(R__b);
   
   if (!R__b.IsReading()) return;

   fprintf(stderr,"Set parent for NSUB=%d\n", fNSUB); fflush(stderr);
   TIter mats(GetListOfMats());
   TNuMat* m;      
   while ((m = (TNuMat*) mats.Next())) {
      if (m->InheritsFrom("TNuMat")) {
         fprintf(stderr,"Setting parent for MAT= %d, NSUB=%d\n", m->GetMAT(), fNSUB); fflush(stderr);
         m->SetParent(this);
      }
      else {
         fprintf(stderr,"%p is not TNuMat for NSUB=%d\n", m, fNSUB); fflush(stderr);
      }
   }   
}
*/

//______________________________________________________________________________
const Char_t* TNuSublib::GetShortName(Int_t NSUB)
{
   // static function to get the short name, e.g., "n", "p", and so on.

   Int_t nsub;
   for (Int_t n=0; (nsub = kProjNameTable[n].nsub) >= 0; n++)
      if (nsub == NSUB) return kProjNameTable[n].shortname;

   // if not found,
   return Form("%d", NSUB);
}

//______________________________________________________________________________
const Char_t* TNuSublib::GetFullName(Int_t NSUB)
{
   // static function to get the full name, e.g., "Incident neutron data".

   Int_t nsub;
   for (Int_t n=0; (nsub = kProjNameTable[n].nsub) >= 0; n++)
      if (nsub == NSUB) return kProjNameTable[n].fullname;

   // if not found, return its NSUB
   return Form("TNuSublib with NSUB=%d", NSUB);
}

//______________________________________________________________________________
TNuMat* TNuSublib::GetMat(Int_t zai) const
{
   // Load TNuMat
   return (TNuMat*) GetObjectByNuID(zai);
}

//______________________________________________________________________________
TNuMat* TNuSublib::GetMat(const Char_t *target) const
{
   return GetMat(TNudy::ZAIof(target));
}

//______________________________________________________________________________
void TNuSublib::ls(Option_t* /*option*/) const
{
   cout << Form("(%s) %s at %p: ",TObject::GetName(), this->GetName(), this);
   cout << " / " << GetTitle() << endl;
   std::cout << std::endl;
   std::cout << "Table of Mats" << std::endl;

   //fMats.ls(option);
   TIter next(GetCollection());
   TNuMat* mat;

   cout << setw(15) << "(TNuMat) Name" << ":";
   cout << setw(7) << "ZAI";
   cout << setw(5) << "MAT";

   cout << setw(8) << "AWR";
   cout << setw(4) << "LRP";
   cout << setw(4) << "LFI";

   cout << setw(5) << "NMOD";  // NMOD
   cout << setw(5) << "LREL";  // LREL
   cout << setw(5) << "NVER";  // NVER
   cout << setw(5) << "LDRV"; //LDRV
   cout << setw(5) << "TEMP";
   cout << setw(11) << "ZSYNAM" << endl;

   while ((mat = (TNuMat*) next())) {
      cout << left << setw(15) << mat->GetName() << right << ":";
      cout << setw(7) << mat->GetZAI();
      cout << setw(5) << mat->GetMAT();

      cout << fixed << setprecision(3) << setw(8) << mat->GetAWR();
      cout << setw(4) << mat->GetLRP();
      cout << setw(4) << mat->GetLFI();

      cout << setw(5) << mat->GetNMOD();
      cout << setw(5) << mat->GetLREL();
      cout << setw(5) << mat->GetNVER();
      cout << setw(5) << mat->GetLDRV();
      cout << setw(5) << (Int_t) (mat->GetTEMP()+0.5);
      cout << setw(11) << mat->GetZSYNAM() << endl;
   }
}

