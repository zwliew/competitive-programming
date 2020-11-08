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
  int minX = INT_MAX, maxX = INT_MIN;
  int minY = INT_MAX, maxY = INT_MIN;
  while (N--) {
    int x, y, r;
    cin >> x >> y >> r;
    minX = min(minX, x - r);
    maxX = max(maxX, x + r);
    minY = min(minY, y - r);
    maxY = max(maxY, y + r);
  }
  cout << (int64_t)(maxX - minX) * (maxY - minY);
}
