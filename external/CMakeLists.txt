cmake_minimum_required(VERSION 3.15)

project(external LANGUAGES NONE)

include(../cmake/SolutionSettings.cmake)
include(ExternalProject)

list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}")

set(EXTERNAL_COMMON_ARGS
    -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
    -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
    -DCMAKE_VERBOSE_MAKEFILE:BOOL=${CMAKE_VERBOSE_MAKEFILE}
)

ExternalProject_Add(googletest
    URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
    DOWNLOAD_NO_PROGRESS TRUE
    TIMEOUT 10
    CMAKE_ARGS
        ${EXTERNAL_COMMON_ARGS}
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_GMOCK=0
)
