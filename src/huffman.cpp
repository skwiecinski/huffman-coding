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
#include "huffman.h"
#include <queue>

using namespace std;

// Implementacja funkcji buildHuffmanTree - budowanie drzewka Huffmana na podstawie czestotliwosci znakow przechowywanacyh w vectorze.
void buildHuffmanTree(priority_queue<huffmanBrench*, vector<huffmanBrench*>, CompareFreq>& huffman_tree) {
    // Dopoki drzewko nie zawiera tylko jednej struktury.
    while (huffman_tree.size() > 1) {

        // Przypisanie do zmiennej struktury, ktora ma najmniejsza czestotliwosc oraz jej usuniecie.
        huffmanBrench* first = huffman_tree.top();
        huffman_tree.pop();

        huffmanBrench* second = huffman_tree.top();
        huffman_tree.pop();

        // Tworzenie nowej struktury, ktora przechowuje dwie inne.
        huffmanBrench* root = new huffmanBrench;
        root->character = '\0';
        root->freq = first->freq + second->freq;
        root->left = first;
        root->right = second;

        huffman_tree.push(root);
    }
}

// Implementacja funkcji createHuffmanCode - tworzenie mapy z kodami dla poszczegolnych znakow.
void createHuffmanCode(huffmanBrench*& brench, string(&huffmanCodes)[ASCII_COUNT]) {
    string code = "";

    generateHuffmanCode(brench, huffmanCodes, code);
}

// Implementacja funkcji generateHuffmanCode - generowanie kodow dla poszczegolnych znakow.
void generateHuffmanCode(huffmanBrench*& brench, string(&huffmanCodes)[ASCII_COUNT], string code) {
    if (brench == nullptr) {
        return;
    }

    // Dojscie na sam dol drzewka Huffmana
    if (brench->left == nullptr && brench->right == nullptr) {
        huffmanCodes[(unsigned char)brench->character] = code;
    }

    generateHuffmanCode(brench->left, huffmanCodes, code + "0");
    generateHuffmanCode(brench->right, huffmanCodes, code + "1");
}
