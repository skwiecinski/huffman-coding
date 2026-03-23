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

// Implementacja funkcji characterCount - zliczanie znakow w podanym tekscie
void characterCount(const vector<char>& input, int(&characters)[ASCII_COUNT]) {
    for (char ch : input) {
        if (ch == '\r') {
            continue;
        }
        else {
            characters[(unsigned char)ch]++;
        }
    }
}