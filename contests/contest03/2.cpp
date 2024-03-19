#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> p(N);
  std::vector<int> p_inverse(N);

  for (int i = 0; i < N; i++) {
    std::cin >> p[i];
  }

  for (int i = 1; i <= N; i++) {
    p_inverse[p[i - 1] - 1] = i;
  }

  for (int i = 0; i < N; i++) {
    std::cout << p_inverse[i] << " ";
  }
  std::cout << std::endl;
}