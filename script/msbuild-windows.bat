
@echo off
mkdir ~msbuild 
cd ~msbuild 
cmake ../src/ -DCMAKE_TOOLCHAIN_FILE=F:\vcpkg\scripts\buildsystems\vcpkg.cmake  -DVCPKG_TARGET_TRIPLET=x64-windows -DCMAKE_INSTALL_PREFIX=F:\on-semi\release -G "Visual Studio 16 2019" -A x64
REM cmake --build . --config Release
cmake --build . --config Release --target install 

cd ..

REM CTest  -C Release --verbose
REM Release\commands_test.exe
