#include <iostream>

int main() {
    int n;
    std::cin >> n;
    float result = 0.0;

    for (int i = 0; i < n; i++) {
        result += (i % 2 == 0 ? 1.0 : -1.0) / (i + 1);
    }

    std::cout << result << std::endl;;

    return 0;
}
