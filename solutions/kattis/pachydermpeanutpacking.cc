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
#define FILE "feast"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  while (cin >> n && n) {
    vector<tuple<double, double, double, double, string>> boxes(n);
    for (auto& [x1, y1, x2, y2, sz] : boxes) {
      cin >> x1 >> y1 >> x2 >> y2 >> sz;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      double x, y;
      string sz;
      cin >> x >> y >> sz;
      string fsz = "floor";
      for (auto& [x1, y1, x2, y2, bsz] : boxes) {
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
          fsz = bsz;
          break;
        }
      }
      cout << sz << ' ';
      if (fsz == sz) {
        cout << "correct";
      } else {
        cout << fsz;
      }
      cout << '\n';
    }
    cout << '\n';
  }
}
