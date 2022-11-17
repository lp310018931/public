
# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required (VERSION 2.8.7)

#set (CMAKE_C_COMPILER "/usr/local/gcc/bin/gcc")
set (CMAKE_CXX_COMPILER "/usr/bin/g++")
#set (CMAKE_CXX_COMPILER "arm-none-linux-gnueabihf-gcc")

#SET(CMAKE_CXX_FLAGS "-std=c++11 -pthread -g")

# Set the project name
project (AUTOSAR_AP)

# 设置boost头文件与lib的目录，分别命名为BOOST_INCLUDE_DIR和BOOST_LIB_DIR供后续使用
#set(BOOST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/include)
#set(BOOST_LIB_DIR ${PROJECT_SOURCE_DIR}/lib/lib/boost)

# 设置依赖库头文件与lib的目录
#set(VSOMEIP_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/include)
#set(VSOMEIP_LIB_DIR ${PROJECT_SOURCE_DIR}/lib/lib/)

# 设置输出的可执行文件的目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# 导入项目内定义的头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 导入boost的头文件
#include_directories(${BOOST_INCLUDE_DIR})

# 链接boost到项目中
#link_directories(${BOOST_LIB_DIR})

# 导入VSomeip的头文件
#include_directories(${VSOMEIP_INCLUDE_DIR})

# 链接VSomeip到项目中
#link_directories(${VSOMEIP_LIB_DIR})

# 添加子文件夹。这样运行当前CMakeLists.txt时，也会运行子文件夹的CMakeLists.txt文件
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
