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

  map<pair<int, int>, int> dist;
  auto parse = []() {
    string s;
    cin >> s;
    vector<pair<char, int>> moves;
    istringstream ss(s);
    while (getline(ss, s, ',')) {
      char dir = s[0];
      int cnt = stoi(s.substr(1));
      moves.emplace_back(dir, cnt);
    }
    return moves;
  };
  auto first = parse();
  auto second = parse();

  int x = 0;
  int y = 0;
  int steps = 0;
  for (auto& [dir, cnt] : first) {
    for (int d = 1; d <= cnt; ++d) {
      ++steps;
      if (dir == 'R') {
        ++x;
      } else if (dir == 'L') {
        --x;
      } else if (dir == 'U') {
        --y;
      } else {
        ++y;
      }
      dist[{x, y}] = steps;
    }
  }

  x = 0;
  y = 0;
  steps = 0;
  int best = INT_MAX;
  for (auto& [dir, cnt] : second) {
    for (int d = 1; d <= cnt; ++d) {
      ++steps;
      if (dir == 'R') {
        ++x;
      } else if (dir == 'L') {
        --x;
      } else if (dir == 'U') {
        --y;
      } else {
        ++y;
      }
      if (dist.count({x, y})) {
        best = min(best, dist[{x, y}] + steps);
      }
    }
  }

  cout << best;
}
