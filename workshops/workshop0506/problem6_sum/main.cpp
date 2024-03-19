///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Sum of Two Numbers
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads two integers from the standard input and calculates
/// their sum using pointers. Print the result.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int *a, *b, n, k;
    std::cin >> n >> k;

    a = &n;
    b = &k;

    int s = *a + *b;

    std::cout << s << std::endl;

    return 0;
}
