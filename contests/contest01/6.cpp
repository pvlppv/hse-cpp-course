#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::string line = "\t";

    for (int k = 1; k < n+1; k++) {
        line += std::to_string(k) + "\t";
    }
    
    std::cout << line << std::endl;
    for (int i = 1; i <= n; i++) {
        line = std::to_string(i) + "\t";
        for (int j = 1; j < n+1; j++) {
            int product = (i * j) % m;
            line += std::to_string(product) + "\t";
        }
        std::cout << line << std::endl;
    }
}