DSP_IMP_TEMPLATE = ll_DSPimplementation
DSP_IMP_TEMPLATE_LIB = $(LIB_PREFIX)$(DSP_IMP_TEMPLATE).$(LIB_SUFFIX)
T1234 = $(wildcard ./sharedobjects/*.c)
SHRDOBJS = $(patsubst %.c,%.o,$(T1234))

ll_%.o : ll_%.c
	$(GCC) $(GCOVFLAG) $(GCFLAGS) $(OTHERSSWITCHES) -c $< -o $(basename $<).o
	$(LD) $(LD_FLAGS) $(GCOVFLAGS) $(KIND) $(basename $@).o $(OTHERSSWITCHES) $(EXTRA_GPFLAGS) -o $(basename $<).$(LIB_SUFFIX)
	@echo NOTICE
	@echo NOTICE
	@echo NOTICE remember to copy $(basename $<).so into sysroot/usr/lib or sysroot/lib on the target system
	@echo NOTICE example for RaspberryPI cp $(basename $<).so /usr/lib/
	@echo NOTICE
	@echo NOTICE
