#include "bits/stdc++.h"
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  unordered_map<string, int> cnt;
  while (N--) {
    string s;
    cin >> s;
    cout << cnt[s] << "\n";
    while (s.size()) {
      cnt[s]++;
      s.pop_back();
    }
  }
}
