# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(cspiro)

# Set the C standard
set(CMAKE_C_STANDARD 11)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.c")

# Define the executable target for release
add_executable(cspiro ${SOURCES})

# Set compiler flags for different build types
set(CMAKE_C_FLAGS_RELEASE "-Wall -s")
set(CMAKE_C_FLAGS_DEBUG "-Wall -g")

# Specify the build types
set(CMAKE_BUILD_TYPE Release) # Default to Release build type
set_property(GLOBAL PROPERTY DEBUG_CONFIGURATIONS Debug)

# Create a separate executable target for debug
add_executable(cspiro_debug ${SOURCES})
set_target_properties(cspiro_debug PROPERTIES COMPILE_FLAGS "-g")
set_target_properties(cspiro PROPERTIES COMPILE_FLAGS "-s")

# Link libraries
target_link_libraries(cspiro m)
target_link_libraries(cspiro_debug m)

# TESTING
include(CTest)

# Include the Unity testing framework (adjust the path as needed)
# include_directories(${CMAKE_SOURCE_DIR}/unity/src)

# Add test files
file(GLOB TEST_SOURCES "tests/*.c")

# Add executable for running tests
add_executable(runTests ${TEST_SOURCES} ${SOURCES})

# Link the math library for tests
target_link_libraries(runTests m)

# Add tests to CTest
add_test(NAME runTests COMMAND runTests)