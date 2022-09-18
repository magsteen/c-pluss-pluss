cmake_minimum_required(VERSION 3.1)

project(3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(3 main.cpp commodity.hpp commodity.cpp)
