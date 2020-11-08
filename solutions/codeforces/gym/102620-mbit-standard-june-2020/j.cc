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

  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (auto& x : A)
    cin >> x;

  vector<int64_t> preSum(N + 1);
  for (int i = 0; i < N; ++i) {
    preSum[i + 1] = preSum[i] + A[i];
  }

  while (Q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v)
      swap(u, v);
    auto d = preSum[v] - preSum[u];
    cout << min(d, preSum[N] - d) << "\n";
  }
}
