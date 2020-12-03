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

  const int dy = 3;
  const int dx = 1;
  int cnt = 0;
  for (int i = 0, j = 0; i < grid.size();
       i += dx, j = (j + dy) % grid[0].size()) {
    if (grid[i][j] == '#')
      ++cnt;
  }
  cout << cnt;
}
