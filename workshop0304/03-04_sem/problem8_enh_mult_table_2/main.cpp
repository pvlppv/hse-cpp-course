////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 8: "Enhanced Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Modification of the Problem 7 (Multiplication Table), where a user can
/// repeat a solution multiple times (with using the “do..while” loop).
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int m, n;
    char repeat;

    do {
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
        
        std::cout << "Do you want to repeat? (y/n): ";
        std::cin >> repeat;

    } while (repeat == 'y');

    return 0;
}
