INCLUDE_DIRECTORIES(.)

FILE(GLOB_RECURSE SRC_FILES "./*.cpp" "./*.h*")
group_by_dir(${PROJECT_SOURCE_DIR} ${SRC_FILES})

ADD_LIBRARY(lab_library STATIC ${SRC_FILES})

set_target_properties(lab_library
    PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON)
