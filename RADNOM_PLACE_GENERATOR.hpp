// ADD TO CODE -> IMPORT IMPLEMENTTATION

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <cmath>  // For using mathematical functions like floor, exp, etc.
#include <bits/stdc++.h>

using namespace std;

// Define Euler's constant (e)
const double EULER_CONSTANT = 2.718281828459045;

// Function to generate salted word index using Euler's constant
int complexEquationUsingE(int i, int totalWords) {
    // Apply Euler's constant and modulo to create an index
    return static_cast<int>(floor(EULER_CONSTANT * i)) % totalWords;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Sample hashmap of words and their frequencies
    unordered_map<string, int> wordFreqMap = {
        {"apple", 3},
        {"banana", 5},
        {"orange", 2},
        {"grape", 4}
    };

    ifstream file("dumpFile.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<string> words;
    string word;

    // Read words from the file
    while (file >> word) {
        // Clean up punctuation
        for (char& c : word) {
            if (ispunct(c)) {
                c = ' ';
            }
        }
        words.push_back(word);
    }

    file.close();  // Close the file

    // Check if words were found in the file
    if (words.empty()) {
        cout << "No words found in the file!" << endl;
        return 1;
    }

    // Create salted words based on the words from the file
    int totalWords = words.size();

    // Add salted words at random intervals using Euler's constant
    for (int i = 0; i < totalWords; ++i) {
        int index = complexEquationUsingE(i, totalWords);  // Get the index using the Euler's constant equation
        
        // Get a random word from the file
        string saltedWord = words[rand() % totalWords];
        
        // Add the salted word to the hashmap or update the frequency
        if (wordFreqMap.find(saltedWord) != wordFreqMap.end()) {
            wordFreqMap[saltedWord]++;  // Increase the frequency
        } else {
            wordFreqMap[saltedWord] = 1; // Add the salted word if not present
        }

        // For demonstration, print which word is added at which position
        cout << "Adding salted word: " << saltedWord << " at position " << index << endl;
    }

    // Output the updated word frequencies
    cout << "\nUpdated word frequencies: \n";
    for (const auto& pair : wordFreqMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
