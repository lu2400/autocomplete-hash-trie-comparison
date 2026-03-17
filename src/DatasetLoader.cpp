//
// Created by Lu Ighodalo
//

#include "DatasetLoader.h"
#include <fstream>
#include <iostream>

std::vector<std::string> loadDataset(const std::string& filepath) {
    std::vector<std::string> words;
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open dataset file: " << filepath << std::endl;
        return words;
    }

    std::string word;
    while (std::getline(file, word)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }

    file.close();
    return words;
}
