#include "iostream"
#include "sstream"
#include "fstream"

// sstream
std::string line;
std::getline(fileStream, line);
std::stringstream ss(line);
std::string field;
std::getline(ss, field, ';');
