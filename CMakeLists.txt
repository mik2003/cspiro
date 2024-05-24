cmake_minimum_required(VERSION 3.10)
project(cspiro)

# Set C standard
set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(include)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Source files for the main application
file(GLOB APP_SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

# Define the executable target for release
add_executable(cspiro ${APP_SOURCES})
target_compile_options(cspiro PRIVATE "-Wall" "-s")

# Define the executable target for debug
add_executable(cspiro_debug ${APP_SOURCES})
target_compile_options(cspiro_debug PRIVATE "-Wall" "-g")
