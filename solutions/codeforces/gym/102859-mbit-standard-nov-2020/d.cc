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

  int N;
  cin >> N;
  int64_t ans = 0;
  vector<pair<int, int>> q;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    if (x) {
      q.emplace_back(x, i);
    }
  }

  for (int i = 0, j = 0; j < N && i < q.size(); ++j) {
    ans += abs(q[i].second - j);
    --q[i].first;
    if (!q[i].first) {
      ++i;
    }
  }
  cout << ans;
}
