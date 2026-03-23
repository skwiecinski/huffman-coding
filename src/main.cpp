/** @file*/

#include <iostream>
#include <string>

#include "functions.h"
#include "dictionary.h"
#include "compression.h"
#include "decompression.h"

using namespace std;

string input_file;
string output_file;
string dictionary_file;

string mode;

// Obsluga parametrow
int main(int argc, char* argv[]) {
	if (argc == 9) {
		for (int i = 1; i < argc; i += 2) {
			if (string(argv[i]) == "-t") {
				if (string(argv[i + 1]) == "k") {
					mode = "k";
				}
				else if (string(argv[i + 1]) == "d") {
					mode = "d";
				}
				else {
					cout << "Usage: -t <mode: k - compression, d - decompression> -i <input file txt> -o <output file txt> -s <dictionary file txt>";
					return 1;
				}
			}
			else if (string(argv[i]) == "-i") {
				input_file = string(argv[i + 1]);
			}
			else if (string(argv[i]) == "-o") {
				output_file = string(argv[i + 1]);
			}
			else if (string(argv[i]) == "-s") {
				dictionary_file = string(argv[i + 1]);
			}
			else {
				cout << "Usage: -t <mode: k - compression, d - decompression> -i <input file txt> -o <output file txt> -s <dictionary file txt>";
				return 1;
			}
		}
	}
	else {
		cout << "Usage: -t <mode: k - compression, d - decompression> -i <input file txt> -o <output file txt> -s <dictionary file txt>";
		return 1;
	}

	// Wywolanie konkretnej funkcji, ktore jest zalezne od podanego trybu pracy programu.
	if (mode == "k") {
		vector<char> input;
		if (openFile(input_file, input)) {
			if (start_compression(input, output_file, dictionary_file)) {
				cout << "-----COMPRESSION COMPLETED-----";
			}
			else {
				cerr << "Plik zostal niepoprawnie otwarty lub sciezka pliku jest niepoprawna.";
				return 1;
			}
		}
		else {
			cerr << "Plik zostal niepoprawnie otwarty lub sciezka pliku jest niepoprawna.";
			return 1;
		}
		return 0;
	}
	else {
		vector<char> input;
		if (openFile(input_file, input)) {
			if (start_decompression(input, dictionary_file, output_file)) {
				cout << "-----DECOMPRESSION COMPLETED-----";
			}
			else {
				cerr << "Plik zostal niepoprawnie otwarty lub sciezka pliku jest niepoprawna.";
				return 1;
			}
		}
		return 0;
	}

}
