cmake_minimum_required(VERSION 3.28)
project(multfiletest)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        multfiletest main.cpp
        testa.cpp
        testb.cpp
        testc.h
        testc.cpp)
