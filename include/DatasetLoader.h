//
// Created by Lu Ighodalo
//

#ifndef AUTOCOMPLETE_HASH_TRIE_COMPARISON_DATASETLOADER_H
#define AUTOCOMPLETE_HASH_TRIE_COMPARISON_DATASETLOADER_H

#include <string>
#include <vector>

// Reads a word list file (one word per line) and returns all words as a vector.
std::vector<std::string> loadDataset(const std::string& filepath);

#endif //AUTOCOMPLETE_HASH_TRIE_COMPARISON_DATASETLOADER_H
