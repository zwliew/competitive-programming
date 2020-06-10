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

int backtrack(unordered_set<int> &reserved, vector<int> &damaged, int idx) {
  if (idx >= (int)damaged.size()) {
    return 0;
  }
  int ans = backtrack(reserved, damaged, idx + 1) + 1;
  if (reserved.count(damaged[idx])) {
    reserved.erase(damaged[idx]);
    ans = min(ans, backtrack(reserved, damaged, idx + 1));
    reserved.emplace(damaged[idx]);
  } else {
    if (reserved.count(damaged[idx] + 1)) {
      reserved.erase(damaged[idx] + 1);
      ans = min(ans, backtrack(reserved, damaged, idx + 1));
      reserved.emplace(damaged[idx] + 1);
    }
    if (reserved.count(damaged[idx] - 1)) {
      reserved.erase(damaged[idx] - 1);
      ans = min(ans, backtrack(reserved, damaged, idx + 1));
      reserved.emplace(damaged[idx] - 1);
    }
  }
  return ans;
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

  int n, s, r;
  cin >> n >> s >> r;
  unordered_set<int> reserved;
  vector<int> damaged;
  while (s--) {
    int x;
    cin >> x;
    damaged.emplace_back(x);
  }
  while (r--) {
    int x;
    cin >> x;
    reserved.emplace(x);
  }
  cout << backtrack(reserved, damaged, 0);
}
