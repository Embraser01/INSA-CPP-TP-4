cmake_minimum_required(VERSION 3.6.2)
project(TP4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB SOURCE_FILES
        "src/*.h"
        "src/*.cpp"
        )
add_executable(TP4 ${SOURCE_FILES})