// TNuPrinter.cxx  =====================================================
// Author: Tae-Sun Park   Jan 06 2012


////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuPrinter = TNuPrinter in TNudy                                   //
//                                                                    //
// The class for controling the printing of TNudy                     //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuPrinter.h"

#include "TString.h"

#include "TNuCont.h"
#include "TNuEndfTAB2.h"
#include "TNuTab1.h"
#include "TNuList.h"

#include "TNudy.h"
#include "TNuLib.h"
#include "TNuMat.h"
#include "TNuSection.h"
#include "TNuLabel.h"

#include "TGFrame.h"
#include "TMath.h"

#include <stdlib.h>
#include <iostream>
#include <iomanip>

ClassImp(TNuPrinter)

TNuPrinter* TNuPrinter::fInstance=NULL;

//______________________________________________________________________________
TNuPrinter::TNuPrinter() : fObject(0), fMAT(0), fMF(0), fMT(0), fHumanity(3)
{
   // TNuPrinter ctor

   fNeedHead = kTRUE; // if true, print [MAT/MF/MT] at the top line

   fTopMargin= kTRUE; // if true, print empty line before printing objects

   fFieldWidth.i = 11;    // width of one field of a record, <= 11.
   fNeedTail =kTRUE;  // if true, print MAT MF MT [NS] at the tail
// fNeedHead =kFALSE; // if true, print [MAT/MF/MT] at the lhs of the first line

   fNeedName =kTRUE; // if true, print name of the record at the tail
   fNeedTitle=kFALSE; // if true, print title of the record at the tail
   fNeedLabel=kFALSE; // if true, print label of the record at the top
   fNeedNS=kTRUE;     // if or not print NS (effective only when fNeedTail = kTRUE)
   fNeedEndfName=kTRUE; // if true, print the ENDF class name (eg, CONT, TAB1, ...)
   fSaveToFile=kFALSE;
   //fPrintEndl=kTRUE; // if true, print a newline before every record


   fFieldSeparator=""; // place this string between fields of a record
   fFloatFortranStyle=kFALSE; // if true, "1.23456+5" instead of "1.23456E+5"
   fMaxLines=-1;              // maximum lines to print. Unlimited if negative

   fStaticNS=0;
   fMaxFieldsPerLine = 6;  // maximum number of fields to be printed in one line
   fIndent = 0;

   fPrintMode = kPrText;      // true if printing data, not labels
   //fTabNBTOneColumn = kFALSE;  // if true, print only 1 set of (NBT,INT) per line
   //fTabXYOneColumn = kFALSE;  // if true, print only 1 set of (x,y) per line

   fSeqNumbers.Set(64);

   TGMainFrame* mf = new TGMainFrame();
   fSTTDlg = new TNuSaveToTextDlg(mf);
}

//______________________________________________________________________________
void TNuPrinter::SetOptions()
{
   // Set print options and
   // initialize fMAT, fMF, fMT, fNS

   Int_t h = fHumanity;// for simple typing

   //fNeedHeadIDs =       (h >= 3) ? kTRUE : kFALSE; // if true, print [MAT/MF/MT] at the top line
   fTopMargin =         (h >= 3) ? kTRUE : kFALSE;
   fNeedTail =          (h >= 3) ? kFALSE : kTRUE;
   fNeedHead =          (h >= 3) ? kTRUE : kFALSE;
   fNeedName =          (h >= 3) ? kTRUE : kFALSE;
   fNeedTitle =         (h >= 3) ? kTRUE : kFALSE;
   fNeedLabel =         (h >= 3) ? kTRUE : kFALSE;
   fNeedNS =            (h >= 3) ? kFALSE : kTRUE;
   fNeedEndfName =      (h >= 3) ? kTRUE : kFALSE;
   fFieldSeparator =    (h >= 3) ? " " : "";
   fFloatFortranStyle = (h >= 3) ? kFALSE : kTRUE;
   //fMaxLines =          (h >= 3) ? 30 : -1;
   //fTabNBTOneColumn =   (h >= 3) ? kTRUE : kFALSE;
   //fTabXYOneColumn =    (h >= 4) ? kTRUE : kFALSE;

   fFieldWidth.i = 11;
   fMaxFieldsPerLine = 6;
   fStaticNS  = 0;
   fIndent = 0;
   fWritten = 0;
   fSaveToFile=kFALSE;
}

