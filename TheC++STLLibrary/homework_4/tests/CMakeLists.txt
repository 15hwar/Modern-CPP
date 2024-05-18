cmake_minimum_required(VERSION 3.29)
project(homework_4_tests)
find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

set(CMAKE_CXX_STANDARD 17)

#  generate compiple commands file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${PROJECT_SOURCE_DIR}/../include)

set(TEST_BINARY ${PROJECT_NAME}_test)
# add_library(named_vector INTERFACE)
add_library(ipb_algorithm ${PROJECT_SOURCE_DIR}/../src/ipb_algorithms.cpp)
add_executable(${TEST_BINARY}
               test_named_vector.cpp
            #    test_ipb_algorithm.cpp
               test_main.cpp
               )

target_link_libraries(${TEST_BINARY} ipb_algorithm Catch2::Catch2)
catch_discover_tests(${TEST_BINARY})
