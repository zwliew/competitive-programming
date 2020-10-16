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
  vector<int> vals(n);
  for (auto& x : vals)
    cin >> x;

  int l = -1, r = n;
  for (int i = 0; i < n - 1; ++i) {
    if (vals[i] > vals[i + 1]) {
      l = i;
      break;
    }
  }
  while (l > 0 && vals[l - 1] == vals[l])
    --l;

  for (int i = n - 1; i; --i) {
    if (vals[i - 1] > vals[i]) {
      r = i;
      break;
    }
  }
  while (r < n - 1 && vals[r] == vals[r + 1])
    ++r;

  if (l == -1) {
    cout << "1 1";
    return 0;
  }

  reverse(vals.begin() + l, vals.begin() + r + 1);
  for (int i = 0; i < n - 1; ++i) {
    if (vals[i] > vals[i + 1]) {
      cout << "impossible";
      return 0;
    }
  }

  cout << l + 1 << " " << r + 1;
}
