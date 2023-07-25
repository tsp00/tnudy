// TNuContList.h  =====================================================
// Author: Tae-Sun Park   Jul 21 08:52:01 2011

#ifndef ROOT_TNuContList
#define ROOT_TNuContList

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuContList                                                        //
//                                                                    //
// 1 TNuCont (inherited) + 1 TNuList (as member variable)             //
//                                                                    //
// This structure is heavily used in Section MF=2, MT=151             //
////////////////////////////////////////////////////////////////////////

#include "TNuRecsWithCont.h"
#include "TNuList.h"

class TNuEndfIO;

class TNuContList : public TNuRecsWithCont
{
public:
   TNuContList() : TNuRecsWithCont() {}
   //TNuContList(TNuEndfIO &src, const Char_t* label=" C1, C2, L1, L2, N1, N2");
   virtual      ~TNuContList();

   //Bool_t        IsFolder() const  { return kTRUE; }
   //void          Browse(TBrowser *b);
   //virtual void  ls(Option_t* option="") const; // *MENU*
   //virtual void  Print(Option_t *opt) const; //

   void          SetList(TNuList* list);// { fList = list; }
   TNuList*      GetList() const  { return (TNuList*) BodyFirst(); }

   //virtual Int_t NRecords() const { return 2; }

protected:
   //TNuList*      fList; // member TNuList ptr

   ClassDef(TNuContList, 1) // 1 TNuCont (inherited) + 1 TNuList (as member variable)
};
#endif

