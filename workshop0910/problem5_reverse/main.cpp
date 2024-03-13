///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program to read the content of a text file and write its content in reverse order to another file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>

void reverseFileContent(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);
    std::string s;
    while (getline(inputFile, s)) {
        std::string s2 = "";
        for (int i = 1; i <= s.length(); i++) {
            s2 += s[s.length() - i];
        }
        outputFile << s2;
    }

    inputFile.close();
    outputFile.close();
};

int main() {
    reverseFileContent("input.txt", "output_reversed.txt");
    return 0;
}
