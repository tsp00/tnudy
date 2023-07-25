# Makefile for the TNudy project.
# This has been developed based on the $(ROOTSYS)/test/Makefile.
#
# Author: Tae-Sun Park, 12/6/2014

RC     := root-config
ifeq ($(shell which $(RC) 2>&1 | sed -ne "s@.*/$(RC)@$(RC)@p"),$(RC))
MKARCH := $(wildcard $(shell $(RC) --etcdir)/Makefile.arch)
RCONFIG := $(wildcard $(shell $(RC) --incdir)/RConfigure.h)
endif

ifneq ($(MKARCH),)
include $(MKARCH)
else
ifeq ($(ROOTSYS),)
ROOTSYS = ..
endif
include $(ROOTSYS)/etc/Makefile.arch
endif

ifeq ($(ROOTCINT),)
ROOTCINT = rootcint
endif

#RLIBMAP = $(ROOTSYS)/bin/rlibmap
RLIBMAP = rlibmap

#-include ../MyConfig.mk

#------------------------------------------------------------------------------

MyName  = Nudy

#MyDir = $(HOME)/nudy
MyDir := $(CURDIR)

MySrcDir := ${MyDir}/src
MyIncDir := ${MyDir}/inc
MyLibDir := $(MyDir)/lib

MyInc     := $(filter-out $(MyIncDir)/Link%,$(wildcard $(MyIncDir)/*.h))
MySrc     := $(filter-out $(MySrcDir)/G__%,$(wildcard $(MySrcDir)/*.cxx))
MyObj     := $(MySrc:.cxx=.o)

MyDict := $(MySrcDir)/G__$(MyName)
MyLinkDef := $(MyIncDir)/LinkDef.h
MyPCM := $(MySrcDir)/G__$(MyName)_rdict.pcm

MySrc += $(MyDict).$(SrcSuf)
MyObj += $(MyDict).$(ObjSuf)

MyLib = $(MyLibDir)/lib$(MyName).$(DllSuf)
MyMap = $(MyLibDir)/lib$(MyName).rootmap

PROGRAMS      = $(MyCode) $(MyLib) $(MyMap)

ifeq ($(ARCH),aix5)
MAKESHARED    = /usr/vacpp/bin/makeC++SharedLib
endif

#------------------------------------------------------------------------------

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf)
.PHONY:    

#all:            $(PROGRAMS)

all:            install

CXXOUT ?= -o 
MAKEDEP = ${ROOTSYS}/bin/rmkdepend  

CXXFLAGS += -I$(MyIncDir)

ifeq ($(EXPLLINKLIBS),)
EXPLLINKLIBS = $(ROOTGLIBS)
endif


%.o: %.cxx
	$(MAKEDEP) -R -f$*.d -Y -w 1000 -- $(CXXFLAGS) -D__cplusplus -- $<
	$(CXX) $(OPT) $(CXXFLAGS) $(CXXOUT)$@ -c $<

$(MyLib):     $(MyObj)
	mkdir -p $(MyLibDir)
ifeq ($(ARCH),aix5)
		$(MAKESHARED) $(OutPutOpt) $@ $(LIBS) -p 0 $^
else
ifeq ($(PLATFORM),macosx)
# We need to make both the .dylib and the .so
		#$(LD) $(SOFLAGS)$@ $(LDFLAGS) $^ $(OutPutOpt) $@ $(EXPLLINKLIBS)
	$(LD) $(SOFLAGS)$@ $(LDFLAGS) $^ $(OutPutOpt) $@ $(EXPLLINKLIBS)
ifneq ($(subst $(MACOSX_MINOR),,1234),1234)
ifeq ($(MACOSX_MINOR),4)
		ln -sf $@ $(subst .$(DllSuf),.so,$@)
endif
endif
else
ifeq ($(PLATFORM),win32)
		bindexplib $* $^ > $*.def
		lib -nologo -MACHINE:IX86 $^ -def:$*.def \
		   $(OutPutOpt)$(MyLib)
		$(LD) $(SOFLAGS) $(LDFLAGS) $^ $*.exp $(LIBS) \
		   $(OutPutOpt)$@
		$(MT_DLL)
else
		@echo "EXPLLINKLIBS = $(EXPLLINKLIBS)"
		$(LD) $(SOFLAGS) $(LDFLAGS) $^ $(OutPutOpt) $@ $(EXPLLINKLIBS)
endif
endif
endif
		@echo "$@ done"

$(MyLibDir):
	@echo "Creating library directory $(MyLibDir) ..."
	mkdir -p $(MyLibDir)

$(MyCode):       $(MyLib) $(MyMap)
		$(LD) $(LDFLAGS) $(MyObj) $(LIBS) $(OutPutOpt)$@
		$(MT_EXE)
		cp $(MySrcDir)/G__$(MyName)_rdict.pcm $(MyLibDir)
		@echo "$@ done"


install: $(MyLib) $(MyMap) $(MyInc)
		cp $(MyLib) $(ROOTSYS)/lib
		cp $(MyMap) $(ROOTSYS)/lib
		cp $(MySrcDir)/G__$(MyName)_rdict.pcm $(MyLibDir)
ifneq ($(wildcard $(MyPCM)),)
	cp $(MyPCM) $(MyLibDir)
endif
		@echo "done"

clean:
		@rm -f $(MyObj) $(PROGRAMS) core $(MySrcDir)/*Dict.* $(MySrcDir)/G__* $(MySrcDir)/*.d $(MyLibDir)/*.so $(MyLibDir)/*.lib $(MyLibDir)/*.rootmap $(MyLibDir)/G__* $(ROOTSYS)/lib/lib$(MyName).$(DllSuf) $(ROOTSYS)/lib/lib$(MyName).rootmap


.SUFFIXES: .$(SrcSuf)

#=================================  rootcint (ROOT v5) vs rootcling (ROOT v6)
ifeq ($(ROOTCLING),)
#---------------------   ROOT v5

$(MyMap):  $(MAKEFILEDEP) $(MyLinkDef)
	@echo "Generating map $@ ..."
		$(RLIBMAP) -o $(MyMap) -l $(MyLib) \
		   -d $(MyLIBDEPM) -c $(MyLinkDef)

$(MyDict).$(SrcSuf): $(MyInc) $(MyLinkDef)
	@echo "Generating dictionary $@ using rootcint ..."
	$(ROOTCINT) -f $@ -c $^
else
#---------------------   ROOT v6

$(MyDict).$(SrcSuf): $(MyInc) $(MyLinkDef)
	@echo "Generating dictionary $@ using rootcling ..."
	$(ROOTCLING) -f $@ -rml $(MyLib) -rmf $(MyMap) $^
endif
