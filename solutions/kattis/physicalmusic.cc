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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& x : p)
      cin >> x;

    vector<int> ans;
    int sufMin = n + 1;
    for (int i = n - 1; i >= 0; --i) {
      if (p[i] > sufMin) {
        ans.push_back(p[i]);
      } else {
        sufMin = min(sufMin, p[i]);
      }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int x : ans) {
      cout << x << "\n";
    }
  }
}
