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
#define FILE "moop"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());

  vector<int> minl(n), maxr(n);
  minl[0] = a[0].second;
  for (int i = 1; i < n; ++i) {
    minl[i] = min(minl[i - 1], a[i].second);
  }
  maxr[n - 1] = a[n - 1].second;
  for (int i = n - 2; i >= 0; --i) {
    maxr[i] = max(maxr[i + 1], a[i].second);
  }

  int ans = 1;
  for (int i = 0; i < n - 1; ++i) {
    if (minl[i] > maxr[i + 1]) {
      ++ans;
    }
  }
  cout << ans;
}
