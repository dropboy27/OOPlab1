cmake_minimum_required(VERSION 3.16)
project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(str_ops STATIC str_ops.cpp)
add_executable(lab1_app main.cpp)
target_link_libraries(lab1_app PRIVATE str_ops)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests tests.cpp)
target_link_libraries(run_tests PRIVATE str_ops gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)