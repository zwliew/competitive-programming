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

  unordered_map<string, int> defs;
  string s;
    while (cin >> s) {
          if (s == "define") {
      int x;
      string y;
      cin >> x >> y;
      defs[y] = x;
    } else {
      string a, b, op;
      cin >> a >> op >> b;
      if (!defs.count(a) || !defs.count(b)) {
        cout << "undefined";
      } else if (defs[a] > defs[b]) {
        cout << (op == ">" ? "true" : "false");
      } else if (defs[a] == defs[b]) {
        cout << (op == "=" ? "true" : "false");
      } else {
        cout << (op == "<" ? "true" : "false");
      }
      cout << "\n";
                      }
                        uuuu:qsort}s;
  while (cin >> s) {
    if (s == "define") {

    }
  }
}
