cmake_minimum_required(VERSION 3.7)
project(server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(server main.cpp data.h Server.h Server.cpp)
