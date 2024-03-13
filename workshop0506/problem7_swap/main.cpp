///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Swap Variables
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads two integers from the standard input and swaps
/// their values using pointers. Print the swapped values.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int *a, *b, *c, n, k;
    std::cin >> n >> k;

    a = &n;
    b = &k;
    c = a;
    a = b;
    b = c;
    
    std::cout << *a << " " << b << std::endl;

    return 0;
}
