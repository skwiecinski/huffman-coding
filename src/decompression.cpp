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
#include "decompression.h"
#include "huffman.h"

using namespace std;

// Implementacja funkcji start_decompression - zarzadzanie kompresja pliku.
bool start_decompression(const vector<char>& input, string& dictionary_file, string& output_file) {
    // Odczyt danych z pliku oraz przypisanie ich do zmiennej characters.
    int characters[ASCII_COUNT]{ 0 };
    if (!readDictionary(dictionary_file, characters)) {
        return false;
    }

    priority_queue<huffmanBrench*, vector<huffmanBrench*>, CompareFreq> huffman_tree;

    // Tworzenie struktury na podstawie znakow i ich wystepowania w tekscie oraz dodanie ich do vectora gdzie nastepnie sa sortowanie funkcja sort_vector.
    for (int i = 0; i < ASCII_COUNT; i++) {
        if (characters[i] == 0) {
            continue;
        }
        else {
            huffmanBrench* brench = new huffmanBrench;
            brench->character = (char)i;
            brench->freq = characters[i];
            brench->left = nullptr;
            brench->right = nullptr;

            huffman_tree.push(brench);
        }
    }

    buildHuffmanTree(huffman_tree);
    if (decompression(input, output_file, huffman_tree)) {
        return true;
    }
    else {
        return false;
    }
    return true;
}

// Implementacja funkcji decompression - dekompresja pliku wejsciowego oraz zapis wyniku tego dzialania do pliku tekstowego podanego przez uzytkownika.
bool decompression(const vector<char>& input, const string output_file, priority_queue<huffmanBrench*, vector<huffmanBrench*>, CompareFreq>& huffman_tree) {
    ofstream file(output_file);

    if (!file) {
        return false;
    }
    else {
        huffmanBrench* current = huffman_tree.top();
        if (current->character != '\0') {
            for (char ch : input) {
                file.put(current->character);
            }
        }
        else {
            for (char ch : input) {
                if (current == nullptr) {
                    return false;
                }
                if (ch == '0' && current->left) {
                    current = current->left;
                }
                else if (ch == '1' && current->right) {
                    current = current->right;
                }
                else if (ch == '\n') {
                    break;
                }
                else {
                    return false;
                }

                // Jezeli left i right = nullptr oznacza to, ze doszlismy do znaku.
                if (current->left == nullptr && current->right == nullptr) {
                    file.put(current->character);
                    current = huffman_tree.top();
                }
            }
        }
        file.close();
    }
    return true;
}
