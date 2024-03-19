#include <iostream>

int remainder(int K, std::string N) {
    int remainder = 0;

    for (int i = 0; i < N.length(); i++) {
        int current = N[i] - '0';
        remainder = (remainder * 10 + current) % K;
    }
    
    return remainder;
}

int main() {
    int K;
    std::string N;
    std::cin >> K >> N;
    
    std::cout << remainder(K, N) << std::endl;

    return 0;
}