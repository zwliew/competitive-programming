#include <iostream>
#include <vector>

int main() {
  uint32_t N, E;
  std::cin >> N >> E;

  std::vector<std::vector<bool>> adjmat(N, std::vector<bool>(N, false));
  for (uint32_t i = 0; i < E; i++) {
    uint32_t A, B;
    std::cin >> A >> B;

    adjmat[A - 1][B - 1] = true;
    adjmat[B - 1][A - 1] = true;
  }

  for (auto row : adjmat) {
    for (auto el : row) {
      std::cout << el;
    }
    std::cout << '\n';
  }
}
