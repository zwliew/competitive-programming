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
#include <random>
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
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    vector<int> v(m);
    bool first = true;
    for (int i = 0; i < m; ++i) {
      cin >> v[i];
      if (i >= 2 && v[i] - v[i - 1] != v[i - 1] - v[i - 2]) {
        first = false;
      }
    }

    if (first) {
      cout << "arithmetic\n";
      continue;
    }

    sort(v.begin(), v.end());
    bool second = true;
    for (int i = 2; i < m; ++i) {
      if (v[i] - v[i - 1] != v[i - 1] - v[i - 2]) {
        second = false;
        break;
      }
    }

    if (second) {
      cout << "permuted arithmetic\n";
    } else {
      cout << "non-arithmetic\n";
    }
  }
}
