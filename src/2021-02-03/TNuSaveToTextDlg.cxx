
// TNuSaveToTextDlg.cxx  =====================================================
// Author: Ki-Hong Lee   Nov 20 2012


////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSaveToTextDlg = TNuSaveToTextDlg in TNudy                       //
//                                                                    //
// The class for Dialog to save the text of object                    //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <fcntl.h>
#include "TNuSaveToTextDlg.h"
#include "TNudy.h"
#include "TNuPrinter.h"
#include "TNuSection.h"
#include "TNuMat.h"
#include "TNuSublib.h"

#include "TGLabel.h"

ClassImp(TNuSaveToTextDlg)
static const char *gFileTypes[]={"Text files", "*.txt", "All files","*", 0, 0};

//______________________________________________________________________________
TNuSaveToTextDlg::TNuSaveToTextDlg(const TGWindow *window)
: fFileInfo(NULL)
{
   fTframe = new TGTransientFrame(window->GetParent(), window);
   fTframe->SetWindowName( "Save To Text File...");
   fTframe->Connect("CloseWindow()", "TNuSaveToTextDlg", this, "Close()");
   fTframe->DontCallClose(); // to avoid double deletions.

   // use hierarchical cleaning
   fTframe->SetCleanup(kDeepCleanup);

   // Create a main frame
   TGLayoutHints* lhn = new TGLayoutHints(kLHintsNormal, 5, 5, 3, 4);
   TGLayoutHints* lhr = new TGLayoutHints(kLHintsRight, 5, 5, 3, 4);
   TGLayoutHints* lhi = new TGLayoutHints(kLHintsNormal, 0, 3, 0, 0);
   
   TGLabel* lbl1 = new TGLabel(fTframe, "Saving Path :");

   // Create a horizontal frame containing two buttonsa
   TGCompositeFrame* hframe1 = new TGCompositeFrame(fTframe, 1, 1, kHorizontalFrame);
   fPathEntry = new TGTextEntry(hframe1, "out.txt");
   fPathEntry->SetWidth(300);
   TGTextButton* browserBtn = new TGTextButton(hframe1, "&Browser");
   browserBtn->Connect("Clicked()", "TNuSaveToTextDlg", this, "OpenBrowser()");
   browserBtn->SetToolTipText("Open Browser");
   hframe1->AddFrame(fPathEntry, lhi);
   hframe1->AddFrame(browserBtn, lhi);
   hframe1->Resize();
   
   TGCompositeFrame* hframe2 = new TGCompositeFrame(fTframe, 1, 1, kHorizontalFrame);
   TGLabel* lbl2 = new TGLabel(hframe2, "Separator Type : ");
   fCombo = new TGComboBox(hframe2);
   fCombo->AddEntry("tab",1);
   fCombo->AddEntry("comma",2);
   fCombo->AddEntry("space", 3);
   fCombo->Resize(100, 20);      
   fCombo->Select(1);
   fCheck = new TGCheckButton(hframe2, "Keep Width");
   hframe2->AddFrame(lbl2, lhi);
   hframe2->AddFrame(fCombo, lhi);
   hframe2->AddFrame(fCheck, new TGLayoutHints(kLHintsNormal, 20, 3, 0, 0));
   hframe2->Resize();

   TGCompositeFrame* hframe3 = new TGCompositeFrame(fTframe, 1, 1, kHorizontalFrame);
   TGTextButton* saveBtn = new TGTextButton(hframe3, "&Save");
   saveBtn->Connect("Clicked()", "TNuSaveToTextDlg", this, "Save()");
   saveBtn->SetToolTipText("Save to Text");
   TGTextButton* cancelBtn = new TGTextButton(hframe3, "&Cancel");
   cancelBtn->Connect("Clicked()", "TNuSaveToTextDlg", this, "Close()");
   hframe3->AddFrame(saveBtn, lhi);
   hframe3->AddFrame(cancelBtn, lhi);
   hframe3->Resize();

   fTframe->AddFrame(lbl1, lhn);
   fTframe->AddFrame(hframe1,lhn);
   fTframe->AddFrame(hframe2,lhn);
   fTframe->AddFrame(hframe3,lhr);
   fTframe->MapSubwindows();
   fTframe->Resize();
   // position relative to the parent's window
   //fTframe->CenterOnParent();
}

//______________________________________________________________________________
TNuSaveToTextDlg::~TNuSaveToTextDlg()
{
   fTframe->DeleteWindow();  // deletes fMain
}

//______________________________________________________________________________
void TNuSaveToTextDlg::Show()
{
   char buf[1024];

   TString def;
   if (fObject->GetParentMat()) {
      //def.Append("-");
      def.Append(fObject->GetParentMat()->GetDefaultName());
      def.Append("-");
   }
   TNuSection * sec = fObject->GetParentSection();
   if(sec) def.Append(Form("%02d-%03d", sec->GetMF(), sec->GetMT()));
   TObjArray array;
   
   TNuObject *obj = (TNuObject*)fObject;
   TNuObject *parent;
   while (obj && (parent = obj->GetParent()) && !obj->InheritsFrom("TNuSection")) {
      if (parent) {
      array.Add(obj);
      obj = parent;
      }
   }
   for (int i = array.GetEntries()-1; i >= 0; i--) {
      def.Append("-");
      def.Append(array.At(i)->GetName());
   }

   fPathEntry->SetText(Form("%s/%s.txt", getcwd(buf,1024), def.Data()));

   fTframe->MapWindow();
}

//______________________________________________________________________________
void TNuSaveToTextDlg::Hide()
{
   fTframe->UnmapWindow();
}

//______________________________________________________________________________
void TNuSaveToTextDlg::OpenBrowser()
{
   if(fFileInfo==NULL) {
      fFileInfo = new TGFileInfo();
      fFileInfo->fFileTypes = gFileTypes;
   }
}

//______________________________________________________________________________
void TNuSaveToTextDlg::Save()
{
   int std, fd;
   fflush(stdout);
   std = dup(1);
   const Char_t* filePath = fPathEntry->GetText();
   fd = open(filePath, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
   dup2(fd, 1);
   close(fd);

   TNuPrinter& printer = TNudy::GetPrinter();
   printer.Set(fObject, "txt");
   switch(fCombo->GetSelected()) {
      case 1:
         printer.fFieldSeparator = "\t";
         break;
      case 2:
         printer.fFieldSeparator = ",";
         break;
      case 3:
      default:
         printer.fFieldSeparator = " ";
   }

   if(!fCheck->IsDown()) {
      printer.fFieldWidth.i=1;
   }

   if(fMode==kSaveObject)
      fObject->Print(NULL);
   else if(fMode==kSaveGraph)
      fObject->Print("Graph");
   
   fflush(stdout);
   dup2(std, 1);
   close(std);
   fTframe->UnmapWindow();
}

//______________________________________________________________________________
void TNuSaveToTextDlg::SetPath()
{
   printf("wow!!\n");
   fPathEntry->SetText(fFileInfo->fFilename);
}

ClassImp(MyFileDlg)
//______________________________________________________________________________
MyFileDlg::MyFileDlg(TNuSaveToTextDlg *parent, TGFileInfo *fileInfo)
: TGFileDialog(parent->fTframe->GetParent(), parent->fTframe, kFDSave, fileInfo)
{
   fOk->Associate(this);
   fOk->Connect("Clicked()", "TNuSaveToTextDlg", parent, "SetPath()");
}

