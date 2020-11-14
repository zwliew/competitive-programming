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

  string s;
  while (cin >> s && s != "END") {
    double x = stod(s);
    double l = 0, r = 1;
    bool ok = true;
    while (r - l > 1e-9) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      if (x <= m1) {
        r = m1;
      } else if (x >= m2) {
        l = m2;
      } else {
        ok = false;
        break;
      }
    }
    cout << (ok ? "MEMBER" : "NON-MEMBER") << "\n";
  }
}
