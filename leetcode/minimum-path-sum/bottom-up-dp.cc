#include <algorithm>
#include <vector>

int minPathSum(std::vector<std::vector<int>> &grid) {
  int M = grid.at(0).size();
  int N = grid.size();

  for (int i = 1; i < M; i++) {
    grid.at(0).at(i) += grid.at(0).at(i - 1);
  }

  for (int i = 1; i < N; i++) {
    grid.at(i).at(0) += grid.at(i - 1).at(0);
  }

  for (int y = 1; y < N; y++) {
    for (int x = 1; x < M; x++) {
      grid.at(y).at(x) += std::min(grid.at(y).at(x - 1), grid.at(y - 1).at(x));
    }
  }

  return grid.back().back();
}
