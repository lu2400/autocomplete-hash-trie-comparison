cmake_minimum_required(VERSION 3.27)
project(FastLookup)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(FastLookup
        src/main.cpp
        src/HashMap.cpp
        src/Trie.cpp
        src/DatasetLoader.cpp
        src/Benchmark.cpp
        src/HelperFuncts.cpp
        include/HashMap.h
)
