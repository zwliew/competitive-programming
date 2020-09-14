#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
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

  // Use prefix and suffix max/mins for every index i
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  vector<bool> ok(n);
  int cmax = 0;
  for (int i = 0; i < n; ++i) {
    ok[i] = a[i] > cmax;
    cmax = max(a[i], cmax);
  }

  int cmin = INT_MAX;
  for (int i = n - 1; i >= 0; --i) {
    ok[i] = ok[i] && a[i] < cmin;
    cmin = min(a[i], cmin);
  }

  cout << accumulate(ok.begin(), ok.end(), 0);
}
