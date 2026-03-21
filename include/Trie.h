
#ifndef AUTOCOMPLETE_HASH_TRIE_COMPARISON_TRIE_H
#define AUTOCOMPLETE_HASH_TRIE_COMPARISON_TRIE_H

#include <string>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[26]; //array of 26 pointers, one for each lowercase
    bool isEndOfWord; //marks if node is end of complete word
    TrieNode();
};

class Trie {
private:
    TrieNode* root; //pointer to root
    //helper to gather words below prefix
    void collectWords(TrieNode* node, string currentWord, vector<string>& results) const;

public:
    Trie();
    ~Trie();
    void insert(const string& word);
    bool search(const string& word) const;
    vector<string> prefixSearch(const string& prefix) const; //return all words with prefix
    void clear(TrieNode* node);
};





#endif //AUTOCOMPLETE_HASH_TRIE_COMPARISON_TRIE_H