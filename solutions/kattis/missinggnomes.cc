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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Slot the missing numbers in lexicographical order using a BST
  int n, m;
  cin >> n >> m;

  set<int> removed;
  for (int i = 1; i <= n; ++i) {
    removed.emplace(i);
  }

  vector<int> v(m);
  for (auto& x : v) {
    cin >> x;
    removed.erase(x);
  }

  for (int x : v) {
    while (removed.size() && *removed.begin() < x) {
      cout << *removed.begin() << '\n';
      removed.erase(removed.begin());
    }
    cout << x << '\n';
  }

  for (int x : removed) {
    cout << x << '\n';
  }
}
