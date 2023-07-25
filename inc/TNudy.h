// TNudy.h  =====================================================
// Author: Tae-Sun Park   09/18/09 (revived at Jun 29 12:48:16 2011)


#ifndef ROOT_TNudy
#define ROOT_TNudy

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TNudy                                                                     //
//                                                                           //
// The master rootT class of the TNudy (rooT NUclear Data librarY)           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TROOT.h"

class TFile;
class TNuEndfIO;
class TNuLib;
class TNuSublib;
class TNuMat;
class TNuFile;
class TNuSection;
class TNuLabel;
class TNuObject;
class TNuPrinter;
class TNuCanvasPrinter;
//class TBrowser;

class TNudy
{
private:
   static Bool_t fPrintType;

public:
   TNudy() {}
   virtual ~TNudy() {}

   static TNuLib* LoadRootFile(const Char_t *filename);
   static TNuLib* LoadRootFile(TFile *tfile);

   static TNuLib*        OpenLib(TFile *tfile, const Char_t* libName);

   static TNuLib*        ImportAsciiEndf(
                     const Char_t *libName,
                     const Char_t *libTitle,
                     const Char_t *asciiEndfFilename,
                     TFile *tfile);

   static TNuLib*        ImportAsciiEndf(
                     const Char_t *libName,
                     const Char_t *libTitle,
                     TList &filelist,
                     TFile *tfile);

   static void           ls(Option_t* option="");

   static Int_t          ZAof(const char *isotope);
   static Int_t          ZAof(const char *isotope, Int_t& iso);

   static Int_t          ZAIof(const char *isotope);
   static inline Int_t   ZAIof(Int_t z, Int_t a, Int_t iso = 0) {
                    return 10*(1000*z + a) + iso; }

   static TNuPrinter&       GetPrinter();
   static void SetPrintType(Bool_t canvas=kFALSE) { fPrintType = canvas; }

   static TList*  GetListOfLibs();
   static Int_t   GetEntries();
   static void    ShowLibs();
   static TNuLib* FindLib(const Char_t *libname);
   static TNuLib* GetLibAt(Int_t lib_pos);

   static TBrowser* GetBrowser();

   static TCanvas*   GetCanvas();
   static Bool_t     NeedsCanvasCleared() { return fNeedsCanvasCleared; }
   static void       NeedsCanvasCleared(Bool_t clear) { fNeedsCanvasCleared = clear; }

private:
   static Bool_t    fNeedsCanvasCleared; // if or not need to clear the canvas before drawing

   //NamespaceDef(TNudy, 1)
   ClassDef(TNudy, 1) // The master class
};


///////////////////////////////////////////////////////////////////////
//
//  Global variables
//
///////////////////////////////////////////////////////////////////////

static const char kChemicalSymbols[][3] = {
    "nn",
    "H" ,"He","Li","Be","B" ,"C" ,"N" ,"O" ,"F" ,"Ne","Na","Mg", // 1~12
    "Al","Si","P" ,"S" ,"Cl","Ar","K" ,"Ca","Sc","Ti","V" ,"Cr", // 13-24
    "Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr", // 25-36
    "Rb","Sr","Y" ,"Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd", // 37-48
    "In","Sn","Sb","Te","I" ,"Xe","Cs","Ba","La","Ce","Pr","Nd", // 49-60
    "Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf", // 61-72
    "Ta","W" ,"Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po", // 73-84
    "At","Rn","Fr","Ra","Ac","Th","Pa","U" ,"Np","Pu","Am","Cm", // 85-96
    "Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs", // 97-108
    "Mt","Ds","Rg" }; //109-111

R__EXTERN TList         gNuListOfLibs;     //! TList of TNuLibs

R__EXTERN TNuLib        *gNuLib;     //! pointer to current TNuLib
R__EXTERN TNuObject     *gNuObject;  //! pointer to current TNuObject

#endif
