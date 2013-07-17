T1234 = $(wildcard ./sharedobjects/*.c)
SHRDOBJS = $(patsubst %.c,%.o,$(T1234))



%.o : %.cpp
	$(GPP) $(GCOVFLAG) $(GPFLAGS) -c $< -o $@

%.o : %.c
	$(GCC) $(GCOVFLAG) $(GCFLAGS) -c $< -o $@
