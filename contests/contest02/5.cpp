#include <iostream>

std::string add_number(std::string N) {
    int add = 1;
    for (int i = N.length() - 1; i >= 0 && add; --i) {
        if (N[i] == '9') N[i] = '0';
        else {
            N[i]++; 
            add = 0;
        }
    }
    if (add) N = '1' + N;
    return N;
}

int main() {
    std::string N;
    std::cin >> N;
    
    std::cout << add_number(N) << std::endl;

    return 0;
}