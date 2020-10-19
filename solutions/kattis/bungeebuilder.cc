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
  vector<int> h(n);
  for (auto& x : h)
    cin >> x;

  vector<int> preMax(h), sufMax(h);
  partial_sum(h.begin(), h.end(), preMax.begin(),
              [](auto& x, auto& y) { return max(x, y); });
  partial_sum(h.rbegin(), h.rend(), sufMax.rbegin(),
              [](auto& x, auto& y) { return max(x, y); });

  int maxDistance = 0;
  for (int i = 0; i < n; ++i) {
    maxDistance = max(maxDistance, min(preMax[i], sufMax[i]) - h[i]);
  }
  cout << maxDistance;
}
