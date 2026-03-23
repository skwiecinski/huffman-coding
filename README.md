# Huffman Coding

Command-line tool for lossless text compression and decompression using the Huffman algorithm.

## Description

This project is a complete, command-line implementation of the Huffman coding algorithm written in C++. It allows users to significantly reduce the size of text files by analyzing character frequencies and building an optimal binary prefix tree (Huffman Tree). 

The program operates in two phases: it can compress a standard text file into a sequence of generated binary codes while exporting a `.bin` dictionary, and it can accurately decompress the data back to its original state using that exact dictionary. The codebase is fully modularized, uses modern standard library features (`std::priority_queue`, `std::map`), and includes Doxygen-style documentation.

## Getting Started

### Dependencies

* A C++ compiler that supports C++17 (e.g., `g++` or `clang`).
* `make` build automation tool.
* Cross-platform: works on Linux, macOS, and Windows (via WSL or MinGW).

### Installing

* Clone this repository to your local machine:
```bash
git clone https://github.com/skwiecinski/huffman-coding.git
```
* Navigate into the project directory:
```bash
cd huffman-coding
```
* Compile the source code using the provided Makefile:
```bash
make
```

### Executing program

The program is executed via the command line interface and requires flags to specify the mode, input file, output file, and dictionary file.

* **Mode `k` (Compression):**
Analyzes the text, creates a binary dictionary, and outputs the compressed string.
```bash
./huffman_app -t k -i input.txt -o compressed.txt -s dictionary.bin
```

* **Mode `d` (Decompression):**
Reads the compressed file and the previously generated dictionary to restore the original text.
```bash
./huffman_app -t d -i compressed.txt -o decompressed.txt -s dictionary.bin
```

## Help

**Common Issues:**
If the console outputs `Plik zostal niepoprawnie otwarty lub sciezka pliku jest niepoprawna.`, please verify that:
* The input file specified after the `-i` flag actually exists in your current directory.
* You have the necessary read/write permissions in the folder.
* You are providing all 4 required flags (`-t`, `-i`, `-o`, `-s`).

## Authors

Szymon Kwieciński
[@skwiecinski](https://github.com/skwiecinski)

## Version History

* 0.1
    * Initial Release - Core compression and decompression functionality, CLI implementation, and Makefile.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.

## Acknowledgments

* Implementation based on standard Data Structures and Algorithms (Huffman Tree).
* [Doxygen](https://doxygen.nl/) used for code documentation standards.
