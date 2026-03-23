/** @file*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>
#include <queue>

#include "functions.h"
#include "dictionary.h"
#include "file_usage.h"
#include "compression.h"
#include "huffman.h"

using namespace std;

// Implementacja funkcji compression - zarzadzanie kompresja pliku.
bool start_compression(const vector<char>& input, const string& output_file, const string& dictionary_file) {
    int characters[ASCII_COUNT]{ 0 };
    characterCount(input, characters);

    // Zapis do pliku tekstowego znakow i ilosci ich wystepowania.
    if (!createDictionary(characters, dictionary_file)) {
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

    // Tworzenie drzewka Huffmana - ³aczenie dwoch najmniejszych czestoliwosci w jedna ga³az oraz wpisanie nowej ga³ezi do vectora.
    buildHuffmanTree(huffman_tree);

    string huffmanCodes[ASCII_COUNT];

    // Tworzenie kodow dla poszczegolnych znakow.

    int characters_count = 0;
    for (int i = 0; i < ASCII_COUNT; i++) {
        if (characters[i] == 0) {
            continue;
        }
        else {
            characters_count++;
        }

        if (characters_count == 1) {
            huffmanCodes[(char)i] = "0";
        }
        else {
            huffmanBrench* temp = huffman_tree.top();
            createHuffmanCode(temp, huffmanCodes);
        }
    }

    if (!writeToOutput(input, huffmanCodes, output_file)) {
        return false;
    }

    return true;
}
