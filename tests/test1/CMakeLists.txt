cmake_minimum_required(VERSION 3.15)

project(test1 LANGUAGES CXX)

find_package(GTest REQUIRED)

add_executable(test1 main.cpp)
target_link_libraries(test1 GTest::gtest)
add_test(NAME test1 COMMAND test1)
