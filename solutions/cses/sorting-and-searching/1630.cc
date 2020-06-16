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
  vector<pair<int, int>> tasks(n);
  for (auto &[a, d] : tasks) cin >> a >> d;
  sort(tasks.begin(), tasks.end());

  long long time = 0;
  long long ans = 0;
  for (auto &[a, d] : tasks) {
    time += a;
    ans += d - time;
  }
  cout << ans;
}
