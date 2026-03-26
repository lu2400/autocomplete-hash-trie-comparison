//
// Created by Lu Ighodalo
//

#ifndef AUTOCOMPLETE_HASH_TRIE_COMPARISON_TESTING_H
#define AUTOCOMPLETE_HASH_TRIE_COMPARISON_TESTING_H

// stores count of passed and failed tests
struct TestResult {
    int passed;
    int failed;
};

// runs correctness tests for hashmap and trie, prints pass/fail per test
TestResult runAllTests();

#endif //AUTOCOMPLETE_HASH_TRIE_COMPARISON_TESTING_H
