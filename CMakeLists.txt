cmake_minimum_required(VERSION 3.24)
project(TareaCortaED)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TareaCortaED
        main.cpp
        menu.cpp
        procedimientos.cpp
        prototipos.h estructuras.h)
