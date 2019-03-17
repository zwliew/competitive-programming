#include <array>
#include <iostream>

std::array<std::array<int, 500>, 500> sums;
std::array<std::array<int, 500>, 500> tiles;

int sum(const int i, const int j, const int W) {
  if (i < 0 || j < 0 || j >= W)
    return 0;

  if (sums[i][j] > 0)
    return sums[i][j];

  sums[i][j] = std::max(sum(i - 1, j - 1, W),
                        std::max(sum(i - 1, j, W), sum(i - 1, j + 1, W))) +
               tiles[i][j];
  return sums[i][j];
}

int main() {
  int H, W;
  std::cin >> H >> W;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      std::cin >> tiles[i][j];
    }
  }

  std::copy(tiles[0].begin(), tiles[1].end(), sums[0].begin());
  for (int i = 1; i < H; i++) {
    sums[i].fill(0);
  }

  int max = 0;
  for (int i = 0; i < W; i++) {
    max = std::max(max, sum(H - 1, i, W));
  }
  std::cout << max;
}
