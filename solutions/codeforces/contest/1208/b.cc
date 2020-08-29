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
#define FILE "balancing"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  auto check = [&](int m) {
    unordered_map<int, int> freq;
    int dups = 0;
    for (auto x : a) {
      ++freq[x];
      if (freq[x] == 2) {
        ++dups;
      }
    }

    for (int i = 0; i < m; ++i) {
      --freq[a[i]];
      if (freq[a[i]] == 1) {
        --dups;
      }
    }

    if (!dups) {
      return true;
    }

    for (int i = m; i < n; ++i) {
      --freq[a[i]];
      if (freq[a[i]] == 1) {
        --dups;
      }
      ++freq[a[i - m]];
      if (freq[a[i - m]] == 2) {
        ++dups;
      }

      if (!dups) {
        return true;
      }
    }

    return false;
  };

  int lo = -1;
  int hi = n;
  while (lo < hi - 1) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  cout << hi;
}
