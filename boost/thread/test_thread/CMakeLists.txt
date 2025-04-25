cmake_minimum_required(VERSION 3.1)
project(test_boost)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3 -pthread" )
message("message: CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS} ")

# if debug
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -O0")

set(Boost_NO_BOOST_CMAKE TRUE)

set(Boost_DIR /usr/local/lib/cmake/Boost-1.70.0)
set(BOOST_LIBRARYDIR /usr/local/lib)

find_package(Boost REQUIRED COMPONENTS system filesystem thread)

if(Boost_FOUND)
    message("message: found boost")
    include_directories(${Boost_INCLUDE_DIRS}) 
    link_directories(test_boost ${Boost_LIBRARY_DIRS})
endif()

add_executable(test_boost test.cpp)
target_link_libraries(test_boost ${Boost_LIBRARIES})
