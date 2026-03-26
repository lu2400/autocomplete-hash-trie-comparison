# Autocomplete Hash vs. Trie Comparison

## Overview
This project implements and compares two data structures for word lookup and autocomplete; Hash Map, and Trie.
The program allows users to load a dataset of words, insert them into both data structures, perform searches, and compare performance.

## How to Build and Run
### Using Terminal (g++)
Make sure you are in the project root directory, then run:

    g++ -Iinclude src/*.cpp -o main.exe
    
    .\main.exe
    
## Features
- Load a dataset of words from a file

- Insert words into both Hash Map and Trie

- Perform case-insensitive word search

- Perform prefix-based autocomplete using a Trie

- Limit autocomplete results to 5 suggestions

- Compare performance between Hash Map and Trie

## Project Structure

    data/
    
        words.txt
      
    include/
    
      Benchmark.h
      
      DatasetLoader.h
      
      HashMap.h
      
      Trie.h
    
    src/
  
      Benchmark.cpp
    
      DatasetLoader.cpp
      
      HashMap.cpp
      
      Trie.cpp
      
      main.cpp
      
    CMakeLists.txt
    
    README.md
  

## How to Use
After running the program, you will see a menu:
### Word Lookup System

1. Load dataset
   
2. Insert words into structures
   
3. Search for a word
   
4. Search by prefix
   
5. Compare performance
 
6. Run correctness tests
 
7. Exit

Then you will enter the number corresponding to what action you would like to complete and any words or prefix you will like to search up.

## Dataset
The dataset file is located in:

### data/words.txt

Each line represents a single word.

## Notes
- Searches are case-insensitive (e.g., "dog", "Dog", "DOG" all work). 

- Trie supports efficient prefix searching.

- Autocomplete results are limited to 5 suggestions for performance and readability.

## Author 
Viannee 
