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

  int N;
  cin >> N;
  vector<int> a(N);
  for (auto& x : a)
    cin >> x;

  vector<int> dp(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (!(a[i] & a[j])) {
        dp[i] = max(dp[i], dp[j]);
      }
    }
    dp[i]++;
  }
  cout << *max_element(dp.begin(), dp.end());
}