//______________________________________________________________________________
void TNuPrinter::SetOptions(Option_t* opt)
{
   // Set print options and
   // initialize fMAT, fMF, fMT, fNS

   //fFieldWidth = 11;
   //fMaxFieldsPerLine = 6;
   fStaticNS  = 0;
   fIndent = 0;
   fWritten = 0;
   if (!opt) return;

   if (!strcmp(opt, "") || !strcmp(opt, "--default"))  {
      fHumanity = 3;
   }
   else if (!strcmp(opt, "txt")) {
      fHumanity = 5;
   }
   else if (!strcmp(opt, "--ENDF")) {
      fHumanity = 0;
   }
   else if (strlen(opt)== 1 && isdigit(*opt)) {
      fHumanity = *opt - '0';
      if (fHumanity < 0) fHumanity = 0;
      if (fHumanity > 5) fHumanity = 5;
   }
   SetOptions();
   if (!strcmp(opt, "txt")) {
      fFloatFortranStyle=kFALSE;
      fSaveToFile=kTRUE;
   }
}


//--------------- high level printing routines ---------------------------------


//______________________________________________________________________________
void TNuPrinter::Set(const TNuObject * const obj, Option_t *opt)
{
   // Sets fObject = obj and get its MAT/MF/MT values
   // If opt != "-", set the options and
   // and prints the head [MAT/MF/MT] if fNeedHead==kTRUE

   if(opt!=NULL) {
      fObject = (TNuObject*) obj;

      TNuObject* parent = (TNuObject*) obj;
      while (parent && !parent->InheritsFrom("TNuSection"))
         parent= parent->GetParent();

      fMAT=0; fMF=0; fMT=0;
      if (parent) {
         fMAT= ((TNuSection*) parent)->GetMAT();
         fMF=  ((TNuSection*) parent)->GetMF();
         fMT=  ((TNuSection*) parent)->GetMT();
      }
      if (strcmp(opt, "-")) {
         SetOptions(opt);
         PrintHead(obj);
         fStaticNS = 0;
         fTopObject = (TNuObject*) obj;
      } else {
      }
      fWritten = 0;
      fSeqNumbers[fIndent]++;
   }
}

//______________________________________________________________________________
void TNuPrinter::PrintHead(const TNuObject * const obj)
{
   if (fNeedHead) {
      using namespace std;
      cout << endl;
      cout << "[" << setw(4) << fMAT << "/" << setw(2) << fMF << "/" << setw(3) << fMT << "] ";
      if (fNeedName)
         cout << obj->GetName() << " of " << obj->ClassName();
      cout << endl;
   }
}


//______________________________________________________________________________
void TNuPrinter::PrintTopInfo(const TNuObject * const obj)
{
   // prints a TNuCont element
   if (fTopMargin) PrintEndl();

   fMaxFieldsPerLine = 0;
   if (fNeedName) {
      TString info = "  ";

      for (Int_t i=1; i <= fIndent; i++)
         info.Append(Form("%d.", fSeqNumbers[i]-1));

      if(info.EndsWith("."))
         info.Append(" ");

      info.Append(Form("%s (%4d/%2d/%3d)", obj->GetName(), fMAT, fMF, fMT));

      PrintText(info);
      PrintEndl();
   }
}

//______________________________________________________________________________
void TNuPrinter::PrintCont(const TNuCont * const obj)
{
   // prints a TNuCont element
   PrintTopInfo(obj);

   //fMaxFieldsPerLine = 6 + 999; // enforce the Flush be not invoked.
   fMaxFieldsPerLine = 6;

   PreparePrint();
   TNuLabel *label = obj->GetLabel();
   if (fNeedLabel) {
      for (Int_t n=0; n< 6; n++) {
         PrintLabel(label->HeadAt(n));
      }
      if (fNeedEndfName) {
         TString s(fObject->GetEndfName());
         if (fSeqNumbers[fIndent] == 0) {
            if (fObject->InheritsFrom("TNuSection"))
               s = "HEAD";
         }

         PrintText(s.Insert(0, "   "));
      }
      Flush();
   }

   PrintDatum(obj->GetC1());
   PrintDatum(obj->GetC2());
   PrintDatum(obj->GetL1());
   PrintDatum(obj->GetL2());
   PrintDatum(obj->GetN1());
   PrintDatum(obj->GetN2());

   FinishPrint();
}

