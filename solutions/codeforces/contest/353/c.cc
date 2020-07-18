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

vector<int> arr;
vector<long long> prefixSum;
vector<int> setBits;
long long solve(int idx) {
  if (idx < 0) {
    return 0;
  }
  return max(setBits[idx] > 0 ? prefixSum[setBits[idx] - 1] : 0,
             arr[setBits[idx]] + solve(idx - 1));
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

  int n;
  cin >> n;
  arr = vector<int>(n);
  for (auto &x : arr) cin >> x;
  string m;
  cin >> m;

  prefixSum = {arr.front()};
  for (int i = 1; i < n; ++i) {
    prefixSum.emplace_back(prefixSum.back() + arr[i]);
  }

  for (int i = 0; i < (int)m.size(); ++i) {
    if (m[i] == '1') {
      setBits.emplace_back(i);
    }
  }

  if (setBits.empty()) {
    cout << 0;
    return 0;
  }

  cout << solve((int)setBits.size() - 1);
}
