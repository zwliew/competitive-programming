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
#define FILE "pairup"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<pair<int, int>> cows(n);
  for (int i = 0; i < n; ++i) {
    cin >> cows[i].second >> cows[i].first;
  }
  sort(cows.begin(), cows.end());

  int i, j;
  int ans = 0;
  for (i = 0, j = n - 1; i <= j;) {
    int d = min(cows[i].second, cows[j].second);
    if (i == j)
      d /= 2;
    ans = max(ans, cows[i].first + cows[j].first);
    cows[i].second -= d;
    cows[j].second -= d;
    if (!cows[i].second)
      ++i;
    if (!cows[j].second)
      --j;
  }

  cout << ans;
}
