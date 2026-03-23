/** @file*/
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <map>
#include <string>
#include <vector>

#include "functions.h"
#include "file_usage.h"

/**
 * @brief Funkcja czyta plik z s³ownikiem i zapisuje dane do tablicy.
 *
 * @param dictionary_file Nazwa pliku, z s³ownikiem zawieraj¹cym znaki i ich czêstotliwoœci wystêpowania w tekœcie.
 * @param characters Tablica, w której indeksy odpowiadaj¹ kodom ASCII, a wartoœci liczb¹ wyst¹pieñ znaku w pliku tekstowym podanym przez u¿ytkownika.
 *
 * @return Zwraca true, gdy funkcja siê wykona prawid³owo.
 */
bool readDictionary(const std::string& dictionary_file, int(&characters)[ASCII_COUNT]);

/**
 * @brief Funkcja zapisuje do pliku tekstowego znaki oraz iloœæ ich wystêpowañ.
 *
 * @param characters Tablica, w której indeksy odpowiadaj¹ kodom ASCII, a wartoœci liczb¹ wyst¹pieñ znaku w pliku tekstowym podanym przez u¿ytkownika.
 * @param dictionary_file Nazwa pliku, do którego ma zostaæ zapisane znaki oraz iloœæ ich wystêpowañ.
 *
 * @return Zwraca true, gdy funkcja siê wykona prawid³owo.
 */
bool createDictionary(const int* characters, const std::string& dictionary_file);

#endif
