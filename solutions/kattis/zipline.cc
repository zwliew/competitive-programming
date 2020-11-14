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

  int N;
  cin >> N;
  cout << fixed << setprecision(6);
  while (N--) {
    int W, G, H, R;
    cin >> W >> G >> H >> R;
    if (H < G) {
      swap(H, G);
    }

    double l = hypot(W, H - G);
    cout << l << " ";

    auto f = [&](double x) {
      double l1 = hypot(x, G - R);
      double l2 = hypot(W - x, H - R);
      return l1 + l2;
    };

    l = 0;
    double r = W;
    for (int i = 0; i < 100; ++i) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      if (f(m1) < f(m2)) {
        r = m2;
      } else {
        l = m1;
      }
    }
    cout << f(l) << "\n";
  }
}
