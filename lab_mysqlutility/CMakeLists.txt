cmake_minimum_required(VERSION 2.8)

PROJECT(lab_mysqlutility)

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
	SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -Wall -D_DEBUG -std=c++11")
	SET(CMAKE_CXX_FLAGS_RELEASE "-O0 -g -Wall -std=c++11")
	SET(LINK_LIB_COMMON libmysql.so libmysqlclient.so)
endif(CMAKE_COMPILER_IS_GNUCXX)

# 输出目录
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 子项目
ADD_SUBDIRECTORY(src)
