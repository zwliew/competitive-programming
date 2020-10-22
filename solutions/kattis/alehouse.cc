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

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> events(n * 2);
  for (int i = 0; i < n; ++i) {
    int s, e;
    cin >> s >> e;
    events[i * 2] = {s, 1};
    events[i * 2 + 1] = {e, -1};
  }
  sort(events.begin(), events.end());

  int ans = 0;
  int pref = 0;
  int count = 0;
  for (int l = 0, r = 0; l < n * 2; ++l) {
    if (l) {
      pref += events[l - 1].second;
      if (events[l - 1].second == 1) {
        --count;
      }
    }
    while (r < n * 2 && events[r].first <= events[l].first + k) {
      if (events[r].second == 1) {
        ++count;
      }
      ++r;
    }
    ans = max(ans, pref + count);
  }
  cout << ans;
}
