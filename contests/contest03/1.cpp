#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void compute_sizes(std::ifstream& inputFile, int& letters, int& words, int& lines) {
    bool inWord = false;
    char letter;
    while (inputFile.get(letter)) {
        if (std::isalpha(letter)) {
            letters++;
            if (!inWord) {
                inWord = true;
                ++words;
            }
        }
        else if (letter == '\n') {
            lines++;
            inWord = false;
        }
        else {
            inWord = false;
        }
    }
}

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    int letters = 0;
    int words = 0;
    int lines = 0;

    compute_sizes(inputFile, letters, words, lines);

    inputFile.close();

    std::cout << "Input file contains:" << std::endl;
    std::cout << letters << " letters" << std::endl;
    std::cout << words << " words" << std::endl;
    std::cout << lines << " lines" << std::endl;

    return 0;
}