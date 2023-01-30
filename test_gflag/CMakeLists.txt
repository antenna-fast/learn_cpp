project(test_gflag)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)

set(GFLAGS_LIBRARIES /usr/lib/x86_64-linux-gnu/libgflags.so)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
find_package(Gflags)
# find_package(Glog)
include_directories(${GFLAGS_INCLUDE_DIRS} ${GLOG_INCLUDE_DIRS})

add_executable(test_gflag
                test.cpp
)

target_link_libraries(test_gflag ${GFLAGS_LIBRARIES}) 
