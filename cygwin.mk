GCC ?= i686-pc-mingw32-gcc
GPP ?= i686-pc-mingw32-g++
EXTENSION ?= dll

REMOVE = rm
QUIET=> /dev/null 2>&1 ; exit 0
FixPath = $(subst \,/,$1)

#INSTALLDIR ?= /usr/lib/ruby/site_ruby/1.8/i386-cygwin
INSTALL ?= /usr/bin/install
INSTALLSWITCHES ?= -c -m 0755

