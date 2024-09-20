project(test_shared_ptr)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3 -pthread" )


find_package(Boost REQUIRED COMPONENTS system filesystem)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(test_shared_ptr test_shared_ptr.cpp)
    link_directories(test_shared_ptr ${Boost_LIBRARY_DIRS})
    target_link_libraries(test_shared_ptr ${Boost_LIBRARIES})
endif()