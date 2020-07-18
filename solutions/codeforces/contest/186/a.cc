/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

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

  string a, b;
  cin >> a >> b;

  if (a.size() != b.size()) {
    cout << "NO";
    return 0;
  }

  int cnt = 0;
  char diffa, diffb;
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] != b[i]) {
      if (!cnt) {
        diffa = min(a[i], b[i]);
        diffb = max(a[i], b[i]);
        ++cnt;
      } else if (cnt == 1) {
        int curdiffa = min(a[i], b[i]);
        int curdiffb = max(a[i], b[i]);
        if (curdiffa != diffa || curdiffb != diffb) {
          cout << "NO";
          return 0;
        }
        ++cnt;
      } else {
        cout << "NO";
        return 0;
      }
    }
  }

  cout << (cnt == 2 ? "YES" : "NO");
}
