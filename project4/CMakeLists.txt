cmake_minimum_required(VERSION 3.8)
project(Project4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MLBHomeruns.cpp MLBHomeruns.h SortingAlgorithms.h)
add_executable(Project4 ${SOURCE_FILES})