///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program to count the number of lines, words, and characters in a text file.
///
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void countFileStatistics(std::ifstream& inputFile, int& letters, int& words, int& lines) {
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
    std::ifstream inputFile("file.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    int letters = 0;
    int words = 0;
    int lines = 0;

    countFileStatistics(inputFile, letters, words, lines);

    inputFile.close();

    std::cout << "Input file contains:" << std::endl;
    std::cout << letters << " letters" << std::endl;
    std::cout << words << " words" << std::endl;
    std::cout << lines << " lines" << std::endl;

    return 0;
}