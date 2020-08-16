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
#define FILE "circlecross"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  string s;
  cin >> s;
  vector<pair<int, int>> pos(26, {-1, -1});
  for (int i = 0; i < s.size(); ++i) {
    if (pos[s[i] - 'A'].first == -1) {
      pos[s[i] - 'A'].first = i;
    } else {
      pos[s[i] - 'A'].second = i;
    }
  }

  int cnt = 0;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (pos[i].first > pos[j].first && pos[i].first < pos[j].second &&
          pos[i].second > pos[j].second) {
        debug(i, j);
        ++cnt;
      }
    }
  }
  cout << cnt;
}
