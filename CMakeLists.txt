cmake_minimum_required(VERSION 3.10)
project(my_console_util)

set(CMAKE_C_STANDARD 11)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(my_console_util ${SOURCES})
