cmake_minimum_required(VERSION 3.16)
project(test_boost)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost REQUIRED COMPONENTS system filesystem)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(test_boost test_copy.cpp)
    link_directories(test_boost ${Boost_LIBRARY_DIRS})
    target_link_libraries(test_boost ${Boost_LIBRARIES})
endif()
