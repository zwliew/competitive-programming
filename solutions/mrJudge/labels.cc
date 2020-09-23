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
//#include "bits/stdc++.h"

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
  vector<int> d(n - 1);
  pair<int, int> bounds = {1, n};
  for (int i = 0; i < n - 1; ++i) {
    cin >> d[i];
    if (i)
      d[i] += d[i - 1];
    // 1 <= d[i] + a[0] <= n
    // 1 - d[i] <= a[0] <= n - d[i]
    bounds.first = max(bounds.first, 1 - d[i]);
    bounds.second = min(bounds.second, n - d[i]);
  }

  if (bounds.first != bounds.second) {
    cout << -1;
    return 0;
  }

  cout << bounds.first;
  for (int i = 0; i < n - 1; ++i) {
    cout << " " << d[i] + bounds.first;
  }
}
