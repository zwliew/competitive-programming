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
#define FILE "measurement"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  array<int, 3> cur{7, 7, 7};
  vector<tuple<int, int, int>> entries(n);
  unordered_map<string, int> m = {
      {"Mildred", 0},
      {"Elsie", 1},
      {"Bessie", 2},
  };
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(entries[i]);
    string s;
    cin >> s;
    get<1>(entries[i]) = m[s];
    cin >> s;
    int val = stoi(s.substr(1));
    if (s.substr(0, 1) == "+") {
      get<2>(entries[i]) = val;
    } else {
      get<2>(entries[i]) = -val;
    }
  }
  sort(entries.begin(), entries.end());

  vector<int> prev{0, 1, 2};
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cur[get<1>(entries[i])] += get<2>(entries[i]);
    vector<int> nxt;
    int mx = 0;
    for (int j = 0; j < 3; ++j) {
      mx = max(mx, cur[j]);
    }
    for (int j = 0; j < 3; ++j) {
      if (cur[j] == mx) {
        nxt.emplace_back(j);
      }
    }
    if (nxt != prev) {
      ++cnt;
      prev = nxt;
    }
  }

  cout << cnt;
}
