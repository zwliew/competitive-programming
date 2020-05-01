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
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // SSSP with various sources.
  int n, h, l;
  cin >> n >> h >> l;
  vector<int> horrors(h);
  vector<int> indices(n, 1e9);
  for (int i = 0; i < h; ++i) {
    cin >> horrors[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < l; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  for (int x : horrors) {
    indices[x] = 0;
    queue<int> q;
    q.emplace(x);
    while (q.size()) {
      int cur = q.front();
      q.pop();
      for (int v : adj[cur]) {
        int nextIdx = indices[cur] + 1;
        if (nextIdx >= indices[v]) continue;
        indices[v] = nextIdx;
        q.emplace(v);
      }
    }
  }

  int lowestMovie = 1e9;
  int lowestIndex = -1e9;
  for (int i = 0; i < n; ++i) {
    if (indices[i] > lowestIndex) {
      lowestIndex = indices[i];
      lowestMovie = i;
    }
  }

  cout << lowestMovie;
}
