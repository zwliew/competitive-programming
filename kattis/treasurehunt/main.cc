#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int r, c;
  cin >> r >> c;
  vector<vector<char>> v(r, vector<char>(c, 0));
  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      cin >> v[y][x];
    }
  }

  r = c = 0;
  int cnt = 0;
  while (1) {
    char o = v[r][c];
    v[r][c] = 0;
    if (o == 'E') {
      ++c;
    } else if (o == 'S') {
      ++r;
    } else if (o == 'W') {
      --c;
    } else if (o == 'N') {
      --r;
    } else if (!o) {
      cout << "Lost";
      return 0;
    } else if (o == 'T') {
      cout << cnt;
      return 0;
    }
    if (r >= v.size() || c >= v[0].size() || r < 0 || c < 0) {
      cout << "Out";
      return 0;
    }
    ++cnt;
  }
}