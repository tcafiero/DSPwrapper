ifdef CYGWIN_SIMULATOR
SHELL = c:/cygwin/bin/sh.exe
#include ./ARMlinux.mk ./sharedobjects/makefile.mk ./src/wrappers/makefile.mk ./settings.mk 
include ./cygwin.mk ./sharedobjects/makefile.mk ./src/wrappers/makefile.mk ./settings.mk 
else
include $(GCC4MBED_DIR)/build/gcc4mbed.mk
endif

