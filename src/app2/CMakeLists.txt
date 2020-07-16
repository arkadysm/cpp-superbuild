cmake_minimum_required(VERSION 3.15)

project(app2 LANGUAGES C)

find_package(GTest REQUIRED)

add_executable(app2 main.c)
target_link_libraries(app2 GTest::gtest)
