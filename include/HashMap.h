#ifndef AUTOCOMPLETE_HASH_TRIE_COMPARISON_HASHMAP_H
#define AUTOCOMPLETE_HASH_TRIE_COMPARISON_HASHMAP_H

#include <string>
#include <vector>
#include <list>
using namespace std;

class HashMap {
private:
    vector<list<string>> buckets; //vector of lists used for seprate chaining
    int bucketCount; //total num of buckets in hash table
    int elementCount; //total num of elements currently stored

    unsigned int hashFunction(const string &word); //funct to calculate hash index for word
    string normalizeWord(const string &word) const; //helper function to convert word to lowercase for case insensitivity   
    
    public:
    explicit HashMap(int size = 100003); //constructor that initializes hash map with given bucket size
    void insert(const string &word); //insert word
    bool search(const string &word); //search for a word, returns bool
    int getBucketCount() const;
    int getElementCount() const;
    double getLoadFactor() const;
};


#endif //AUTOCOMPLETE_HASH_TRIE_COMPARISON_HASHMAP_H