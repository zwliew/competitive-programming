#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int64_t pwr(int64_t a, int64_t b, int64_t m) {
  int64_t r = 1;
  while (b) {
    if (b & 1) {
      r *= a;
      r %= m;
    }
    a *= a;
    a %= m;
    b >>= 1;
  }
  return r;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (auto& x : a)
    cin >> x;
  sort(a.begin(), a.end());

  const int64_t m = 998244353;
  int64_t total = 0;
  for (int i = 0; i < n; ++i) {
    total += a[i + n] - a[i];
    total %= m;
  }

  for (int i = n + 1; i <= 2 * n; ++i) {
    total *= i;
    total %= m;
  }

  int64_t fact = 1;
  for (int i = 2; i <= n; ++i) {
    fact *= i;
    fact %= m;
  }
  fact = pwr(fact, m - 2, m);

  total *= fact;
  total %= m;
  cout << total;
}
