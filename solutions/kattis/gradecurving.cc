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

  double x, lo, hi;
  cin >> x >> lo >> hi;

  double cur = x;
  int cnt = 0;
  while (ceil(cur) < lo) {
    cur = 10 * sqrt(cur);
    ++cnt;
  }

  if (x < lo && ceil(cur) > hi) {
    cout << "impossible";
    return 0;
  }

  cout << cnt << " ";

  if (hi == 100) {
    cout << "inf";
    return 0;
  }

  while (ceil(cur) < hi) {
    cur = 10 * sqrt(cur);
    ++cnt;
  }

  if (ceil(cur) > hi) {
    --cnt;
  }
  cout << cnt;
}
