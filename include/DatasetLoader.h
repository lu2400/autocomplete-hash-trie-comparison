//
// Created by Lu Ighodalo
//

#ifndef AUTOCOMPLETE_HASH_TRIE_COMPARISON_DATASETLOADER_H
#define AUTOCOMPLETE_HASH_TRIE_COMPARISON_DATASETLOADER_H

#include <string>
#include <vector>
using namespace std;

// getting words from data folder (words_alpha.txt)
//returns vectore with all words in the file
vector<string> loadDataset(const string& filepath);

#endif //AUTOCOMPLETE_HASH_TRIE_COMPARISON_DATASETLOADER_H
