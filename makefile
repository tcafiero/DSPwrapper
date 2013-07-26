SHELL = c:/cygwin/bin/sh.exe

ifdef CYGWIN_SIMULATOR
include ./cygwin.mk ./sharedobjects/makefile.mk ./src/wrappers/makefile.mk ./settings.mk 
else
include ./ARMlinux.mk ./sharedobjects/makefile.mk ./src/wrappers/makefile.mk ./settings.mk 
endif

