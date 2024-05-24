cmake_minimum_required(VERSION 3.10)
project(cspiro)

# Set C standard
set(CMAKE_C_STANDARD 11)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# Include the directory with the project's header files
include_directories(../include)

# Add each test file separately
add_executable(test_matrix test_matrix.c ../src/matrix.c)
