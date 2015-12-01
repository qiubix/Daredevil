project(StringCalculator)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/build $ENV{GMOCK_HOME}/gtest/build)
add_definitions(-std=c++0x)
#set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -g -O0 -Wall -fprofile-arcs -ftest-coverage -pthread")
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -g -O0 -Wall -pthread")
enable_testing()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

#add_definitions(--coverage)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
#SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage")

include(Coverage)
coveralls_turn_on_coverage()

set(sources
   main.cpp
   StringCalculator.hpp
   StringCalculatorTest.cpp)

coveralls_setup(
        "${sources}"
        ${COVERALLS_UPLOAD}
        "${PROJECT_SOURCE_DIR}/cmake")

add_executable(StringCalculatorTest ${sources})
target_link_libraries(StringCalculatorTest pthread)
target_link_libraries(StringCalculatorTest gmock)
target_link_libraries(StringCalculatorTest gtest)
add_dependencies(StringCalculatorTest gmock)
add_test(StringCalculatorTest StringCalculatorTest)



# if(CMAKE_COMPILER_IS_GNUCXX)
#     include(CodeCoverage)
#     setup_target_for_coverage(${PROJECT_NAME}_coverage StringCalculatorTest coverage)
# endif()

