/** @file*/
#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

#include <map>
#include <string>
#include <vector>
#include <queue>

#include "functions.h"

/**
 * @brief Funkcja steruje dekompresj¹ pliku tekstowego oraz zapisuje wynik tego dzia³ania do pliku tekstowego podanego przez u¿ytkownika.
 *
 * @param input Vector charów, który przechowuje zawartoœæ pliku.
 * @param dictionary_file Nazwa pliku, z s³ownikiem zawieraj¹cym znaki i ich czêstotliwoœci wystêpowania w tekœcie.
 * @param output_file Nazwa pliku, do którego ma zostaæ wpisany wynik dekompresji metod¹ Huffmana.
 *
 * @return Zwraca true, gdy funkcja siê wykona prawid³owo.
 */
bool start_decompression(const std::vector<char>& input, std::string& dictionary_file, std::string& output_file);

/**
 * @brief Funkcja dekompresuje podany kod za pomoc¹ vectora z drzewkiem Huffmana.
 *
 * @param input Vector charów, który przechowuje zawartoœæ pliku.
 * @param output_file Œcie¿ka do pliku, w którym ma zostaæ zapisany wynik dekompresji.
 * @param huffman_tree Kolejka priorytetowa zawierajac¹ struktury "ga³êzie" Huffmana.
 *
 * @return Zwraca true, gdy funkcja siê wykona prawid³owo.
 */
bool decompression(const std::vector<char>& input, const std::string output_file, std::priority_queue<huffmanBrench*, std::vector<huffmanBrench*>, CompareFreq>& huffman_tree);



#endif
