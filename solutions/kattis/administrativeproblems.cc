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
#include <iterator>
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

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    unordered_map<string, array<int64_t, 3>> cars;
    unordered_map<string, string> spyUsing;
    map<string, int64_t> total;
    for (int i = 0; i < n; ++i) {
      string name;
      int p, q, k;
      cin >> name >> p >> q >> k;
      cars[name] = {p, q, k};
    }
    while (m--) {
      int tmp;
      string s;
      char e;
      cin >> tmp >> s >> e;
      if (e == 'p') {
        string c;
        cin >> c;
        if (spyUsing[s].size()) {
          total[s] = -1;
        } else if (total[s] != -1) {
          total[s] += cars[c][1];
          spyUsing[s] = c;
        }
      } else if (e == 'r') {
        int d;
        cin >> d;
        if (spyUsing[s].empty()) {
          total[s] = -1;
        } else if (total[s] != -1) {
          total[s] += d * cars[spyUsing[s]][2];
          spyUsing[s] = "";
        }
      } else {
        int p;
        cin >> p;
        if (spyUsing[s].empty()) {
          total[s] = -1;
        } else if (total[s] != -1) {
          total[s] += (p * cars[spyUsing[s]][0] + 99) / 100;
        }
      }
    }

    for (auto& [k, v] : total) {
      cout << k << " ";
      if (v == -1 || spyUsing[k].size()) {
        cout << "INCONSISTENT";
      } else {
        cout << v;
      }
      cout << "\n";
    }
  }
}
