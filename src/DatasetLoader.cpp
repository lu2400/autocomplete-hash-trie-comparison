//
// Created by Lu Ighodalo
//

#include "DatasetLoader.h"
#include <fstream>
#include <iostream>
using namespace std;

vector<string> loadDataset(const string& filepath) {
    vector<string> words;
    ifstream file(filepath);

    if (!file.is_open()) {
        cerr << "Error: Could not open dataset file: " << filepath << endl;
        return words;
    }

    string word;
    while (getline(file, word)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }

    file.close();
    return words;
}
