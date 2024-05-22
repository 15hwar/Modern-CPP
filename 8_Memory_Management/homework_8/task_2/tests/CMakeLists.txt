cmake_minimum_required(VERSION 3.29)
project(homework_8_task_2)

find_package(GTest REQUIRED)
find_package(PNG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/../include/)

set(TEST_BINARY ${PROJECT_NAME}_test)

add_library(image ${PROJECT_SOURCE_DIR}/../src/color_image.cpp ${PROJECT_SOURCE_DIR}/../src/strategies.cpp)

add_executable(${TEST_BINARY}
               test_init.cpp
               test_from_png.cpp
               test_from_ppm.cpp
               test_resize.cpp)

target_link_libraries(${TEST_BINARY} image GTest::Main ${PNG_LIBRARY})
gtest_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})
