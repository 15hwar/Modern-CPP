cmake_minimum_required(VERSION 3.29)
project(homework_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include/)

add_library(html_writer src/html_writer.cpp)
add_library(image_browser src/image_browser.cpp)

link_libraries(html_writer image_browser)

add_executable(create_image_browser src/create_image_browser.cpp)

target_link_libraries(create_image_browser html_writer image_browser)