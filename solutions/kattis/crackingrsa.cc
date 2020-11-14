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

  int T;
  cin >> T;
  while (T--) {
    int N, E;
    cin >> N >> E;

    int phi = N;
    for (int d = 2; d * d <= N; ++d) {
      if (N % d == 0) {
        while (N % d == 0) {
          N /= d;
        }
        phi -= phi / d;
      }
    }
    if (N > 1) {
      phi -= phi / N;
    }

    for (int64_t d = 2; d < phi; ++d) {
      if ((d * E) % phi == 1) {
        cout << d << "\n";
        break;
      }
    }
  }
}
