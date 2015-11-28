project(StringCalculator)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/build $ENV{GMOCK_HOME}/gtest/build)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -g -O0 -Wall -pthread")
enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

set(sources
   main.cpp
   StringCalculator.hpp
   StringCalculatorTest.cpp)

add_executable(StringCalculatorTest ${sources})
target_link_libraries(StringCalculatorTest pthread)
target_link_libraries(StringCalculatorTest gmock)
target_link_libraries(StringCalculatorTest gtest)
add_dependencies(StringCalculatorTest gmock)
add_test(StringCalculatorTest StringCalculatorTest)

