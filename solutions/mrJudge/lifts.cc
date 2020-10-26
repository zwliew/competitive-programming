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

long long minTime(int n, int s, int h, int f[]) {
  int mx = *max_element(f, f + n);
  vector<int> cnt(mx + 1);
  for (int i = 0; i < n; ++i) {
    cnt[f[i]]++;
  }

  int64_t res = 0;
  int load = 0;
  for (int i = mx; i;) {
    if (!cnt[i]) {
      --i;
      continue;
    }
    int j = i;
    while (j && load < h) {
      int d = min(h - load, cnt[j]);
      load += d;
      cnt[j] -= d;
      if (!cnt[j]) {
        --j;
      }
    }
    res += i * 2;
    load = 0;
    i = j;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, s, h;
  cin >> n >> s >> h;
  int f[n];
  for (int i = 0; i < n; ++i)
    cin >> f[i];
  cout << minTime(n, s, h, f);
}
