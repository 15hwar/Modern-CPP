cmake_minimum_required(VERSION 3.29)
project(homework_2_task_1)
# set install folder
set(CMAKE_CXX_STANDARD 17)
#  generate compiple commands file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-Wall")
# set libs folder

# set executables folder
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
## COMPILATION
add_executable(task_1 guessing_game.cpp)