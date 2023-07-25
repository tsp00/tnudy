// TNuContList.h  =====================================================
// Author: Tae-Sun Park   Jul 21 08:52:01 2011

////////////////////////////////////////////////////////////////////////
//                                                                    //
// TNuContList                                                        //
//                                                                    //
// 1 TNuCont (inherited) + 1 TNuList (as member variable)             //
//                                                                    //
// This structure is heavily used in Section MF=2, MT=151             //
////////////////////////////////////////////////////////////////////////


#include "TNuContList.h"

//#include "TNuEndfIO.h"

//#include "TBrowser.h"

//#include "TNuPrinter.h"
//#include <iostream>
//#include <iomanip>
//sing namespace std;

ClassImp(TNuContList)

/*
//______________________________________________________________________________
TNuContList::TNuContList(TNuEndfIO &src, const Char_t* label) : TNuCont(src, label)
{
   // ctor of TNuContList importing ENDF data
}
*/

//______________________________________________________________________________
TNuContList::~TNuContList()
{
   // dtor
}

//______________________________________________________________________________
void TNuContList::SetList(TNuList* list)
{
   // Browse TNuContList

   if (NBodies()) {
      Error("SetList", "We got already body elements!");
      return;
   }
   Add(list);
}

/*
//______________________________________________________________________________
void TNuContList::Browse(TBrowser *b)
{
   // Browse TNuContList

   if (b && GetList()) {
      b->Add(GetList());
   }
}

//______________________________________________________________________________
void TNuContList::ls(Option_t* option) const
{
   cout << Form("(%s) %s at %x: ", ClassName(), GetName(), (size_t) this);
   cout << " / " << GetTitle() << endl;

   TNuCont::ls(option);

   if (fList) {
      cout << setw(5) << "List: ";
      GetList()->ls(option);
   }
}

//______________________________________________________________________________
void TNuContList::Print(Option_t *opt) const
{
   // print cont + list

   TNudy::GetPrinter().Set(this, opt);

   TNudy::GetPrinter().PrintCont((TNuCont*) this);
   TNudy::GetPrinter().PrintList(GetList());
}
*/
