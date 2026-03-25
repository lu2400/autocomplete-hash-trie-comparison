#include "HashMap.h"
#include <cctype>

string HashMap::normalizeWord(const string &word) const {
    string result = word;
    for (char &c: result) {
        c = tolower(c); //convert each char to lowercase
    }
    return result;
}
HashMap::HashMap(int size) {
    bucketCount = size;
    elementCount = 0;
    buckets.resize(bucketCount);
}

unsigned int HashMap::hashFunction(const string &word) {
    unsigned int hash = 0; //hash value = 0

    for (char ch : word) { //loop through each char of word
        hash = hash * 31 + static_cast<unsigned int>(ch); //update has using polynomial rolling
    }

    return hash % bucketCount; //final hash value maps to valid index
}

void HashMap::insert(const string &word) {
    string normalized = normalizeWord(word); //normalize word to lowercase
    unsigned int index = hashFunction(normalized); //find bucket index

    for (const string& existingWord : buckets[index]) {
        if (existingWord == normalized) { //check if word already exist
            return;
        }
    }
    buckets[index].push_back(normalized);
    elementCount++;
}

bool HashMap::search(const string &word) {
    string normalized = normalizeWord(word);
    unsigned int index = hashFunction(normalized);
    for (const string& existingWord : buckets[index]) {
        if (existingWord == normalized) {
            return true;
        }
    }
    return false;
}

int HashMap::getBucketCount() const {
    return bucketCount;
}

int HashMap::getElementCount() const {
    return elementCount;
}

double HashMap::getLoadFactor() const {
    if (bucketCount == 0) {
        return 0.0;
    }
    return (double) elementCount / bucketCount;
}

