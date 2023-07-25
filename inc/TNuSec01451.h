// TNuSec01451.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuSec01451
#define ROOT_TNuSec01451

///////////////////////////////////////////////////////////////////////////////
//
// TNuSec01451: class for MF=1 and MT=451
//
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCont.h"
//#include "TNuRecs.h"
#include "TString.h"
#include "TObjString.h"
#include "TNuSection.h"
#include "TNuDescription.h"
#include "TNuDirs.h"

//class TNuFile;
/*
class TNuEndfDir
{
public:
   TNuEndfDir() {}
   TNuEndfDir(Int_t mf, Int_t mt, Int_t nc, Int_t mod) : fMF(mf), fMT(mt), fNC(nc), fMOD(mod) {}
   virtual ~TNuEndfDir()  {}

   Int_t GetMF() const  { return fMF; }
   Int_t GetMT() const  { return fMT; }
   Int_t GetNC() const  { return fNC; }
   Int_t GetMOD() const { return fMOD; }

private:
   Int_t fMF;
   Int_t fMT;
   Int_t fNC;
   Int_t fMOD;
};
*/

//class TNuSec01451 : public TNuRecs
class TNuSec01451 : public TNuSection
{
public:
   TNuSec01451() : TNuSection() {}
   TNuSec01451(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSec01451();

   //void      Init();

   Int_t     GetMF() const   { return 1; }
   Int_t     GetMT() const   { return 451; }


   void        ShowDescription() const;
   void        ShowDir() const;
   //TObjString* DescriptionAt(Int_t i) { return (TObjString*) fDescription[i]; }
   const Char_t* DescriptionAt(Int_t i) { return  GetDescription()->At(i); }
   //TNuCont*    DirAt(Int_t i) { return (TNuCont*) fDirs[i]; }
   TNuCont*    DirAt(Int_t i) { return (TNuCont*) GetDirs()->GetContAt(i); }
   //TObjArray&  GetDescription() { return fDescription; }
   TNuDescription*  GetDescription() { return (TNuDescription*) BodyFirst(); }
   //TObjArray&  GetDirs() { return fDirs; }
   TNuDirs*      GetDirs() { return (TNuDirs*) TailLast(); }

   void     ImportEndfData(TNuEndfIO& src);

private:
   Int_t        fNWD; //number of description lines
   Int_t        fNXC; //number of directories
   //TObjArray    fDescription; //
   //TObjArray    fDirs;        //

   ClassDef(TNuSec01451, 1)  // General description
};

#endif

