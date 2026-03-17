#include <iostream>
#include <string>
#include <vector>
#include "HashMap.h"
#include "DatasetLoader.h"
using namespace std;

void printMenu() {
    cout << "\n--------------------------\n";
    cout << "   Word Lookup System\n";
    cout << "--------------------------\n";
    cout << "1. Load dataset\n";
    cout << "2. Insert words into structures\n";
    cout << "3. Search for a word\n";
    cout << "4. Search by prefix\n";
    cout << "5. Compare performance\n";
    cout << "6. Exit\n";
    cout << "--------------------------\n";
    cout << "Enter choice: ";
}

int main() {
    HashMap hashMap;
    vector<string> words;
    bool datasetLoaded = false;
    bool wordsInserted = false;

    int choice;
    do {
        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Loading dataset...\n";
                words = loadDataset("../data/words_alpha.txt");
                if (!words.empty()) {
                    cout << "Loaded " << words.size() << " words.\n";
                    datasetLoaded = true;
                    wordsInserted = false;
                } else {
                    cout << "Failed to load dataset.\n";
                }
                break;
            }
            case 2: {
                if (!datasetLoaded) {
                    cout << "Please load the dataset first (option 1).\n";
                    break;
                }
                cout << "Inserting " << words.size() << " words into structures...\n";
                hashMap = HashMap();
                for (const string& word : words) {
                    hashMap.insert(word);
                }
                wordsInserted = true;
                cout << "Done.\n";
                break;
            }
            case 3: {
                if (!wordsInserted) {
                    cout << "Please load and insert words first (options 1 & 2).\n";
                    break;
                }
                string query;
                cout << "Enter word to search: ";
                getline(cin, query);
                cout << "Hash Map Result: " << (hashMap.search(query) ? "Found" : "Not Found") << "\n";
                break;
            }
            case 4:
            case 5:
                cout << "Coming soon.\n";
                break;
            case 6:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
