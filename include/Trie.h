// 
// Created by Viannee
//

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
    //helper function that changes a words to lowercase because it is case sensitive
    string normalizeWord(const string& word) const;

public:
    Trie();
    ~Trie();
    //inserts word into trie after normalizing it
    void insert(const string& word);
    //checks if word exisits in the trie
    bool search(const string& word) const;
    //returns all words with prefix
    vector<string> prefixSearch(const string& prefix) const; //return all words with prefix
    void clear(TrieNode* node);
};



#endif //AUTOCOMPLETE_HASH_TRIE_COMPARISON_TRIE_H