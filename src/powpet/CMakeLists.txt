cmake_minimum_required(VERSION 3.5)

project(powpet LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(powpet STATIC
  powpet.cpp
  powpet.h
)

target_compile_definitions(powpet PRIVATE POWPET_LIBRARY)
