//
// Created by Lu Ighodalo
//

#include "Benchmark.h"
#include "Trie.h"
#include <chrono>
#include <iostream>
#include <iomanip>
using namespace std;

BenchmarkResult benchmarkHashMap(const vector<string>& words) {
    BenchmarkResult result;
    HashMap map;

    // time insertion
    auto start = chrono::high_resolution_clock::now();
    for (const string& word : words) {
        map.insert(word);
    }
    auto end = chrono::high_resolution_clock::now();
    result.insertTime = chrono::duration<double>(end - start).count();

    // search every word that was inserted
    start = chrono::high_resolution_clock::now();
    for (const string& word : words) {
        map.search(word);
    }
    end = chrono::high_resolution_clock::now();

    result.searchTime = chrono::duration<double>(end - start).count();
    result.prefixTime = -1.0; // HashMap doesn't support prefix search
    return result;
}

BenchmarkResult benchmarkTrie(const vector<string>& words) {
    Trie trie;

    auto startInsert = chrono::high_resolution_clock::now();
    for (const string& word : words) {
        trie.insert(word);
    }
    auto endInsert = chrono::high_resolution_clock::now();

    auto startSearch = chrono::high_resolution_clock::now();
    for (const string& word : words) {
        trie.search(word);
    }
    auto endSearch = chrono::high_resolution_clock::now();

    auto startPrefix = chrono::high_resolution_clock::now();
    for (int i = 0; i < words.size() && i < 1000; i++) {
        if (words[i].length() >= 3) {
            string prefix = words[i].substr(0, 3);
            trie.prefixSearch(prefix);
        }
    }
    auto endPrefix = chrono::high_resolution_clock::now();

    BenchmarkResult result;
    result.insertTime = chrono::duration<double>(endInsert - startInsert).count();
    result.searchTime = chrono::duration<double>(endSearch - startSearch).count();
    result.prefixTime = chrono::duration<double>(endPrefix - startPrefix).count();
    return result;
}

void printResults(const BenchmarkResult& hashResult, const BenchmarkResult& trieResult, int wordCount) {
    cout << fixed << setprecision(6);
    cout << "\n--- Performance Comparison (" << wordCount << " words) ---\n";
    cout << left
              << setw(18) << "Operation"
              << setw(18) << "Hash Map (s)"
              << setw(18) << "Trie (s)" << "\n";
    cout << string(54, '-') << "\n";

    cout << setw(18) << "Insert"
              << setw(18) << hashResult.insertTime
              << setw(18) << trieResult.insertTime << "\n";

    cout << setw(18) << "Search"
              << setw(18) << hashResult.searchTime
              << setw(18) << trieResult.searchTime << "\n";

    cout << setw(18) << "Prefix Search"
              << setw(18) << "N/A"
              << setw(18) << trieResult.prefixTime << "\n";

    cout << string(54, '-') << "\n";
}
