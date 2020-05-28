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

  vi powers(10, 1);
  for (int i = 1; i < 10; ++i) {
    powers[i] = powers[i - 1] * 4;
  }

  // State space SSSP with BFS.
  int s = 0;
  for (int i = 0; i < 9; ++i) {
    int x;
    cin >> x;
    s += x * powers[i];
  }

  queue<int> q;
  q.emplace(s);
  vi dist(1e8, 1e9);
  dist[s] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();

    if (!u) {
      cout << dist[0];
      return 0;
    }

    // a * 64 + b * 16 + c * 4 + d * 1
    int ndist = dist[u] + 1;
    for (int i = 0; i < 9; ++i) {
      int v = u;

      for (int j = i / 3 * 3; j < i / 3 * 3 + 3; ++j) {
        int dig = (v / powers[j]) % 4;
        int newdig = (dig + 1) % 4;
        v += (newdig - dig) * powers[j];
      }

      for (int j = i % 3; j < 9; j += 3) {
        if (j == i) continue;
        int dig = (v / powers[j]) % 4;
        int newdig = (dig + 1) % 4;
        v += (newdig - dig) * powers[j];
      }

      if (ndist < dist[v]) {
        dist[v] = ndist;
        q.emplace(v);
      }
    }
  }

  cout << -1;
}
