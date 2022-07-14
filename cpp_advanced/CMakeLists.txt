project(cpp_advanced)
cmake_minimum_required(VERSION 3.16)

# set(CMAKE_CXX_STANDARD 14)

# 设置编译选项
# 允许c++11标准、O3优化、多线程。match选项可避免一些cpu上的问题
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread" )

#设定可执行二进制文件的目录
# SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

#设定存放编译出来的库文件的目录
SET( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 

find_package (Threads REQUIRED)

#设定头文件目录
# INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/include

add_executable(cpp_advanced
#        test_file_and_stream.cpp
#        test_dynamic_memory.cpp
#        test_namespace.cpp
#        test_templete.cpp
#        test_pre_process.cpp
        # test_signal.cpp
        test_multi_thread.cpp
        )
