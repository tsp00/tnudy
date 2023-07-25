// TNuSection.h  =====================================================
// Author: Tae-Sun Park   Jun 13 2011

#ifndef ROOT_TNuSection
#define ROOT_TNuSection

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSection (default class for a section data)                      //
//                                                                    //
// TNuSection.cxx:                                                    //
// Routine to handle a ENDF Section                                   //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuRecs.h"
//#include "TNuFile.h"

class TNuFile;
class TNuMat;
class TNuSublib;
class TNuLib;
class TNuEndfIO;

class TNuSection : public TNuRecs
{
public:
   TNuSection();
   TNuSection(Int_t mat, Int_t mf, Int_t mt);
   virtual ~TNuSection();

   void           What() const; // *MENU*

   Short_t        GetMT() const     { return fMT; }
   Short_t        GetMF() const     { return fMF; }
   Int_t          GetMFT() const    { return 1000*fMF + fMT; }
   Short_t        GetMAT() const    { return fMAT; }

   Int_t          GetZA() const     { return (Int_t) HeadCont()->GetC1() + 0.5; }
   Int_t          GetZ() const      { return GetZA() / 1000; }
   Int_t          GetA() const      { return GetZA() % 1000; }
   Int_t          GetN() const      { return GetA() - GetZ(); }
   Double_t      GetAWR() const    { return HeadCont()->GetC2(); }

   Double_t      GetMassExcess() const; // mass excess in AMU
   Double_t      GetBindingEnergy() const; // (N*m_n + Z*m_p - m)*c^2 in eV

   Int_t         GetNuID() const      { return GetMFT(); }

   void           ls(Option_t* option="") const; // *MENU*
   void           Print(Option_t *opt) const; // *MENU*

   //static const Char_t* GetDefSymbolTitle(Int_t mt);
   static const Char_t*  GetDefSymbol(Int_t mt);
   static const Char_t*  GetDefTitle(Int_t mt);
   virtual const Char_t* GetFigTitle() const;
   virtual const Char_t* GetChannelSymbol() const;
   static void   GetDefSymbolTitle(Int_t mt, const Char_t*& symbol, const Char_t*& title);

   const Char_t* GetSymbol() const;

   static TNuSection*   CreateSection(TNuEndfIO& src, TNuFile* pFile, Int_t mf, Int_t mt);

   virtual void  ImportEndfData(TNuEndfIO& src);

   Bool_t         IsSection() const { return kTRUE; }// check if it is a TNuSection 
   TNuSection*    GetParentSection() const { return (TNuSection*) this; }
   TNuFile*       GetParentFile() const { return (TNuFile*) GetParent(); }
   //TNuMat*        GetParentMat() const { return GetParentFile()->GetParentMat(); }
   //TNuSublib*    GetParentSublib() const { return GetParentFile()->GetParentSublib(); }
   //TNuLib*        GetParentLib() const { return GetParentFile()->GetParentLib(); }

protected:
   Short_t        fMAT;  // MAT number of the section
   Short_t        fMF;   // MF number of the section
   Short_t        fMT;   // MT number of the section


   ClassDef(TNuSection, 1) // Class for the ENDF SECTION data
};

#endif

