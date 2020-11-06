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

  int B;
  cin >> B;
  vector<pair<double, double>> bands(B);
  for (auto& [s, p] : bands)
    cin >> s >> p;
  for (int i = 1; i < B; ++i) {
    bands[i].first += bands[i - 1].first;
  }
  double P;
  cin >> P;
  int F;
  cin >> F;
  cout << fixed << setprecision(6);
  while (F--) {
    double E, M;
    cin >> E >> M;

    double l = 0, r = 1e14;
    for (int i = 0; i < 100; ++i) {
      double m = (l + r) / 2;
      double total = 0;
      double left = m;
      double e = E;
      for (int j = 0; j < B && left; ++j) {
        if (e >= bands[j].first)
          continue;
        double d = min(left, bands[j].first - e);
        total += d * (100 - bands[j].second) / 100;
        left -= d;
        e += d;
      }
      if (total + left * (100 - P) / 100 >= M) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << r << "\n";
  }
}
