cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 11)

add_executable(C__ main.cpp
        Headers/DataStructure.h Headers/DataStructure2.h Headers/Graph.h Headers/Greedy.h Headers/Mathematics.h
        Headers/Recursive.h Headers/Search.h Headers/SortFind.h Headers/String.h Headers/Violence.h
        Sources/DataStructure.cpp Sources/DataStructure2.cpp Sources/Graph.cpp Sources/Greedy.cpp Sources/Mathematics.cpp
        Sources/Recursive.cpp Sources/Search.cpp Sources/SortFind.cpp Sources/String.cpp Sources/Violence.cpp Headers/DP.h Sources/DP.cpp
        Sources/machine/machine.cpp)