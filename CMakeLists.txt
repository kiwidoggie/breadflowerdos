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

add_definitions( -D_GLIBCXX_USE_CXX11_ABI=0 ) # this is required for STL binary combatibility on modern GCC

# Get all of the source files that need to be compiled
file(GLOB_RECURSE BF2_SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.cc ${PROJECT_SOURCE_DIR}/src/*.cxx ${PROJECT_SOURCE_DIR}/src/*.c ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/src/*.hpp ${PROJECT_SOURCE_DIR}/src/*.hxx)

add_executable(${PROJECT_NAME} ${BF2_SRC_FILES})