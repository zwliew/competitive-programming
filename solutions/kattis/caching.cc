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
#include <iterator>
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

  int c, n, a;
  cin >> c >> n >> a;
  vector<vector<int>> accessTimes(n);
  vector<int> accesses(a);
  for (int i = 0; i < a; ++i) {
    cin >> accesses[i];
    accessTimes[accesses[i]].push_back(i);
  }
  for (auto& v : accessTimes) {
    reverse(v.begin(), v.end());
  }

  unordered_set<int> cache;
  set<pair<int, int>, greater<pair<int, int>>> s;
  int faultCnt = 0;
  for (int i = 0; i < a; ++i) {
    int x = accesses[i];
    if (cache.count(x)) {
      auto it = s.find({i, x});
      s.erase(it);
    } else {
      if (cache.size() == c) {
        auto [t, u] = *s.begin();
        s.erase(s.begin());
        cache.erase(u);
      }
      ++faultCnt;
      cache.insert(x);
    }
    int nt = a;
    if (accessTimes[x].size() > 1) {
      accessTimes[x].pop_back();
      nt = accessTimes[x].back();
    }
    s.emplace(nt, x);
  }
  cout << faultCnt;
}
