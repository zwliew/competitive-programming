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

  const int l = 147981;
  const int r = 691423;
  int cnt = 0;
  for (int i = l; i <= r; ++i) {
    bool adj = false;
    bool inc = true;
    int prev = INT_MAX;
    int cur = i;
    while (cur) {
      int nxt = cur % 10;
      cur /= 10;
      inc = inc && nxt <= prev;
      adj = adj || nxt == prev;
      prev = nxt;
    }

    if (adj && inc) {
      ++cnt;
    }
  }
  cout << cnt;
}
