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

  int b, n;
  while (cin >> b >> n && (b || n)) {
    vector<int> banks(b);
    for (int i = 0; i < b; ++i) {
      cin >> banks[i];
    }
    for (int i = 0; i < n; ++i) {
      int d, c, v;
      cin >> d >> c >> v;
      --d, --c;
      banks[d] -= v;
      banks[c] += v;
    }

    bool ok = true;
    for (int i = 0; i < b; ++i) {
      if (banks[i] < 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "S\n";
    } else {
      cout << "N\n";
    }
  }
}
