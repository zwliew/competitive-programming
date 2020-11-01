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
    vector<int> s(n);
    for (auto& x : s)
      cin >> x;
    sort(s.begin(), s.end());

    int sum = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      sum += s[i];
      if (i >= p) {
        sum -= s[i - p];
      }
      if (i >= p - 1) {
        ans = min(ans, s[i] * p - sum);
      }
    }
    cout << ans << "\n";
  }
}
