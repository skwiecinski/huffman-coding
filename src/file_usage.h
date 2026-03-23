/** @file*/
#ifndef FILE_USAGE_H
#define FILE_USAGE_H

#include <map>
#include <string>
#include <vector>

/**
 * @brief Funkcja otwiera plik tekstowy ".txt" oraz czyta jego zawartoœæ.
 *
 * @param fileName Nazwa pliku, który ma zostaæ otwarty.
 * @param content Vector charów, który przechowuje zawartoœæ pliku.
 *
 * @return Zwraca true, gdy funkcja siê wykona prawid³owo.
 */
bool openFile(const std::string& fileName, std::vector<char>& content);

/**
 * @brief Funkcja zapisuje do pliku tekstowego wynik koñcowy kompresji metod¹ Huffmana.
 *
 * @param input Vector charów, który przechowuje zawartoœæ pliku.
 * @param huffmanCodes Tablica, w której indeksy odpowiadaj¹ kodom ASCII, a wartoœci s¹ kodami w wyniku kompresji Huffmana.
 * @param output_file Œcie¿ka pliku tekstowego, do którego ma byæ zapisany wynik koñcowy kompresji metod¹ Huffmana.
 *
 * @return Zwraca true, gdy funkcja siê wykona prawid³owo.
 */
bool writeToOutput(const std::vector<char>& input, std::string(&huffmanCodes)[ASCII_COUNT], const std::string& output_file);

#endif
