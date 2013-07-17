T432 = $(wildcard ./src/wrappers/*.i)
WRAPPEROBJS = $(patsubst %.i,%_wrap.o,$(T432))
SWIGINCLUDE ?= -I/cygdrive/c/Programmi/Java/jdk1.6.0_22/include/ -I/cygdrive/c/Programmi/Java/jdk1.6.0_22/include/win32
#SWIGINCLUDE ?= -I/usr/lib/ruby/1.8/i386-cygwin
SWIGFLAGS ?= -java
#SWIGFLAGS ?= -ruby
SHAREDINCLUDE ?= -I./sharedobjects



%_wrap.o	: %.i
	swig $(SWIGFLAGS) $<
	$(GCC) $(GCOVFLAG) $(DBG) -Wall $(OPTIMIZATION) -pipe -fno-strict-aliasing $(TESTFLAG) $(SWIGINCLUDE) $(SHAREDINCLUDE) -c $(basename $<)_wrap.c -o $@
