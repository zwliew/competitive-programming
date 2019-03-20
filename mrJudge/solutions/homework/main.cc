#include <algorithm>
#include <array>
#include <iostream>

std::array<uint32_t, 3000001> d;

int main() {
  size_t N;
  std::cin >> N;

  uint32_t count = 0;
  uint32_t tmp;
  for (size_t i = 0; i < N; i++) {
    std::cin >> tmp;
    if (tmp <= 365) {
      d.at(i) = tmp;
      count++;
    }
  }

  if (count) {
    std::sort(d.begin(), d.begin() + count);

    std::cout << d.at(0);
    for (size_t i = 1; i < count; i++) {
      std::cout << " " << d.at(i);
    }
  }

  std::cout << "\n";
}
