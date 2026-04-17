cmake_minimum_required(VERSION 3.25)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE ALGORITHM_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/*.h")

add_library(algorithm_objs OBJECT ${ALGORITHM_SOURCES})
target_include_directories(algorithm_objs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(algorithm main.cpp $<TARGET_OBJECTS:algorithm_objs>)
target_include_directories(algorithm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()

add_executable(algorithm_tests tests/algorithm_smoke_tests.cpp $<TARGET_OBJECTS:algorithm_objs>)
target_include_directories(algorithm_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(algorithm_tests PRIVATE ALGORITHM_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_test(NAME algorithm_registry_smoke COMMAND algorithm_tests)
