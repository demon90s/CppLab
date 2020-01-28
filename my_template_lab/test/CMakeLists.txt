cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(test_template_lib)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/../library)
set(LINK_DIR ${PROJECT_SOURCE_DIR}/lib)
set(LIBS gtest pthread)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

include_directories(${INCLUDE_DIR})

link_directories(${LINK_DIR})

file(GLOB_RECURSE SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}../library/*.h*)

add_executable(main ${SRC_FILES})

target_link_libraries(main ${LIBS})