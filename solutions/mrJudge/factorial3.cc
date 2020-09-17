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

  // Greedily take the largest box
  // We can do this because the size of a box is a multiple of every previous
  // one
  int n;
  cin >> n;
  vector<int> fact = {1};
  while (fact.back() <= n) {
    fact.push_back(fact.back() * fact.size());
  }

  vector<int> ans;
  for (int i = (int)fact.size() - 2; i >= 1; --i) {
    ans.push_back(n / fact[i]);
    n %= fact[i];
  }
  reverse(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for (int x : ans) {
    cout << x << ' ';
  }
}
