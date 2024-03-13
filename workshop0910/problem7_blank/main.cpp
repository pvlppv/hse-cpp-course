///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that removes all blank lines from a text file and writes the result to a new file.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    std::string s;
    while (getline(inputFile, s)) {
        if (s != "") {
            outputFile << s << "\n";
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
