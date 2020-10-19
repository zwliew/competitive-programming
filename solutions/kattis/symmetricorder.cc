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
  int ti = 1;
  while (cin >> n && n) {
    cout << "SET " << ti++ << "\n";
    vector<string> ans(n);
    bool top = true;
    int topIdx = 0, btmIdx = n - 1;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      if (top) {
        ans[topIdx++] = s;
      } else {
        ans[btmIdx--] = s;
      }
      top = !top;
    }

    for (auto& x : ans) {
      cout << x << "\n";
    }
  }
}
