T1234 = $(wildcard ./sharedobjects/*.c)
SHRDOBJS = $(patsubst %.c,%.o,$(T1234))


