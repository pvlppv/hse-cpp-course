#include <iostream>

int main() {
    int N, K, M;
    std::cin >> N >> K >> M;
    int result = 0; 

    if ((N != 0 && K != 0 && M != 0) && (N >= K && K >= M)) {
        while (N / K) {
            int zagatovki = N / K;
            result += zagatovki * (K / M);
            N %= K;
            N += zagatovki * (K % M);
        }
    }  

    std::cout << result << std::endl;
    
    return 0;
}