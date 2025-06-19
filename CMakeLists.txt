cmake_minimum_required(VERSION 3.31)
project(PTIT_K24DTCN638_DSA_MAJOR_ASSIGNMENT)

set(CMAKE_CXX_STANDARD 20)

add_executable(binary-generation src/generation-algorithms/binary-generation.cpp)
add_executable(combination-generation src/generation-algorithms/combination-generation.cpp)
add_executable(permutation-generation src/generation-algorithms/permutation-generation.cpp)
add_executable(bfs src/graph-algorithms/bfs.cpp)
add_executable(dfs src/graph-algorithms/dfs.cpp)
add_executable(bubble-sort src/sorting/bubble-sort.cpp)
add_executable(selection-sort src/sorting/selection-sort.cpp)
add_executable(quick-sort src/sorting/quick-sort.cpp)
add_executable(heap-sort src/sorting/heap-sort.cpp)
add_executable(merge-sort src/sorting/merge-sort.cpp)
add_executable(hanoi-tower src/divide-and-conquer/hanoi-tower.cpp)
add_executable(knight-s-tour src/backtracking/knight-s-tour.cpp)

