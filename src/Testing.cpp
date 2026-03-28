//
// Created by Lu Ighodalo
//

#include "Testing.h"
#include "HashMap.h"
#include "Trie.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// prints PASS or FAIL label with test name and updates counters
static void check(const string& testName, bool passed, TestResult& result) {
    cout << "  [" << (passed ? "PASS" : "FAIL") << "] " << testName << "\n";
    if (passed) result.passed++;
    else result.failed++;
}

TestResult runAllTests() {
    TestResult result = {0, 0};
    cout << "\n=== HashMap Tests ===\n";

    // inserted words are found
    {
        HashMap map;
        map.insert("apple");
        map.insert("banana");
        check("Insert and search found words",
              map.search("apple") && map.search("banana"), result);
    }

    // words never inserted return false
    {
        HashMap map;
        map.insert("apple");
        check("Search returns false for missing word",
              !map.search("orange"), result);
    }

    // inserting "Apple" should match search for "apple" and "APPLE"
    {
        HashMap map;
        map.insert("Apple");
        check("Case insensitive search",
              map.search("apple") && map.search("APPLE"), result);
    }

    // inserting same word twice should only count once
    {
        HashMap map;
        map.insert("test");
        map.insert("test");
        check("No duplicate inserts", map.getElementCount() == 1, result);
    }

    // multiple words, all present
    {
        HashMap map;
        vector<string> words = {"cat", "dog", "fish", "bird"};
        for (const string& w : words) map.insert(w);
        bool allFound = true;
        for (const string& w : words) {
            if (!map.search(w)) allFound = false;
        }
        check("Multiple words all found after insert", allFound, result);
    }

    cout << "\n=== Trie Tests ===\n";

    // inserted words are found
    {
        Trie trie;
        trie.insert("hello");
        trie.insert("world");
        check("Insert and search found words",
              trie.search("hello") && trie.search("world"), result);
    }

    // prefix of word and word with extra chars shouldn't match
    {
        Trie trie;
        trie.insert("hello");
        check("Search returns false for prefix-only and extended word",
              !trie.search("hell") && !trie.search("hellos"), result);
    }

    // inserting "Hello" should match search for "hello" and "HELLO"
    {
        Trie trie;
        trie.insert("Hello");
        check("Case insensitive search",
              trie.search("hello") && trie.search("HELLO"), result);
    }

    // prefix search returns exactly the right number of matches
    {
        Trie trie;
        trie.insert("automatic");
        trie.insert("automation");
        trie.insert("automobile");
        trie.insert("cat");
        vector<string> results = trie.prefixSearch("auto");
        check("Prefix search returns correct number of matches",
              (int)results.size() == 3, result);
    }

    // prefix search on a prefix that matches no words returns empty
    {
        Trie trie;
        trie.insert("apple");
        check("Prefix search returns empty for no match",
              trie.prefixSearch("xyz").empty(), result);
    }

    // prefix that is a full word also returns that word in results
    {
        Trie trie;
        trie.insert("run");
        trie.insert("runner");
        trie.insert("running");
        vector<string> results = trie.prefixSearch("run");
        check("Prefix search includes exact-match word in results",
              (int)results.size() == 3, result);
    }

    // single character word
    {
        Trie trie;
        trie.insert("a");
        check("Single character word insert and search",
              trie.search("a") && !trie.search("b"), result);
    }

    // print summary
    cout << "\n------------------------------------------\n";
    cout << "Results: " << result.passed << " passed, "
         << result.failed << " failed out of "
         << (result.passed + result.failed) << " tests\n";
    cout << "------------------------------------------\n";

    return result;
}
