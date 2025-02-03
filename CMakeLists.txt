cmake_minimum_required(VERSION 3.28)
project(McDonalds_Ordering_System)

set(CMAKE_CXX_STANDARD 17)

include_directories(./EasyX/include)
link_directories(./EasyX/lib64)
link_libraries(libeasyx.a)

add_executable(McDonalds_Ordering_System main.cpp)
