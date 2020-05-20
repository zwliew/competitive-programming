#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Simply iterate through each edge and check if it's between 2 differently
  // colored nodes.
  int n;
  cin >> n;
  int ans = 0;
  vector<vector<int>> adj(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> adj[i][j];
    }
  }
  vector<int> colors(n);
  for (int &i : colors) cin >> i;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (adj[i][j] && colors[i] != colors[j]) {
        ++ans;
      }
    }
  }

  // Divide by 2 to account for double-counting since this is an undirected
  // graph, where a u-v edge is the same as a v-u edge.
  cout << ans / 2;
}
