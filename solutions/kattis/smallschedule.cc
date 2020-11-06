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

  int64_t Q, M, S, L;
  cin >> Q >> M >> S >> L;

  int64_t l = -1, r = 1e10;
  while (l < r - 1) {
    int64_t m = l + (r - l) / 2;
    int64_t availQ = m / Q * M;
    int64_t availS = m * M - Q * L;
    if (availS >= S && availQ >= L) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r;
}
