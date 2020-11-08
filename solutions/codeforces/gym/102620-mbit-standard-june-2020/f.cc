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

  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> T(N);
  for (int i = 0; i < N; ++i) {
    int t;
    cin >> t;
    T[i] = {t, i};
  }
  sort(T.begin(), T.end());

  int64_t dist = abs(K - 1 - T[0].second);
  for (int i = 1; i < N; ++i) {
    dist += abs(T[i].second - T[i - 1].second);
  }
  cout << dist;
}
