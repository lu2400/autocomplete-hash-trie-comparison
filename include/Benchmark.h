//
// Created by Lu Ighodalo
//

#ifndef AUTOCOMPLETE_HASH_TRIE_COMPARISON_BENCHMARK_H
#define AUTOCOMPLETE_HASH_TRIE_COMPARISON_BENCHMARK_H

#include <string>
#include <vector>
#include "HashMap.h"

struct BenchmarkResult {
    double insertTime;  // seconds to insert all words
    double searchTime;  // seconds to search all words
    double prefixTime;  // seconds to run prefix searches (-1.0 if not supported)
};

BenchmarkResult benchmarkHashMap(const std::vector<std::string>& words);
// benchmarkTrie will be added once Trie is implemented 
void printResults(const BenchmarkResult& hashResult, const BenchmarkResult& trieResult, int wordCount);

#endif //AUTOCOMPLETE_HASH_TRIE_COMPARISON_BENCHMARK_H
