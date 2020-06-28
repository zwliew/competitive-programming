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

  int n;
  cin >> n;
  vector<int> first, second;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    first.emplace_back(c - '0');
  }
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    second.emplace_back(c - '0');
  }
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());

  bool less = true, more = true;
  for (int i = 0; i < n; ++i) {
    if (first[i] <= second[i]) {
      more = false;
    }
    if (first[i] >= second[i]) {
      less = false;
    }
  }

  if (more || less) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
