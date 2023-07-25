// TNuObject.cxx  =====================================================
// Author: Tae-Sun Park   Jun 16 2011


////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuObject = TObject in TNudy                                       //
//                                                                    //
// Any object that consists of one or more ENDF records               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "TNuObject.h"
#include "TClass.h"

#include "TNudy.h"
#include "TNuLib.h"
#include "TNuSublib.h"
#include "TNuMat.h"
#include "TNuFile.h"
#include "TNuSection.h"

#include "TF1.h"
#include "TF2.h"
#include "TF3.h"

#include "TROOT.h"
#include "TCanvas.h"
#include "TPad.h"

#include "TNuVF1.h"

#include <iostream>
#include <iomanip>

#include "TNuPrinter.h"
#include "TNuCanvasPrinter.h"
#include "TNuSaveToTextDlg.h"
#include "string.h"
#include "assert.h"

ClassImp(TNuObject)

//______________________________________________________________________________
TNuObject::TNuObject() : TObject(), fParent(0), fLabelID(0)
{
   // TNuObject ctor
}

//______________________________________________________________________________
TNuObject::TNuObject(const TNuObject &rec) : TObject(rec)
{
   // TNuObject copy ctor

   if (this != &rec) {
      fParent = rec.fParent;
      //fNameID  = rec.fNameID;
      //fTitleID = rec.fTitleID;
      fLabelID = rec.fLabelID;
   }
}

//______________________________________________________________________________
TNuObject& TNuObject::operator=(const TNuObject &rec)
{
   // TNuObject assignment operator

   if (this != &rec) {
      TObject::operator=(rec);
      fParent    = rec.fParent;
      //fNameID  = rec.fNameID;
      //fTitleID = rec.fTitleID;
      fLabelID = rec.fLabelID;
   }
   return *this;
}

//______________________________________________________________________________
TNuObject::~TNuObject()
{
   // TNuObject dtor
   fParent = 0;
}

/*
//______________________________________________________________________________
void TNuObject::Streamer(TBuffer &R__b)
{
   // Set parent

   TObject::Streamer(R__b);
   
   SetLineage();
}
*/

//______________________________________________________________________________
void TNuObject::ls(Option_t* option) const
{
   // ls
   TObject::ls(option);
}

//______________________________________________________________________________
void TNuObject::Print(Option_t* option) const
{
   // Print
   TObject::Print(option);
}

//______________________________________________________________________________
void TNuObject::PrintOnCanvas() const
{
   // Print on canvas

   TNudy::SetPrintType(kTRUE);
   TNuCanvasPrinter::GetInstance().SetCounting();
   Print("3");
   TNuCanvasPrinter::GetInstance().SetCounting(kFALSE);
   Print(NULL);
   TNuCanvasPrinter::GetInstance().ResizeCanvas();
   TNudy::SetPrintType(kFALSE);
}


//______________________________________________________________________________
void TNuObject::SaveGraphDataAsText() const
{
   TNudy::GetPrinter().OpenSaveToTextDlg(this, kSaveGraph);
}

//______________________________________________________________________________
const Char_t* TNuObject::GetName() const
{
   UShort_t nameID = GetNameID();

   if (nameID) return GetParentLib()->GetObjName(nameID);
   else        return ClassName();
}

//______________________________________________________________________________
const Char_t* TNuObject::GetTitle() const
{
   UShort_t titleID = GetTitleID();

   if (titleID) return GetParentLib()->GetObjTitle(titleID);
   else         return ClassName();
}


//______________________________________________________________________________
TNuLabel* TNuObject::GetLabel() const
{
   return GetParentLib()->GetObjLabel(fLabelID);
}

//______________________________________________________________________________
void TNuObject::SetName(const Char_t* name)
{
   // Assign fNameID (emboddied in fUniqueID) corresponding to the name
   // and add the name to the fNames if it is new

   UShort_t nameID = GetParentLib()->SetObjName(name);
   UInt_t uniqueID = GetUniqueID();
   SetUniqueID((nameID << 16) + (uniqueID & 0xffff));
}

//______________________________________________________________________________
void TNuObject::SetTitle(const Char_t* title)
{
   // Assign fTitleID (emboddied in fUniqueID) corresponding to the title
   // and add the title to the fTitles if it is new

   UShort_t titleID = GetParentLib()->SetObjTitle(title);
   UInt_t uniqueID = GetUniqueID();
   SetUniqueID((uniqueID & 0xffff0000) + titleID);
}


