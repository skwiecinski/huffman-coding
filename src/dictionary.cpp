/** @file*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>

#include "functions.h"
#include "dictionary.h"
#include "file_usage.h"

using namespace std;

// Implementacja funkcji createDictionary - otwieranie pliku tekstowego oraz zapis znakow i ich czestotliwosci.
bool createDictionary(const int* characters, const string& dictionary_file) {
    ofstream file(dictionary_file, ios::binary);

    if (!file) {
        return false;
    }
    else {
        for (int i = 0; i < ASCII_COUNT; ++i) {
            if (characters[i] == 0) {
                continue;
            }
            else {
                file.write((char*)&i, 1);
                file.write((char*)&(characters[i]), sizeof(int));
            }
        }

        return true;
    }
}

// Implementacja funkcji readDictionary - czytanie slownika z pliku tekstowego oraz tworzenie na jego podstawie map<char, int>
bool readDictionary(const string& dictionary_file, int(&characters)[ASCII_COUNT]) {
    ifstream file(dictionary_file, ios::binary);

    if (!file) {
        return false;
    }
    else {
        while (!file.eof()) {
            char character;
            int freq;

            file.read(&character, sizeof(char));
            file.read((char*)(&freq), sizeof(int));

            if (file.eof()) {
                break;
            }

            characters[(unsigned char)character] = freq;
        }
    }

    return true;
}
