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

  int n, m;
  cin >> n >> m;
  vector<int> entrances(n), exits(m);
  for (auto& x : entrances)
    cin >> x;
  for (auto& x : exits)
    cin >> x;

  map<int, int> diffCnt;
  for (int x : entrances) {
    for (int y : exits) {
      if (y < x)
        continue;
      diffCnt[y - x]++;
    }
  }

  int maxCnt = 0;
  int best = 0;
  for (auto& [k, v] : diffCnt) {
    if (v > maxCnt) {
      best = k;
      maxCnt = v;
    }
  }
  cout << best;
}
