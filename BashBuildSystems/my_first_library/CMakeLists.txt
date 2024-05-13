cmake_minimum_required(VERSION 3.29)
project(my_first_library)

set(CMAKE_CXX_STANDARD 17) # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(tools tools.cpp)
add_executable(main main.cpp)
target_link_libraries(main tools)