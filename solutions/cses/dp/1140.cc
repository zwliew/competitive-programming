/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  // Sort by ascending order of start times.
  int n;
  cin >> n;
  vector<tuple<int, int, int>> projects(n);
  for (auto& [s, e, p] : projects) {
    cin >> s >> e >> p;
  }
  sort(projects.begin(), projects.end());
  vector<long long> dp(n + 1);
  for (int i = n - 1; ~i; --i) {
    dp[i] = dp[i + 1];
    auto& [s, e, p] = projects[i];
    auto it = lower_bound(projects.begin() + i + 1, projects.end(),
                          make_tuple(e + 1, 0, 0));
    dp[i] = max(dp[i], dp[it - projects.begin()] + p);
  }
  cout << dp.front();

  // Alternative solution: dp[i] = max profit considering the first i projects
  // Sort projects in ascending order of end-times
  // If we take project i, we need to binary search for the last project that we
  // can take. We can take project j if project[i].start > project[j].end.
  //
  // int n;
  // cin >> n;
  // vector<tuple<int, int, int>> a(n);
  // for (auto& [e, s, p] : a) {
  //   cin >> s >> e >> p;
  // }
  // sort(a.begin(), a.end());
  // vector<int64_t> dp(n + 1);
  // for (int i = 1; i <= n; ++i) {
  //   dp[i] = dp[i - 1];
  //   auto it = lower_bound(a.begin(), a.begin() + i,
  //                         make_tuple(get<1>(a[i - 1]), 0, 0)) -
  //             a.begin();
  //   dp[i] = max(dp[i], dp[it] + get<2>(a[i - 1]));
  // }
  // cout << dp[n];
}
