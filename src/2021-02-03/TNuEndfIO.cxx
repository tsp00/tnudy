//  TNuEndxIO.cxx  =====================================================
// @(#)root/meta:$Id: TNuEndfIO.cxx 29000 2009-06-15 13:53:52Z rdm $
// Author: Tae-Sun Park   09/18/09

/**********************************************************************
 **********************************************************************/


////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuEndfIO (NUclear Data librarY IO routines)                       //
//                                                                    //
// TNuEndfIO.cxx:                                                     //
// Routine to handle a single ENDF file                               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuEndfIO.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "TROOT.h"
#include "TString.h"

ClassImp(TNuEndfIO)

//______________________________________________________________________________
TNuEndfIO::TNuEndfIO(const Char_t *srcfSrcFilename, Bool_t do_warn)
: fIsEndfTape(kFALSE), fFP(0), fSrcFilename(0), fMAT(0), fMF(0), fMT(0), \
  fNS(0), fLineNum(0), fPos(0), fHasEOF(kFALSE)
{
   // TNuEndfIO ctor

   fTitle[0] = 0;
   
   fSrcFilename=new char[strlen(srcfSrcFilename)+1];
   strcpy(fSrcFilename, srcfSrcFilename);
   fFP = fopen(srcfSrcFilename, "r");
   if (fFP == NULL) {
      if (do_warn)
         Error("TNuEndfIO::TNuEndfIO", "Cannot open the file %s", srcfSrcFilename);
      return;
   }

   ScanNextLine(do_warn);
   if (GetMF() != 1 || GetMT() != 451) {
      strncpy(fTitle, fLine, 80);
      fTitle[80] = '\0';
      ScanNextLine(do_warn);
   }
   if (GetMF() != 1 || GetMT() != 451) {
      if (do_warn)
         Error("TNuEndfIO::TNuEndfIO", "%s is not an ENDF file, MF=%d, MT=%d", srcfSrcFilename, GetMF(), GetMT());
      // fFP=NULL; // why I inserted this line ??
      return;
   }
   fIsEndfTape = kTRUE;
}

//______________________________________________________________________________
TNuEndfIO::~TNuEndfIO()
{
   // TNuEndfIO dtor

   if (fSrcFilename) delete[] fSrcFilename;
   if (fFP) fclose(fFP);
}


//----------------  Low-level IO routines  -------------------------------------
//______________________________________________________________________________
void TNuEndfIO::ReadSEND()
{
   // Read SEND line

   if(!IsSEND()) {
      Error("TNuEndfIO::ReadSEND",
      "%ld-th line is not SEND, skipping to next SEND ...", fLineNum);
      GotoSEND();
   }
   ScanNextLine();
}

//______________________________________________________________________________
void TNuEndfIO::ReadFEND()
{
   // Read FEND line

   if(!IsFEND()) {
      Error("TNuEndfIO::ReadFEND",
      "%ld-th line is not FEND, skipping to next FEND ...", fLineNum);
      GotoFEND();
   }
   ScanNextLine();
}

//______________________________________________________________________________
void TNuEndfIO::ReadMEND()
{
   // Read MEND line

   if(!IsMEND()) {
      Error("TNuEndfIO::ReadMEND",
      "%ld-th line is not MEND, skipping to next MEND ...", fLineNum);
      GotoMEND();
   }
   ScanNextLine();
}


//______________________________________________________________________________
void TNuEndfIO::ReadCONT(
   Double_t *c1, Double_t *c2, Int_t *l1, Int_t *l2, Int_t *n1, Int_t *n2)
{

   if (c1) *c1 = Atof(fLine + 0 * 11);
   if (c2) *c2 = Atof(fLine + 1 * 11);
   if (l1) *l1 = Atoi(fLine + 2 * 11, 11, 0);
   if (l2) *l2 = Atoi(fLine + 3 * 11, 11, 0);
   if (n1) *n1 = Atoi(fLine + 4 * 11, 11, 0);
   if (n2) *n2 = Atoi(fLine + 5 * 11, 11, 0);
   ScanNextLine();
}

//______________________________________________________________________________
void TNuEndfIO::ReadCONT(
   Double_t &c1, Double_t &c2, Int_t &l1, Int_t &l2, Int_t &n1, Int_t &n2)
{

   c1 = Atof(fLine + 0 * 11);
   c2 = Atof(fLine + 1 * 11);
   l1 = Atoi(fLine + 2 * 11, 11, 0);
   l2 = Atoi(fLine + 3 * 11, 11, 0);
   n1 = Atoi(fLine + 4 * 11, 11, 0);
   n2 = Atoi(fLine + 5 * 11, 11, 0);
   ScanNextLine();
}


