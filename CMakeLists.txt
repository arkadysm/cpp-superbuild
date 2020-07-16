cmake_minimum_required(VERSION 3.15)

project(solution LANGUAGES NONE)

include(cmake/SolutionSettings.cmake)
include(ExternalProject)

get_filename_component(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/.." ABSOLUTE)

ExternalProject_Add(external
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external"
    INSTALL_COMMAND ""
    BUILD_ALWAYS TRUE
    CMAKE_ARGS          
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
)

ExternalProject_Add(solution_projects
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src"
    INSTALL_COMMAND ""
    BUILD_ALWAYS TRUE
    CMAKE_ARGS          
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
)

ExternalProject_Add(solution_tests
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests"
    INSTALL_COMMAND ""
    BUILD_ALWAYS TRUE
    CMAKE_ARGS          
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
)

ExternalProject_Add_StepDependencies(solution_tests configure solution_projects)
ExternalProject_Add_StepDependencies(solution_projects configure external)
ExternalProject_Get_Property(external source_dir binary_dir)

enable_testing()
add_test(NAME test COMMAND ${CMAKE_COMMAND} -C "${binary_dir}" test)
