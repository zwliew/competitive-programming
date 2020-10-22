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
    int n;
    cin >> n;
    map<string, set<string>> possibilities, revPossibilities;
    while (n--) {
      string s;
      cin >> s;
      int m;
      cin >> m;
      set<string> native, foreign;
      for (int i = 0; i < m; ++i) {
        string x;
        cin >> x;
        foreign.insert(x);
      }
      cin >> m;
      for (int i = 0; i < m; ++i) {
        string x;
        cin >> x;
        native.insert(x);
      }
      for (auto& x : foreign) {
        if (!possibilities.count(x)) {
          possibilities[x] = native;
        } else {
          set<string> nxt;
          for (auto& y : possibilities[x]) {
            if (native.count(y)) {
              nxt.insert(y);
            }
          }
          possibilities[x] = nxt;
        }
      }
      for (auto& x : native) {
        if (!revPossibilities.count(x)) {
          revPossibilities[x] = foreign;
        } else {
          set<string> nxt;
          for (auto& y : revPossibilities[x]) {
            if (foreign.count(y)) {
              nxt.insert(y);
            }
          }
          revPossibilities[x] = nxt;
        }
      }
    }

    for (auto& [k, v] : possibilities) {
      for (auto& s : v) {
        if (revPossibilities[s].count(k))
          cout << "(" << k << ", " << s << ")\n";
      }
    }
    cout << "\n";
  }
}
