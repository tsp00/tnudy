// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedIidInudydIsrcdIG__Nudy
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/home/i/nudy/inc/TNuVResonance.h"
#include "/home/i/nudy/inc/TNuMath.h"
#include "/home/i/nudy/inc/TNuPrinter.h"
#include "/home/i/nudy/inc/TNuSec13.h"
#include "/home/i/nudy/inc/TNuSec10.h"
#include "/home/i/nudy/inc/TNuSec09.h"
#include "/home/i/nudy/inc/TNuLib.h"
#include "/home/i/nudy/inc/TNuEndfIO.h"
#include "/home/i/nudy/inc/TNuIntg.h"
#include "/home/i/nudy/inc/TNuContLists.h"
#include "/home/i/nudy/inc/TNuSection.h"
#include "/home/i/nudy/inc/TNuTab1Lists.h"
#include "/home/i/nudy/inc/TNuListTaylor.h"
#include "/home/i/nudy/inc/TNuRecsWithTAB2.h"
#include "/home/i/nudy/inc/TNuTab1.h"
#include "/home/i/nudy/inc/TNuSec15.h"
#include "/home/i/nudy/inc/TNuResoResolved.h"
#include "/home/i/nudy/inc/TNuEndfTAB2.h"
#include "/home/i/nudy/inc/TNuSec04.h"
#include "/home/i/nudy/inc/TNuVTab.h"
#include "/home/i/nudy/inc/TNuListLegendre.h"
#include "/home/i/nudy/inc/TNuSec03.h"
#include "/home/i/nudy/inc/TNuCollection.h"
#include "/home/i/nudy/inc/TNuTab3.h"
#include "/home/i/nudy/inc/TNuSec06.h"
#include "/home/i/nudy/inc/TNuCont.h"
#include "/home/i/nudy/inc/TNuSec07002Coherent.h"
#include "/home/i/nudy/inc/TNuDescription.h"
#include "/home/i/nudy/inc/TNuDirs.h"
#include "/home/i/nudy/inc/TNuSec01458.h"
#include "/home/i/nudy/inc/TNuSec28.h"
#include "/home/i/nudy/inc/TNuSublib.h"
#include "/home/i/nudy/inc/TNuDEpDMu2Body.h"
#include "/home/i/nudy/inc/TNuSec12Transitions.h"
#include "/home/i/nudy/inc/TNuListCoulomb.h"
#include "/home/i/nudy/inc/TNuResoReichMoore.h"
#include "/home/i/nudy/inc/TNuSec07004.h"
#include "/home/i/nudy/inc/TNuSec01451.h"
#include "/home/i/nudy/inc/TNuList.h"
#include "/home/i/nudy/inc/TNuSec08.h"
#include "/home/i/nudy/inc/TNuVF1.h"
#include "/home/i/nudy/inc/TNuList2KalbachMann.h"
#include "/home/i/nudy/inc/TNuSec01.h"
#include "/home/i/nudy/inc/TNuSec12Yields.h"
#include "/home/i/nudy/inc/TNuVF3.h"
#include "/home/i/nudy/inc/TNuContList.h"
#include "/home/i/nudy/inc/TNuDEpDMu.h"
#include "/home/i/nudy/inc/TNuSec07002.h"
#include "/home/i/nudy/inc/TNuSec08457.h"
#include "/home/i/nudy/inc/TNuList2Legendre.h"
#include "/home/i/nudy/inc/TNuTab2Tab1.h"
#include "/home/i/nudy/inc/TNuCov.h"
#include "/home/i/nudy/inc/TNuResonance.h"
#include "/home/i/nudy/inc/TNuSec05.h"
#include "/home/i/nudy/inc/TNuTab2List1.h"
#include "/home/i/nudy/inc/TNuSec14.h"
#include "/home/i/nudy/inc/TNuSec27.h"
#include "/home/i/nudy/inc/TNuRecsWithTab1.h"
#include "/home/i/nudy/inc/TNuList1.h"
#include "/home/i/nudy/inc/TNuTab2.h"
#include "/home/i/nudy/inc/TNuSec07002Incoherent.h"
#include "/home/i/nudy/inc/TNuDEpDMuETransfer.h"
#include "/home/i/nudy/inc/TNuLabel.h"
#include "/home/i/nudy/inc/TNuVF2.h"
#include "/home/i/nudy/inc/TNuVF1s.h"
#include "/home/i/nudy/inc/TNuObject.h"
#include "/home/i/nudy/inc/TNuSec02.h"
#include "/home/i/nudy/inc/TNuResoRMatrixLimited.h"
#include "/home/i/nudy/inc/TNudy.h"
#include "/home/i/nudy/inc/TNuSaveToTextDlg.h"
#include "/home/i/nudy/inc/TNuResoUnresolved.h"
#include "/home/i/nudy/inc/TNuMat.h"
#include "/home/i/nudy/inc/TNuCanvasPrinter.h"
#include "/home/i/nudy/inc/TNuList2.h"
#include "/home/i/nudy/inc/TNuTab1ListsSub.h"
#include "/home/i/nudy/inc/TNuResoAdlerAdler.h"
#include "/home/i/nudy/inc/TNuTab3Tab2.h"
#include "/home/i/nudy/inc/TNuTab3Tab1Lists.h"
#include "/home/i/nudy/inc/TNuRecsWithCont.h"
#include "/home/i/nudy/inc/TNuFile.h"
#include "/home/i/nudy/inc/TNuRecs.h"
#include "/home/i/nudy/inc/TNuListFPY.h"
#include "/home/i/nudy/inc/TNuSec26.h"
#include "/home/i/nudy/inc/TNuList1Tab1.h"
#include "/home/i/nudy/inc/TNuSec12.h"
#include "/home/i/nudy/inc/TNuSec01460.h"
#include "/home/i/nudy/inc/TNuLazyCollection.h"
#include "/home/i/nudy/inc/TNuResoBrightWigner.h"
#include "/home/i/nudy/inc/TNuSec08454.h"
#include "/home/i/nudy/inc/TNuList2Tab1.h"
#include "/home/i/nudy/inc/TNuSec23.h"
#include "/home/i/nudy/inc/TNuTab3List2.h"

// Header files passed via #pragma extra_include

