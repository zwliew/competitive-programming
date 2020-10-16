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

  int h, w;
  while (cin >> h >> w) {
    int area = 0;
    for (int i = 0; i < h; ++i) {
      bool inside = false;
      for (int j = 0; j < w; ++j) {
        char c;
        cin >> c;
        if (c == '/' || c == '\\') {
          inside = !inside;
          ++area;
        } else if (inside) {
          area += 2;
        }
      }
    }
    cout << area / 2 << "\n";
  }
}
