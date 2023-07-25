// TNuSublib.h  =====================================================
// Author: Tae-Sun Park   Jun 29 12:48:16 2011

#ifndef ROOT_TNuSublib
#define ROOT_TNuSublib

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSublib  --- ENDF sub-library                                   //
//                                                                    //
// Collection of TNuMat for a given incident particle                 //
// Characterized by NSUB value                                        //
//                                                                    //
////////////////////////////////////////////////////////////////////////

//#include "TNuObject.h"
#include "TNuLazyCollection.h"
//#include "TList.h"
//#include "TBrowser.h"

//#include "TNuLib.h"
#include "TNuMat.h"

class TNuEndfIO;
//class TNuMat;
class TNuLib;

class TNuSublib: public TNuLazyCollection
{
public:
   TNuSublib(Int_t nsub = 0);
   virtual ~TNuSublib();

   void Init();
 
   static const Char_t*  GetShortName(Int_t nsub);
   static const Char_t*  GetFullName(Int_t nsub);

   const Char_t*  GetShortName() const { return GetShortName(fNSUB); }
   const Char_t*  GetFullName() const { return GetFullName(fNSUB); }
   Int_t          SubLibraryNumber() const          { return fNSUB; }
   Int_t          GetNSUB() const   { return fNSUB; }  // library number

   Int_t          GetNuID() const { return GetNSUB(); }

   TNuMat*        GetCurMat() const { return (TNuMat*) GetCurObject(); }
   //TNuMat*        MatAt(Int_t n) const { return (n>=0 && n <= NMats()) ? (TNuMat*) fMats.At(n): 0 ; }
   //TNuObject*     At(Int_t n) const { return (TNuObject*) MatAt(n); }

   //TList*         GetMatList() const { return (TList*) &fMats; }
   //TList*         GetListOfMats() const { return (TList*) &fMats; }
   //TList*         GetCollection() const { return GetListOfMats(); }

   //Int_t          GetEntries() const { return fMats.GetEntries(); }
   Int_t          NMats() const { return GetEntries(); }

   TNuMat*        GetMat(Int_t zai) const;
   TNuMat*        GetMat(const Char_t *target) const;

   Bool_t         IsFolder() const { return kTRUE; }
   //void           Browse(TBrowser *b);

   //const Char_t*  GetPath() const;

   void           ls(Option_t* option="") const; // *MENU*
   //void           Print(Option_t *opt) const; // *MENU*

   Bool_t        IsSublib() const { return kTRUE; } // check if it is a TNuSublib 
   TNuSublib*   GetParentSublib() const { return (TNuSublib*) this; }
   TNuLib*       GetParentLib() const { return (TNuLib *) GetParent(); }

   TNuMat*        NextMat() { return (TNuMat*) TNuCollection::Next(); }

   ROOT::Internal::TRangeDynCastIterator<TNuMat> begin() const { return GetCollection()->begin(); }
   ROOT::Internal::TRangeDynCastIterator<TNuMat> end() const { return GetCollection()->end(); }

private:

   Int_t          fNSUB;     // sub-library number
   //TList          fMats;

   ClassDef(TNuSublib, 1) // A set of TNuMat elements with common NSUB
};

/*
static const struct {
      Int_t nsub;
      Char_t fullname[32];
      Char_t shortname2[8];
      Char_t shortname[8];
   } kProjNameTable[] = {
   {    0, "Photo-nuclear data",                "g",       "g"},
   {    1, "Photo-induced fission yields",      "g/fpy",   "gfy"},
   {    3, "Photo-atomic data",                 "photoat", "photo"},
   {    4, "Radioactive decay data",            "dec",     "decay"},
   {    5, "Spontenous fission yields",         "s/fpy",   "sfy"},
   {    6, "Atomic relaxation data",            "ard",     "atom"},
   {   10, "Incident neutron data",             "nn",      "n"},
   {   11, "Neutron induced fission yields",    "n/fpy",   "nfy"},
   {   12, "Thermal neutron scattering data",   "tsl",     "tsl"},
   {   19, "Standards",                         "std",     "std"},
   {  113, "Electro-atomic data",               "e",       "e"},
   {10010, "Incident proton data",              "p",       "p"},
   {10011, "Proton induced fission yields",     "p/fpy",   "pfy"},
   {10020, "Indident deuteron data",            "d",       "d"},
   {10030, "Indident triton data",              "t",       "t"},
   {20030, "Incident He3 data",                 "he3",     "he3"},
   {20040, "Incident alpha data",               "he4",     "he4"},
   {   -1, "",                                  "",        ""}
   };
*/

static const struct {
      Int_t nsub;
      Char_t fullname[32];
      Char_t shortname2[8];
      Char_t shortname[8];
   } kProjNameTable[] = {
   {    0, "Photo-nuclear_data",                "g",       "g"},
   {    1, "Photo-induced_fission_yields",      "g/fpy",   "gfy"},
   {    3, "Photo-atomic_data",                 "photoat", "photo"},
   {    4, "Radioactive_decay_data",            "dec",     "decay"},
   {    5, "Spontenous_fission_yields",         "s/fpy",   "sfy"},
   {    6, "Atomic_relaxation_data",            "ard",     "atom"},
   {   10, "Incident_neutron_data",             "nn",      "n"},
   {   11, "Neutron-induced_fission_yields",    "n/fpy",   "nfy"},
   {   12, "Thermal-neutron_scattering_data",   "tsl",     "tsl"},
   {   19, "Standards",                         "std",     "std"},
   {  113, "Electro-atomic_data",               "e",       "e"},
   {10010, "Incident-proton_data",              "p",       "p"},
   {10011, "Proton-induced_fission_yields",     "p/fpy",   "pfy"},
   {10020, "Indident-deuteron_data",            "d",       "d"},
   {10030, "Indident-triton_data",              "t",       "t"},
   {20030, "Incident-He3_data",                 "he3",     "he3"},
   {20040, "Incident-alpha_data",               "he4",     "he4"},
   {   -1, "",                                  "",        ""}
   };

#endif
