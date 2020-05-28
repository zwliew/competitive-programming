#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> dp;

int tile(const int x, const int y) {
  if (x < 0 || y < 0)
    return 0;
  return dp.at(x).at(y);
}

int uniquePaths(const int m, const int n) {
  dp = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));
  dp.at(0).at(0) = 1;

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      if (!x && !y)
        continue;
      dp.at(x).at(y) = tile(x - 1, y) + tile(x, y - 1);
    }
  }

  return dp.at(m - 1).at(n - 1);
}

int main() {
  int m, n;
  std::cin >> m >> n;
  std::cout << uniquePaths(m, n);
}
