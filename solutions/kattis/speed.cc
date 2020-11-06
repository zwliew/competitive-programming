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

  int N, T;
  cin >> N >> T;
  vector<pair<int, int>> segs(N);

  double l = -1e9;
  for (auto& [d, s] : segs) {
    cin >> d >> s;
    l = max<double>(l, -s);
  }

  double r = 1e9;
  for (int i = 0; i < 100; ++i) {
    double m = (l + r) / 2;
    double t = 0;
    for (auto& [d, s] : segs) {
      t += (double)d / (s + m);
    }
    if (t <= T) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << fixed << setprecision(6) << r;
}
