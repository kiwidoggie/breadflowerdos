cmake_minimum_required(VERSION 3.12)

# Set verbosity
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Set the project to be a C CXX ASM
project(bf2 CXX)

# C++ Defaults
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the include directories
include_directories(${PROJECT_SOURCE_DIR}/src)

# Get all of the source files that need to be compiled
file(GLOB_RECURSE BF2_SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.cc ${PROJECT_SOURCE_DIR}/*.cxx ${PROJECT_SOURCE_DIR}/*.c ${PROJECT_SOURCE_DIR}/*.h ${PROJECT_SOURCE_DIR}/*.hpp ${PROJECT_SOURCE_DIR}/*.hxx)

add_executable(${PROJECT_NAME} ${BF2_SRC_FILES})