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

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    cout << "Case #" << ti << ": ";

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
      cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());

    int cnt = 0;
    int end = 0;
    for (int i = 0; i < n; ++i) {
      int s = intervals[i].first;
      int e = intervals[i].second;
      if (end >= e) {
        continue;
      }
      int curCnt = (e - max(end, s) + k - 1) / k;
      cnt += curCnt;
      end = max(end, s) + curCnt * k;
    }
    cout << cnt << "\n";
  }
}
