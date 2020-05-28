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

  // State space SSSP problem. Use BFS.
  string s, t;
  cin >> s >> t;
  unordered_map<string, int> dist;
  dist[s] = 0;
  queue<string> q;
  q.emplace(s);
  while (q.size()) {
    string u = q.front();
    q.pop();

    if (u == t) {
      cout << dist[u];
      return 0;
    }

    for (int i = 0; i < 8; ++i) {
      string next = u;
      if (u[i] == 'A') {
        if (i > 0) {
          next[i - 1] = (next[i - 1] + 1 - 'A') % 6 + 'A';
        }
        if (i < 7) {
          next[i + 1] = (next[i + 1] + 1 - 'A') % 6 + 'A';
        }
      } else if (u[i] == 'B') {
        if (i < 7 && i > 0) {
          next[i + 1] = next[i - 1];
        }
      } else if (u[i] == 'C') {
        next[7 - i] = (next[7 - i] + 1 - 'A') % 6 + 'A';
      } else if (u[i] == 'D') {
        if (i < 7 - i) {
          for (int j = i - 1; j >= 0; --j) {
            next[j] = (next[j] + 1 - 'A') % 6 + 'A';
          }
        } else {
          for (int j = i + 1; j <= 7; ++j) {
            next[j] = (next[j] + 1 - 'A') % 6 + 'A';
          }
        }
      } else if (u[i] == 'E') {
        if (i > 0 && i < 7) {
          int delta = min(i, 7 - i);
          next[i - delta] = (next[i - delta] + 1 - 'A') % 6 + 'A';
          next[i + delta] = (next[i + delta] + 1 - 'A') % 6 + 'A';
        }
      } else {
        if (i % 2) {
          next[i / 2] = (next[i / 2] + 1 - 'A') % 6 + 'A';
        } else {
          next[i / 2 + 4] = (next[i / 2 + 4] + 1 - 'A') % 6 + 'A';
        }
      }

      if (!dist.count(next)) {
        dist[next] = dist[u] + 1;
        q.emplace(next);
      }
    }
  }
}
