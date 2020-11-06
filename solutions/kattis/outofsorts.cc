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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  int64_t m, a, c;
  cin >> n >> m >> a >> c;
  vector<int64_t> x(n + 1);
  cin >> x[0];
  for (int i = 1; i <= n; ++i) {
    x[i] = (a * x[i - 1] + c) % m;
  }

  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int l = 1;
    int r = n;
    while (l <= r) {
      int m = (l + r) / 2;
      if (x[i] == x[m]) {
        ++cnt;
        break;
      }
      if (x[m] < x[i]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
  }
  cout << cnt;
}
