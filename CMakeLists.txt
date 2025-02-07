cmake_minimum_required(VERSION 3.14)
project(leetcode)

# 移除手动设置的build type（由命令行参数控制）
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Conan基础集成（重要）
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

add_subdirectory(thirdparty)

# 现代CMake目标链接方式
find_package(GTest REQUIRED CONFIG)  # 使用CONFIG模式查找

# 创建接口库处理公共包含路径
add_library(leetcode_common INTERFACE)
target_include_directories(leetcode_common INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_subdirectory(problems/1_array)
add_subdirectory(problems/2_list)
# 移除 add_subdirectory(include) （头文件目录不需要编译）
