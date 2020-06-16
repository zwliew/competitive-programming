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

  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  unordered_map<long long, int> cnt;
  cnt[0] = 1;
  int ans = 0;
  long long cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    ans += cnt[cur - x];
    cnt[cur]++;
  }

  cout << ans;
}
