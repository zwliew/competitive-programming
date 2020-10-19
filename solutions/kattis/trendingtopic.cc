#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
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

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  deque<unordered_map<string, int>> freqs;
  string s;
  int idx = 0;
  unordered_map<string, int> cur;
  map<int, set<string>> rev;
  while (cin >> s) {
    if (s == "<text>") {
      unordered_map<string, int> nxt;
      while (cin >> s && s != "</text>") {
        if (s.size() < 4)
          continue;
        nxt[s]++;
      }
      for (auto& [k, v] : nxt) {
        rev[cur[k]].erase(k);
        cur[k] += v;
        rev[cur[k]].insert(k);
      }
      freqs.push_back(nxt);
      if (idx >= 7) {
        for (auto& [k, v] : freqs.front()) {
          rev[cur[k]].erase(k);
          cur[k] -= v;
          rev[cur[k]].insert(k);
        }
        freqs.pop_front();
      }
      ++idx;
    } else if (s == "<top") {
      int n;
      cin >> n >> s;

      int cnt = 0;
      cout << "<top " << n << ">\n";
      for (auto it = rev.rbegin(); it != rev.rend() && cnt < n; ++it) {
        cnt += it->second.size();
        for (auto& x : it->second) {
          cout << x << " " << it->first << "\n";
        }
      }
      cout << "</top>\n";
    }
  }
}
