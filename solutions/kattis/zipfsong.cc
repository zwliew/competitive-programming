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

  int n, m;
  cin >> n >> m;
  vector<tuple<int64_t, int, string>> songs(n);
  int idx = INT_MAX;
  for (auto& [q, i, s] : songs) {
    cin >> q >> s;
    i = idx--;
  }
  for (int i = 0; i < n; ++i) {
    get<0>(songs[i]) *= i + 1;
  }
  sort(songs.rbegin(), songs.rend());

  for (int i = 0; i < m; ++i) {
    cout << get<2>(songs[i]) << "\n";
  }
}
