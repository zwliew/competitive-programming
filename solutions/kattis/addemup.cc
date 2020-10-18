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

  vector<int> mp = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

  int n, target;
  cin >> n >> target;
  unordered_set<int> seen;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int flipped = 0;
    int tmp = x;
    bool ok = true;
    while (tmp) {
      int cur = tmp % 10;
      if (mp[cur] == -1) {
        ok = false;
        break;
      }
      flipped = flipped * 10 + mp[cur];
      tmp /= 10;
    }
    if (seen.count(target - x) || (ok && seen.count(target - flipped))) {
      cout << "YES";
      return 0;
    }
    seen.insert(x);
    if (ok)
      seen.insert(flipped);
  }
  cout << "NO";
}
