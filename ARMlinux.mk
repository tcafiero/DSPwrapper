TOOL_PREFIX ?= arm-none-linux-gnueabi
GCC = $(TOOL_PREFIX)-gcc
GPP = $(TOOL_PREFIX)-g++
LD = $(TOOL_PREFIX)-gcc
KIND = -shared
OS_TARGET = linux
LIB_PREFIX = lib
LIB_SUFFIX = so


SWIGINCLUDE ?= $(call FixPath,-I$(JDK_PATH)/include -I$(JDK_PATH)/include/$(OS_TARGET))
#SWIGINCLUDE ?= -I/usr/lib/ruby/1.8/i386-cygwin
SWIGFLAGS ?= -java
#SWIGFLAGS ?= -ruby

JDK_PATH ?= .
#JDK_PATH ?= /cygdrive/c/Programmi/Java/jdk1.7.0_25

# switches for ruby or java wrapping
#OTHERSSWITCHES ?= -Wl,--enable-auto-image-base,--enable-auto-import,--export-all   -lruby  -lrt -ldl -lcrypt
OTHERSSWITCHES ?= 
#OTHERSSWITCHES ?= -G
#OTHERSSWITCHES ?= -lc -lgcc

LD_FLAGS ?= -mtls-dialect=gnu -nodefaultlibs -nostdlib -shared-libgcc -Wl,-nostdlib -Wl,-call_shared -Wl,--dynamic-linker=/etc/libc/lib/ld-linux.so.3

REMOVE = rm
QUIET=> /dev/null 2>&1 ; exit 0
#FixPath = $1
FixPath = $(subst /,\\,$(subst /cygwin/usr/bin,/cygwin/bin,$(subst /cygdrive/c,C:,$1)))

#INSTALLDIR ?= /usr/lib/ruby/site_ruby/1.8/i386-cygwin
