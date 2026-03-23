/** @file*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <map>
#include <string>
#include <vector>

constexpr int ASCII_COUNT = 256;

/**
 * @brief Struktura przechowuj¹ca znak, iloœæ jego wystêpowania oraz lew¹ jak i praw¹ podstukturê drzewka Huffmana.
 *
 * @param character Znak w tekœcie.
 * @param freq Iloœæ wystêpowania znaku.
 * @param left Lewa podstruktura drzewka Huffmana; domyœlnie "nullptr".
 * @param right Prawa podstruktura drzewka Huffmana; domyœlnie "nullptr".
 *
 */
struct huffmanBrench {
    char character;
    int freq;
    huffmanBrench* left;
    huffmanBrench* right;
};

struct CompareFreq {
    bool operator()(huffmanBrench* left, huffmanBrench* right) {
        return left->freq > right->freq;
    }
};

/**
 * @brief Funkcja oblicza liczbê wyst¹pieñ ka¿dego znaku w podanym tekœcie.
 *
 * @param input Vector charów, który przechowuje zawartoœæ pliku.
 * @param characters Tablica, w której indeksy odpowiadaj¹ kodom ASCII, a wartoœci liczb¹ wyst¹pieñ znaku w pliku tekstowym podanym przez u¿ytkownika.
 *
 * @return Zwraca true, gdy funkcja siê wykona prawid³owo.
 */
void characterCount(const std::vector<char>& input, int(&characters)[ASCII_COUNT]);

#endif

