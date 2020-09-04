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
#define FILE "measurement"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  int sum = 0;
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    if (i) {
      sum -= a[i - 1];
    }

    while (j < n && sum + a[j] <= t) {
      sum += a[j];
      ++j;
    }

    ans = max(ans, j - i);
  }
  cout << ans;
}
