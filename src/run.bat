
rd /s /q build
rd /s /q bin
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
make
cd ..
.\bin\test.exe
