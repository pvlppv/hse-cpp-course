///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Set Bit
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n and a position k as input. The program
/// should set (change to 1) the k-th bit of the integer n and print the resulting
/// number in binary and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{      
    int n, k;
    std::cin >> n >> k;

    std::bitset<32> n_bits (n);

    n_bits[k] = 1;

    std::cout << n_bits << std::endl;
    std::cout << n << std::endl;


    return 0;
}
