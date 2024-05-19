cmake_minimum_required(VERSION 3.29)
project(homework_6)

find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/../include)

set(TEST_BINARY ${PROJECT_NAME}_test)
add_library(image ${PROJECT_SOURCE_DIR}/../src/image.cpp)
add_executable(${TEST_BINARY}
               test_init.cpp
               test_histogram.cpp
               test_from_file.cpp
               test_resize.cpp)

target_link_libraries(${TEST_BINARY} image GTest::Main)
gtest_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})
