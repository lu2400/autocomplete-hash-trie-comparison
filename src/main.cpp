#include <iostream>
#include <string>
#include <vector>
#include "HashMap.h"
#include "DatasetLoader.h"

void printMenu() {
    std::cout << "\n--------------------------\n";
    std::cout << "   Word Lookup System\n";
    std::cout << "--------------------------\n";
    std::cout << "1. Load dataset\n";
    std::cout << "2. Insert words into structures\n";
    std::cout << "3. Search for a word\n";
    std::cout << "4. Search by prefix\n";
    std::cout << "5. Compare performance\n";
    std::cout << "6. Exit\n";
    std::cout << "--------------------------\n";
    std::cout << "Enter choice: ";
}

int main() {
    HashMap hashMap;
    std::vector<std::string> words;
    bool datasetLoaded = false;
    bool wordsInserted = false;

    int choice;
    do {
        printMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::cout << "Loading dataset...\n";
                words = loadDataset("../data/words_alpha.txt");
                if (!words.empty()) {
                    std::cout << "Loaded " << words.size() << " words.\n";
                    datasetLoaded = true;
                    wordsInserted = false;
                } else {
                    std::cout << "Failed to load dataset.\n";
                }
                break;
            }
            case 2: {
                if (!datasetLoaded) {
                    std::cout << "Please load the dataset first (option 1).\n";
                    break;
                }
                std::cout << "Inserting " << words.size() << " words into structures...\n";
                hashMap = HashMap();
                for (const std::string& word : words) {
                    hashMap.insert(word);
                }
                wordsInserted = true;
                std::cout << "Done.\n";
                break;
            }
            case 3: {
                if (!wordsInserted) {
                    std::cout << "Please load and insert words first (options 1 & 2).\n";
                    break;
                }
                std::string query;
                std::cout << "Enter word to search: ";
                std::getline(std::cin, query);
                std::cout << "Hash Map Result: " << (hashMap.search(query) ? "Found" : "Not Found") << "\n";
                break;
            }
            case 4:
            case 5:
                std::cout << "Coming soon.\n";
                break;
            case 6:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
