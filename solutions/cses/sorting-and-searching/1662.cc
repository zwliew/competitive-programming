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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  map<int, int> cnt;
  cnt[0] = 1;
  int cur = 0;
  long long ans = 0;
  for (auto x : a) {
    cur = (cur + x % n + n) % n;
    ans += cnt[cur];
    cnt[cur]++;
  }
  cout << ans;
}
