@echo off
if not exist build mkdir build
conan install . --output-folder=build --build=missing
cd build

cmake .. -G "MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release

cmake --build . --config Release

cd ..
