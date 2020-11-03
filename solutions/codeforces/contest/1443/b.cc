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
    int a, b;
    string s;
    cin >> a >> b >> s;
    int i = 0;
    while (i < s.size() && s[i] == '0')
      ++i;
    int total = i < s.size() ? a : 0;
    for (; i < s.size();) {
      int zeros = 0;
      while (i < s.size() && s[i] == '1')
        ++i;
      while (i < s.size() && s[i] == '0') {
        ++i;
        ++zeros;
      }
      if (i < s.size()) {
        total += min(zeros * b, a);
      }
    }
    cout << total << "\n";
  }
}
