#include <iostream>

int main() {
    int n, sum = 0;
    std::cin >> n;
    std::string n_str = std::to_string(n);

    for (int i = 0; i < n_str.length(); i++) {
        sum += std::stoi(std::string(1, n_str[i]));
    }

    std::cout << sum << std::endl;

    return 0;
}
