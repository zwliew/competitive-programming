#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int, int>;

#define eb emplace_back

bool dfs(unordered_map<string, vector<string>> &adj,
         unordered_set<string> &explored, string u) {
  explored.emplace(u);
  for (string v : adj[u]) {
    if (explored.count(v) || dfs(adj, explored, v)) {
      return true;
    }
  }
  explored.erase(u);
  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Cycle detection in a directed graph.
  int n;
  cin >> n;
  unordered_map<string, vector<string>> adj;
  while (n--) {
    string u, v;
    cin >> u >> v;
    adj[u].eb(v);
  }

  string src;
  while (cin >> src) {
    cout << src << ' ';
    unordered_set<string> explored;
    if (dfs(adj, explored, src)) {
      cout << "safe\n";
    } else {
      cout << "trapped\n";
    }
  }
}
