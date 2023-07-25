// TNuIntg.h  =====================================================
// Author: Tae-Sun Park   Jun 13 23:43:10 2011

#ifndef ROOT_TNuIntg
#define ROOT_TNuIntg

///////////////////////////////////////////////////////////////////////////////
//
// TNuIntg
//
// 1 CONT + NM INTG lines
//
// [MAT,32,151/ 0.0, 0.0, NDIGIT, NNN, NM, 0 ]CONT
// [MAT,32,151/ II, JJ, KIJ ]INTG
// [MAT,32,151/ II, JJ, KIJ ]INTG
// < Continue until a total of NM of INTG records are read >
//
///////////////////////////////////////////////////////////////////////////////

#include "TNuCont.h"
class TNuEndfIO;

class TNuIntg : public TNuCont
{
public:
   TNuIntg(): TNuCont(), fI(0), fJ(0), fK(0) {}
   TNuIntg(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);
   TNuIntg(TNuEndfIO &src, const Char_t* label=" 0.0, 0.0, NDIGIT, NNN, NM, 0");
   //TNuIntg(const TNuIntg &list);
   virtual ~TNuIntg();

   void  ImportEndfData(TNuEndfIO &src);
   Int_t GetNDIGIT() const { return GetL1() ? GetL1() : 2; }
   Int_t GetNNN()    const { return GetL2(); }
   Int_t GetNM()     const { return GetN1(); } //number of INTG lines
   //Int_t GetNData()  const { return fNData; }
   void SetAt(Int_t i, Int_t j, Short_t kij[], Int_t at);

   Short_t* GetIs() const { return fI; }
   Short_t* GetJs() const { return fJ; }
   Short_t* GetKs() const { return fK; }

   Double_t GetCorrelation(Int_t i, Int_t j) const;

   Short_t  GetI(Int_t n) const { return RangeOk(n, GetNM()) ? fI[n] : 0; }
   Short_t  GetJ(Int_t n) const { return RangeOk(n, GetNM()) ? fJ[n] : 0; }
   Short_t  GetK(Int_t n, Int_t m) const { return
               RangeOk(n, GetNM()) && RangeOk(m, fNRow) ? fK[n*fNRow + m] : 0; }

   void     SetCont(Double_t c1, Double_t c2, Int_t l1, Int_t l2, Int_t n1, Int_t n2);


private:
   void     ClearHeap();
   void     Init();
   Bool_t   RangeOk(int n, int nmax) const {
               if (n >= 0 && n < nmax) return kTRUE;
               fprintf(stderr, "TNuIntg::Error: %d is not in [0, %d)\n", n, nmax);
               return kFALSE;
            }

   Int_t    fNRow;  // number of KIJ(N) data per row, NROW
   Int_t    fKsize; // number of whole KIJ(N) data, GetNM() * fNRow
   Double_t fScaleFactor; //! scale factor to be multiplied to K for Corr.

   Short_t* fI;     //[fN1]
   Short_t* fJ;     //[fN1]
   Short_t* fK;     //[fKsize]

   ClassDef(TNuIntg, 1) // Class for ENDF INTG structure
};


#endif



