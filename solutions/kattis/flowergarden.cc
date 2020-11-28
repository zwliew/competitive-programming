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

  const int MAXN = 2e4;
  vector<bool> p(MAXN + 1, 1);
  p[0] = p[1] = 0;
  for (int i = 2; i * i <= MAXN; ++i) {
    if (p[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        p[j] = 0;
      }
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int N, D;
    cin >> N >> D;
    vector<int> px(N), py(N);
    for (int i = 0; i < N; ++i) {
      cin >> px[i] >> py[i];
    }

    int cx = 0, cy = 0;
    double dist = 0;
    int best = 0;
    for (int i = 0; i < N && dist <= D; ++i) {
      double cd = hypot(px[i] - cx, py[i] - cy);
      dist += cd;
      if (dist <= D && p[i + 1]) {
        best = i + 1;
      }
      cx = px[i];
      cy = py[i];
    }
    cout << best << "\n";
  }
}
