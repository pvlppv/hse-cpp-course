////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 5: "Print ASCII table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Print the “printable part” of the ASCII table using tabs for aligning.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    for (int i = 32; i < 127; i++) {
        std::cout << char(i) << "\t";
    }
    return 0;
}
