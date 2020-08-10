/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "citystate"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  map<pair<string, string>, int64_t> freq;
  int64_t cnt = 0;
  while (n--) {
    string city, state;
    cin >> city >> state;
    auto pref = city.substr(0, 2);
    if (pref != state) {
      cnt += freq[{state, pref}];
    }
    freq[{pref, state}]++;
  }
  cout << cnt;
}
