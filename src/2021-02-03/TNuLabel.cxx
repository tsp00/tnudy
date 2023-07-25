// TNulabel.cxx  =====================================================
// Author: Tae-Sun Park   Jul 22 10:15:24 2011

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuLabel                                                           //
//                                                                    //
//                                                                    //
// Class for the labels of a record                                   //
//                                                                    //
// There are 3 different types of labels                              //
// 1. Head labels (e.g., C1 C2 L1 L2 N1 N2),                          //
//    which describe labels for CONT.                                 //
// 2. Body labels (e.g., ER AJ GN GG GFA GFB),                        //
//    which usually describe the data of LIST                         //
// 3. Tail labels,                                                    //
//    optional labels for data of LIST                                //
//                                                                    //
// For input, use, for example,                                       //
// obj->SetLabel(                                                     //
//   "C1, C2, L1, L2, N1, N2"      // head labels                     //
//   "; ER, AJ, GN, GG, GFA, GFB"  // optional body labels            //
//   "& extra_1, extra_2, ..."  // optional tail labels               //
//   "/ title"                // optional title                       //
//   );                                                               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuLabel.h"
#include "TObjString.h"


#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(TNuLabel)

//______________________________________________________________________________
TNuLabel::TNuLabel() : TObject()
{
   // TNuLabel ctor
   fHeads.Delete();
   fBodies.Delete();
   fTails.Delete();
}

//______________________________________________________________________________
TNuLabel::TNuLabel(const Char_t *label) : TObject()
{
   SetLabel(label);
}

//______________________________________________________________________________
TNuLabel::~TNuLabel()
{
   // TNuLabel dtor
}

//______________________________________________________________________________
void TNuLabel::SetLabel(const Char_t *label)
{
   // Set TNuLabel from label.
   // Tokenize label with the comma mark (',') plays as the field separator.
   // Minimally 6 fields for labels for head,
   // and optional labels for data description.

   //const Int_t MaxChars = 1024;
   //Label_t temp[MaxLabels];
   Char_t temp[12];

   const Char_t *s= label;

   TObjArray *pArray = &fHeads;

   fHeads.Delete();
   fBodies.Delete();
   fTails.Delete();

   while (*s) {
      for(Int_t j=0; j < 12; j++) temp[j]=0;
      Char_t *t = temp;
      while(isspace(*s)) s++;
      for(Int_t j=0; *s && *s != ',' && *s != ';'  && *s != '&' && *s != '/'; j++) {
         if (j < 11) *t++ = *s;
         s++;
      }
      //while(isspace(*s)) s++;

      if (*t) {
         fprintf(stderr, "Warning: The *t=%d(%c) should be zero, label=[%s]\n",
            *t, *t, label);
      }
      while (isspace(*--t) && t >= temp) *t='\0'; // remove trailing spaces
      pArray->Add(new TObjString(temp));

      if (*s == 0 || *s == '/') break;

      if (*s == ';') {
         // begin of data labels
         pArray = &fBodies;
         if (NHeads() != 6) Warning("TNuLabel",
            "Data label indicator occurred at fNLabel =%d for label=[%s]",
            NHeads(), label);
         for (Int_t i=NHeads(); i < 6; i++) fHeads.Add(new TObjString(""));
      }
      else if (*s == '&') {
         // begin of aux data labels
         pArray = &fTails;
         if (NBodies() == 0) Warning("TNuLabel",
            "Tail label indicator occurred at without data labels for label=[%s]",
            label);
      }
      else if (*s != ',') {
         fprintf(stderr, "The *s=%d(%c) should be comma mark, label=[%s]\n",
            *s, *s, label);
      }
      s++;
   }
}

//______________________________________________________________________________
const Char_t* TNuLabel::HeadLabels() const
{
   return Form("%11s%11s%11s%11s%11s%11s",
      HeadAt(0), HeadAt(1), HeadAt(2), HeadAt(3), HeadAt(4), HeadAt(5));

}

//______________________________________________________________________________
Int_t TNuLabel::GetEntries() const
{
   return NHeads() + NBodies() + NTails();
}

/*
//______________________________________________________________________________
const Char_t* TNuLabel::At(Int_t n) const
{
   if (n < 0 || n >= GetEntries()) return 0;

   if (n < NHeads()) return HeadAt(n);
   n -= NHeads();
   if (n < NBodies()) return BodyAt(n);
   n -= NBodies();
   return TailAt(n);
}
*/

//______________________________________________________________________________
const Char_t* TNuLabel::HeadAt(Int_t n) const
{
   if (n < 0 || n > NHeads()) {
      Warning("HeadAt","Out of bound, n = %d", n);
      return 0;
   }
   return ((TObjString*) fHeads.At(n))->String();
}

//______________________________________________________________________________
const Char_t* TNuLabel::BodyAt(Int_t n) const
{
   if (n < 0 || n > NBodies()) {
      Warning("BodyAt","Out of bound, n = %d", n);
      return 0;
   }
   return ((TObjString*) fBodies.At(n))->String();
}

//______________________________________________________________________________
const Char_t* TNuLabel::TailAt(Int_t n) const
{
   if (n < 0 || n > NTails()) {
      Warning("TailAt","Out of bound, n = %d", n);
      return 0;
   }
   return ((TObjString*) fTails.At(n))->String();
}

//______________________________________________________________________________
Bool_t TNuLabel::IsEqualTo(const TNuLabel* label) const
{
   // check if label == this
   if (this == label) return kTRUE;

   if (NHeads() - label->NHeads()) return kFALSE;
   for (Int_t i=0; i < NHeads(); i++) {
      if (strcmp(HeadAt(i), label->HeadAt(i))) return kFALSE;
   }

   if (NBodies() - label->NBodies()) return kFALSE;
   for (Int_t i=0; i < NBodies(); i++) {
      if (strcmp(BodyAt(i), label->BodyAt(i))) return kFALSE;
   }

   if (NTails() - label->NTails()) return kFALSE;
   for (Int_t i=0; i < NTails(); i++) {
      if (strcmp(TailAt(i), label->TailAt(i))) return kFALSE;
   }

   return kTRUE;
}

//______________________________________________________________________________
Int_t TNuLabel::CompareTo(const TNuLabel* label) const
{
   // comparison of this to label
   Int_t x;

   if (this == label) return 0;

   if ((x = NHeads() - label->NHeads())) return x;
   for (Int_t i=0; i < NHeads(); i++) {
      Int_t diff = strcmp(HeadAt(i), label->HeadAt(i));
      if (diff) return diff;
   }

   if ((x = NBodies() - label->NBodies())) return x;
   for (Int_t i=0; i < NBodies(); i++) {
      Int_t diff = strcmp(BodyAt(i), label->BodyAt(i));
      if (diff) return diff;
   }

   if ((x = NTails() - label->NTails())) return x;
   for (Int_t i=0; i < NTails(); i++) {
      Int_t diff = strcmp(TailAt(i), label->TailAt(i));
      if (diff) return diff;
   }

   return 0;
}

