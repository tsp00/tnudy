// TNuCanvasPrinter.cxx  =====================================================
// Author: Ki-Hong Lee   Aug 26 2012


////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuCanvasPrinter = TNuCanvasPrinter in TNudy                       //
//                                                                    //
// The class for controling the printing of TNudy on Canvas           //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include <fcntl.h>
#include "TNuCanvasPrinter.h"

#include "TNuCont.h"
#include "TNuEndfTAB2.h"
#include "TNuTab1.h"
#include "TNuList.h"

#include "TNudy.h"
#include "TNuLib.h"
#include "TNuMat.h"
#include "TNuSection.h"
#include "TNuLabel.h"
#include "TGMenu.h" 

ClassImp(TNuCanvasPrinter)


enum ECanvasPrintCommandIdentifiers {
   M_FILE_SAVETOTEXT = 1001,
};

TNuCanvasPrinter* TNuCanvasPrinter::fInstance=NULL;
//______________________________________________________________________________
TNuCanvasPrinter::TNuCanvasPrinter() : fCanvas(NULL), fTextLines(0), fTotalLines(0), fSkipLines(0), fLocalStartNum(0), fLineSpace(0.0), fCounting(kFALSE), fColoring(kFALSE), fPrintSkip(kFALSE) 
{
   // TNuCanvasPrinter ctor
   SetTextAttr(42, 32, 0);
   fBox.SetFillColor(18);
   fLine.SetLineColor(14);
   fMaxLines=200;
}

//--------------- high level printing routines ---------------------------------

//______________________________________________________________________________
void TNuCanvasPrinter::PrepareCanvas() {
   Float_t lineSpace = 1.4f;
   Double_t h;
   if(fTotalLines < fMaxLines) {
      h = fTotalLines * lineSpace;
   } else {
      h = (fMaxLines+4) * lineSpace;
   }
   Double_t ratio = 1.0 / h;
   
   if(ratio > 0.01)    ratio = 0.01;
   fLatex.SetTextSize(ratio);
   fLineSpace = ratio*lineSpace;
   fFieldWidth.f = ratio*7;
   fCanvas = (TCanvas*)(gROOT->GetListOfCanvases())->FindObject(fTitle);
   if (fCanvas==0) {
      fCanvas = new TCanvas(fTitle, fTitle, 1000, 800);
      fRootCanvas = (TRootCanvas *)(fCanvas->GetCanvasImp());
      TGPopupMenu* pm = fRootCanvas->GetMenuBar()->GetPopup("File");
      
      pm->AddEntry("Save to Text", M_FILE_SAVETOTEXT, 0, 0, pm->GetEntry("Save As..."));
      pm->Connect("Activated(Int_t)", "TNuCanvasPrinter", this, "HandleMenu(Int_t)");
   } else {
      fCanvas->SetEditable(kTRUE);
      fCanvas->Clear();
   }
   fCanvas->SetCanvasSize(800, 800);
   fTextLines = 0;
   fSkipLines = 0;
   fLocalStartNum = 0;
   fColoring = kFALSE;
   fPrintSkip = kFALSE;
   fPrintMode = kPrText;
   PrintEndl();
}


//______________________________________________________________________________
void TNuCanvasPrinter::HandleMenu(Int_t id)
{
   if(id==M_FILE_SAVETOTEXT) {
      OpenSaveToTextDlg(fTopObject);
   }
}

//______________________________________________________________________________
void TNuCanvasPrinter::PrintHead(const TNuObject * const obj)
{
   sprintf(fTitle, "[%d/%d/%d] %s of %s", fMAT, fMF, fMT, obj->GetName(), obj->ClassName());
}

//______________________________________________________________________________
void TNuCanvasPrinter::SetCounting(Bool_t count)
{
   // counting the number of lines to be printed
   fCounting = count;
   if(count) {
      fTotalLines=0;
      fPrintSkip=kTRUE;
   } else {
      //printf("total line:%d\n", fTotalLines);
      PrepareCanvas();
   }
}


//______________________________________________________________________________
void TNuCanvasPrinter::SetOptions()
{
   TNuPrinter::SetOptions();
   fTopMargin = kFALSE;
}

//______________________________________________________________________________
void TNuCanvasPrinter::ResizeCanvas()
{
   Double_t ratio = 0.02/ fLatex.GetTextSize();
   if(ratio > 1.01)
      fCanvas->SetCanvasSize((UInt_t)(fCanvas->GetWw()*ratio),(UInt_t)(fCanvas->GetWh()*ratio));
   fCanvas->SetEditable(kFALSE);

   //printf("canvas w:%d, h:%d\n", fCanvas->GetWw(), fCanvas->GetWh());
   //   fCanvas->SetWindowSize(600, 800);
}

//--------------- low level printing routines  ---------------------------------

