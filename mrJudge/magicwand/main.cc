#include <bits/stdc++.h>
using namespace std;

array<array<int16_t, 501>, 501> selected, grid;
array<pair<int16_t, int16_t>, 4> deltas = {make_pair(1, 0), make_pair(-1, 0),
                                           make_pair(0, 1), make_pair(0, -1)};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int16_t H, W, X, Y, T;
  std::cin >> H >> W >> X >> Y >> T;

  for (int16_t i = 0; i < selected.size(); ++i) {
    fill_n(selected[i].begin(), selected[i].size(), -1);
    fill_n(grid[i].begin(), grid[i].size(), -1);
  }

  for (int16_t x = 0; x < H; ++x) {
    for (int16_t y = 0; y < W; ++y) {
      cin >> grid[x][y];
    }
  }

  const int16_t orig_px = grid[X - 1][Y - 1];

  queue<pair<int16_t, int16_t>> neighbours;
  neighbours.emplace(X - 1, Y - 1);
  while (!neighbours.empty()) {
    const pair<int16_t, int16_t> cur = neighbours.front();
    neighbours.pop();

    if (selected[cur.first][cur.second] != -1) {
      continue;
    }

    selected[cur.first][cur.second] = 1;

    for (auto delta : deltas) {
      const pair<int16_t, int16_t> next(cur.first + delta.first,
                                        cur.second + delta.second);
      if (next.first < 0 || next.second < 0 || next.first >= H ||
          next.second >= W)
        continue;

      if (selected[next.first][next.second] != -1) continue;

      const int16_t next_px = grid[next.first][next.second];
      if (next_px > orig_px + T || orig_px > next_px + T) {
        selected[next.first][next.second] = 0;
        continue;
      }

      neighbours.push(next);
    }
  }

  for (int16_t i = 0; i < H; ++i) {
    for (int16_t j = 0; j < W; ++j) {
      cout << (selected[i][j] == -1 ? 0 : selected[i][j]);
    }
    cout << '\n';
  }
}