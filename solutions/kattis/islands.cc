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

  int P;
  cin >> P;
  while (P--) {
    int K;
    cin >> K;
    cout << K << " ";
    array<int, 12> a;
    for (auto& x : a)
      cin >> x;

    int cnt = 0;
    for (int i = 1; i < 11; ++i) {
      if (a[i] <= a[i - 1])
        continue;
      int cmin = a[i];
      for (int j = i; j < 11; ++j) {
        cmin = min(a[j], cmin);
        if (cmin > a[i - 1] && cmin > a[j + 1]) {
          ++cnt;
        }
      }
    }
    cout << cnt << "\n";
  }
}
