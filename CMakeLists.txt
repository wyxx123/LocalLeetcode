cmake_minimum_required(VERSION 3.14)
project(leetcode)

# 移除手动设置的build type（由命令行参数控制）
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Conan基础集成
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# 现代CMake目标链接方式
find_package(GTest REQUIRED CONFIG)  # 使用CONFIG模式查找

# 创建接口库处理公共包含路径
add_library(leetcode_common INTERFACE)
target_include_directories(leetcode_common INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

file(GLOB_RECURSE SRC_FILES "problems/**/*.cpp")

# 启用测试
enable_testing()

# 遍历所有可执行文件
foreach(SRC_FILE ${SRC_FILES})
    # 获取子文件夹名和文件名并拼接（例如: 1_array/problem_1.cpp -> 1_array/problem_1）
    get_filename_component(SRC_DIR ${SRC_FILE} DIRECTORY)
    get_filename_component(SRC_DIR ${SRC_DIR} NAME)
    get_filename_component(FILE_NAME ${SRC_FILE} NAME_WE)
    
    set(EXEC_NAME "${SRC_DIR}-${FILE_NAME}")
    # 拼接子文件夹名和文件名作为可执行目标名
    string(REPLACE "/" "_" EXEC_NAME "${EXEC_NAME}")
    string(REPLACE "." "" EXEC_NAME "${EXEC_NAME}")
    string(REPLACE ":" "" EXEC_NAME "${EXEC_NAME}")

    # 创建可执行文件
    add_executable(${EXEC_NAME} ${SRC_FILE})

    # 添加测试目标
    add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME})

    # 如果需要链接到 gtest 或其他库，可以使用 target_link_libraries
    target_link_libraries(${EXEC_NAME} leetcode_common gtest::gtest)
endforeach()


# 清理不需要文件
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMENT "Cleaning build directory"
)
