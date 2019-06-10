cmake_minimum_required(VERSION 2.8)

PROJECT(lab_fastdb)

# 将源文件分组归类的方法
function(group_by_dir src_dir)
    if(MSVC)
        foreach(FILE ${ARGN})
            # 获取文件绝对路径
            get_filename_component(FULL_NAME "${FILE}" ABSOLUTE)
            # 获取文件父路径
            get_filename_component(PARENT_DIR "${FULL_NAME}" PATH)
            # 移除父路径中的源码根路径
            string(REPLACE "${ARGV0}" "" GROUP "${PARENT_DIR}")
            # 确保路径使用windows路径符号
            string(REPLACE "/" "\\" GROUP "${GROUP}")
            source_group("${GROUP}" FILES "${FILE}")
        endforeach()
    endif(MSVC)
endfunction(group_by_dir)

# VS设定
if (MSVC)
	ADD_DEFINITIONS(/W3 /wd"4819" /wd"4091" /wd"4996")
	SET(LINK_LIB_COMMON libmysql.dll)
endif(MSVC)

# Linux设定
if (CMAKE_COMPILER_IS_GNUCXX)
        SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -Wall -D_DEBUG -std=c++11 -fpermissive")
	    SET(CMAKE_CXX_FLAGS_RELEASE "-O0 -g -Wall -std=c++11")
	    SET(LINK_LIB_COMMON libmysql.so libmysqlclient.so)
endif(CMAKE_COMPILER_IS_GNUCXX)

INCLUDE_DIRECTORIES(.)

FILE(GLOB_RECURSE FASTDB_FILES "./fastdb/*.cpp" "./fastdb/*.h")
FILE(GLOB_RECURSE SRC_FILES "./src/*.cpp" "./src/*.h")
FILE(GLOB_RECURSE TABLEDEF_FILES "./tabledef/*.cpp" "./tabledef/*.h")

group_by_dir(${PROJECT_SOURCE_DIR} ${FASTDB_FILES})
group_by_dir(${PROJECT_SOURCE_DIR} ${SRC_FILES})

ADD_EXECUTABLE(lab_fastdb_${CMAKE_BUILD_TYPE} ${FASTDB_FILES} ${SRC_FILES})

target_link_libraries(lab_fastdb_${CMAKE_BUILD_TYPE} pthread)
