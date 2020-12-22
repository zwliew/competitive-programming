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
#define FILE "censor"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  string s, t;
  cin >> s >> t;

  const int P = 131;
  const int M = 1e9 + 7;

  int pt = 1;
  for (int i = 0; i < t.size(); ++i) {
    pt = ((int64_t)pt * P) % M;
  }
  int th = 0;
  for (int i = 0; i < t.size(); ++i) {
    th = ((int64_t)th * P + t[i] - 'a' + 1) % M;
  }

  vector<int> h = {0};
  string res;
  for (char c : s) {
    res += c;
    int ch = h.back();
    ch = ((int64_t)ch * P + c - 'a' + 1) % M;
    h.push_back(ch);
    if (h.size() > t.size() &&
        (h.back() - ((int64_t)h[h.size() - t.size() - 1] * pt % M) + M) % M ==
            th) {
      h.resize(h.size() - t.size());
      res.resize(res.size() - t.size());
    }
  }
  cout << res;
}
