cmake_minimum_required(VERSION 3.1)

project(test_h_file)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")

message("message:" ${PROJECT_SOURCE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)
# set(SRC src/b.cpp)

file(GLOB_RECURSE SRC src/*.cpp)

add_executable(test_h_file ${SRC})

