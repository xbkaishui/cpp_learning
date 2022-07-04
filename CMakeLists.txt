cmake_minimum_required(VERSION 3.16)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 17)

include_directories("/usr/include/eigen3")

add_executable(cpp_learning main.cpp)