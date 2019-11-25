
@echo off
mkdir ~ninja-build
cd ~ninja-build
cmake ../src/ -G Ninja -DCMAKE_TOOLCHAIN_FILE=F:\vcpkg\scripts\buildsystems\vcpkg.cmake 
cmake --build . --config Release
REM CTest  -C Release --verbose
REM Release\commands_test.exe
