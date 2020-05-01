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

  // Each second from 0 to 3600 is a vertex. SSSP from vertex 0.
  int t;
  cin >> t;
  while (t--) {
    int v, dest;
    cin >> v >> dest;
    vi edges(v);
    for (int &x : edges) cin >> x;

    vi dist(3601, 1e9);
    queue<int> q;
    q.emplace(0);
    dist[0] = 0;
    int ans = 1e9;
    while (q.size()) {
      int cur = q.front();
      q.pop();
      if (cur >= dest && cur < ans) {
        ans = cur;
      }

      for (int w : edges) {
        int next = min(max(0, cur + w), 3600);
        if (dist[cur] + 1 >= dist[next]) continue;
        dist[next] = dist[cur] + 1;
        q.emplace(next);
      }
    }

    cout << dist[ans] << ' ' << ans - dest << '\n';
  }
}