//______________________________________________________________________________
void TNuPrinter::PrintTAB2(const TNuEndfTAB2 * const obj)
{
   // prints a TNuEndfTAB2 element

   PrintCont((TNuCont*) obj);

   if (fHumanity >= 3) {
      fMaxFieldsPerLine = 2;
      PreparePrint();
      PrintLabel("NBT");
      PrintLabel("INT");
      Flush();
   }
   else {
      fMaxFieldsPerLine = 6;
      PreparePrint();
   }
   for (Int_t n=0; n < obj->GetN1(); n++) {
      PrintDatum(obj->GetNBT(n));
      PrintDatum(obj->GetINT(n));
   }

   FinishPrint();
}

//______________________________________________________________________________
void TNuPrinter::PrintTab1(const TNuTab1 * const obj)
{
   // prints a TNuTab1 element
   PrintTAB2(obj);
   fMaxFieldsPerLine = (fHumanity >= 4) ? 2 : 6;

   PreparePrint();
   if (fHumanity >= 3) {
      for (Int_t n=0; n < fMaxFieldsPerLine/2; n++) {
         PrintLabel("X");
         PrintLabel("Y");
      }
      Flush();
   }

   for (Int_t n=0; n < obj->GetN2(); n++) {
      PrintDatum(obj->GetX(n));
      PrintDatum(obj->GetY(n));
      if (fWritten == fMaxFieldsPerLine) Flush();
   }
   FinishPrint();
}

//______________________________________________________________________________
void TNuPrinter::PrintList(const TNuList * const obj)
{
   // prints a TNuList element

   PrintCont((TNuCont*) obj);

   TNuLabel *label = obj->GetLabel();

   Int_t data_labels = label->NBodies();
   Int_t tail_labels = label->NTails();

   Int_t n1 = (tail_labels) ? data_labels : obj->GetNPL();

   fMaxFieldsPerLine = (data_labels>0 && data_labels < 6) ? data_labels : 6;
   PreparePrint();
   // print aux labels an aux data, if any
   if (fNeedLabel && data_labels) {
      for (Int_t n=0; n < data_labels; n++) {
         PrintLabel(label->BodyAt(n));
         if (fWritten == fMaxFieldsPerLine) Flush();
      }
      Flush();
   }

   for (Int_t n=0; n < n1; n++) {
      PrintDatum(obj->At(n));
      if (fWritten == fMaxFieldsPerLine) Flush();
   }

   FinishPrint();

   fMaxFieldsPerLine = (tail_labels>0 && tail_labels < 6) ? tail_labels : 6;
   PreparePrint();
   // print data labels if any
   if (fNeedLabel && tail_labels) {
      for (Int_t n=0; n < tail_labels; n++) {
         PrintLabel(label->TailAt(n));
      if (fWritten == fMaxFieldsPerLine) Flush();
      }
      Flush();
   }

   // print remaining data
   for (Int_t n=n1; n < obj->GetNPL(); n++) {
      PrintDatum(obj->At(n));
      if (fWritten == fMaxFieldsPerLine) Flush();
   }
   FinishPrint();
}


//______________________________________________________________________________
void TNuPrinter::PrintGraph(const TNuTab1 * const obj)
{
   //print graph data

   fMaxFieldsPerLine = 2;
   Double_t *x, *y;
   Int_t size = obj->GetInterpolatedXY(&x, &y);
   PrintLabel("X");
   PrintLabel("Y");
   Flush();

   for (Int_t n=0; n<size; n++) {
      PrintDatum(x[n]);
      PrintDatum(y[n]);
      Flush();
   }

   delete[] x;
   delete[] y;
}
//--------------- low level printing routines  ---------------------------------

//______________________________________________________________________________
void TNuPrinter::OpenSaveToTextDlg(const TNuObject* obj, ESaveMode mode)
{
   fSTTDlg->Open(obj, mode);
}

//______________________________________________________________________________
void TNuPrinter::PrintEndfName()
{
   if (fNeedEndfName && fObject->GetEndfName())
      PrintText(fObject->GetEndfName());
}

//______________________________________________________________________________
void TNuPrinter::PrintDatum(Int_t i)
{
   // print an int
   fPrintMode = kPrData;
   Puts(Form("%d",i));
}

