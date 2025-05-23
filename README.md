# BreadFlowerDos
A Battlefield 2/2142 "decompilation" project

## What is this project

This project is an "effort" to create a free and open source recreation of the Refractor 2? Game engine. 

Primarily focused on Battlefield 2 and 2142. This is more of a reimplementation of the engine than a 1:1 decomp.

We will be using modern C++ and re-implementing functionality as we see fit, this isn't going to be a direct
port but more of a recreation.

Do not expect any meaningful efforts as I open Ghidra and start on this project once every 6 months or so.

## Compiling

### Requirements
* CMake 4.0+
* Clang 19+ (or MSVC)
* Clang-Tidy
* Clang-Format

## Contribution

You must run clang-tidy and clang-format before each commit, or it will cause build errors.

### Linux

`find . -iname '*.h' -o -iname '*.cpp' -o -iname '*.hpp' | clang-format --style=file -i --files=/dev/stdin`

`clang-tidy -checks='-*,modernize-concat-nested-namespaces' -fix-errors dice/hfe/world/**.hpp`

### Windows (TODO)

`TODO`