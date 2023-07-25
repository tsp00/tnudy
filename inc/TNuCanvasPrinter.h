// TNuPrinter.h  =====================================================
// Author: Ki-Hong Lee     Aug 26 2012

#ifndef ROOT_TNuCanvasPrinter
#define ROOT_TNuCanvasPrinter

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuCanvasPrinter = TNuCanvasPrinter in TNudy                       //
//                                                                    //
// The class for controling the printing of TNudy on Canvas           //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuPrinter.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TGLabel.h"
#include "TGMenu.h"
#include "TLatex.h"
#include "TLine.h"
#include "TBox.h"
#include <RQ_OBJECT.h>

class TNuCanvasPrinter : public TNuPrinter {
   RQ_OBJECT("TNuCanvasPrinter")

public:
   static TNuCanvasPrinter& GetInstance() {
      if(fInstance == NULL) fInstance = new TNuCanvasPrinter();
      return *fInstance;
   }

   static TNuCanvasPrinter* GetInstancePtr() {
      if(fInstance == NULL) fInstance = new TNuCanvasPrinter();
      return fInstance;
   }

   ~TNuCanvasPrinter() {}

   void ResizeCanvas();
   void SetCounting(Bool_t count=kTRUE);
   void HandleMenu(Int_t id);
protected:
   virtual void PrintHead(const TNuObject * const obj);
   virtual void PrintLabel(const Char_t *s);
   virtual void Puts(const Char_t *s);
   virtual void PrintEndl();

   virtual void PrintText(const Char_t *s, Bool_t coloring=kTRUE);
   virtual void PreparePrint();     // prepare drawing
   virtual void FinishPrint();      // finish up drawing
   virtual void SetOptions();
private:
   static TNuCanvasPrinter* fInstance;
   TNuCanvasPrinter();
   void     PrepareCanvas();
   void     DrawText(Double_t x, Double_t y, const Char_t *s) { fLatex.DrawText(x, y, s); }
   void     LabelColoring();void    SetTextAttr(Int_t font, Int_t align, Color_t color);
   void     DrawVLines();        // draw vertical lines
   void     DrawHLines();        // draw horizontal lines
   Double_t GetPosX() { return GetPosX(fFieldWidth.f); }
   Double_t GetPosX(Double_t fieldWidth) { return fPosX += fieldWidth; }
   Double_t GetPosY() { return 1.0 - fTextLines*fLineSpace; }

   TRootCanvas* fRootCanvas;
   TCanvas* fCanvas;
   TLatex   fLatex;           // tool of drawing text
   TBox     fBox;             // tool of drawing text background(coloring)
   TLine    fLine;            // tool of drawing lines
   Int_t    fTextLines;       // current number of lines
   Int_t    fTotalLines;      // total number of lines
   Int_t    fSkipLines;       // count skip lines
   Int_t    fLocalStartNum;

   Float_t  fLineSpace;       // space(margin) of each line

   Double_t fPosX;
   Char_t   fTitle[100];
   Bool_t   fCounting;        // if true, count the lines, else draw text
   Bool_t   fColoring;        // for striped pattern(background)
   Bool_t   fPrintSkip;       // if true, skip to draw text

   ClassDef(TNuCanvasPrinter,0)  // Class for controling the printing of TNudy on Canvas
};
#endif

