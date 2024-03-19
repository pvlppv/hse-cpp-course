///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Find Maximum Element
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input and
/// finds the maximum element using pointers. Print the maximum element.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int arraySize;
    std::cin >> arraySize;

    int *array = new int[arraySize];
    for (int i = 0; i < arraySize; ++i) std::cin >> array[i];

    int *max = array;
    for (int i = 0; i < arraySize; ++i) if (array[i] > *max) max = &array[i];

    std::cout << *max << std::endl;

    delete[] array;
    
    return 0;
}
