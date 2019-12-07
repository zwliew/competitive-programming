#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  uint16_t N;
  std::cin >> N;

  std::vector<uint16_t> A(N), B(N);
  for (size_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  for (size_t i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  uint16_t X;
  std::cin >> X;

  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end(), std::greater<uint16_t>());

  uint16_t total = 0;
  for (size_t i = 0; i < N; i++) {
    int16_t diff = A.at(i) + B.at(i) - X;
    if (diff > 0)
      total += diff;
  }

  std::cout << total * 100;
}
