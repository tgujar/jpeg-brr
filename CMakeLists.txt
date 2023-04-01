cmake_minimum_required(VERSION 3.21)
project(jpeg_brr)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(jpeg_brr
        main.cpp
        ppm.cpp)
