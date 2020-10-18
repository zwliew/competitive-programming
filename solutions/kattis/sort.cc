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

  unordered_map<int, int> freq, initialIdx;
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    freq[x]++;
    if (!initialIdx.count(x)) {
      initialIdx[x] = i;
    }
  }

  vector<tuple<int, int, int>> vals;
  for (auto& [k, v] : freq) {
    vals.emplace_back(-v, initialIdx[k], k);
  }
  sort(vals.begin(), vals.end());

  for (auto& [v, i, k] : vals) {
    for (int i = 0; i < -v; ++i) {
      cout << k << " ";
    }
  }
}
