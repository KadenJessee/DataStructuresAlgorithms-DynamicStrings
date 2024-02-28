cmake_minimum_required(VERSION 3.14)
project(dynamic_strings)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(inc)

add_executable(dynamic_strings
        inc/DynamicString.h
        src/DynamicString.cpp
        src/DynamicStringTest.cpp src/URLTesting.cpp src/Url.cpp)
