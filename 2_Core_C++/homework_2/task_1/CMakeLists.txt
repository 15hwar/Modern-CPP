cmake_minimum_required(VERSION 3.29)
project(homework_2_task_1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-Wall")

include(cmake/ClangFormat.cmake)
include(cmake/StaticAnalyzers.cmake)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(task_1 guessing_game.cpp)