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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Build the adjacency list and this turns into an SSSP problem.
  int n;
  cin >> n;
  while (n--) {
    int s;
    cin >> s;
    map<ii, vector<ii>> adj;
    ii pos = {0, 0};
    ii end;
    while (s--) {
      char c;
      cin >> c;
      ii next = pos;
      if (c == 'S') {
        next.second++;
      } else if (c == 'E') {
        next.first++;
      } else if (c == 'N') {
        next.second--;
      } else {
        next.first--;
      }
      adj[pos].eb(next);
      adj[next].eb(pos);
      pos = next;
    }
    end = pos;

    queue<ii> q;
    q.emplace(0, 0);
    map<ii, int> dist;
    dist[{0, 0}] = 0;
    while (q.size()) {
      auto u = q.front();
      q.pop();

      if (u == end) {
        cout << dist[u] << '\n';
        break;
      }

      int ndist = dist[u] + 1;
      for (auto v : adj[u]) {
        if (!dist.count(v)) {
          dist[v] = ndist;
          q.emplace(v);
        }
      }
    }
  }
}
