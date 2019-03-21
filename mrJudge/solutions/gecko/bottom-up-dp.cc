#include <array>
#include <iostream>

std::array<std::array<int, 500>, 500> sums;

int tile(const int i, const int j, const int W) {
  if (i < 0 || j < 0 || j >= W) {
    return 0;
  }
  return sums[i][j];
}

int main() {
  int H, W;
  std::cin >> H >> W;

  std::array<std::array<int, 500>, 500> tiles;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      std::cin >> tiles[i][j];
    }
  }

  std::copy(tiles[0].begin(), tiles[1].end(), sums[0].begin());

  for (int i = 1; i < H; i++) {
    for (int j = 0; j < W; j++) {
      sums[i][j] = std::max(std::max(tile(i - 1, j - 1, W), tile(i - 1, j, W)),
                            tile(i - 1, j + 1, W)) +
                   tiles[i][j];
    }
  }

  int max = 0;
  for (int i = 0; i < W; i++) {
    max = std::max(max, sums[H - 1][i]);
  }
  std::cout << max;
}
