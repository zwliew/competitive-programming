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

  int n, k;
  cin >> n >> k;
  vector<int> cnt(26);
  while (n--) {
    char c;
    cin >> c;
    cnt[c - 'A']++;
  }
  sort(cnt.begin(), cnt.end());

  int64_t sum = 0;
  while (k) {
    int num = min(k, cnt.back());
    sum += (int64_t)num * num;
    k -= num;
    cnt.pop_back();
  }

  cout << sum;
}
