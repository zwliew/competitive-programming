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

  int N, K;
  cin >> N >> K;
  vector<int> A(N), T(N);
  for (auto& x : A)
    cin >> x;
  for (auto& x : T)
    cin >> x;

  vector<int> pre(N);
  for (int i = 0; i < N; ++i) {
    pre[i] = (i ? pre[i - 1] : 0) + A[i] * !T[i];
  }

  vector<int> dp(2);
  for (int i = 0; i < N; ++i) {
    dp[0] += T[i] * A[i];
    dp[1] =
        max(dp[1] + T[i] * A[i], dp[0] + pre[i] - (i >= K ? pre[i - K] : 0));
  }
  cout << dp[1];
}
