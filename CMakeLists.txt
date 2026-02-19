cmake_minimum_required(VERSION 3.31)
project(rodne_cislo)

set(CMAKE_CXX_STANDARD 20)

add_executable(rodne_cislo main.cpp
        rc.cpp
        rc.h)
