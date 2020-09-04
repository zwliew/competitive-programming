#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
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
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "pairup"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<int> cities(n), towers(m);
  for (auto& x : cities)
    cin >> x;
  for (auto& x : towers)
    cin >> x;

  int ans = 0;
  int j = -1;
  for (int i = 0; i < n; ++i) {
    while (j + 1 < m && towers[j + 1] <= cities[i]) {
      ++j;
    }

    ans = max(ans, min(j >= 0 ? cities[i] - towers[j] : INT_MAX,
                       j + 1 < m ? towers[j + 1] - cities[i] : INT_MAX));
  }

  cout << ans;
}
