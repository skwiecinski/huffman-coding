/** @file*/
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <map>
#include <string>
#include <vector>
#include <queue>

#include "functions.h"

/**
 * @brief Funkcja tworzy drzewko Huffmana na podstawie czêstotliwoœci wystêpowania znaków, które s¹ przechowywane w priority_queue huffman_tree.
 *
 * @param huffman_tree huffman_tree Kolejka priorytetowa zawierajac¹ struktury "ga³êzie" Huffmana.
 */
void buildHuffmanTree(std::priority_queue<huffmanBrench*, std::vector<huffmanBrench*>, CompareFreq>& huffman_tree);

/**
 * @brief Funkcja tworzy tablice, do której zapisywane s¹ kody binarne poszczególnych znaków w podanym pliku tekstowym.
 *
 * @param brench Struktura "drzewa" Huffmana.
 * @param huffmanCodes Tablica, w której indeksy odpowiadaj¹ kodom ASCII, a wartoœci s¹ kodami w wyniku kompresji Huffmana.
 */
void createHuffmanCode(huffmanBrench*& brench, std::string(&huffmanCodes)[ASCII_COUNT]);

/**
 * @brief Funkcja rekurencyjna, która tworzy kody binarne dla poszczególnych znaków.
 *
 * @param brench Struktura "drzewa" Huffmana.
 * @param huffmanCodes Tablica, w której indeksy odpowiadaj¹ kodom ASCII, a wartoœci s¹ kodami w wyniku kompresji Huffmana.
 * @param code Tymczasowa zmienna, do której s¹ dodawane kolejne cyfry kodu.
 */
void generateHuffmanCode(huffmanBrench*& brench, std::string(&huffmanCodes)[ASCII_COUNT], std::string code);

#endif
