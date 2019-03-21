#include <vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
  if (obstacleGrid.at(0).at(0))
    return 0;

  const int M = obstacleGrid.at(0).size();
  const int N = obstacleGrid.size();

  // Convert to a 2D vector of unsigned ints
  // to avoid signed integer overflows
  std::vector<std::vector<unsigned int>> num(N,
                                             std::vector<unsigned int>(M, -1));

  num.at(0).at(0) = 1;

  for (int i = 1; i < M; i++) {
    num.at(0).at(i) = obstacleGrid.at(0).at(i) ? 0 : num.at(0).at(i - 1);
  }

  for (int i = 1; i < N; i++) {
    num.at(i).at(0) = obstacleGrid.at(i).at(0) ? 0 : num.at(i - 1).at(0);
  }

  for (int y = 1; y < N; y++) {
    for (int x = 1; x < M; x++) {
      num.at(y).at(x) = obstacleGrid.at(y).at(x)
                            ? 0
                            : num.at(y).at(x - 1) + num.at(y - 1).at(x);
    }
  }

  return num.back().back();
}
