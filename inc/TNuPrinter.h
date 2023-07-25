// TNuPrinter.h  =====================================================
// Author: Tae-Sun Park   Jan 06 2012

#ifndef ROOT_TNuPrinter
#define ROOT_TNuPrinter

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuPrinter = TNuPrinter in TNudy                                   //
//                                                                    //
// The class for controling the printing of TNudy                     //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuObject.h"
#include "TNuSaveToTextDlg.h"

class TNuCont;
class TNuEndfTAB2;
class TNuTab1;
class TNuList;
//class TArrayI;
#include "TArrayI.h"

typedef union FiledWidth {  // Type of Field width
   int i;                  //integer is for TNuPrinter(console)
   float f;                  //float is for TNuCanvasPriner(GUI Editor)
} FieldWidth;  

class TNuPrinter : public TObject
{
public:

   static TNuPrinter& GetInstance() {
      if(fInstance == NULL) fInstance = new TNuPrinter;
      return *fInstance;
   }

   static TNuPrinter* GetInstancePtr() {
      if(fInstance == NULL) fInstance = new TNuPrinter;
      return fInstance;
   }
/*
   static void ReleaseInstance() {
      if(fInstance != NULL) delete fInstance;
      fInstance = 0;
   }
*/
   ~TNuPrinter() {}
   void Set(const TNuObject * const obj, Option_t *opt);
   void PrintTab1(const TNuTab1 * const obj);
   void PrintList(const TNuList * const obj);
   void PrintCont(const TNuCont * const obj);
   void PrintTAB2(const TNuEndfTAB2 * const obj);
   void PrintGraph(const TNuTab1 * const obj);

   void PrintEND(Int_t mat, Int_t mf, Int_t mt, Int_t ns, const Char_t* name = "");
   void SetOptions(Option_t* opt);
   void PrintTopInfo(const TNuObject * const obj);
   void AddIndent(Int_t n); // raise or lower the indentation
   void SetMaxLine(const Int_t n) { fMaxLines = n; } 
   void OpenSaveToTextDlg(const TNuObject* obj, ESaveMode mode=kSaveObject);
protected:
   virtual void PrintHead(const TNuObject * const obj);
   virtual void PrintLabel(const Char_t *s);
   virtual void Puts(const Char_t *s);
   virtual void PrintEndl();
   virtual void PrintText(const Char_t *s, Bool_t unused=kTRUE);
   virtual void PreparePrint() {}
   virtual void FinishPrint();
   virtual void SetOptions();

   void PrintTail(Int_t mat, Int_t mf, Int_t mt, Int_t ns = -1);
   void PrintEndfName();
   void PrintDatum(Int_t i);
   void PrintDatum(Double_t f);
   void Flush();

   //void Register(const TNuObject* const obj);
protected:
   TNuPrinter();

protected:
   TNuObject* fTopObject;
   TNuObject* fObject; //! the pointer of the current object
   Int_t      fMAT;    //! the MAT value of the object
   Int_t      fMF;     //! the MF value of the object
   Int_t      fMT;     //! the MT value of the object

   FieldWidth   fFieldWidth;    // width of one field of a record, <= 11.
   Bool_t  fNeedTail;  // if true, print MAT MF MT [NS] at the tail
// Bool_t  fNeedHead; // if true, print [MAT/MF/MT] at the lhs of the first line
   Bool_t  fNeedHead;   //fNeedHeadIDs; // if true, print [MAT/MF/MT] at the top line

   Bool_t  fNeedName; // if true, print name of the record at the top
   Bool_t  fNeedTitle; // if true, print title of the record at the tail

   Bool_t  fNeedLabel; // if true, print label of the record at the top
   Bool_t  fNeedNS;     // if or not print NS (effective only when fNeedTail = kTRUE)
   Bool_t  fNeedEndfName; // if true, print the ENDF class name (eg, CONT, TAB1, ...)
   Bool_t  fSaveToFile;   // if true, saving as file. else printing to monitor

   Bool_t  fFloatFortranStyle; // if true, "1.23456+5" instead of "1.23456E+5"
   Bool_t  fTopMargin; // if true, print empty line before printing objects

   Long_t  fStaticNS;

   Int_t   fMaxFieldsPerLine;  // maximum number of fields to be printed in one line
   Int_t   fIndent;            // indentation
   Int_t   fWritten;           // number of fields written in the current line

   Int_t   fPrintMode;      // true if printing data, not labels
   //Bool_t  fTabNBTOneColumn;  // if true, print only 1 set of (NBT,INT) per line
   //Bool_t  fTabXYOneColumn;  // if true, print only 1 set of (x,y) per line


   Int_t   fHumanity;  // 0 means original ENDF, 5 means most human-readable
   TArrayI fSeqNumbers; // for the sequential numbers
   Int_t  fMaxLines;       // maximum lines to print. Unlimited if negative
   TString fFieldSeparator; // place this string between fields of a record

private:
   static TNuPrinter* fInstance;
   TNuSaveToTextDlg* fSTTDlg;            // The instance of 'save to text' Dialog

   friend class TNuSaveToTextDlg;

   ClassDef(TNuPrinter, 1) // The class for controling the printing of TNudy
};

enum EPrintMode {
   kPrText=0,
   kPrData=1,
   kPrLabel=2
};

#endif

