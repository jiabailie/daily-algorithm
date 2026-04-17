cmake_minimum_required(VERSION 4.1)
project(algorithm)

set(CMAKE_CXX_STANDARD 26)

file(GLOB_RECURSE ALGORITHM_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/*.h")

add_executable(algorithm main.cpp ${ALGORITHM_SOURCES}
        leetcode/3761/MinimumAbsoluteDistanceBetweenMirrorPairs.cpp
        leetcode/3761/MinimumAbsoluteDistanceBetweenMirrorPairs.h)
