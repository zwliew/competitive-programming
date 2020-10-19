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

  int c;
  cin >> c;
  while (c--) {
    int n, t, m;
    cin >> n >> t >> m;
    vector<pair<int, bool>> cars(m);
    for (auto& [x, y] : cars) {
      string s;
      cin >> x >> s;
      y = s == "left";
    }

    vector<int> arrival(m);
    array<queue<int>, 2> q;
    bool left = true;
    int time = 0;
    int idx = 0;
    while (idx < m || q[0].size() || q[1].size()) {
      while (idx < m && cars[idx].first <= time) {
        q[cars[idx].second].push(idx);
        ++idx;
      }

      if (q[0].empty() && q[1].empty()) {
        time = cars[idx].first;
        continue;
      }

      int cnt = 0;
      while (q[left].size() && cnt < n) {
        arrival[q[left].front()] = time + t;
        q[left].pop();
        ++cnt;
      }

      time += t;
      left = !left;
    }

    for (auto x : arrival) {
      cout << x << "\n";
    }
    cout << "\n";
  }
}
