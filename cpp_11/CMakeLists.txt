project(cpp_11)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3 -pthread" )

add_executable(
        cpp_11
        # test_right_ref.cpp
        # test_ptr.cpp
        # test_for.cpp
        test_lambda.cpp
        # test_thread.cpp
        # test_async.cpp
)