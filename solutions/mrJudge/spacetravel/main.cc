#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  uint16_t N, S;
  std::cin >> N >> S;

  std::vector<uint16_t> t(N);
  for (size_t i = 0; i < N; i++) {
    std::cin >> t.at(i);
  }

  std::sort(t.begin(), t.end(), std::greater<uint16_t>());

  uint32_t sum = 0;
  for (size_t i = 0; i < N; i++) {
    if (S) {
      sum += t.at(i);
      S--;
    } else {
      sum += t.at(i) * 2;
    }
  }

  std::cout << sum;
}
