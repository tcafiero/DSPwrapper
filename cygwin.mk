.PHONY: all clean deploy


all:: $(ProjName).$(EXTENSION)

$(ProjName).$(EXTENSION): $(OBJ) $(WRAPPEROBJS) $(SHRDOBJS)
	$(GCC) $(GCOVFLAGS) $(KIND) $(OBJS) $(WRAPPEROBJS) $(SHRDOBJS) $(OTHERSSWITCHES) -o $@
#	$(INSTALL) $(INSTALLSWITCHES) $@ $(INSTALLDIR) 


clean:
	$(REMOVE) -f $(call FixPath,$(SWIG_OUTPUT)) $(QUIET)
	$(REMOVE) -f $(call FixPath,$(CODEGEN_OUTPUT)) $(QUIET)
	$(REMOVE) -f $(call FixPath,$(SWIGOBJECTS)) $(QUIET)
	$(REMOVE) -f $(call FixPath,$(SHAREDOBJECTS)) $(QUIET)
	$(REMOVE) -f $(call FixPath,$(OBJECTS)) $(QUIET)
	$(REMOVE) -f $(call FixPath,$(DEPFILES)) $(QUIET)
	$(REMOVE) -f main.o $(QUIET)
	$(REMOVE) -f $(PROJECT).o $(QUIET)
	$(REMOVE) -f $(PROJECT).exe $(QUIET)
	$(REMOVE) -f $(PROJECT).so $(QUIET)
	find . -name "*.gcno" -print0 | xargs -0 rm -rf
	find . -name "*.gcda" -print0 | xargs -0 rm -rf
	find . -name "*.o" -print0 | xargs -0 rm -rf
	find . -name "*.exe" -print0 | xargs -0 rm -rf
	find . -name "*.so" -print0 | xargs -0 rm -rf
	find . -name "*.java" -print0 | xargs -0 rm -rf
	find . -name "*.dll" -print0 | xargs -0 rm -rf

