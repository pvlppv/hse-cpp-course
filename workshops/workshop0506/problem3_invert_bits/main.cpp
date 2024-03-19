///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Bitwise Complement
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n as input and performs bitwise complement
/// (inverts all bits) on it. Print the resulting number in binary and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    std::cout << std::bitset<32>(~n) << std::endl;
    std::cout << ~n << std::endl; 

    // while ((n & (1 << 31)) == 0) {
    //     n <<= 1;
    // }
    return 0;
}
