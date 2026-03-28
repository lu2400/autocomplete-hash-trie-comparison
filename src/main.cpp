#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "../include/HashMap.h"
#include "../include/Trie.h"
#include "../include/Benchmark.h"
#include "../include/DatasetLoader.h"
#include "../include/Testing.h"
using namespace std;

//prints out menu and structure of menu so users know what to do
void printMenu() {
    cout << "\n--------------------------\n";
    cout << "   Word Lookup System\n";
    cout << "--------------------------\n";
    cout << "1. Load dataset\n";
    cout << "2. Insert words into structures\n";
    cout << "3. Search for a word\n";
    cout << "4. Search by prefix\n";
    cout << "5. Compare performance\n";
    cout << "6. Run correctness tests\n";
    cout << "7. Exit\n";
    cout << "--------------------------\n";
    cout << "Enter choice: ";
}

int main() {
    //creating structures of hashmap and trie to compare
    HashMap hashMap;
    Trie trie;
    vector<string> words;
    //flags that keep track of what the user is doing
    bool datasetLoaded = false;
    bool wordsInserted = false;

    int choice;
    do {// keeps running until exit is selected
        printMenu();
        if (!(cin >> choice)) {// make sure user inputs a valid number
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "Invalid choice. Please enter 1-7.\n";
            continue;
        }
        cin.ignore();

        switch (choice) {
            //loads the dataset from the file into vector
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
            }//inserts all words to both trie and hashmap structures
            case 2: {
                if (!datasetLoaded) {
                    cout << "Please load the dataset first (option 1).\n";
                    break;
                }//loop through every word 
                if (wordsInserted) {
                    cout << "Words have already been inserted into the structures. \n";
                    break;
                }
                cout << "Inserting " << words.size() << " words into structures...\n";
                for (const string& word : words) {
                    hashMap.insert(word);
                    trie.insert(word);
                }
                wordsInserted = true;
                cout << "Done.\n";

                break;
            }// looks for full word in trie and hashmap structures
            case 3: {
                if (!wordsInserted) {
                    cout << "Please load and insert words first (options 1 & 2).\n";
                    break;
                }
                string query;
                cout << "Enter word to search: ";
                getline(cin, query);
                //checks if the word exists the each structure
                cout << "Hash Map Result: " << (hashMap.search(query) ? "Found" : "Not Found") << "\n";
                cout << "Trie Result: " << (trie.search(query) ? "Found" : "Not Found") << "\n";
                break;
            }//prefix search with trie structure
            case 4: {
                if (!wordsInserted) {
                    cout << "Please load and insert words first (options 1 & 2).\n";
                    break;
                }
                string prefix;
                cout << "Enter prefix: ";
                getline(cin, prefix);
                vector<string> results = trie.prefixSearch(prefix);
                if (results.empty()) {
                    cout << "No suggestions found.\n";
                } else {
                    cout << "Suggestions:\n";
                    int limit = 6;//only shows first 6 suggestions
                    for (int i = 0; i < results.size() && i < limit; i++) {
                        cout << results[i] << "\n";
                    }
                    if (results.size() > limit) {
                        cout << "...and " << results.size() - limit << " more results.\n";
                    }
                }
                break;
            }//compare runtime performance of trie vs hashmap
            case 5: {
                if (!datasetLoaded) {
                    cout << "Please load the dataset first (option 1).\n";
                    break;
                }
                cout << "Running benchmarks...\n";
                BenchmarkResult hashResult = benchmarkHashMap(words);
                BenchmarkResult trieResult = benchmarkTrie(words);
                //prints results 
                printResults(hashResult, trieResult, static_cast<int>(words.size()));
                break;
            }//runs all correctness tests on trie and hashmap
            case 6:
                runAllTests();
                break;
            case 7:
                cout << "Goodbye!\n";//exits the program
                break;
            default:
                cout << "Invalid choice. Please enter 1-7.\n";//handles invalid menu choice
        }
    } while (choice != 7);// the loop continues until the user selects option 7 to exit

    return 0;
}
