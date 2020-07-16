cmake_minimum_required(VERSION 3.15)

project(app1 LANGUAGES CXX)

find_package(GTest REQUIRED)

add_executable(app1 main.cpp)
target_link_libraries(app1 GTest::gtest)
