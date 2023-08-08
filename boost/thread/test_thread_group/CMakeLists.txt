cmake_minimum_required(VERSION 3.1)
project(test_thread_group)

add_definitions(-std=c++11)

include_directories("/usr/local/include")
link_directories("/usr/local/lib")

file( GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
foreach( sourcefile ${APP_SOURCES} )
    file(RELATIVE_PATH filename ${CMAKE_CURRENT_SOURCE_DIR} ${sourcefile})
    string(REPLACE ".cpp" "" file ${filename})
    add_executable(${file} ${sourcefile})
    target_link_libraries(${file} boost_filesystem boost_thread boost_system boost_serialization pthread boost_chrono)
endforeach( sourcefile ${APP_SOURCES} )
