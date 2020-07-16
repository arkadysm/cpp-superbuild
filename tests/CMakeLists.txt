cmake_minimum_required(VERSION 3.15)

project(tests LANGUAGES NONE)

include(../cmake/SolutionSettings.cmake)

list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_INSTALL_PREFIX}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_INSTALL_PREFIX}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_INSTALL_PREFIX}/lib")

enable_testing()

add_subdirectory(test1)
add_subdirectory(test2)
