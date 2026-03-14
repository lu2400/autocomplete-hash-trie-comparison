#include "HashMap.h"

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
    unsigned int index = hashFunction(word); //find bucket index

    for (const string& existingWord : buckets[index]) {
        if (existingWord == word) { //check if word already exist
            return;
        }
    }
    buckets[index].push_back(word);
    elementCount++;
}

bool HashMap::search(const string &word) {
    unsigned int index = hashFunction(word);
    for (const string& existingWord : buckets[index]) {
        if (existingWord == word) {
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

