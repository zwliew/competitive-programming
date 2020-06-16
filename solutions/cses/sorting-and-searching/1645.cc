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
  stack<pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    while (s.size() && s.top().first >= x) {
      s.pop();
    }
    cout << (s.empty() ? 0 : s.top().second + 1) << ' ';
    s.emplace(x, i);
  }
}
