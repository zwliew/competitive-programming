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

  vector<int64_t> lucky;
  int64_t cur = 4;
  while (cur <= 1e10) {
    lucky.emplace_back(cur);
    vector<int> digits;
    int64_t next = cur;
    while (next) {
      digits.emplace_back(next % 10);
      next /= 10;
    }
    reverse(digits.begin(), digits.end());
    int idx = digits.size() - 1;
    while (idx >= 0 && digits[idx] == 7) {
      --idx;
    }
    if (idx < 0) {
      next = 4;
    } else {
      next = 0;
      digits[idx] = 7;
    }
    for (++idx; idx < digits.size(); ++idx) {
      digits[idx] = 4;
    }

    for (int i = 0; i < digits.size(); ++i) {
      next = next * 10 + digits[i];
    }
    cur = next;
  }

  for (int i = 0; i < 20; ++i) {
    debug(lucky[i]);
  }

  int64_t l, r;
  cin >> l >> r;
  int64_t sum = 0;
  while (l <= r) {
    int64_t next = *lower_bound(lucky.begin(), lucky.end(), l);
    sum += next * (min(next, r) - l + 1);
    l = next + 1;
  }
  cout << sum;
}
