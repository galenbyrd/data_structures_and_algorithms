cmake_minimum_required(VERSION 3.8)
project(Project5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MLBHomeruns.cpp MLBHomeruns.h SeparateChaining.h Probing.h)
add_executable(Project5 ${SOURCE_FILES})