//______________________________________________________________________________
void TNuObject::SetNameTitle(const Char_t* name, const Char_t* title)
{
   // set name and title

   SetName(name);
   SetTitle(title);
}

//______________________________________________________________________________
void TNuObject::SetLabel(const Char_t* label)
{
   // Assign flabelID corresponding to the "label/title"
   // and add the label/title to the fLabels/fTitles if they are new}

   fLabelID = GetParentLib()->SetObjLabel(label);
}

//______________________________________________________________________________
void TNuObject::SetPrintOption(Option_t* opt) const
{
   // Set print options and
   // initialize fMAT, fMF, fMT, fNS

   //TNuPrinter::GetInstance().SetOptions(opt);
   TNudy::GetPrinter().SetOptions(opt);
}

//______________________________________________________________________________
Bool_t TNuObject::IsFunctor() const
{
   // true if it inherits from TNuVF1
   return InheritsFrom("TNuVF1");
}

//______________________________________________________________________________
void TNuObject::What() const
{
   using namespace std;

   //cout << Form("(%s) %s at %x: ",TObject::GetName(), GetName(), this);
   //cout << " / " << GetTitle() << endl;
   cout << ClassName() << " at " << this << endl;
   cout << "\tName   = [" << GetName() << "]" << endl;
   cout << "\tTitle  = [" << GetTitle() << "]" << endl;
   if (GetLabelID())
      cout << "\tLabel  = [" << GetLabel()->HeadLabels() << "]" << endl;

   TNuCont *cont = HeadCont();
   if (cont) {
      cout << "\t       = [";
      cout << setw(11) << Form("%#9G", cont->GetC1());
      cout << setw(11) << Form("%#9G", cont->GetC2());
      cout << setw(11) << Form("%d", cont->GetL1());
      cout << setw(11) << Form("%d", cont->GetL2());
      cout << setw(11) << Form("%d", cont->GetN1());
      cout << setw(11) << Form("%d", cont->GetN2());
      cout << "]" << endl;
   }

   if (GetSymbol())
      cout << "\tSymbol = [" << GetSymbol() << "]" << endl;

   if (IsFunctor()) {
      TNuObject *obj= (TNuObject*) this;
      TNuVF1 *vf1 = dynamic_cast<TNuVF1*>(obj);
      if (!vf1) {
         fprintf(stderr,"Error in What: Null vf1 for this = 0x%p\n", this);
         return;
      }
      vf1->VirtualWhat();
   }
}

//______________________________________________________________________________
void TNuObject::Draw(Option_t* option)
{
   // if it is a functor, create TFn and execute Draw()

   if (IsFunctor()) {
      //((TNuVF1*) this)->VirtualDraw(option);
      TNuVF1 *vf1 = dynamic_cast<TNuVF1*>(this);
      if (!vf1) {
         fprintf(stderr,"Error in What: Null vf1 for this = 0x%p\n", this);
         return;
      }
      vf1->VirtualDraw(option);
   }
}


//______________________________________________________________________________
void TNuObject::Paint(Option_t* option)
{
   // if it is a functor, call its Paint()
   if (IsFunctor()) dynamic_cast<TNuVF1*>(this)->VirtualPaint(option);
}

//______________________________________________________________________________
void TNuObject::PrintLineage(Int_t n) const
{
   // print lineage of an object
   using namespace std;

   if (n == 0) {
      cout << endl << "Lineage chart of the object at " << this << endl;
   }

   if (n >=10) {
      // Error
      return;
   }
   cout << n << ". (" << ClassName() << ") : " << GetName() << " at " << this << endl;
   const TNuObject* obj = GetParent();
   if (obj) obj->PrintLineage(n+1);
}

//______________________________________________________________________________
TNuSection* TNuObject::GetParentSection() const
{
   // returns the pointer of its parent TNuSection
   if (IsSection()) return (TNuSection*) this;
   
   TNuObject *parent = GetParent();
   return (parent) ? parent->GetParentSection() : 0;
}


//______________________________________________________________________________
TNuFile* TNuObject::GetParentFile() const
{
   // returns the pointer of its parent TNuFile
   if (IsFile()) return (TNuFile*) this;

   TNuSection *sec = (TNuSection *) GetParentSection();
   return (sec) ? sec->GetParentFile() : 0;
}


