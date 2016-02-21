cmake_minimum_required(VERSION 3.3)
project(meeting4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    SamiString.cpp
    SamiString.h
    string_test.cc)

add_executable(meeting4 ${SOURCE_FILES})