//______________________________________________________________________________
Char_t * TNuEndfIO::ReadTEXT(Char_t *buf, Int_t len)
{
   // Copy len chars of fLine to buf

   if (buf == 0) {
      buf = new Char_t[len+1];
   }

   strncpy(buf, fLine, len+1);
   buf[len] = '\0';
   ScanNextLine();
   return buf;
}

//______________________________________________________________________________
void TNuEndfIO::ReadINTG(Int_t &i, Int_t &j, Short_t kij[], Int_t ndigit)
{
   // Read 1 line of INTG data
/*
INTG, or INTeGer, records are used to store a correlation matrix in integer format.  The
shorthand notation is

[MAT,  MF,  MT / II, JJ, KIJ ] INTG

where II and JJ are position locators, and KIJ is an array whose dimension is specified by the
number of digits NDIGIT to be used for representing the values.  NDIGIT can have any value
from 2 to 6; the corresponding dimensions (NROW) are 18, 13, 11, 9, and 8, respectively.
The INTG record can be read with the following FORTRAN statements:
   DIMENSION KIJ(NROW)
   IF (NDIGIT.EQ.2) READ (LIB,20) II, JJ, KIJ, MAT, MF, MT, NS
   IF (NDIGIT.EQ.3) READ (LIB,30) II, JJ, KIJ, MAT, MF, MT, NS
   IF (NDIGIT.EQ.4) READ (LIB,40) II, JJ, KIJ, MAT, MF, MT, NS
   IF (NDIGIT.EQ.5) READ (LIB,50) II, JJ, KIJ, MAT, MF, MT, NS
   IF (NDIGIT.EQ.6) READ (LIB,60) II, JJ, KIJ, MAT, MF, MT, NS
 20 FORMAT (2I5, 1X, 18I3, 1X,  I4, I2, I3, I5)
 30 FORMAT (2I5, 1X, 13I4, 3X,  I4, I2, I3, I5)
 40 FORMAT (2I5, 1X, 11I5,      I4, I2, I3, I5)
 50 FORMAT (2I5, 1X,  9I6, 1X,  I4, I2, I3, I5)
 60 FORMAT (2I5,      8I7,      I4, I2, I3, I5)
*/
   if (ndigit == 0) ndigit = 2;

   if (ndigit < 2 || ndigit > 6) {
      Error("ReadINTG", "ndigit=%d is out of range", ndigit);
      Error("ReadINTG", "%s at %ld", fLine, fLineNum);
      ScanNextLine();
      return;
   }
   const Int_t ndata[] = {18, 0, 18, 13, 11, 9, 8 }; // number of INTG data per line

   i = Atoi(fLine, 5, 0);
   j = Atoi(fLine + 5, 5, 0);
   for (Int_t n = 0; n < ndata[ndigit]; n++)
      kij[n] = (Short_t) Atoi(fLine + 10 + n * (ndigit+1), ndigit+1, 0);
   ScanNextLine();
}


//______________________________________________________________________________
void TNuEndfIO::ReadIntegers(Int_t ints[6], Int_t len)
{
   // Read 1 line of integer data

   if (len <= 0 || len > 6)
      Error("ReadIntegers", "len = %d is out of range", len);
 
   Char_t err=0;
   for (Int_t n = 0; n < len; n++) {
      ints[n] = Atoi(fLine + n * 11, 11, &err);
      if (err) {
         if (err == 'b') Error("ReadIntegers", 
            "At %d of %ld-th line is a blank, not a float\n[%s]", 
            n, GetLineNum(), fLine);
         else Error("ReadIntegers", 
            "At %d of %ld-th line is not a float\n[%s]", n, GetLineNum(), fLine);
      }
   }
   ScanNextLine();
}

//______________________________________________________________________________
void TNuEndfIO::ReadFloats(Double_t floats[6], Int_t len)
{
   // Read 1 line of float data

   Char_t err=0;
   for (Int_t n = 0; n < len; n++) {
      floats[n] = Atof(fLine + n * 11, &err);
      if (err) {
         if (err == 'b') Error("ReadFloats", 
            "At %d of %ld-th line is a blank, not a float\n[%s]", 
            n, GetLineNum(), fLine);
         else Error("ReadFloats", 
            "At %d of %ld-th line is not a float\n[%s]", n, GetLineNum(), fLine);
      }
   }
   ScanNextLine();
}


//----------------  return parameter values that are to be read  ---------------
//______________________________________________________________________________
Bool_t TNuEndfIO::IsIntegers()
{
   // Check if the line is for integer data

   if (fMT == 0)  return kFALSE;
   if (fMF == 1 && fMT == 451) return kFALSE;

   if (!memchr(fLine, '.', 11) // 1st record is not a float number
      && isdigit(fLine[10]))   // and the 11th char is a digit
      return kTRUE;

   return kFALSE;
}

