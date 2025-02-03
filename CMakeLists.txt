cmake_minimum_required(VERSION 3.28)
project(multfiletest2)

set(CMAKE_CXX_STANDARD 17)

add_executable(multfiletest2 main.cpp
        file1.cpp
        file1.h
        file1.cpp)
