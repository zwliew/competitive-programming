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
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  vector<string> grid;
  string s;
  while (getline(cin, s)) {
    grid.push_back(s);
  }

  const vector<int> dy = {1, 1, 1, 1, 2};
  const vector<int> dx = {1, 3, 5, 7, 1};
  int64_t ans = 1;
  for (int i = 0; i < 5; ++i) {
    int cdy = dy[i];
    int cdx = dx[i];
    int cnt = 0;
    for (int r = 0, c = 0; r < grid.size();
         r += cdy, c = (c + cdx) % grid[0].size()) {
      if (grid[r][c] == '#')
        ++cnt;
    }
    ans *= cnt;
  }
  cout << ans;
}
