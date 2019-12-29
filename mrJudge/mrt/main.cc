#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint64_t n, e, q;
  cin >> n >> e >> q;

  vector<vector<uint64_t>> v(n, vector<uint64_t>(n, UINT32_MAX));
  for (uint64_t i = 0; i < n; ++i) {
    v[i][i] = 0;
  }

  for (uint64_t ei = 0; ei < e; ++ei) {
    uint64_t x, y, t;
    cin >> x >> y >> t;

    v[x][y] = t;
    v[y][x] = t;
  }

  for (uint64_t k = 0; k < n; ++k) {
    for (uint64_t i = 0; i < n; ++i) {
      for (uint64_t j = 0; j < n; ++j) {
        if (v[i][j] > v[i][k] + v[k][j]) {
          v[i][j] = v[i][k] + v[k][j];
        }
      }
    }
  }

  for (uint64_t qi = 0; qi < q; ++qi) {
    uint64_t a, b;
    cin >> a >> b;

    if (v[a][b] > 1e9) {
      cout << "-1\n";
    } else {
      cout << v[a][b] << '\n';
    }
  }
}