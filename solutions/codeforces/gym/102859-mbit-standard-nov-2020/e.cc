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

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N, K;
  cin >> N >> K;
  vector<int> T(N);
  for (auto& x : T)
    cin >> x;
  sort(T.begin(), T.end());

  int64_t ans = 0;
  int64_t cur = 0;
  int prev = INT_MAX;
  for (int x : T) {
    if (x - prev > K) {
      ans = max(ans, cur);
      cur = 0;
    }
    cur += x;
    prev = x;
  }
  cout << max(ans, cur);
}
