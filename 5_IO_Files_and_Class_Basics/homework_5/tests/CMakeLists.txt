cmake_minimum_required(VERSION 3.29)
project(homework_5)

find_package(Catch2 REQUIRED)
find_package(OpenCV REQUIRED)

include(CTest)
include(Catch)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/../include)

add_library(sifts_internal SHARED sifts_internal.cpp)
add_library(mat_serialization ${PROJECT_SOURCE_DIR}/../src/serialize.cpp)
add_library(convert_dataset ${PROJECT_SOURCE_DIR}/../src/convert_dataset.cpp)

target_link_libraries(sifts_internal ${OpenCV_LIBS})

set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY}
               test_serialize.cpp
               test_convert_dataset.cpp
               test_main.cpp)

target_link_libraries(${TEST_BINARY}
                      convert_dataset
                      mat_serialization
                      sifts_internal
                      Catch2::Catch2)

catch_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})
