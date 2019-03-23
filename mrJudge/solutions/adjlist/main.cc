#include <iostream>
#include <vector>

int main() {
  uint32_t N, E;
  std::cin >> N >> E;

  std::vector<std::vector<uint32_t>> adjlist(N);
  for (uint32_t i = 0; i < E; i++) {
    uint32_t A, B;
    std::cin >> A >> B;

    adjlist.at(A - 1).emplace_back(B);
    adjlist.at(B - 1).emplace_back(A);
  }

  for (auto row : adjlist) {
    for (uint32_t i = 0; i < row.size(); i++) {
      if (i > 0)
        std::cout << ' ';
      std::cout << row.at(i);
    }
    std::cout << '\n';
  }
}
