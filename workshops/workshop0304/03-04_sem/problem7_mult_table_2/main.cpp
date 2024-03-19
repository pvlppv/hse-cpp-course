////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 7: "Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Program asks a user for two numbers, 1 <= (m, n) <= 8 and prints a rectangle
/// multiplication table aligning output at tab positions.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::string line = "\t";

    for (int k = 1; k < n+1; k++) {
        line += std::to_string(k) + "\t";
    }
    
    std::cout << line << std::endl;
    for (int i = 1; i <= m; i++) {
        line = std::to_string(i) + "\t";
        for (int j = 1; j < n+1; j++) {
            int product = i * j;
            line += std::to_string(product) + "\t";
        }
        std::cout << line << std::endl;
    }
}
