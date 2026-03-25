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
        if (!word.empty() && word.back() == '\r') {
            words.pop_back();
        }
        string cleanedWord;
        for (char c : word) {
            if (isalpha(c)) {
                cleanedWord += c;
            }
        }
        if (!cleanedWord.empty()) {
            words.push_back(cleanedWord);
        }
    }

    file.close();
    return words;
}
