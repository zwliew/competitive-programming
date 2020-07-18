/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  vector<int64_t> a(n);
  unordered_set<int64_t> s;
  for (auto& x : a) {
    cin >> x;
    s.emplace(x);
  }
  sort(a.begin(), a.end());

  int sz = n;
  for (int i = 0; i < n; ++i) {
    if (!s.count(a[i]))
      continue;
    int64_t cur = a[i];
    int cnt = 0;
    while (s.count(cur)) {
      ++cnt;
      s.erase(cur);
      cur *= k;
    }
    sz -= cnt / 2;
  }
  cout << sz;
}

