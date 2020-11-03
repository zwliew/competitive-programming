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
    string S;
    cin >> S;
    int64_t total = 0;
    int cnt = 0;
    for (int i = 0; i + 4 < S.size(); ++i) {
      if (i >= 3 && S.substr(i - 3, 4) == "KICK") {
        ++cnt;
      }
      if (S.substr(i, 5) == "START") {
        total += cnt;
      }
    }
    cout << "Case #" << t << ": " << total << "\n";
  }
}
