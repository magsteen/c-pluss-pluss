cmake_minimum_required(VERSION 3.1)

project(7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(1 1.cpp fraction.cpp)
add_executable(2 2.cpp set.cpp)
