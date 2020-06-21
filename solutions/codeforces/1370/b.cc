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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    vector<int> oddIdx, evenIdx;
    for (int i = 1; i <= n * 2; ++i) {
      cin >> a[i - 1];
      if (a[i - 1] % 2) {
        oddIdx.emplace_back(i);
      } else {
        evenIdx.emplace_back(i);
      }
    }

    if (oddIdx.size() % 2) {
      oddIdx.pop_back();
      evenIdx.pop_back();
    } else {
      if (oddIdx.size() >= 2) {
        oddIdx.pop_back();
        oddIdx.pop_back();
      } else {
        evenIdx.pop_back();
        evenIdx.pop_back();
      }
    }

    while (oddIdx.size()) {
      cout << oddIdx.back() << ' ';
      oddIdx.pop_back();
      assert(oddIdx.size());
      cout << oddIdx.back() << '\n';
      oddIdx.pop_back();
    }

    while (evenIdx.size()) {
      cout << evenIdx.back() << ' ';
      evenIdx.pop_back();
      assert(evenIdx.size());
      cout << evenIdx.back() << '\n';
      evenIdx.pop_back();
    }
  }
}
