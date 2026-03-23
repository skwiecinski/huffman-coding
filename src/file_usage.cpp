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

// Implementacja funkcji openFile - otwieranie pliku oraz przypisanie jego zawartosci do zmiennej
bool openFile(const string& fileName, vector<char>& content) {
    ifstream file(fileName, ios::binary);

    if (!file) {
        return false;
    }

    file.seekg(0, std::ios::end);
    streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    vector<char> temp(fileSize);

    file.read(temp.data(), fileSize);

    content = temp;
    return true;
}

// Implementacja funkcji writeToOutput - funkcja zapisuje tekst w postaci kodow, ktore reprezentuja znaki do pliku tekstowego, ktory podal uzytkownik.
bool writeToOutput(const vector<char>& input, string(&huffmanCodes)[ASCII_COUNT], const string& output_file) {
    string content;

    ofstream file(output_file);

    if (!file) {
        return false;
    }
    else {
        for (char ch : input) {
            content += huffmanCodes[(unsigned char)ch];
        }
        file << content;
    }
    return true;
}
