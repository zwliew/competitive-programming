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

  int N, T;
  cin >> N >> T;
  vector<int> a(N);
  for (auto& x : a)
    cin >> x;

  map<int, int> s;
  s[0] = 1;
  for (int i = 1; i < (1 << (N / 2)); ++i) {
    int curSum = 0;
    for (int j = i; j && curSum <= T; j -= j & -j) {
      int nxt = __builtin_ctz(j);
      curSum += a[nxt];
    }
    if (curSum <= T)
      s[curSum]++;
  }

  int64_t ans = s[T];
  for (int i = 1; i < (1 << ((N + 1) / 2)); ++i) {
    int curSum = 0;
    for (int j = i; j && curSum <= T; j -= j & -j) {
      int nxt = __builtin_ctz(j) + N / 2;
      curSum += a[nxt];
    }
    if (curSum <= T)
      ans += s[T - curSum];
  }
  cout << ans;
}
