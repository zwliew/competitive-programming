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
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // SSSP on an unweighted, undirected graph.
  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;
  vi dist(f + 1, 1e9);
  dist[s] = 0;
  queue<int> q;
  q.emplace(s);
  while (q.size()) {
    int cur = q.front();
    q.pop();
    if (cur == g) {
      cout << dist[cur];
      return 0;
    }
    int ndist = dist[cur] + 1;
    if (cur + u <= f && ndist < dist[cur + u]) {
      dist[cur + u] = ndist;
      q.emplace(cur + u);
    }
    if (cur - d >= 1 && ndist < dist[cur - d]) {
      dist[cur - d] = ndist;
      q.emplace(cur - d);
    }
  }
  cout << "use the stairs";
}
