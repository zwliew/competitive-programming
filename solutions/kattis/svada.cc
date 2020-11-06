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

  int T;
  cin >> T;
  int N;
  cin >> N;
  vector<pair<int, int>> first(N);
  for (auto& [a, b] : first)
    cin >> a >> b;
  int M;
  cin >> M;
  vector<pair<int, int>> second(M);
  for (auto& [c, d] : second)
    cin >> c >> d;

  int l = 0, r = T;
  while (l < r - 1) {
    int m = l + (r - l) / 2;
    int found = 0;
    for (auto& [a, b] : first) {
      if (m >= a) {
        found += (m - a) / b + 1;
      }
    }
    int opened = 0;
    for (auto& [c, d] : second) {
      if (T - m >= c) {
        opened += (T - m - c) / d + 1;
      }
    }
    if (opened >= found) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l;
}
