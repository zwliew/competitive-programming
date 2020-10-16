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
#define FILE "taming"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  a[0] = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] != -1) {
      int cur = a[i] - 1;
      for (int j = i - 1; cur >= 0; --j, --cur) {
        if (a[j] != -1 && a[j] != cur) {
          cout << -1;
          return 0;
        }
        a[j] = cur;
      }
      i -= a[i];
    }
  }

  int mn = 0, mx = 0;
  for (int x : a) {
    if (!x) {
      ++mn;
      ++mx;
    } else if (x == -1) {
      ++mx;
    }
  }
  cout << mn << ' ' << mx;
}