//______________________________________________________________________________
Bool_t TNuEndfIO::IsFloats()
{
   // Check if the line is for float data

   if (fMT == 0)  return kFALSE;
   if (fMF == 1 && fMT == 451) return kFALSE;

   if (memchr(fLine, '.', 11)) { // 1st record is a float number
      Char_t *s= fLine + 2 * 11; // 3rd record
      if (memchr(s, '.', 11)     // 3rd record is either float
         || !strncmp(s, "           ", 11)) // or blank
         return kTRUE;
   }

   return kFALSE;
}

//______________________________________________________________________________
Bool_t TNuEndfIO::IsINTG()
{
   // Check if the line is for INTG data

   if (fMT == 0)  return kFALSE;
   if (fMF == 1 && fMT == 451) return kFALSE;

   // true if II[5] and JJ[5] are set
   if (fLine[10]==' ' && isdigit(fLine[4]) && isdigit(fLine[9]))
      return kTRUE;

   return kFALSE;
}

//______________________________________________________________________________
const Char_t* TNuEndfIO::GuessRecType()
{
   // Returns the type of ENDF RECORD that is to be read,
   // it will be one of
   //   "SEND", "FEND", "MEND", "TEND",
   //   "CONT", "TAB1", "TAB2", "LIST", "INTG",
   //   or "Unknown"

   Long_t pos = fPos;
   Long_t linenum = fLineNum;

   if (IsSEND()) return "SEND";
   else if (IsFEND()) return "FEND";
   else if (IsMEND()) return "MEND";
   else if (IsTEND()) return "TEND";

   Double_t c1, c2;
   Int_t l1, l2, n1, n2;

   ReadCONT( c1, c2, l1, l2, n1, n2);

   Int_t nI = 0; // number of integer data lines
   Int_t nF = 0; // number of float data lines
   Int_t nG = 0; // number of INTG data lines

   while(IsIntegers()) {
      nI++;
      ScanNextLine();
   }
   while(IsFloats()) {
      nF++;
      ScanNextLine();
   }
   while(IsINTG()) {
      nG++;
      ScanNextLine();
   }

   // reset the file pointer to the original place
   fseek (fFP, pos, SEEK_SET);
   ScanNextLine();
   fLineNum = linenum;

   if (nG>0) {
     if (nI==0 && nF==0) return "INTG";
   }
   else if (nI==0 && nF==0) {
      return "CONT";
   }
//   else if (nI==0 && 6*nF>=n1) {
//      if (nF == (n1+5)/6) return "LIST";
   else if (nI==0 && nF>0) {
      return "LIST";
   }
//   else if (nI>=2*6*n1 && nF==0 && n2>0) {
//      if (nI == (2*n1+5)/6) return "TAB2";
   else if (nI>0 && nF==0) {
      return "TAB2";
   }
//   else if (nI>=2*6*n1 && nF>=2*6*n2) {
//      if (nI == (2*n1+5)/6 && nF == (2*n2+5)/6) return "TAB1";
   else if (nI>0 && nF>0) {
      return "TAB1";
   }
   Info("GuessRecType", "fLine = %s : %ld", fLine, fLineNum);
   Info("GuessRecType", "nI=%d, nF=%d", nI, nF);
   return "Unknown";
}


//______________________________________________________________________________
Bool_t TNuEndfIO::CheckRecType(const char* classname)
{
   TString t = GuessRecType();
   if (strcasecmp(t.Data(), classname)) {
      Warning("Check", "%ld-th line. guess = %s, required=%s\n[%s]",
         GetLineNum(), t.Data(), classname, fLine);
      return kFALSE;
   }
   return kTRUE;
}

//----------------  Go to ...  -------------------------------------------------
//______________________________________________________________________________
void TNuEndfIO::GotoSEND()
{
   // Skip to next SEND

   do {
      ScanNextLine();
   } while (!IsSEND());
}

//______________________________________________________________________________
void TNuEndfIO::GotoFEND()
{
   // Skip to next FEND

   do {
      ScanNextLine();
   } while (!IsFEND());
}

//______________________________________________________________________________
void TNuEndfIO::GotoMEND()
{
   // Skip to next MEND

   do {
      ScanNextLine();
   } while (!IsMEND());
}

