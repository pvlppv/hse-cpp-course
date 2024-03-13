///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Count Elements
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input and
/// counts the number of elements in the array using pointers. Print the count.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int arraySize, counter = 0;
    std::cin >> arraySize;

    int *array = new int[arraySize];
    for (int i = 0; i < arraySize; ++i) std::cin >> array[i];

    int *count = &counter;
    for (int i = 0; i < arraySize; ++i) if (*count < array[i]) *count += 1;

    std::cout << *count << std::endl;

    delete[] array;

    return 0;
}
