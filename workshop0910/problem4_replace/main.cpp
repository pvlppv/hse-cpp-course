///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to find and replace all occurrences of a word in a file.
///
///////////////////////////////////////////////////////////////////////////////

#include <fstream> // For fstream
#include <sstream> // For stringstream

void findAndReplaceInFile(const std::string& filePath, const std::string& toFind, const std::string& toReplace) {
    std::ifstream inputFile(filePath);
    std::ofstream outputFile("output.txt");
    std::string s;
    while (getline(inputFile, s)) {
        size_t pos = s.find(toFind); 
        s.replace(pos, toFind.length(), toReplace);
        outputFile << s;
    }

    inputFile.close();
    outputFile.close();
};

int main() {
    findAndReplaceInFile("file.txt", "oldWord", "newWord");    
    return 0;
}