//______________________________________________________________________________
Bool_t TNuEndfIO::IsEndfTape(const Char_t *filename)
{
   // check if it is an ENDF ASCII data file (tape)
/*
   FILE* fP = fopen(filename, "r");
   if (fP == NULL) {
      return kFALSE;
   }
   
   Int_t n, mat, mf, mt;
   Char_t c, line[82];
   for (int trial = 0; trial <= 1; trial++) {
      for (n = 0; (c = fgetc(fP)) != EOF && c != '\n' && n < 82; n++)
         line[n] = c;
      if (c == EOF || n < 75) break;

      if (c != '\n')
         for (n = 82; (c = fgetc(fP)) != EOF && c != '\n' && n < 1024; n++) ;

      if (c != '\n') break;

      line[n] = '\0';
      mat =Atoi(line + 66, 4);
      mf = Atoi(line + 70, 2);
      mt = Atoi(line + 72, 3);
      if (mf == 1 && mt == 451) {
         fclose(fP);
         return kTRUE;
      }
      //if (mf == 0 && mt == 0 && trial == 0) continue;
      //break;
   }
   fclose(fP);
   return kFALSE;
*/
   TNuEndfIO test(filename, kFALSE); // turn off the warning
   return test.IsEndfTape();
}

//----------------  Lowest level reading routine  ------------------------------
//______________________________________________________________________________
Int_t TNuEndfIO::ScanNextLine(Bool_t do_warn)
{
   // Lowest level reading routine

   if (fHasEOF) {
      if (do_warn)
         Error("ScanNextLine", "You are trying to read while EOF has already been encountered.");
      return 0;
   }

   fLineNum++;
   fPos = ftell(fFP);

   Int_t n;
   Char_t c;
   for (n = 0; (c = fgetc(fFP)) != EOF && c != '\n' && n < 82; n++)
      fLine[n] = c;

   if (c != EOF && c != '\n')
      for (n = 82; (c = fgetc(fFP)) != EOF && c != '\n' && n < 1024; n++) ;

   if (c == EOF) fHasEOF = kTRUE;

   if (c != EOF && c != '\n') {
      if (do_warn) Error("TNuEndfIO::ScanNextLine",
      "Too long line at %ld : fLine=%81s", fLineNum, fLine);
   }
   if (n < 75) {
      if (do_warn) Error("TNuEndfIO::ScanNextLine",
      "Too short line at %ld : fLine=%81s", fLineNum, fLine);
   }
   fLine[n] = '\0';

   fMAT =Atoi(fLine + 66, 4, 0);
   fMF = Atoi(fLine + 70, 2, 0);
   fMT = Atoi(fLine + 72, 3, 0);
   fNS = Atoi(fLine + 75, 5, 0);

   return (Int_t) c;
}


//----------------  handy static io routines  ----------------------------------
//______________________________________________________________________________
Int_t TNuEndfIO::Atoi(const Char_t s[], Int_t len, Char_t *err)
{
   // Return the integer value of s[len=11]

   if (err) *err = 'b'; // for blank
   Int_t sum=0, sign = 1;

   for (Int_t n = 0; n < len; n++) {
      Int_t c= s[n];
      if (c == ' ')
         continue;
      if (err) *err = 0; // got something
      if (c == '-') {
         sign = -1;
         continue;
      }
      c = c - '0';
      if (c < 0 || c >= 10) {
         //Error("TNuEndfIO::Atoi", "s=[%11s] is not an integer",s);
         if (err) *err = 'E';
         return 0;
      }
      sum = 10 * sum + c;
   }
   return sign * sum;
}

//______________________________________________________________________________
Double_t TNuEndfIO::Atof(const Char_t s[], Char_t *err)
{
   // Return the float value of s[11]

   if (err) *err = 'b';
   char target[13], *t;
   int has_num=0, has_E=0, has_dot=0;

   t=target;

   for (Int_t n = 0; n < 11; n++) {
      Char_t c=toupper(s[n]);
      if (c==' ') continue;
      if (err) *err = 0;
      if (c=='D') c='E';

      if (c=='+' || c=='-') {
         if (has_num && !has_E) *t++= 'E';
      }
      else if ((c=='E') && !has_E) has_E=1;
      else if (isdigit(c)) has_num=1;
      else if (c=='.' && !has_dot) has_dot=1;
      else {
         //Error("TNuEndfIO::Atof", "s=[%11s] is not a float number", s);
         if (err) *err = 'E';
         return 0;
      }
      *t++=c;
   }
   *t='\0';
   return atof(target);
}

//______________________________________________________________________________
void TNuEndfIO::AppendToEndf(FILE *endffile)
{
   if (!ftell(endffile) && *fTitle) {
      // if it is begining of endffile
      fprintf(endffile,"%80s\n",fTitle);
   }
   while (!IsTEND()) {
      fprintf(endffile,"%80s\n",fLine);
      ScanNextLine();
   }
}
