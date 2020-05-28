#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> W;
std::vector<int> V;
std::vector<std::vector<int>> vals;

static int val(const int n, const int m) {
  if (n < 0 || m < 0)
    return 0;

  int stored = vals.at(n).at(m);
  if (stored != -1)
    return stored;

  stored = val(n - 1, m);
  if (m >= W.at(n)) {
    stored = std::max(
        stored, std::max(val(n, m - 1), val(n - 1, m - W.at(n)) + V.at(n)));
  }
  vals.at(n).at(m) = stored;

  return stored;
}

int main() {
  int N, M;
  std::cin >> N >> M;

  vals = std::vector<std::vector<int>>(N, std::vector<int>(M + 1, -1));
  W = std::vector<int>(N);
  V = std::vector<int>(N);
  for (int i = 0; i < N; i++) {
    std::cin >> W.at(i) >> V.at(i);
  }

  std::cout << val(N - 1, M);
}
