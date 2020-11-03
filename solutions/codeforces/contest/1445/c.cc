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
    int64_t p, q;
    cin >> p >> q;
    if (p < q || p % q) {
      cout << p << "\n";
    } else {
      int64_t origQ = q;
      vector<int64_t> factors;
      for (int64_t i = 2; i * i <= q; ++i) {
        if (q % i == 0) {
          factors.push_back(i);
          while (q % i == 0) {
            q /= i;
          }
        }
      }
      if (q > 1) {
        factors.push_back(q);
      }

      int64_t largest = 0;
      for (auto x : factors) {
        int64_t cur = p;
        while (cur % origQ == 0)
          cur /= x;
        largest = max(largest, cur);
      }
      cout << largest << "\n";
    }
  }
}
