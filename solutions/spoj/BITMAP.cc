/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

#define f first
#define s second
#define eb emplace_back

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vb> grid(n, vb(m));
    queue<pi> q;
    vector<vi> dist(n, vi(m, INT_MAX));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        if (c == '1') {
          grid[i][j] = 1;
          q.emplace(i, j);
          dist[i][j] = 0;
        }
      }
    }

    vpi edges = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (q.size()) {
      auto [r, c] = q.front();
      q.pop();

      int ndist = dist[r][c] + 1;
      for (auto &[dr, dc] : edges) {
        int nr = r + dr;
        int nc = c + dc;
        if (nr < 0 || nr >= n || nc < 0 || nc >= m || dist[nr][nc] < INT_MAX)
          continue;
        dist[nr][nc] = ndist;
        q.emplace(nr, nc);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << dist[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}

