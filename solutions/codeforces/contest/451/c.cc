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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
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
    int64_t n, k, d1, d2;
    cin >> n >> k >> d1 >> d2;

    // a + b + c = k
    // possibilities:
    // a = d1 + b, b = d2 + c => a = d1 + d2 + c => d1 + 2d2 + 3c = k => c = (k
    // - d1 - 2d2) / 3 a = b - d1, b = d2 + c => a = d2 + c - d1 => 2d2 + 3c -
    // d1 = k => c = (k + d1 - 2d2) / 3 a = d1 + b, b = c - d2 => a = d1 + c -
    // d2 => d1 + 3c - 2d2 = k => c = (k + 2d2 - d1) / 3 a = b - d1, b = c - d2
    // => a = c - d2 - d1 => 3c - 2d2 - d1 = k => c = (k + d1 + 2d2) / 3

    // Editorial solution. Notice that the signs of d1 and d2 are all that
    // matter.
    bool ok = false;
    for (int sign1 = -1; sign1 <= 1; ++sign1) {
      for (int sign2 = -1; sign2 <= 1; ++sign2) {
        if (!sign1 || !sign2)
          continue;

        int64_t d1s = sign1 * d1;
        int64_t d2s = sign2 * d2;
        int64_t cp = k + d1s + 2 * d2s;
        int64_t c = cp / 3;
        int64_t b = c - d2s;
        int64_t a = b - d1s;
        int64_t mx = max({a, b, c});
        int64_t diff = n - k - 3 * mx + a + b + c;
        ok |= cp % 3 == 0 && c >= 0 && a >= 0 && b >= 0 && diff >= 0 &&
              diff % 3 == 0;
      }
    }

    // My original solution. Manually wrote out the 4 cases.
    // auto isDiffOk = [&](int64_t a, int64_t b, int64_t c) {
    //   int64_t mx = max({a, b, c});
    //   int64_t diff = n - k - 3 * mx + a + b + c;
    //   return a >= 0 && b >= 0 && c >= 0 && diff >= 0 && diff % 3 == 0;
    // };
    // bool ok = false;
    // int64_t c = k - d1 - 2 * d2;
    // if (c % 3 == 0) {
    //   c /= 3;
    //   int64_t b = d2 + c;
    //   int64_t a = d1 + b;
    //   ok |= isDiffOk(a, b, c);
    // }
    // c = k + d1 - 2 * d2;
    // if (c % 3 == 0) {
    //   c /= 3;
    //   int64_t b = d2 + c;
    //   int64_t a = b - d1;
    //   ok |= isDiffOk(a, b, c);
    // }
    // c = k + 2 * d2 - d1;
    // if (c % 3 == 0) {
    //   c /= 3;
    //   int64_t b = c - d2;
    //   int64_t a = d1 + b;
    //   ok |= isDiffOk(a, b, c);
    // }
    // c = k + d1 + 2 * d2;
    // if (c % 3 == 0) {
    //   c /= 3;
    //   int64_t b = c - d2;
    //   int64_t a = b - d1;
    //   ok |= isDiffOk(a, b, c);
    // }

    cout << (ok ? "yes\n" : "no\n");
  }
}