//______________________________________________________________________________
void TNuPrinter::PrintDatum(Double_t f)
{
   // print a float
   Char_t s[14];

   if(fFloatFortranStyle==kTRUE) {
      sprintf(s,"%11.5e",f);
      const char * e_str = strchr(s, 'e');
      char expo[5]; // exponent with sign, e.g., +5, -12, ..., but not +04, -012
      int exponent = atoi(e_str+1);
      sprintf(expo, "%+d", exponent);
      int elen = strlen(expo);
      const char *fmt =
         (elen == 2) ? "%9.6f%s" : // [ 0.123456+7], [-0.123456-8]
         (elen == 3) ? "%8.5f%s" : // [ 0.12345+12]. [-0.12345+99]
         "%f%s";
      sprintf(s, fmt, f / TMath::Power(10, exponent), expo);
   } else {
      sprintf(s,"%11.4e",f);
   }

   fPrintMode = kPrData;
   Puts(s);
}

//______________________________________________________________________________
void TNuPrinter::PrintLabel(const Char_t *s)
{
   // print label
   fPrintMode = kPrLabel;
   Puts(s);
}

//______________________________________________________________________________
void TNuPrinter::PrintText(const Char_t *s, Bool_t /*unused*/)
{
   // print a string
   //fPrintMode = kPrText;
   if(fWritten!=0)
      std::cout << fFieldSeparator;
   std::cout << s;
}

//______________________________________________________________________________
void TNuPrinter::Puts(const Char_t *s)
{
   // print a string s
   /*
   if (fWritten >=  fMaxFieldsPerLine) {
      fprintf(stderr, "\nError in TNuPrinter::Puts: "
         "Too many fields, %d for %d\n", fWritten, fMaxFieldsPerLine);
      //Flush();
   }
   */

   if (fWritten==0) {
      std::cout << ((fPrintMode == kPrLabel) ?  "!" : " ");
   } else {
     std::cout << fFieldSeparator;
   }

   //if(fSaveToFile==kFALSE)
   //std::cout << std::setw(fFieldWidth.i);
   //std::cout << s;

   std::cout << std::setw(fFieldWidth.i) << s;
   fWritten++;
}


//______________________________________________________________________________
void TNuPrinter::Flush()
{
   // flush : print tail infos and line feed, if fWritten > 0
   if (fWritten) {
      for (Int_t n=fWritten; n < fMaxFieldsPerLine; n++)
         Puts("");

      if(fPrintMode == kPrData)
         PrintTail(fMAT, fMF, fMT);
      PrintEndl();
   }
}

//______________________________________________________________________________
void TNuPrinter::PrintEndl()
{
   // print new line
   fWritten = 0;
   std::cout << std::endl;
}

//______________________________________________________________________________
void TNuPrinter::PrintTail(Int_t mat, Int_t mf, Int_t mt, Int_t ns)
{
   // print MAT/MF/MT/NS
   fStaticNS++;
   if (ns < 0) ns = fStaticNS;
   if (fNeedTail) {
      Char_t* tail = Form("%7d %2d %3d", mat, mf, mt);

      if (fNeedNS){
         tail = Form("%s %5d", tail, ns);
      }
      PrintText(tail, kFALSE);
   }
}

//______________________________________________________________________________
void TNuPrinter::PrintEND(Int_t mat, Int_t mf, Int_t mt, Int_t ns, const Char_t* name)
{
   // print END line with MAT/MF/MT/NS
   fMaxFieldsPerLine = 6;
   PreparePrint();

   for (Int_t i=0; i < 2; i++)
      PrintDatum(0.0);

   for (Int_t i=0; i < 4; i++)
      PrintDatum(0);

   if (fNeedTail) {
      Char_t* tail = Form("%7d %2d %3d", mat, mf, mt);

      if (fNeedNS)
         tail = Form("%s %5d", tail, ns);
      PrintText(tail, kFALSE);
   }

   if (fNeedEndfName && name)
      PrintText(Form("   %s", name));

   FinishPrint();
}

//______________________________________________________________________________
void TNuPrinter::AddIndent(Int_t n)
{
   // raise/lower the indentation

   if (n > 1 || n < -1) {
      fprintf(stderr, "Warning in AddIndent : Too big change in indentation, n = %d", n);
   }

   fIndent += n;
   if (fIndent < 0) {
      fprintf(stderr, "Warning in AddIndent : The resulting indentation = %d is negative", fIndent);
      fIndent = 0;
   }
   if (n>0) fSeqNumbers[fIndent] = 0;
}

//______________________________________________________________________________
void TNuPrinter::FinishPrint()
{
   Flush();
   PrintEndl();
}
