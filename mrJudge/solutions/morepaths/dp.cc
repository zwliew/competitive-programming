#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> vals;

inline int val(const int i, const int j) {
  if (i < 0 || j < 0)
    return 0;
  return vals.at(i).at(j);
}

int main() {
  int N, M, K;
  std::cin >> N >> M >> K;

  vals = std::vector<std::vector<int>>(N, std::vector<int>(M, 0));

  std::vector<std::vector<int>> grid(N, std::vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> grid.at(i).at(j);
    }
  }

  std::vector<int> largest_K(K);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      vals.at(i).at(j) =
          std::max(val(i, j - 1), val(i - 1, j)) + grid.at(i).at(j);
    }
  }

  std::cout << vals.at(N - 1).at(M - 1);
}
