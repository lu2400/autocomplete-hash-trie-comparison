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
    result.prefixTime = -1.0; //hashmap doesn't support prefix search
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
    for (size_t i = 0; i < words.size() && i < 1000; i++) {
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

// returns "blah (blahx faster)" or "blah(same speed)" winner label for a timed row
static string timeWinner(const string& aName, double aTime, const string& bName, double bTime) {
    if (aTime <= 0 || bTime <= 0) return "N/A";
    const double threshold = 1.02; // added a margin of error here (need to account for timing discrepancies and such)
    if (aTime < bTime / threshold) {
        return aName + " (" + to_string(bTime / aTime).substr(0, 4) + "x faster)";
    } else if (bTime < aTime / threshold) {
        return bName + " (" + to_string(aTime / bTime).substr(0, 4) + "x faster)";
    }
    return "roughly equal";
}
// kind of a hack to get a winner label for the prefix search row since only trie supports it but it works sooo
void printResults(const BenchmarkResult& hashResult, const BenchmarkResult& trieResult, int wordCount) {
    cout << fixed << setprecision(6);
    cout << "\n--- Performance Comparison (" << wordCount << " words) ---\n";
    cout << left
         << setw(18) << "Operation"
         << setw(18) << "Hash Map(sec)"
         << setw(18) << " Trie(sec)"
         << "Winner" << "\n";
    cout << string(72, '-') << "\n";

    cout << setw(18) << "Insert"
         << setw(18) << hashResult.insertTime
         << setw(18) << trieResult.insertTime
         << timeWinner("HashMap", hashResult.insertTime, "Trie", trieResult.insertTime) << "\n";

    cout << setw(18) << "Search"
         << setw(18) << hashResult.searchTime
         << setw(18) << trieResult.searchTime
         << timeWinner("HashMap", hashResult.searchTime, "Trie", trieResult.searchTime) << "\n";

    cout << setw(18) << "Prefix Search"
         << setw(18) << "N/A"
         << setw(18) << trieResult.prefixTime
         << "Trie (only structure with prefix support)" << "\n";

    cout << string(72, '-') << "\n";
}
