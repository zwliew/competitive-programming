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

  int n;
  cin >> n;
  int l = 0;
  array<vector<int>, 2> weights;
  for (int i = 0; i < 2; ++i) {
    unordered_map<int, int> cnt;
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      weights[i].push_back(x);
      cnt[x]++;
    }
    for (auto& [k, v] : cnt) {
      if (v == 1) {
        l = max(l, k);
      }
    }
  }

  --l;
  int r = 1e9;
  while (l < r - 1) {
    int m = l + (r - l) / 2;
    int greater = 0;
    bool ok = true;
    for (int i = 0; i < 2; ++i) {
      greater = 0;
      for (int j = 0; j < n; ++j) {
        if (weights[i][j] > m) {
          if (greater && greater != weights[i][j]) {
            ok = false;
            break;
          } else if (greater == weights[i][j]) {
            greater = 0;
          } else {
            greater = weights[i][j];
          }
        }
      }
      if (!ok) {
        break;
      }
    }
    if (ok) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << "\n";
}
