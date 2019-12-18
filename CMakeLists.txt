cmake_minimum_required(VERSION 3.10)

project(puzzle)

set(CMAKE_CXX_STANDARD 17)

# define puzzle library
include_directories(src)
set(PUZZLE_SOURCES
        src/puzzle.cpp
        )
set(PUZZLE_LIB puzzle_lib)
add_library(${PUZZLE_LIB} STATIC ${PUZZLE_SOURCES})

# define test for the library
set(PUZZLE_TEST_SOURCES
        test/puzzleTest.cpp)

set(PUZZLE_TEST puzzle_test)
add_executable(${PUZZLE_TEST} ${PUZZLE_TEST_SOURCES})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(${PUZZLE_TEST} ${PUZZLE_LIB} ${GTEST_BOTH_LIBRARIES} pthread)