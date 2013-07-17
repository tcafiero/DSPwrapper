ProjName ?= dsp
EXTENSION ?= dll

ifeq "$(EXTENSION)"  "dll"
KIND = -shared
else
KIND =
endif


REMOVE = rm
QUIET=> /dev/null 2>&1 ; exit 0
FixPath = $(subst \,/,$1)


GCC ?= i686-pc-mingw32-gcc
GPP ?= i686-pc-mingw32-g++

OPTIMIZATION ?= -O0
DBG ?= -g
GCOVFLAGS ?= -ftest-coverage -fprofile-arcs
OBJS =
GPFLAGS ?= $(DBG) -Wall $(OPTIMIZATION)
GPFLAGS += -I./sharedobjects
GCFLAGS = $(GPFLAGS)

#OTHERSSWITCHES ?= -Wl,--enable-auto-image-base,--enable-auto-import,--export-all   -lruby  -lrt -ldl -lcrypt
OTHERSSWITCHES ?= -mno-cygwin -Wl,--add-stdcall-alias
#INSTALLDIR ?= /usr/lib/ruby/site_ruby/1.8/i386-cygwin


INSTALL ?= /usr/bin/install
INSTALLSWITCHES ?= -c -m 0755
