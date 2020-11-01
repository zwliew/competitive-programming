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
  for (int ti = 1; ti <= t; ++ti) {
    cout << "Case #" << ti << ": ";

    string n;
    cin >> n;
    int64_t ni = stoll(n);
    string lo = n;
    int i;
    for (i = 0; i < lo.size() && (lo[i] - '0') % 2 == 0; ++i)
      ;
    if (i == lo.size()) {
      cout << 0;
    } else {
      lo[i]--;
      for (int j = i + 1; j < lo.size(); ++j) {
        lo[j] = '8';
      }
      int64_t loi = stoll(lo);

      string hi = n;
      int64_t pw = 1;
      for (int j = i + 1; j < lo.size(); ++j) {
        hi[j] = '0';
        pw *= 10;
      }
      int64_t hii = stoll(hi);
      hii += pw;
      while (hi[i] == '9') {
        --i;
        pw *= 10;
        hii += pw;
        if (i >= 0)
          hi[i]++;
      }

      cout << min(ni - loi, hii - ni);
    }

    cout << "\n";
  }
}
