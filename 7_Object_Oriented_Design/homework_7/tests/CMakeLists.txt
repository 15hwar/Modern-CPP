cmake_minimum_required(VERSION 3.29)
project(homework_7)

find_package(GTest REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/../include)

add_library(serialization ${PROJECT_SOURCE_DIR}/../src/convert_dataset.cpp ${PROJECT_SOURCE_DIR}/../src/serialize.cpp)
add_library(kmeans ${PROJECT_SOURCE_DIR}/../src/kmeans.cpp)
add_library(bow_dictionary ${PROJECT_SOURCE_DIR}/../src/bow_dictionary.cpp)

add_executable(test_kmeans test_kmeans.cpp test_data.cpp)
target_link_libraries(test_kmeans kmeans GTest::Main ${OpenCV_LIBS})
gtest_discover_tests(test_kmeans WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_bow_dictionary test_bow_dictionary.cpp)
target_link_libraries(test_bow_dictionary
                      bow_dictionary
                      serialization
                      GTest::Main
                      ${OpenCV_LIBS})
gtest_discover_tests(test_bow_dictionary WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})
