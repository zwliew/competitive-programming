#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>

int32_t tile(std::vector<std::vector<int32_t>> &grid,
          const int32_t &y, const int32_t &x,
          const uint32_t &H, const uint32_t &W) {
  if (y < 0 || y >= H || x < 0 || x >= W) return -1;
  return grid.at(y).at(x);
}

int main() {
  uint32_t H, W, N;
  std::cin >> H >> W >> N;

  std::vector<std::unordered_set<uint32_t>> counts(N);
  std::vector<std::vector<int32_t>> grid(H, std::vector<int32_t>(W, -1));

  for (uint32_t y = 0; y < H; y++) {
    auto &row = grid.at(y);
    for (uint32_t x = 0; x < W; x++) {
      std::cin >> row.at(x);
    }
  }

  for (uint32_t y = 0; y < H; y++) {
    auto &row = grid.at(y);
    for (uint32_t x = 0; x < W; x++) {
      const uint32_t &cur_id = row.at(x);
      std::unordered_set<uint32_t> &count = counts.at(cur_id);
      const std::array<int32_t, 4> ids = {
        tile(grid, y - 1, x, H, W),
        tile(grid, y + 1, x, H, W),
        tile(grid, y, x - 1, H, W),
        tile(grid, y, x + 1, H, W)
      };

      for (int32_t id : ids) {
        if (id != -1 && id != cur_id) {
          count.insert(id);
        }
      }
    }
  }

  for (auto &count : counts) {
    std::cout << count.size() << '\n';
  }
}
