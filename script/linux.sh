rm ./~build

mkdir ~build 
cd ~build 
cmake ../src/ -G  "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build . --config Release

