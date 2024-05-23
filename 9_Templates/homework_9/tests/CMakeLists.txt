cmake_minimum_required(VERSION 3.29)
project(homework_9)

find_package(GTest REQUIRED)
find_package(OpenCV REQUIRED)

set(TEST_BINARY ${PROJECT_NAME}_test)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/../include)

add_library(bow_dictionary ${PROJECT_SOURCE_DIR}/../src/bovw_dictionary.cpp ${PROJECT_SOURCE_DIR}/../src/kmeans.cpp)
add_library(hostogram ${PROJECT_SOURCE_DIR}/../src/histogram.cpp)

add_executable(${TEST_BINARY}
               test_data.cpp
               test_dictionary.cpp
               test_histograms.cpp)

target_link_libraries(${TEST_BINARY} histogram bow_dictionary GTest::Main ${OPENCV_LIBS})

gtest_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})
