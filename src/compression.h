/** @file*/
#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <map>
#include <string>
#include <vector>

/**
 * @brief Funkcja steruje kompresj¹ pliku tekstowego - tworzy tablicê z znakami oraz ich czêstotliwoœciami, tworzy drzewko Huffmana.
 *
 * @param input Vector charów, który przechowuje zawartoœæ pliku.
 * @param output_file Nazwa pliku, do którego ma zostaæ zapisany wynik kompresji metod¹ Huffmana.
 * @param dictionary_file Nazwa pliku, do którego ma zostaæ zapisany s³ownik dotycz¹cy drzewka Huffmana.
 *
 * @return Zwraca true, gdy funkcja siê wykona prawid³owo.
 */
bool start_compression(const std::vector<char>& input, const std::string& output_file, const std::string& dictionary_file);

#endif
