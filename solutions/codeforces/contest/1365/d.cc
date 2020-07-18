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
    vector<vc> grid(n, vc(m));
    vpi goods, bads;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        grid[i][j] = c;
        if (c == 'G') {
          goods.eb(i, j);
        } else if (c == 'B') {
          bads.eb(i, j);
        }
      }
    }

    vpi edges = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };
    bool ok = true;
    for (auto &[br, bc] : bads) {
      for (auto &[gr, gc] : goods) {
        for (auto &[dr, dc] : edges) {
          int nr = br + dr;
          int nc = bc + dc;
          if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
          if (gr == nr && gc == nc) {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }
      if (!ok) break;
    }

    for (auto &[br, bc] : bads) {
      for (auto &[dr, dc] : edges) {
        int nr = br + dr;
        int nc = bc + dc;
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.') {
          grid[nr][nc] = '#';
        }
      }
    }

    if (!ok) {
      cout << "No\n";
      continue;
    }

    vector<vb> vis(n, vb(m));
    if (grid[n - 1][m - 1] != '#') {
      queue<pi> q;
      q.emplace(n - 1, m - 1);
      while (q.size()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto &[dr, dc] : edges) {
          int nr = r + dr;
          int nc = c + dc;
          if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
          if (vis[nr][nc]) continue;
          if (grid[nr][nc] == '#') continue;
          q.emplace(nr, nc);
          vis[nr][nc] = true;
        }
      }
    }

    for (auto &[gr, gc] : goods) {
      if (!vis[gr][gc]) {
        ok = false;
        break;
      }
    }

    for (auto &[br, bc] : bads) {
      if (vis[br][bc]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
