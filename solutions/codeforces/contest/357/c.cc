/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int fs(vector<int> &p, int u) { return p[u] == u ? u : p[u] = fs(p, p[u]); }
void us(vector<int> &p, int u, int v) {
  u = fs(p, u);
  v = fs(p, v);
  if (u == v) return;
  p[v] = u;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, m;
  cin >> n >> m;
  set<int> left;
  for (int i = 1; i <= n; ++i) {
    left.emplace(i);
  }
  vector<int> ans(n + 1);
  vector<int> p(n + 2);
  iota(p.begin(), p.end(), 0);
  while (m--) {
    int l, r, x;
    cin >> l >> r >> x;
    // Find knights remaining in O(K) time using an idea similar to Union-find &
    // Arpa's trick
    int cur = fs(p, l);
    while (cur <= r) {
      if (cur != x) {
        ans[cur] = x;
        us(p, cur + 1, cur);
      }
      cur = fs(p, cur + 1);
    }

    // Find knights remaining in O(KlogN) time using a BST
    // auto lb = left.lower_bound(l);
    // vector<set<int>::iterator> erasing;
    // for (auto it = lb; it != left.end() && *it <= r; ++it) {
    //   if (*it != x) {
    //     erasing.emplace_back(it);
    //     ans[*it] = x;
    //   }
    // }
    // for (auto &it : erasing) {
    //   left.erase(it);
    // }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
}
