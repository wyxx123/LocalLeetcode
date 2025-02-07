@echo off
if not exist build mkdir build
cd build

cmake .. -G "MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release

cmake --build . --config Release

cd ..
