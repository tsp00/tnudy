// TNulabel.h  =====================================================
// Author: Tae-Sun Park   Jul 22 10:15:24 2011

#ifndef ROOT_TNuLabel
#define ROOT_TNuLabel

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

#include "TObject.h"
#include "TObjArray.h"
#include "TString.h"

class TNuLabel : public TObject
{
public:
   TNuLabel();
   TNuLabel(const Char_t* label);
   virtual ~TNuLabel();

   void           SetLabel(const Char_t *label);
   const Char_t*  HeadLabels() const;
   //const Char_t*  operator()() const { return HeadLabels(); }

   Int_t          GetEntries() const; // the total number of labels
   Int_t          NHeads() const { return fHeads.GetEntries(); }
   Int_t          NBodies() const { return fBodies.GetEntries(); }
   Int_t          NTails() const { return fTails.GetEntries(); }

   Bool_t         HasHeads() const { return fHeads.GetEntries() > 0; }
   Bool_t         HasBodies() const { return fBodies.GetEntries() > 0; }
   Bool_t         HasTails() const { return fTails.GetEntries() > 0; }

   //const Char_t*  At(Int_t i) const;
   //const Char_t*  operator[](Int_t i) const { return At(i); }

   const Char_t*  HeadAt(Int_t i) const;
   const Char_t*  BodyAt(Int_t i) const;
   const Char_t*  TailAt(Int_t i) const;

   Bool_t         IsEqualTo(const TNuLabel* label) const;
   Int_t          CompareTo(const TNuLabel* label) const;

private:

   TObjArray  fHeads;    // for the labels of head
   TObjArray  fBodies;    // for the labels of data
   TObjArray  fTails;     // for the labels of auxilary data

   ClassDef(TNuLabel, 1) // Class for the labels of a record
};
#endif

