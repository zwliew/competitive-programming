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
#define FILE "censor"
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
    array<int, 3> a;
    for (int i = 0; i < 3; ++i)
      cin >> a[i];
    int total = accumulate(a.begin(), a.end(), 0);
    int k = total / 9;
    if (total % 9 == 0 &&
        all_of(a.begin(), a.end(), [&](auto& x) { return x >= k; })) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
