
// TNuSaveToTextDlg.h  =====================================================
// Author: Ki-Hong Lee     Nov 20 2012

#ifndef ROOT_TNuSaveToTextDlg
#define ROOT_TNuSaveToTextDlg

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuSaveToTextDlg = TNuSaveToTextDlg in TNudy                       //
//                                                                    //
// The class for Dialog to save the text of object                    //
//                                                                    //
////////////////////////////////////////////////////////////////////////

//#include "TNuCanvasPrinter.h"
#include "TNuObject.h"
#include "TGFrame.h"
#include "TGTextEntry.h"
#include "TGFileDialog.h"
#include "TGComboBox.h"
#include "TGButton.h"
#include <RQ_OBJECT.h>

//class TNuCanvasPrinter;
enum ESaveMode {
   kSaveObject=1,
   kSaveGraph=2
};

class TNuSaveToTextDlg  : public TObject
{
RQ_OBJECT("TNuSaveToTextDlg")

public:
   TGTransientFrame *fTframe;

   TNuSaveToTextDlg(const TGWindow *window);
// TNuSaveToTextDlg(TGWindow *window, TNuObject *obj);
// TNuSaveToTextDlg(TGWindow *window, TNuObject *obj);
   virtual ~TNuSaveToTextDlg();
   void Open(const TNuObject* obj, ESaveMode mode) {
      fMode = mode;
      SetObject(obj);
      Show();
   }
   void Close() {
      Hide();
   }

   void Save();
   void OpenBrowser();

protected:
   void Show();
   void Hide();
   void SetPath();
   void SetObject(const TNuObject* obj) {
      fObject=obj;
   }

private:
   const TNuObject *fObject;
   ESaveMode      fMode;
   TGTextEntry    *fPathEntry;
   TGComboBox     *fCombo;
   TGCheckButton  *fCheck;
   TGFileInfo     *fFileInfo;

   ClassDef(TNuSaveToTextDlg, 1) // Class for Dialog to save the text of object
};


class MyFileDlg : public TGFileDialog
{
//RQ_OBJECT("MyFileDlg")

public:
   MyFileDlg(TNuSaveToTextDlg *parent, TGFileInfo *fileinfo);
   //virtual Bool_t  ProcessMessage(Long_t msg, Long_t parm1, Long_t parm2);
   ClassDef(MyFileDlg, 1)
};
#endif

