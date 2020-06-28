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

  vector<string> cards(12);
  for (auto &x : cards)
    cin >> x;

  auto ok = [&](string &a, string &b, string &c) {
    for (int i = 0; i < 4; ++i) {
      if ((a[i] != b[i] || b[i] != c[i] || a[i] != c[i]) &&
          (a[i] == b[i] || c[i] == b[i] || a[i] == c[i])) {
        return false;
      }
    }
    return true;
  };

  vector<tuple<int, int, int>> found;
  for (int i = 0; i < 12; ++i) {
    for (int j = i + 1; j < 12; ++j) {
      for (int k = j + 1; k < 12; ++k) {
        if (ok(cards[i], cards[j], cards[k])) {
          found.emplace_back(i + 1, j + 1, k + 1);
        }
      }
    }
  }

  if (found.empty()) {
    cout << "no sets";
  } else {
    for (auto &[a, b, c] : found) {
      cout << a << ' ' << b << ' ' << c << '\n';
    }
  }
}
