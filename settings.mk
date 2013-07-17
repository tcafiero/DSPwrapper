ProjName ?= dsp

ifeq "$(EXTENSION)"  "dll"
KIND = -shared
else
KIND =
endif


OPTIMIZATION ?= -O0
DBG ?= -g
GCOVFLAGS ?= -ftest-coverage -fprofile-arcs
OBJS =
GPFLAGS ?= $(DBG) -Wall $(OPTIMIZATION)
GPFLAGS += -I./sharedobjects
GCFLAGS = $(GPFLAGS)

# switches for ruby or java wrapping
#OTHERSSWITCHES ?= -Wl,--enable-auto-image-base,--enable-auto-import,--export-all   -lruby  -lrt -ldl -lcrypt
OTHERSSWITCHES ?= -mno-cygwin -Wl,--add-stdcall-alias



.PHONY: all clean deploy

all:: $(ProjName).$(EXTENSION)

$(ProjName).$(EXTENSION): $(OBJ) $(WRAPPEROBJS) $(SHRDOBJS)
	$(GCC) $(GCOVFLAGS) $(KIND) $(OBJS) $(WRAPPEROBJS) $(SHRDOBJS) $(OTHERSSWITCHES) -o $@
#	$(INSTALL) $(INSTALLSWITCHES) $@ $(INSTALLDIR) 

clean:
	find . -name "*.gcno" -print0 | xargs -0 rm -rf
	find . -name "*.gcda" -print0 | xargs -0 rm -rf
	find . -name "*.o" -print0 | xargs -0 rm -rf
	find . -name "*.exe" -print0 | xargs -0 rm -rf
	find . -name "*.so" -print0 | xargs -0 rm -rf
	find . -name "*.java" -print0 | xargs -0 rm -rf
	find . -name "*.dll" -print0 | xargs -0 rm -rf


%.o : %.cpp
	$(GPP) $(GCOVFLAG) $(GPFLAGS) -c $< -o $@

%.o : %.c
	$(GCC) $(GCOVFLAG) $(GCFLAGS) -c $< -o $@

