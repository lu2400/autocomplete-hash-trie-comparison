//
// Created by Lu Ighodalo
//

#include "Benchmark.h"
#include <chrono>
#include <iostream>
#include <iomanip>

BenchmarkResult benchmarkHashMap(const std::vector<std::string>& words) {
    BenchmarkResult result;
    HashMap map;

    // Time insertion
    auto start = std::chrono::high_resolution_clock::now();
    for (const std::string& word : words) {
        map.insert(word);
    }
    auto end = std::chrono::high_resolution_clock::now();
    result.insertTime = std::chrono::duration<double>(end - start).count();

    // Time search (search every word that was inserted)
    start = std::chrono::high_resolution_clock::now();
    for (const std::string& word : words) {
        map.search(word);
    }
    end = std::chrono::high_resolution_clock::now();
    result.searchTime = std::chrono::duration<double>(end - start).count();

    result.prefixTime = -1.0; // HashMap does not support prefix search

    return result;
}

void printResults(const BenchmarkResult& hashResult, const BenchmarkResult& trieResult, int wordCount) {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\n--- Performance Comparison (" << wordCount << " words) ---\n";
    std::cout << std::left
              << std::setw(18) << "Operation"
              << std::setw(18) << "Hash Map (s)"
              << std::setw(18) << "Trie (s)" << "\n";
    std::cout << std::string(54, '-') << "\n";

    std::cout << std::setw(18) << "Insert"
              << std::setw(18) << hashResult.insertTime
              << std::setw(18) << trieResult.insertTime << "\n";

    std::cout << std::setw(18) << "Search"
              << std::setw(18) << hashResult.searchTime
              << std::setw(18) << trieResult.searchTime << "\n";

    std::cout << std::setw(18) << "Prefix Search"
              << std::setw(18) << "N/A"
              << std::setw(18) << trieResult.prefixTime << "\n";

    std::cout << std::string(54, '-') << "\n";
}
