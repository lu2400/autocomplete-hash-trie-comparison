//
// Created by Lu Ighodalo
//

#ifndef AUTOCOMPLETE_HASH_TRIE_COMPARISON_BENCHMARK_H
#define AUTOCOMPLETE_HASH_TRIE_COMPARISON_BENCHMARK_H

#include <string>
#include <vector>
#include "HashMap.h"
#include "Trie.h"

//Stores timing result per data struct
struct BenchmarkResult {
    double insertTime;  // seconds to insert all words
    double searchTime;  // seconds to search all words
    double prefixTime;  // seconds to run prefix searches (-1.0 if not supported)
};

//benchmark test on hashmap
//measuring insertion, search, and search performance 
BenchmarkResult benchmarkHashMap(const std::vector<std::string>& words);
BenchmarkResult benchmarkTrie(const std::vector<std::string>& words);
//prints benchmark resukts,compares hashmap and trie
void printResults(const BenchmarkResult& hashResult, const BenchmarkResult& trieResult, int wordCount);

#endif //AUTOCOMPLETE_HASH_TRIE_COMPARISON_BENCHMARK_H
