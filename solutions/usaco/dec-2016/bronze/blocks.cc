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
#define FILE "blocks"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  array<int, 26> total;
  fill(total.begin(), total.end(), 0);
  for (int i = 0; i < n; ++i) {
    array<int, 26> first, second;
    fill(first.begin(), first.end(), 0);
    fill(second.begin(), second.end(), 0);
    string s;
    cin >> s;
    for (char c : s) {
      first[c - 'a']++;
    }
    cin >> s;
    for (char c : s) {
      second[c - 'a']++;
    }

    for (int j = 0; j < 26; ++j) {
      total[j] += max(first[j], second[j]);
    }
  }

  for (int i = 0; i < 26; ++i) {
    cout << total[i] << '\n';
  }
}
