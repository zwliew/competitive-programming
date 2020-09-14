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

  // Iterate through the array while keeping track of the last number for each
  // sequence. On each iteration, binary search for the first number less than
  // the current element
  int n;
  cin >> n;
  vector<vector<int>> ans;
  vector<int> last;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    auto it = upper_bound(last.begin(), last.end(), x, greater<int>());
    if (it == last.end()) {
      last.emplace_back(x);
      ans.resize(ans.size() + 1);
      ans.back().push_back(x);
    } else {
      int idx = it - last.begin();
      last[idx] = x;
      ans[idx].emplace_back(x);
    }
  }

  for (auto& v : ans) {
    for (int x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
