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
#define FILE "hoofball"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;

  if (n == 1) {
    cout << 1;
    return 0;
  }

  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> pos[i];
  }
  sort(pos.begin(), pos.end());

  vector<int> to(n);
  to[0] = 1;
  to[n - 1] = n - 2;
  for (int i = 1; i < n - 1; ++i) {
    if (pos[i + 1] - pos[i] < pos[i] - pos[i - 1]) {
      to[i] = i + 1;
    } else {
      to[i] = i - 1;
    }
  }

  vector<int> indeg(n);
  for (int i = 0; i < n; ++i) {
    indeg[to[i]]++;
  }

  int cyclic = 0;
  for (int i = 0; i < n; ++i) {
    if (i == to[to[i]] && indeg[i] == 1 && indeg[to[i]] == 1) {
      ++cyclic;
    }
  }

  int ans = cyclic / 2;
  for (int i = 0; i < n; ++i) {
    if (!indeg[i]) {
      ++ans;
    }
  }
  cout << ans;
}
