cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(PROJECT_NAME_STR Bencode)
project(${PROJECT_NAME_STR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -O2")

enable_testing()

add_subdirectory(test)

add_library(bencode STATIC
        benstring.cpp
        dictionary.cpp
        element.cpp
        integer.cpp
        keyvaluepair.cpp
        list.cpp
        parser.cpp
        exception.cpp)
