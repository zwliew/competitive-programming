#include <iostream>
#include <vector>

std::vector<std::vector<int>> dp;

int _uniquePaths(const int x, const int y) {
  if (x < 0 || y < 0)
    return 0;

  if (!x && !y)
    return 1;

  int result = dp.at(x).at(y);
  if (result >= 0)
    return result;

  result = _uniquePaths(x - 1, y) + _uniquePaths(x, y - 1);
  dp.at(x).at(y) = result;
  return result;
}

int uniquePaths(const int m, int n) {
  dp = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));
  return _uniquePaths(m - 1, n - 1);
}

int main() {
  int m, n;
  std::cin >> m >> n;
  std::cout << uniquePaths(m, n);
}
