cmake_minimum_required(VERSION 3.30.5)

# Set verbosity
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Set the project to be a C CXX ASM
project(bf2 CXX)

# C++ Defaults
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_CLANG_TIDY
        clang-tidy;
        -header-filter=.;
        -checks=-*,modernize-concat-nested-namespaces;)

# Set the include directories
include_directories(${PROJECT_SOURCE_DIR}/src)

if (MSVC)
    # warning level 4
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    string(REPLACE "/W3" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_definitions( -D_GLIBCXX_USE_CXX11_ABI=0 ) # this is required for STL binary combatibility on modern GCC

# Get all of the source files that need to be compiled
file(GLOB_RECURSE BF2_SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.cc ${PROJECT_SOURCE_DIR}/src/*.cxx ${PROJECT_SOURCE_DIR}/src/*.c ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/src/*.hpp ${PROJECT_SOURCE_DIR}/src/*.hxx)

add_executable(${PROJECT_NAME} ${BF2_SRC_FILES})