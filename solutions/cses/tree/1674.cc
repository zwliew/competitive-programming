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
#define FILE "maxflow"
#endif

vector<int> ans;
vector<vector<int>> adj;

void dfs(int u) {
  for (int v : adj[u]) {
    dfs(v);
    ans[u] += ans[v] + 1;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Construct the tree and traverse it.
  int n;
  cin >> n;
  ans.resize(n);
  adj.resize(n);

  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    adj[x].push_back(i);
  }

  dfs(0);

  for (int x : ans) {
    cout << x << ' ';
  }
}
