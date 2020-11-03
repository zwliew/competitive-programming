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
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    int longest = 0;
    int cur = 0;
    int diff = INT_MIN;
    int prev;
    cin >> prev;
    for (int i = 1; i < N; ++i) {
      int x;
      cin >> x;
      int cdiff = x - prev;
      if (cdiff != diff) {
        diff = cdiff;
        longest = max(longest, cur);
        cur = 2;
      } else {
        ++cur;
      }
      prev = x;
    }
    cout << "Case #" << t << ": " << max(longest, cur) << "\n";
  }
}
