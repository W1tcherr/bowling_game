cmake_minimum_required(VERSION 3.2)
project(bowling)

set(CMAKE_CXX_STANDARD 14)

link_directories(lib)

add_executable(bowling
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
)