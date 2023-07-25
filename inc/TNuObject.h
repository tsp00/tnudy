// TNuObject.h  =====================================================
// Author: Tae-Sun Park   Jun 16 2011

#ifndef ROOT_TNuObject
#define ROOT_TNuObject

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuObject = TObject in TNudy                                       //
//                                                                    //
// Any object that consists of one or more ENDF records               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TNuLabel.h"

class TNuCont;
class TF1;
class TF2;
class TF3;
class TBrowser;
class TNuSection;
class TNuFile;
class TNuMat;
class TNuSublib;
class TNuLib;
class TCanvas;

class TNuObject : public TObject
{
public:
   TNuObject();
   TNuObject(const TNuObject &rec);
   TNuObject& operator=(const TNuObject &rec);
   virtual ~TNuObject();

   //virtual void Streamer(TBuffer &R__b);
   
   virtual Int_t NRecords() const { return 1; }

   virtual void  ls(Option_t* option="") const; // *MENU*
   virtual void  Print(Option_t* option="") const;  // *MENU*
   virtual void  PrintOnCanvas() const; // *MENU*
   virtual void  SaveGraphDataAsText() const; // *MENU*
   // this must be overridden in the derived classes
   virtual TNuCont* HeadCont() const { return 0; }

   void Browse(TBrowser *) {}

   // this must be overridden in the derived classes
   virtual const Char_t* GetEndfName() const { return ""; }

   const Char_t* GetName()  const;
   const Char_t* GetTitle() const;
   TNuLabel*     GetLabel() const;

   // The title that is to appear in the figure of it
   virtual const Char_t*  GetFigTitle() const;// { return GetTitle(); }

   // Use TObject::GetUniqueID() as fNameID(16 bit):fTitleID(16 bit)
   UShort_t      GetNameID() const { return GetUniqueID() >> 16; }
   UShort_t      GetTitleID() const { return GetUniqueID() & 0xffff; }
   UShort_t      GetLabelID() const { return fLabelID; }

   virtual void  SetName(const Char_t* name = "");
   virtual void  SetTitle(const Char_t* title = "");
   virtual void  SetNameTitle(const Char_t* name = "", const Char_t* title = "");
   virtual void  SetLabel(const Char_t* label = "");

   virtual void  SetPrintOption(Option_t* opt) const;

   Bool_t        IsFunctor() const; // true if it inherits from TNVF1
   virtual void  What() const; // *MENU*


   // the symbol that represents the class
   virtual const Char_t* GetSymbol() const { return GetName(); }

   virtual void  Draw(Option_t* option="");
   virtual void  Paint(Option_t* option="");

   // is it a good idea to assign fParent to all the TNuObject ?
   //
   TNuObject*    GetParent() const { return fParent; }
   TNuObject*&   GetParent() { return fParent; }
   void          SetParent(const TNuObject* parent)  {
      fParent = (TNuObject*) parent; // set parent
    }

   virtual void  SetLineage() { SetTransient(); } // and set transient member data

   // set transient member variables, it is to be called only once
   // when the instance is loaded into memory from disk
   virtual void  SetTransient() {}

   // for test
   void          PrintLineage() const { PrintLineage(0); } // *MENU*
   void          PrintLineage(Int_t n) const;

   virtual Int_t    GetNuID() const { return (Int_t) GetUniqueID(); }
   virtual ULong_t  Hash() const { return GetNuID(); }
   //virtual const Char_t* GetPath() const;
   Bool_t           CdToDataDir() const;

   // virtual version of At(n)
   //  to allow expressions such as obj->At(1)->At(3)->At(0)->What()
   // It is overridden by TNuRecs and TNuTab2/TNuTab3
   virtual TNuObject* VAt(Int_t /*n*/) const {
      MayNotUse("VirtualAt");
      return 0;
   }

   /* -------------------
   following methods might be handy especially in CINT
   but it causes compile error
---------------------------------*/

   // returns the pointer of its parents
   // will it be a good idea to define these as virtual ?
   virtual TNuSection* GetParentSection() const;
   virtual TNuFile*    GetParentFile() const;
   virtual TNuMat*     GetParentMat() const;
   virtual TNuSublib*  GetParentSublib() const;
   virtual TNuLib*     GetParentLib() const;
   
   virtual Bool_t   IsSection() const { return kFALSE; }// check if it is a TNuSection 
   virtual Bool_t   IsFile() const { return kFALSE; } // check if it is a TNuFile 
   virtual Bool_t   IsMat() const { return kFALSE; } // check if it is a TNuMat 
   virtual Bool_t   IsSublib() const { return kFALSE; } // check if it is a TNuSublib 
   virtual Bool_t   IsLib() const { return kFALSE; } // check if it is a TNuLib

   Int_t         GetNSUB() const;
   Int_t         GetProjectileZA() const;
   Double_t      GetProjectileAWR() const;
   Int_t         GetTargetZA() const;
   Double_t      GetTargetAWR() const;


   // for the convenience in writing macros and in debugging
   Bool_t        IsClassName (const Char_t* classname) const;
   void          AssertClassName (const Char_t* classname) const;

   void          SetGlobal(); // *MENU*

protected:

   // Will it be a good idea to assign fParent to all the TNuObject ?
   //
   TNuObject*    fParent; //! pointer to the parent TNuObject


private:

   //UShort_t    fNameID;  // ID to indicate the Name string
   //UShort_t    fTitleID; // ID to indicate the Title string
   UShort_t      fLabelID;   // ID to indicate the Label string

   ClassDef(TNuObject, 1) //TObject in TNudy
};
#endif

