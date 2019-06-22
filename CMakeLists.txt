cmake_minimum_required(VERSION 3.13)
project(group_27)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(group_27
        Card.cpp
        Card.hpp
        GameEngine.cpp
        GameEngine.hpp
        main.cpp)
