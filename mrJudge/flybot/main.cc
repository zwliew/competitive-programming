#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;

  vector<vector<int>> r(h + 1, vector<int>(w + 1, 0));
  r[1][1] = 1;

  for (int hi = 1; hi <= h; ++hi) {
    for (int wi = 1; wi <= w; ++wi) {
      char c;
      cin >> c;
      if (c == 'X') {
        r[hi][wi] = -1;
      }
    }
  }

  for (int y = 1; y <= h; ++y) {
    for (int x = 1; x <= w; ++x) {
      if (y == x && x == 1) continue;
      if (r[y][x] == -1) {
        r[y][x] = 0;
        continue;
      }
      r[y][x] = (r[y - 1][x] + r[y][x - 1]) % 1000000007;
    }
  }

  cout << r[h][w];
}