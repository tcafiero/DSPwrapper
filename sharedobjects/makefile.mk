COMPONENT = dirana
COMPONENTLIB = $(LIB_PREFIX)$(COMPONENT).$(LIB_SUFFIX)
T1234 = $(wildcard ./sharedobjects/*.c)
SHRDOBJS = $(patsubst %.c,%.o,$(T1234))

