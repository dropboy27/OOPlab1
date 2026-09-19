cmake_minimum_required(VERSION 3.2)
project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(str_ops STATIC str_ops.cpp)

add_executable(lab1_app main.cpp)
target_link_libraries(lab1_app PRIVATE str_ops)