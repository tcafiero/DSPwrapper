ProjName ?= dsp


OPTIMIZATION ?= -O0
DBG ?= -g
#GCOVFLAGS ?= -ftest-coverage -fprofile-arcs
GCOVFLAGS ?= 
OBJS =
GPFLAGS ?= $(DBG) -Wall $(OPTIMIZATION) $(EXTRA_GPFLAGS)
GPFLAGS += $(call FixPath,-I./sharedobjects)
GCFLAGS = $(GPFLAGS)
INSTALL ?= /usr/bin/install
INSTALLSWITCHES ?= -c -m 0755




.PHONY: all clean deploy

all:: $(COMPONENTLIB) $(WRAPPERLIB)

#	$(INSTALL) $(INSTALLSWITCHES) $@ $(INSTALLDIR) 

$(COMPONENTLIB): $(SHRDOBJS)
	$(LD) $(LD_FLAGS) $(GCOVFLAGS) $(KIND) $(SHRDOBJS) $(OTHERSSWITCHES) $(EXTRA_GPFLAGS) -o $@

$(WRAPPERLIB): $(WRAPPEROBJS) $(COMPONENTLIB)
	$(LD) $(LD_FLAGS) $(GCOVFLAGS) $(KIND) $(WRAPPEROBJS) $(SHRDOBJS) $(OTHERSSWITCHES) $(EXTRA_GPFLAGS) -o $@



clean:
	find . -name "*.gcno" -print0 | xargs -0 rm -rf
	find . -name "*.gcda" -print0 | xargs -0 rm -rf
	find . -name "*.o" -print0 | xargs -0 rm -rf
	find . -name "*.exe" -print0 | xargs -0 rm -rf
	find . -name "*.so" -print0 | xargs -0 rm -rf
	find . -name "*.java" -print0 | xargs -0 rm -rf
	find . -name "*.class" -print0 | xargs -0 rm -rf
	find . -name "*.dll" -print0 | xargs -0 rm -rf
	find . -name "*_wrap.c" -print0 | xargs -0 rm -rf

%.o : %.cpp
	$(GPP) $(GCOVFLAG) $(GPFLAGS) $(OTHERSSWITCHES) -c $< -o $@

%.o : %.c
	$(GCC) $(GCOVFLAG) $(GCFLAGS) $(OTHERSSWITCHES) -c $< -o $@

