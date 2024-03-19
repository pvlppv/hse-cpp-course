#include <iostream>

int main() {
    int first_cell, first_row, last_cell, last_row;
    std::cin >> first_cell >> first_row >> last_cell >> last_row;
    
    // 1) row way
    if (first_row == last_row) std::cout << "YES" << std::endl;
    // 2) cell way
    else if (first_cell == last_cell) std::cout << "YES" << std::endl;
    // 3) diagonal way
    else if ((first_cell - first_row == last_cell - last_row) || (first_cell + first_row == last_cell + last_row)) std::cout << "YES" << std::endl;
    // 4) no way
    else std::cout << "NO" << std::endl;

    return 0;
}
