cmake_minimum_required (VERSION 3.16)
project (test_glog VERSION 1.0)

find_package (glog REQUIRED)

add_executable (myapp main.cpp)
target_link_libraries (myapp glog::glog)
