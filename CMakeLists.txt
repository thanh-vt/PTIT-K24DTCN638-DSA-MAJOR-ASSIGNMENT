cmake_minimum_required(VERSION 3.31)
project(PTIT_K24DTCN638_DSA_MAJOR_ASSIGNMENT)

set(CMAKE_CXX_STANDARD 20)

add_executable(binary-generation src/generation-algorithms/binary-generation.cpp)
add_executable(combination-generation src/generation-algorithms/combination-generation.cpp)
add_executable(permutation-generation src/generation-algorithms/permutation-generation.cpp)