//______________________________________________________________________________
void TNuCanvasPrinter::LabelColoring()
{
   Double_t dx = fLatex.GetTextSize();
   Double_t dy = fLineSpace/2;
   fBox.DrawBox(fPosX+dx, GetPosY()-dy, fPosX+fFieldWidth.f+dx, GetPosY()+dy);
}


//______________________________________________________________________________
void TNuCanvasPrinter::SetTextAttr(Int_t font, Int_t align, Color_t color) {
   if(font) fLatex.SetTextFont(font);
   if(align) fLatex.SetTextAlign(align);
   if(color) fLatex.SetTextColor(color);
}

//______________________________________________________________________________
void TNuCanvasPrinter::PrintLabel(const Char_t *s)
{
   // print a label
   //fPosX-=fFieldWidth.f/3;
   SetTextAttr(32, 32, 46);
   TNuPrinter::PrintLabel(s);
   SetTextAttr(42, 32, 1);
   //fPosX+=fFieldWidth.f/3;
}


//______________________________________________________________________________
void TNuCanvasPrinter::PrintText(const Char_t *s, Bool_t coloring)
{
   
   if(fWritten==0)
      fPrintMode = kPrText;

   Int_t font=0;
   Color_t color=0;
   if(coloring) {
      font=22;
      color=kMagenta+3;
   }
   SetTextAttr(font, 12, color);

   Float_t dx = fFieldWidth.f*0.9;
   fPosX -= dx;
   Puts(s);
   SetTextAttr(42, 32, 1);
   fPosX += dx;
}

//___________________________________________________________________________
void TNuCanvasPrinter::Puts(const Char_t *s)
{
   // print a string s
   if( !fPrintSkip ) {
      if(fColoring && fPrintMode==kPrData && fWritten<fMaxFieldsPerLine) 
         LabelColoring();

      DrawText(GetPosX(), GetPosY(), s);
   }
   fWritten++;
}

//______________________________________________________________________________
void TNuCanvasPrinter::PrintEndl()
{
   // new line
   if(fCounting) {
      ++fTotalLines;
   } else {
      fPosX=fLatex.GetTextSize()*2; //initialize fPosX

      if(fTotalLines <= fMaxLines || fTextLines < fMaxLines-20-1 
            || (fTextLines+fSkipLines-3+1)>=fTotalLines-20) {
         
         if(fPrintSkip==kTRUE){
            //printf("skip lines:%d\n", fSkipLines);
            fLocalStartNum++;
         }
         
         if(fPrintMode != kPrText && fPrintSkip==kFALSE)
            DrawHLines();

         fPrintSkip = kFALSE;
         fTextLines++; 
         if(fPrintMode==kPrData) {
            fColoring=!fColoring;
         } else {
            fColoring=kFALSE;
         }
      } else {
         if(fSkipLines==0) {
            DrawHLines();
            fTextLines+=1;
            DrawHLines();
            DrawVLines();
            fTextLines+=1;
            SetTextAttr(32, 22, kRed+3);
            Double_t posX=fLatex.GetTextSize()*(fMaxFieldsPerLine+2)*3;
            DrawText(posX, GetPosY(), Form("... ... (%d lines skipped.)", fTotalLines-fMaxLines));
            fTextLines+=1;
            SetTextAttr(42, 32, 1);
            fLocalStartNum = fTextLines;
            fPrintSkip = kTRUE;
         }
         ++fSkipLines;
      }
   }
   fWritten = 0;
}

//______________________________________________________________________________
void TNuCanvasPrinter::PreparePrint()
{
   fLocalStartNum = fTextLines;
   DrawHLines();
}

//______________________________________________________________________________
void TNuCanvasPrinter::FinishPrint()
{
   Flush();
   DrawVLines();
   PrintEndl();
}

//______________________________________________________________________________
void TNuCanvasPrinter::DrawVLines()
{
   if(fPrintSkip==kFALSE) {
      Int_t lines = fLocalStartNum-fTextLines;

      Double_t posX = fPosX+fLatex.GetTextSize();
      Double_t posY2 = GetPosY() + fLineSpace/2;
      Double_t posY1 = posY2 - fLineSpace*lines;

      for(int i=0;i<=fMaxFieldsPerLine;i++) {
         fLine.DrawLine(posX, posY1, posX, posY2);
         posX+=fFieldWidth.f;
      }
   }
}      

//______________________________________________________________________________
void TNuCanvasPrinter::DrawHLines()
{
   if(fPrintSkip==kFALSE) {
      Double_t posX = fPosX+fLatex.GetTextSize();
      Double_t posY = GetPosY() + fLineSpace/2;
      fLine.DrawLine(posX, posY, posX + fFieldWidth.f*fMaxFieldsPerLine, posY);
   }      
}
