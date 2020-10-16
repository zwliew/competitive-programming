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

  int s, n, m;
  cin >> s >> n >> m;
  vector<int> prices(s);
  for (auto& x : prices)
    cin >> x;

  vector<int> incEnd(s, 1), decEnd(s, 1), incStart(s, 1), decStart(s, 1);
  for (int i = 1; i < s; ++i) {
    if (prices[i] > prices[i - 1]) {
      incEnd[i] += incEnd[i - 1];
    } else if (prices[i] < prices[i - 1]) {
      decEnd[i] += decEnd[i - 1];
    }
  }
  for (int i = s - 2; i >= 0; --i) {
    if (prices[i] < prices[i + 1]) {
      incStart[i] += incStart[i + 1];
    } else if (prices[i] > prices[i + 1]) {
      decStart[i] += decStart[i + 1];
    }
  }

  int peaks = 0, valleys = 0;
  for (int i = 0; i < s; ++i) {
    if (incEnd[i] >= n && decStart[i] >= n) {
      ++peaks;
    }
    if (incStart[i] >= m && decEnd[i] >= m) {
      ++valleys;
    }
  }
  cout << peaks << " " << valleys;
}
