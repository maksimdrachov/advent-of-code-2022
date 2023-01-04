cmake_minimum_required(VERSION 3.24)
project(day_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(day_2 main.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
