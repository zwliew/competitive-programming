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

long long backtrack(vector<int> &p, int idx, long long a, long long b) {
  if (idx == p.size()) {
    return abs(a - b);
  }
  return min(backtrack(p, idx + 1, a + p[idx], b),
             backtrack(p, idx + 1, a, b + p[idx]));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &x : p) cin >> x;

  cout << backtrack(p, 0, 0, 0);
}
