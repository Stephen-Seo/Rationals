cmake_minimum_required(VERSION 2.8)
project(Rationals)

set(Rational_SOURCES
    Rational.cpp)

add_library(Rational
    ${Rational_SOURCES})

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -D_GLIBCXX_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -D NDEBUG")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Debug', none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug")

find_package(GTest)

if(GTEST_FOUND)
    set(Unit_Tests_SOURCES
        test/TestRational.cpp
        test/Main.cpp)

    add_executable(Unit_Tests
        ${Unit_Tests_SOURCES})

    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries(Unit_Tests ${GTEST_BOTH_LIBRARIES} Rational)

    enable_testing()

    add_test(NAME UnitTests COMMAND Unit_Tests)
endif()

endif()
