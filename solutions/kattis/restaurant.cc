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

  int n;
  while (cin >> n && n) {
    array<int, 2> st = {0, 0};
    while (n--) {
      string s;
      int x;
      cin >> s >> x;

      if (s == "DROP") {
        st[0] += x;
        cout << "DROP 1 " << x << "\n";
      } else if (s == "TAKE") {
        int d = min(st[1], x);
        if (d) {
          cout << "TAKE 2 " << d << "\n";
          x -= d;
          st[1] -= d;
        }
        if (x) {
          cout << "MOVE 1->2 " << st[0] << "\n";
          st[1] += st[0] - x;
          st[0] = 0;
          cout << "TAKE 2 " << x << "\n";
        }
      }
    }
    cout << "\n";
  }
}
