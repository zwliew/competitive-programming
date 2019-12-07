#include <iostream>
#include <vector>

int main() {
  uint32_t N, M;
  std::cin >> N >> M;

  uint32_t count = N;
  std::vector<bool> has_frens(N, false);
  for (uint32_t i = 0; i < M; i++) {
    uint32_t A, B;
    std::cin >> A >> B;

    if (A == B)
      continue;

    if (!has_frens.at(A)) {
      has_frens.at(A) = true;
      count--;
    }

    if (!has_frens.at(B)) {
      has_frens.at(B) = true;
      count--;
    }
  }

  std::cout << count;
}