namespace TNuMath {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *TNuMath_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("TNuMath", 0 /*version*/, "TNuMath.h", 10,
                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0),
                     &TNuMath_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *TNuMath_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static void *new_TNuLabel(void *p = 0);
   static void *newArray_TNuLabel(Long_t size, void *p);
   static void delete_TNuLabel(void *p);
   static void deleteArray_TNuLabel(void *p);
   static void destruct_TNuLabel(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuLabel*)
   {
      ::TNuLabel *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuLabel >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuLabel", ::TNuLabel::Class_Version(), "TNuLabel.h", 36,
                  typeid(::TNuLabel), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuLabel::Dictionary, isa_proxy, 4,
                  sizeof(::TNuLabel) );
      instance.SetNew(&new_TNuLabel);
      instance.SetNewArray(&newArray_TNuLabel);
      instance.SetDelete(&delete_TNuLabel);
      instance.SetDeleteArray(&deleteArray_TNuLabel);
      instance.SetDestructor(&destruct_TNuLabel);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuLabel*)
   {
      return GenerateInitInstanceLocal((::TNuLabel*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuLabel*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuObject(void *p = 0);
   static void *newArray_TNuObject(Long_t size, void *p);
   static void delete_TNuObject(void *p);
   static void deleteArray_TNuObject(void *p);
   static void destruct_TNuObject(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuObject*)
   {
      ::TNuObject *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuObject >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuObject", ::TNuObject::Class_Version(), "TNuObject.h", 30,
                  typeid(::TNuObject), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuObject::Dictionary, isa_proxy, 4,
                  sizeof(::TNuObject) );
      instance.SetNew(&new_TNuObject);
      instance.SetNewArray(&newArray_TNuObject);
      instance.SetDelete(&delete_TNuObject);
      instance.SetDeleteArray(&deleteArray_TNuObject);
      instance.SetDestructor(&destruct_TNuObject);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuObject*)
   {
      return GenerateInitInstanceLocal((::TNuObject*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuObject*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuVF1(void *p);
   static void deleteArray_TNuVF1(void *p);
   static void destruct_TNuVF1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuVF1*)
   {
      ::TNuVF1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuVF1 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuVF1", ::TNuVF1::Class_Version(), "TNuVF1.h", 31,
                  typeid(::TNuVF1), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuVF1::Dictionary, isa_proxy, 4,
                  sizeof(::TNuVF1) );
      instance.SetDelete(&delete_TNuVF1);
      instance.SetDeleteArray(&deleteArray_TNuVF1);
      instance.SetDestructor(&destruct_TNuVF1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuVF1*)
   {
      return GenerateInitInstanceLocal((::TNuVF1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuVF1*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuVF1s(void *p);
   static void deleteArray_TNuVF1s(void *p);
   static void destruct_TNuVF1s(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuVF1s*)
   {
      ::TNuVF1s *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuVF1s >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuVF1s", ::TNuVF1s::Class_Version(), "TNuVF1s.h", 30,
                  typeid(::TNuVF1s), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuVF1s::Dictionary, isa_proxy, 4,
                  sizeof(::TNuVF1s) );
      instance.SetDelete(&delete_TNuVF1s);
      instance.SetDeleteArray(&deleteArray_TNuVF1s);
      instance.SetDestructor(&destruct_TNuVF1s);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuVF1s*)
   {
      return GenerateInitInstanceLocal((::TNuVF1s*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuVF1s*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuVResonance(void *p);
   static void deleteArray_TNuVResonance(void *p);
   static void destruct_TNuVResonance(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuVResonance*)
   {
      ::TNuVResonance *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuVResonance >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuVResonance", ::TNuVResonance::Class_Version(), "TNuVResonance.h", 24,
                  typeid(::TNuVResonance), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuVResonance::Dictionary, isa_proxy, 4,
                  sizeof(::TNuVResonance) );
      instance.SetDelete(&delete_TNuVResonance);
      instance.SetDeleteArray(&deleteArray_TNuVResonance);
      instance.SetDestructor(&destruct_TNuVResonance);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuVResonance*)
   {
      return GenerateInitInstanceLocal((::TNuVResonance*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuVResonance*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuSaveToTextDlg(void *p);
   static void deleteArray_TNuSaveToTextDlg(void *p);
   static void destruct_TNuSaveToTextDlg(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSaveToTextDlg*)
   {
      ::TNuSaveToTextDlg *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSaveToTextDlg >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSaveToTextDlg", ::TNuSaveToTextDlg::Class_Version(), "TNuSaveToTextDlg.h", 31,
                  typeid(::TNuSaveToTextDlg), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSaveToTextDlg::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSaveToTextDlg) );
      instance.SetDelete(&delete_TNuSaveToTextDlg);
      instance.SetDeleteArray(&deleteArray_TNuSaveToTextDlg);
      instance.SetDestructor(&destruct_TNuSaveToTextDlg);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSaveToTextDlg*)
   {
      return GenerateInitInstanceLocal((::TNuSaveToTextDlg*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSaveToTextDlg*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_MyFileDlg(void *p);
   static void deleteArray_MyFileDlg(void *p);
   static void destruct_MyFileDlg(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyFileDlg*)
   {
      ::MyFileDlg *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyFileDlg >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyFileDlg", ::MyFileDlg::Class_Version(), "TNuSaveToTextDlg.h", 74,
                  typeid(::MyFileDlg), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::MyFileDlg::Dictionary, isa_proxy, 4,
                  sizeof(::MyFileDlg) );
      instance.SetDelete(&delete_MyFileDlg);
      instance.SetDeleteArray(&deleteArray_MyFileDlg);
      instance.SetDestructor(&destruct_MyFileDlg);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyFileDlg*)
   {
      return GenerateInitInstanceLocal((::MyFileDlg*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MyFileDlg*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuPrinter(void *p);
   static void deleteArray_TNuPrinter(void *p);
   static void destruct_TNuPrinter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuPrinter*)
   {
      ::TNuPrinter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuPrinter >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuPrinter", ::TNuPrinter::Class_Version(), "TNuPrinter.h", 30,
                  typeid(::TNuPrinter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuPrinter::Dictionary, isa_proxy, 4,
                  sizeof(::TNuPrinter) );
      instance.SetDelete(&delete_TNuPrinter);
      instance.SetDeleteArray(&deleteArray_TNuPrinter);
      instance.SetDestructor(&destruct_TNuPrinter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuPrinter*)
   {
      return GenerateInitInstanceLocal((::TNuPrinter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuPrinter*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuCont(void *p = 0);
   static void *newArray_TNuCont(Long_t size, void *p);
   static void delete_TNuCont(void *p);
   static void deleteArray_TNuCont(void *p);
   static void destruct_TNuCont(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuCont*)
   {
      ::TNuCont *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuCont >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuCont", ::TNuCont::Class_Version(), "TNuCont.h", 19,
                  typeid(::TNuCont), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuCont::Dictionary, isa_proxy, 4,
                  sizeof(::TNuCont) );
      instance.SetNew(&new_TNuCont);
      instance.SetNewArray(&newArray_TNuCont);
      instance.SetDelete(&delete_TNuCont);
      instance.SetDeleteArray(&deleteArray_TNuCont);
      instance.SetDestructor(&destruct_TNuCont);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuCont*)
   {
      return GenerateInitInstanceLocal((::TNuCont*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuCont*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuRecs(void *p = 0);
   static void *newArray_TNuRecs(Long_t size, void *p);
   static void delete_TNuRecs(void *p);
   static void deleteArray_TNuRecs(void *p);
   static void destruct_TNuRecs(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuRecs*)
   {
      ::TNuRecs *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuRecs >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuRecs", ::TNuRecs::Class_Version(), "TNuRecs.h", 57,
                  typeid(::TNuRecs), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuRecs::Dictionary, isa_proxy, 4,
                  sizeof(::TNuRecs) );
      instance.SetNew(&new_TNuRecs);
      instance.SetNewArray(&newArray_TNuRecs);
      instance.SetDelete(&delete_TNuRecs);
      instance.SetDeleteArray(&deleteArray_TNuRecs);
      instance.SetDestructor(&destruct_TNuRecs);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuRecs*)
   {
      return GenerateInitInstanceLocal((::TNuRecs*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuRecs*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSection(void *p = 0);
   static void *newArray_TNuSection(Long_t size, void *p);
   static void delete_TNuSection(void *p);
   static void deleteArray_TNuSection(void *p);
   static void destruct_TNuSection(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSection*)
   {
      ::TNuSection *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSection >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSection", ::TNuSection::Class_Version(), "TNuSection.h", 25,
                  typeid(::TNuSection), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSection::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSection) );
      instance.SetNew(&new_TNuSection);
      instance.SetNewArray(&newArray_TNuSection);
      instance.SetDelete(&delete_TNuSection);
      instance.SetDeleteArray(&deleteArray_TNuSection);
      instance.SetDestructor(&destruct_TNuSection);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSection*)
   {
      return GenerateInitInstanceLocal((::TNuSection*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSection*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuVTab(void *p);
   static void deleteArray_TNuVTab(void *p);
   static void destruct_TNuVTab(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuVTab*)
   {
      ::TNuVTab *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuVTab >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuVTab", ::TNuVTab::Class_Version(), "TNuVTab.h", 24,
                  typeid(::TNuVTab), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuVTab::Dictionary, isa_proxy, 4,
                  sizeof(::TNuVTab) );
      instance.SetDelete(&delete_TNuVTab);
      instance.SetDeleteArray(&deleteArray_TNuVTab);
      instance.SetDestructor(&destruct_TNuVTab);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuVTab*)
   {
      return GenerateInitInstanceLocal((::TNuVTab*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuVTab*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuEndfTAB2(void *p = 0);
   static void *newArray_TNuEndfTAB2(Long_t size, void *p);
   static void delete_TNuEndfTAB2(void *p);
   static void deleteArray_TNuEndfTAB2(void *p);
   static void destruct_TNuEndfTAB2(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuEndfTAB2*)
   {
      ::TNuEndfTAB2 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuEndfTAB2 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuEndfTAB2", ::TNuEndfTAB2::Class_Version(), "TNuEndfTAB2.h", 26,
                  typeid(::TNuEndfTAB2), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuEndfTAB2::Dictionary, isa_proxy, 4,
                  sizeof(::TNuEndfTAB2) );
      instance.SetNew(&new_TNuEndfTAB2);
      instance.SetNewArray(&newArray_TNuEndfTAB2);
      instance.SetDelete(&delete_TNuEndfTAB2);
      instance.SetDeleteArray(&deleteArray_TNuEndfTAB2);
      instance.SetDestructor(&destruct_TNuEndfTAB2);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuEndfTAB2*)
   {
      return GenerateInitInstanceLocal((::TNuEndfTAB2*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuEndfTAB2*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuTab1(void *p = 0);
   static void *newArray_TNuTab1(Long_t size, void *p);
   static void delete_TNuTab1(void *p);
   static void deleteArray_TNuTab1(void *p);
   static void destruct_TNuTab1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab1*)
   {
      ::TNuTab1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab1 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab1", ::TNuTab1::Class_Version(), "TNuTab1.h", 22,
                  typeid(::TNuTab1), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab1::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab1) );
      instance.SetNew(&new_TNuTab1);
      instance.SetNewArray(&newArray_TNuTab1);
      instance.SetDelete(&delete_TNuTab1);
      instance.SetDeleteArray(&deleteArray_TNuTab1);
      instance.SetDestructor(&destruct_TNuTab1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab1*)
   {
      return GenerateInitInstanceLocal((::TNuTab1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab1*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuEndfIO(void *p);
   static void deleteArray_TNuEndfIO(void *p);
   static void destruct_TNuEndfIO(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuEndfIO*)
   {
      ::TNuEndfIO *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuEndfIO >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuEndfIO", ::TNuEndfIO::Class_Version(), "TNuEndfIO.h", 22,
                  typeid(::TNuEndfIO), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuEndfIO::Dictionary, isa_proxy, 4,
                  sizeof(::TNuEndfIO) );
      instance.SetDelete(&delete_TNuEndfIO);
      instance.SetDeleteArray(&deleteArray_TNuEndfIO);
      instance.SetDestructor(&destruct_TNuEndfIO);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuEndfIO*)
   {
      return GenerateInitInstanceLocal((::TNuEndfIO*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuEndfIO*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec13(void *p = 0);
   static void *newArray_TNuSec13(Long_t size, void *p);
   static void delete_TNuSec13(void *p);
   static void deleteArray_TNuSec13(void *p);
   static void destruct_TNuSec13(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec13*)
   {
      ::TNuSec13 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec13 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec13", ::TNuSec13::Class_Version(), "TNuSec13.h", 36,
                  typeid(::TNuSec13), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec13::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec13) );
      instance.SetNew(&new_TNuSec13);
      instance.SetNewArray(&newArray_TNuSec13);
      instance.SetDelete(&delete_TNuSec13);
      instance.SetDeleteArray(&deleteArray_TNuSec13);
      instance.SetDestructor(&destruct_TNuSec13);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec13*)
   {
      return GenerateInitInstanceLocal((::TNuSec13*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec13*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec10(void *p = 0);
   static void *newArray_TNuSec10(Long_t size, void *p);
   static void delete_TNuSec10(void *p);
   static void deleteArray_TNuSec10(void *p);
   static void destruct_TNuSec10(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec10*)
   {
      ::TNuSec10 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec10 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec10", ::TNuSec10::Class_Version(), "TNuSec10.h", 40,
                  typeid(::TNuSec10), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec10::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec10) );
      instance.SetNew(&new_TNuSec10);
      instance.SetNewArray(&newArray_TNuSec10);
      instance.SetDelete(&delete_TNuSec10);
      instance.SetDeleteArray(&deleteArray_TNuSec10);
      instance.SetDestructor(&destruct_TNuSec10);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec10*)
   {
      return GenerateInitInstanceLocal((::TNuSec10*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec10*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec09(void *p = 0);
   static void *newArray_TNuSec09(Long_t size, void *p);
   static void delete_TNuSec09(void *p);
   static void deleteArray_TNuSec09(void *p);
   static void destruct_TNuSec09(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec09*)
   {
      ::TNuSec09 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec09 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec09", ::TNuSec09::Class_Version(), "TNuSec09.h", 28,
                  typeid(::TNuSec09), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec09::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec09) );
      instance.SetNew(&new_TNuSec09);
      instance.SetNewArray(&newArray_TNuSec09);
      instance.SetDelete(&delete_TNuSec09);
      instance.SetDeleteArray(&deleteArray_TNuSec09);
      instance.SetDestructor(&destruct_TNuSec09);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec09*)
   {
      return GenerateInitInstanceLocal((::TNuSec09*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec09*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuCollection(void *p);
   static void deleteArray_TNuCollection(void *p);
   static void destruct_TNuCollection(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuCollection*)
   {
      ::TNuCollection *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuCollection >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuCollection", ::TNuCollection::Class_Version(), "TNuCollection.h", 18,
                  typeid(::TNuCollection), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuCollection::Dictionary, isa_proxy, 4,
                  sizeof(::TNuCollection) );
      instance.SetDelete(&delete_TNuCollection);
      instance.SetDeleteArray(&deleteArray_TNuCollection);
      instance.SetDestructor(&destruct_TNuCollection);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuCollection*)
   {
      return GenerateInitInstanceLocal((::TNuCollection*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuCollection*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuIter(void *p);
   static void deleteArray_TNuIter(void *p);
   static void destruct_TNuIter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuIter*)
   {
      ::TNuIter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuIter >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuIter", ::TNuIter::Class_Version(), "TNuCollection.h", 70,
                  typeid(::TNuIter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuIter::Dictionary, isa_proxy, 4,
                  sizeof(::TNuIter) );
      instance.SetDelete(&delete_TNuIter);
      instance.SetDeleteArray(&deleteArray_TNuIter);
      instance.SetDestructor(&destruct_TNuIter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuIter*)
   {
      return GenerateInitInstanceLocal((::TNuIter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuIter*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuLazyCollection(void *p = 0);
   static void *newArray_TNuLazyCollection(Long_t size, void *p);
   static void delete_TNuLazyCollection(void *p);
   static void deleteArray_TNuLazyCollection(void *p);
   static void destruct_TNuLazyCollection(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuLazyCollection*)
   {
      ::TNuLazyCollection *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuLazyCollection >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuLazyCollection", ::TNuLazyCollection::Class_Version(), "TNuLazyCollection.h", 29,
                  typeid(::TNuLazyCollection), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuLazyCollection::Dictionary, isa_proxy, 4,
                  sizeof(::TNuLazyCollection) );
      instance.SetNew(&new_TNuLazyCollection);
      instance.SetNewArray(&newArray_TNuLazyCollection);
      instance.SetDelete(&delete_TNuLazyCollection);
      instance.SetDeleteArray(&deleteArray_TNuLazyCollection);
      instance.SetDestructor(&destruct_TNuLazyCollection);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuLazyCollection*)
   {
      return GenerateInitInstanceLocal((::TNuLazyCollection*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuLazyCollection*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuFile(void *p = 0);
   static void *newArray_TNuFile(Long_t size, void *p);
   static void delete_TNuFile(void *p);
   static void deleteArray_TNuFile(void *p);
   static void destruct_TNuFile(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuFile*)
   {
      ::TNuFile *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuFile >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuFile", ::TNuFile::Class_Version(), "TNuFile.h", 29,
                  typeid(::TNuFile), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuFile::Dictionary, isa_proxy, 4,
                  sizeof(::TNuFile) );
      instance.SetNew(&new_TNuFile);
      instance.SetNewArray(&newArray_TNuFile);
      instance.SetDelete(&delete_TNuFile);
      instance.SetDeleteArray(&deleteArray_TNuFile);
      instance.SetDestructor(&destruct_TNuFile);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuFile*)
   {
      return GenerateInitInstanceLocal((::TNuFile*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuFile*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuMat(void *p = 0);
   static void *newArray_TNuMat(Long_t size, void *p);
   static void delete_TNuMat(void *p);
   static void deleteArray_TNuMat(void *p);
   static void destruct_TNuMat(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuMat*)
   {
      ::TNuMat *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuMat >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuMat", ::TNuMat::Class_Version(), "TNuMat.h", 32,
                  typeid(::TNuMat), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuMat::Dictionary, isa_proxy, 4,
                  sizeof(::TNuMat) );
      instance.SetNew(&new_TNuMat);
      instance.SetNewArray(&newArray_TNuMat);
      instance.SetDelete(&delete_TNuMat);
      instance.SetDeleteArray(&deleteArray_TNuMat);
      instance.SetDestructor(&destruct_TNuMat);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuMat*)
   {
      return GenerateInitInstanceLocal((::TNuMat*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuMat*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSublib(void *p = 0);
   static void *newArray_TNuSublib(Long_t size, void *p);
   static void delete_TNuSublib(void *p);
   static void deleteArray_TNuSublib(void *p);
   static void destruct_TNuSublib(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSublib*)
   {
      ::TNuSublib *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSublib >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSublib", ::TNuSublib::Class_Version(), "TNuSublib.h", 28,
                  typeid(::TNuSublib), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSublib::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSublib) );
      instance.SetNew(&new_TNuSublib);
      instance.SetNewArray(&newArray_TNuSublib);
      instance.SetDelete(&delete_TNuSublib);
      instance.SetDeleteArray(&deleteArray_TNuSublib);
      instance.SetDestructor(&destruct_TNuSublib);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSublib*)
   {
      return GenerateInitInstanceLocal((::TNuSublib*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSublib*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuLib(void *p = 0);
   static void *newArray_TNuLib(Long_t size, void *p);
   static void delete_TNuLib(void *p);
   static void deleteArray_TNuLib(void *p);
   static void destruct_TNuLib(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuLib*)
   {
      ::TNuLib *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuLib >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuLib", ::TNuLib::Class_Version(), "TNuLib.h", 35,
                  typeid(::TNuLib), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuLib::Dictionary, isa_proxy, 4,
                  sizeof(::TNuLib) );
      instance.SetNew(&new_TNuLib);
      instance.SetNewArray(&newArray_TNuLib);
      instance.SetDelete(&delete_TNuLib);
      instance.SetDeleteArray(&deleteArray_TNuLib);
      instance.SetDestructor(&destruct_TNuLib);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuLib*)
   {
      return GenerateInitInstanceLocal((::TNuLib*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuLib*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuIntg(void *p = 0);
   static void *newArray_TNuIntg(Long_t size, void *p);
   static void delete_TNuIntg(void *p);
   static void deleteArray_TNuIntg(void *p);
   static void destruct_TNuIntg(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuIntg*)
   {
      ::TNuIntg *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuIntg >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuIntg", ::TNuIntg::Class_Version(), "TNuIntg.h", 23,
                  typeid(::TNuIntg), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuIntg::Dictionary, isa_proxy, 4,
                  sizeof(::TNuIntg) );
      instance.SetNew(&new_TNuIntg);
      instance.SetNewArray(&newArray_TNuIntg);
      instance.SetDelete(&delete_TNuIntg);
      instance.SetDeleteArray(&deleteArray_TNuIntg);
      instance.SetDestructor(&destruct_TNuIntg);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuIntg*)
   {
      return GenerateInitInstanceLocal((::TNuIntg*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuIntg*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuRecsWithCont(void *p = 0);
   static void *newArray_TNuRecsWithCont(Long_t size, void *p);
   static void delete_TNuRecsWithCont(void *p);
   static void deleteArray_TNuRecsWithCont(void *p);
   static void destruct_TNuRecsWithCont(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuRecsWithCont*)
   {
      ::TNuRecsWithCont *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuRecsWithCont >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuRecsWithCont", ::TNuRecsWithCont::Class_Version(), "TNuRecsWithCont.h", 31,
                  typeid(::TNuRecsWithCont), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuRecsWithCont::Dictionary, isa_proxy, 4,
                  sizeof(::TNuRecsWithCont) );
      instance.SetNew(&new_TNuRecsWithCont);
      instance.SetNewArray(&newArray_TNuRecsWithCont);
      instance.SetDelete(&delete_TNuRecsWithCont);
      instance.SetDeleteArray(&deleteArray_TNuRecsWithCont);
      instance.SetDestructor(&destruct_TNuRecsWithCont);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuRecsWithCont*)
   {
      return GenerateInitInstanceLocal((::TNuRecsWithCont*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuRecsWithCont*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuList(void *p = 0);
   static void *newArray_TNuList(Long_t size, void *p);
   static void delete_TNuList(void *p);
   static void deleteArray_TNuList(void *p);
   static void destruct_TNuList(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuList*)
   {
      ::TNuList *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuList >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuList", ::TNuList::Class_Version(), "TNuList.h", 19,
                  typeid(::TNuList), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuList::Dictionary, isa_proxy, 4,
                  sizeof(::TNuList) );
      instance.SetNew(&new_TNuList);
      instance.SetNewArray(&newArray_TNuList);
      instance.SetDelete(&delete_TNuList);
      instance.SetDeleteArray(&deleteArray_TNuList);
      instance.SetDestructor(&destruct_TNuList);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuList*)
   {
      return GenerateInitInstanceLocal((::TNuList*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuList*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuContLists(void *p = 0);
   static void *newArray_TNuContLists(Long_t size, void *p);
   static void delete_TNuContLists(void *p);
   static void deleteArray_TNuContLists(void *p);
   static void destruct_TNuContLists(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuContLists*)
   {
      ::TNuContLists *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuContLists >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuContLists", ::TNuContLists::Class_Version(), "TNuContLists.h", 21,
                  typeid(::TNuContLists), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuContLists::Dictionary, isa_proxy, 4,
                  sizeof(::TNuContLists) );
      instance.SetNew(&new_TNuContLists);
      instance.SetNewArray(&newArray_TNuContLists);
      instance.SetDelete(&delete_TNuContLists);
      instance.SetDeleteArray(&deleteArray_TNuContLists);
      instance.SetDestructor(&destruct_TNuContLists);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuContLists*)
   {
      return GenerateInitInstanceLocal((::TNuContLists*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuContLists*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuVF2(void *p);
   static void deleteArray_TNuVF2(void *p);
   static void destruct_TNuVF2(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuVF2*)
   {
      ::TNuVF2 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuVF2 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuVF2", ::TNuVF2::Class_Version(), "TNuVF2.h", 32,
                  typeid(::TNuVF2), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuVF2::Dictionary, isa_proxy, 4,
                  sizeof(::TNuVF2) );
      instance.SetDelete(&delete_TNuVF2);
      instance.SetDeleteArray(&deleteArray_TNuVF2);
      instance.SetDestructor(&destruct_TNuVF2);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuVF2*)
   {
      return GenerateInitInstanceLocal((::TNuVF2*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuVF2*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuTab1Lists(void *p = 0);
   static void *newArray_TNuTab1Lists(Long_t size, void *p);
   static void delete_TNuTab1Lists(void *p);
   static void deleteArray_TNuTab1Lists(void *p);
   static void destruct_TNuTab1Lists(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab1Lists*)
   {
      ::TNuTab1Lists *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab1Lists >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab1Lists", ::TNuTab1Lists::Class_Version(), "TNuTab1Lists.h", 38,
                  typeid(::TNuTab1Lists), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab1Lists::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab1Lists) );
      instance.SetNew(&new_TNuTab1Lists);
      instance.SetNewArray(&newArray_TNuTab1Lists);
      instance.SetDelete(&delete_TNuTab1Lists);
      instance.SetDeleteArray(&deleteArray_TNuTab1Lists);
      instance.SetDestructor(&destruct_TNuTab1Lists);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab1Lists*)
   {
      return GenerateInitInstanceLocal((::TNuTab1Lists*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab1Lists*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuList1(void *p);
   static void deleteArray_TNuList1(void *p);
   static void destruct_TNuList1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuList1*)
   {
      ::TNuList1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuList1 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuList1", ::TNuList1::Class_Version(), "TNuList1.h", 20,
                  typeid(::TNuList1), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuList1::Dictionary, isa_proxy, 4,
                  sizeof(::TNuList1) );
      instance.SetDelete(&delete_TNuList1);
      instance.SetDeleteArray(&deleteArray_TNuList1);
      instance.SetDestructor(&destruct_TNuList1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuList1*)
   {
      return GenerateInitInstanceLocal((::TNuList1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuList1*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuListTaylor(void *p = 0);
   static void *newArray_TNuListTaylor(Long_t size, void *p);
   static void delete_TNuListTaylor(void *p);
   static void deleteArray_TNuListTaylor(void *p);
   static void destruct_TNuListTaylor(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuListTaylor*)
   {
      ::TNuListTaylor *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuListTaylor >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuListTaylor", ::TNuListTaylor::Class_Version(), "TNuListTaylor.h", 20,
                  typeid(::TNuListTaylor), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuListTaylor::Dictionary, isa_proxy, 4,
                  sizeof(::TNuListTaylor) );
      instance.SetNew(&new_TNuListTaylor);
      instance.SetNewArray(&newArray_TNuListTaylor);
      instance.SetDelete(&delete_TNuListTaylor);
      instance.SetDeleteArray(&deleteArray_TNuListTaylor);
      instance.SetDestructor(&destruct_TNuListTaylor);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuListTaylor*)
   {
      return GenerateInitInstanceLocal((::TNuListTaylor*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuListTaylor*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuRecsWithTAB2(void *p = 0);
   static void *newArray_TNuRecsWithTAB2(Long_t size, void *p);
   static void delete_TNuRecsWithTAB2(void *p);
   static void deleteArray_TNuRecsWithTAB2(void *p);
   static void destruct_TNuRecsWithTAB2(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuRecsWithTAB2*)
   {
      ::TNuRecsWithTAB2 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuRecsWithTAB2 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuRecsWithTAB2", ::TNuRecsWithTAB2::Class_Version(), "TNuRecsWithTAB2.h", 27,
                  typeid(::TNuRecsWithTAB2), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuRecsWithTAB2::Dictionary, isa_proxy, 4,
                  sizeof(::TNuRecsWithTAB2) );
      instance.SetNew(&new_TNuRecsWithTAB2);
      instance.SetNewArray(&newArray_TNuRecsWithTAB2);
      instance.SetDelete(&delete_TNuRecsWithTAB2);
      instance.SetDeleteArray(&deleteArray_TNuRecsWithTAB2);
      instance.SetDestructor(&destruct_TNuRecsWithTAB2);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuRecsWithTAB2*)
   {
      return GenerateInitInstanceLocal((::TNuRecsWithTAB2*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuRecsWithTAB2*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuTab2(void *p);
   static void deleteArray_TNuTab2(void *p);
   static void destruct_TNuTab2(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab2*)
   {
      ::TNuTab2 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab2 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab2", ::TNuTab2::Class_Version(), "TNuTab2.h", 25,
                  typeid(::TNuTab2), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab2::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab2) );
      instance.SetDelete(&delete_TNuTab2);
      instance.SetDeleteArray(&deleteArray_TNuTab2);
      instance.SetDestructor(&destruct_TNuTab2);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab2*)
   {
      return GenerateInitInstanceLocal((::TNuTab2*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab2*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuRecsWithTab1(void *p = 0);
   static void *newArray_TNuRecsWithTab1(Long_t size, void *p);
   static void delete_TNuRecsWithTab1(void *p);
   static void deleteArray_TNuRecsWithTab1(void *p);
   static void destruct_TNuRecsWithTab1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuRecsWithTab1*)
   {
      ::TNuRecsWithTab1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuRecsWithTab1 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuRecsWithTab1", ::TNuRecsWithTab1::Class_Version(), "TNuRecsWithTab1.h", 23,
                  typeid(::TNuRecsWithTab1), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuRecsWithTab1::Dictionary, isa_proxy, 4,
                  sizeof(::TNuRecsWithTab1) );
      instance.SetNew(&new_TNuRecsWithTab1);
      instance.SetNewArray(&newArray_TNuRecsWithTab1);
      instance.SetDelete(&delete_TNuRecsWithTab1);
      instance.SetDeleteArray(&deleteArray_TNuRecsWithTab1);
      instance.SetDestructor(&destruct_TNuRecsWithTab1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuRecsWithTab1*)
   {
      return GenerateInitInstanceLocal((::TNuRecsWithTab1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuRecsWithTab1*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec15(void *p = 0);
   static void *newArray_TNuSec15(Long_t size, void *p);
   static void delete_TNuSec15(void *p);
   static void deleteArray_TNuSec15(void *p);
   static void destruct_TNuSec15(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec15*)
   {
      ::TNuSec15 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec15 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec15", ::TNuSec15::Class_Version(), "TNuSec15.h", 30,
                  typeid(::TNuSec15), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec15::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec15) );
      instance.SetNew(&new_TNuSec15);
      instance.SetNewArray(&newArray_TNuSec15);
      instance.SetDelete(&delete_TNuSec15);
      instance.SetDeleteArray(&deleteArray_TNuSec15);
      instance.SetDestructor(&destruct_TNuSec15);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec15*)
   {
      return GenerateInitInstanceLocal((::TNuSec15*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec15*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResonance(void *p = 0);
   static void *newArray_TNuResonance(Long_t size, void *p);
   static void delete_TNuResonance(void *p);
   static void deleteArray_TNuResonance(void *p);
   static void destruct_TNuResonance(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResonance*)
   {
      ::TNuResonance *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResonance >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResonance", ::TNuResonance::Class_Version(), "TNuResonance.h", 48,
                  typeid(::TNuResonance), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResonance::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResonance) );
      instance.SetNew(&new_TNuResonance);
      instance.SetNewArray(&newArray_TNuResonance);
      instance.SetDelete(&delete_TNuResonance);
      instance.SetDeleteArray(&deleteArray_TNuResonance);
      instance.SetDestructor(&destruct_TNuResonance);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResonance*)
   {
      return GenerateInitInstanceLocal((::TNuResonance*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResonance*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoResolved(void *p = 0);
   static void *newArray_TNuResoResolved(Long_t size, void *p);
   static void delete_TNuResoResolved(void *p);
   static void deleteArray_TNuResoResolved(void *p);
   static void destruct_TNuResoResolved(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoResolved*)
   {
      ::TNuResoResolved *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoResolved >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoResolved", ::TNuResoResolved::Class_Version(), "TNuResoResolved.h", 22,
                  typeid(::TNuResoResolved), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoResolved::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoResolved) );
      instance.SetNew(&new_TNuResoResolved);
      instance.SetNewArray(&newArray_TNuResoResolved);
      instance.SetDelete(&delete_TNuResoResolved);
      instance.SetDeleteArray(&deleteArray_TNuResoResolved);
      instance.SetDestructor(&destruct_TNuResoResolved);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoResolved*)
   {
      return GenerateInitInstanceLocal((::TNuResoResolved*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoResolved*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec04(void *p = 0);
   static void *newArray_TNuSec04(Long_t size, void *p);
   static void delete_TNuSec04(void *p);
   static void deleteArray_TNuSec04(void *p);
   static void destruct_TNuSec04(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec04*)
   {
      ::TNuSec04 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec04 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec04", ::TNuSec04::Class_Version(), "TNuSec04.h", 45,
                  typeid(::TNuSec04), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec04::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec04) );
      instance.SetNew(&new_TNuSec04);
      instance.SetNewArray(&newArray_TNuSec04);
      instance.SetDelete(&delete_TNuSec04);
      instance.SetDeleteArray(&deleteArray_TNuSec04);
      instance.SetDestructor(&destruct_TNuSec04);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec04*)
   {
      return GenerateInitInstanceLocal((::TNuSec04*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec04*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuListLegendre(void *p = 0);
   static void *newArray_TNuListLegendre(Long_t size, void *p);
   static void delete_TNuListLegendre(void *p);
   static void deleteArray_TNuListLegendre(void *p);
   static void destruct_TNuListLegendre(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuListLegendre*)
   {
      ::TNuListLegendre *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuListLegendre >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuListLegendre", ::TNuListLegendre::Class_Version(), "TNuListLegendre.h", 24,
                  typeid(::TNuListLegendre), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuListLegendre::Dictionary, isa_proxy, 4,
                  sizeof(::TNuListLegendre) );
      instance.SetNew(&new_TNuListLegendre);
      instance.SetNewArray(&newArray_TNuListLegendre);
      instance.SetDelete(&delete_TNuListLegendre);
      instance.SetDeleteArray(&deleteArray_TNuListLegendre);
      instance.SetDestructor(&destruct_TNuListLegendre);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuListLegendre*)
   {
      return GenerateInitInstanceLocal((::TNuListLegendre*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuListLegendre*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec03(void *p = 0);
   static void *newArray_TNuSec03(Long_t size, void *p);
   static void delete_TNuSec03(void *p);
   static void deleteArray_TNuSec03(void *p);
   static void destruct_TNuSec03(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec03*)
   {
      ::TNuSec03 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec03 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec03", ::TNuSec03::Class_Version(), "TNuSec03.h", 29,
                  typeid(::TNuSec03), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec03::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec03) );
      instance.SetNew(&new_TNuSec03);
      instance.SetNewArray(&newArray_TNuSec03);
      instance.SetDelete(&delete_TNuSec03);
      instance.SetDeleteArray(&deleteArray_TNuSec03);
      instance.SetDestructor(&destruct_TNuSec03);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec03*)
   {
      return GenerateInitInstanceLocal((::TNuSec03*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec03*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuVF3(void *p);
   static void deleteArray_TNuVF3(void *p);
   static void destruct_TNuVF3(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuVF3*)
   {
      ::TNuVF3 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuVF3 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuVF3", ::TNuVF3::Class_Version(), "TNuVF3.h", 36,
                  typeid(::TNuVF3), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuVF3::Dictionary, isa_proxy, 4,
                  sizeof(::TNuVF3) );
      instance.SetDelete(&delete_TNuVF3);
      instance.SetDeleteArray(&deleteArray_TNuVF3);
      instance.SetDestructor(&destruct_TNuVF3);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuVF3*)
   {
      return GenerateInitInstanceLocal((::TNuVF3*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuVF3*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuTab3(void *p);
   static void deleteArray_TNuTab3(void *p);
   static void destruct_TNuTab3(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab3*)
   {
      ::TNuTab3 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab3 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab3", ::TNuTab3::Class_Version(), "TNuTab3.h", 25,
                  typeid(::TNuTab3), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab3::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab3) );
      instance.SetDelete(&delete_TNuTab3);
      instance.SetDeleteArray(&deleteArray_TNuTab3);
      instance.SetDestructor(&destruct_TNuTab3);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab3*)
   {
      return GenerateInitInstanceLocal((::TNuTab3*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab3*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec06(void *p = 0);
   static void *newArray_TNuSec06(Long_t size, void *p);
   static void delete_TNuSec06(void *p);
   static void deleteArray_TNuSec06(void *p);
   static void destruct_TNuSec06(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec06*)
   {
      ::TNuSec06 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec06 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec06", ::TNuSec06::Class_Version(), "TNuSec06.h", 29,
                  typeid(::TNuSec06), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec06::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec06) );
      instance.SetNew(&new_TNuSec06);
      instance.SetNewArray(&newArray_TNuSec06);
      instance.SetDelete(&delete_TNuSec06);
      instance.SetDeleteArray(&deleteArray_TNuSec06);
      instance.SetDestructor(&destruct_TNuSec06);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec06*)
   {
      return GenerateInitInstanceLocal((::TNuSec06*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec06*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec07002(void *p = 0);
   static void *newArray_TNuSec07002(Long_t size, void *p);
   static void delete_TNuSec07002(void *p);
   static void deleteArray_TNuSec07002(void *p);
   static void destruct_TNuSec07002(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec07002*)
   {
      ::TNuSec07002 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec07002 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec07002", ::TNuSec07002::Class_Version(), "TNuSec07002.h", 31,
                  typeid(::TNuSec07002), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec07002::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec07002) );
      instance.SetNew(&new_TNuSec07002);
      instance.SetNewArray(&newArray_TNuSec07002);
      instance.SetDelete(&delete_TNuSec07002);
      instance.SetDeleteArray(&deleteArray_TNuSec07002);
      instance.SetDestructor(&destruct_TNuSec07002);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec07002*)
   {
      return GenerateInitInstanceLocal((::TNuSec07002*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec07002*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec07002Coherent(void *p = 0);
   static void *newArray_TNuSec07002Coherent(Long_t size, void *p);
   static void delete_TNuSec07002Coherent(void *p);
   static void deleteArray_TNuSec07002Coherent(void *p);
   static void destruct_TNuSec07002Coherent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec07002Coherent*)
   {
      ::TNuSec07002Coherent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec07002Coherent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec07002Coherent", ::TNuSec07002Coherent::Class_Version(), "TNuSec07002Coherent.h", 51,
                  typeid(::TNuSec07002Coherent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec07002Coherent::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec07002Coherent) );
      instance.SetNew(&new_TNuSec07002Coherent);
      instance.SetNewArray(&newArray_TNuSec07002Coherent);
      instance.SetDelete(&delete_TNuSec07002Coherent);
      instance.SetDeleteArray(&deleteArray_TNuSec07002Coherent);
      instance.SetDestructor(&destruct_TNuSec07002Coherent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec07002Coherent*)
   {
      return GenerateInitInstanceLocal((::TNuSec07002Coherent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec07002Coherent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDescription(void *p = 0);
   static void *newArray_TNuDescription(Long_t size, void *p);
   static void delete_TNuDescription(void *p);
   static void deleteArray_TNuDescription(void *p);
   static void destruct_TNuDescription(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDescription*)
   {
      ::TNuDescription *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDescription >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDescription", ::TNuDescription::Class_Version(), "TNuDescription.h", 21,
                  typeid(::TNuDescription), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDescription::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDescription) );
      instance.SetNew(&new_TNuDescription);
      instance.SetNewArray(&newArray_TNuDescription);
      instance.SetDelete(&delete_TNuDescription);
      instance.SetDeleteArray(&deleteArray_TNuDescription);
      instance.SetDestructor(&destruct_TNuDescription);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDescription*)
   {
      return GenerateInitInstanceLocal((::TNuDescription*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDescription*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDirs(void *p = 0);
   static void *newArray_TNuDirs(Long_t size, void *p);
   static void delete_TNuDirs(void *p);
   static void deleteArray_TNuDirs(void *p);
   static void destruct_TNuDirs(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDirs*)
   {
      ::TNuDirs *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDirs >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDirs", ::TNuDirs::Class_Version(), "TNuDirs.h", 22,
                  typeid(::TNuDirs), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDirs::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDirs) );
      instance.SetNew(&new_TNuDirs);
      instance.SetNewArray(&newArray_TNuDirs);
      instance.SetDelete(&delete_TNuDirs);
      instance.SetDeleteArray(&deleteArray_TNuDirs);
      instance.SetDestructor(&destruct_TNuDirs);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDirs*)
   {
      return GenerateInitInstanceLocal((::TNuDirs*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDirs*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec01458(void *p = 0);
   static void *newArray_TNuSec01458(Long_t size, void *p);
   static void delete_TNuSec01458(void *p);
   static void deleteArray_TNuSec01458(void *p);
   static void destruct_TNuSec01458(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec01458*)
   {
      ::TNuSec01458 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec01458 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec01458", ::TNuSec01458::Class_Version(), "TNuSec01458.h", 19,
                  typeid(::TNuSec01458), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec01458::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec01458) );
      instance.SetNew(&new_TNuSec01458);
      instance.SetNewArray(&newArray_TNuSec01458);
      instance.SetDelete(&delete_TNuSec01458);
      instance.SetDeleteArray(&deleteArray_TNuSec01458);
      instance.SetDestructor(&destruct_TNuSec01458);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec01458*)
   {
      return GenerateInitInstanceLocal((::TNuSec01458*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec01458*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec28(void *p = 0);
   static void *newArray_TNuSec28(Long_t size, void *p);
   static void delete_TNuSec28(void *p);
   static void deleteArray_TNuSec28(void *p);
   static void destruct_TNuSec28(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec28*)
   {
      ::TNuSec28 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec28 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec28", ::TNuSec28::Class_Version(), "TNuSec28.h", 56,
                  typeid(::TNuSec28), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec28::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec28) );
      instance.SetNew(&new_TNuSec28);
      instance.SetNewArray(&newArray_TNuSec28);
      instance.SetDelete(&delete_TNuSec28);
      instance.SetDeleteArray(&deleteArray_TNuSec28);
      instance.SetDestructor(&destruct_TNuSec28);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec28*)
   {
      return GenerateInitInstanceLocal((::TNuSec28*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec28*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMu(void *p = 0);
   static void *newArray_TNuDEpDMu(Long_t size, void *p);
   static void delete_TNuDEpDMu(void *p);
   static void deleteArray_TNuDEpDMu(void *p);
   static void destruct_TNuDEpDMu(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMu*)
   {
      ::TNuDEpDMu *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMu >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMu", ::TNuDEpDMu::Class_Version(), "TNuDEpDMu.h", 45,
                  typeid(::TNuDEpDMu), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMu::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMu) );
      instance.SetNew(&new_TNuDEpDMu);
      instance.SetNewArray(&newArray_TNuDEpDMu);
      instance.SetDelete(&delete_TNuDEpDMu);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMu);
      instance.SetDestructor(&destruct_TNuDEpDMu);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMu*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMu*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMu*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMuF3(void *p = 0);
   static void *newArray_TNuDEpDMuF3(Long_t size, void *p);
   static void delete_TNuDEpDMuF3(void *p);
   static void deleteArray_TNuDEpDMuF3(void *p);
   static void destruct_TNuDEpDMuF3(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMuF3*)
   {
      ::TNuDEpDMuF3 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMuF3 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMuF3", ::TNuDEpDMuF3::Class_Version(), "TNuDEpDMu.h", 115,
                  typeid(::TNuDEpDMuF3), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMuF3::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMuF3) );
      instance.SetNew(&new_TNuDEpDMuF3);
      instance.SetNewArray(&newArray_TNuDEpDMuF3);
      instance.SetDelete(&delete_TNuDEpDMuF3);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMuF3);
      instance.SetDestructor(&destruct_TNuDEpDMuF3);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMuF3*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMuF3*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMuF3*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMuUnknwon(void *p = 0);
   static void *newArray_TNuDEpDMuUnknwon(Long_t size, void *p);
   static void delete_TNuDEpDMuUnknwon(void *p);
   static void deleteArray_TNuDEpDMuUnknwon(void *p);
   static void destruct_TNuDEpDMuUnknwon(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMuUnknwon*)
   {
      ::TNuDEpDMuUnknwon *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMuUnknwon >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMuUnknwon", ::TNuDEpDMuUnknwon::Class_Version(), "TNuDEpDMu.h", 156,
                  typeid(::TNuDEpDMuUnknwon), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMuUnknwon::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMuUnknwon) );
      instance.SetNew(&new_TNuDEpDMuUnknwon);
      instance.SetNewArray(&newArray_TNuDEpDMuUnknwon);
      instance.SetDelete(&delete_TNuDEpDMuUnknwon);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMuUnknwon);
      instance.SetDestructor(&destruct_TNuDEpDMuUnknwon);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMuUnknwon*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMuUnknwon*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMuUnknwon*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMuContinuum(void *p = 0);
   static void *newArray_TNuDEpDMuContinuum(Long_t size, void *p);
   static void delete_TNuDEpDMuContinuum(void *p);
   static void deleteArray_TNuDEpDMuContinuum(void *p);
   static void destruct_TNuDEpDMuContinuum(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMuContinuum*)
   {
      ::TNuDEpDMuContinuum *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMuContinuum >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMuContinuum", ::TNuDEpDMuContinuum::Class_Version(), "TNuDEpDMu.h", 211,
                  typeid(::TNuDEpDMuContinuum), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMuContinuum::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMuContinuum) );
      instance.SetNew(&new_TNuDEpDMuContinuum);
      instance.SetNewArray(&newArray_TNuDEpDMuContinuum);
      instance.SetDelete(&delete_TNuDEpDMuContinuum);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMuContinuum);
      instance.SetDestructor(&destruct_TNuDEpDMuContinuum);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMuContinuum*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMuContinuum*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMuContinuum*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMuNBodyPhaseSpace(void *p = 0);
   static void *newArray_TNuDEpDMuNBodyPhaseSpace(Long_t size, void *p);
   static void delete_TNuDEpDMuNBodyPhaseSpace(void *p);
   static void deleteArray_TNuDEpDMuNBodyPhaseSpace(void *p);
   static void destruct_TNuDEpDMuNBodyPhaseSpace(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMuNBodyPhaseSpace*)
   {
      ::TNuDEpDMuNBodyPhaseSpace *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMuNBodyPhaseSpace >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMuNBodyPhaseSpace", ::TNuDEpDMuNBodyPhaseSpace::Class_Version(), "TNuDEpDMu.h", 237,
                  typeid(::TNuDEpDMuNBodyPhaseSpace), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMuNBodyPhaseSpace::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMuNBodyPhaseSpace) );
      instance.SetNew(&new_TNuDEpDMuNBodyPhaseSpace);
      instance.SetNewArray(&newArray_TNuDEpDMuNBodyPhaseSpace);
      instance.SetDelete(&delete_TNuDEpDMuNBodyPhaseSpace);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMuNBodyPhaseSpace);
      instance.SetDestructor(&destruct_TNuDEpDMuNBodyPhaseSpace);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMuNBodyPhaseSpace*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMuNBodyPhaseSpace*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMuNBodyPhaseSpace*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMuLaboratory(void *p = 0);
   static void *newArray_TNuDEpDMuLaboratory(Long_t size, void *p);
   static void delete_TNuDEpDMuLaboratory(void *p);
   static void deleteArray_TNuDEpDMuLaboratory(void *p);
   static void destruct_TNuDEpDMuLaboratory(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMuLaboratory*)
   {
      ::TNuDEpDMuLaboratory *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMuLaboratory >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMuLaboratory", ::TNuDEpDMuLaboratory::Class_Version(), "TNuDEpDMu.h", 264,
                  typeid(::TNuDEpDMuLaboratory), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMuLaboratory::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMuLaboratory) );
      instance.SetNew(&new_TNuDEpDMuLaboratory);
      instance.SetNewArray(&newArray_TNuDEpDMuLaboratory);
      instance.SetDelete(&delete_TNuDEpDMuLaboratory);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMuLaboratory);
      instance.SetDestructor(&destruct_TNuDEpDMuLaboratory);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMuLaboratory*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMuLaboratory*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMuLaboratory*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuDEpDMu2Body(void *p);
   static void deleteArray_TNuDEpDMu2Body(void *p);
   static void destruct_TNuDEpDMu2Body(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMu2Body*)
   {
      ::TNuDEpDMu2Body *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMu2Body >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMu2Body", ::TNuDEpDMu2Body::Class_Version(), "TNuDEpDMu2Body.h", 46,
                  typeid(::TNuDEpDMu2Body), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMu2Body::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMu2Body) );
      instance.SetDelete(&delete_TNuDEpDMu2Body);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMu2Body);
      instance.SetDestructor(&destruct_TNuDEpDMu2Body);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMu2Body*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMu2Body*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMu2Body*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMu2BodyScattering(void *p = 0);
   static void *newArray_TNuDEpDMu2BodyScattering(Long_t size, void *p);
   static void delete_TNuDEpDMu2BodyScattering(void *p);
   static void deleteArray_TNuDEpDMu2BodyScattering(void *p);
   static void destruct_TNuDEpDMu2BodyScattering(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMu2BodyScattering*)
   {
      ::TNuDEpDMu2BodyScattering *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMu2BodyScattering >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMu2BodyScattering", ::TNuDEpDMu2BodyScattering::Class_Version(), "TNuDEpDMu2Body.h", 83,
                  typeid(::TNuDEpDMu2BodyScattering), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMu2BodyScattering::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMu2BodyScattering) );
      instance.SetNew(&new_TNuDEpDMu2BodyScattering);
      instance.SetNewArray(&newArray_TNuDEpDMu2BodyScattering);
      instance.SetDelete(&delete_TNuDEpDMu2BodyScattering);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMu2BodyScattering);
      instance.SetDestructor(&destruct_TNuDEpDMu2BodyScattering);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMu2BodyScattering*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMu2BodyScattering*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyScattering*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMu2BodyIsotropic(void *p = 0);
   static void *newArray_TNuDEpDMu2BodyIsotropic(Long_t size, void *p);
   static void delete_TNuDEpDMu2BodyIsotropic(void *p);
   static void deleteArray_TNuDEpDMu2BodyIsotropic(void *p);
   static void destruct_TNuDEpDMu2BodyIsotropic(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMu2BodyIsotropic*)
   {
      ::TNuDEpDMu2BodyIsotropic *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMu2BodyIsotropic >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMu2BodyIsotropic", ::TNuDEpDMu2BodyIsotropic::Class_Version(), "TNuDEpDMu2Body.h", 105,
                  typeid(::TNuDEpDMu2BodyIsotropic), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMu2BodyIsotropic::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMu2BodyIsotropic) );
      instance.SetNew(&new_TNuDEpDMu2BodyIsotropic);
      instance.SetNewArray(&newArray_TNuDEpDMu2BodyIsotropic);
      instance.SetDelete(&delete_TNuDEpDMu2BodyIsotropic);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMu2BodyIsotropic);
      instance.SetDestructor(&destruct_TNuDEpDMu2BodyIsotropic);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMu2BodyIsotropic*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMu2BodyIsotropic*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyIsotropic*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMu2BodyRecoil(void *p = 0);
   static void *newArray_TNuDEpDMu2BodyRecoil(Long_t size, void *p);
   static void delete_TNuDEpDMu2BodyRecoil(void *p);
   static void deleteArray_TNuDEpDMu2BodyRecoil(void *p);
   static void destruct_TNuDEpDMu2BodyRecoil(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMu2BodyRecoil*)
   {
      ::TNuDEpDMu2BodyRecoil *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMu2BodyRecoil >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMu2BodyRecoil", ::TNuDEpDMu2BodyRecoil::Class_Version(), "TNuDEpDMu2Body.h", 129,
                  typeid(::TNuDEpDMu2BodyRecoil), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMu2BodyRecoil::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMu2BodyRecoil) );
      instance.SetNew(&new_TNuDEpDMu2BodyRecoil);
      instance.SetNewArray(&newArray_TNuDEpDMu2BodyRecoil);
      instance.SetDelete(&delete_TNuDEpDMu2BodyRecoil);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMu2BodyRecoil);
      instance.SetDestructor(&destruct_TNuDEpDMu2BodyRecoil);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMu2BodyRecoil*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMu2BodyRecoil*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyRecoil*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMu2BodyCoulomb(void *p = 0);
   static void *newArray_TNuDEpDMu2BodyCoulomb(Long_t size, void *p);
   static void delete_TNuDEpDMu2BodyCoulomb(void *p);
   static void deleteArray_TNuDEpDMu2BodyCoulomb(void *p);
   static void destruct_TNuDEpDMu2BodyCoulomb(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMu2BodyCoulomb*)
   {
      ::TNuDEpDMu2BodyCoulomb *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMu2BodyCoulomb >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMu2BodyCoulomb", ::TNuDEpDMu2BodyCoulomb::Class_Version(), "TNuDEpDMu2Body.h", 154,
                  typeid(::TNuDEpDMu2BodyCoulomb), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMu2BodyCoulomb::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMu2BodyCoulomb) );
      instance.SetNew(&new_TNuDEpDMu2BodyCoulomb);
      instance.SetNewArray(&newArray_TNuDEpDMu2BodyCoulomb);
      instance.SetDelete(&delete_TNuDEpDMu2BodyCoulomb);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMu2BodyCoulomb);
      instance.SetDestructor(&destruct_TNuDEpDMu2BodyCoulomb);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMu2BodyCoulomb*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMu2BodyCoulomb*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyCoulomb*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec12(void *p = 0);
   static void *newArray_TNuSec12(Long_t size, void *p);
   static void delete_TNuSec12(void *p);
   static void deleteArray_TNuSec12(void *p);
   static void destruct_TNuSec12(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec12*)
   {
      ::TNuSec12 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec12 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec12", ::TNuSec12::Class_Version(), "TNuSec12.h", 46,
                  typeid(::TNuSec12), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec12::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec12) );
      instance.SetNew(&new_TNuSec12);
      instance.SetNewArray(&newArray_TNuSec12);
      instance.SetDelete(&delete_TNuSec12);
      instance.SetDeleteArray(&deleteArray_TNuSec12);
      instance.SetDestructor(&destruct_TNuSec12);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec12*)
   {
      return GenerateInitInstanceLocal((::TNuSec12*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec12*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec12Transitions(void *p = 0);
   static void *newArray_TNuSec12Transitions(Long_t size, void *p);
   static void delete_TNuSec12Transitions(void *p);
   static void deleteArray_TNuSec12Transitions(void *p);
   static void destruct_TNuSec12Transitions(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec12Transitions*)
   {
      ::TNuSec12Transitions *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec12Transitions >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec12Transitions", ::TNuSec12Transitions::Class_Version(), "TNuSec12Transitions.h", 62,
                  typeid(::TNuSec12Transitions), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec12Transitions::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec12Transitions) );
      instance.SetNew(&new_TNuSec12Transitions);
      instance.SetNewArray(&newArray_TNuSec12Transitions);
      instance.SetDelete(&delete_TNuSec12Transitions);
      instance.SetDeleteArray(&deleteArray_TNuSec12Transitions);
      instance.SetDestructor(&destruct_TNuSec12Transitions);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec12Transitions*)
   {
      return GenerateInitInstanceLocal((::TNuSec12Transitions*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec12Transitions*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuListCoulomb(void *p = 0);
   static void *newArray_TNuListCoulomb(Long_t size, void *p);
   static void delete_TNuListCoulomb(void *p);
   static void deleteArray_TNuListCoulomb(void *p);
   static void destruct_TNuListCoulomb(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuListCoulomb*)
   {
      ::TNuListCoulomb *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuListCoulomb >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuListCoulomb", ::TNuListCoulomb::Class_Version(), "TNuListCoulomb.h", 23,
                  typeid(::TNuListCoulomb), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuListCoulomb::Dictionary, isa_proxy, 4,
                  sizeof(::TNuListCoulomb) );
      instance.SetNew(&new_TNuListCoulomb);
      instance.SetNewArray(&newArray_TNuListCoulomb);
      instance.SetDelete(&delete_TNuListCoulomb);
      instance.SetDeleteArray(&deleteArray_TNuListCoulomb);
      instance.SetDestructor(&destruct_TNuListCoulomb);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuListCoulomb*)
   {
      return GenerateInitInstanceLocal((::TNuListCoulomb*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuListCoulomb*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoReichMoore(void *p = 0);
   static void *newArray_TNuResoReichMoore(Long_t size, void *p);
   static void delete_TNuResoReichMoore(void *p);
   static void deleteArray_TNuResoReichMoore(void *p);
   static void destruct_TNuResoReichMoore(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoReichMoore*)
   {
      ::TNuResoReichMoore *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoReichMoore >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoReichMoore", ::TNuResoReichMoore::Class_Version(), "TNuResoReichMoore.h", 12,
                  typeid(::TNuResoReichMoore), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoReichMoore::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoReichMoore) );
      instance.SetNew(&new_TNuResoReichMoore);
      instance.SetNewArray(&newArray_TNuResoReichMoore);
      instance.SetDelete(&delete_TNuResoReichMoore);
      instance.SetDeleteArray(&deleteArray_TNuResoReichMoore);
      instance.SetDestructor(&destruct_TNuResoReichMoore);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoReichMoore*)
   {
      return GenerateInitInstanceLocal((::TNuResoReichMoore*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoReichMoore*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec07004(void *p = 0);
   static void *newArray_TNuSec07004(Long_t size, void *p);
   static void delete_TNuSec07004(void *p);
   static void deleteArray_TNuSec07004(void *p);
   static void destruct_TNuSec07004(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec07004*)
   {
      ::TNuSec07004 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec07004 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec07004", ::TNuSec07004::Class_Version(), "TNuSec07004.h", 18,
                  typeid(::TNuSec07004), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec07004::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec07004) );
      instance.SetNew(&new_TNuSec07004);
      instance.SetNewArray(&newArray_TNuSec07004);
      instance.SetDelete(&delete_TNuSec07004);
      instance.SetDeleteArray(&deleteArray_TNuSec07004);
      instance.SetDestructor(&destruct_TNuSec07004);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec07004*)
   {
      return GenerateInitInstanceLocal((::TNuSec07004*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec07004*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec01451(void *p = 0);
   static void *newArray_TNuSec01451(Long_t size, void *p);
   static void delete_TNuSec01451(void *p);
   static void deleteArray_TNuSec01451(void *p);
   static void destruct_TNuSec01451(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec01451*)
   {
      ::TNuSec01451 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec01451 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec01451", ::TNuSec01451::Class_Version(), "TNuSec01451.h", 45,
                  typeid(::TNuSec01451), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec01451::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec01451) );
      instance.SetNew(&new_TNuSec01451);
      instance.SetNewArray(&newArray_TNuSec01451);
      instance.SetDelete(&delete_TNuSec01451);
      instance.SetDeleteArray(&deleteArray_TNuSec01451);
      instance.SetDestructor(&destruct_TNuSec01451);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec01451*)
   {
      return GenerateInitInstanceLocal((::TNuSec01451*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec01451*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec08(void *p = 0);
   static void *newArray_TNuSec08(Long_t size, void *p);
   static void delete_TNuSec08(void *p);
   static void deleteArray_TNuSec08(void *p);
   static void destruct_TNuSec08(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec08*)
   {
      ::TNuSec08 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec08 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec08", ::TNuSec08::Class_Version(), "TNuSec08.h", 16,
                  typeid(::TNuSec08), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec08::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec08) );
      instance.SetNew(&new_TNuSec08);
      instance.SetNewArray(&newArray_TNuSec08);
      instance.SetDelete(&delete_TNuSec08);
      instance.SetDeleteArray(&deleteArray_TNuSec08);
      instance.SetDestructor(&destruct_TNuSec08);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec08*)
   {
      return GenerateInitInstanceLocal((::TNuSec08*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec08*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuList2(void *p);
   static void deleteArray_TNuList2(void *p);
   static void destruct_TNuList2(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuList2*)
   {
      ::TNuList2 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuList2 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuList2", ::TNuList2::Class_Version(), "TNuList2.h", 35,
                  typeid(::TNuList2), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuList2::Dictionary, isa_proxy, 4,
                  sizeof(::TNuList2) );
      instance.SetDelete(&delete_TNuList2);
      instance.SetDeleteArray(&deleteArray_TNuList2);
      instance.SetDestructor(&destruct_TNuList2);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuList2*)
   {
      return GenerateInitInstanceLocal((::TNuList2*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuList2*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuList2KalbachMann(void *p = 0);
   static void *newArray_TNuList2KalbachMann(Long_t size, void *p);
   static void delete_TNuList2KalbachMann(void *p);
   static void deleteArray_TNuList2KalbachMann(void *p);
   static void destruct_TNuList2KalbachMann(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuList2KalbachMann*)
   {
      ::TNuList2KalbachMann *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuList2KalbachMann >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuList2KalbachMann", ::TNuList2KalbachMann::Class_Version(), "TNuList2KalbachMann.h", 34,
                  typeid(::TNuList2KalbachMann), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuList2KalbachMann::Dictionary, isa_proxy, 4,
                  sizeof(::TNuList2KalbachMann) );
      instance.SetNew(&new_TNuList2KalbachMann);
      instance.SetNewArray(&newArray_TNuList2KalbachMann);
      instance.SetDelete(&delete_TNuList2KalbachMann);
      instance.SetDeleteArray(&deleteArray_TNuList2KalbachMann);
      instance.SetDestructor(&destruct_TNuList2KalbachMann);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuList2KalbachMann*)
   {
      return GenerateInitInstanceLocal((::TNuList2KalbachMann*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuList2KalbachMann*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec01(void *p = 0);
   static void *newArray_TNuSec01(Long_t size, void *p);
   static void delete_TNuSec01(void *p);
   static void deleteArray_TNuSec01(void *p);
   static void destruct_TNuSec01(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec01*)
   {
      ::TNuSec01 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec01 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec01", ::TNuSec01::Class_Version(), "TNuSec01.h", 20,
                  typeid(::TNuSec01), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec01::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec01) );
      instance.SetNew(&new_TNuSec01);
      instance.SetNewArray(&newArray_TNuSec01);
      instance.SetDelete(&delete_TNuSec01);
      instance.SetDeleteArray(&deleteArray_TNuSec01);
      instance.SetDestructor(&destruct_TNuSec01);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec01*)
   {
      return GenerateInitInstanceLocal((::TNuSec01*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec01*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec12Yields(void *p = 0);
   static void *newArray_TNuSec12Yields(Long_t size, void *p);
   static void delete_TNuSec12Yields(void *p);
   static void deleteArray_TNuSec12Yields(void *p);
   static void destruct_TNuSec12Yields(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec12Yields*)
   {
      ::TNuSec12Yields *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec12Yields >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec12Yields", ::TNuSec12Yields::Class_Version(), "TNuSec12Yields.h", 51,
                  typeid(::TNuSec12Yields), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec12Yields::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec12Yields) );
      instance.SetNew(&new_TNuSec12Yields);
      instance.SetNewArray(&newArray_TNuSec12Yields);
      instance.SetDelete(&delete_TNuSec12Yields);
      instance.SetDeleteArray(&deleteArray_TNuSec12Yields);
      instance.SetDestructor(&destruct_TNuSec12Yields);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec12Yields*)
   {
      return GenerateInitInstanceLocal((::TNuSec12Yields*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec12Yields*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuContList(void *p = 0);
   static void *newArray_TNuContList(Long_t size, void *p);
   static void delete_TNuContList(void *p);
   static void deleteArray_TNuContList(void *p);
   static void destruct_TNuContList(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuContList*)
   {
      ::TNuContList *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuContList >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuContList", ::TNuContList::Class_Version(), "TNuContList.h", 21,
                  typeid(::TNuContList), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuContList::Dictionary, isa_proxy, 4,
                  sizeof(::TNuContList) );
      instance.SetNew(&new_TNuContList);
      instance.SetNewArray(&newArray_TNuContList);
      instance.SetDelete(&delete_TNuContList);
      instance.SetDeleteArray(&deleteArray_TNuContList);
      instance.SetDestructor(&destruct_TNuContList);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuContList*)
   {
      return GenerateInitInstanceLocal((::TNuContList*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuContList*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec08457(void *p = 0);
   static void *newArray_TNuSec08457(Long_t size, void *p);
   static void delete_TNuSec08457(void *p);
   static void deleteArray_TNuSec08457(void *p);
   static void destruct_TNuSec08457(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec08457*)
   {
      ::TNuSec08457 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec08457 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec08457", ::TNuSec08457::Class_Version(), "TNuSec08457.h", 65,
                  typeid(::TNuSec08457), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec08457::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec08457) );
      instance.SetNew(&new_TNuSec08457);
      instance.SetNewArray(&newArray_TNuSec08457);
      instance.SetDelete(&delete_TNuSec08457);
      instance.SetDeleteArray(&deleteArray_TNuSec08457);
      instance.SetDestructor(&destruct_TNuSec08457);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec08457*)
   {
      return GenerateInitInstanceLocal((::TNuSec08457*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec08457*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSFYSub(void *p = 0);
   static void *newArray_TNuSFYSub(Long_t size, void *p);
   static void delete_TNuSFYSub(void *p);
   static void deleteArray_TNuSFYSub(void *p);
   static void destruct_TNuSFYSub(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSFYSub*)
   {
      ::TNuSFYSub *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSFYSub >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSFYSub", ::TNuSFYSub::Class_Version(), "TNuSec08457.h", 167,
                  typeid(::TNuSFYSub), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSFYSub::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSFYSub) );
      instance.SetNew(&new_TNuSFYSub);
      instance.SetNewArray(&newArray_TNuSFYSub);
      instance.SetDelete(&delete_TNuSFYSub);
      instance.SetDeleteArray(&deleteArray_TNuSFYSub);
      instance.SetDestructor(&destruct_TNuSFYSub);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSFYSub*)
   {
      return GenerateInitInstanceLocal((::TNuSFYSub*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSFYSub*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuList2Legendre(void *p = 0);
   static void *newArray_TNuList2Legendre(Long_t size, void *p);
   static void delete_TNuList2Legendre(void *p);
   static void deleteArray_TNuList2Legendre(void *p);
   static void destruct_TNuList2Legendre(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuList2Legendre*)
   {
      ::TNuList2Legendre *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuList2Legendre >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuList2Legendre", ::TNuList2Legendre::Class_Version(), "TNuList2Legendre.h", 31,
                  typeid(::TNuList2Legendre), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuList2Legendre::Dictionary, isa_proxy, 4,
                  sizeof(::TNuList2Legendre) );
      instance.SetNew(&new_TNuList2Legendre);
      instance.SetNewArray(&newArray_TNuList2Legendre);
      instance.SetDelete(&delete_TNuList2Legendre);
      instance.SetDeleteArray(&deleteArray_TNuList2Legendre);
      instance.SetDestructor(&destruct_TNuList2Legendre);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuList2Legendre*)
   {
      return GenerateInitInstanceLocal((::TNuList2Legendre*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuList2Legendre*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuTab2Tab1(void *p = 0);
   static void *newArray_TNuTab2Tab1(Long_t size, void *p);
   static void delete_TNuTab2Tab1(void *p);
   static void deleteArray_TNuTab2Tab1(void *p);
   static void destruct_TNuTab2Tab1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab2Tab1*)
   {
      ::TNuTab2Tab1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab2Tab1 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab2Tab1", ::TNuTab2Tab1::Class_Version(), "TNuTab2Tab1.h", 25,
                  typeid(::TNuTab2Tab1), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab2Tab1::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab2Tab1) );
      instance.SetNew(&new_TNuTab2Tab1);
      instance.SetNewArray(&newArray_TNuTab2Tab1);
      instance.SetDelete(&delete_TNuTab2Tab1);
      instance.SetDeleteArray(&deleteArray_TNuTab2Tab1);
      instance.SetDestructor(&destruct_TNuTab2Tab1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab2Tab1*)
   {
      return GenerateInitInstanceLocal((::TNuTab2Tab1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab2Tab1*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuContListNC(void *p = 0);
   static void *newArray_TNuContListNC(Long_t size, void *p);
   static void delete_TNuContListNC(void *p);
   static void deleteArray_TNuContListNC(void *p);
   static void destruct_TNuContListNC(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuContListNC*)
   {
      ::TNuContListNC *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuContListNC >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuContListNC", ::TNuContListNC::Class_Version(), "TNuCov.h", 34,
                  typeid(::TNuContListNC), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuContListNC::Dictionary, isa_proxy, 4,
                  sizeof(::TNuContListNC) );
      instance.SetNew(&new_TNuContListNC);
      instance.SetNewArray(&newArray_TNuContListNC);
      instance.SetDelete(&delete_TNuContListNC);
      instance.SetDeleteArray(&deleteArray_TNuContListNC);
      instance.SetDestructor(&destruct_TNuContListNC);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuContListNC*)
   {
      return GenerateInitInstanceLocal((::TNuContListNC*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuContListNC*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuListNI(void *p = 0);
   static void *newArray_TNuListNI(Long_t size, void *p);
   static void delete_TNuListNI(void *p);
   static void deleteArray_TNuListNI(void *p);
   static void destruct_TNuListNI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuListNI*)
   {
      ::TNuListNI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuListNI >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuListNI", ::TNuListNI::Class_Version(), "TNuCov.h", 89,
                  typeid(::TNuListNI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuListNI::Dictionary, isa_proxy, 4,
                  sizeof(::TNuListNI) );
      instance.SetNew(&new_TNuListNI);
      instance.SetNewArray(&newArray_TNuListNI);
      instance.SetDelete(&delete_TNuListNI);
      instance.SetDeleteArray(&deleteArray_TNuListNI);
      instance.SetDestructor(&destruct_TNuListNI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuListNI*)
   {
      return GenerateInitInstanceLocal((::TNuListNI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuListNI*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuContListsCov33(void *p = 0);
   static void *newArray_TNuContListsCov33(Long_t size, void *p);
   static void delete_TNuContListsCov33(void *p);
   static void deleteArray_TNuContListsCov33(void *p);
   static void destruct_TNuContListsCov33(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuContListsCov33*)
   {
      ::TNuContListsCov33 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuContListsCov33 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuContListsCov33", ::TNuContListsCov33::Class_Version(), "TNuCov.h", 159,
                  typeid(::TNuContListsCov33), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuContListsCov33::Dictionary, isa_proxy, 4,
                  sizeof(::TNuContListsCov33) );
      instance.SetNew(&new_TNuContListsCov33);
      instance.SetNewArray(&newArray_TNuContListsCov33);
      instance.SetDelete(&delete_TNuContListsCov33);
      instance.SetDeleteArray(&deleteArray_TNuContListsCov33);
      instance.SetDestructor(&destruct_TNuContListsCov33);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuContListsCov33*)
   {
      return GenerateInitInstanceLocal((::TNuContListsCov33*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuContListsCov33*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuCovMatrix(void *p = 0);
   static void *newArray_TNuCovMatrix(Long_t size, void *p);
   static void delete_TNuCovMatrix(void *p);
   static void deleteArray_TNuCovMatrix(void *p);
   static void destruct_TNuCovMatrix(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuCovMatrix*)
   {
      ::TNuCovMatrix *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuCovMatrix >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuCovMatrix", ::TNuCovMatrix::Class_Version(), "TNuCov.h", 217,
                  typeid(::TNuCovMatrix), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuCovMatrix::Dictionary, isa_proxy, 4,
                  sizeof(::TNuCovMatrix) );
      instance.SetNew(&new_TNuCovMatrix);
      instance.SetNewArray(&newArray_TNuCovMatrix);
      instance.SetDelete(&delete_TNuCovMatrix);
      instance.SetDeleteArray(&deleteArray_TNuCovMatrix);
      instance.SetDestructor(&destruct_TNuCovMatrix);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuCovMatrix*)
   {
      return GenerateInitInstanceLocal((::TNuCovMatrix*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuCovMatrix*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec31(void *p = 0);
   static void *newArray_TNuSec31(Long_t size, void *p);
   static void delete_TNuSec31(void *p);
   static void deleteArray_TNuSec31(void *p);
   static void destruct_TNuSec31(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec31*)
   {
      ::TNuSec31 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec31 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec31", ::TNuSec31::Class_Version(), "TNuCov.h", 263,
                  typeid(::TNuSec31), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec31::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec31) );
      instance.SetNew(&new_TNuSec31);
      instance.SetNewArray(&newArray_TNuSec31);
      instance.SetDelete(&delete_TNuSec31);
      instance.SetDeleteArray(&deleteArray_TNuSec31);
      instance.SetDestructor(&destruct_TNuSec31);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec31*)
   {
      return GenerateInitInstanceLocal((::TNuSec31*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec31*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec33(void *p = 0);
   static void *newArray_TNuSec33(Long_t size, void *p);
   static void delete_TNuSec33(void *p);
   static void deleteArray_TNuSec33(void *p);
   static void destruct_TNuSec33(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec33*)
   {
      ::TNuSec33 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec33 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec33", ::TNuSec33::Class_Version(), "TNuCov.h", 329,
                  typeid(::TNuSec33), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec33::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec33) );
      instance.SetNew(&new_TNuSec33);
      instance.SetNewArray(&newArray_TNuSec33);
      instance.SetDelete(&delete_TNuSec33);
      instance.SetDeleteArray(&deleteArray_TNuSec33);
      instance.SetDestructor(&destruct_TNuSec33);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec33*)
   {
      return GenerateInitInstanceLocal((::TNuSec33*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec33*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuContListsCov34(void *p = 0);
   static void *newArray_TNuContListsCov34(Long_t size, void *p);
   static void delete_TNuContListsCov34(void *p);
   static void deleteArray_TNuContListsCov34(void *p);
   static void destruct_TNuContListsCov34(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuContListsCov34*)
   {
      ::TNuContListsCov34 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuContListsCov34 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuContListsCov34", ::TNuContListsCov34::Class_Version(), "TNuCov.h", 409,
                  typeid(::TNuContListsCov34), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuContListsCov34::Dictionary, isa_proxy, 4,
                  sizeof(::TNuContListsCov34) );
      instance.SetNew(&new_TNuContListsCov34);
      instance.SetNewArray(&newArray_TNuContListsCov34);
      instance.SetDelete(&delete_TNuContListsCov34);
      instance.SetDeleteArray(&deleteArray_TNuContListsCov34);
      instance.SetDestructor(&destruct_TNuContListsCov34);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuContListsCov34*)
   {
      return GenerateInitInstanceLocal((::TNuContListsCov34*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuContListsCov34*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSubSec34(void *p = 0);
   static void *newArray_TNuSubSec34(Long_t size, void *p);
   static void delete_TNuSubSec34(void *p);
   static void deleteArray_TNuSubSec34(void *p);
   static void destruct_TNuSubSec34(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSubSec34*)
   {
      ::TNuSubSec34 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSubSec34 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSubSec34", ::TNuSubSec34::Class_Version(), "TNuCov.h", 463,
                  typeid(::TNuSubSec34), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSubSec34::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSubSec34) );
      instance.SetNew(&new_TNuSubSec34);
      instance.SetNewArray(&newArray_TNuSubSec34);
      instance.SetDelete(&delete_TNuSubSec34);
      instance.SetDeleteArray(&deleteArray_TNuSubSec34);
      instance.SetDestructor(&destruct_TNuSubSec34);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSubSec34*)
   {
      return GenerateInitInstanceLocal((::TNuSubSec34*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSubSec34*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec34(void *p = 0);
   static void *newArray_TNuSec34(Long_t size, void *p);
   static void delete_TNuSec34(void *p);
   static void deleteArray_TNuSec34(void *p);
   static void destruct_TNuSec34(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec34*)
   {
      ::TNuSec34 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec34 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec34", ::TNuSec34::Class_Version(), "TNuCov.h", 524,
                  typeid(::TNuSec34), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec34::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec34) );
      instance.SetNew(&new_TNuSec34);
      instance.SetNewArray(&newArray_TNuSec34);
      instance.SetDelete(&delete_TNuSec34);
      instance.SetDeleteArray(&deleteArray_TNuSec34);
      instance.SetDestructor(&destruct_TNuSec34);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec34*)
   {
      return GenerateInitInstanceLocal((::TNuSec34*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec34*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec35(void *p = 0);
   static void *newArray_TNuSec35(Long_t size, void *p);
   static void delete_TNuSec35(void *p);
   static void deleteArray_TNuSec35(void *p);
   static void destruct_TNuSec35(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec35*)
   {
      ::TNuSec35 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec35 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec35", ::TNuSec35::Class_Version(), "TNuCov.h", 623,
                  typeid(::TNuSec35), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec35::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec35) );
      instance.SetNew(&new_TNuSec35);
      instance.SetNewArray(&newArray_TNuSec35);
      instance.SetDelete(&delete_TNuSec35);
      instance.SetDeleteArray(&deleteArray_TNuSec35);
      instance.SetDestructor(&destruct_TNuSec35);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec35*)
   {
      return GenerateInitInstanceLocal((::TNuSec35*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec35*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec40(void *p = 0);
   static void *newArray_TNuSec40(Long_t size, void *p);
   static void delete_TNuSec40(void *p);
   static void deleteArray_TNuSec40(void *p);
   static void destruct_TNuSec40(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec40*)
   {
      ::TNuSec40 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec40 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec40", ::TNuSec40::Class_Version(), "TNuCov.h", 700,
                  typeid(::TNuSec40), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec40::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec40) );
      instance.SetNew(&new_TNuSec40);
      instance.SetNewArray(&newArray_TNuSec40);
      instance.SetDelete(&delete_TNuSec40);
      instance.SetDeleteArray(&deleteArray_TNuSec40);
      instance.SetDestructor(&destruct_TNuSec40);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec40*)
   {
      return GenerateInitInstanceLocal((::TNuSec40*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec40*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec32(void *p = 0);
   static void *newArray_TNuSec32(Long_t size, void *p);
   static void delete_TNuSec32(void *p);
   static void deleteArray_TNuSec32(void *p);
   static void destruct_TNuSec32(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec32*)
   {
      ::TNuSec32 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec32 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec32", ::TNuSec32::Class_Version(), "TNuCov.h", 771,
                  typeid(::TNuSec32), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec32::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec32) );
      instance.SetNew(&new_TNuSec32);
      instance.SetNewArray(&newArray_TNuSec32);
      instance.SetDelete(&delete_TNuSec32);
      instance.SetDeleteArray(&deleteArray_TNuSec32);
      instance.SetDestructor(&destruct_TNuSec32);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec32*)
   {
      return GenerateInitInstanceLocal((::TNuSec32*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec32*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSubIsotopeCov(void *p = 0);
   static void *newArray_TNuSubIsotopeCov(Long_t size, void *p);
   static void delete_TNuSubIsotopeCov(void *p);
   static void deleteArray_TNuSubIsotopeCov(void *p);
   static void destruct_TNuSubIsotopeCov(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSubIsotopeCov*)
   {
      ::TNuSubIsotopeCov *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSubIsotopeCov >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSubIsotopeCov", ::TNuSubIsotopeCov::Class_Version(), "TNuCov.h", 821,
                  typeid(::TNuSubIsotopeCov), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSubIsotopeCov::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSubIsotopeCov) );
      instance.SetNew(&new_TNuSubIsotopeCov);
      instance.SetNewArray(&newArray_TNuSubIsotopeCov);
      instance.SetDelete(&delete_TNuSubIsotopeCov);
      instance.SetDeleteArray(&deleteArray_TNuSubIsotopeCov);
      instance.SetDestructor(&destruct_TNuSubIsotopeCov);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSubIsotopeCov*)
   {
      return GenerateInitInstanceLocal((::TNuSubIsotopeCov*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSubIsotopeCov*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResonanceCov(void *p = 0);
   static void *newArray_TNuResonanceCov(Long_t size, void *p);
   static void delete_TNuResonanceCov(void *p);
   static void deleteArray_TNuResonanceCov(void *p);
   static void destruct_TNuResonanceCov(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResonanceCov*)
   {
      ::TNuResonanceCov *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResonanceCov >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResonanceCov", ::TNuResonanceCov::Class_Version(), "TNuCov.h", 895,
                  typeid(::TNuResonanceCov), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResonanceCov::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResonanceCov) );
      instance.SetNew(&new_TNuResonanceCov);
      instance.SetNewArray(&newArray_TNuResonanceCov);
      instance.SetDelete(&delete_TNuResonanceCov);
      instance.SetDeleteArray(&deleteArray_TNuResonanceCov);
      instance.SetDestructor(&destruct_TNuResonanceCov);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResonanceCov*)
   {
      return GenerateInitInstanceLocal((::TNuResonanceCov*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResonanceCov*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec05(void *p = 0);
   static void *newArray_TNuSec05(Long_t size, void *p);
   static void delete_TNuSec05(void *p);
   static void deleteArray_TNuSec05(void *p);
   static void destruct_TNuSec05(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec05*)
   {
      ::TNuSec05 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec05 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec05", ::TNuSec05::Class_Version(), "TNuSec05.h", 42,
                  typeid(::TNuSec05), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec05::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec05) );
      instance.SetNew(&new_TNuSec05);
      instance.SetNewArray(&newArray_TNuSec05);
      instance.SetDelete(&delete_TNuSec05);
      instance.SetDeleteArray(&deleteArray_TNuSec05);
      instance.SetDestructor(&destruct_TNuSec05);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec05*)
   {
      return GenerateInitInstanceLocal((::TNuSec05*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec05*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuESpectrum(void *p);
   static void deleteArray_TNuESpectrum(void *p);
   static void destruct_TNuESpectrum(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuESpectrum*)
   {
      ::TNuESpectrum *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuESpectrum >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuESpectrum", ::TNuESpectrum::Class_Version(), "TNuSec05.h", 93,
                  typeid(::TNuESpectrum), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuESpectrum::Dictionary, isa_proxy, 4,
                  sizeof(::TNuESpectrum) );
      instance.SetDelete(&delete_TNuESpectrum);
      instance.SetDeleteArray(&deleteArray_TNuESpectrum);
      instance.SetDestructor(&destruct_TNuESpectrum);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuESpectrum*)
   {
      return GenerateInitInstanceLocal((::TNuESpectrum*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuESpectrum*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuESpectrumTabulated(void *p = 0);
   static void *newArray_TNuESpectrumTabulated(Long_t size, void *p);
   static void delete_TNuESpectrumTabulated(void *p);
   static void deleteArray_TNuESpectrumTabulated(void *p);
   static void destruct_TNuESpectrumTabulated(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuESpectrumTabulated*)
   {
      ::TNuESpectrumTabulated *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuESpectrumTabulated >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuESpectrumTabulated", ::TNuESpectrumTabulated::Class_Version(), "TNuSec05.h", 129,
                  typeid(::TNuESpectrumTabulated), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuESpectrumTabulated::Dictionary, isa_proxy, 4,
                  sizeof(::TNuESpectrumTabulated) );
      instance.SetNew(&new_TNuESpectrumTabulated);
      instance.SetNewArray(&newArray_TNuESpectrumTabulated);
      instance.SetDelete(&delete_TNuESpectrumTabulated);
      instance.SetDeleteArray(&deleteArray_TNuESpectrumTabulated);
      instance.SetDestructor(&destruct_TNuESpectrumTabulated);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuESpectrumTabulated*)
   {
      return GenerateInitInstanceLocal((::TNuESpectrumTabulated*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuESpectrumTabulated*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuESpectrumGeneralEvaporation(void *p = 0);
   static void *newArray_TNuESpectrumGeneralEvaporation(Long_t size, void *p);
   static void delete_TNuESpectrumGeneralEvaporation(void *p);
   static void deleteArray_TNuESpectrumGeneralEvaporation(void *p);
   static void destruct_TNuESpectrumGeneralEvaporation(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuESpectrumGeneralEvaporation*)
   {
      ::TNuESpectrumGeneralEvaporation *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuESpectrumGeneralEvaporation >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuESpectrumGeneralEvaporation", ::TNuESpectrumGeneralEvaporation::Class_Version(), "TNuSec05.h", 152,
                  typeid(::TNuESpectrumGeneralEvaporation), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuESpectrumGeneralEvaporation::Dictionary, isa_proxy, 4,
                  sizeof(::TNuESpectrumGeneralEvaporation) );
      instance.SetNew(&new_TNuESpectrumGeneralEvaporation);
      instance.SetNewArray(&newArray_TNuESpectrumGeneralEvaporation);
      instance.SetDelete(&delete_TNuESpectrumGeneralEvaporation);
      instance.SetDeleteArray(&deleteArray_TNuESpectrumGeneralEvaporation);
      instance.SetDestructor(&destruct_TNuESpectrumGeneralEvaporation);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuESpectrumGeneralEvaporation*)
   {
      return GenerateInitInstanceLocal((::TNuESpectrumGeneralEvaporation*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuESpectrumGeneralEvaporation*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuESpectrumMaxwellian(void *p = 0);
   static void *newArray_TNuESpectrumMaxwellian(Long_t size, void *p);
   static void delete_TNuESpectrumMaxwellian(void *p);
   static void deleteArray_TNuESpectrumMaxwellian(void *p);
   static void destruct_TNuESpectrumMaxwellian(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuESpectrumMaxwellian*)
   {
      ::TNuESpectrumMaxwellian *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuESpectrumMaxwellian >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuESpectrumMaxwellian", ::TNuESpectrumMaxwellian::Class_Version(), "TNuSec05.h", 177,
                  typeid(::TNuESpectrumMaxwellian), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuESpectrumMaxwellian::Dictionary, isa_proxy, 4,
                  sizeof(::TNuESpectrumMaxwellian) );
      instance.SetNew(&new_TNuESpectrumMaxwellian);
      instance.SetNewArray(&newArray_TNuESpectrumMaxwellian);
      instance.SetDelete(&delete_TNuESpectrumMaxwellian);
      instance.SetDeleteArray(&deleteArray_TNuESpectrumMaxwellian);
      instance.SetDestructor(&destruct_TNuESpectrumMaxwellian);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuESpectrumMaxwellian*)
   {
      return GenerateInitInstanceLocal((::TNuESpectrumMaxwellian*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuESpectrumMaxwellian*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuESpectrumEvaporation(void *p = 0);
   static void *newArray_TNuESpectrumEvaporation(Long_t size, void *p);
   static void delete_TNuESpectrumEvaporation(void *p);
   static void deleteArray_TNuESpectrumEvaporation(void *p);
   static void destruct_TNuESpectrumEvaporation(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuESpectrumEvaporation*)
   {
      ::TNuESpectrumEvaporation *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuESpectrumEvaporation >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuESpectrumEvaporation", ::TNuESpectrumEvaporation::Class_Version(), "TNuSec05.h", 202,
                  typeid(::TNuESpectrumEvaporation), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuESpectrumEvaporation::Dictionary, isa_proxy, 4,
                  sizeof(::TNuESpectrumEvaporation) );
      instance.SetNew(&new_TNuESpectrumEvaporation);
      instance.SetNewArray(&newArray_TNuESpectrumEvaporation);
      instance.SetDelete(&delete_TNuESpectrumEvaporation);
      instance.SetDeleteArray(&deleteArray_TNuESpectrumEvaporation);
      instance.SetDestructor(&destruct_TNuESpectrumEvaporation);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuESpectrumEvaporation*)
   {
      return GenerateInitInstanceLocal((::TNuESpectrumEvaporation*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuESpectrumEvaporation*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuESpectrumWatt(void *p = 0);
   static void *newArray_TNuESpectrumWatt(Long_t size, void *p);
   static void delete_TNuESpectrumWatt(void *p);
   static void deleteArray_TNuESpectrumWatt(void *p);
   static void destruct_TNuESpectrumWatt(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuESpectrumWatt*)
   {
      ::TNuESpectrumWatt *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuESpectrumWatt >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuESpectrumWatt", ::TNuESpectrumWatt::Class_Version(), "TNuSec05.h", 227,
                  typeid(::TNuESpectrumWatt), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuESpectrumWatt::Dictionary, isa_proxy, 4,
                  sizeof(::TNuESpectrumWatt) );
      instance.SetNew(&new_TNuESpectrumWatt);
      instance.SetNewArray(&newArray_TNuESpectrumWatt);
      instance.SetDelete(&delete_TNuESpectrumWatt);
      instance.SetDeleteArray(&deleteArray_TNuESpectrumWatt);
      instance.SetDestructor(&destruct_TNuESpectrumWatt);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuESpectrumWatt*)
   {
      return GenerateInitInstanceLocal((::TNuESpectrumWatt*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuESpectrumWatt*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuESpectrumMadlandNix(void *p = 0);
   static void *newArray_TNuESpectrumMadlandNix(Long_t size, void *p);
   static void delete_TNuESpectrumMadlandNix(void *p);
   static void deleteArray_TNuESpectrumMadlandNix(void *p);
   static void destruct_TNuESpectrumMadlandNix(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuESpectrumMadlandNix*)
   {
      ::TNuESpectrumMadlandNix *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuESpectrumMadlandNix >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuESpectrumMadlandNix", ::TNuESpectrumMadlandNix::Class_Version(), "TNuSec05.h", 251,
                  typeid(::TNuESpectrumMadlandNix), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuESpectrumMadlandNix::Dictionary, isa_proxy, 4,
                  sizeof(::TNuESpectrumMadlandNix) );
      instance.SetNew(&new_TNuESpectrumMadlandNix);
      instance.SetNewArray(&newArray_TNuESpectrumMadlandNix);
      instance.SetDelete(&delete_TNuESpectrumMadlandNix);
      instance.SetDeleteArray(&deleteArray_TNuESpectrumMadlandNix);
      instance.SetDestructor(&destruct_TNuESpectrumMadlandNix);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuESpectrumMadlandNix*)
   {
      return GenerateInitInstanceLocal((::TNuESpectrumMadlandNix*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuESpectrumMadlandNix*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuTab2List1(void *p = 0);
   static void *newArray_TNuTab2List1(Long_t size, void *p);
   static void delete_TNuTab2List1(void *p);
   static void deleteArray_TNuTab2List1(void *p);
   static void destruct_TNuTab2List1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab2List1*)
   {
      ::TNuTab2List1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab2List1 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab2List1", ::TNuTab2List1::Class_Version(), "TNuTab2List1.h", 25,
                  typeid(::TNuTab2List1), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab2List1::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab2List1) );
      instance.SetNew(&new_TNuTab2List1);
      instance.SetNewArray(&newArray_TNuTab2List1);
      instance.SetDelete(&delete_TNuTab2List1);
      instance.SetDeleteArray(&deleteArray_TNuTab2List1);
      instance.SetDestructor(&destruct_TNuTab2List1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab2List1*)
   {
      return GenerateInitInstanceLocal((::TNuTab2List1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab2List1*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec14(void *p = 0);
   static void *newArray_TNuSec14(Long_t size, void *p);
   static void delete_TNuSec14(void *p);
   static void deleteArray_TNuSec14(void *p);
   static void destruct_TNuSec14(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec14*)
   {
      ::TNuSec14 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec14 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec14", ::TNuSec14::Class_Version(), "TNuSec14.h", 30,
                  typeid(::TNuSec14), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec14::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec14) );
      instance.SetNew(&new_TNuSec14);
      instance.SetNewArray(&newArray_TNuSec14);
      instance.SetDelete(&delete_TNuSec14);
      instance.SetDeleteArray(&deleteArray_TNuSec14);
      instance.SetDestructor(&destruct_TNuSec14);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec14*)
   {
      return GenerateInitInstanceLocal((::TNuSec14*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec14*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec27(void *p = 0);
   static void *newArray_TNuSec27(Long_t size, void *p);
   static void delete_TNuSec27(void *p);
   static void deleteArray_TNuSec27(void *p);
   static void destruct_TNuSec27(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec27*)
   {
      ::TNuSec27 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec27 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec27", ::TNuSec27::Class_Version(), "TNuSec27.h", 29,
                  typeid(::TNuSec27), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec27::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec27) );
      instance.SetNew(&new_TNuSec27);
      instance.SetNewArray(&newArray_TNuSec27);
      instance.SetDelete(&delete_TNuSec27);
      instance.SetDeleteArray(&deleteArray_TNuSec27);
      instance.SetDestructor(&destruct_TNuSec27);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec27*)
   {
      return GenerateInitInstanceLocal((::TNuSec27*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec27*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec07002Incoherent(void *p = 0);
   static void *newArray_TNuSec07002Incoherent(Long_t size, void *p);
   static void delete_TNuSec07002Incoherent(void *p);
   static void deleteArray_TNuSec07002Incoherent(void *p);
   static void destruct_TNuSec07002Incoherent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec07002Incoherent*)
   {
      ::TNuSec07002Incoherent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec07002Incoherent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec07002Incoherent", ::TNuSec07002Incoherent::Class_Version(), "TNuSec07002Incoherent.h", 44,
                  typeid(::TNuSec07002Incoherent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec07002Incoherent::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec07002Incoherent) );
      instance.SetNew(&new_TNuSec07002Incoherent);
      instance.SetNewArray(&newArray_TNuSec07002Incoherent);
      instance.SetDelete(&delete_TNuSec07002Incoherent);
      instance.SetDeleteArray(&deleteArray_TNuSec07002Incoherent);
      instance.SetDestructor(&destruct_TNuSec07002Incoherent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec07002Incoherent*)
   {
      return GenerateInitInstanceLocal((::TNuSec07002Incoherent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec07002Incoherent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuDEpDMuETransfer(void *p = 0);
   static void *newArray_TNuDEpDMuETransfer(Long_t size, void *p);
   static void delete_TNuDEpDMuETransfer(void *p);
   static void deleteArray_TNuDEpDMuETransfer(void *p);
   static void destruct_TNuDEpDMuETransfer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuDEpDMuETransfer*)
   {
      ::TNuDEpDMuETransfer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuDEpDMuETransfer >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuDEpDMuETransfer", ::TNuDEpDMuETransfer::Class_Version(), "TNuDEpDMuETransfer.h", 26,
                  typeid(::TNuDEpDMuETransfer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuDEpDMuETransfer::Dictionary, isa_proxy, 4,
                  sizeof(::TNuDEpDMuETransfer) );
      instance.SetNew(&new_TNuDEpDMuETransfer);
      instance.SetNewArray(&newArray_TNuDEpDMuETransfer);
      instance.SetDelete(&delete_TNuDEpDMuETransfer);
      instance.SetDeleteArray(&deleteArray_TNuDEpDMuETransfer);
      instance.SetDestructor(&destruct_TNuDEpDMuETransfer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuDEpDMuETransfer*)
   {
      return GenerateInitInstanceLocal((::TNuDEpDMuETransfer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuDEpDMuETransfer*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec02(void *p = 0);
   static void *newArray_TNuSec02(Long_t size, void *p);
   static void delete_TNuSec02(void *p);
   static void deleteArray_TNuSec02(void *p);
   static void destruct_TNuSec02(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec02*)
   {
      ::TNuSec02 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec02 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec02", ::TNuSec02::Class_Version(), "TNuSec02.h", 26,
                  typeid(::TNuSec02), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec02::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec02) );
      instance.SetNew(&new_TNuSec02);
      instance.SetNewArray(&newArray_TNuSec02);
      instance.SetDelete(&delete_TNuSec02);
      instance.SetDeleteArray(&deleteArray_TNuSec02);
      instance.SetDestructor(&destruct_TNuSec02);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec02*)
   {
      return GenerateInitInstanceLocal((::TNuSec02*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec02*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSubIsotope(void *p = 0);
   static void *newArray_TNuSubIsotope(Long_t size, void *p);
   static void delete_TNuSubIsotope(void *p);
   static void deleteArray_TNuSubIsotope(void *p);
   static void destruct_TNuSubIsotope(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSubIsotope*)
   {
      ::TNuSubIsotope *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSubIsotope >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSubIsotope", ::TNuSubIsotope::Class_Version(), "TNuSec02.h", 76,
                  typeid(::TNuSubIsotope), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSubIsotope::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSubIsotope) );
      instance.SetNew(&new_TNuSubIsotope);
      instance.SetNewArray(&newArray_TNuSubIsotope);
      instance.SetDelete(&delete_TNuSubIsotope);
      instance.SetDeleteArray(&deleteArray_TNuSubIsotope);
      instance.SetDestructor(&destruct_TNuSubIsotope);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSubIsotope*)
   {
      return GenerateInitInstanceLocal((::TNuSubIsotope*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSubIsotope*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoRMatrixLimited(void *p = 0);
   static void *newArray_TNuResoRMatrixLimited(Long_t size, void *p);
   static void delete_TNuResoRMatrixLimited(void *p);
   static void deleteArray_TNuResoRMatrixLimited(void *p);
   static void destruct_TNuResoRMatrixLimited(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoRMatrixLimited*)
   {
      ::TNuResoRMatrixLimited *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoRMatrixLimited >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoRMatrixLimited", ::TNuResoRMatrixLimited::Class_Version(), "TNuResoRMatrixLimited.h", 14,
                  typeid(::TNuResoRMatrixLimited), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoRMatrixLimited::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoRMatrixLimited) );
      instance.SetNew(&new_TNuResoRMatrixLimited);
      instance.SetNewArray(&newArray_TNuResoRMatrixLimited);
      instance.SetDelete(&delete_TNuResoRMatrixLimited);
      instance.SetDeleteArray(&deleteArray_TNuResoRMatrixLimited);
      instance.SetDestructor(&destruct_TNuResoRMatrixLimited);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoRMatrixLimited*)
   {
      return GenerateInitInstanceLocal((::TNuResoRMatrixLimited*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoRMatrixLimited*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNudy(void *p = 0);
   static void *newArray_TNudy(Long_t size, void *p);
   static void delete_TNudy(void *p);
   static void deleteArray_TNudy(void *p);
   static void destruct_TNudy(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNudy*)
   {
      ::TNudy *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNudy >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNudy", ::TNudy::Class_Version(), "TNudy.h", 31,
                  typeid(::TNudy), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNudy::Dictionary, isa_proxy, 4,
                  sizeof(::TNudy) );
      instance.SetNew(&new_TNudy);
      instance.SetNewArray(&newArray_TNudy);
      instance.SetDelete(&delete_TNudy);
      instance.SetDeleteArray(&deleteArray_TNudy);
      instance.SetDestructor(&destruct_TNudy);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNudy*)
   {
      return GenerateInitInstanceLocal((::TNudy*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNudy*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuResoUnresolved(void *p);
   static void deleteArray_TNuResoUnresolved(void *p);
   static void destruct_TNuResoUnresolved(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoUnresolved*)
   {
      ::TNuResoUnresolved *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoUnresolved >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoUnresolved", ::TNuResoUnresolved::Class_Version(), "TNuResoUnresolved.h", 19,
                  typeid(::TNuResoUnresolved), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoUnresolved::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoUnresolved) );
      instance.SetDelete(&delete_TNuResoUnresolved);
      instance.SetDeleteArray(&deleteArray_TNuResoUnresolved);
      instance.SetDestructor(&destruct_TNuResoUnresolved);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoUnresolved*)
   {
      return GenerateInitInstanceLocal((::TNuResoUnresolved*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoUnresolved*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoUnresolvedA(void *p = 0);
   static void *newArray_TNuResoUnresolvedA(Long_t size, void *p);
   static void delete_TNuResoUnresolvedA(void *p);
   static void deleteArray_TNuResoUnresolvedA(void *p);
   static void destruct_TNuResoUnresolvedA(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoUnresolvedA*)
   {
      ::TNuResoUnresolvedA *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoUnresolvedA >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoUnresolvedA", ::TNuResoUnresolvedA::Class_Version(), "TNuResoUnresolved.h", 41,
                  typeid(::TNuResoUnresolvedA), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoUnresolvedA::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoUnresolvedA) );
      instance.SetNew(&new_TNuResoUnresolvedA);
      instance.SetNewArray(&newArray_TNuResoUnresolvedA);
      instance.SetDelete(&delete_TNuResoUnresolvedA);
      instance.SetDeleteArray(&deleteArray_TNuResoUnresolvedA);
      instance.SetDestructor(&destruct_TNuResoUnresolvedA);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoUnresolvedA*)
   {
      return GenerateInitInstanceLocal((::TNuResoUnresolvedA*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoUnresolvedA*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoUnresolvedB(void *p = 0);
   static void *newArray_TNuResoUnresolvedB(Long_t size, void *p);
   static void delete_TNuResoUnresolvedB(void *p);
   static void deleteArray_TNuResoUnresolvedB(void *p);
   static void destruct_TNuResoUnresolvedB(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoUnresolvedB*)
   {
      ::TNuResoUnresolvedB *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoUnresolvedB >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoUnresolvedB", ::TNuResoUnresolvedB::Class_Version(), "TNuResoUnresolved.h", 53,
                  typeid(::TNuResoUnresolvedB), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoUnresolvedB::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoUnresolvedB) );
      instance.SetNew(&new_TNuResoUnresolvedB);
      instance.SetNewArray(&newArray_TNuResoUnresolvedB);
      instance.SetDelete(&delete_TNuResoUnresolvedB);
      instance.SetDeleteArray(&deleteArray_TNuResoUnresolvedB);
      instance.SetDestructor(&destruct_TNuResoUnresolvedB);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoUnresolvedB*)
   {
      return GenerateInitInstanceLocal((::TNuResoUnresolvedB*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoUnresolvedB*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoUnresolvedC(void *p = 0);
   static void *newArray_TNuResoUnresolvedC(Long_t size, void *p);
   static void delete_TNuResoUnresolvedC(void *p);
   static void deleteArray_TNuResoUnresolvedC(void *p);
   static void destruct_TNuResoUnresolvedC(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoUnresolvedC*)
   {
      ::TNuResoUnresolvedC *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoUnresolvedC >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoUnresolvedC", ::TNuResoUnresolvedC::Class_Version(), "TNuResoUnresolved.h", 70,
                  typeid(::TNuResoUnresolvedC), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoUnresolvedC::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoUnresolvedC) );
      instance.SetNew(&new_TNuResoUnresolvedC);
      instance.SetNewArray(&newArray_TNuResoUnresolvedC);
      instance.SetDelete(&delete_TNuResoUnresolvedC);
      instance.SetDeleteArray(&deleteArray_TNuResoUnresolvedC);
      instance.SetDestructor(&destruct_TNuResoUnresolvedC);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoUnresolvedC*)
   {
      return GenerateInitInstanceLocal((::TNuResoUnresolvedC*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoUnresolvedC*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_TNuCanvasPrinter(void *p);
   static void deleteArray_TNuCanvasPrinter(void *p);
   static void destruct_TNuCanvasPrinter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuCanvasPrinter*)
   {
      ::TNuCanvasPrinter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuCanvasPrinter >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuCanvasPrinter", ::TNuCanvasPrinter::Class_Version(), "TNuCanvasPrinter.h", 25,
                  typeid(::TNuCanvasPrinter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuCanvasPrinter::Dictionary, isa_proxy, 4,
                  sizeof(::TNuCanvasPrinter) );
      instance.SetDelete(&delete_TNuCanvasPrinter);
      instance.SetDeleteArray(&deleteArray_TNuCanvasPrinter);
      instance.SetDestructor(&destruct_TNuCanvasPrinter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuCanvasPrinter*)
   {
      return GenerateInitInstanceLocal((::TNuCanvasPrinter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuCanvasPrinter*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuTab1ListsSub(void *p = 0);
   static void *newArray_TNuTab1ListsSub(Long_t size, void *p);
   static void delete_TNuTab1ListsSub(void *p);
   static void deleteArray_TNuTab1ListsSub(void *p);
   static void destruct_TNuTab1ListsSub(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab1ListsSub*)
   {
      ::TNuTab1ListsSub *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab1ListsSub >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab1ListsSub", ::TNuTab1ListsSub::Class_Version(), "TNuTab1ListsSub.h", 32,
                  typeid(::TNuTab1ListsSub), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab1ListsSub::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab1ListsSub) );
      instance.SetNew(&new_TNuTab1ListsSub);
      instance.SetNewArray(&newArray_TNuTab1ListsSub);
      instance.SetDelete(&delete_TNuTab1ListsSub);
      instance.SetDeleteArray(&deleteArray_TNuTab1ListsSub);
      instance.SetDestructor(&destruct_TNuTab1ListsSub);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab1ListsSub*)
   {
      return GenerateInitInstanceLocal((::TNuTab1ListsSub*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab1ListsSub*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoAdlerAdler(void *p = 0);
   static void *newArray_TNuResoAdlerAdler(Long_t size, void *p);
   static void delete_TNuResoAdlerAdler(void *p);
   static void deleteArray_TNuResoAdlerAdler(void *p);
   static void destruct_TNuResoAdlerAdler(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoAdlerAdler*)
   {
      ::TNuResoAdlerAdler *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoAdlerAdler >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoAdlerAdler", ::TNuResoAdlerAdler::Class_Version(), "TNuResoAdlerAdler.h", 13,
                  typeid(::TNuResoAdlerAdler), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoAdlerAdler::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoAdlerAdler) );
      instance.SetNew(&new_TNuResoAdlerAdler);
      instance.SetNewArray(&newArray_TNuResoAdlerAdler);
      instance.SetDelete(&delete_TNuResoAdlerAdler);
      instance.SetDeleteArray(&deleteArray_TNuResoAdlerAdler);
      instance.SetDestructor(&destruct_TNuResoAdlerAdler);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoAdlerAdler*)
   {
      return GenerateInitInstanceLocal((::TNuResoAdlerAdler*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoAdlerAdler*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuTab3Tab2(void *p = 0);
   static void *newArray_TNuTab3Tab2(Long_t size, void *p);
   static void delete_TNuTab3Tab2(void *p);
   static void deleteArray_TNuTab3Tab2(void *p);
   static void destruct_TNuTab3Tab2(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab3Tab2*)
   {
      ::TNuTab3Tab2 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab3Tab2 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab3Tab2", ::TNuTab3Tab2::Class_Version(), "TNuTab3Tab2.h", 25,
                  typeid(::TNuTab3Tab2), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab3Tab2::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab3Tab2) );
      instance.SetNew(&new_TNuTab3Tab2);
      instance.SetNewArray(&newArray_TNuTab3Tab2);
      instance.SetDelete(&delete_TNuTab3Tab2);
      instance.SetDeleteArray(&deleteArray_TNuTab3Tab2);
      instance.SetDestructor(&destruct_TNuTab3Tab2);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab3Tab2*)
   {
      return GenerateInitInstanceLocal((::TNuTab3Tab2*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab3Tab2*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuTab3Tab1Lists(void *p = 0);
   static void *newArray_TNuTab3Tab1Lists(Long_t size, void *p);
   static void delete_TNuTab3Tab1Lists(void *p);
   static void deleteArray_TNuTab3Tab1Lists(void *p);
   static void destruct_TNuTab3Tab1Lists(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab3Tab1Lists*)
   {
      ::TNuTab3Tab1Lists *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab3Tab1Lists >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab3Tab1Lists", ::TNuTab3Tab1Lists::Class_Version(), "TNuTab3Tab1Lists.h", 25,
                  typeid(::TNuTab3Tab1Lists), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab3Tab1Lists::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab3Tab1Lists) );
      instance.SetNew(&new_TNuTab3Tab1Lists);
      instance.SetNewArray(&newArray_TNuTab3Tab1Lists);
      instance.SetDelete(&delete_TNuTab3Tab1Lists);
      instance.SetDeleteArray(&deleteArray_TNuTab3Tab1Lists);
      instance.SetDestructor(&destruct_TNuTab3Tab1Lists);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab3Tab1Lists*)
   {
      return GenerateInitInstanceLocal((::TNuTab3Tab1Lists*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab3Tab1Lists*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuListFPY(void *p = 0);
   static void *newArray_TNuListFPY(Long_t size, void *p);
   static void delete_TNuListFPY(void *p);
   static void deleteArray_TNuListFPY(void *p);
   static void destruct_TNuListFPY(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuListFPY*)
   {
      ::TNuListFPY *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuListFPY >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuListFPY", ::TNuListFPY::Class_Version(), "TNuListFPY.h", 27,
                  typeid(::TNuListFPY), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuListFPY::Dictionary, isa_proxy, 4,
                  sizeof(::TNuListFPY) );
      instance.SetNew(&new_TNuListFPY);
      instance.SetNewArray(&newArray_TNuListFPY);
      instance.SetDelete(&delete_TNuListFPY);
      instance.SetDeleteArray(&deleteArray_TNuListFPY);
      instance.SetDestructor(&destruct_TNuListFPY);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuListFPY*)
   {
      return GenerateInitInstanceLocal((::TNuListFPY*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuListFPY*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec26(void *p = 0);
   static void *newArray_TNuSec26(Long_t size, void *p);
   static void delete_TNuSec26(void *p);
   static void deleteArray_TNuSec26(void *p);
   static void destruct_TNuSec26(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec26*)
   {
      ::TNuSec26 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec26 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec26", ::TNuSec26::Class_Version(), "TNuSec26.h", 41,
                  typeid(::TNuSec26), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec26::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec26) );
      instance.SetNew(&new_TNuSec26);
      instance.SetNewArray(&newArray_TNuSec26);
      instance.SetDelete(&delete_TNuSec26);
      instance.SetDeleteArray(&deleteArray_TNuSec26);
      instance.SetDestructor(&destruct_TNuSec26);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec26*)
   {
      return GenerateInitInstanceLocal((::TNuSec26*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec26*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuList1Tab1(void *p = 0);
   static void *newArray_TNuList1Tab1(Long_t size, void *p);
   static void delete_TNuList1Tab1(void *p);
   static void deleteArray_TNuList1Tab1(void *p);
   static void destruct_TNuList1Tab1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuList1Tab1*)
   {
      ::TNuList1Tab1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuList1Tab1 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuList1Tab1", ::TNuList1Tab1::Class_Version(), "TNuList1Tab1.h", 28,
                  typeid(::TNuList1Tab1), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuList1Tab1::Dictionary, isa_proxy, 4,
                  sizeof(::TNuList1Tab1) );
      instance.SetNew(&new_TNuList1Tab1);
      instance.SetNewArray(&newArray_TNuList1Tab1);
      instance.SetDelete(&delete_TNuList1Tab1);
      instance.SetDeleteArray(&deleteArray_TNuList1Tab1);
      instance.SetDestructor(&destruct_TNuList1Tab1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuList1Tab1*)
   {
      return GenerateInitInstanceLocal((::TNuList1Tab1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuList1Tab1*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec01460(void *p = 0);
   static void *newArray_TNuSec01460(Long_t size, void *p);
   static void delete_TNuSec01460(void *p);
   static void deleteArray_TNuSec01460(void *p);
   static void destruct_TNuSec01460(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec01460*)
   {
      ::TNuSec01460 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec01460 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec01460", ::TNuSec01460::Class_Version(), "TNuSec01460.h", 19,
                  typeid(::TNuSec01460), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec01460::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec01460) );
      instance.SetNew(&new_TNuSec01460);
      instance.SetNewArray(&newArray_TNuSec01460);
      instance.SetDelete(&delete_TNuSec01460);
      instance.SetDeleteArray(&deleteArray_TNuSec01460);
      instance.SetDestructor(&destruct_TNuSec01460);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec01460*)
   {
      return GenerateInitInstanceLocal((::TNuSec01460*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec01460*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoBrightWigner(void *p = 0);
   static void *newArray_TNuResoBrightWigner(Long_t size, void *p);
   static void delete_TNuResoBrightWigner(void *p);
   static void deleteArray_TNuResoBrightWigner(void *p);
   static void destruct_TNuResoBrightWigner(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoBrightWigner*)
   {
      ::TNuResoBrightWigner *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoBrightWigner >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoBrightWigner", ::TNuResoBrightWigner::Class_Version(), "TNuResoBrightWigner.h", 25,
                  typeid(::TNuResoBrightWigner), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoBrightWigner::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoBrightWigner) );
      instance.SetNew(&new_TNuResoBrightWigner);
      instance.SetNewArray(&newArray_TNuResoBrightWigner);
      instance.SetDelete(&delete_TNuResoBrightWigner);
      instance.SetDeleteArray(&deleteArray_TNuResoBrightWigner);
      instance.SetDestructor(&destruct_TNuResoBrightWigner);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoBrightWigner*)
   {
      return GenerateInitInstanceLocal((::TNuResoBrightWigner*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoBrightWigner*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoSLBW(void *p = 0);
   static void *newArray_TNuResoSLBW(Long_t size, void *p);
   static void delete_TNuResoSLBW(void *p);
   static void deleteArray_TNuResoSLBW(void *p);
   static void destruct_TNuResoSLBW(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoSLBW*)
   {
      ::TNuResoSLBW *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoSLBW >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoSLBW", ::TNuResoSLBW::Class_Version(), "TNuResoBrightWigner.h", 39,
                  typeid(::TNuResoSLBW), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoSLBW::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoSLBW) );
      instance.SetNew(&new_TNuResoSLBW);
      instance.SetNewArray(&newArray_TNuResoSLBW);
      instance.SetDelete(&delete_TNuResoSLBW);
      instance.SetDeleteArray(&deleteArray_TNuResoSLBW);
      instance.SetDestructor(&destruct_TNuResoSLBW);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoSLBW*)
   {
      return GenerateInitInstanceLocal((::TNuResoSLBW*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoSLBW*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuResoMLBW(void *p = 0);
   static void *newArray_TNuResoMLBW(Long_t size, void *p);
   static void delete_TNuResoMLBW(void *p);
   static void deleteArray_TNuResoMLBW(void *p);
   static void destruct_TNuResoMLBW(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuResoMLBW*)
   {
      ::TNuResoMLBW *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuResoMLBW >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuResoMLBW", ::TNuResoMLBW::Class_Version(), "TNuResoBrightWigner.h", 49,
                  typeid(::TNuResoMLBW), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuResoMLBW::Dictionary, isa_proxy, 4,
                  sizeof(::TNuResoMLBW) );
      instance.SetNew(&new_TNuResoMLBW);
      instance.SetNewArray(&newArray_TNuResoMLBW);
      instance.SetDelete(&delete_TNuResoMLBW);
      instance.SetDeleteArray(&deleteArray_TNuResoMLBW);
      instance.SetDestructor(&destruct_TNuResoMLBW);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuResoMLBW*)
   {
      return GenerateInitInstanceLocal((::TNuResoMLBW*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuResoMLBW*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec08454(void *p = 0);
   static void *newArray_TNuSec08454(Long_t size, void *p);
   static void delete_TNuSec08454(void *p);
   static void deleteArray_TNuSec08454(void *p);
   static void destruct_TNuSec08454(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec08454*)
   {
      ::TNuSec08454 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec08454 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec08454", ::TNuSec08454::Class_Version(), "TNuSec08454.h", 21,
                  typeid(::TNuSec08454), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec08454::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec08454) );
      instance.SetNew(&new_TNuSec08454);
      instance.SetNewArray(&newArray_TNuSec08454);
      instance.SetDelete(&delete_TNuSec08454);
      instance.SetDeleteArray(&deleteArray_TNuSec08454);
      instance.SetDestructor(&destruct_TNuSec08454);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec08454*)
   {
      return GenerateInitInstanceLocal((::TNuSec08454*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec08454*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuList2Tab1(void *p = 0);
   static void *newArray_TNuList2Tab1(Long_t size, void *p);
   static void delete_TNuList2Tab1(void *p);
   static void deleteArray_TNuList2Tab1(void *p);
   static void destruct_TNuList2Tab1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuList2Tab1*)
   {
      ::TNuList2Tab1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuList2Tab1 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuList2Tab1", ::TNuList2Tab1::Class_Version(), "TNuList2Tab1.h", 35,
                  typeid(::TNuList2Tab1), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuList2Tab1::Dictionary, isa_proxy, 4,
                  sizeof(::TNuList2Tab1) );
      instance.SetNew(&new_TNuList2Tab1);
      instance.SetNewArray(&newArray_TNuList2Tab1);
      instance.SetDelete(&delete_TNuList2Tab1);
      instance.SetDeleteArray(&deleteArray_TNuList2Tab1);
      instance.SetDestructor(&destruct_TNuList2Tab1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuList2Tab1*)
   {
      return GenerateInitInstanceLocal((::TNuList2Tab1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuList2Tab1*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuSec23(void *p = 0);
   static void *newArray_TNuSec23(Long_t size, void *p);
   static void delete_TNuSec23(void *p);
   static void deleteArray_TNuSec23(void *p);
   static void destruct_TNuSec23(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuSec23*)
   {
      ::TNuSec23 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuSec23 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuSec23", ::TNuSec23::Class_Version(), "TNuSec23.h", 37,
                  typeid(::TNuSec23), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuSec23::Dictionary, isa_proxy, 4,
                  sizeof(::TNuSec23) );
      instance.SetNew(&new_TNuSec23);
      instance.SetNewArray(&newArray_TNuSec23);
      instance.SetDelete(&delete_TNuSec23);
      instance.SetDeleteArray(&deleteArray_TNuSec23);
      instance.SetDestructor(&destruct_TNuSec23);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuSec23*)
   {
      return GenerateInitInstanceLocal((::TNuSec23*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuSec23*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNuTab3List2(void *p = 0);
   static void *newArray_TNuTab3List2(Long_t size, void *p);
   static void delete_TNuTab3List2(void *p);
   static void deleteArray_TNuTab3List2(void *p);
   static void destruct_TNuTab3List2(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNuTab3List2*)
   {
      ::TNuTab3List2 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNuTab3List2 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNuTab3List2", ::TNuTab3List2::Class_Version(), "TNuTab3List2.h", 25,
                  typeid(::TNuTab3List2), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNuTab3List2::Dictionary, isa_proxy, 4,
                  sizeof(::TNuTab3List2) );
      instance.SetNew(&new_TNuTab3List2);
      instance.SetNewArray(&newArray_TNuTab3List2);
      instance.SetDelete(&delete_TNuTab3List2);
      instance.SetDeleteArray(&deleteArray_TNuTab3List2);
      instance.SetDestructor(&destruct_TNuTab3List2);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNuTab3List2*)
   {
      return GenerateInitInstanceLocal((::TNuTab3List2*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNuTab3List2*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TNuLabel::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuLabel::Class_Name()
{
   return "TNuLabel";
}

//______________________________________________________________________________
const char *TNuLabel::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuLabel*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuLabel::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuLabel*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuLabel::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuLabel*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuLabel::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuLabel*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuObject::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuObject::Class_Name()
{
   return "TNuObject";
}

//______________________________________________________________________________
const char *TNuObject::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuObject*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuObject::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuObject*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuObject::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuObject*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuObject::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuObject*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuVF1::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuVF1::Class_Name()
{
   return "TNuVF1";
}

//______________________________________________________________________________
const char *TNuVF1::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVF1*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuVF1::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVF1*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuVF1::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVF1*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuVF1::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVF1*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuVF1s::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuVF1s::Class_Name()
{
   return "TNuVF1s";
}

//______________________________________________________________________________
const char *TNuVF1s::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVF1s*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuVF1s::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVF1s*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuVF1s::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVF1s*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuVF1s::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVF1s*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuVResonance::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuVResonance::Class_Name()
{
   return "TNuVResonance";
}

//______________________________________________________________________________
const char *TNuVResonance::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVResonance*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuVResonance::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVResonance*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuVResonance::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVResonance*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuVResonance::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVResonance*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSaveToTextDlg::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSaveToTextDlg::Class_Name()
{
   return "TNuSaveToTextDlg";
}

//______________________________________________________________________________
const char *TNuSaveToTextDlg::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSaveToTextDlg*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSaveToTextDlg::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSaveToTextDlg*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSaveToTextDlg::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSaveToTextDlg*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSaveToTextDlg::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSaveToTextDlg*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyFileDlg::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyFileDlg::Class_Name()
{
   return "MyFileDlg";
}

//______________________________________________________________________________
const char *MyFileDlg::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFileDlg*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyFileDlg::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFileDlg*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyFileDlg::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFileDlg*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyFileDlg::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFileDlg*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuPrinter::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuPrinter::Class_Name()
{
   return "TNuPrinter";
}

//______________________________________________________________________________
const char *TNuPrinter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuPrinter*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuPrinter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuPrinter*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuPrinter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuPrinter*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuPrinter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuPrinter*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuCont::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuCont::Class_Name()
{
   return "TNuCont";
}

//______________________________________________________________________________
const char *TNuCont::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuCont*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuCont::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuCont*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuCont::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuCont*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuCont::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuCont*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuRecs::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuRecs::Class_Name()
{
   return "TNuRecs";
}

//______________________________________________________________________________
const char *TNuRecs::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuRecs*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuRecs::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuRecs*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuRecs::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuRecs*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuRecs::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuRecs*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSection::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSection::Class_Name()
{
   return "TNuSection";
}

//______________________________________________________________________________
const char *TNuSection::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSection*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSection::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSection*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSection::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSection*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSection::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSection*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuVTab::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuVTab::Class_Name()
{
   return "TNuVTab";
}

//______________________________________________________________________________
const char *TNuVTab::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVTab*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuVTab::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVTab*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuVTab::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVTab*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuVTab::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVTab*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuEndfTAB2::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuEndfTAB2::Class_Name()
{
   return "TNuEndfTAB2";
}

//______________________________________________________________________________
const char *TNuEndfTAB2::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuEndfTAB2*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuEndfTAB2::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuEndfTAB2*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuEndfTAB2::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuEndfTAB2*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuEndfTAB2::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuEndfTAB2*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab1::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab1::Class_Name()
{
   return "TNuTab1";
}

//______________________________________________________________________________
const char *TNuTab1::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab1::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab1::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab1::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuEndfIO::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuEndfIO::Class_Name()
{
   return "TNuEndfIO";
}

//______________________________________________________________________________
const char *TNuEndfIO::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuEndfIO*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuEndfIO::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuEndfIO*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuEndfIO::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuEndfIO*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuEndfIO::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuEndfIO*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec13::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec13::Class_Name()
{
   return "TNuSec13";
}

//______________________________________________________________________________
const char *TNuSec13::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec13*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec13::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec13*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec13::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec13*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec13::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec13*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec10::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec10::Class_Name()
{
   return "TNuSec10";
}

//______________________________________________________________________________
const char *TNuSec10::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec10*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec10::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec10*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec10::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec10*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec10::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec10*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec09::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec09::Class_Name()
{
   return "TNuSec09";
}

//______________________________________________________________________________
const char *TNuSec09::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec09*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec09::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec09*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec09::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec09*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec09::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec09*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuCollection::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuCollection::Class_Name()
{
   return "TNuCollection";
}

//______________________________________________________________________________
const char *TNuCollection::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuCollection*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuCollection::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuCollection*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuCollection::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuCollection*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuCollection::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuCollection*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuIter::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuIter::Class_Name()
{
   return "TNuIter";
}

//______________________________________________________________________________
const char *TNuIter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuIter*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuIter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuIter*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuIter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuIter*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuIter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuIter*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuLazyCollection::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuLazyCollection::Class_Name()
{
   return "TNuLazyCollection";
}

//______________________________________________________________________________
const char *TNuLazyCollection::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuLazyCollection*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuLazyCollection::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuLazyCollection*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuLazyCollection::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuLazyCollection*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuLazyCollection::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuLazyCollection*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuFile::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuFile::Class_Name()
{
   return "TNuFile";
}

//______________________________________________________________________________
const char *TNuFile::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuFile*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuFile::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuFile*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuFile::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuFile*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuFile::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuFile*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuMat::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuMat::Class_Name()
{
   return "TNuMat";
}

//______________________________________________________________________________
const char *TNuMat::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuMat*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuMat::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuMat*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuMat::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuMat*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuMat::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuMat*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSublib::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSublib::Class_Name()
{
   return "TNuSublib";
}

//______________________________________________________________________________
const char *TNuSublib::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSublib*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSublib::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSublib*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSublib::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSublib*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSublib::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSublib*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuLib::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuLib::Class_Name()
{
   return "TNuLib";
}

//______________________________________________________________________________
const char *TNuLib::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuLib*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuLib::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuLib*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuLib::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuLib*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuLib::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuLib*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuIntg::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuIntg::Class_Name()
{
   return "TNuIntg";
}

//______________________________________________________________________________
const char *TNuIntg::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuIntg*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuIntg::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuIntg*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuIntg::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuIntg*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuIntg::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuIntg*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuRecsWithCont::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuRecsWithCont::Class_Name()
{
   return "TNuRecsWithCont";
}

//______________________________________________________________________________
const char *TNuRecsWithCont::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithCont*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuRecsWithCont::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithCont*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuRecsWithCont::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithCont*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuRecsWithCont::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithCont*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuList::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuList::Class_Name()
{
   return "TNuList";
}

//______________________________________________________________________________
const char *TNuList::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuList::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuList::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuList::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuContLists::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuContLists::Class_Name()
{
   return "TNuContLists";
}

//______________________________________________________________________________
const char *TNuContLists::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContLists*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuContLists::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContLists*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuContLists::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContLists*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuContLists::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContLists*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuVF2::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuVF2::Class_Name()
{
   return "TNuVF2";
}

//______________________________________________________________________________
const char *TNuVF2::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVF2*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuVF2::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVF2*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuVF2::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVF2*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuVF2::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVF2*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab1Lists::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab1Lists::Class_Name()
{
   return "TNuTab1Lists";
}

//______________________________________________________________________________
const char *TNuTab1Lists::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1Lists*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab1Lists::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1Lists*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab1Lists::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1Lists*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab1Lists::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1Lists*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuList1::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuList1::Class_Name()
{
   return "TNuList1";
}

//______________________________________________________________________________
const char *TNuList1::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList1*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuList1::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList1*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuList1::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList1*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuList1::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList1*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuListTaylor::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuListTaylor::Class_Name()
{
   return "TNuListTaylor";
}

//______________________________________________________________________________
const char *TNuListTaylor::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListTaylor*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuListTaylor::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListTaylor*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuListTaylor::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListTaylor*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuListTaylor::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListTaylor*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuRecsWithTAB2::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuRecsWithTAB2::Class_Name()
{
   return "TNuRecsWithTAB2";
}

//______________________________________________________________________________
const char *TNuRecsWithTAB2::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithTAB2*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuRecsWithTAB2::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithTAB2*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuRecsWithTAB2::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithTAB2*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuRecsWithTAB2::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithTAB2*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab2::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab2::Class_Name()
{
   return "TNuTab2";
}

//______________________________________________________________________________
const char *TNuTab2::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab2::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab2::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab2::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuRecsWithTab1::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuRecsWithTab1::Class_Name()
{
   return "TNuRecsWithTab1";
}

//______________________________________________________________________________
const char *TNuRecsWithTab1::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithTab1*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuRecsWithTab1::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithTab1*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuRecsWithTab1::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithTab1*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuRecsWithTab1::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuRecsWithTab1*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec15::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec15::Class_Name()
{
   return "TNuSec15";
}

//______________________________________________________________________________
const char *TNuSec15::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec15*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec15::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec15*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec15::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec15*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec15::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec15*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResonance::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResonance::Class_Name()
{
   return "TNuResonance";
}

//______________________________________________________________________________
const char *TNuResonance::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResonance*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResonance::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResonance*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResonance::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResonance*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResonance::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResonance*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoResolved::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoResolved::Class_Name()
{
   return "TNuResoResolved";
}

//______________________________________________________________________________
const char *TNuResoResolved::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoResolved*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoResolved::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoResolved*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoResolved::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoResolved*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoResolved::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoResolved*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec04::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec04::Class_Name()
{
   return "TNuSec04";
}

//______________________________________________________________________________
const char *TNuSec04::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec04*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec04::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec04*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec04::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec04*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec04::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec04*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuListLegendre::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuListLegendre::Class_Name()
{
   return "TNuListLegendre";
}

//______________________________________________________________________________
const char *TNuListLegendre::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListLegendre*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuListLegendre::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListLegendre*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuListLegendre::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListLegendre*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuListLegendre::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListLegendre*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec03::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec03::Class_Name()
{
   return "TNuSec03";
}

//______________________________________________________________________________
const char *TNuSec03::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec03*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec03::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec03*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec03::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec03*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec03::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec03*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuVF3::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuVF3::Class_Name()
{
   return "TNuVF3";
}

//______________________________________________________________________________
const char *TNuVF3::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVF3*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuVF3::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuVF3*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuVF3::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVF3*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuVF3::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuVF3*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab3::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab3::Class_Name()
{
   return "TNuTab3";
}

//______________________________________________________________________________
const char *TNuTab3::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab3::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab3::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab3::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec06::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec06::Class_Name()
{
   return "TNuSec06";
}

//______________________________________________________________________________
const char *TNuSec06::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec06*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec06::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec06*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec06::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec06*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec06::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec06*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec07002::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec07002::Class_Name()
{
   return "TNuSec07002";
}

//______________________________________________________________________________
const char *TNuSec07002::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec07002::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec07002::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec07002::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec07002Coherent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec07002Coherent::Class_Name()
{
   return "TNuSec07002Coherent";
}

//______________________________________________________________________________
const char *TNuSec07002Coherent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002Coherent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec07002Coherent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002Coherent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec07002Coherent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002Coherent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec07002Coherent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002Coherent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDescription::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDescription::Class_Name()
{
   return "TNuDescription";
}

//______________________________________________________________________________
const char *TNuDescription::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDescription*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDescription::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDescription*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDescription::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDescription*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDescription::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDescription*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDirs::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDirs::Class_Name()
{
   return "TNuDirs";
}

//______________________________________________________________________________
const char *TNuDirs::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDirs*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDirs::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDirs*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDirs::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDirs*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDirs::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDirs*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec01458::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec01458::Class_Name()
{
   return "TNuSec01458";
}

//______________________________________________________________________________
const char *TNuSec01458::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01458*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec01458::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01458*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec01458::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01458*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec01458::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01458*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec28::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec28::Class_Name()
{
   return "TNuSec28";
}

//______________________________________________________________________________
const char *TNuSec28::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec28*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec28::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec28*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec28::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec28*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec28::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec28*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMu::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMu::Class_Name()
{
   return "TNuDEpDMu";
}

//______________________________________________________________________________
const char *TNuDEpDMu::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMu::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMu::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMu::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMuF3::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMuF3::Class_Name()
{
   return "TNuDEpDMuF3";
}

//______________________________________________________________________________
const char *TNuDEpDMuF3::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuF3*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMuF3::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuF3*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMuF3::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuF3*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMuF3::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuF3*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMuUnknwon::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMuUnknwon::Class_Name()
{
   return "TNuDEpDMuUnknwon";
}

//______________________________________________________________________________
const char *TNuDEpDMuUnknwon::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuUnknwon*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMuUnknwon::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuUnknwon*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMuUnknwon::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuUnknwon*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMuUnknwon::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuUnknwon*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMuContinuum::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMuContinuum::Class_Name()
{
   return "TNuDEpDMuContinuum";
}

//______________________________________________________________________________
const char *TNuDEpDMuContinuum::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuContinuum*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMuContinuum::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuContinuum*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMuContinuum::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuContinuum*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMuContinuum::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuContinuum*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMuNBodyPhaseSpace::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMuNBodyPhaseSpace::Class_Name()
{
   return "TNuDEpDMuNBodyPhaseSpace";
}

//______________________________________________________________________________
const char *TNuDEpDMuNBodyPhaseSpace::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuNBodyPhaseSpace*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMuNBodyPhaseSpace::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuNBodyPhaseSpace*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMuNBodyPhaseSpace::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuNBodyPhaseSpace*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMuNBodyPhaseSpace::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuNBodyPhaseSpace*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMuLaboratory::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMuLaboratory::Class_Name()
{
   return "TNuDEpDMuLaboratory";
}

//______________________________________________________________________________
const char *TNuDEpDMuLaboratory::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuLaboratory*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMuLaboratory::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuLaboratory*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMuLaboratory::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuLaboratory*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMuLaboratory::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuLaboratory*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMu2Body::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMu2Body::Class_Name()
{
   return "TNuDEpDMu2Body";
}

//______________________________________________________________________________
const char *TNuDEpDMu2Body::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2Body*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMu2Body::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2Body*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMu2Body::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2Body*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMu2Body::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2Body*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMu2BodyScattering::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMu2BodyScattering::Class_Name()
{
   return "TNuDEpDMu2BodyScattering";
}

//______________________________________________________________________________
const char *TNuDEpDMu2BodyScattering::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyScattering*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMu2BodyScattering::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyScattering*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMu2BodyScattering::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyScattering*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMu2BodyScattering::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyScattering*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMu2BodyIsotropic::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMu2BodyIsotropic::Class_Name()
{
   return "TNuDEpDMu2BodyIsotropic";
}

//______________________________________________________________________________
const char *TNuDEpDMu2BodyIsotropic::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyIsotropic*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMu2BodyIsotropic::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyIsotropic*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMu2BodyIsotropic::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyIsotropic*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMu2BodyIsotropic::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyIsotropic*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMu2BodyRecoil::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMu2BodyRecoil::Class_Name()
{
   return "TNuDEpDMu2BodyRecoil";
}

//______________________________________________________________________________
const char *TNuDEpDMu2BodyRecoil::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyRecoil*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMu2BodyRecoil::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyRecoil*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMu2BodyRecoil::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyRecoil*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMu2BodyRecoil::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyRecoil*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMu2BodyCoulomb::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMu2BodyCoulomb::Class_Name()
{
   return "TNuDEpDMu2BodyCoulomb";
}

//______________________________________________________________________________
const char *TNuDEpDMu2BodyCoulomb::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyCoulomb*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMu2BodyCoulomb::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyCoulomb*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMu2BodyCoulomb::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyCoulomb*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMu2BodyCoulomb::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMu2BodyCoulomb*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec12::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec12::Class_Name()
{
   return "TNuSec12";
}

//______________________________________________________________________________
const char *TNuSec12::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec12::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec12::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec12::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec12Transitions::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec12Transitions::Class_Name()
{
   return "TNuSec12Transitions";
}

//______________________________________________________________________________
const char *TNuSec12Transitions::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12Transitions*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec12Transitions::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12Transitions*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec12Transitions::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12Transitions*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec12Transitions::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12Transitions*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuListCoulomb::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuListCoulomb::Class_Name()
{
   return "TNuListCoulomb";
}

//______________________________________________________________________________
const char *TNuListCoulomb::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListCoulomb*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuListCoulomb::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListCoulomb*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuListCoulomb::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListCoulomb*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuListCoulomb::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListCoulomb*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoReichMoore::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoReichMoore::Class_Name()
{
   return "TNuResoReichMoore";
}

//______________________________________________________________________________
const char *TNuResoReichMoore::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoReichMoore*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoReichMoore::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoReichMoore*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoReichMoore::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoReichMoore*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoReichMoore::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoReichMoore*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec07004::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec07004::Class_Name()
{
   return "TNuSec07004";
}

//______________________________________________________________________________
const char *TNuSec07004::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07004*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec07004::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07004*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec07004::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07004*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec07004::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07004*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec01451::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec01451::Class_Name()
{
   return "TNuSec01451";
}

//______________________________________________________________________________
const char *TNuSec01451::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01451*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec01451::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01451*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec01451::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01451*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec01451::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01451*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec08::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec08::Class_Name()
{
   return "TNuSec08";
}

//______________________________________________________________________________
const char *TNuSec08::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec08::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec08::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec08::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuList2::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuList2::Class_Name()
{
   return "TNuList2";
}

//______________________________________________________________________________
const char *TNuList2::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList2*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuList2::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList2*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuList2::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList2*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuList2::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList2*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuList2KalbachMann::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuList2KalbachMann::Class_Name()
{
   return "TNuList2KalbachMann";
}

//______________________________________________________________________________
const char *TNuList2KalbachMann::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList2KalbachMann*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuList2KalbachMann::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList2KalbachMann*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuList2KalbachMann::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList2KalbachMann*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuList2KalbachMann::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList2KalbachMann*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec01::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec01::Class_Name()
{
   return "TNuSec01";
}

//______________________________________________________________________________
const char *TNuSec01::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec01::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec01::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec01::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec12Yields::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec12Yields::Class_Name()
{
   return "TNuSec12Yields";
}

//______________________________________________________________________________
const char *TNuSec12Yields::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12Yields*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec12Yields::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12Yields*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec12Yields::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12Yields*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec12Yields::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec12Yields*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuContList::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuContList::Class_Name()
{
   return "TNuContList";
}

//______________________________________________________________________________
const char *TNuContList::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContList*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuContList::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContList*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuContList::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContList*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuContList::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContList*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec08457::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec08457::Class_Name()
{
   return "TNuSec08457";
}

//______________________________________________________________________________
const char *TNuSec08457::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08457*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec08457::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08457*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec08457::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08457*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec08457::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08457*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSFYSub::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSFYSub::Class_Name()
{
   return "TNuSFYSub";
}

//______________________________________________________________________________
const char *TNuSFYSub::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSFYSub*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSFYSub::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSFYSub*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSFYSub::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSFYSub*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSFYSub::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSFYSub*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuList2Legendre::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuList2Legendre::Class_Name()
{
   return "TNuList2Legendre";
}

//______________________________________________________________________________
const char *TNuList2Legendre::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList2Legendre*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuList2Legendre::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList2Legendre*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuList2Legendre::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList2Legendre*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuList2Legendre::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList2Legendre*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab2Tab1::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab2Tab1::Class_Name()
{
   return "TNuTab2Tab1";
}

//______________________________________________________________________________
const char *TNuTab2Tab1::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2Tab1*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab2Tab1::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2Tab1*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab2Tab1::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2Tab1*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab2Tab1::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2Tab1*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuContListNC::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuContListNC::Class_Name()
{
   return "TNuContListNC";
}

//______________________________________________________________________________
const char *TNuContListNC::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContListNC*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuContListNC::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContListNC*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuContListNC::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContListNC*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuContListNC::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContListNC*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuListNI::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuListNI::Class_Name()
{
   return "TNuListNI";
}

//______________________________________________________________________________
const char *TNuListNI::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListNI*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuListNI::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListNI*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuListNI::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListNI*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuListNI::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListNI*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuContListsCov33::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuContListsCov33::Class_Name()
{
   return "TNuContListsCov33";
}

//______________________________________________________________________________
const char *TNuContListsCov33::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContListsCov33*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuContListsCov33::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContListsCov33*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuContListsCov33::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContListsCov33*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuContListsCov33::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContListsCov33*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuCovMatrix::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuCovMatrix::Class_Name()
{
   return "TNuCovMatrix";
}

//______________________________________________________________________________
const char *TNuCovMatrix::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuCovMatrix*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuCovMatrix::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuCovMatrix*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuCovMatrix::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuCovMatrix*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuCovMatrix::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuCovMatrix*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec31::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec31::Class_Name()
{
   return "TNuSec31";
}

//______________________________________________________________________________
const char *TNuSec31::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec31*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec31::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec31*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec31::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec31*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec31::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec31*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec33::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec33::Class_Name()
{
   return "TNuSec33";
}

//______________________________________________________________________________
const char *TNuSec33::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec33*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec33::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec33*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec33::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec33*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec33::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec33*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuContListsCov34::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuContListsCov34::Class_Name()
{
   return "TNuContListsCov34";
}

//______________________________________________________________________________
const char *TNuContListsCov34::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContListsCov34*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuContListsCov34::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuContListsCov34*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuContListsCov34::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContListsCov34*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuContListsCov34::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuContListsCov34*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSubSec34::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSubSec34::Class_Name()
{
   return "TNuSubSec34";
}

//______________________________________________________________________________
const char *TNuSubSec34::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSubSec34*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSubSec34::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSubSec34*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSubSec34::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSubSec34*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSubSec34::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSubSec34*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec34::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec34::Class_Name()
{
   return "TNuSec34";
}

//______________________________________________________________________________
const char *TNuSec34::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec34*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec34::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec34*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec34::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec34*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec34::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec34*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec35::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec35::Class_Name()
{
   return "TNuSec35";
}

//______________________________________________________________________________
const char *TNuSec35::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec35*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec35::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec35*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec35::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec35*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec35::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec35*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec40::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec40::Class_Name()
{
   return "TNuSec40";
}

//______________________________________________________________________________
const char *TNuSec40::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec40*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec40::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec40*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec40::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec40*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec40::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec40*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec32::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec32::Class_Name()
{
   return "TNuSec32";
}

//______________________________________________________________________________
const char *TNuSec32::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec32*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec32::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec32*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec32::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec32*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec32::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec32*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSubIsotopeCov::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSubIsotopeCov::Class_Name()
{
   return "TNuSubIsotopeCov";
}

//______________________________________________________________________________
const char *TNuSubIsotopeCov::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSubIsotopeCov*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSubIsotopeCov::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSubIsotopeCov*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSubIsotopeCov::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSubIsotopeCov*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSubIsotopeCov::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSubIsotopeCov*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResonanceCov::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResonanceCov::Class_Name()
{
   return "TNuResonanceCov";
}

//______________________________________________________________________________
const char *TNuResonanceCov::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResonanceCov*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResonanceCov::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResonanceCov*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResonanceCov::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResonanceCov*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResonanceCov::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResonanceCov*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec05::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec05::Class_Name()
{
   return "TNuSec05";
}

//______________________________________________________________________________
const char *TNuSec05::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec05*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec05::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec05*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec05::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec05*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec05::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec05*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuESpectrum::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuESpectrum::Class_Name()
{
   return "TNuESpectrum";
}

//______________________________________________________________________________
const char *TNuESpectrum::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrum*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuESpectrum::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrum*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuESpectrum::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrum*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuESpectrum::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrum*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuESpectrumTabulated::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuESpectrumTabulated::Class_Name()
{
   return "TNuESpectrumTabulated";
}

//______________________________________________________________________________
const char *TNuESpectrumTabulated::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumTabulated*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuESpectrumTabulated::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumTabulated*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuESpectrumTabulated::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumTabulated*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuESpectrumTabulated::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumTabulated*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuESpectrumGeneralEvaporation::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuESpectrumGeneralEvaporation::Class_Name()
{
   return "TNuESpectrumGeneralEvaporation";
}

//______________________________________________________________________________
const char *TNuESpectrumGeneralEvaporation::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumGeneralEvaporation*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuESpectrumGeneralEvaporation::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumGeneralEvaporation*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuESpectrumGeneralEvaporation::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumGeneralEvaporation*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuESpectrumGeneralEvaporation::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumGeneralEvaporation*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuESpectrumMaxwellian::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuESpectrumMaxwellian::Class_Name()
{
   return "TNuESpectrumMaxwellian";
}

//______________________________________________________________________________
const char *TNuESpectrumMaxwellian::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumMaxwellian*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuESpectrumMaxwellian::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumMaxwellian*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuESpectrumMaxwellian::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumMaxwellian*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuESpectrumMaxwellian::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumMaxwellian*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuESpectrumEvaporation::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuESpectrumEvaporation::Class_Name()
{
   return "TNuESpectrumEvaporation";
}

//______________________________________________________________________________
const char *TNuESpectrumEvaporation::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumEvaporation*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuESpectrumEvaporation::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumEvaporation*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuESpectrumEvaporation::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumEvaporation*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuESpectrumEvaporation::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumEvaporation*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuESpectrumWatt::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuESpectrumWatt::Class_Name()
{
   return "TNuESpectrumWatt";
}

//______________________________________________________________________________
const char *TNuESpectrumWatt::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumWatt*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuESpectrumWatt::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumWatt*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuESpectrumWatt::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumWatt*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuESpectrumWatt::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumWatt*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuESpectrumMadlandNix::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuESpectrumMadlandNix::Class_Name()
{
   return "TNuESpectrumMadlandNix";
}

//______________________________________________________________________________
const char *TNuESpectrumMadlandNix::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumMadlandNix*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuESpectrumMadlandNix::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumMadlandNix*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuESpectrumMadlandNix::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumMadlandNix*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuESpectrumMadlandNix::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuESpectrumMadlandNix*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab2List1::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab2List1::Class_Name()
{
   return "TNuTab2List1";
}

//______________________________________________________________________________
const char *TNuTab2List1::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2List1*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab2List1::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2List1*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab2List1::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2List1*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab2List1::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab2List1*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec14::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec14::Class_Name()
{
   return "TNuSec14";
}

//______________________________________________________________________________
const char *TNuSec14::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec14*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec14::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec14*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec14::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec14*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec14::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec14*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec27::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec27::Class_Name()
{
   return "TNuSec27";
}

//______________________________________________________________________________
const char *TNuSec27::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec27*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec27::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec27*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec27::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec27*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec27::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec27*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec07002Incoherent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec07002Incoherent::Class_Name()
{
   return "TNuSec07002Incoherent";
}

//______________________________________________________________________________
const char *TNuSec07002Incoherent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002Incoherent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec07002Incoherent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002Incoherent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec07002Incoherent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002Incoherent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec07002Incoherent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec07002Incoherent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuDEpDMuETransfer::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuDEpDMuETransfer::Class_Name()
{
   return "TNuDEpDMuETransfer";
}

//______________________________________________________________________________
const char *TNuDEpDMuETransfer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuETransfer*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuDEpDMuETransfer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuETransfer*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuDEpDMuETransfer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuETransfer*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuDEpDMuETransfer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuDEpDMuETransfer*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec02::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec02::Class_Name()
{
   return "TNuSec02";
}

//______________________________________________________________________________
const char *TNuSec02::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec02*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec02::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec02*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec02::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec02*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec02::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec02*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSubIsotope::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSubIsotope::Class_Name()
{
   return "TNuSubIsotope";
}

//______________________________________________________________________________
const char *TNuSubIsotope::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSubIsotope*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSubIsotope::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSubIsotope*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSubIsotope::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSubIsotope*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSubIsotope::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSubIsotope*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoRMatrixLimited::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoRMatrixLimited::Class_Name()
{
   return "TNuResoRMatrixLimited";
}

//______________________________________________________________________________
const char *TNuResoRMatrixLimited::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoRMatrixLimited*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoRMatrixLimited::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoRMatrixLimited*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoRMatrixLimited::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoRMatrixLimited*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoRMatrixLimited::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoRMatrixLimited*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNudy::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNudy::Class_Name()
{
   return "TNudy";
}

//______________________________________________________________________________
const char *TNudy::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNudy*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNudy::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNudy*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNudy::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNudy*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNudy::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNudy*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoUnresolved::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoUnresolved::Class_Name()
{
   return "TNuResoUnresolved";
}

//______________________________________________________________________________
const char *TNuResoUnresolved::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolved*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoUnresolved::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolved*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoUnresolved::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolved*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoUnresolved::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolved*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoUnresolvedA::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoUnresolvedA::Class_Name()
{
   return "TNuResoUnresolvedA";
}

//______________________________________________________________________________
const char *TNuResoUnresolvedA::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedA*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoUnresolvedA::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedA*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoUnresolvedA::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedA*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoUnresolvedA::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedA*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoUnresolvedB::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoUnresolvedB::Class_Name()
{
   return "TNuResoUnresolvedB";
}

//______________________________________________________________________________
const char *TNuResoUnresolvedB::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedB*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoUnresolvedB::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedB*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoUnresolvedB::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedB*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoUnresolvedB::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedB*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoUnresolvedC::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoUnresolvedC::Class_Name()
{
   return "TNuResoUnresolvedC";
}

//______________________________________________________________________________
const char *TNuResoUnresolvedC::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedC*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoUnresolvedC::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedC*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoUnresolvedC::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedC*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoUnresolvedC::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoUnresolvedC*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuCanvasPrinter::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuCanvasPrinter::Class_Name()
{
   return "TNuCanvasPrinter";
}

//______________________________________________________________________________
const char *TNuCanvasPrinter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuCanvasPrinter*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuCanvasPrinter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuCanvasPrinter*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuCanvasPrinter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuCanvasPrinter*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuCanvasPrinter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuCanvasPrinter*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab1ListsSub::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab1ListsSub::Class_Name()
{
   return "TNuTab1ListsSub";
}

//______________________________________________________________________________
const char *TNuTab1ListsSub::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1ListsSub*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab1ListsSub::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1ListsSub*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab1ListsSub::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1ListsSub*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab1ListsSub::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab1ListsSub*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoAdlerAdler::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoAdlerAdler::Class_Name()
{
   return "TNuResoAdlerAdler";
}

//______________________________________________________________________________
const char *TNuResoAdlerAdler::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoAdlerAdler*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoAdlerAdler::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoAdlerAdler*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoAdlerAdler::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoAdlerAdler*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoAdlerAdler::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoAdlerAdler*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab3Tab2::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab3Tab2::Class_Name()
{
   return "TNuTab3Tab2";
}

//______________________________________________________________________________
const char *TNuTab3Tab2::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3Tab2*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab3Tab2::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3Tab2*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab3Tab2::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3Tab2*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab3Tab2::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3Tab2*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab3Tab1Lists::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab3Tab1Lists::Class_Name()
{
   return "TNuTab3Tab1Lists";
}

//______________________________________________________________________________
const char *TNuTab3Tab1Lists::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3Tab1Lists*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab3Tab1Lists::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3Tab1Lists*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab3Tab1Lists::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3Tab1Lists*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab3Tab1Lists::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3Tab1Lists*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuListFPY::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuListFPY::Class_Name()
{
   return "TNuListFPY";
}

//______________________________________________________________________________
const char *TNuListFPY::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListFPY*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuListFPY::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuListFPY*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuListFPY::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListFPY*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuListFPY::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuListFPY*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec26::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec26::Class_Name()
{
   return "TNuSec26";
}

//______________________________________________________________________________
const char *TNuSec26::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec26*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec26::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec26*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec26::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec26*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec26::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec26*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuList1Tab1::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuList1Tab1::Class_Name()
{
   return "TNuList1Tab1";
}

//______________________________________________________________________________
const char *TNuList1Tab1::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList1Tab1*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuList1Tab1::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList1Tab1*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuList1Tab1::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList1Tab1*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuList1Tab1::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList1Tab1*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec01460::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec01460::Class_Name()
{
   return "TNuSec01460";
}

//______________________________________________________________________________
const char *TNuSec01460::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01460*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec01460::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01460*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec01460::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01460*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec01460::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec01460*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoBrightWigner::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoBrightWigner::Class_Name()
{
   return "TNuResoBrightWigner";
}

//______________________________________________________________________________
const char *TNuResoBrightWigner::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoBrightWigner*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoBrightWigner::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoBrightWigner*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoBrightWigner::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoBrightWigner*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoBrightWigner::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoBrightWigner*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoSLBW::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoSLBW::Class_Name()
{
   return "TNuResoSLBW";
}

//______________________________________________________________________________
const char *TNuResoSLBW::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoSLBW*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoSLBW::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoSLBW*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoSLBW::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoSLBW*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoSLBW::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoSLBW*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuResoMLBW::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuResoMLBW::Class_Name()
{
   return "TNuResoMLBW";
}

//______________________________________________________________________________
const char *TNuResoMLBW::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoMLBW*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuResoMLBW::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuResoMLBW*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuResoMLBW::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoMLBW*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuResoMLBW::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuResoMLBW*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec08454::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec08454::Class_Name()
{
   return "TNuSec08454";
}

//______________________________________________________________________________
const char *TNuSec08454::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08454*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec08454::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08454*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec08454::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08454*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec08454::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec08454*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuList2Tab1::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuList2Tab1::Class_Name()
{
   return "TNuList2Tab1";
}

//______________________________________________________________________________
const char *TNuList2Tab1::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList2Tab1*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuList2Tab1::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuList2Tab1*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuList2Tab1::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList2Tab1*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuList2Tab1::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuList2Tab1*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuSec23::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuSec23::Class_Name()
{
   return "TNuSec23";
}

//______________________________________________________________________________
const char *TNuSec23::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec23*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuSec23::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuSec23*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuSec23::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec23*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuSec23::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuSec23*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNuTab3List2::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNuTab3List2::Class_Name()
{
   return "TNuTab3List2";
}

//______________________________________________________________________________
const char *TNuTab3List2::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3List2*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNuTab3List2::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3List2*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNuTab3List2::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3List2*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNuTab3List2::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNuTab3List2*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TNuLabel::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuLabel.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuLabel::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuLabel::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuLabel(void *p) {
      return  p ? new(p) ::TNuLabel : new ::TNuLabel;
   }
   static void *newArray_TNuLabel(Long_t nElements, void *p) {
      return p ? new(p) ::TNuLabel[nElements] : new ::TNuLabel[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuLabel(void *p) {
      delete ((::TNuLabel*)p);
   }
   static void deleteArray_TNuLabel(void *p) {
      delete [] ((::TNuLabel*)p);
   }
   static void destruct_TNuLabel(void *p) {
      typedef ::TNuLabel current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuLabel

//______________________________________________________________________________
void TNuObject::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuObject.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuObject::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuObject::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuObject(void *p) {
      return  p ? new(p) ::TNuObject : new ::TNuObject;
   }
   static void *newArray_TNuObject(Long_t nElements, void *p) {
      return p ? new(p) ::TNuObject[nElements] : new ::TNuObject[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuObject(void *p) {
      delete ((::TNuObject*)p);
   }
   static void deleteArray_TNuObject(void *p) {
      delete [] ((::TNuObject*)p);
   }
   static void destruct_TNuObject(void *p) {
      typedef ::TNuObject current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuObject

//______________________________________________________________________________
void TNuVF1::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuVF1.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuVF1::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuVF1::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuVF1(void *p) {
      delete ((::TNuVF1*)p);
   }
   static void deleteArray_TNuVF1(void *p) {
      delete [] ((::TNuVF1*)p);
   }
   static void destruct_TNuVF1(void *p) {
      typedef ::TNuVF1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuVF1

//______________________________________________________________________________
void TNuVF1s::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuVF1s.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuVF1s::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuVF1s::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuVF1s(void *p) {
      delete ((::TNuVF1s*)p);
   }
   static void deleteArray_TNuVF1s(void *p) {
      delete [] ((::TNuVF1s*)p);
   }
   static void destruct_TNuVF1s(void *p) {
      typedef ::TNuVF1s current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuVF1s

//______________________________________________________________________________
void TNuVResonance::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuVResonance.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuVResonance::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuVResonance::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuVResonance(void *p) {
      delete ((::TNuVResonance*)p);
   }
   static void deleteArray_TNuVResonance(void *p) {
      delete [] ((::TNuVResonance*)p);
   }
   static void destruct_TNuVResonance(void *p) {
      typedef ::TNuVResonance current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuVResonance

//______________________________________________________________________________
void TNuSaveToTextDlg::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSaveToTextDlg.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSaveToTextDlg::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSaveToTextDlg::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuSaveToTextDlg(void *p) {
      delete ((::TNuSaveToTextDlg*)p);
   }
   static void deleteArray_TNuSaveToTextDlg(void *p) {
      delete [] ((::TNuSaveToTextDlg*)p);
   }
   static void destruct_TNuSaveToTextDlg(void *p) {
      typedef ::TNuSaveToTextDlg current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSaveToTextDlg

//______________________________________________________________________________
void MyFileDlg::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyFileDlg.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyFileDlg::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyFileDlg::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_MyFileDlg(void *p) {
      delete ((::MyFileDlg*)p);
   }
   static void deleteArray_MyFileDlg(void *p) {
      delete [] ((::MyFileDlg*)p);
   }
   static void destruct_MyFileDlg(void *p) {
      typedef ::MyFileDlg current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyFileDlg

//______________________________________________________________________________
void TNuPrinter::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuPrinter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuPrinter::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuPrinter::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuPrinter(void *p) {
      delete ((::TNuPrinter*)p);
   }
   static void deleteArray_TNuPrinter(void *p) {
      delete [] ((::TNuPrinter*)p);
   }
   static void destruct_TNuPrinter(void *p) {
      typedef ::TNuPrinter current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuPrinter

//______________________________________________________________________________
void TNuCont::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuCont.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuCont::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuCont::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuCont(void *p) {
      return  p ? new(p) ::TNuCont : new ::TNuCont;
   }
   static void *newArray_TNuCont(Long_t nElements, void *p) {
      return p ? new(p) ::TNuCont[nElements] : new ::TNuCont[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuCont(void *p) {
      delete ((::TNuCont*)p);
   }
   static void deleteArray_TNuCont(void *p) {
      delete [] ((::TNuCont*)p);
   }
   static void destruct_TNuCont(void *p) {
      typedef ::TNuCont current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuCont

//______________________________________________________________________________
void TNuRecs::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuRecs.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuRecs::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuRecs::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuRecs(void *p) {
      return  p ? new(p) ::TNuRecs : new ::TNuRecs;
   }
   static void *newArray_TNuRecs(Long_t nElements, void *p) {
      return p ? new(p) ::TNuRecs[nElements] : new ::TNuRecs[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuRecs(void *p) {
      delete ((::TNuRecs*)p);
   }
   static void deleteArray_TNuRecs(void *p) {
      delete [] ((::TNuRecs*)p);
   }
   static void destruct_TNuRecs(void *p) {
      typedef ::TNuRecs current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuRecs

//______________________________________________________________________________
void TNuSection::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSection.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSection::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSection::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSection(void *p) {
      return  p ? new(p) ::TNuSection : new ::TNuSection;
   }
   static void *newArray_TNuSection(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSection[nElements] : new ::TNuSection[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSection(void *p) {
      delete ((::TNuSection*)p);
   }
   static void deleteArray_TNuSection(void *p) {
      delete [] ((::TNuSection*)p);
   }
   static void destruct_TNuSection(void *p) {
      typedef ::TNuSection current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSection

//______________________________________________________________________________
void TNuVTab::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuVTab.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuVTab::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuVTab::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuVTab(void *p) {
      delete ((::TNuVTab*)p);
   }
   static void deleteArray_TNuVTab(void *p) {
      delete [] ((::TNuVTab*)p);
   }
   static void destruct_TNuVTab(void *p) {
      typedef ::TNuVTab current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuVTab

//______________________________________________________________________________
void TNuEndfTAB2::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuEndfTAB2.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuEndfTAB2::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuEndfTAB2::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuEndfTAB2(void *p) {
      return  p ? new(p) ::TNuEndfTAB2 : new ::TNuEndfTAB2;
   }
   static void *newArray_TNuEndfTAB2(Long_t nElements, void *p) {
      return p ? new(p) ::TNuEndfTAB2[nElements] : new ::TNuEndfTAB2[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuEndfTAB2(void *p) {
      delete ((::TNuEndfTAB2*)p);
   }
   static void deleteArray_TNuEndfTAB2(void *p) {
      delete [] ((::TNuEndfTAB2*)p);
   }
   static void destruct_TNuEndfTAB2(void *p) {
      typedef ::TNuEndfTAB2 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuEndfTAB2

//______________________________________________________________________________
void TNuTab1::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab1.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab1::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab1::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuTab1(void *p) {
      return  p ? new(p) ::TNuTab1 : new ::TNuTab1;
   }
   static void *newArray_TNuTab1(Long_t nElements, void *p) {
      return p ? new(p) ::TNuTab1[nElements] : new ::TNuTab1[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuTab1(void *p) {
      delete ((::TNuTab1*)p);
   }
   static void deleteArray_TNuTab1(void *p) {
      delete [] ((::TNuTab1*)p);
   }
   static void destruct_TNuTab1(void *p) {
      typedef ::TNuTab1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab1

//______________________________________________________________________________
void TNuEndfIO::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuEndfIO.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuEndfIO::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuEndfIO::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuEndfIO(void *p) {
      delete ((::TNuEndfIO*)p);
   }
   static void deleteArray_TNuEndfIO(void *p) {
      delete [] ((::TNuEndfIO*)p);
   }
   static void destruct_TNuEndfIO(void *p) {
      typedef ::TNuEndfIO current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuEndfIO

//______________________________________________________________________________
void TNuSec13::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec13.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec13::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec13::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec13(void *p) {
      return  p ? new(p) ::TNuSec13 : new ::TNuSec13;
   }
   static void *newArray_TNuSec13(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec13[nElements] : new ::TNuSec13[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec13(void *p) {
      delete ((::TNuSec13*)p);
   }
   static void deleteArray_TNuSec13(void *p) {
      delete [] ((::TNuSec13*)p);
   }
   static void destruct_TNuSec13(void *p) {
      typedef ::TNuSec13 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec13

//______________________________________________________________________________
void TNuSec10::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec10.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec10::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec10::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec10(void *p) {
      return  p ? new(p) ::TNuSec10 : new ::TNuSec10;
   }
   static void *newArray_TNuSec10(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec10[nElements] : new ::TNuSec10[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec10(void *p) {
      delete ((::TNuSec10*)p);
   }
   static void deleteArray_TNuSec10(void *p) {
      delete [] ((::TNuSec10*)p);
   }
   static void destruct_TNuSec10(void *p) {
      typedef ::TNuSec10 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec10

//______________________________________________________________________________
void TNuSec09::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec09.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec09::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec09::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec09(void *p) {
      return  p ? new(p) ::TNuSec09 : new ::TNuSec09;
   }
   static void *newArray_TNuSec09(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec09[nElements] : new ::TNuSec09[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec09(void *p) {
      delete ((::TNuSec09*)p);
   }
   static void deleteArray_TNuSec09(void *p) {
      delete [] ((::TNuSec09*)p);
   }
   static void destruct_TNuSec09(void *p) {
      typedef ::TNuSec09 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec09

//______________________________________________________________________________
void TNuCollection::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuCollection.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuCollection::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuCollection::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuCollection(void *p) {
      delete ((::TNuCollection*)p);
   }
   static void deleteArray_TNuCollection(void *p) {
      delete [] ((::TNuCollection*)p);
   }
   static void destruct_TNuCollection(void *p) {
      typedef ::TNuCollection current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuCollection

//______________________________________________________________________________
void TNuIter::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuIter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuIter::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuIter::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuIter(void *p) {
      delete ((::TNuIter*)p);
   }
   static void deleteArray_TNuIter(void *p) {
      delete [] ((::TNuIter*)p);
   }
   static void destruct_TNuIter(void *p) {
      typedef ::TNuIter current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuIter

//______________________________________________________________________________
void TNuLazyCollection::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuLazyCollection.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuLazyCollection::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuLazyCollection::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuLazyCollection(void *p) {
      return  p ? new(p) ::TNuLazyCollection : new ::TNuLazyCollection;
   }
   static void *newArray_TNuLazyCollection(Long_t nElements, void *p) {
      return p ? new(p) ::TNuLazyCollection[nElements] : new ::TNuLazyCollection[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuLazyCollection(void *p) {
      delete ((::TNuLazyCollection*)p);
   }
   static void deleteArray_TNuLazyCollection(void *p) {
      delete [] ((::TNuLazyCollection*)p);
   }
   static void destruct_TNuLazyCollection(void *p) {
      typedef ::TNuLazyCollection current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuLazyCollection

//______________________________________________________________________________
void TNuFile::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuFile.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuFile::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuFile::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuFile(void *p) {
      return  p ? new(p) ::TNuFile : new ::TNuFile;
   }
   static void *newArray_TNuFile(Long_t nElements, void *p) {
      return p ? new(p) ::TNuFile[nElements] : new ::TNuFile[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuFile(void *p) {
      delete ((::TNuFile*)p);
   }
   static void deleteArray_TNuFile(void *p) {
      delete [] ((::TNuFile*)p);
   }
   static void destruct_TNuFile(void *p) {
      typedef ::TNuFile current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuFile

//______________________________________________________________________________
void TNuMat::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuMat.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuMat::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuMat::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuMat(void *p) {
      return  p ? new(p) ::TNuMat : new ::TNuMat;
   }
   static void *newArray_TNuMat(Long_t nElements, void *p) {
      return p ? new(p) ::TNuMat[nElements] : new ::TNuMat[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuMat(void *p) {
      delete ((::TNuMat*)p);
   }
   static void deleteArray_TNuMat(void *p) {
      delete [] ((::TNuMat*)p);
   }
   static void destruct_TNuMat(void *p) {
      typedef ::TNuMat current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuMat

//______________________________________________________________________________
void TNuSublib::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSublib.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSublib::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSublib::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSublib(void *p) {
      return  p ? new(p) ::TNuSublib : new ::TNuSublib;
   }
   static void *newArray_TNuSublib(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSublib[nElements] : new ::TNuSublib[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSublib(void *p) {
      delete ((::TNuSublib*)p);
   }
   static void deleteArray_TNuSublib(void *p) {
      delete [] ((::TNuSublib*)p);
   }
   static void destruct_TNuSublib(void *p) {
      typedef ::TNuSublib current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSublib

//______________________________________________________________________________
void TNuLib::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuLib.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuLib::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuLib::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuLib(void *p) {
      return  p ? new(p) ::TNuLib : new ::TNuLib;
   }
   static void *newArray_TNuLib(Long_t nElements, void *p) {
      return p ? new(p) ::TNuLib[nElements] : new ::TNuLib[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuLib(void *p) {
      delete ((::TNuLib*)p);
   }
   static void deleteArray_TNuLib(void *p) {
      delete [] ((::TNuLib*)p);
   }
   static void destruct_TNuLib(void *p) {
      typedef ::TNuLib current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuLib

//______________________________________________________________________________
void TNuIntg::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuIntg.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuIntg::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuIntg::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuIntg(void *p) {
      return  p ? new(p) ::TNuIntg : new ::TNuIntg;
   }
   static void *newArray_TNuIntg(Long_t nElements, void *p) {
      return p ? new(p) ::TNuIntg[nElements] : new ::TNuIntg[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuIntg(void *p) {
      delete ((::TNuIntg*)p);
   }
   static void deleteArray_TNuIntg(void *p) {
      delete [] ((::TNuIntg*)p);
   }
   static void destruct_TNuIntg(void *p) {
      typedef ::TNuIntg current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuIntg

//______________________________________________________________________________
void TNuRecsWithCont::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuRecsWithCont.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuRecsWithCont::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuRecsWithCont::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuRecsWithCont(void *p) {
      return  p ? new(p) ::TNuRecsWithCont : new ::TNuRecsWithCont;
   }
   static void *newArray_TNuRecsWithCont(Long_t nElements, void *p) {
      return p ? new(p) ::TNuRecsWithCont[nElements] : new ::TNuRecsWithCont[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuRecsWithCont(void *p) {
      delete ((::TNuRecsWithCont*)p);
   }
   static void deleteArray_TNuRecsWithCont(void *p) {
      delete [] ((::TNuRecsWithCont*)p);
   }
   static void destruct_TNuRecsWithCont(void *p) {
      typedef ::TNuRecsWithCont current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuRecsWithCont

//______________________________________________________________________________
void TNuList::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuList.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuList::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuList::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuList(void *p) {
      return  p ? new(p) ::TNuList : new ::TNuList;
   }
   static void *newArray_TNuList(Long_t nElements, void *p) {
      return p ? new(p) ::TNuList[nElements] : new ::TNuList[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuList(void *p) {
      delete ((::TNuList*)p);
   }
   static void deleteArray_TNuList(void *p) {
      delete [] ((::TNuList*)p);
   }
   static void destruct_TNuList(void *p) {
      typedef ::TNuList current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuList

//______________________________________________________________________________
void TNuContLists::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuContLists.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuContLists::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuContLists::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuContLists(void *p) {
      return  p ? new(p) ::TNuContLists : new ::TNuContLists;
   }
   static void *newArray_TNuContLists(Long_t nElements, void *p) {
      return p ? new(p) ::TNuContLists[nElements] : new ::TNuContLists[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuContLists(void *p) {
      delete ((::TNuContLists*)p);
   }
   static void deleteArray_TNuContLists(void *p) {
      delete [] ((::TNuContLists*)p);
   }
   static void destruct_TNuContLists(void *p) {
      typedef ::TNuContLists current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuContLists

//______________________________________________________________________________
void TNuVF2::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuVF2.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuVF2::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuVF2::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuVF2(void *p) {
      delete ((::TNuVF2*)p);
   }
   static void deleteArray_TNuVF2(void *p) {
      delete [] ((::TNuVF2*)p);
   }
   static void destruct_TNuVF2(void *p) {
      typedef ::TNuVF2 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuVF2

//______________________________________________________________________________
void TNuTab1Lists::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab1Lists.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab1Lists::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab1Lists::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuTab1Lists(void *p) {
      return  p ? new(p) ::TNuTab1Lists : new ::TNuTab1Lists;
   }
   static void *newArray_TNuTab1Lists(Long_t nElements, void *p) {
      return p ? new(p) ::TNuTab1Lists[nElements] : new ::TNuTab1Lists[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuTab1Lists(void *p) {
      delete ((::TNuTab1Lists*)p);
   }
   static void deleteArray_TNuTab1Lists(void *p) {
      delete [] ((::TNuTab1Lists*)p);
   }
   static void destruct_TNuTab1Lists(void *p) {
      typedef ::TNuTab1Lists current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab1Lists

//______________________________________________________________________________
void TNuList1::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuList1.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuList1::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuList1::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuList1(void *p) {
      delete ((::TNuList1*)p);
   }
   static void deleteArray_TNuList1(void *p) {
      delete [] ((::TNuList1*)p);
   }
   static void destruct_TNuList1(void *p) {
      typedef ::TNuList1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuList1

//______________________________________________________________________________
void TNuListTaylor::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuListTaylor.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuListTaylor::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuListTaylor::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuListTaylor(void *p) {
      return  p ? new(p) ::TNuListTaylor : new ::TNuListTaylor;
   }
   static void *newArray_TNuListTaylor(Long_t nElements, void *p) {
      return p ? new(p) ::TNuListTaylor[nElements] : new ::TNuListTaylor[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuListTaylor(void *p) {
      delete ((::TNuListTaylor*)p);
   }
   static void deleteArray_TNuListTaylor(void *p) {
      delete [] ((::TNuListTaylor*)p);
   }
   static void destruct_TNuListTaylor(void *p) {
      typedef ::TNuListTaylor current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuListTaylor

//______________________________________________________________________________
void TNuRecsWithTAB2::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuRecsWithTAB2.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuRecsWithTAB2::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuRecsWithTAB2::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuRecsWithTAB2(void *p) {
      return  p ? new(p) ::TNuRecsWithTAB2 : new ::TNuRecsWithTAB2;
   }
   static void *newArray_TNuRecsWithTAB2(Long_t nElements, void *p) {
      return p ? new(p) ::TNuRecsWithTAB2[nElements] : new ::TNuRecsWithTAB2[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuRecsWithTAB2(void *p) {
      delete ((::TNuRecsWithTAB2*)p);
   }
   static void deleteArray_TNuRecsWithTAB2(void *p) {
      delete [] ((::TNuRecsWithTAB2*)p);
   }
   static void destruct_TNuRecsWithTAB2(void *p) {
      typedef ::TNuRecsWithTAB2 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuRecsWithTAB2

//______________________________________________________________________________
void TNuTab2::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab2.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab2::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab2::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuTab2(void *p) {
      delete ((::TNuTab2*)p);
   }
   static void deleteArray_TNuTab2(void *p) {
      delete [] ((::TNuTab2*)p);
   }
   static void destruct_TNuTab2(void *p) {
      typedef ::TNuTab2 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab2

//______________________________________________________________________________
void TNuRecsWithTab1::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuRecsWithTab1.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuRecsWithTab1::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuRecsWithTab1::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuRecsWithTab1(void *p) {
      return  p ? new(p) ::TNuRecsWithTab1 : new ::TNuRecsWithTab1;
   }
   static void *newArray_TNuRecsWithTab1(Long_t nElements, void *p) {
      return p ? new(p) ::TNuRecsWithTab1[nElements] : new ::TNuRecsWithTab1[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuRecsWithTab1(void *p) {
      delete ((::TNuRecsWithTab1*)p);
   }
   static void deleteArray_TNuRecsWithTab1(void *p) {
      delete [] ((::TNuRecsWithTab1*)p);
   }
   static void destruct_TNuRecsWithTab1(void *p) {
      typedef ::TNuRecsWithTab1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuRecsWithTab1

//______________________________________________________________________________
void TNuSec15::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec15.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec15::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec15::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec15(void *p) {
      return  p ? new(p) ::TNuSec15 : new ::TNuSec15;
   }
   static void *newArray_TNuSec15(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec15[nElements] : new ::TNuSec15[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec15(void *p) {
      delete ((::TNuSec15*)p);
   }
   static void deleteArray_TNuSec15(void *p) {
      delete [] ((::TNuSec15*)p);
   }
   static void destruct_TNuSec15(void *p) {
      typedef ::TNuSec15 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec15

//______________________________________________________________________________
void TNuResonance::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResonance.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResonance::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResonance::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResonance(void *p) {
      return  p ? new(p) ::TNuResonance : new ::TNuResonance;
   }
   static void *newArray_TNuResonance(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResonance[nElements] : new ::TNuResonance[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResonance(void *p) {
      delete ((::TNuResonance*)p);
   }
   static void deleteArray_TNuResonance(void *p) {
      delete [] ((::TNuResonance*)p);
   }
   static void destruct_TNuResonance(void *p) {
      typedef ::TNuResonance current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResonance

//______________________________________________________________________________
void TNuResoResolved::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoResolved.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoResolved::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoResolved::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoResolved(void *p) {
      return  p ? new(p) ::TNuResoResolved : new ::TNuResoResolved;
   }
   static void *newArray_TNuResoResolved(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoResolved[nElements] : new ::TNuResoResolved[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoResolved(void *p) {
      delete ((::TNuResoResolved*)p);
   }
   static void deleteArray_TNuResoResolved(void *p) {
      delete [] ((::TNuResoResolved*)p);
   }
   static void destruct_TNuResoResolved(void *p) {
      typedef ::TNuResoResolved current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoResolved

//______________________________________________________________________________
void TNuSec04::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec04.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec04::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec04::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec04(void *p) {
      return  p ? new(p) ::TNuSec04 : new ::TNuSec04;
   }
   static void *newArray_TNuSec04(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec04[nElements] : new ::TNuSec04[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec04(void *p) {
      delete ((::TNuSec04*)p);
   }
   static void deleteArray_TNuSec04(void *p) {
      delete [] ((::TNuSec04*)p);
   }
   static void destruct_TNuSec04(void *p) {
      typedef ::TNuSec04 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec04

//______________________________________________________________________________
void TNuListLegendre::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuListLegendre.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuListLegendre::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuListLegendre::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuListLegendre(void *p) {
      return  p ? new(p) ::TNuListLegendre : new ::TNuListLegendre;
   }
   static void *newArray_TNuListLegendre(Long_t nElements, void *p) {
      return p ? new(p) ::TNuListLegendre[nElements] : new ::TNuListLegendre[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuListLegendre(void *p) {
      delete ((::TNuListLegendre*)p);
   }
   static void deleteArray_TNuListLegendre(void *p) {
      delete [] ((::TNuListLegendre*)p);
   }
   static void destruct_TNuListLegendre(void *p) {
      typedef ::TNuListLegendre current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuListLegendre

//______________________________________________________________________________
void TNuSec03::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec03.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec03::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec03::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec03(void *p) {
      return  p ? new(p) ::TNuSec03 : new ::TNuSec03;
   }
   static void *newArray_TNuSec03(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec03[nElements] : new ::TNuSec03[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec03(void *p) {
      delete ((::TNuSec03*)p);
   }
   static void deleteArray_TNuSec03(void *p) {
      delete [] ((::TNuSec03*)p);
   }
   static void destruct_TNuSec03(void *p) {
      typedef ::TNuSec03 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec03

//______________________________________________________________________________
void TNuVF3::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuVF3.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuVF3::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuVF3::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuVF3(void *p) {
      delete ((::TNuVF3*)p);
   }
   static void deleteArray_TNuVF3(void *p) {
      delete [] ((::TNuVF3*)p);
   }
   static void destruct_TNuVF3(void *p) {
      typedef ::TNuVF3 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuVF3

//______________________________________________________________________________
void TNuTab3::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab3.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab3::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab3::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuTab3(void *p) {
      delete ((::TNuTab3*)p);
   }
   static void deleteArray_TNuTab3(void *p) {
      delete [] ((::TNuTab3*)p);
   }
   static void destruct_TNuTab3(void *p) {
      typedef ::TNuTab3 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab3

//______________________________________________________________________________
void TNuSec06::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec06.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec06::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec06::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec06(void *p) {
      return  p ? new(p) ::TNuSec06 : new ::TNuSec06;
   }
   static void *newArray_TNuSec06(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec06[nElements] : new ::TNuSec06[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec06(void *p) {
      delete ((::TNuSec06*)p);
   }
   static void deleteArray_TNuSec06(void *p) {
      delete [] ((::TNuSec06*)p);
   }
   static void destruct_TNuSec06(void *p) {
      typedef ::TNuSec06 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec06

//______________________________________________________________________________
void TNuSec07002::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec07002.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec07002::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec07002::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec07002(void *p) {
      return  p ? new(p) ::TNuSec07002 : new ::TNuSec07002;
   }
   static void *newArray_TNuSec07002(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec07002[nElements] : new ::TNuSec07002[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec07002(void *p) {
      delete ((::TNuSec07002*)p);
   }
   static void deleteArray_TNuSec07002(void *p) {
      delete [] ((::TNuSec07002*)p);
   }
   static void destruct_TNuSec07002(void *p) {
      typedef ::TNuSec07002 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec07002

//______________________________________________________________________________
void TNuSec07002Coherent::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec07002Coherent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec07002Coherent::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec07002Coherent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec07002Coherent(void *p) {
      return  p ? new(p) ::TNuSec07002Coherent : new ::TNuSec07002Coherent;
   }
   static void *newArray_TNuSec07002Coherent(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec07002Coherent[nElements] : new ::TNuSec07002Coherent[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec07002Coherent(void *p) {
      delete ((::TNuSec07002Coherent*)p);
   }
   static void deleteArray_TNuSec07002Coherent(void *p) {
      delete [] ((::TNuSec07002Coherent*)p);
   }
   static void destruct_TNuSec07002Coherent(void *p) {
      typedef ::TNuSec07002Coherent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec07002Coherent

//______________________________________________________________________________
void TNuDescription::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDescription.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDescription::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDescription::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDescription(void *p) {
      return  p ? new(p) ::TNuDescription : new ::TNuDescription;
   }
   static void *newArray_TNuDescription(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDescription[nElements] : new ::TNuDescription[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDescription(void *p) {
      delete ((::TNuDescription*)p);
   }
   static void deleteArray_TNuDescription(void *p) {
      delete [] ((::TNuDescription*)p);
   }
   static void destruct_TNuDescription(void *p) {
      typedef ::TNuDescription current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDescription

//______________________________________________________________________________
void TNuDirs::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDirs.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDirs::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDirs::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDirs(void *p) {
      return  p ? new(p) ::TNuDirs : new ::TNuDirs;
   }
   static void *newArray_TNuDirs(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDirs[nElements] : new ::TNuDirs[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDirs(void *p) {
      delete ((::TNuDirs*)p);
   }
   static void deleteArray_TNuDirs(void *p) {
      delete [] ((::TNuDirs*)p);
   }
   static void destruct_TNuDirs(void *p) {
      typedef ::TNuDirs current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDirs

//______________________________________________________________________________
void TNuSec01458::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec01458.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec01458::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec01458::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec01458(void *p) {
      return  p ? new(p) ::TNuSec01458 : new ::TNuSec01458;
   }
   static void *newArray_TNuSec01458(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec01458[nElements] : new ::TNuSec01458[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec01458(void *p) {
      delete ((::TNuSec01458*)p);
   }
   static void deleteArray_TNuSec01458(void *p) {
      delete [] ((::TNuSec01458*)p);
   }
   static void destruct_TNuSec01458(void *p) {
      typedef ::TNuSec01458 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec01458

//______________________________________________________________________________
void TNuSec28::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec28.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec28::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec28::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec28(void *p) {
      return  p ? new(p) ::TNuSec28 : new ::TNuSec28;
   }
   static void *newArray_TNuSec28(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec28[nElements] : new ::TNuSec28[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec28(void *p) {
      delete ((::TNuSec28*)p);
   }
   static void deleteArray_TNuSec28(void *p) {
      delete [] ((::TNuSec28*)p);
   }
   static void destruct_TNuSec28(void *p) {
      typedef ::TNuSec28 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec28

//______________________________________________________________________________
void TNuDEpDMu::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMu.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMu::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMu::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMu(void *p) {
      return  p ? new(p) ::TNuDEpDMu : new ::TNuDEpDMu;
   }
   static void *newArray_TNuDEpDMu(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMu[nElements] : new ::TNuDEpDMu[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMu(void *p) {
      delete ((::TNuDEpDMu*)p);
   }
   static void deleteArray_TNuDEpDMu(void *p) {
      delete [] ((::TNuDEpDMu*)p);
   }
   static void destruct_TNuDEpDMu(void *p) {
      typedef ::TNuDEpDMu current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMu

//______________________________________________________________________________
void TNuDEpDMuF3::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMuF3.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMuF3::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMuF3::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMuF3(void *p) {
      return  p ? new(p) ::TNuDEpDMuF3 : new ::TNuDEpDMuF3;
   }
   static void *newArray_TNuDEpDMuF3(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMuF3[nElements] : new ::TNuDEpDMuF3[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMuF3(void *p) {
      delete ((::TNuDEpDMuF3*)p);
   }
   static void deleteArray_TNuDEpDMuF3(void *p) {
      delete [] ((::TNuDEpDMuF3*)p);
   }
   static void destruct_TNuDEpDMuF3(void *p) {
      typedef ::TNuDEpDMuF3 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMuF3

//______________________________________________________________________________
void TNuDEpDMuUnknwon::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMuUnknwon.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMuUnknwon::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMuUnknwon::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMuUnknwon(void *p) {
      return  p ? new(p) ::TNuDEpDMuUnknwon : new ::TNuDEpDMuUnknwon;
   }
   static void *newArray_TNuDEpDMuUnknwon(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMuUnknwon[nElements] : new ::TNuDEpDMuUnknwon[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMuUnknwon(void *p) {
      delete ((::TNuDEpDMuUnknwon*)p);
   }
   static void deleteArray_TNuDEpDMuUnknwon(void *p) {
      delete [] ((::TNuDEpDMuUnknwon*)p);
   }
   static void destruct_TNuDEpDMuUnknwon(void *p) {
      typedef ::TNuDEpDMuUnknwon current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMuUnknwon

//______________________________________________________________________________
void TNuDEpDMuContinuum::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMuContinuum.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMuContinuum::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMuContinuum::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMuContinuum(void *p) {
      return  p ? new(p) ::TNuDEpDMuContinuum : new ::TNuDEpDMuContinuum;
   }
   static void *newArray_TNuDEpDMuContinuum(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMuContinuum[nElements] : new ::TNuDEpDMuContinuum[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMuContinuum(void *p) {
      delete ((::TNuDEpDMuContinuum*)p);
   }
   static void deleteArray_TNuDEpDMuContinuum(void *p) {
      delete [] ((::TNuDEpDMuContinuum*)p);
   }
   static void destruct_TNuDEpDMuContinuum(void *p) {
      typedef ::TNuDEpDMuContinuum current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMuContinuum

//______________________________________________________________________________
void TNuDEpDMuNBodyPhaseSpace::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMuNBodyPhaseSpace.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMuNBodyPhaseSpace::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMuNBodyPhaseSpace::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMuNBodyPhaseSpace(void *p) {
      return  p ? new(p) ::TNuDEpDMuNBodyPhaseSpace : new ::TNuDEpDMuNBodyPhaseSpace;
   }
   static void *newArray_TNuDEpDMuNBodyPhaseSpace(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMuNBodyPhaseSpace[nElements] : new ::TNuDEpDMuNBodyPhaseSpace[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMuNBodyPhaseSpace(void *p) {
      delete ((::TNuDEpDMuNBodyPhaseSpace*)p);
   }
   static void deleteArray_TNuDEpDMuNBodyPhaseSpace(void *p) {
      delete [] ((::TNuDEpDMuNBodyPhaseSpace*)p);
   }
   static void destruct_TNuDEpDMuNBodyPhaseSpace(void *p) {
      typedef ::TNuDEpDMuNBodyPhaseSpace current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMuNBodyPhaseSpace

//______________________________________________________________________________
void TNuDEpDMuLaboratory::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMuLaboratory.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMuLaboratory::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMuLaboratory::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMuLaboratory(void *p) {
      return  p ? new(p) ::TNuDEpDMuLaboratory : new ::TNuDEpDMuLaboratory;
   }
   static void *newArray_TNuDEpDMuLaboratory(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMuLaboratory[nElements] : new ::TNuDEpDMuLaboratory[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMuLaboratory(void *p) {
      delete ((::TNuDEpDMuLaboratory*)p);
   }
   static void deleteArray_TNuDEpDMuLaboratory(void *p) {
      delete [] ((::TNuDEpDMuLaboratory*)p);
   }
   static void destruct_TNuDEpDMuLaboratory(void *p) {
      typedef ::TNuDEpDMuLaboratory current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMuLaboratory

//______________________________________________________________________________
void TNuDEpDMu2Body::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMu2Body.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMu2Body::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMu2Body::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuDEpDMu2Body(void *p) {
      delete ((::TNuDEpDMu2Body*)p);
   }
   static void deleteArray_TNuDEpDMu2Body(void *p) {
      delete [] ((::TNuDEpDMu2Body*)p);
   }
   static void destruct_TNuDEpDMu2Body(void *p) {
      typedef ::TNuDEpDMu2Body current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMu2Body

//______________________________________________________________________________
void TNuDEpDMu2BodyScattering::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMu2BodyScattering.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMu2BodyScattering::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMu2BodyScattering::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMu2BodyScattering(void *p) {
      return  p ? new(p) ::TNuDEpDMu2BodyScattering : new ::TNuDEpDMu2BodyScattering;
   }
   static void *newArray_TNuDEpDMu2BodyScattering(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMu2BodyScattering[nElements] : new ::TNuDEpDMu2BodyScattering[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMu2BodyScattering(void *p) {
      delete ((::TNuDEpDMu2BodyScattering*)p);
   }
   static void deleteArray_TNuDEpDMu2BodyScattering(void *p) {
      delete [] ((::TNuDEpDMu2BodyScattering*)p);
   }
   static void destruct_TNuDEpDMu2BodyScattering(void *p) {
      typedef ::TNuDEpDMu2BodyScattering current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMu2BodyScattering

//______________________________________________________________________________
void TNuDEpDMu2BodyIsotropic::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMu2BodyIsotropic.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMu2BodyIsotropic::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMu2BodyIsotropic::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMu2BodyIsotropic(void *p) {
      return  p ? new(p) ::TNuDEpDMu2BodyIsotropic : new ::TNuDEpDMu2BodyIsotropic;
   }
   static void *newArray_TNuDEpDMu2BodyIsotropic(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMu2BodyIsotropic[nElements] : new ::TNuDEpDMu2BodyIsotropic[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMu2BodyIsotropic(void *p) {
      delete ((::TNuDEpDMu2BodyIsotropic*)p);
   }
   static void deleteArray_TNuDEpDMu2BodyIsotropic(void *p) {
      delete [] ((::TNuDEpDMu2BodyIsotropic*)p);
   }
   static void destruct_TNuDEpDMu2BodyIsotropic(void *p) {
      typedef ::TNuDEpDMu2BodyIsotropic current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMu2BodyIsotropic

//______________________________________________________________________________
void TNuDEpDMu2BodyRecoil::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMu2BodyRecoil.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMu2BodyRecoil::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMu2BodyRecoil::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMu2BodyRecoil(void *p) {
      return  p ? new(p) ::TNuDEpDMu2BodyRecoil : new ::TNuDEpDMu2BodyRecoil;
   }
   static void *newArray_TNuDEpDMu2BodyRecoil(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMu2BodyRecoil[nElements] : new ::TNuDEpDMu2BodyRecoil[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMu2BodyRecoil(void *p) {
      delete ((::TNuDEpDMu2BodyRecoil*)p);
   }
   static void deleteArray_TNuDEpDMu2BodyRecoil(void *p) {
      delete [] ((::TNuDEpDMu2BodyRecoil*)p);
   }
   static void destruct_TNuDEpDMu2BodyRecoil(void *p) {
      typedef ::TNuDEpDMu2BodyRecoil current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMu2BodyRecoil

//______________________________________________________________________________
void TNuDEpDMu2BodyCoulomb::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMu2BodyCoulomb.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMu2BodyCoulomb::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMu2BodyCoulomb::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMu2BodyCoulomb(void *p) {
      return  p ? new(p) ::TNuDEpDMu2BodyCoulomb : new ::TNuDEpDMu2BodyCoulomb;
   }
   static void *newArray_TNuDEpDMu2BodyCoulomb(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMu2BodyCoulomb[nElements] : new ::TNuDEpDMu2BodyCoulomb[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMu2BodyCoulomb(void *p) {
      delete ((::TNuDEpDMu2BodyCoulomb*)p);
   }
   static void deleteArray_TNuDEpDMu2BodyCoulomb(void *p) {
      delete [] ((::TNuDEpDMu2BodyCoulomb*)p);
   }
   static void destruct_TNuDEpDMu2BodyCoulomb(void *p) {
      typedef ::TNuDEpDMu2BodyCoulomb current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMu2BodyCoulomb

//______________________________________________________________________________
void TNuSec12::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec12.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec12::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec12::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec12(void *p) {
      return  p ? new(p) ::TNuSec12 : new ::TNuSec12;
   }
   static void *newArray_TNuSec12(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec12[nElements] : new ::TNuSec12[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec12(void *p) {
      delete ((::TNuSec12*)p);
   }
   static void deleteArray_TNuSec12(void *p) {
      delete [] ((::TNuSec12*)p);
   }
   static void destruct_TNuSec12(void *p) {
      typedef ::TNuSec12 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec12

//______________________________________________________________________________
void TNuSec12Transitions::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec12Transitions.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec12Transitions::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec12Transitions::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec12Transitions(void *p) {
      return  p ? new(p) ::TNuSec12Transitions : new ::TNuSec12Transitions;
   }
   static void *newArray_TNuSec12Transitions(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec12Transitions[nElements] : new ::TNuSec12Transitions[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec12Transitions(void *p) {
      delete ((::TNuSec12Transitions*)p);
   }
   static void deleteArray_TNuSec12Transitions(void *p) {
      delete [] ((::TNuSec12Transitions*)p);
   }
   static void destruct_TNuSec12Transitions(void *p) {
      typedef ::TNuSec12Transitions current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec12Transitions

//______________________________________________________________________________
void TNuListCoulomb::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuListCoulomb.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuListCoulomb::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuListCoulomb::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuListCoulomb(void *p) {
      return  p ? new(p) ::TNuListCoulomb : new ::TNuListCoulomb;
   }
   static void *newArray_TNuListCoulomb(Long_t nElements, void *p) {
      return p ? new(p) ::TNuListCoulomb[nElements] : new ::TNuListCoulomb[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuListCoulomb(void *p) {
      delete ((::TNuListCoulomb*)p);
   }
   static void deleteArray_TNuListCoulomb(void *p) {
      delete [] ((::TNuListCoulomb*)p);
   }
   static void destruct_TNuListCoulomb(void *p) {
      typedef ::TNuListCoulomb current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuListCoulomb

//______________________________________________________________________________
void TNuResoReichMoore::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoReichMoore.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoReichMoore::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoReichMoore::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoReichMoore(void *p) {
      return  p ? new(p) ::TNuResoReichMoore : new ::TNuResoReichMoore;
   }
   static void *newArray_TNuResoReichMoore(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoReichMoore[nElements] : new ::TNuResoReichMoore[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoReichMoore(void *p) {
      delete ((::TNuResoReichMoore*)p);
   }
   static void deleteArray_TNuResoReichMoore(void *p) {
      delete [] ((::TNuResoReichMoore*)p);
   }
   static void destruct_TNuResoReichMoore(void *p) {
      typedef ::TNuResoReichMoore current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoReichMoore

//______________________________________________________________________________
void TNuSec07004::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec07004.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec07004::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec07004::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec07004(void *p) {
      return  p ? new(p) ::TNuSec07004 : new ::TNuSec07004;
   }
   static void *newArray_TNuSec07004(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec07004[nElements] : new ::TNuSec07004[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec07004(void *p) {
      delete ((::TNuSec07004*)p);
   }
   static void deleteArray_TNuSec07004(void *p) {
      delete [] ((::TNuSec07004*)p);
   }
   static void destruct_TNuSec07004(void *p) {
      typedef ::TNuSec07004 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec07004

//______________________________________________________________________________
void TNuSec01451::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec01451.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec01451::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec01451::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec01451(void *p) {
      return  p ? new(p) ::TNuSec01451 : new ::TNuSec01451;
   }
   static void *newArray_TNuSec01451(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec01451[nElements] : new ::TNuSec01451[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec01451(void *p) {
      delete ((::TNuSec01451*)p);
   }
   static void deleteArray_TNuSec01451(void *p) {
      delete [] ((::TNuSec01451*)p);
   }
   static void destruct_TNuSec01451(void *p) {
      typedef ::TNuSec01451 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec01451

//______________________________________________________________________________
void TNuSec08::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec08.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec08::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec08::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec08(void *p) {
      return  p ? new(p) ::TNuSec08 : new ::TNuSec08;
   }
   static void *newArray_TNuSec08(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec08[nElements] : new ::TNuSec08[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec08(void *p) {
      delete ((::TNuSec08*)p);
   }
   static void deleteArray_TNuSec08(void *p) {
      delete [] ((::TNuSec08*)p);
   }
   static void destruct_TNuSec08(void *p) {
      typedef ::TNuSec08 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec08

//______________________________________________________________________________
void TNuList2::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuList2.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuList2::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuList2::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuList2(void *p) {
      delete ((::TNuList2*)p);
   }
   static void deleteArray_TNuList2(void *p) {
      delete [] ((::TNuList2*)p);
   }
   static void destruct_TNuList2(void *p) {
      typedef ::TNuList2 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuList2

//______________________________________________________________________________
void TNuList2KalbachMann::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuList2KalbachMann.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuList2KalbachMann::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuList2KalbachMann::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuList2KalbachMann(void *p) {
      return  p ? new(p) ::TNuList2KalbachMann : new ::TNuList2KalbachMann;
   }
   static void *newArray_TNuList2KalbachMann(Long_t nElements, void *p) {
      return p ? new(p) ::TNuList2KalbachMann[nElements] : new ::TNuList2KalbachMann[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuList2KalbachMann(void *p) {
      delete ((::TNuList2KalbachMann*)p);
   }
   static void deleteArray_TNuList2KalbachMann(void *p) {
      delete [] ((::TNuList2KalbachMann*)p);
   }
   static void destruct_TNuList2KalbachMann(void *p) {
      typedef ::TNuList2KalbachMann current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuList2KalbachMann

//______________________________________________________________________________
void TNuSec01::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec01.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec01::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec01::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec01(void *p) {
      return  p ? new(p) ::TNuSec01 : new ::TNuSec01;
   }
   static void *newArray_TNuSec01(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec01[nElements] : new ::TNuSec01[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec01(void *p) {
      delete ((::TNuSec01*)p);
   }
   static void deleteArray_TNuSec01(void *p) {
      delete [] ((::TNuSec01*)p);
   }
   static void destruct_TNuSec01(void *p) {
      typedef ::TNuSec01 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec01

//______________________________________________________________________________
void TNuSec12Yields::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec12Yields.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec12Yields::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec12Yields::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec12Yields(void *p) {
      return  p ? new(p) ::TNuSec12Yields : new ::TNuSec12Yields;
   }
   static void *newArray_TNuSec12Yields(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec12Yields[nElements] : new ::TNuSec12Yields[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec12Yields(void *p) {
      delete ((::TNuSec12Yields*)p);
   }
   static void deleteArray_TNuSec12Yields(void *p) {
      delete [] ((::TNuSec12Yields*)p);
   }
   static void destruct_TNuSec12Yields(void *p) {
      typedef ::TNuSec12Yields current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec12Yields

//______________________________________________________________________________
void TNuContList::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuContList.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuContList::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuContList::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuContList(void *p) {
      return  p ? new(p) ::TNuContList : new ::TNuContList;
   }
   static void *newArray_TNuContList(Long_t nElements, void *p) {
      return p ? new(p) ::TNuContList[nElements] : new ::TNuContList[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuContList(void *p) {
      delete ((::TNuContList*)p);
   }
   static void deleteArray_TNuContList(void *p) {
      delete [] ((::TNuContList*)p);
   }
   static void destruct_TNuContList(void *p) {
      typedef ::TNuContList current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuContList

//______________________________________________________________________________
void TNuSec08457::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec08457.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec08457::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec08457::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec08457(void *p) {
      return  p ? new(p) ::TNuSec08457 : new ::TNuSec08457;
   }
   static void *newArray_TNuSec08457(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec08457[nElements] : new ::TNuSec08457[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec08457(void *p) {
      delete ((::TNuSec08457*)p);
   }
   static void deleteArray_TNuSec08457(void *p) {
      delete [] ((::TNuSec08457*)p);
   }
   static void destruct_TNuSec08457(void *p) {
      typedef ::TNuSec08457 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec08457

//______________________________________________________________________________
void TNuSFYSub::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSFYSub.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSFYSub::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSFYSub::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSFYSub(void *p) {
      return  p ? new(p) ::TNuSFYSub : new ::TNuSFYSub;
   }
   static void *newArray_TNuSFYSub(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSFYSub[nElements] : new ::TNuSFYSub[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSFYSub(void *p) {
      delete ((::TNuSFYSub*)p);
   }
   static void deleteArray_TNuSFYSub(void *p) {
      delete [] ((::TNuSFYSub*)p);
   }
   static void destruct_TNuSFYSub(void *p) {
      typedef ::TNuSFYSub current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSFYSub

//______________________________________________________________________________
void TNuList2Legendre::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuList2Legendre.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuList2Legendre::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuList2Legendre::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuList2Legendre(void *p) {
      return  p ? new(p) ::TNuList2Legendre : new ::TNuList2Legendre;
   }
   static void *newArray_TNuList2Legendre(Long_t nElements, void *p) {
      return p ? new(p) ::TNuList2Legendre[nElements] : new ::TNuList2Legendre[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuList2Legendre(void *p) {
      delete ((::TNuList2Legendre*)p);
   }
   static void deleteArray_TNuList2Legendre(void *p) {
      delete [] ((::TNuList2Legendre*)p);
   }
   static void destruct_TNuList2Legendre(void *p) {
      typedef ::TNuList2Legendre current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuList2Legendre

//______________________________________________________________________________
void TNuTab2Tab1::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab2Tab1.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab2Tab1::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab2Tab1::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuTab2Tab1(void *p) {
      return  p ? new(p) ::TNuTab2Tab1 : new ::TNuTab2Tab1;
   }
   static void *newArray_TNuTab2Tab1(Long_t nElements, void *p) {
      return p ? new(p) ::TNuTab2Tab1[nElements] : new ::TNuTab2Tab1[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuTab2Tab1(void *p) {
      delete ((::TNuTab2Tab1*)p);
   }
   static void deleteArray_TNuTab2Tab1(void *p) {
      delete [] ((::TNuTab2Tab1*)p);
   }
   static void destruct_TNuTab2Tab1(void *p) {
      typedef ::TNuTab2Tab1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab2Tab1

//______________________________________________________________________________
void TNuContListNC::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuContListNC.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuContListNC::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuContListNC::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuContListNC(void *p) {
      return  p ? new(p) ::TNuContListNC : new ::TNuContListNC;
   }
   static void *newArray_TNuContListNC(Long_t nElements, void *p) {
      return p ? new(p) ::TNuContListNC[nElements] : new ::TNuContListNC[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuContListNC(void *p) {
      delete ((::TNuContListNC*)p);
   }
   static void deleteArray_TNuContListNC(void *p) {
      delete [] ((::TNuContListNC*)p);
   }
   static void destruct_TNuContListNC(void *p) {
      typedef ::TNuContListNC current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuContListNC

//______________________________________________________________________________
void TNuListNI::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuListNI.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuListNI::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuListNI::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuListNI(void *p) {
      return  p ? new(p) ::TNuListNI : new ::TNuListNI;
   }
   static void *newArray_TNuListNI(Long_t nElements, void *p) {
      return p ? new(p) ::TNuListNI[nElements] : new ::TNuListNI[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuListNI(void *p) {
      delete ((::TNuListNI*)p);
   }
   static void deleteArray_TNuListNI(void *p) {
      delete [] ((::TNuListNI*)p);
   }
   static void destruct_TNuListNI(void *p) {
      typedef ::TNuListNI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuListNI

//______________________________________________________________________________
void TNuContListsCov33::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuContListsCov33.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuContListsCov33::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuContListsCov33::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuContListsCov33(void *p) {
      return  p ? new(p) ::TNuContListsCov33 : new ::TNuContListsCov33;
   }
   static void *newArray_TNuContListsCov33(Long_t nElements, void *p) {
      return p ? new(p) ::TNuContListsCov33[nElements] : new ::TNuContListsCov33[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuContListsCov33(void *p) {
      delete ((::TNuContListsCov33*)p);
   }
   static void deleteArray_TNuContListsCov33(void *p) {
      delete [] ((::TNuContListsCov33*)p);
   }
   static void destruct_TNuContListsCov33(void *p) {
      typedef ::TNuContListsCov33 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuContListsCov33

//______________________________________________________________________________
void TNuCovMatrix::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuCovMatrix.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuCovMatrix::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuCovMatrix::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuCovMatrix(void *p) {
      return  p ? new(p) ::TNuCovMatrix : new ::TNuCovMatrix;
   }
   static void *newArray_TNuCovMatrix(Long_t nElements, void *p) {
      return p ? new(p) ::TNuCovMatrix[nElements] : new ::TNuCovMatrix[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuCovMatrix(void *p) {
      delete ((::TNuCovMatrix*)p);
   }
   static void deleteArray_TNuCovMatrix(void *p) {
      delete [] ((::TNuCovMatrix*)p);
   }
   static void destruct_TNuCovMatrix(void *p) {
      typedef ::TNuCovMatrix current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuCovMatrix

//______________________________________________________________________________
void TNuSec31::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec31.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec31::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec31::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec31(void *p) {
      return  p ? new(p) ::TNuSec31 : new ::TNuSec31;
   }
   static void *newArray_TNuSec31(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec31[nElements] : new ::TNuSec31[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec31(void *p) {
      delete ((::TNuSec31*)p);
   }
   static void deleteArray_TNuSec31(void *p) {
      delete [] ((::TNuSec31*)p);
   }
   static void destruct_TNuSec31(void *p) {
      typedef ::TNuSec31 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec31

//______________________________________________________________________________
void TNuSec33::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec33.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec33::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec33::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec33(void *p) {
      return  p ? new(p) ::TNuSec33 : new ::TNuSec33;
   }
   static void *newArray_TNuSec33(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec33[nElements] : new ::TNuSec33[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec33(void *p) {
      delete ((::TNuSec33*)p);
   }
   static void deleteArray_TNuSec33(void *p) {
      delete [] ((::TNuSec33*)p);
   }
   static void destruct_TNuSec33(void *p) {
      typedef ::TNuSec33 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec33

//______________________________________________________________________________
void TNuContListsCov34::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuContListsCov34.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuContListsCov34::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuContListsCov34::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuContListsCov34(void *p) {
      return  p ? new(p) ::TNuContListsCov34 : new ::TNuContListsCov34;
   }
   static void *newArray_TNuContListsCov34(Long_t nElements, void *p) {
      return p ? new(p) ::TNuContListsCov34[nElements] : new ::TNuContListsCov34[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuContListsCov34(void *p) {
      delete ((::TNuContListsCov34*)p);
   }
   static void deleteArray_TNuContListsCov34(void *p) {
      delete [] ((::TNuContListsCov34*)p);
   }
   static void destruct_TNuContListsCov34(void *p) {
      typedef ::TNuContListsCov34 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuContListsCov34

//______________________________________________________________________________
void TNuSubSec34::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSubSec34.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSubSec34::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSubSec34::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSubSec34(void *p) {
      return  p ? new(p) ::TNuSubSec34 : new ::TNuSubSec34;
   }
   static void *newArray_TNuSubSec34(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSubSec34[nElements] : new ::TNuSubSec34[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSubSec34(void *p) {
      delete ((::TNuSubSec34*)p);
   }
   static void deleteArray_TNuSubSec34(void *p) {
      delete [] ((::TNuSubSec34*)p);
   }
   static void destruct_TNuSubSec34(void *p) {
      typedef ::TNuSubSec34 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSubSec34

//______________________________________________________________________________
void TNuSec34::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec34.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec34::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec34::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec34(void *p) {
      return  p ? new(p) ::TNuSec34 : new ::TNuSec34;
   }
   static void *newArray_TNuSec34(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec34[nElements] : new ::TNuSec34[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec34(void *p) {
      delete ((::TNuSec34*)p);
   }
   static void deleteArray_TNuSec34(void *p) {
      delete [] ((::TNuSec34*)p);
   }
   static void destruct_TNuSec34(void *p) {
      typedef ::TNuSec34 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec34

//______________________________________________________________________________
void TNuSec35::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec35.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec35::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec35::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec35(void *p) {
      return  p ? new(p) ::TNuSec35 : new ::TNuSec35;
   }
   static void *newArray_TNuSec35(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec35[nElements] : new ::TNuSec35[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec35(void *p) {
      delete ((::TNuSec35*)p);
   }
   static void deleteArray_TNuSec35(void *p) {
      delete [] ((::TNuSec35*)p);
   }
   static void destruct_TNuSec35(void *p) {
      typedef ::TNuSec35 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec35

//______________________________________________________________________________
void TNuSec40::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec40.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec40::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec40::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec40(void *p) {
      return  p ? new(p) ::TNuSec40 : new ::TNuSec40;
   }
   static void *newArray_TNuSec40(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec40[nElements] : new ::TNuSec40[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec40(void *p) {
      delete ((::TNuSec40*)p);
   }
   static void deleteArray_TNuSec40(void *p) {
      delete [] ((::TNuSec40*)p);
   }
   static void destruct_TNuSec40(void *p) {
      typedef ::TNuSec40 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec40

//______________________________________________________________________________
void TNuSec32::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec32.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec32::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec32::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec32(void *p) {
      return  p ? new(p) ::TNuSec32 : new ::TNuSec32;
   }
   static void *newArray_TNuSec32(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec32[nElements] : new ::TNuSec32[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec32(void *p) {
      delete ((::TNuSec32*)p);
   }
   static void deleteArray_TNuSec32(void *p) {
      delete [] ((::TNuSec32*)p);
   }
   static void destruct_TNuSec32(void *p) {
      typedef ::TNuSec32 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec32

//______________________________________________________________________________
void TNuSubIsotopeCov::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSubIsotopeCov.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSubIsotopeCov::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSubIsotopeCov::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSubIsotopeCov(void *p) {
      return  p ? new(p) ::TNuSubIsotopeCov : new ::TNuSubIsotopeCov;
   }
   static void *newArray_TNuSubIsotopeCov(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSubIsotopeCov[nElements] : new ::TNuSubIsotopeCov[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSubIsotopeCov(void *p) {
      delete ((::TNuSubIsotopeCov*)p);
   }
   static void deleteArray_TNuSubIsotopeCov(void *p) {
      delete [] ((::TNuSubIsotopeCov*)p);
   }
   static void destruct_TNuSubIsotopeCov(void *p) {
      typedef ::TNuSubIsotopeCov current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSubIsotopeCov

//______________________________________________________________________________
void TNuResonanceCov::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResonanceCov.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResonanceCov::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResonanceCov::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResonanceCov(void *p) {
      return  p ? new(p) ::TNuResonanceCov : new ::TNuResonanceCov;
   }
   static void *newArray_TNuResonanceCov(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResonanceCov[nElements] : new ::TNuResonanceCov[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResonanceCov(void *p) {
      delete ((::TNuResonanceCov*)p);
   }
   static void deleteArray_TNuResonanceCov(void *p) {
      delete [] ((::TNuResonanceCov*)p);
   }
   static void destruct_TNuResonanceCov(void *p) {
      typedef ::TNuResonanceCov current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResonanceCov

//______________________________________________________________________________
void TNuSec05::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec05.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec05::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec05::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec05(void *p) {
      return  p ? new(p) ::TNuSec05 : new ::TNuSec05;
   }
   static void *newArray_TNuSec05(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec05[nElements] : new ::TNuSec05[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec05(void *p) {
      delete ((::TNuSec05*)p);
   }
   static void deleteArray_TNuSec05(void *p) {
      delete [] ((::TNuSec05*)p);
   }
   static void destruct_TNuSec05(void *p) {
      typedef ::TNuSec05 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec05

//______________________________________________________________________________
void TNuESpectrum::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuESpectrum.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuESpectrum::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuESpectrum::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuESpectrum(void *p) {
      delete ((::TNuESpectrum*)p);
   }
   static void deleteArray_TNuESpectrum(void *p) {
      delete [] ((::TNuESpectrum*)p);
   }
   static void destruct_TNuESpectrum(void *p) {
      typedef ::TNuESpectrum current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuESpectrum

//______________________________________________________________________________
void TNuESpectrumTabulated::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuESpectrumTabulated.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuESpectrumTabulated::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuESpectrumTabulated::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuESpectrumTabulated(void *p) {
      return  p ? new(p) ::TNuESpectrumTabulated : new ::TNuESpectrumTabulated;
   }
   static void *newArray_TNuESpectrumTabulated(Long_t nElements, void *p) {
      return p ? new(p) ::TNuESpectrumTabulated[nElements] : new ::TNuESpectrumTabulated[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuESpectrumTabulated(void *p) {
      delete ((::TNuESpectrumTabulated*)p);
   }
   static void deleteArray_TNuESpectrumTabulated(void *p) {
      delete [] ((::TNuESpectrumTabulated*)p);
   }
   static void destruct_TNuESpectrumTabulated(void *p) {
      typedef ::TNuESpectrumTabulated current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuESpectrumTabulated

//______________________________________________________________________________
void TNuESpectrumGeneralEvaporation::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuESpectrumGeneralEvaporation.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuESpectrumGeneralEvaporation::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuESpectrumGeneralEvaporation::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuESpectrumGeneralEvaporation(void *p) {
      return  p ? new(p) ::TNuESpectrumGeneralEvaporation : new ::TNuESpectrumGeneralEvaporation;
   }
   static void *newArray_TNuESpectrumGeneralEvaporation(Long_t nElements, void *p) {
      return p ? new(p) ::TNuESpectrumGeneralEvaporation[nElements] : new ::TNuESpectrumGeneralEvaporation[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuESpectrumGeneralEvaporation(void *p) {
      delete ((::TNuESpectrumGeneralEvaporation*)p);
   }
   static void deleteArray_TNuESpectrumGeneralEvaporation(void *p) {
      delete [] ((::TNuESpectrumGeneralEvaporation*)p);
   }
   static void destruct_TNuESpectrumGeneralEvaporation(void *p) {
      typedef ::TNuESpectrumGeneralEvaporation current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuESpectrumGeneralEvaporation

//______________________________________________________________________________
void TNuESpectrumMaxwellian::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuESpectrumMaxwellian.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuESpectrumMaxwellian::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuESpectrumMaxwellian::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuESpectrumMaxwellian(void *p) {
      return  p ? new(p) ::TNuESpectrumMaxwellian : new ::TNuESpectrumMaxwellian;
   }
   static void *newArray_TNuESpectrumMaxwellian(Long_t nElements, void *p) {
      return p ? new(p) ::TNuESpectrumMaxwellian[nElements] : new ::TNuESpectrumMaxwellian[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuESpectrumMaxwellian(void *p) {
      delete ((::TNuESpectrumMaxwellian*)p);
   }
   static void deleteArray_TNuESpectrumMaxwellian(void *p) {
      delete [] ((::TNuESpectrumMaxwellian*)p);
   }
   static void destruct_TNuESpectrumMaxwellian(void *p) {
      typedef ::TNuESpectrumMaxwellian current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuESpectrumMaxwellian

//______________________________________________________________________________
void TNuESpectrumEvaporation::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuESpectrumEvaporation.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuESpectrumEvaporation::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuESpectrumEvaporation::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuESpectrumEvaporation(void *p) {
      return  p ? new(p) ::TNuESpectrumEvaporation : new ::TNuESpectrumEvaporation;
   }
   static void *newArray_TNuESpectrumEvaporation(Long_t nElements, void *p) {
      return p ? new(p) ::TNuESpectrumEvaporation[nElements] : new ::TNuESpectrumEvaporation[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuESpectrumEvaporation(void *p) {
      delete ((::TNuESpectrumEvaporation*)p);
   }
   static void deleteArray_TNuESpectrumEvaporation(void *p) {
      delete [] ((::TNuESpectrumEvaporation*)p);
   }
   static void destruct_TNuESpectrumEvaporation(void *p) {
      typedef ::TNuESpectrumEvaporation current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuESpectrumEvaporation

//______________________________________________________________________________
void TNuESpectrumWatt::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuESpectrumWatt.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuESpectrumWatt::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuESpectrumWatt::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuESpectrumWatt(void *p) {
      return  p ? new(p) ::TNuESpectrumWatt : new ::TNuESpectrumWatt;
   }
   static void *newArray_TNuESpectrumWatt(Long_t nElements, void *p) {
      return p ? new(p) ::TNuESpectrumWatt[nElements] : new ::TNuESpectrumWatt[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuESpectrumWatt(void *p) {
      delete ((::TNuESpectrumWatt*)p);
   }
   static void deleteArray_TNuESpectrumWatt(void *p) {
      delete [] ((::TNuESpectrumWatt*)p);
   }
   static void destruct_TNuESpectrumWatt(void *p) {
      typedef ::TNuESpectrumWatt current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuESpectrumWatt

//______________________________________________________________________________
void TNuESpectrumMadlandNix::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuESpectrumMadlandNix.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuESpectrumMadlandNix::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuESpectrumMadlandNix::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuESpectrumMadlandNix(void *p) {
      return  p ? new(p) ::TNuESpectrumMadlandNix : new ::TNuESpectrumMadlandNix;
   }
   static void *newArray_TNuESpectrumMadlandNix(Long_t nElements, void *p) {
      return p ? new(p) ::TNuESpectrumMadlandNix[nElements] : new ::TNuESpectrumMadlandNix[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuESpectrumMadlandNix(void *p) {
      delete ((::TNuESpectrumMadlandNix*)p);
   }
   static void deleteArray_TNuESpectrumMadlandNix(void *p) {
      delete [] ((::TNuESpectrumMadlandNix*)p);
   }
   static void destruct_TNuESpectrumMadlandNix(void *p) {
      typedef ::TNuESpectrumMadlandNix current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuESpectrumMadlandNix

//______________________________________________________________________________
void TNuTab2List1::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab2List1.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab2List1::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab2List1::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuTab2List1(void *p) {
      return  p ? new(p) ::TNuTab2List1 : new ::TNuTab2List1;
   }
   static void *newArray_TNuTab2List1(Long_t nElements, void *p) {
      return p ? new(p) ::TNuTab2List1[nElements] : new ::TNuTab2List1[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuTab2List1(void *p) {
      delete ((::TNuTab2List1*)p);
   }
   static void deleteArray_TNuTab2List1(void *p) {
      delete [] ((::TNuTab2List1*)p);
   }
   static void destruct_TNuTab2List1(void *p) {
      typedef ::TNuTab2List1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab2List1

//______________________________________________________________________________
void TNuSec14::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec14.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec14::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec14::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec14(void *p) {
      return  p ? new(p) ::TNuSec14 : new ::TNuSec14;
   }
   static void *newArray_TNuSec14(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec14[nElements] : new ::TNuSec14[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec14(void *p) {
      delete ((::TNuSec14*)p);
   }
   static void deleteArray_TNuSec14(void *p) {
      delete [] ((::TNuSec14*)p);
   }
   static void destruct_TNuSec14(void *p) {
      typedef ::TNuSec14 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec14

//______________________________________________________________________________
void TNuSec27::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec27.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec27::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec27::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec27(void *p) {
      return  p ? new(p) ::TNuSec27 : new ::TNuSec27;
   }
   static void *newArray_TNuSec27(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec27[nElements] : new ::TNuSec27[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec27(void *p) {
      delete ((::TNuSec27*)p);
   }
   static void deleteArray_TNuSec27(void *p) {
      delete [] ((::TNuSec27*)p);
   }
   static void destruct_TNuSec27(void *p) {
      typedef ::TNuSec27 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec27

//______________________________________________________________________________
void TNuSec07002Incoherent::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec07002Incoherent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec07002Incoherent::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec07002Incoherent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec07002Incoherent(void *p) {
      return  p ? new(p) ::TNuSec07002Incoherent : new ::TNuSec07002Incoherent;
   }
   static void *newArray_TNuSec07002Incoherent(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec07002Incoherent[nElements] : new ::TNuSec07002Incoherent[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec07002Incoherent(void *p) {
      delete ((::TNuSec07002Incoherent*)p);
   }
   static void deleteArray_TNuSec07002Incoherent(void *p) {
      delete [] ((::TNuSec07002Incoherent*)p);
   }
   static void destruct_TNuSec07002Incoherent(void *p) {
      typedef ::TNuSec07002Incoherent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec07002Incoherent

//______________________________________________________________________________
void TNuDEpDMuETransfer::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuDEpDMuETransfer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuDEpDMuETransfer::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuDEpDMuETransfer::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuDEpDMuETransfer(void *p) {
      return  p ? new(p) ::TNuDEpDMuETransfer : new ::TNuDEpDMuETransfer;
   }
   static void *newArray_TNuDEpDMuETransfer(Long_t nElements, void *p) {
      return p ? new(p) ::TNuDEpDMuETransfer[nElements] : new ::TNuDEpDMuETransfer[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuDEpDMuETransfer(void *p) {
      delete ((::TNuDEpDMuETransfer*)p);
   }
   static void deleteArray_TNuDEpDMuETransfer(void *p) {
      delete [] ((::TNuDEpDMuETransfer*)p);
   }
   static void destruct_TNuDEpDMuETransfer(void *p) {
      typedef ::TNuDEpDMuETransfer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuDEpDMuETransfer

//______________________________________________________________________________
void TNuSec02::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec02.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec02::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec02::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec02(void *p) {
      return  p ? new(p) ::TNuSec02 : new ::TNuSec02;
   }
   static void *newArray_TNuSec02(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec02[nElements] : new ::TNuSec02[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec02(void *p) {
      delete ((::TNuSec02*)p);
   }
   static void deleteArray_TNuSec02(void *p) {
      delete [] ((::TNuSec02*)p);
   }
   static void destruct_TNuSec02(void *p) {
      typedef ::TNuSec02 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec02

//______________________________________________________________________________
void TNuSubIsotope::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSubIsotope.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSubIsotope::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSubIsotope::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSubIsotope(void *p) {
      return  p ? new(p) ::TNuSubIsotope : new ::TNuSubIsotope;
   }
   static void *newArray_TNuSubIsotope(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSubIsotope[nElements] : new ::TNuSubIsotope[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSubIsotope(void *p) {
      delete ((::TNuSubIsotope*)p);
   }
   static void deleteArray_TNuSubIsotope(void *p) {
      delete [] ((::TNuSubIsotope*)p);
   }
   static void destruct_TNuSubIsotope(void *p) {
      typedef ::TNuSubIsotope current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSubIsotope

//______________________________________________________________________________
void TNuResoRMatrixLimited::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoRMatrixLimited.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoRMatrixLimited::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoRMatrixLimited::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoRMatrixLimited(void *p) {
      return  p ? new(p) ::TNuResoRMatrixLimited : new ::TNuResoRMatrixLimited;
   }
   static void *newArray_TNuResoRMatrixLimited(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoRMatrixLimited[nElements] : new ::TNuResoRMatrixLimited[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoRMatrixLimited(void *p) {
      delete ((::TNuResoRMatrixLimited*)p);
   }
   static void deleteArray_TNuResoRMatrixLimited(void *p) {
      delete [] ((::TNuResoRMatrixLimited*)p);
   }
   static void destruct_TNuResoRMatrixLimited(void *p) {
      typedef ::TNuResoRMatrixLimited current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoRMatrixLimited

//______________________________________________________________________________
void TNudy::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNudy.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNudy::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNudy::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNudy(void *p) {
      return  p ? new(p) ::TNudy : new ::TNudy;
   }
   static void *newArray_TNudy(Long_t nElements, void *p) {
      return p ? new(p) ::TNudy[nElements] : new ::TNudy[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNudy(void *p) {
      delete ((::TNudy*)p);
   }
   static void deleteArray_TNudy(void *p) {
      delete [] ((::TNudy*)p);
   }
   static void destruct_TNudy(void *p) {
      typedef ::TNudy current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNudy

//______________________________________________________________________________
void TNuResoUnresolved::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoUnresolved.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoUnresolved::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoUnresolved::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuResoUnresolved(void *p) {
      delete ((::TNuResoUnresolved*)p);
   }
   static void deleteArray_TNuResoUnresolved(void *p) {
      delete [] ((::TNuResoUnresolved*)p);
   }
   static void destruct_TNuResoUnresolved(void *p) {
      typedef ::TNuResoUnresolved current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoUnresolved

//______________________________________________________________________________
void TNuResoUnresolvedA::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoUnresolvedA.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoUnresolvedA::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoUnresolvedA::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoUnresolvedA(void *p) {
      return  p ? new(p) ::TNuResoUnresolvedA : new ::TNuResoUnresolvedA;
   }
   static void *newArray_TNuResoUnresolvedA(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoUnresolvedA[nElements] : new ::TNuResoUnresolvedA[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoUnresolvedA(void *p) {
      delete ((::TNuResoUnresolvedA*)p);
   }
   static void deleteArray_TNuResoUnresolvedA(void *p) {
      delete [] ((::TNuResoUnresolvedA*)p);
   }
   static void destruct_TNuResoUnresolvedA(void *p) {
      typedef ::TNuResoUnresolvedA current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoUnresolvedA

//______________________________________________________________________________
void TNuResoUnresolvedB::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoUnresolvedB.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoUnresolvedB::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoUnresolvedB::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoUnresolvedB(void *p) {
      return  p ? new(p) ::TNuResoUnresolvedB : new ::TNuResoUnresolvedB;
   }
   static void *newArray_TNuResoUnresolvedB(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoUnresolvedB[nElements] : new ::TNuResoUnresolvedB[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoUnresolvedB(void *p) {
      delete ((::TNuResoUnresolvedB*)p);
   }
   static void deleteArray_TNuResoUnresolvedB(void *p) {
      delete [] ((::TNuResoUnresolvedB*)p);
   }
   static void destruct_TNuResoUnresolvedB(void *p) {
      typedef ::TNuResoUnresolvedB current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoUnresolvedB

//______________________________________________________________________________
void TNuResoUnresolvedC::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoUnresolvedC.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoUnresolvedC::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoUnresolvedC::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoUnresolvedC(void *p) {
      return  p ? new(p) ::TNuResoUnresolvedC : new ::TNuResoUnresolvedC;
   }
   static void *newArray_TNuResoUnresolvedC(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoUnresolvedC[nElements] : new ::TNuResoUnresolvedC[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoUnresolvedC(void *p) {
      delete ((::TNuResoUnresolvedC*)p);
   }
   static void deleteArray_TNuResoUnresolvedC(void *p) {
      delete [] ((::TNuResoUnresolvedC*)p);
   }
   static void destruct_TNuResoUnresolvedC(void *p) {
      typedef ::TNuResoUnresolvedC current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoUnresolvedC

//______________________________________________________________________________
void TNuCanvasPrinter::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuCanvasPrinter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuCanvasPrinter::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuCanvasPrinter::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TNuCanvasPrinter(void *p) {
      delete ((::TNuCanvasPrinter*)p);
   }
   static void deleteArray_TNuCanvasPrinter(void *p) {
      delete [] ((::TNuCanvasPrinter*)p);
   }
   static void destruct_TNuCanvasPrinter(void *p) {
      typedef ::TNuCanvasPrinter current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuCanvasPrinter

//______________________________________________________________________________
void TNuTab1ListsSub::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab1ListsSub.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab1ListsSub::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab1ListsSub::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuTab1ListsSub(void *p) {
      return  p ? new(p) ::TNuTab1ListsSub : new ::TNuTab1ListsSub;
   }
   static void *newArray_TNuTab1ListsSub(Long_t nElements, void *p) {
      return p ? new(p) ::TNuTab1ListsSub[nElements] : new ::TNuTab1ListsSub[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuTab1ListsSub(void *p) {
      delete ((::TNuTab1ListsSub*)p);
   }
   static void deleteArray_TNuTab1ListsSub(void *p) {
      delete [] ((::TNuTab1ListsSub*)p);
   }
   static void destruct_TNuTab1ListsSub(void *p) {
      typedef ::TNuTab1ListsSub current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab1ListsSub

//______________________________________________________________________________
void TNuResoAdlerAdler::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoAdlerAdler.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoAdlerAdler::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoAdlerAdler::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoAdlerAdler(void *p) {
      return  p ? new(p) ::TNuResoAdlerAdler : new ::TNuResoAdlerAdler;
   }
   static void *newArray_TNuResoAdlerAdler(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoAdlerAdler[nElements] : new ::TNuResoAdlerAdler[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoAdlerAdler(void *p) {
      delete ((::TNuResoAdlerAdler*)p);
   }
   static void deleteArray_TNuResoAdlerAdler(void *p) {
      delete [] ((::TNuResoAdlerAdler*)p);
   }
   static void destruct_TNuResoAdlerAdler(void *p) {
      typedef ::TNuResoAdlerAdler current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoAdlerAdler

//______________________________________________________________________________
void TNuTab3Tab2::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab3Tab2.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab3Tab2::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab3Tab2::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuTab3Tab2(void *p) {
      return  p ? new(p) ::TNuTab3Tab2 : new ::TNuTab3Tab2;
   }
   static void *newArray_TNuTab3Tab2(Long_t nElements, void *p) {
      return p ? new(p) ::TNuTab3Tab2[nElements] : new ::TNuTab3Tab2[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuTab3Tab2(void *p) {
      delete ((::TNuTab3Tab2*)p);
   }
   static void deleteArray_TNuTab3Tab2(void *p) {
      delete [] ((::TNuTab3Tab2*)p);
   }
   static void destruct_TNuTab3Tab2(void *p) {
      typedef ::TNuTab3Tab2 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab3Tab2

//______________________________________________________________________________
void TNuTab3Tab1Lists::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab3Tab1Lists.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab3Tab1Lists::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab3Tab1Lists::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuTab3Tab1Lists(void *p) {
      return  p ? new(p) ::TNuTab3Tab1Lists : new ::TNuTab3Tab1Lists;
   }
   static void *newArray_TNuTab3Tab1Lists(Long_t nElements, void *p) {
      return p ? new(p) ::TNuTab3Tab1Lists[nElements] : new ::TNuTab3Tab1Lists[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuTab3Tab1Lists(void *p) {
      delete ((::TNuTab3Tab1Lists*)p);
   }
   static void deleteArray_TNuTab3Tab1Lists(void *p) {
      delete [] ((::TNuTab3Tab1Lists*)p);
   }
   static void destruct_TNuTab3Tab1Lists(void *p) {
      typedef ::TNuTab3Tab1Lists current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab3Tab1Lists

//______________________________________________________________________________
void TNuListFPY::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuListFPY.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuListFPY::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuListFPY::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuListFPY(void *p) {
      return  p ? new(p) ::TNuListFPY : new ::TNuListFPY;
   }
   static void *newArray_TNuListFPY(Long_t nElements, void *p) {
      return p ? new(p) ::TNuListFPY[nElements] : new ::TNuListFPY[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuListFPY(void *p) {
      delete ((::TNuListFPY*)p);
   }
   static void deleteArray_TNuListFPY(void *p) {
      delete [] ((::TNuListFPY*)p);
   }
   static void destruct_TNuListFPY(void *p) {
      typedef ::TNuListFPY current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuListFPY

//______________________________________________________________________________
void TNuSec26::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec26.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec26::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec26::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec26(void *p) {
      return  p ? new(p) ::TNuSec26 : new ::TNuSec26;
   }
   static void *newArray_TNuSec26(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec26[nElements] : new ::TNuSec26[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec26(void *p) {
      delete ((::TNuSec26*)p);
   }
   static void deleteArray_TNuSec26(void *p) {
      delete [] ((::TNuSec26*)p);
   }
   static void destruct_TNuSec26(void *p) {
      typedef ::TNuSec26 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec26

//______________________________________________________________________________
void TNuList1Tab1::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuList1Tab1.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuList1Tab1::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuList1Tab1::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuList1Tab1(void *p) {
      return  p ? new(p) ::TNuList1Tab1 : new ::TNuList1Tab1;
   }
   static void *newArray_TNuList1Tab1(Long_t nElements, void *p) {
      return p ? new(p) ::TNuList1Tab1[nElements] : new ::TNuList1Tab1[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuList1Tab1(void *p) {
      delete ((::TNuList1Tab1*)p);
   }
   static void deleteArray_TNuList1Tab1(void *p) {
      delete [] ((::TNuList1Tab1*)p);
   }
   static void destruct_TNuList1Tab1(void *p) {
      typedef ::TNuList1Tab1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuList1Tab1

//______________________________________________________________________________
void TNuSec01460::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec01460.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec01460::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec01460::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec01460(void *p) {
      return  p ? new(p) ::TNuSec01460 : new ::TNuSec01460;
   }
   static void *newArray_TNuSec01460(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec01460[nElements] : new ::TNuSec01460[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec01460(void *p) {
      delete ((::TNuSec01460*)p);
   }
   static void deleteArray_TNuSec01460(void *p) {
      delete [] ((::TNuSec01460*)p);
   }
   static void destruct_TNuSec01460(void *p) {
      typedef ::TNuSec01460 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec01460

//______________________________________________________________________________
void TNuResoBrightWigner::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoBrightWigner.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoBrightWigner::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoBrightWigner::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoBrightWigner(void *p) {
      return  p ? new(p) ::TNuResoBrightWigner : new ::TNuResoBrightWigner;
   }
   static void *newArray_TNuResoBrightWigner(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoBrightWigner[nElements] : new ::TNuResoBrightWigner[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoBrightWigner(void *p) {
      delete ((::TNuResoBrightWigner*)p);
   }
   static void deleteArray_TNuResoBrightWigner(void *p) {
      delete [] ((::TNuResoBrightWigner*)p);
   }
   static void destruct_TNuResoBrightWigner(void *p) {
      typedef ::TNuResoBrightWigner current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoBrightWigner

//______________________________________________________________________________
void TNuResoSLBW::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoSLBW.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoSLBW::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoSLBW::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoSLBW(void *p) {
      return  p ? new(p) ::TNuResoSLBW : new ::TNuResoSLBW;
   }
   static void *newArray_TNuResoSLBW(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoSLBW[nElements] : new ::TNuResoSLBW[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoSLBW(void *p) {
      delete ((::TNuResoSLBW*)p);
   }
   static void deleteArray_TNuResoSLBW(void *p) {
      delete [] ((::TNuResoSLBW*)p);
   }
   static void destruct_TNuResoSLBW(void *p) {
      typedef ::TNuResoSLBW current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoSLBW

//______________________________________________________________________________
void TNuResoMLBW::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuResoMLBW.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuResoMLBW::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuResoMLBW::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuResoMLBW(void *p) {
      return  p ? new(p) ::TNuResoMLBW : new ::TNuResoMLBW;
   }
   static void *newArray_TNuResoMLBW(Long_t nElements, void *p) {
      return p ? new(p) ::TNuResoMLBW[nElements] : new ::TNuResoMLBW[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuResoMLBW(void *p) {
      delete ((::TNuResoMLBW*)p);
   }
   static void deleteArray_TNuResoMLBW(void *p) {
      delete [] ((::TNuResoMLBW*)p);
   }
   static void destruct_TNuResoMLBW(void *p) {
      typedef ::TNuResoMLBW current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuResoMLBW

//______________________________________________________________________________
void TNuSec08454::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec08454.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec08454::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec08454::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec08454(void *p) {
      return  p ? new(p) ::TNuSec08454 : new ::TNuSec08454;
   }
   static void *newArray_TNuSec08454(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec08454[nElements] : new ::TNuSec08454[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec08454(void *p) {
      delete ((::TNuSec08454*)p);
   }
   static void deleteArray_TNuSec08454(void *p) {
      delete [] ((::TNuSec08454*)p);
   }
   static void destruct_TNuSec08454(void *p) {
      typedef ::TNuSec08454 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec08454

//______________________________________________________________________________
void TNuList2Tab1::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuList2Tab1.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuList2Tab1::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuList2Tab1::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuList2Tab1(void *p) {
      return  p ? new(p) ::TNuList2Tab1 : new ::TNuList2Tab1;
   }
   static void *newArray_TNuList2Tab1(Long_t nElements, void *p) {
      return p ? new(p) ::TNuList2Tab1[nElements] : new ::TNuList2Tab1[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuList2Tab1(void *p) {
      delete ((::TNuList2Tab1*)p);
   }
   static void deleteArray_TNuList2Tab1(void *p) {
      delete [] ((::TNuList2Tab1*)p);
   }
   static void destruct_TNuList2Tab1(void *p) {
      typedef ::TNuList2Tab1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuList2Tab1

//______________________________________________________________________________
void TNuSec23::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuSec23.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuSec23::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuSec23::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuSec23(void *p) {
      return  p ? new(p) ::TNuSec23 : new ::TNuSec23;
   }
   static void *newArray_TNuSec23(Long_t nElements, void *p) {
      return p ? new(p) ::TNuSec23[nElements] : new ::TNuSec23[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuSec23(void *p) {
      delete ((::TNuSec23*)p);
   }
   static void deleteArray_TNuSec23(void *p) {
      delete [] ((::TNuSec23*)p);
   }
   static void destruct_TNuSec23(void *p) {
      typedef ::TNuSec23 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuSec23

//______________________________________________________________________________
void TNuTab3List2::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNuTab3List2.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNuTab3List2::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNuTab3List2::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNuTab3List2(void *p) {
      return  p ? new(p) ::TNuTab3List2 : new ::TNuTab3List2;
   }
   static void *newArray_TNuTab3List2(Long_t nElements, void *p) {
      return p ? new(p) ::TNuTab3List2[nElements] : new ::TNuTab3List2[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNuTab3List2(void *p) {
      delete ((::TNuTab3List2*)p);
   }
   static void deleteArray_TNuTab3List2(void *p) {
      delete [] ((::TNuTab3List2*)p);
   }
   static void destruct_TNuTab3List2(void *p) {
      typedef ::TNuTab3List2 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNuTab3List2

namespace ROOT {
   static TClass *maplEintcOTKeymUgR_Dictionary();
   static void maplEintcOTKeymUgR_TClassManip(TClass*);
   static void *new_maplEintcOTKeymUgR(void *p = 0);
   static void *newArray_maplEintcOTKeymUgR(Long_t size, void *p);
   static void delete_maplEintcOTKeymUgR(void *p);
   static void deleteArray_maplEintcOTKeymUgR(void *p);
   static void destruct_maplEintcOTKeymUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,TKey*>*)
   {
      map<int,TKey*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,TKey*>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,TKey*>", -2, "map", 100,
                  typeid(map<int,TKey*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOTKeymUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,TKey*>) );
      instance.SetNew(&new_maplEintcOTKeymUgR);
      instance.SetNewArray(&newArray_maplEintcOTKeymUgR);
      instance.SetDelete(&delete_maplEintcOTKeymUgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOTKeymUgR);
      instance.SetDestructor(&destruct_maplEintcOTKeymUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,TKey*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<int,TKey*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOTKeymUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,TKey*>*)0x0)->GetClass();
      maplEintcOTKeymUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOTKeymUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOTKeymUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,TKey*> : new map<int,TKey*>;
   }
   static void *newArray_maplEintcOTKeymUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,TKey*>[nElements] : new map<int,TKey*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOTKeymUgR(void *p) {
      delete ((map<int,TKey*>*)p);
   }
   static void deleteArray_maplEintcOTKeymUgR(void *p) {
      delete [] ((map<int,TKey*>*)p);
   }
   static void destruct_maplEintcOTKeymUgR(void *p) {
      typedef map<int,TKey*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,TKey*>

namespace {
  void TriggerDictionaryInitialization_G__Nudy_Impl() {
    static const char* headers[] = {
"inc/TNuVResonance.h",
"inc/TNuMath.h",
"inc/TNuPrinter.h",
"inc/TNuSec13.h",
"inc/TNuSec10.h",
"inc/TNuSec09.h",
"inc/TNuLib.h",
"inc/TNuEndfIO.h",
"inc/TNuIntg.h",
"inc/TNuContLists.h",
"inc/TNuSection.h",
"inc/TNuTab1Lists.h",
"inc/TNuListTaylor.h",
"inc/TNuRecsWithTAB2.h",
"inc/TNuTab1.h",
"inc/TNuSec15.h",
"inc/TNuResoResolved.h",
"inc/TNuEndfTAB2.h",
"inc/TNuSec04.h",
"inc/TNuVTab.h",
"inc/TNuListLegendre.h",
"inc/TNuSec03.h",
"inc/TNuCollection.h",
"inc/TNuTab3.h",
"inc/TNuSec06.h",
"inc/TNuCont.h",
"inc/TNuSec07002Coherent.h",
"inc/TNuDescription.h",
"inc/TNuDirs.h",
"inc/TNuSec01458.h",
"inc/TNuSec28.h",
"inc/TNuSublib.h",
"inc/TNuDEpDMu2Body.h",
"inc/TNuSec12Transitions.h",
"inc/TNuListCoulomb.h",
"inc/TNuResoReichMoore.h",
"inc/TNuSec07004.h",
"inc/TNuSec01451.h",
"inc/TNuList.h",
"inc/TNuSec08.h",
"inc/TNuVF1.h",
"inc/TNuList2KalbachMann.h",
"inc/TNuSec01.h",
"inc/TNuSec12Yields.h",
"inc/TNuVF3.h",
"inc/TNuContList.h",
"inc/TNuDEpDMu.h",
"inc/TNuSec07002.h",
"inc/TNuSec08457.h",
"inc/TNuList2Legendre.h",
"inc/TNuTab2Tab1.h",
"inc/TNuCov.h",
"inc/TNuResonance.h",
"inc/TNuSec05.h",
"inc/TNuTab2List1.h",
"inc/TNuSec14.h",
"inc/TNuSec27.h",
"inc/TNuRecsWithTab1.h",
"inc/TNuList1.h",
"inc/TNuTab2.h",
"inc/TNuSec07002Incoherent.h",
"inc/TNuDEpDMuETransfer.h",
"inc/TNuLabel.h",
"inc/TNuVF2.h",
"inc/TNuVF1s.h",
"inc/TNuObject.h",
"inc/TNuSec02.h",
"inc/TNuResoRMatrixLimited.h",
"inc/TNudy.h",
"inc/TNuSaveToTextDlg.h",
"inc/TNuResoUnresolved.h",
"inc/TNuMat.h",
"inc/TNuCanvasPrinter.h",
"inc/TNuList2.h",
"inc/TNuTab1ListsSub.h",
"inc/TNuResoAdlerAdler.h",
"inc/TNuTab3Tab2.h",
"inc/TNuTab3Tab1Lists.h",
"inc/TNuRecsWithCont.h",
"inc/TNuFile.h",
"inc/TNuRecs.h",
"inc/TNuListFPY.h",
"inc/TNuSec26.h",
"inc/TNuList1Tab1.h",
"inc/TNuSec12.h",
"inc/TNuSec01460.h",
"inc/TNuLazyCollection.h",
"inc/TNuResoBrightWigner.h",
"inc/TNuSec08454.h",
"inc/TNuList2Tab1.h",
"inc/TNuSec23.h",
"inc/TNuTab3List2.h",
0
    };
    static const char* includePaths[] = {
"/home/i/soft/root/v6-20-04/include/",
"/home/i/nudy/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "G__Nudy dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for the labels of a record)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuLabel.h")))  __attribute__((annotate("$clingAutoload$inc/TNuVResonance.h")))  TNuLabel;
class __attribute__((annotate(R"ATTRDUMP(TObject in TNudy)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuObject.h")))  __attribute__((annotate("$clingAutoload$inc/TNuVResonance.h")))  TNuObject;
class __attribute__((annotate(R"ATTRDUMP(Abstract class for 1D functor)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuVF1.h")))  __attribute__((annotate("$clingAutoload$inc/TNuVResonance.h")))  TNuVF1;
class __attribute__((annotate(R"ATTRDUMP(Abstract class for a set of 1D functors)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuVF1s.h")))  __attribute__((annotate("$clingAutoload$inc/TNuVResonance.h")))  TNuVF1s;
class __attribute__((annotate(R"ATTRDUMP(Abstract class to provide a uniform interfaces for the resonance data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuVResonance.h")))  TNuVResonance;
class __attribute__((annotate(R"ATTRDUMP(Class for Dialog to save the text of object)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuSaveToTextDlg.h")))  __attribute__((annotate("$clingAutoload$inc/TNuPrinter.h")))  TNuSaveToTextDlg;
class __attribute__((annotate("$clingAutoload$TNuSaveToTextDlg.h")))  __attribute__((annotate("$clingAutoload$inc/TNuPrinter.h")))  MyFileDlg;
class __attribute__((annotate(R"ATTRDUMP(The class for controling the printing of TNudy)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuPrinter.h")))  TNuPrinter;
class __attribute__((annotate(R"ATTRDUMP(Class for the ENDF CONT record)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuCont.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec13.h")))  TNuCont;
class __attribute__((annotate(R"ATTRDUMP(Base class for the collection of TNuObject elements.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuRecs.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec13.h")))  TNuRecs;
class __attribute__((annotate(R"ATTRDUMP(Class for the ENDF SECTION data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuSection.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec13.h")))  TNuSection;
class __attribute__((annotate(R"ATTRDUMP(Abstract class for handling tabulated ENDF data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuVTab.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec13.h")))  TNuVTab;
class __attribute__((annotate(R"ATTRDUMP(Class for the ENDF TAB2 record)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuEndfTAB2.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec13.h")))  TNuEndfTAB2;
class __attribute__((annotate(R"ATTRDUMP(Class for the ENDF TAB1 record)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuTab1.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec13.h")))  TNuTab1;
class __attribute__((annotate(R"ATTRDUMP(class for an ENDF data file)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuEndfIO.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec13.h")))  TNuEndfIO;
class __attribute__((annotate(R"ATTRDUMP(Photon production cross sections)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec13.h")))  TNuSec13;
class __attribute__((annotate(R"ATTRDUMP(Product cross sections)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec10.h")))  TNuSec10;
class __attribute__((annotate(R"ATTRDUMP(Multiplicities of RN)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec09.h")))  TNuSec09;
class __attribute__((annotate(R"ATTRDUMP(Abstract class for a container)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuCollection.h")))  __attribute__((annotate("$clingAutoload$inc/TNuLib.h")))  TNuCollection;
class __attribute__((annotate("$clingAutoload$TNuCollection.h")))  __attribute__((annotate("$clingAutoload$inc/TNuLib.h")))  TNuIter;
class __attribute__((annotate(R"ATTRDUMP(class for lazy loading collection)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuLazyCollection.h")))  __attribute__((annotate("$clingAutoload$inc/TNuLib.h")))  TNuLazyCollection;
class __attribute__((annotate(R"ATTRDUMP(A set of TNuSection data with a common MF value)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuFile.h")))  __attribute__((annotate("$clingAutoload$inc/TNuLib.h")))  TNuFile;
class __attribute__((annotate(R"ATTRDUMP(data for a material of ENDF)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuMat.h")))  __attribute__((annotate("$clingAutoload$inc/TNuLib.h")))  TNuMat;
class __attribute__((annotate(R"ATTRDUMP(A set of TNuMat elements with common NSUB)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuSublib.h")))  __attribute__((annotate("$clingAutoload$inc/TNuLib.h")))  TNuSublib;
class __attribute__((annotate(R"ATTRDUMP(Set of all the ENDF data that belong to a ENDF library)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuLib.h")))  TNuLib;
class __attribute__((annotate(R"ATTRDUMP(Class for ENDF INTG structure)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuIntg.h")))  TNuIntg;
class __attribute__((annotate(R"ATTRDUMP(Class for the data of the form TNuCont + subsection)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuRecsWithCont.h")))  __attribute__((annotate("$clingAutoload$inc/TNuContLists.h")))  TNuRecsWithCont;
class __attribute__((annotate(R"ATTRDUMP(Class for ENDF LIST record)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuList.h")))  __attribute__((annotate("$clingAutoload$inc/TNuContLists.h")))  TNuList;
class __attribute__((annotate(R"ATTRDUMP(TNuCont + (i-th TNuList, i=1, N))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuContLists.h")))  TNuContLists;
class __attribute__((annotate(R"ATTRDUMP(Abstract class for 2D functor)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuVF2.h")))  __attribute__((annotate("$clingAutoload$inc/TNuTab1Lists.h")))  TNuVF2;
class __attribute__((annotate(R"ATTRDUMP(2D functor S(T, E) on a retangular grid)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuTab1Lists.h")))  TNuTab1Lists;
class __attribute__((annotate(R"ATTRDUMP(Service class for TNuList with TNuVF1)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuList1.h")))  __attribute__((annotate("$clingAutoload$inc/TNuListTaylor.h")))  TNuList1;
class __attribute__((annotate(R"ATTRDUMP(TNuList for Taylor polynomial coefficients)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuListTaylor.h")))  TNuListTaylor;
class __attribute__((annotate(R"ATTRDUMP(subsection with TAB2)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuRecsWithTAB2.h")))  TNuRecsWithTAB2;
class __attribute__((annotate(R"ATTRDUMP(2-dimensional functor(example: TAB2 of TAB1))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuTab2.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec15.h")))  TNuTab2;
class __attribute__((annotate(R"ATTRDUMP(Class for Tab1 for (E, y(E)) + sub-structure)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuRecsWithTab1.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec15.h")))  TNuRecsWithTab1;
class __attribute__((annotate(R"ATTRDUMP(Continuous photon energy spectra)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec15.h")))  TNuSec15;
class __attribute__((annotate(R"ATTRDUMP(A specific representation of resonance parameters)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuResonance.h")))  __attribute__((annotate("$clingAutoload$inc/TNuResoResolved.h")))  TNuResonance;
class __attribute__((annotate(R"ATTRDUMP(Resolved Resonance Parameters (LRU=1))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoResolved.h")))  TNuResoResolved;
class __attribute__((annotate(R"ATTRDUMP(Angular distributions)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec04.h")))  TNuSec04;
class __attribute__((annotate(R"ATTRDUMP(TNuList for normalized Legendre polynomial coefficients)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuListLegendre.h")))  TNuListLegendre;
class __attribute__((annotate(R"ATTRDUMP(Reaction cross sections)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec03.h")))  TNuSec03;
class __attribute__((annotate(R"ATTRDUMP(Abstract class for 3D functor)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuVF3.h")))  __attribute__((annotate("$clingAutoload$inc/TNuTab3.h")))  TNuVF3;
class __attribute__((annotate(R"ATTRDUMP(3-dimensional functor (example: TAB2 of TNuTab2))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuTab3.h")))  TNuTab3;
class __attribute__((annotate(R"ATTRDUMP(Energy-angle distributions)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec06.h")))  TNuSec06;
class __attribute__((annotate(R"ATTRDUMP(Thermal neutron scattering data (E < 5 eV))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuSec07002.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec07002Coherent.h")))  TNuSec07002;
class __attribute__((annotate(R"ATTRDUMP(Thermal neutron elastic coherent scattering data (E < 5 eV))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec07002Coherent.h")))  TNuSec07002Coherent;
class __attribute__((annotate(R"ATTRDUMP(class for text data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuDescription.h")))  TNuDescription;
class __attribute__((annotate(R"ATTRDUMP(class for text data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuDirs.h")))  TNuDirs;
class __attribute__((annotate(R"ATTRDUMP(Fission energy released)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec01458.h")))  TNuSec01458;
class __attribute__((annotate(R"ATTRDUMP(Atomic relaxation data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec28.h")))  TNuSec28;
class __attribute__((annotate(R"ATTRDUMP(Law-dependent energy-angle distribution)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuDEpDMu.h")))  __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMu;
class __attribute__((annotate(R"ATTRDUMP(TNuDEpDMu with TNuVF3)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuDEpDMu.h")))  __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMuF3;
class __attribute__((annotate(R"ATTRDUMP(Unknown Distribution (LAW=0))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuDEpDMu.h")))  __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMuUnknwon;
class __attribute__((annotate(R"ATTRDUMP(Continuum Energy-Angle Distributions (LAW=1))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuDEpDMu.h")))  __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMuContinuum;
class __attribute__((annotate(R"ATTRDUMP(N-Body Phase-Space Distributions (LAW=6))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuDEpDMu.h")))  __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMuNBodyPhaseSpace;
class __attribute__((annotate(R"ATTRDUMP(Laboratory Angle-Energy Law (LAW=7))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuDEpDMu.h")))  __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMuLaboratory;
class __attribute__((annotate(R"ATTRDUMP(2-body scattering data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMu2Body;
class __attribute__((annotate(R"ATTRDUMP(Discrete Two-Body Scattering (LAW=2))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMu2BodyScattering;
class __attribute__((annotate(R"ATTRDUMP(Isotropic Discrete Emission (LAW=3))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMu2BodyIsotropic;
class __attribute__((annotate(R"ATTRDUMP(Discrete Two-Body Recoils (LAW=4))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMu2BodyRecoil;
class __attribute__((annotate(R"ATTRDUMP(Charged-Particle Elastic Scattering (LAW=5))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuDEpDMu2Body.h")))  TNuDEpDMu2BodyCoulomb;
class __attribute__((annotate(R"ATTRDUMP(Multiplicities and transition probability arrays)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuSec12.h")))  __attribute__((annotate("$clingAutoload$inc/TNuSec12Transitions.h")))  TNuSec12;
class __attribute__((annotate(R"ATTRDUMP(Multiplicities in transitions)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec12Transitions.h")))  TNuSec12Transitions;
class __attribute__((annotate(R"ATTRDUMP(Elastic Coulomb scattering cross section)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuListCoulomb.h")))  TNuListCoulomb;
class __attribute__((annotate(R"ATTRDUMP(Resonance data in Reich-Moorer (LRF=3) format)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoReichMoore.h")))  TNuResoReichMoore;
class __attribute__((annotate(R"ATTRDUMP(Thermal neutron inelastic scattering data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec07004.h")))  TNuSec07004;
class __attribute__((annotate(R"ATTRDUMP(General description)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec01451.h")))  TNuSec01451;
class __attribute__((annotate(R"ATTRDUMP(Decay data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec08.h")))  TNuSec08;
class __attribute__((annotate(R"ATTRDUMP(TAB2 of LISTs but represented by a single LIST)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNuList2.h")))  __attribute__((annotate("$clingAutoload$inc/TNuList2KalbachMann.h")))  TNuList2;
class __attribute__((annotate(R"ATTRDUMP(TNuList2 where a sub-list is for Kalbach-Mann coefficients)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuList2KalbachMann.h")))  TNuList2KalbachMann;
class __attribute__((annotate(R"ATTRDUMP(Neutron yields (MT=452 for total, MT=455 for delayed, MT=456 for prompt))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec01.h")))  TNuSec01;
class __attribute__((annotate(R"ATTRDUMP(Multiplicities in yields)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec12Yields.h")))  TNuSec12Yields;
class __attribute__((annotate(R"ATTRDUMP(1 TNuCont (inherited) + 1 TNuList (as member variable))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuContList.h")))  TNuContList;
class __attribute__((annotate(R"ATTRDUMP(spontaneous radioactive decay data (MT=457))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec08457.h")))  TNuSec08457;
class __attribute__((annotate(R"ATTRDUMP(Subsection of TNuSec08457, data for spontaneous fission products)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec08457.h")))  TNuSFYSub;
class __attribute__((annotate(R"ATTRDUMP(TNuList2 where a sub-list is for Legendre coefficients)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuList2Legendre.h")))  TNuList2Legendre;
class __attribute__((annotate(R"ATTRDUMP(2-dimensional functor(TAB2 of TNuTab1))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuTab2Tab1.h")))  TNuTab2Tab1;
class __attribute__((annotate(R"ATTRDUMP(fission product yield data at an energy)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuContListNC;
class __attribute__((annotate(R"ATTRDUMP(fission product yield data at an energy)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuListNI;
class __attribute__((annotate(R"ATTRDUMP(fission product yield data at an energy)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuContListsCov33;
class __attribute__((annotate(R"ATTRDUMP(fission product yield data at an energy)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuCovMatrix;
class __attribute__((annotate(R"ATTRDUMP(Neutron yields (MT=452 for total, MT=455 for delayed, MT=456 for prompt))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuSec31;
class __attribute__((annotate(R"ATTRDUMP(Reaction cross sections)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuSec33;
class __attribute__((annotate(R"ATTRDUMP(fission product yield data at an energy)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuContListsCov34;
class __attribute__((annotate(R"ATTRDUMP(fission product yield data at an energy)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuSubSec34;
class __attribute__((annotate(R"ATTRDUMP(Angular distributions)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuSec34;
class __attribute__((annotate(R"ATTRDUMP(Energy Distributions)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuSec35;
class __attribute__((annotate(R"ATTRDUMP(Product cross sections)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuSec40;
class __attribute__((annotate(R"ATTRDUMP(Resonance data section, MF=2, MT=151)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuSec32;
class __attribute__((annotate(R"ATTRDUMP(Resonance parameters for an isotope)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuSubIsotopeCov;
class __attribute__((annotate(R"ATTRDUMP(A specific representation of resonance parameters)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCov.h")))  TNuResonanceCov;
class __attribute__((annotate(R"ATTRDUMP(Energy Distributions)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec05.h")))  TNuSec05;
class __attribute__((annotate(R"ATTRDUMP(Generic class for energy distributions)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec05.h")))  TNuESpectrum;
class __attribute__((annotate(R"ATTRDUMP(Arbitrary Tabulated Function (LF=1))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec05.h")))  TNuESpectrumTabulated;
class __attribute__((annotate(R"ATTRDUMP(General Evaporation Spectrum (LF=5))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec05.h")))  TNuESpectrumGeneralEvaporation;
class __attribute__((annotate(R"ATTRDUMP(Simple Maxwellian Fission Spectrum (LF=7))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec05.h")))  TNuESpectrumMaxwellian;
class __attribute__((annotate(R"ATTRDUMP(Evaporation Spectrum (LF=9))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec05.h")))  TNuESpectrumEvaporation;
class __attribute__((annotate(R"ATTRDUMP(Energy-Dependent Watt Spectrum (LF=11))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec05.h")))  TNuESpectrumWatt;
class __attribute__((annotate(R"ATTRDUMP(Energy-Dependent Fission Neutron Spectrum (Madland and Nix) (LF=12))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec05.h")))  TNuESpectrumMadlandNix;
class __attribute__((annotate(R"ATTRDUMP(2-dimensional functor(TAB2 of TNuList1))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuTab2List1.h")))  TNuTab2List1;
class __attribute__((annotate(R"ATTRDUMP(Photon angular distributions)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec14.h")))  TNuSec14;
class __attribute__((annotate(R"ATTRDUMP(Atomic form factors or scattering functions)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec27.h")))  TNuSec27;
class __attribute__((annotate(R"ATTRDUMP(Thermal neutron elastic incoherent scattering data (E < 5 eV))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec07002Incoherent.h")))  TNuSec07002Incoherent;
class __attribute__((annotate(R"ATTRDUMP(Energy transfer during electro-atomic excitation or bremsstrahlung)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuDEpDMuETransfer.h")))  TNuDEpDMuETransfer;
class __attribute__((annotate(R"ATTRDUMP(Resonance data section, MF=2, MT=151)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec02.h")))  TNuSec02;
class __attribute__((annotate(R"ATTRDUMP(Resonance parameters for an isotope)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec02.h")))  TNuSubIsotope;
class __attribute__((annotate(R"ATTRDUMP(Resonance data in R-Matrix Limited (LRF=7) format)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoRMatrixLimited.h")))  TNuResoRMatrixLimited;
class __attribute__((annotate(R"ATTRDUMP(The master class)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNudy.h")))  TNudy;
class __attribute__((annotate(R"ATTRDUMP(Ubresolved Resonance Parameters (LRU=2))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoUnresolved.h")))  TNuResoUnresolved;
class __attribute__((annotate(R"ATTRDUMP(Ubresolved Resonance Parameters (LRU=2), Case A)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoUnresolved.h")))  TNuResoUnresolvedA;
class __attribute__((annotate(R"ATTRDUMP(Ubresolved Resonance Parameters (LRU=2), Case B)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoUnresolved.h")))  TNuResoUnresolvedB;
class __attribute__((annotate(R"ATTRDUMP(Ubresolved Resonance Parameters (LRU=2), Case C)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoUnresolved.h")))  TNuResoUnresolvedC;
class __attribute__((annotate(R"ATTRDUMP(Class for controling the printing of TNudy on Canvas)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuCanvasPrinter.h")))  TNuCanvasPrinter;
class __attribute__((annotate(R"ATTRDUMP(the LIST that appears as a data element of TNuTab1Lists)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuTab1ListsSub.h")))  TNuTab1ListsSub;
class __attribute__((annotate(R"ATTRDUMP(Resonance data in Adler-Adler (LRF=4) format)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoAdlerAdler.h")))  TNuResoAdlerAdler;
class __attribute__((annotate(R"ATTRDUMP(3-dimensional functor (TAB2 of TNuTab2))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuTab3Tab2.h")))  TNuTab3Tab2;
class __attribute__((annotate(R"ATTRDUMP(3-dimensional functor (TAB2 of TNuTab1Lists))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuTab3Tab1Lists.h")))  TNuTab3Tab1Lists;
class __attribute__((annotate(R"ATTRDUMP(fission product yield data at an energy)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuListFPY.h")))  TNuListFPY;
class __attribute__((annotate(R"ATTRDUMP(Secondary distributions for photo- and electro-atomic data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec26.h")))  TNuSec26;
class __attribute__((annotate(R"ATTRDUMP(TNuTab1 represented as a TNuList)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuList1Tab1.h")))  TNuList1Tab1;
class __attribute__((annotate(R"ATTRDUMP(Delayed photon data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec01460.h")))  TNuSec01460;
class __attribute__((annotate(R"ATTRDUMP(Resonance data in Breit-Wigner format)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoBrightWigner.h")))  TNuResoBrightWigner;
class __attribute__((annotate(R"ATTRDUMP(Resonance data in Single-level Breit-Wigner (LRF=1) format)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoBrightWigner.h")))  TNuResoSLBW;
class __attribute__((annotate(R"ATTRDUMP(Resonance data in Multi-level Breit-Wigner (LRF=2) format)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuResoBrightWigner.h")))  TNuResoMLBW;
class __attribute__((annotate(R"ATTRDUMP(Fission product yield data (MT=454 for independent, MT=459 for cumulative))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec08454.h")))  TNuSec08454;
class __attribute__((annotate(R"ATTRDUMP(TNuList2 where a sub-list is for TAB1 data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuList2Tab1.h")))  TNuList2Tab1;
class __attribute__((annotate(R"ATTRDUMP(Smooth photon interaction cross sections)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuSec23.h")))  TNuSec23;
class __attribute__((annotate(R"ATTRDUMP(3-dimensional functor (TAB2 of TNuList2))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$inc/TNuTab3List2.h")))  TNuTab3List2;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "G__Nudy dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "inc/TNuVResonance.h"
#include "inc/TNuMath.h"
#include "inc/TNuPrinter.h"
#include "inc/TNuSec13.h"
#include "inc/TNuSec10.h"
#include "inc/TNuSec09.h"
#include "inc/TNuLib.h"
#include "inc/TNuEndfIO.h"
#include "inc/TNuIntg.h"
#include "inc/TNuContLists.h"
#include "inc/TNuSection.h"
#include "inc/TNuTab1Lists.h"
#include "inc/TNuListTaylor.h"
#include "inc/TNuRecsWithTAB2.h"
#include "inc/TNuTab1.h"
#include "inc/TNuSec15.h"
#include "inc/TNuResoResolved.h"
#include "inc/TNuEndfTAB2.h"
#include "inc/TNuSec04.h"
#include "inc/TNuVTab.h"
#include "inc/TNuListLegendre.h"
#include "inc/TNuSec03.h"
#include "inc/TNuCollection.h"
#include "inc/TNuTab3.h"
#include "inc/TNuSec06.h"
#include "inc/TNuCont.h"
#include "inc/TNuSec07002Coherent.h"
#include "inc/TNuDescription.h"
#include "inc/TNuDirs.h"
#include "inc/TNuSec01458.h"
#include "inc/TNuSec28.h"
#include "inc/TNuSublib.h"
#include "inc/TNuDEpDMu2Body.h"
#include "inc/TNuSec12Transitions.h"
#include "inc/TNuListCoulomb.h"
#include "inc/TNuResoReichMoore.h"
#include "inc/TNuSec07004.h"
#include "inc/TNuSec01451.h"
#include "inc/TNuList.h"
#include "inc/TNuSec08.h"
#include "inc/TNuVF1.h"
#include "inc/TNuList2KalbachMann.h"
#include "inc/TNuSec01.h"
#include "inc/TNuSec12Yields.h"
#include "inc/TNuVF3.h"
#include "inc/TNuContList.h"
#include "inc/TNuDEpDMu.h"
#include "inc/TNuSec07002.h"
#include "inc/TNuSec08457.h"
#include "inc/TNuList2Legendre.h"
#include "inc/TNuTab2Tab1.h"
#include "inc/TNuCov.h"
#include "inc/TNuResonance.h"
#include "inc/TNuSec05.h"
#include "inc/TNuTab2List1.h"
#include "inc/TNuSec14.h"
#include "inc/TNuSec27.h"
#include "inc/TNuRecsWithTab1.h"
#include "inc/TNuList1.h"
#include "inc/TNuTab2.h"
#include "inc/TNuSec07002Incoherent.h"
#include "inc/TNuDEpDMuETransfer.h"
#include "inc/TNuLabel.h"
#include "inc/TNuVF2.h"
#include "inc/TNuVF1s.h"
#include "inc/TNuObject.h"
#include "inc/TNuSec02.h"
#include "inc/TNuResoRMatrixLimited.h"
#include "inc/TNudy.h"
#include "inc/TNuSaveToTextDlg.h"
#include "inc/TNuResoUnresolved.h"
#include "inc/TNuMat.h"
#include "inc/TNuCanvasPrinter.h"
#include "inc/TNuList2.h"
#include "inc/TNuTab1ListsSub.h"
#include "inc/TNuResoAdlerAdler.h"
#include "inc/TNuTab3Tab2.h"
#include "inc/TNuTab3Tab1Lists.h"
#include "inc/TNuRecsWithCont.h"
#include "inc/TNuFile.h"
#include "inc/TNuRecs.h"
#include "inc/TNuListFPY.h"
#include "inc/TNuSec26.h"
#include "inc/TNuList1Tab1.h"
#include "inc/TNuSec12.h"
#include "inc/TNuSec01460.h"
#include "inc/TNuLazyCollection.h"
#include "inc/TNuResoBrightWigner.h"
#include "inc/TNuSec08454.h"
#include "inc/TNuList2Tab1.h"
#include "inc/TNuSec23.h"
#include "inc/TNuTab3List2.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"MyFileDlg", payloadCode, "@",
"TNuCanvasPrinter", payloadCode, "@",
"TNuCollection", payloadCode, "@",
"TNuCont", payloadCode, "@",
"TNuContList", payloadCode, "@",
"TNuContListNC", payloadCode, "@",
"TNuContLists", payloadCode, "@",
"TNuContListsCov33", payloadCode, "@",
"TNuContListsCov34", payloadCode, "@",
"TNuCovMatrix", payloadCode, "@",
"TNuDEpDMu", payloadCode, "@",
"TNuDEpDMu2Body", payloadCode, "@",
"TNuDEpDMu2BodyCoulomb", payloadCode, "@",
"TNuDEpDMu2BodyIsotropic", payloadCode, "@",
"TNuDEpDMu2BodyRecoil", payloadCode, "@",
"TNuDEpDMu2BodyScattering", payloadCode, "@",
"TNuDEpDMuContinuum", payloadCode, "@",
"TNuDEpDMuETransfer", payloadCode, "@",
"TNuDEpDMuF3", payloadCode, "@",
"TNuDEpDMuLaboratory", payloadCode, "@",
"TNuDEpDMuNBodyPhaseSpace", payloadCode, "@",
"TNuDEpDMuUnknwon", payloadCode, "@",
"TNuDescription", payloadCode, "@",
"TNuDirs", payloadCode, "@",
"TNuESpectrum", payloadCode, "@",
"TNuESpectrumEvaporation", payloadCode, "@",
"TNuESpectrumGeneralEvaporation", payloadCode, "@",
"TNuESpectrumMadlandNix", payloadCode, "@",
"TNuESpectrumMaxwellian", payloadCode, "@",
"TNuESpectrumTabulated", payloadCode, "@",
"TNuESpectrumWatt", payloadCode, "@",
"TNuEndfIO", payloadCode, "@",
"TNuEndfTAB2", payloadCode, "@",
"TNuFile", payloadCode, "@",
"TNuIntg", payloadCode, "@",
"TNuIter", payloadCode, "@",
"TNuLabel", payloadCode, "@",
"TNuLazyCollection", payloadCode, "@",
"TNuLib", payloadCode, "@",
"TNuList", payloadCode, "@",
"TNuList1", payloadCode, "@",
"TNuList1Tab1", payloadCode, "@",
"TNuList2", payloadCode, "@",
"TNuList2KalbachMann", payloadCode, "@",
"TNuList2Legendre", payloadCode, "@",
"TNuList2Tab1", payloadCode, "@",
"TNuListCoulomb", payloadCode, "@",
"TNuListFPY", payloadCode, "@",
"TNuListLegendre", payloadCode, "@",
"TNuListNI", payloadCode, "@",
"TNuListTaylor", payloadCode, "@",
"TNuMat", payloadCode, "@",
"TNuObject", payloadCode, "@",
"TNuPrinter", payloadCode, "@",
"TNuRecs", payloadCode, "@",
"TNuRecsWithCont", payloadCode, "@",
"TNuRecsWithTAB2", payloadCode, "@",
"TNuRecsWithTab1", payloadCode, "@",
"TNuResoAdlerAdler", payloadCode, "@",
"TNuResoBrightWigner", payloadCode, "@",
"TNuResoMLBW", payloadCode, "@",
"TNuResoRMatrixLimited", payloadCode, "@",
"TNuResoReichMoore", payloadCode, "@",
"TNuResoResolved", payloadCode, "@",
"TNuResoSLBW", payloadCode, "@",
"TNuResoUnresolved", payloadCode, "@",
"TNuResoUnresolvedA", payloadCode, "@",
"TNuResoUnresolvedB", payloadCode, "@",
"TNuResoUnresolvedC", payloadCode, "@",
"TNuResonance", payloadCode, "@",
"TNuResonanceCov", payloadCode, "@",
"TNuSFYSub", payloadCode, "@",
"TNuSaveToTextDlg", payloadCode, "@",
"TNuSec01", payloadCode, "@",
"TNuSec01451", payloadCode, "@",
"TNuSec01458", payloadCode, "@",
"TNuSec01460", payloadCode, "@",
"TNuSec02", payloadCode, "@",
"TNuSec03", payloadCode, "@",
"TNuSec04", payloadCode, "@",
"TNuSec05", payloadCode, "@",
"TNuSec06", payloadCode, "@",
"TNuSec07002", payloadCode, "@",
"TNuSec07002Coherent", payloadCode, "@",
"TNuSec07002Incoherent", payloadCode, "@",
"TNuSec07004", payloadCode, "@",
"TNuSec08", payloadCode, "@",
"TNuSec08454", payloadCode, "@",
"TNuSec08457", payloadCode, "@",
"TNuSec09", payloadCode, "@",
"TNuSec10", payloadCode, "@",
"TNuSec12", payloadCode, "@",
"TNuSec12Transitions", payloadCode, "@",
"TNuSec12Yields", payloadCode, "@",
"TNuSec13", payloadCode, "@",
"TNuSec14", payloadCode, "@",
"TNuSec15", payloadCode, "@",
"TNuSec23", payloadCode, "@",
"TNuSec26", payloadCode, "@",
"TNuSec27", payloadCode, "@",
"TNuSec28", payloadCode, "@",
"TNuSec31", payloadCode, "@",
"TNuSec32", payloadCode, "@",
"TNuSec33", payloadCode, "@",
"TNuSec34", payloadCode, "@",
"TNuSec35", payloadCode, "@",
"TNuSec40", payloadCode, "@",
"TNuSection", payloadCode, "@",
"TNuSubIsotope", payloadCode, "@",
"TNuSubIsotopeCov", payloadCode, "@",
"TNuSubSec34", payloadCode, "@",
"TNuSublib", payloadCode, "@",
"TNuTab1", payloadCode, "@",
"TNuTab1Lists", payloadCode, "@",
"TNuTab1ListsSub", payloadCode, "@",
"TNuTab2", payloadCode, "@",
"TNuTab2List1", payloadCode, "@",
"TNuTab2Tab1", payloadCode, "@",
"TNuTab3", payloadCode, "@",
"TNuTab3List2", payloadCode, "@",
"TNuTab3Tab1Lists", payloadCode, "@",
"TNuTab3Tab2", payloadCode, "@",
"TNuVF1", payloadCode, "@",
"TNuVF1s", payloadCode, "@",
"TNuVF2", payloadCode, "@",
"TNuVF3", payloadCode, "@",
"TNuVResonance", payloadCode, "@",
"TNuVTab", payloadCode, "@",
"TNudy", payloadCode, "@",
"gNuLib", payloadCode, "@",
"gNuListOfLibs", payloadCode, "@",
"gNuObject", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("G__Nudy",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_G__Nudy_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_G__Nudy_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_G__Nudy() {
  TriggerDictionaryInitialization_G__Nudy_Impl();
}