//______________________________________________________________________________
TNuMat* TNuObject::GetParentMat() const
{
   // returns the pointer of its parent TNuMat
   if (IsMat()) return (TNuMat*) this;

   TNuFile *file = GetParentFile();
   return (file) ? file->GetParentMat() : 0;
}

//______________________________________________________________________________
TNuSublib* TNuObject::GetParentSublib() const
{
   // returns the pointer of its parent TNuSublib
   if (IsSublib()) return (TNuSublib*) this;

   TNuMat *mat = GetParentMat();
   return (mat) ? mat->GetParentSublib() : 0;
}


//______________________________________________________________________________
TNuLib* TNuObject::GetParentLib() const
{
   // returns the pointer of its parent TNuLib
   if (IsLib()) return (TNuLib*) this;

   TNuSublib *proj = GetParentSublib();
   return (proj) ? proj->GetParentLib() : gNuLib;
}

//______________________________________________________________________________
Int_t TNuObject::GetNSUB() const { 
   TNuSublib* proj = GetParentSublib();
   return proj ? proj->GetNSUB() : 0;
}

//______________________________________________________________________________
Int_t TNuObject::GetProjectileZA() const { 
   TNuSublib* proj = GetParentSublib();
   return proj ? proj->GetNSUB()/10 : 0;
}

//______________________________________________________________________________
Double_t TNuObject::GetProjectileAWR() const { 
   TNuMat *mat = GetParentMat();
   return mat ? mat->ProjectileMass() : 0;
}

//______________________________________________________________________________
Int_t TNuObject::GetTargetZA() const { 
   TNuSection *sec = GetParentSection();
   return sec ? sec->GetZA() : 0;
}

//______________________________________________________________________________
Double_t TNuObject::GetTargetAWR() const { 
   TNuSection *sec = GetParentSection();
   return sec ? sec->GetAWR() : 0;
}

//______________________________________________________________________________
Bool_t TNuObject::CdToDataDir() const 
{
   Bool_t ok;
   const char *dir = "";
   TNuObject *p = GetParent();
   if (p) {
      ok = p->CdToDataDir();
   } else {
      gDirectory->cd("/");
      dir = "__raw_data__";
      if (!gDirectory->GetDirectory(dir)) {
         gDirectory->mkdir(dir, "Directory for TNudy Raw Data");
      }
      ok = gDirectory->cd(dir);
   }
   if (ok) {
      dir = GetName();
      if (!gDirectory->GetDirectory(dir)) {
         gDirectory->mkdir(dir);
      }
      ok = gDirectory->cd(dir);
   }
   if (!ok) {
      fprintf(stderr, "Fail to cd to raw data of %s, dir=%s, cwd = %s\n",
         GetName(), dir, gDirectory->GetPath());
   }
   return ok;
}
/*
const Char_t* TNuObject::GetPath() const
{
   TNuObject* parent = GetParent();
   return Form("%s/%s",
      parent ? parent->GetPath() : "/__raw_data__", GetName());
}
*/

//______________________________________________________________________________
Bool_t TNuObject::IsClassName(const Char_t* classname) const
{
   return !strcmp(ClassName(), classname);
}

//______________________________________________________________________________
void TNuObject::AssertClassName(const Char_t* classname) const
{
   assert(IsClassName(classname));
}

//______________________________________________________________________________
void TNuObject::SetGlobal()
{
   // assign this to gNuObject
   gNuObject = this;
}


//______________________________________________________________________________
const Char_t* TNuObject::GetFigTitle() const
{
   // The title to appear in the figures
   // returns the title of its figures 
   
   TNuMat *mat = GetParentMat();
   TNuSection *sec = GetParentSection();
   TNuCont* cont = HeadCont();
   if (!mat || !sec || !cont) return GetName();
   
   const Char_t *target_name = mat->GetDefaultName("Latex");
   const Char_t *channel_name = sec->GetChannelSymbol();
   const Char_t *c1 = "", *c2 = "";
   TNuLabel *label = cont->GetLabel();
   if (label && label->NHeads() > 2) {
      c1 = label->HeadAt(0);
      c2 = label->HeadAt(1);
   }
   
   return Form("%s: %s of %s%s. MT=%d.%s%s",
      GetName(),
      sec->GetSymbol(),
      target_name,
      channel_name,
      sec->GetMT(),
      (isalpha(*c1)) ? Form(" %s=%10.3e.", c1, cont->GetC1()) : "", 
      (isalpha(*c2)) ? Form(" %s=%10.3e.", c2, cont->GetC2()) : ""
      );
}
   
