{
// dont know why but we should include this "libRIO" first
//http://root.cern.ch/phpBB2/viewtopic.php?p=38612&sid=298e1764cd2d07300af2710764e851e8
// 
//gSystem->Load("libRIO");
//gSystem->Load("libHist");



gSystem->Load("libNudy.so");

//TNuMaterial *gNuMat;
//TNuSection  *gNuSec;
//TNudy  *gNudy;

// open the ENDF data file
TNuLib *lib = TNudy::LoadRootFile("ENDF-B-VII.1.root");

//
// print catalog, 1 line for each MAT. it will print ~1,000 lines !
//
// gCat->Print();

//
// move to the directory with NSUB=10 (indent neutron)
//
//gDirectory->cd("NSUB_10");
lib->GetSublib(10);

//
// move to the directory for MAT=9228
//
//gDirectory->cd("MAT_9228");


//
// load the data for U235: sections are not loaded, only info is loaded
//
TNuMat *u235=lib->GetMat(922350);
TNuMat *u238=lib->GetMat(922380);
TNuMat *th232=lib->GetMat(902320);
TNuMat *he4=lib->GetMat(20040);

//
// print the info of  MAT=9228
//
u235->What();

// for the total cross section
TNuSec03* stot = u235->GetSection(3001);
TF1 *t235_xtot= stot->GetTF1()->Draw();
//t235_xtot->Draw();

// for the nu_bar
//TF1 *t235_nubar= u235->LoadF1D("nu_bar");
//t235_nubar->Draw();
/*
:::::::::::    Files & Sections Name    :::::::::::::
File:
nu = 1
sig == X = 2

Section:
  tot=  1,   ne=  2,   ni=  4,   2n= 16,   3n= 17, fiss= 18,
   na= 22,  n3a= 23,  2na= 24,  3na= 25,   np= 28,  n2a= 29,
 2n2a= 30,   nd= 32,   nt= 33, n3he= 34, nd2a= 35, nt2a= 36,
   4n= 37,  2np= 41,  3np= 42, ni01= 51, ni02= 52, ni03= 53,
 ni04= 54, ni05= 55, ni06= 56, ni07= 57, ni08= 58, ni09= 59,
 ni10= 60, ni11= 61, ni12= 62, ni13= 63, ni14= 64, ni15= 65,
 ni16= 66, ni17= 67, ni18= 68, ni19= 69, ni20= 70, ni21= 71,
 ni22= 72, ni23= 73, ni24= 74, ni25= 75, ni26= 76, ni27= 77,
 ni28= 78, ni29= 79, ni30= 80, ni31= 81, ni32= 82, ni33= 83,
 ni34= 84, ni35= 85, ni36= 86, ni37= 87, ni38= 88, ni39= 89,
 ni40= 90, nico= 91, capt=102,    p=103,    d=104,    t=105,
  3he=106,    a=107,   2a=108,   3a=109,   2p=111,   pa=112,
  t2a=113,  d2a=114,   pp=115,   pt=116,  bar=452
*/
// access the TF1 by the MFT value, MFT= 1000*MF + MT
//u235->LoadF1D(3001)->Draw();

//TF1 *f=t235_xtot;
}
