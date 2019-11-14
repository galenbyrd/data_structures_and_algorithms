cmake_minimum_required(VERSION 3.8)
project(Project3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MLBHomeruns.cpp MLBHomeruns.h BinarySearchTree.h dsexceptions.h AVLTree.h SplayTree.h)
add_executable(Project3 ${SOURCE_FILES})