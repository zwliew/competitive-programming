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
// #include "bits/stdc++.h"

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

  // Use the N smallest dishes. Greedily pair the smallest main with the largest
  // side (rearrangement inequality).
  int n, m, s;
  cin >> n >> m >> s;
  vector<int> main(m), side(s);
  for (auto& x : main)
    cin >> x;
  for (auto& x : side)
    cin >> x;
  sort(main.begin(), main.end());
  sort(side.begin(), side.end());

  int mx = 0;
  for (int i = 0, j = n - 1; i < n; ++i, --j) {
    mx = max(main[i] + side[j], mx);
  }
  cout << mx;
}
