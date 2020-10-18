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

  int n, m;
  double w;
  while (cin >> n >> m >> w && (n || m || w)) {
    w /= 2;

    vector<double> r(n), c(m);
    for (auto& x : r)
      cin >> x;
    for (auto& x : c)
      cin >> x;
    sort(r.begin(), r.end());
    sort(c.begin(), c.end());

    bool rowsCovered = true;
    double prev = 0;
    for (auto& x : r) {
      if (prev < x - w) {
        rowsCovered = false;
        break;
      }
      prev = x + w;
    }
    rowsCovered = rowsCovered && prev >= 75;

    bool colsCovered = true;
    prev = 0;
    for (auto& x : c) {
      if (prev < x - w) {
        colsCovered = false;
        break;
      }
      prev = x + w;
    }
    colsCovered = colsCovered && prev >= 100;
      
    if (rowsCovered && colsCovered) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << "\n";
  }
}
