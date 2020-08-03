make_minimum_required(VERSION 3.0.0)

set(CMAKE_BUILD_TYPE Release)

project(DateTime VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CPUARCH x64)
else()
    set(CPUARCH x32)
endif()

if(WIN32)
    set(OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/windows/${CPUARCH}")
elseif(APPLE)
    set(OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/macos/${CPUARCH}")
else()
    set(OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/linux/${CPUARCH}")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})

file(GLOB_RECURSE SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(datetime STATIC ${SRC})

target_include_directories(datetime PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_compile_features(datetime
    PRIVATE
    cxx_attributes
    cxx_defaulted_functions
    cxx_deleted_functions
    cxx_final
)

install(TARGETS datetime
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
)