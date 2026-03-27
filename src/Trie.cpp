#include "../include/Trie.h"
#include <cctype>


TrieNode::TrieNode() {
    isEndOfWord = false; //set end of word flag false
    for (int i = 0; i < 26; i++) { //sets all pointers to null
        children[i] = nullptr;
    }
}


Trie::Trie() {
    root = new TrieNode(); //creates root
}


Trie::~Trie() {
    clear(root); //destructor
}


string Trie::normalizeWord(const string& word) const {
    string result = word;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}


void Trie::clear(TrieNode *node) { //deletes all nodes in trie
    if (node == nullptr) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        clear(node->children[i]);
    }
    delete node;
}


void Trie::insert(const string& word) {
    string normalized = normalizeWord(word); //convert word to lowercase
    TrieNode *current = root; //start traversal at root
    for (char c : normalized) {//loops through each char of input
        if (c < 'a' || c > 'z') {
            return;
        }
        int index = c - 'a'; //converts char into an index 0 to 25
        if (current->children[index] == nullptr) { //checks if child node for letter doesn't exist
            current->children[index] = new TrieNode(); //create a new child node for letter
        }
        current = current->children[index]; //moves to child node for next iteration
    }
    current->isEndOfWord = true; //marks final node as end of word
}


bool Trie::search(const string& word) const{
    string normalized = normalizeWord(word); //convert word to lowercase
    TrieNode *current = root;
    for (char c : normalized) {
        if (c < 'a' || c > 'z') {
            return false;
        }
        int index = c - 'a';
        if (current->children[index] == nullptr) { //checks if needed child node doens't exist
            return false; //returns false if word not in trie
        }
        current = current->children[index];
    }
    return current->isEndOfWord;
}


void Trie::collectWords(TrieNode *node, string currentWord, vector<string> &results) const{
    if (node == nullptr || results.size() >= 5) { //checks if current node is null
        return;
    }
    if (node->isEndOfWord) { //checks if current node ends in complete word
        results.push_back(currentWord);  //adds built word to result list
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) { //checks if child node exists for letter
            char nextChar = 'a' + i; //converts child index back into char
            collectWords(node->children[i], currentWord + nextChar, results); //recursively explores child subtree
            if (results.size() >= 5) {
                return;
            }
        }
    }
}


vector<string> Trie::prefixSearch(const string& prefix) const {
    vector<string> result; //stores autocomplete results
    string normalized = normalizeWord(prefix); //convert prefix to lowercase
    TrieNode *current = root; //start at root


    for (char c : normalized) {
        if (c < 'a' || c > 'z') {
            return result;
        }
        int index = c - 'a';
        if (current->children[index] == nullptr) {//checks if prefix path doesn't exist
            return result; //returns empty if no words match
        }
        current = current->children[index]; //moves to next node
    }
    collectWords(current, normalized, result); //collects all complete words below prefix
    return result; //returns all matching autocomplete suggestions
}
