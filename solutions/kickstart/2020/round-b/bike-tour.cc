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
//#include "bits/stdc++.h"

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

  // Straightforward implementation problem
  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto& x : h)
      cin >> x;

    int cnt = 0;
    for (int i = 1; i < n - 1; ++i) {
      if (h[i] > h[i - 1] && h[i] > h[i + 1])
        ++cnt;
    }
    cout << "Case #" << ti << ": " << cnt << "\n";
  }
}
