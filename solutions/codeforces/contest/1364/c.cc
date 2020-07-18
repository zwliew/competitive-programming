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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  vector<int> unused(1000001);
  for (int i = 0; i < n; ++i) {
    unused[a[i]]++;
  }

  queue<int> toUse;
  vector<int> ans;
  int cur = 0;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (toUse.size()) {
      ans.emplace_back(toUse.front());
      toUse.pop();
    } else {
      while (unused[cur]) {
        ++cur;
      }
      ans.emplace_back(cur);
      ++cur;
    }
    unused[a[i]]--;
    if (!unused[a[i]]) {
      if (a[i] == cur) ++cur;
      toUse.emplace(a[i]);
    }
  }

  for (int x : ans) {
    cout << x << ' ';
  }
}

