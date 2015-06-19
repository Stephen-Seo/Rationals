cmake_minimum_required(VERSION 2.8)
project(Rational)

set(Rational_VERSION 1.0.0)

include(GenerateExportHeader)

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

generate_export_header(Rational)
set_property(TARGET Rational PROPERTY VERSION ${Rational_VERSION})
set_property(TARGET Rational PROPERTY SOVERSION 1)
set_property(TARGET Rational PROPERTY INTERFACE_Rational_MAJOR_VERSION 1)
set_property(TARGET Rational APPEND PROPERTY COMPATIBLE_INTERFACE_STRING Rational_MAJOR_VERSION)

install(TARGETS Rational EXPORT RationalTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include)

install(
    FILES
        Rational.hpp
        "${CMAKE_CURRENT_BINARY_DIR}/rational_export.h"
    DESTINATION
        include
    COMPONENT
        Devel
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/Rational/RationalConfigVersion.cmake"
    VERSION ${Rational_VERSION}
    COMPATIBILITY AnyNewerVersion
)

export(EXPORT RationalTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/Rational/RationalTargets.cmake"
)

configure_file(cmake/RationalConfig.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/Rational/RationalConfig.cmake"
    @ONLY
)

export(PACKAGE Rational)

set(ConfigPackageLocation lib/cmake/Rational)

install(EXPORT RationalTargets
    FILE
        RationalTargets.cmake
    DESTINATION
        ${ConfigPackageLocation}
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/Rational/RationalConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/Rational/RationalConfigVersion.cmake"
    DESTINATION
        ${ConfigPackageLocation}
    COMPONENT
        Devel
)

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
