///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Copy Array
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input,
/// creates a new array, copies the elements from the original array to the new
/// array using pointers, and then prints the new array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int arraySize;
    std::cin >> arraySize;

    int *arr1 = new int[arraySize];
    int *arr2 = new int[arraySize];

    for (int i = 0; i < arraySize; i++) std::cin >> arr1[i];

    for (int i = 0; i < arraySize; i++) {
        int *a = &arr1[i];
        arr2[i] = *a;
    }

    for (int i = 0; i < arraySize; i++) {
        std::cout << arr2[i] << " ";
    }

    return 0;
}
