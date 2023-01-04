cmake_minimum_required(VERSION 3.24)
project(day_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(day_1 main.cpp)

# https://stackoverflow.com/questions/46995733/how-to-set-cmake-in-order-to-add-txt-files-into-working-directory-as-resource
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})