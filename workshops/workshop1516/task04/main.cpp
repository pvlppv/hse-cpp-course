#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

/*
Create a program that manages a dictionary of terms and their definitions.
*/

// Function to load dictionary from a file
void loadDictionary(const std::string& filename, std::map<std::string, std::string>& dictionary) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string term, definition;
        if (std::getline(ss, term, ':') && std::getline(ss, definition)) {
            dictionary[term] = definition;
        }
    }

    file.close();
}

// Function to display definition of a term
void lookupTerm(const std::string& term, const std::map<std::string, std::string>& dictionary) {
    if (dictionary.count(term) == 0) {
        std::cout << "not found!" << std::endl;
    } else {
        std::cout << "Definition of " << term << ": " << dictionary.at(term) << std::endl;
    }
}

// Function to add a new term-definition pair to the dictionary
void addTerm(std::map<std::string, std::string>& dictionary) {
    std::string term, definition;
    std::cout << "Enter term: ";
    std::cin >> term;
    std::cout << "Enter definition: ";
    std::getline(std::cin >> std::ws, definition);
    dictionary[term] = definition;
    std::cout << "Term added successfully." << std::endl;
}

// Function to delete a term from the dictionary
void deleteTerm(const std::string& term, std::map<std::string, std::string>& dictionary) {
    if (dictionary.count(term) == 0) {
        std::cout << "not found!" << std::endl;
    } else {
        dictionary.erase(term);
        std::cout << "Term deleted!" << std::endl;
    }
}

// Function to save dictionary to a file
void saveDictionary(const std::string& filename, const std::map<std::string, std::string>& dictionary) {
    std::ofstream file(filename);
    for (const auto& pair : dictionary) {
        file << pair.first << ":" << pair.second << std::endl;
    }

    file.close();
    std::cout << "Dictionary saved!!!" << std::endl;
}

int main() {
    std::map<std::string, std::string> dictionary;
    std::string filename = "dictionary.txt";
    loadDictionary(filename, dictionary);

    int choice;
    std::string term;

    do {
        std::cout << "\nDictionary Application\n"
                  << "1. Look up a term\n"
                  << "2. Add a new term\n"
                  << "3. Delete a term\n"
                  << "4. Save dictionary to file\n"
                  << "5. Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter term to search: ";
                std::cin >> term;
                lookupTerm(term, dictionary);
                break;
            case 2:
                addTerm(dictionary);
                break;
            case 3:
                std::cout << "Enter term to delete: ";
                std::cin >> term;
                deleteTerm(term, dictionary);
                break;
            case 4:
                saveDictionary(filename, dictionary);
                break;
            case 5:
                break;
            default:
                std::cout << "incorrect choice!!" << std::endl;
        }
    } while (choice != 5);

    return 0;
}

