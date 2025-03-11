#ifndef RANDOM_GENERATOR
#define RANDOM_GENERATOR

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    ifstream file("dumpFile.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<string> words;
    string word;

    // reading and cleaning
    while (file >> word) {
        for (char& c : word) {
            if (ispunct(c)) {
                c = ' ';
            }
        }
        words.push_back(word);
    }

    file.close();

    if (words.empty()) {
        cout << "No words found in the file!" << endl;
        return 1;
    }

    // Pick a random word from the vector
    int randomIndex = rand() % words.size();
    string s = words[randomIndex];
    reverse(s.begin(), s.end());

    return s;
}

#endif
