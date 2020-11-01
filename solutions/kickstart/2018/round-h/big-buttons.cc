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

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    cout << "Case #" << ti << ": ";

    int n, p;
    cin >> n >> p;
    vector<string> prefixes(p);
    for (auto& x : prefixes)
      cin >> x;
    sort(prefixes.begin(), prefixes.end());

    vector<int64_t> pwr2 = {1};
    for (int i = 1; i <= n; ++i) {
      pwr2.push_back(pwr2.back() * 2);
    }

    int64_t ans = pwr2.back();
    unordered_set<string> seen;
    for (auto& s : prefixes) {
      string cur;
      int j;
      for (j = 0; j < s.size() && !seen.count(cur); ++j) {
        cur += s[j];
      }
      if (j == s.size()) {
        seen.insert(cur);
        ans -= pwr2[n - s.size()];
      }
    }

    cout << ans << "\n";
  }
}
