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
#define FILE "mooyomooyo"
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
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      cnt += a[i];
    }

    if (cnt * 2 <= n) {
      cout << n - cnt << '\n';
      for (int i = 0; i < n - cnt; ++i) {
        cout << "0 ";
      }
    } else {
      cout << cnt - (cnt % 2) << '\n';
      for (int i = 0; i < cnt - (cnt % 2); ++i) {
        cout << "1 ";
      }
    }
    cout << '\n';
  }
}
