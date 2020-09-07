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
#define FILE "family"
#endif

unordered_map<string, vector<string>> adj;
array<unordered_map<string, int>, 2> lvl;

void dfs(string u) {
  for (auto& v : adj[u]) {
    if (!lvl[0].count(v)) {
      lvl[0][v] = lvl[0][u] + 1;
      dfs(v);
    }
  }
}

string dfs2(string u) {
  if (lvl[0].count(u)) {
    return u;
  }
  for (auto& v : adj[u]) {
    if (!lvl[1].count(v)) {
      lvl[1][v] = lvl[1][u] + 1;
      string x = dfs2(v);
      if (x.size()) {
        return x;
      }
    }
  }
  return "";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Construct a directed tree and find the lowest common ancestor when DFS'ing
  // from both A and B. The depth of the lowest common ancestor determines the
  // relationship of A and B.
  int n;
  string a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; ++i) {
    string u, v;
    cin >> u >> v;
    adj[v].push_back(u);
  }

  lvl[0][a] = 1;
  dfs(a);

  lvl[1][b] = 1;
  string x = dfs2(b);

  if (x.empty()) {
    cout << "NOT RELATED";
    return 0;
  }

  if (lvl[0][x] == 2 && lvl[1][x] == 2) {
    // same mother
    cout << "SIBLINGS";
    return 0;
  }

  if (lvl[0][x] == 1 || lvl[1][x] == 1) {
    // one is the direct ancestor of the other
    int d = abs(lvl[0][x] - lvl[1][x]);
    string ans;
    while (d > 2) {
      ans += "great-";
      --d;
    }
    if (d == 2) {
      ans += "grand-";
    }
    ans += "mother";
    if (lvl[1][x] == 1) {
      swap(a, b);
    }
    cout << a << " is the " << ans << " of " << b;
    return 0;
  }

  if (lvl[0][x] == 2 || lvl[1][x] == 2) {
    // one is the aunt
    int d = abs(lvl[0][x] - lvl[1][x]);
    string ans;
    while (d > 1) {
      ans += "great-";
      --d;
    }
    ans += "aunt";
    if (lvl[1][x] == 2) {
      swap(a, b);
    }
    cout << a << " is the " << ans << " of " << b;
    return 0;
  }

  cout << "COUSINS";
}
