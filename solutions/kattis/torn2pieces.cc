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
#define FILE "mootube"
#endif

unordered_map<string, vector<string>> adj;
unordered_set<string> vis;
unordered_map<string, string> p;
string t;

bool dfs(string u) {
  if (u == t) {
    return true;
  }
  vis.emplace(u);
  for (auto& v : adj[u]) {
    if (!vis.count(v)) {
      p[v] = u;
      if (dfs(v)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // DFS for the path between the source and destination
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    stringstream ss(s);
    string u;
    bool first = true;
    while (ss >> s) {
      if (first) {
        u = s;
        first = false;
      } else {
        adj[u].push_back(s);
        adj[s].push_back(u);
      }
    }
  }

  cin >> s >> t;
  if (!dfs(s)) {
    cout << "no route found";
    return 0;
  }

  stack<string> path;
  while (t != s) {
    path.emplace(t);
    t = p[t];
  }
  path.emplace(s);

  while (path.size()) {
    cout << path.top() << ' ';
    path.pop();
  }
}
