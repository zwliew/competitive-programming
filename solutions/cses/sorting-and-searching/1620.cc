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

  long long n, t;
  cin >> n >> t;
  vector<long long> k(n);
  for (auto &x : k) cin >> x;

  long long lo = 0;
  long long hi = 1e18;
  while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    long long cnt = 0;
    for (long long x : k) {
      if (cnt >= t) break;
      cnt += mid / x;
    }
    if (cnt >= t) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << hi;
}
