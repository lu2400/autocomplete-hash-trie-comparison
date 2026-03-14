#include <iostream>
#include <HashMap.h>

int main() {
    HashMap map;

    map.insert("cat");
    map.insert("car");
    map.insert("dog");

    std::cout << "Searching for 'cat': "
              << (map.search("cat") ? "Found" : "Not Found") << std::endl;

    std::cout << "Searching for 'cow': "
              << (map.search("cow") ? "Found" : "Not Found") << std::endl;

    std::cout << "Element count: " << map.getElementCount() << std::endl;
    std::cout << "Bucket count: " << map.getBucketCount() << std::endl;
    std::cout << "Load factor: " << map.getLoadFactor() << std::endl;

    return 0;
}