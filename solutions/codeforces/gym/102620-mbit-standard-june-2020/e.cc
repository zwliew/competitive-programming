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

  int W, H, x0, y0;
  cin >> W >> H >> x0 >> y0;
  int N;
  cin >> N;
  int64_t dist = 0;
  while (N--) {
    int x, y;
    cin >> x >> y;
    int dy = abs(y - y0);
    int dx = abs(x - x0);
    dist += 1 + (dy && dx && dy != dx);
    y0 = y;
    x0 = x;
  }
  cout << dist;
}
