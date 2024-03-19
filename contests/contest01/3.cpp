#include <iostream>

int main() {
    int v, t;
    std::cin >> v >> t;
    int s = v*t;

    // v>0, t>0, s > 109 -> s % 109
    // v>0, t>0, s < 109 -> s
    // v<0, t>0, s > -109 -> 109 + s
    // v<0, t>0, s < -109 -> 109 + s % 109
    // simplier: s % 109 and if s < 0 -> 109 + s

    int result = s % 109;
    if (result < 0) result += 109;

    std::cout << result << std::endl;

    return 0;
}
