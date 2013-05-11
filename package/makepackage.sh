#!/bin/bash
rm -v -f ./package.7z
/cygdrive/c/HolisticSystems/tools/7za.exe a -t7z ./package.7z ../src/framework/*.h ../src/framework/*.c ../src/models/*.c ../src/models/*.h ../src/prototypes/*.h
