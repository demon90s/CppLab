INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/library)

FILE(GLOB_RECURSE SRC_FILES "./*.cpp" "./*.h")
source_group(src FILES ${SRC_FILES})

ADD_EXECUTABLE(lab_library_test ${SRC_FILES})

set_target_properties(lab_library_test
    PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON)

TARGET_LINK_LIBRARIES(lab_library_test ${LINK_LIB_COMMON})
