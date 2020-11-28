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

  int m, n, t;
  cin >> m >> n >> t;

  int lim;
  double cur;
  switch (t) {
    case 1:
      for (cur = 1, lim = 0; cur <= m; ++lim, cur *= lim)
        ;
      --lim;
      break;
    case 2:
      lim = log2(m);
      break;
    case 3:
      lim = pow(m, 0.25);
      break;
    case 4:
      lim = cbrt(m);
      break;
    case 5:
      lim = sqrt(m);
      break;
    case 6:
      for (cur = 1, lim = 0; cur <= m; ++lim, cur = lim * log2(lim))
        ;
      --lim;
      break;
    case 7:
      lim = m;
      break;
  }
  cout << (lim >= n ? "AC" : "TLE");
}
