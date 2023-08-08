cmake_minimum_required (VERSION 3.16)
project (test_glog VERSION 1.0)

find_package (glog REQUIRED)

add_executable (test_glog 
                test.cpp
                )

target_link_libraries (test_glog 
                    glog::glog
                    )
