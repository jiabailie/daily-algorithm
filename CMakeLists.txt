cmake_minimum_required(VERSION 3.25)
project(algorithm)

set(CMAKE_CXX_STANDARD 26)

file(GLOB_RECURSE ALGORITHM_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/*.h")

add_executable(algorithm main.cpp ${ALGORITHM_SOURCES})
