/*******************************************************************************
 *  Workshop 2/Task 2
 *
 *  Studying input, output, conditions and simple loops.
 *
 *  A program outputs a formatted multiplication table for n numbers.
 *
 *  Example. For n = 3, the output is:
 *
 *      1   2   3
 *  1   1   2   3
 *  2   2   4   6
 *  3   3   6   9
 *
 *  1) Ask a user to input a boundary n for the table.
 *  2) Check whether n is in the range [1; 10] using if statement. Otherwise
 *     output the following message: "Wrong argument", and terminate the program.
 *  3) Output a table row by row using for-loop statement. Use tabs to separate
 *     individual values.
 *  4) Modify the program. Use while-loop statement.
 *
 ******************************************************************************/

#include <iostream>

// the entrypoint of the application
int main() {
    int n;
    std::string line;
    std::cin >> n;
    if (n <= 10 && n >= 1) {
        line = "    ";
        for (int k = 1; k < n+1; k++) {
            line += std::to_string(k) + "   ";
        }
        std::cout << line << std::endl;
        line = "";
        for (int i = 1; i < n+1; i++) {
            line = std::to_string(i) + "   ";
            for (int j = 1; j < n+1; j++) {
                int product = i * j;
                line += std::to_string(product) + "   ";
            }
            std::cout << line << std::endl;
        }
    }
    else {
        std::cout << "Wrong argument" << std::endl;
        return 0;
    }
    return 0;
}
